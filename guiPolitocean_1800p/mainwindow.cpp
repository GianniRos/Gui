#include "mainwindow.h"
#include "ui_design.h"
#include "my_qlabel.h"
#include "vision.h"

#include <iostream>
#include <QTimer>
#include <QMouseEvent>
#include <QPixmap>
#include <QApplication>
#include <QResizeEvent>


#define sizeIconMenu 80
#define sizeIconComponent 30

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    cap.open("/dev/video0");

    //INIT PRIVATE VARIABLE
    video = false;

    /*TIMER DISPLAY CAMERAS*/
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(DisplayImage()));
    Timer->start(33);

    /*CONNECTION BUTTONS*/
    connect(ui->startVideo,SIGNAL(clicked()),SLOT(setVideoStart()));
    connect(ui->auto_drive,SIGNAL(clicked()),SLOT(modeAuto()));
    connect(ui->home,SIGNAL(clicked()),SLOT(modeHome()));
    connect(ui->shapes_recognize,SIGNAL(clicked()),SLOT(modeShapes()));
    connect(ui->cannon_measure,SIGNAL(clicked()),SLOT(modeCannon()));
    connect(ui->measure_button,SIGNAL(clicked()),SLOT(startMeasure()));
    connect(ui->home_4,SIGNAL(clicked()),SLOT(calculate()));


    //Mouse Callback for cannon mode
    connect(ui->display_image_2,SIGNAL(Mouse_Pos()),this,SLOT(Mouse_current_pos()));
    connect(ui->display_image_2,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
    connect(ui->display_image_2,SIGNAL(Mouse_Left()),this,SLOT(Mouse_left()));


    /* WIDGET CONNECTIONS */
    connect(ui->trackbar_circle,SIGNAL(valueChanged(int)),this,SLOT(valueTrackbar(int)));
    connect(this,SIGNAL(messageArrived(QString,int)),this,SLOT(setMessageConsole(QString,int)));

    //LOAD ICONS BUTTONS
    icon.addFile(QString::fromUtf8("images/microchip-solid_w.png"), QSize(), QIcon::Normal, QIcon::Off);
    icon2.addFile(QString::fromUtf8("images/gamepad-solid_w.png"), QSize(), QIcon::Normal, QIcon::Off);
    video_icon.addFile(QString::fromUtf8("images/video_error.png"), QSize(), QIcon::Normal, QIcon::Off);
    auto_icon.addFile(QString::fromUtf8("images/robot-solid.png"), QSize(), QIcon::Normal, QIcon::Off);
    shapes_icon.addFile(QString::fromUtf8("images/shapes-solid.png"), QSize(), QIcon::Normal, QIcon::Off);
    home_icon.addFile(QString::fromUtf8("images/home.png"), QSize(), QIcon::Normal, QIcon::Off);
    auto_icon_w.addFile(QString::fromUtf8("images/robot-solid_w.png"), QSize(), QIcon::Normal, QIcon::Off);
    shapes_icon_w.addFile(QString::fromUtf8("images/shapes-solid_w.png"), QSize(), QIcon::Normal, QIcon::Off);
    home_icon_w.addFile(QString::fromUtf8("images/home_w.png"), QSize(), QIcon::Normal, QIcon::Off);
    cannon_icon.addFile(QString::fromUtf8("images/cannon.png"), QSize(), QIcon::Normal, QIcon::Off);
    cannon_icon_w.addFile(QString::fromUtf8("images/cannon_w.png"), QSize(), QIcon::Normal, QIcon::Off);
    term_icon.addFile(QString::fromUtf8("images/thermometer.png"), QSize(), QIcon::Normal, QIcon::Off);


    QPixmap pix;

    if(pix.load("images/LogoOcean.png")){
        /** scale pixmap to fit in label'size and keep ratio of pixmap */
        pix = pix.scaled(ui->logoLabel->size(),Qt::KeepAspectRatio);
        ui->logoLabel->setPixmap(pix);
    }

  /*  if(pix.load("images/grid.png")){
        // scale pixmap to fit in label'size and keep ratio of pixmap
        ui->gridLabel->setPixmap(pix);
    }
  */

    //SET ICON
    ui->atMega_status->setIcon(icon);
    ui->atMega_status->setIconSize(QSize(sizeIconComponent, sizeIconComponent));
    ui->joystick_status->setIcon(icon2);
    ui->joystick_status->setIconSize(QSize(sizeIconComponent, sizeIconComponent));
    ui->error_video->setIcon(video_icon);
    ui->error_video->setIconSize(QSize(sizeIconMenu,sizeIconMenu));
    ui->auto_drive->setIcon(auto_icon);
    ui->auto_drive->setIconSize(QSize(sizeIconMenu,sizeIconMenu));
    ui->shapes_recognize->setIcon(shapes_icon);
    ui->shapes_recognize->setIconSize(QSize(sizeIconMenu,sizeIconMenu));
    ui->home->setIcon(home_icon_w);
    ui->home->setIconSize(QSize(sizeIconMenu,sizeIconMenu));
    ui->cannon_measure->setIcon(cannon_icon);
    ui->cannon_measure->setIconSize(QSize(sizeIconMenu,sizeIconMenu));
    ui->term_sensor->setIcon(term_icon);
    ui->term_sensor->setIconSize(QSize(30,30));

    //-> setting TRACKBAR
    ui->trackbar_circle->setMaximum(400);


    value_track = 0;
    cnt = 0;
    left = Point(0,0);
    right = Point(0,0);
    a = 0;
    b = 0;
    l = 0;
    unit = 0;
    turn = 0;
    snap_b = false;
    snap = false;
    snap_a = false;
}

