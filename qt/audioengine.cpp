#include "audioengine.h"
#include "dywapitchtrack.h"
#include "signaldata.h"
#include "common.h"
#include <cmath>
#include <QBuffer>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QTGlobal>
#include <QDateTime>

static dywapitchtracker ptch_trk;

void g_util_prnt_list(QList<int> &list)
{
    for (int i = 0; i < list.count(); i++)
        qWarning(" %d", list.at(i));
    return;
}

AudioEngine::AudioEngine(uint32_t mic_num)
{
    _mic_num = mic_num;
    _windowCtr = 0;
}

AudioEngine::~AudioEngine()
{
}

void AudioEngine::endThread(void)
{
    _endThread = true;
}

void AudioEngine::stateChanged(QAudio::State state)
{
    qWarning("New state: %d", state);
    switch (state) {
        case QAudio::StoppedState:
            if (_audioInput->error() != QAudio::NoError) {
                // Error handling
            } else {
                // Finished recording
            }
            break;

        case QAudio::ActiveState:
            // Started recording - read from IO device
            break;

        default:
            // ... other cases as appropriate
            break;
    }
}

void AudioEngine::setMinFreq(int freq)
{
    _minFreq = freq;
    _sampCount = dywapitch_neededsamplecount(_minFreq);
    qWarning("samp %d", _sampCount);
    return;
}

void AudioEngine::process()
{
    _endThread = false;
    static char _buffer[10000];
    _buff = new QBuffer(&_byteArray);
    QObject::connect(_buff, SIGNAL(bytesWritten(qint64)), this, SLOT(procData(qint64)));
    // Number of required samples plus overhead
    _byteArray.setRawData(_buffer, sizeof(_buffer));
    if (_buff->open(QBuffer::ReadWrite) == false) qWarning("Fail to open file");
    QAudioFormat format;
    format.setFrequency(44100);
    format.setChannels(1);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setSampleType(QAudioFormat::SignedInt);
    // TODO: Set microphone options
    for (int i = 0; QAudioDeviceInfo::availableDevices(QAudio::AudioInput).count() > i; i++) { qWarning("Mic %d: %s", i, QAudioDeviceInfo::availableDevices(QAudio::AudioInput).at(i).deviceName().toAscii().data()); }
    QAudioDeviceInfo info(QAudioDeviceInfo::availableDevices(QAudio::AudioInput).at(_mic_num));
    qWarning("byte order %d",format.byteOrder());
    if (!info.isFormatSupported(format)) {
        qWarning("Warning, audio input format is not supported");
        qWarning("Supported sample rates: ");
        //g_util_prnt_list(info.supportedSampleRates());
        qWarning("Sizes");
        //g_util_prnt_list(info.supportedSampleSizes());
        info.nearestFormat(format);
    }
    _audioInput = new QAudioInput(format, this);

    //QObject::connect(_audioInput, SIGNAL(notify()), this, SLOT(stopRecording()));
    _audioInput->setBufferSize(10240);
    g_trace.audioInput(_audioInput->bufferSize());

    //QObject::connect(_audioInput, SIGNAL(stateChanged(QAudio::State)), this, SLOT(stateChanged(QAudio::State)));
    _last = 0;
    _time = 0;
    switch (1) {
    case 1:
        //_audioInput->setNotifyInterval(80);
        //qWarning("Notify interval: %d",_audioInput->notifyInterval());
        this->setMinFreq(130);
        this->getMsIntval();
        //_timer = new QTimer(this);
        this->getPitch();
        //_timer->start(100);
        //connect(_timer, SIGNAL(timeout()), this, SLOT(stopRecording()));
        break;
    }
}

void AudioEngine::threadCleanup()
{
    _buff->close();
    _buff->deleteLater();
    //_timer->stop();
    //_timer->deleteLater();
    _audioInput->stop();
    _audioInput->deleteLater();

    emit finished();
}

int AudioEngine::getMsIntval(void)
{
    return _sampCount / 44 + 1;
}
// TODO: Audio limitation error has prperty getting correct data to the bytebuffer on the last attempt before operation is stopped.
void AudioEngine::startRecording(int minFreq)
{
    QDateTime t;
    if (!_last) {
        _last = t.currentMSecsSinceEpoch();
    }
    else {
        qint64 diff = t.currentMSecsSinceEpoch() - _last;
        _time += (double)diff / 1000;
        _last += diff;
    }
    _windowCtr += 1;
    //QTimer::singleShot(50, this, SLOT(stopRecording()));
    _audioInput->start(_buff);
}

void AudioEngine::stopRecording()
{
    qWarning("stoped");
    _audioInput->stop();

}

void AudioEngine::procData(qint64 bytes)
{
    _audioInput->stop();
    //qWarning("Samples ready: %d", (int)bytes/2);

    if (_endThread) {
        this->threadCleanup();
        return;
    }

    _buff->close();
    _buff->open(QBuffer::ReadOnly);

    g_trace.sampToFile(_byteArray, 2, (int)bytes, _windowCtr);
    switch (1) {
    case 1:
        // unsigned int to float
        float *tmp = dywapitchGetSampPtr();
        for (int i = 0; i < DYWA_SAMPLE_COUNT_BYTES; i += DYWA_SAMPLE_SIZE) {
            tmp[i >> 1] = (float)*(short*)(_byteArray.constData() + i);
        }
        _buff->close();
        _buff->open(QBuffer::ReadWrite);
        float amp = 0;
        for(int i = 0; i < 1024; i++)
            amp += tmp[i] * tmp[i];

        float rms = sqrt(amp);
        rms /= 15;
        double pitch = 0;

        if (rms > 100) {

            dywapitch_inittracking(&ptch_trk);
            pitch = dywapitch_computepitch(&ptch_trk, (void*)_byteArray.constData(), 0, _sampCount);
            if (pitch > 150 && pitch < 600) {
                //const QPointF s(_time, pitch);
                const QPointF s(_time, pitch);//(double)(int)(log(pitch / 16.35) / log(1.059463094359) + 2.5));
                SignalData::instance().append(s);
                emit(dataReady(pitch, rms));
            }
        }
        else {

            //const QPointF s(_time, 151);
            //SignalData::instance().append(s);
        }
        this->getPitch();

    }

    return;
}

void AudioEngine::getPitch()
{
    // Get audio here
    this->startRecording(_minFreq);

    return;
}
