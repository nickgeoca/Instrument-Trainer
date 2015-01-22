#ifndef PLOT_H
#define PLOT_H

#include <qwt_plot.h>
#include <qwt_interval.h>
#include <qwt_system_clock.h>

class QwtPlotCurve;
class QwtPlotMarker;
class QwtPlotDirectPainter;

class Plot: public QwtPlot
{
    Q_OBJECT

public:
    Plot(QWidget * = NULL);
    virtual ~Plot();

    void start();
    void stop();
    virtual void replot();
    void setLineColor(QColor &color);
public Q_SLOTS:
    void setIntervalLength(double);

protected:
    virtual void showEvent(QShowEvent *);
    virtual void resizeEvent(QResizeEvent *);
    virtual void timerEvent(QTimerEvent *);

private:
    void initGradient();

    void updateCurve();
    void incrementInterval();

    QwtPlotMarker *d_origin;
    QwtPlotCurve *d_curve;
    int d_paintedPoints;
    QPen *_pen_data;
    QwtPlotDirectPainter *d_directPainter;

    QwtInterval d_interval;
    int d_timerId;

    QwtSystemClock *d_clock;
};

#endif
