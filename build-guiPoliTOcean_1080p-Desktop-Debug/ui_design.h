/********************************************************************************
** Form generated from reading UI file 'design.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESIGN_H
#define UI_DESIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <my_qlabel.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *display_image;
    my_qlabel *display_image_2;
    QPushButton *startVideo;
    QPushButton *joystick_status;
    QPushButton *atMega_status;
    QLabel *gradient;
    QLabel *gradient_2;
    QPushButton *error_video;
    QLabel *gradient_3;
    QPushButton *auto_drive;
    QPushButton *shapes_recognize;
    QLabel *gradient_4;
    QLabel *gradient_5;
    QLabel *gradient_6;
    QPushButton *home;
    QSlider *trackbar_circle;
    QLCDNumber *lcdNumberTrackbar;
    QLabel *logoLabel;
    QPushButton *cannon_measure;
    QLabel *gradient_7;
    QLabel *gradient_8;
    QPushButton *term_sensor;
    QTextEdit *console;
    QPushButton *home_3;
    QLabel *gradient_9;
    QPushButton *measure_button;
    QLabel *gradient_10;
    QLabel *lblMouse_unit;
    QPushButton *home_4;
    QLabel *lblMouse_R1;
    QLabel *lblMouse_L;
    QLabel *lblMouse_R2;
    QCheckBox *debugCheck;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1800, 1000);
        MainWindow->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color:white;\n"
"border-style: solid;\n"
"\n"
"border-width: 1px;\n"
"border-radius: 7px;\n"
"}\n"
"QMainWindow{\n"
"	background-color: #37474f;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        display_image = new QLabel(centralWidget);
        display_image->setObjectName(QStringLiteral("display_image"));
        display_image->setGeometry(QRect(10, 70, 900, 720));
        display_image->setStyleSheet(QLatin1String("border-style: solid;\n"
"border-color: #00838f ;\n"
"border-width: 3px;\n"
""));
        display_image_2 = new my_qlabel(centralWidget);
        display_image_2->setObjectName(QStringLiteral("display_image_2"));
        display_image_2->setGeometry(QRect(930, 70, 900, 720));
        display_image_2->setMouseTracking(true);
        display_image_2->setStyleSheet(QLatin1String("border-style: solid;\n"
"border-color: #00838f ;\n"
"border-width: 3px;"));
        display_image_2->setFrameShape(QFrame::NoFrame);
        startVideo = new QPushButton(centralWidget);
        startVideo->setObjectName(QStringLiteral("startVideo"));
        startVideo->setGeometry(QRect(10, 930, 131, 54));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        startVideo->setFont(font);
        startVideo->setStyleSheet(QLatin1String("background-color:#eeeeee;\n"
"color: black;\n"
"border-color: white;"));
        joystick_status = new QPushButton(centralWidget);
        joystick_status->setObjectName(QStringLiteral("joystick_status"));
        joystick_status->setGeometry(QRect(10, 850, 61, 61));
        joystick_status->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #64dd17; \n"
"\n"
"}"));
        atMega_status = new QPushButton(centralWidget);
        atMega_status->setObjectName(QStringLiteral("atMega_status"));
        atMega_status->setGeometry(QRect(80, 850, 61, 61));
        atMega_status->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #c62828;\n"
"}"));
        gradient = new QLabel(centralWidget);
        gradient->setObjectName(QStringLiteral("gradient"));
        gradient->setGeometry(QRect(10, 860, 61, 57));
        gradient->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0, y1:0.784, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(55, 71, 76, 255));\n"
"\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        gradient_2 = new QLabel(centralWidget);
        gradient_2->setObjectName(QStringLiteral("gradient_2"));
        gradient_2->setGeometry(QRect(80, 860, 61, 57));
        gradient_2->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0, y1:0.784, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(55, 71, 79, 255));\n"
"\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        error_video = new QPushButton(centralWidget);
        error_video->setObjectName(QStringLiteral("error_video"));
        error_video->setGeometry(QRect(130, 110, 400, 400));
        error_video->setStyleSheet(QStringLiteral("background-color: rgba(0,0,0,0);"));
        gradient_3 = new QLabel(centralWidget);
        gradient_3->setObjectName(QStringLiteral("gradient_3"));
        gradient_3->setGeometry(QRect(10, 930, 131, 61));
        gradient_3->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0, y1:0.784, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(55, 71, 76, 255));\n"
"\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        auto_drive = new QPushButton(centralWidget);
        auto_drive->setObjectName(QStringLiteral("auto_drive"));
        auto_drive->setGeometry(QRect(310, 850, 141, 131));
        auto_drive->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #00838f ; \n"
"\n"
"}"));
        shapes_recognize = new QPushButton(centralWidget);
        shapes_recognize->setObjectName(QStringLiteral("shapes_recognize"));
        shapes_recognize->setGeometry(QRect(460, 850, 131, 131));
        shapes_recognize->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #00838f ; \n"
"\n"
"}"));
        gradient_4 = new QLabel(centralWidget);
        gradient_4->setObjectName(QStringLiteral("gradient_4"));
        gradient_4->setGeometry(QRect(310, 850, 141, 141));
        gradient_4->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0, y1:0.784, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(55, 71, 76, 255));\n"
"\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        gradient_5 = new QLabel(centralWidget);
        gradient_5->setObjectName(QStringLiteral("gradient_5"));
        gradient_5->setGeometry(QRect(460, 850, 131, 141));
        gradient_5->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0, y1:0.784, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(55, 71, 76, 255));\n"
"\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        gradient_6 = new QLabel(centralWidget);
        gradient_6->setObjectName(QStringLiteral("gradient_6"));
        gradient_6->setGeometry(QRect(160, 850, 141, 141));
        gradient_6->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0, y1:0.784, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(55, 71, 76, 255));\n"
"\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        home = new QPushButton(centralWidget);
        home->setObjectName(QStringLiteral("home"));
        home->setGeometry(QRect(160, 850, 141, 131));
        home->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #00838f ; \n"
"\n"
"}"));
        trackbar_circle = new QSlider(centralWidget);
        trackbar_circle->setObjectName(QStringLiteral("trackbar_circle"));
        trackbar_circle->setGeometry(QRect(1570, 20, 171, 51));
        trackbar_circle->setMaximum(400);
        trackbar_circle->setOrientation(Qt::Horizontal);
        lcdNumberTrackbar = new QLCDNumber(centralWidget);
        lcdNumberTrackbar->setObjectName(QStringLiteral("lcdNumberTrackbar"));
        lcdNumberTrackbar->setGeometry(QRect(1640, 0, 64, 31));
        lcdNumberTrackbar->setProperty("value", QVariant(0));
        lcdNumberTrackbar->setProperty("intValue", QVariant(0));
        logoLabel = new QLabel(centralWidget);
        logoLabel->setObjectName(QStringLiteral("logoLabel"));
        logoLabel->setGeometry(QRect(640, -70, 641, 291));
        cannon_measure = new QPushButton(centralWidget);
        cannon_measure->setObjectName(QStringLiteral("cannon_measure"));
        cannon_measure->setGeometry(QRect(600, 850, 141, 131));
        cannon_measure->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #00838f ; \n"
"\n"
"}"));
        gradient_7 = new QLabel(centralWidget);
        gradient_7->setObjectName(QStringLiteral("gradient_7"));
        gradient_7->setGeometry(QRect(600, 850, 141, 141));
        gradient_7->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0, y1:0.784, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(55, 71, 76, 255));\n"
"\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        gradient_8 = new QLabel(centralWidget);
        gradient_8->setObjectName(QStringLiteral("gradient_8"));
        gradient_8->setGeometry(QRect(30, 20, 50, 45));
        gradient_8->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0, y1:0.784, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(55, 71, 76, 255));\n"
"\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        term_sensor = new QPushButton(centralWidget);
        term_sensor->setObjectName(QStringLiteral("term_sensor"));
        term_sensor->setGeometry(QRect(30, 10, 50, 50));
        term_sensor->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #00838f ; \n"
"\n"
"}"));
        console = new QTextEdit(centralWidget);
        console->setObjectName(QStringLiteral("console"));
        console->setGeometry(QRect(760, 850, 521, 131));
        console->setStyleSheet(QLatin1String("border-style: solid;\n"
"border-color: #00838f ;\n"
"border-width: 1px;"));
        home_3 = new QPushButton(centralWidget);
        home_3->setObjectName(QStringLiteral("home_3"));
        home_3->setGeometry(QRect(200, 10, 50, 50));
        home_3->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #00838f ; \n"
"\n"
"}"));
        gradient_9 = new QLabel(centralWidget);
        gradient_9->setObjectName(QStringLiteral("gradient_9"));
        gradient_9->setGeometry(QRect(200, 20, 50, 45));
        gradient_9->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0, y1:0.784, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(55, 71, 76, 255));\n"
"\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        measure_button = new QPushButton(centralWidget);
        measure_button->setObjectName(QStringLiteral("measure_button"));
        measure_button->setGeometry(QRect(1720, 690, 91, 81));
        measure_button->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #00838f ; \n"
"\n"
"}"));
        gradient_10 = new QLabel(centralWidget);
        gradient_10->setObjectName(QStringLiteral("gradient_10"));
        gradient_10->setGeometry(QRect(1720, 690, 91, 91));
        gradient_10->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0, y1:0.784, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(55, 71, 76, 255));\n"
"\n"
"border-width: 1px;\n"
"border-radius: 10px;"));
        lblMouse_unit = new QLabel(centralWidget);
        lblMouse_unit->setObjectName(QStringLiteral("lblMouse_unit"));
        lblMouse_unit->setGeometry(QRect(1310, 10, 111, 21));
        home_4 = new QPushButton(centralWidget);
        home_4->setObjectName(QStringLiteral("home_4"));
        home_4->setGeometry(QRect(1250, 10, 50, 50));
        home_4->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #00838f ; \n"
"\n"
"}"));
        lblMouse_R1 = new QLabel(centralWidget);
        lblMouse_R1->setObjectName(QStringLiteral("lblMouse_R1"));
        lblMouse_R1->setGeometry(QRect(1310, 30, 111, 21));
        lblMouse_L = new QLabel(centralWidget);
        lblMouse_L->setObjectName(QStringLiteral("lblMouse_L"));
        lblMouse_L->setGeometry(QRect(1430, 10, 101, 21));
        lblMouse_R2 = new QLabel(centralWidget);
        lblMouse_R2->setObjectName(QStringLiteral("lblMouse_R2"));
        lblMouse_R2->setGeometry(QRect(1430, 30, 91, 21));
        debugCheck = new QCheckBox(centralWidget);
        debugCheck->setObjectName(QStringLiteral("debugCheck"));
        debugCheck->setGeometry(QRect(270, 30, 92, 23));
        MainWindow->setCentralWidget(centralWidget);
        display_image->raise();
        display_image_2->raise();
        gradient->raise();
        joystick_status->raise();
        gradient_2->raise();
        atMega_status->raise();
        error_video->raise();
        gradient_3->raise();
        startVideo->raise();
        gradient_4->raise();
        gradient_5->raise();
        shapes_recognize->raise();
        auto_drive->raise();
        gradient_6->raise();
        home->raise();
        lcdNumberTrackbar->raise();
        logoLabel->raise();
        gradient_7->raise();
        cannon_measure->raise();
        gradient_8->raise();
        term_sensor->raise();
        trackbar_circle->raise();
        gradient_9->raise();
        home_3->raise();
        console->raise();
        gradient_10->raise();
        measure_button->raise();
        lblMouse_unit->raise();
        home_4->raise();
        lblMouse_R1->raise();
        lblMouse_L->raise();
        lblMouse_R2->raise();
        debugCheck->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        display_image->setText(QString());
        display_image_2->setText(QString());
        startVideo->setText(QApplication::translate("MainWindow", "Start Video", Q_NULLPTR));
        joystick_status->setText(QString());
        atMega_status->setText(QString());
        gradient->setText(QString());
        gradient_2->setText(QString());
        error_video->setText(QString());
        gradient_3->setText(QString());
        auto_drive->setText(QString());
        shapes_recognize->setText(QString());
        gradient_4->setText(QString());
        gradient_5->setText(QString());
        gradient_6->setText(QString());
        home->setText(QString());
        logoLabel->setText(QString());
        cannon_measure->setText(QString());
        gradient_7->setText(QString());
        gradient_8->setText(QString());
        term_sensor->setText(QString());
        console->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#204a87;\">-- PoliTOcean Carassius v2.0:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        home_3->setText(QString());
        gradient_9->setText(QString());
        measure_button->setText(QString());
        gradient_10->setText(QString());
        lblMouse_unit->setText(QApplication::translate("MainWindow", "Unit: ", Q_NULLPTR));
        home_4->setText(QString());
        lblMouse_R1->setText(QApplication::translate("MainWindow", "R1: ", Q_NULLPTR));
        lblMouse_L->setText(QApplication::translate("MainWindow", "L:", Q_NULLPTR));
        lblMouse_R2->setText(QApplication::translate("MainWindow", "R2: ", Q_NULLPTR));
        debugCheck->setText(QApplication::translate("MainWindow", "Debug", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESIGN_H