MainWindow::~MainWindow()
{
    cap.release();
    delete ui;
}

void MainWindow::DisplayImage(){

    Mat img_hls,res,frame;

    if(video){
        cap >> frame;
        img = frame;

        cvtColor(img,img_hls,CV_BGR2HLS);
        cvtColor(img,img,CV_BGR2RGB);
        cv::resize(img, img, cv::Size(1024,720));
        if(mode == MODE::MODE_HOME){
            //img = Vision::addCircle(frame,value_track);
            QImage cam1((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
            ui->display_image->setPixmap(QPixmap::fromImage(cam1));
        }

        if(mode  == MODE::MODE_AUTO){
            Mat filtered = Vision::filterRed(img_hls);
            Direction dir = autodrive.updateDirection(filtered);
            std::cout << "Ciao" << std::endl;

            QImage cam1((uchar*)filtered.data, filtered.cols, filtered.rows, filtered.step, QImage::Format_Grayscale8);
            ui->display_image->setPixmap(QPixmap::fromImage(cam1));
        }

        else if(mode == MODE::MODE_SHAPES){

                    shape = Vision::getImageBlackShape(img,value_track);
                    ui->display_image_2->setVisible(true);
                    //DRAW THE REGION OF INTEREST
                    rectangle( shape,Point(200,200),Point(800,600),Scalar( 255, 255, 255 ),1,LINE_4 );

                    //SELECT ONLY THIS REGION OF THE IMAGE
                    Rect roi;
                    roi.x = 200;
                    roi.y = 200;
                    roi.width = (800-200);
                    roi.height=(600-200);
                   // shape = shape(roi);

                    if(!ui->debugCheck->isChecked()){
                         QImage cam1((uchar*)shape.data, shape.cols, shape.rows, shape.step, QImage::Format_Grayscale8);
                         ui->display_image->setPixmap(QPixmap::fromImage(cam1));
                     }
                     else if(ui->debugCheck->isChecked()){

                         debug = true;
                         res = Vision::getshape(shape,debug,mean,moda);
                         QImage cam1((uchar*)res.data, res.cols, res.rows, res.step,QImage::Format_RGB888);
                         ui->display_image->setPixmap(QPixmap::fromImage(cam1));
                     }

                   if(snap_b){
                       shape = shape(roi);
                       debug = false;

                       if(moda!=20){
                            mean++;
                            res = Vision::getshape(shape,debug,mean,moda);
                        }

                       if(mean == 20 ){
                           mean=0;
                           moda++;
                           QImage cam2((uchar*)res.data, res.cols, res.rows, res.step, QImage::Format_RGB888);
                           ui->display_image_2->setPixmap(QPixmap::fromImage(cam2));
                           //snap_b = false;
                       }
                       if(moda==20){
                           res = Vision::getshape(shape,debug,mean,moda);
                           QImage cam2((uchar*)res.data, res.cols, res.rows, res.step, QImage::Format_RGB888);
                           ui->display_image_2->setPixmap(QPixmap::fromImage(cam2));
                           moda = 0;
                           snap_b = false;
                       }



                   }


                }

        if(mode == MODE::MODE_CANNON){

            QImage cam1((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
            ui->display_image->setPixmap(QPixmap::fromImage(cam1));
            if(snap_b){
                //imwrite( "/home/gianni/Downloads/cannon_mode.jpg", img );
                cnt = 1;
                snap_b = false;

            }

            if(cnt == 1){

               // Mat src = imread("/home/gianni/Downloads/cannon_mode.jpg");
                Mat src = imread("images/can3.png");
                cv::resize(src,src,cv::Size(900,720));
                rectangle( src,left,right,Scalar( 255, 0, 0 ),1,LINE_8 );

                if(snap_a){

                    Rect roi;
                    roi.x = left.x;
                    roi.y = left.y;
                    roi.width = (right.x - left.x);
                    roi.height= (right.x - left.x)*(900/720);

                    Mat zoom = src(roi);
                    cv::resize(zoom,zoom,cv::Size(900,720));

                    imwrite( "/home/gianni/Downloads/cannon_mode.jpg", zoom );
                    cnt = 2;

                }
                else{
                    QImage cam2((uchar*)src.data, src.cols, src.rows, src.step, QImage::Format_RGB888);
                    ui->display_image_2->setPixmap(QPixmap::fromImage(cam2));
                }
            }
            if(cnt == 2){

                Mat src = imread("/home/gianni/Downloads/cannon_mode.jpg");

                line(src,left,right,Scalar(0,0,255),1,LINE_8);

                QImage cam2((uchar*)src.data, src.cols, src.rows, src.step, QImage::Format_RGB888);
                ui->display_image_2->setPixmap(QPixmap::fromImage(cam2));

            }
        }
    }
}



void MainWindow::setVideoStart()
{
    //TOOGLE START VIDEO
    video = !video;
    if(video){
        ui->error_video->setIcon(QIcon());  }
    else{
        ui->error_video->setIcon(video_icon);
        ui->error_video->setIconSize(QSize(sizeIconMenu,sizeIconMenu));

    }
}

void MainWindow::modeAuto()
{
    mode = MODE::MODE_AUTO;
    ui->auto_drive->setIcon(auto_icon_w);
    ui->auto_drive->setIconSize(QSize(sizeIconMenu,sizeIconMenu));

    ui->home->setIcon(home_icon);
    ui->home->setIconSize(QSize(sizeIconMenu,sizeIconMenu));
    ui->shapes_recognize->setIcon(shapes_icon);
    ui->shapes_recognize->setIconSize(QSize(sizeIconMenu,sizeIconMenu));
    ui->cannon_measure->setIcon(cannon_icon);
    ui->cannon_measure->setIconSize(QSize(sizeIconMenu,sizeIconMenu));
}


void MainWindow::setMessageConsole(QString msg,int type)
{
    QString color_red,color_yellow,color_black;
    QString label;

    if(type == -1){
        label = "[ERROR]: ";
        color_red ="<span style=\"font-weight:600; color:#a40000;\">";
        color_red.append(label);
        color_red.append("</span>");
        color_red.append(msg);
        ui->console->append(color_red);
    }

    else if(type == 0){
        label = "[MESSAGE]: ";
        color_black = "<span style=\"font-weight:600;\">";
        color_black.append(label);
        color_black.append("</span>");
        color_black.append(msg);
        ui->console->append(color_black);
    }

    else if(type == 1){
        label = "[COMPONENT]: ";
        color_yellow = "<span style=\"font-weight:600;color:#204a87;\">";
        color_yellow.append(label);
        color_yellow.append("</span>");
        color_yellow.append(msg);
        ui->console->append(color_yellow);
    }

    ui->console->scrollBarWidgets(Qt::AlignBottom);
}

void MainWindow::Mouse_current_pos()
{
    if(snap){
       left = Point(ui->display_image_2->x,ui->display_image_2->y);
    }
}

void MainWindow::Mouse_Pressed()
{
        snap = true;
        right = Point(ui->display_image_2->x,ui->display_image_2->y);

}

void MainWindow::Mouse_left()
{
        snap = false;
}

void MainWindow::modeShapes()
{
    mode = MODE::MODE_SHAPES;

    /* Draw white icon */
    ui->shapes_recognize->setIcon(shapes_icon_w);
    ui->shapes_recognize->setIconSize(QSize(sizeIconMenu,sizeIconMenu));
    ui->auto_drive->setIcon(auto_icon);
    ui->auto_drive->setIconSize(QSize(sizeIconMenu,sizeIconMenu));
    ui->home->setIcon(home_icon);
    ui->home->setIconSize(QSize(sizeIconMenu,sizeIconMenu));
    ui->cannon_measure->setIcon(cannon_icon);
    ui->cannon_measure->setIconSize(QSize(sizeIconMenu,sizeIconMenu));
}

void MainWindow::modeCannon()
{
    mode = MODE::MODE_CANNON;

    /* Draw white icon */
    ui->cannon_measure->setIcon(cannon_icon_w);
    ui->cannon_measure->setIconSize(QSize(sizeIconMenu,sizeIconMenu));
    ui->auto_drive->setIcon(auto_icon);
    ui->auto_drive->setIconSize(QSize(sizeIconMenu,sizeIconMenu));
    ui->home->setIcon(home_icon);
    ui->home->setIconSize(QSize(sizeIconMenu,sizeIconMenu));
    ui->shapes_recognize->setIcon(shapes_icon);
    ui->shapes_recognize->setIconSize(QSize(sizeIconMenu,sizeIconMenu));
}
void MainWindow::modeHome()
{
    mode = MODE::MODE_HOME;
    ui->home->setIcon(home_icon_w);
    ui->home->setIconSize(QSize(sizeIconMenu,sizeIconMenu));

    ui->shapes_recognize->setIcon(shapes_icon);
    ui->shapes_recognize->setIconSize(QSize(sizeIconMenu,sizeIconMenu));
    ui->auto_drive->setIcon(auto_icon);
    ui->auto_drive->setIconSize(QSize(sizeIconMenu,sizeIconMenu));
    ui->cannon_measure->setIcon(cannon_icon);
    ui->cannon_measure->setIconSize(QSize(sizeIconMenu,sizeIconMenu));

}

void MainWindow::setJoystick(bool connected)
{

    if(connected){
        ui->joystick_status->setStyleSheet("QPushButton{background-color: #64dd17; }");
    }
    else{
        ui->joystick_status->setStyleSheet("QPushButton{background-color: #c62828; }");
    }

}

void MainWindow::setAtMega(bool connected)
{

    if(connected){
        ui->atMega_status->setStyleSheet("QPushButton{background-color: #64dd17; }");
    }
    else{
        ui->atMega_status->setStyleSheet("QPushButton{background-color: #c62828; }");
    }

}

void MainWindow::valueTrackbar(int value)
{
    value_track = value;
    ui->lcdNumberTrackbar->display(value);
}


void MainWindow::startMeasure()
{
    snap_b = true;
}
void MainWindow::calculate()
{
    snap_a = !snap_a;


    a = abs(left.x-right.x);
    b = abs(left.y-right.y);
    l = sqrt(pow(a,2) + pow(b,2));
    if(turn == 0){

        ui->lblMouse_unit->setText(QString("Unit = 0"));
        ui->lblMouse_R1->setText(QString("R1 = 0"));
        ui->lblMouse_R2->setText(QString("R2 = 0"));
        ui->lblMouse_L->setText(QString("L = 0"));
        turn++;
    }
    else if(turn == 1){
        //convesion pixel in cm
        unit = 11/l;

        ui->lblMouse_unit->setText(QString("Unit = %1 px").arg(unit));
        turn++;
    }
    else if(turn==2){
        L = l*unit;
        ui->lblMouse_L->setText(QString("L = %1 cm").arg(L));
        turn++;
    }
    else if(turn==3){
        R1 = l*unit;
        ui->lblMouse_R1->setText(QString("R1 = %1 cm").arg(R1));
        turn++;

    }
    else{
        R2 = l*unit;
        ui->lblMouse_R2->setText(QString("R2 = %1 cm").arg(R2));
        turn = 0;

    }


}

