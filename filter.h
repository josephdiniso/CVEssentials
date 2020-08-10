#include <iostream>
#include <math.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// WIP
Mat convolveFilter(Mat image, int padding)
{
    // TODO - Convert to B&W and call padding from here
    Mat filtered(image.rows-padding, image.cols-padding, CV_8UC3, (0,0,0));
    // 3x3 test array of size 3x3 (mxn) (rows x columns)
    float testKernel[3][3] = {{-1,0,1}, {-2,0,2}, {-1,0,1}};
    for (int j = padding; j<image.cols-padding; j++) {
        float sum = 0;
        // TODO: Add convolution
        for (int i = padding; i<image.rows-padding; i++) {
            cout << "hello";
        }
    }
    return image;
}

Mat applyZeroPadding(Mat image, int padding)
    /*
    @param image: Image to apply padding to 
    @param padding: Integer value for padding width on a single side
    @return Padded image
    */
{
    // Can handle non square images for padding
    resize(image, image, Size(400,500));
    Mat filtered(image.rows+padding*2, image.cols+padding*2, CV_8UC3, Scalar(0,0,0));
    for (int j = padding; j < image.rows+padding; j++) {
        for (int i = padding; i < image.cols+padding; i++) {
            /*255
            Vec3b is a typedef for:
                Vec<uchar, 3>
            The Point() function is used for 2 dimensional coordinates
            */
            filtered.at<Vec3b>(Point(i,j)) = image.at<Vec3b>(Point(i-padding,j-padding));
        }
    }
    return filtered;
}


Mat filterImage(Mat image) 
    /*
    @param (Mat) image: Image to filter
    @return (Mat): Filtered image
    */
{
    int padding = 100;
    
    Mat filtered = applyZeroPadding(image, 10);
    namedWindow("Filtered", WINDOW_AUTOSIZE);
    imshow("Filtered", filtered);
    waitKey(0);
    return filtered;
}
