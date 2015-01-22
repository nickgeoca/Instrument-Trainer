#define MAINWINDOW_TABLE_DEF
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "common.h"
#include "plot.h"
#include <QPalette>
#include <QAudioInput>
#include <QtCore>
#include <QtGui>
#include <QtOpenGL/QGLWidget>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Setup UI
    ui->setupUi(this);

    // plot
    _plot = new Plot(this);
    _plot->setIntervalLength(5);
    _plot->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    ui->plotLayout->addWidget(_plot);
    // Push Button
    ui->pushButton->setText("Start");
    ui->pushButton->setCheckable(true);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::gray);
    this->setPalette(pal);
    // Event Text

    _audio_t = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(bool checked)
{
    if (checked) {
        // Worker Exist?
        if (_audio_t != NULL) {
            ui->eventText->setText("Busy");
            return;
        }
        //ui->eventText->setText("Pitch calculation started.");
        _audio_t = new QThread;
        _audio = new AudioEngine(ui->spinBox_micNum->value());
        _audio->moveToThread(_audio_t);

        connect(_audio, SIGNAL(dataReady(float, float)), this, SLOT(updateData(float, float)));
        connect(_audio_t, SIGNAL(started()), _audio, SLOT(process()));
        connect(_audio, SIGNAL(finished()), _audio_t, SLOT(quit()));
        connect(_audio, SIGNAL(finished()), _audio, SLOT(deleteLater()));
        connect(_audio_t, SIGNAL(finished()), _audio_t, SLOT(deleteLater()));
        _audio_t->start(QThread::HighPriority);
        ui->pushButton->setText("Stop");
        _plot->start();

    }
    else {
        _audio->endThread();
        _audio_t = NULL;
        //ui->eventText->setText("Idle");
        ui->pushButton->setText("Start");
        _plot->stop();

    }
}

void MainWindow::updateData(float d, float t)
{
    if (d == 0) return;

    const char *note_table[] = {"C", "C#", "D", "Eb", "E", "F", "F#", "G", "G#", "A", "Bb", "B"};
    QString s;
    int note_int = 0;
    double note = 0;

    note = log(d / 16.35) / log(1.059463094359) + 2;
    note_int = (int)(note + .5);
    s.sprintf("Note: %s%d", note_table[note_int % 12], note_int / 12);
    t = log(t) / 10;
    t -= .5;
    if (t < 0) t *= -1;
    t *= 3;

    ui->eventText->setText(s);
    //s.sprintf("Freq: %.2f", d);
    s.sprintf("Tune: %.2f", note - (float)note_int);
    ui->eventText_2->setText(s);
    s.sprintf("Power: %.2f", t);
    ui->eventText_3->setText(s);

    //t *= sizeof(choropleth_map) / 3 - 1;
    //if (t > sizeof(choropleth_map) / 3 - 1) t = sizeof(choropleth_map) / 3 - 1;
    //QColor b(choropleth_map[(int)t][2], choropleth_map[(int)t][0], choropleth_map[(int)t][1], 255);
    //_plot->setLineColor(b);
    //ui->textBrowser->set(s);
    return;
}


void MainWindow::paintEvent(QPaintEvent *e)
{

}
