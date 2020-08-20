#include "curl/curl.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <opencv2/opencv.hpp>
#include "nlohmann/json.hpp"
#include "PackData.h"
#include "Image.h"

using namespace nlohmann;
using namespace cv;
json toJson(const char* jsonString){
    json jsonObj;
    std::stringstream(jsonString) >> jsonObj;

    return jsonObj;

}
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}



int main() {
	  CURL *curl;
	  CURLcode res;
	  std::string readBuffer;

	  curl = curl_easy_init();
	  if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://www.alphavantage.co/query?function=TIME_SERIES_WEEKLY&symbol=AAPL&apikey=PS3ITVUEZVFNKB8N");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		json convert = toJson(readBuffer.c_str());
		int size = 1920 / 10;
		float prices[size];
		jsonToArr(&prices[0], convert, size);
		curl_easy_cleanup(curl);

		Mat image = Mat::zeros(Size(1500, 700),CV_8UC3);
		Vec3b originalColor = {163, 10, 138};
		Vec3b finalColor = {17, 175, 237};

		Mat newImage = makeGradient(image, originalColor, finalColor);

	  }

	  return 0;
	}
