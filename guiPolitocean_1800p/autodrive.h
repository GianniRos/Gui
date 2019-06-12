#ifndef AUTODRIVE_H
#define AUTODRIVE_H

#include "vision.h"
#include <opencv2/opencv.hpp>


enum class Direction{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class AutoDrive
{
public:
    AutoDrive();
    AutoDrive(Direction startDirection);
    Direction updateDirection(Mat frame);


private:
    Direction direction;
    Direction path[12];
    Mat grid;


};

#endif // AUTODRIVE_H
