/*
 * Image.h
 *
 *  Created on: Aug 19, 2020
 *      Author: jdiniso
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include <opencv2/opencv.hpp>

using namespace cv;


Vec3f updateColor(Vec3f paintColor, Vec3b finalColor, float jumpSize, int dirs[3]) {
	for (int i = 0; i < 3; i++) {
		if (int (paintColor[i]) != finalColor[i]) {
			paintColor[i] += dirs[i] * jumpSize;
		}
	}
	return paintColor;
}

Vec3b convToInt(Vec3f paintColor) {
	static Vec3b newPaintColor;
	for (int i = 0; i< 3; i++) {
		int newVal = static_cast<uint8_t>(paintColor[i]);
		newPaintColor[i] = newVal;
//		std::cout << "hereee:" << round(paintColor[i]) << std::endl;
//		std::cout << "here:" << newPaintColor[i] << std::endl;
	}
	return newPaintColor;
}

Mat drawCircle(Mat image, int radius, Vec3b color, int x, int y) {
//TODO: Add circle draw (GROSS)
}

Mat makeGradient(Mat image, Vec3b originalColor, Vec3b finalColor) {
	int dirs[3] = {0,0,0};

	for (int i = 0; i < 3; i++) {
		if (originalColor[i] > finalColor[i]) {
			dirs[i] = -1;
		}
		else {
			dirs[i] = 1;
		}
	}
	Vec3f paintColor = originalColor;
	for (int i = image.rows; i > 0; i--) {
		for (int j = 0; j < image.cols; j++) {
			Vec3b color = image.at<Vec3b>(Point(j,i));
			color[0] = paintColor[0];
			color[1] = paintColor[1];
			color[2] = paintColor[2];
			image.at<Vec3b>(Point(j,i)) = color;
		}
		paintColor = updateColor(paintColor, finalColor, 0.2, dirs);
	}
	namedWindow("img", WINDOW_AUTOSIZE);
	imshow("img", image);
	waitKey(0);
	return image;
}



#endif /* IMAGE_H_ */
