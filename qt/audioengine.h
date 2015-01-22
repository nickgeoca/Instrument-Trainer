#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

#include <QBuffer>
#include <QAudioInput>
#include <QObject>
#include <QTimer>

class AudioEngine : public QObject
{
    Q_OBJECT
public:
    AudioEngine(uint32_t mic_num);
    ~AudioEngine();
    void setMinFreq(int freq);
    int getMsIntval(void);
    void getPitch();
    void endThread();
private slots:
    void stopRecording();
    void process();
    void procData(qint64 bytes);
public slots:
    void stateChanged(QAudio::State state);
signals:
    void finished();
    void dataReady(float,float);
private:
    QTimer *_timer;
    void startRecording(int minFreq);
    void calcPitch();
    void threadCleanup();
    QBuffer *_buff;
    QByteArray _byteArray;
    QAudioInput *_audioInput;
    int _minFreq;
    int _sampCount;
    bool _endThread;
    int _mic_num;
    int _windowCtr;
    double _time;
    qint64 _last;
};

#endif // AUDIOENGINE_H
