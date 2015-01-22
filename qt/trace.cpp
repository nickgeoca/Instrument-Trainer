#include "trace.h"

// Trace Levels
#define TLEV_SAMP_TO_F      0x80000000
#define TLEV_AUDIO_INPUT    0x40000000
#define TLEV_CHECK(a) if (!(_traceLev & a)) return;

#define TRACE_ON 1
Trace g_trace;

Trace::Trace()
{
    _traceLev = 0;
    _traceLev = 0x40000000;
    //_traceLev = 0xFFFFFFFF;
}

void Trace::sampToFile(QByteArray &bytes, int sampSize, int sampCount, int windCtr)
{
#if TRACE_ON
    TLEV_CHECK(TLEV_SAMP_TO_F);
    sampCount /= sampSize;
    qWarning("Window #: %d", windCtr);
    qWarning("Sample Count: %d", sampCount);
    for (int i = 0; i < 2048; i += 2) {
        qWarning("val: %f", (float)*(short*)(bytes.constData()+i));
    }
#endif // TRACE_ON
}

void Trace::audioInput(int buffSize)
{
#if TRACE_ON
    TLEV_CHECK(TLEV_AUDIO_INPUT);
    qWarning("Audio Input->Buffer Size: %d", buffSize);
#endif // TRACE_ON
}
