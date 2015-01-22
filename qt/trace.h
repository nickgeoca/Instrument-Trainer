#ifndef TRACE_H
#define TRACE_H

#include <QBuffer>

class Trace
{
public:
    Trace();
    void sampToFile(QByteArray &bytes, int sampSize, int sampCount, int windCtr);
    void audioInput(int buffSize);
private:
    unsigned int _traceLev;
};

extern Trace g_trace;

#endif // TRACE_H
