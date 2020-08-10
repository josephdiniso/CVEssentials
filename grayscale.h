#include <iostream>
#include <math.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


Mat grayscaleIntensity(Mat image) 
    /*
    Creates simple grayscale image by average color values of each pixel
    @param (Mat) image: Image to convert to grayscale
    @return (Mat): Grayscale image
    */
{
    // Creates blank image with a single color channel
    Mat grayscale(image.rows, image.cols, CV_8UC1, Scalar(0));
    for (int j=0; j<image.cols; j++) {
        for (int i=0; i<image.rows; i++) {
            auto pixelVal = image.at<Vec3b>(i,j);
            grayscale.at<uchar>(i,j) = (pixelVal[0]+pixelVal[1]+pixelVal[2]) / 3;
        }
    }
    return grayscale;
}

Mat grayscaleGleam(Mat image, float gamma=2.2)
{
    /*
    Creates grayscale image with gamma color correction
    @param gamma (float): gamma value for calculation
    @return (Mat): Gleam grayscale image
    */
    Mat grayscale(image.rows, image.cols, CV_8UC1, Scalar(0));  
    for (int j=0; j<image.cols; j++) {
        for (int i=0; i<image.rows; i++) {
            Vec3b pixel = image.at<Vec3b>(i,j);
            float val = 255*pow(float(pixel[0])/255, 1/gamma) + 
                        255*pow(float(pixel[1])/255, 1/gamma) +
                        255*pow(float(pixel[2])/255, 1/gamma);
            val /= 3;
            grayscale.at<uchar>(i,j) = int(val);
        }
    }
    return grayscale;
}


Mat grayscaleLuminance(Mat image) 
    /*
    Creates simple grayscale image by luminance
    @param (Mat) image: Image to convert to grayscale
    @return (Mat): Grayscale image
    */
{
    // Creates blank image with a single color channel
    Mat grayscale(image.rows, image.cols, CV_8UC1, Scalar(0));
    for (int j=0; j<image.cols; j++) {
        for (int i=0; i<image.rows; i++) {
            auto pixelVal = image.at<Vec3b>(i,j);
            grayscale.at<uchar>(i,j) =  0.3*float(pixelVal[2]) +
                                        0.59*float(pixelVal[1])+
                                        0.11*float(pixelVal[0]);
        }
    }
    return grayscale;
}


Mat grayscaleLuma(Mat image, float gamma=2.2) 
    /*
    Creates simple grayscale image by luma
    @param (Mat) image: Image to convert to grayscale
    @return (Mat): Grayscale image
    */
{
    // Creates blank image with a single color channel
    Mat grayscale(image.rows, image.cols, CV_8UC1, Scalar(0));
    for (int j=0; j<image.cols; j++) {
        for (int i=0; i<image.rows; i++) {
            auto pixel = image.at<Vec3b>(i,j);
            grayscale.at<uchar>(i,j) = 0.2126*255*pow(float(pixel[0])/255, 1/gamma) + 
                        0.7152*255*pow(float(pixel[1])/255, 1/gamma) +
                        0.0722*255*pow(float(pixel[2])/255, 1/gamma);
        }
    }
    return grayscale;
}


Mat grayscaleLightness(Mat image)
    /*
    Conversion to grayscale using lightness method (WIP)
    @param image (Mat): Input image to convert to grayscale
    @return (Mat): Grayscale image
    */
{
    Mat grayscale(image.rows, image.cols, CV_8UC1, Scalar(0));
    for (int j = 0; j<image.cols; j++) {
        for (int i = 0; i<image.rows; i++) {
            Vec3b pixel = image.at<Vec3b>(i,j);
            float Y = 0.2126*pixel[2]+0.7152*pixel[1]+0.0722*pixel[0];
            // Ternary operator for f(Y)    
            float f = (Y > pow((6/29), 3)) ? pow(Y, 1./3):1/3*pow((29./6), 2) * Y + 4/29;
            grayscale.at<uchar>(i,j) = 1./100*(116*f-16);
        }
    }
    return grayscale;
}


Mat grayscaleValue(Mat image)
{
    Mat grayscale(image.rows, image.cols, CV_8UC1, Scalar(0));
    for (int j = 0; j<image.cols; j++) {
        for (int i = 0; i<image.rows; i++) {
            Vec3b pixel = image.at<Vec3b>(i,j);
            uchar max = MAX(pixel[0], pixel[1]);
            max = MAX(max, pixel[2]);
            grayscale.at<uchar>(i,j) = max;
        }
    }
    return grayscale;   
}


Mat grayscaleLuster(Mat image)
{
    Mat grayscale(image.rows, image.cols, CV_8UC1, Scalar(0));
    for (int j = 0; j<image.cols; j++) {
        for (int i = 0; i<image.rows; i++) {
            Vec3b pixel = image.at<Vec3b>(i,j);
            int max = MAX(pixel[0], pixel[1]);
            max = MAX(pixel[2], max);
            int min = MIN(pixel[0], pixel[1]);
            min = MIN(pixel[2], min);
            grayscale.at<uchar>(i,j) = 1./2*(min+max);
        }
    }
    return grayscale;
}