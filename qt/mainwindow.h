#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <audioengine.h>
#include <qwidget.h>

class Plot;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked(bool checked);
    void updateData(float d, float t);

private:
    QTimer *timer;
    Ui::MainWindow *ui;
    AudioEngine *_audio;
    Plot *_plot;

protected:
    void paintEvent(QPaintEvent *e);
    QThread *_audio_t;
};



#endif // MAINWINDOW_H


#if defined(MAINWINDOW_TABLE_DEF)
unsigned char choropleth_map[][3] =
{
    { 115 , 27 , 133 },
    { 117 , 33 , 138 },
    { 115 , 33 , 140 },
    { 113 , 33 , 140 },
    { 114 , 33 , 142 },
    { 115 , 33 , 145 },
    { 115 , 35 , 148 },
    { 113 , 35 , 148 },
    { 112 , 39 , 149 },
    { 112 , 44 , 151 },
    { 110 , 47 , 151 },
    { 106 , 47 , 151 },
    { 107 , 51 , 156 },
    { 105 , 52 , 156 },
    { 105 , 52 , 155 },
    { 105 , 54 , 158 },
    { 102 , 54 , 160 },
    { 102 , 59 , 164 },
    { 99 , 65 , 166 },
    { 94 , 66 , 166 },
    { 89 , 67 , 169 },
    { 91 , 73 , 174 },
    { 91 , 73 , 174 },
    { 89 , 75 , 176 },
    { 81 , 77 , 173 },
    { 77 , 79 , 173 },
    { 74 , 80 , 175 },
    { 71 , 81 , 175 },
    { 71 , 85 , 181 },
    { 68 , 86 , 181 },
    { 66 , 89 , 181 },
    { 66 , 92 , 182 },
    { 65 , 92 , 182 },
    { 62 , 92 , 181 },
    { 62 , 96 , 186 },
    { 63 , 98 , 188 },
    { 62 , 100 , 188 },
    { 63 , 101 , 189 },
    { 64 , 105 , 190 },
    { 66 , 107 , 192 },
    { 64 , 108 , 192 },
    { 69 , 115 , 199 },
    { 68 , 116 , 198 },
    { 66 , 116 , 198 },
    { 68 , 118 , 201 },
    { 71 , 121 , 204 },
    { 72 , 122 , 204 },
    { 71 , 124 , 204 },
    { 70 , 125 , 206 },
    { 72 , 129 , 208 },
    { 72 , 130 , 206 },
    { 73 , 134 , 208 },
    { 75 , 135 , 211 },
    { 78 , 138 , 214 },
    { 77 , 138 , 212 },
    { 78 , 140 , 211 },
    { 83 , 143 , 213 },
    { 86 , 147 , 215 },
    { 86 , 149 , 217 },
    { 88 , 153 , 221 },
    { 86 , 154 , 221 },
    { 90 , 159 , 222 },
    { 93 , 163 , 222 },
    { 93 , 164 , 221 },
    { 93 , 167 , 221 },
    { 94 , 170 , 223 },
    { 92 , 171 , 222 },
    { 93 , 175 , 223 },
    { 93 , 175 , 222 },
    { 96 , 179 , 224 },
    { 100 , 183 , 228 },
    { 101 , 185 , 227 },
    { 99 , 187 , 223 },
    { 103 , 193 , 224 },
    { 103 , 194 , 225 },
    { 105 , 196 , 227 },
    { 255 , 108 , 198 },
    { 228 , 106 , 197 },
    { 224 , 110 , 201 },
    { 228 , 111 , 204 },
    { 229 , 109 , 203 },
    { 226 , 118 , 211 },
    { 232 , 120 , 211 },
    { 232 , 124 , 213 },
    { 233 , 128 , 216 },
    { 233 , 132 , 219 },
    { 235 , 135 , 217 },
    { 234 , 141 , 221 },
    { 238 , 147 , 224 },
    { 240 , 157 , 230 },
    { 244 , 164 , 233 },
    { 243 , 169 , 231 },
    { 241 , 171 , 232 },
    { 242 , 179 , 235 },
    { 246 , 185 , 235 },
    { 247 , 191 , 236 },
    { 247 , 198 , 240 },
    { 247 , 207 , 245 },
    { 249 , 209 , 244 },
    { 247 , 216 , 245 },
    { 249 , 221 , 246 },
    { 250 , 230 , 249 },
    { 254 , 234 , 251 },
    { 254 , 239 , 251 },
    { 255 , 245 , 252 },
    { 255 , 248 , 251 }
};
#endif
