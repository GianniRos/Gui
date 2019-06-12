#include "autodrive.h"

AutoDrive::AutoDrive()
{

}

AutoDrive::AutoDrive(Direction startDirection)
{
    this->direction = startDirection;

}


Direction AutoDrive::updateDirection(Mat frame)
{

    if(direction == Direction::DOWN || direction == Direction::UP){

        if(Vision::checkLeft(frame)){
            direction == Direction::LEFT;
            /* SENDING MQTT TOPIC */
        }
        else if(Vision::checkRight(frame)){
            direction == Direction::RIGHT;

        }
    }

    else if(direction == Direction::LEFT || direction == Direction::RIGHT){

        if(Vision::checkTop(frame)){
            direction == Direction::LEFT;
            /* SENDING MQTT TOPIC */
        }
        else if(Vision::checkBottom(frame)){
            direction == Direction::RIGHT;
        }
    }

    return direction;
}
