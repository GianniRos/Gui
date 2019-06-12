#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <QLabel>
//#include "ipcamera.h"
#include <rovmqtt.h>
#include "autodrive.h"


enum class MODE{
    MODE_HOME,
    MODE_AUTO,
    MODE_SHAPES,
    MODE_CANNON
};

using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setJoystick(bool connected);
    void setAtMega(bool connected);
    QImage imdisplay;  //This will create QImage which is shown in Qt label
    QTimer* Timer;   // A timer is needed in GUI application
    //IpCamera cam;
    VideoCapture cap;

    ~MainWindow();

public
slots:    // A slot or function is defined which will be intiated by timer
    void DisplayImage();
    void setVideoStart();
    void modeAuto();
    void modeShapes();
    void modeHome();
    void modeCannon();
    void startMeasure();
    void calculate();
    void valueTrackbar(int value);
    void setMessageConsole(QString message, int type);

private slots:
    void Mouse_current_pos();
    void Mouse_Pressed();
    void Mouse_left();


signals:
    void componentChanged();
    void messageArrived(QString msg,int type);




private:
    bool video,snap_b,snap,snap_a,debug;
    Ui::MainWindow *ui;
    Mat img,shape;
    QIcon icon,icon2,video_icon,auto_icon,shapes_icon,home_icon,cannon_icon;
    QIcon auto_icon_w,shapes_icon_w,home_icon_w,term_icon,cannon_icon_w;
    MODE mode = MODE::MODE_HOME;
    AutoDrive autodrive;
    int value_track,cnt,turn,mean=0,moda=0;
    Point right;
    Point left;
    double R1,R2,L,a,b,l,unit;

};

#endif // MAINWINDOW_H
