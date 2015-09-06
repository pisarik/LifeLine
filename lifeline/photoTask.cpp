#include <iostream>
#include <iomanip>

#include "photoTask.h"

void PhotoTask::execute(){
	cv::Mat photo;
	takePhoto(photo);
	savePhoto(photo);
}

void PhotoTask::takePhoto(cv::Mat &outPhoto){
	cv::VideoCapture capture = cv::VideoCapture(0);

	if (!capture.isOpened())
		throw exception("Camera error");

	capture.read(outPhoto);

	cv::waitKey(10);
	capture.release();
}

void PhotoTask::savePhoto(const cv::Mat &photo){
	const string OUTPUT_FOLDER = "";  //temporarily
	string photoName = time_pointToString(system_clock::now());
	string photoExt = ".jpg";

	cv::imwrite(OUTPUT_FOLDER + photoName + photoExt, photo);
}

string PhotoTask::time_pointToString(const time_point<system_clock> &time){
	time_t cTime = system_clock::to_time_t(time);
	struct tm * now = localtime(&cTime);

	ostringstream ss;
	ss << setfill('0');
	ss << now->tm_year + 1900 << '-'
		<< setw(2) << now->tm_mon + 1 << '-'
		<< setw(2) << now->tm_mday << ' '
		<< setw(2) << now->tm_hour << '.'
		<< setw(2) << now->tm_min;

	return ss.str();
}