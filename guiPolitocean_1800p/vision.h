#ifndef VISION_H
#define VISION_H

#include <opencv2/opencv.hpp>


#define LINE_TICKNESS 2.0
#define SQUARE_LENGTH 21.0
#define OFFSET 2
#define TOLERANCE 3000

using namespace cv;

class Vision
{
public:
    Vision();
    static bool checkTop(Mat src);
    static bool checkLeft(Mat src);
    static bool checkRight(Mat src);
    static bool checkBottom(Mat src);

    /* FILTERS */
    static Mat filterRed(Mat src);
    static Mat filterBlue(Mat src);
    static Mat filterBlack(Mat src);
    static Mat addROI(Mat src);
    static bool isCentered(Mat srcBlackFiltered);
    static int getLenghtFromBlack(Mat black,Mat blue);
    static void getLenghtFromCenter(Mat src);

    static void Circle( cv::Mat img, int position[4]);
    static void Triangle( cv::Mat img ,int position[4]);
    static void Line( cv::Mat img,int position[4]);
    static void Rectangle( cv::Mat img, int position[4] );
    static cv::Mat getshape(cv::Mat image1,bool debug,int mean,int final);
    static cv::Mat getImageBlackShape(cv::Mat src,int thresh);
    static int mean_mode( int numeri[100]);

    static Mat addCircle(Mat src, int value);

private:
    int height,width;

};

#endif // VISION_H

