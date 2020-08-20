#include <iostream>
#include <opencv2/opencv.hpp>

#include "filter.h"
#include "grayscale.h"
using namespace std;
using namespace cv;

int main(int, char**) {
    Mat image = imread("/home/jdiniso/lena.png", 1);
    resize(image, image, Size(500, 500));
    // filterImage(image);
    // convolveFilter(image);
    
    // Mat img = grayscaleLuminance(image);
    Mat img = grayscaleLuster(image);
    namedWindow("Filtered", WINDOW_AUTOSIZE);
    imshow("Filtered", img);
    waitKey(0);
    return 0;
}
