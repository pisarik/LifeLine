#ifndef PHOTO_TASK_H
#define PHOTO_TASK_H

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <string>

#include "task.h"

using namespace std;

class PhotoTask : public Task{
	void takePhoto(cv::Mat &outPhoto);
	void savePhoto(const cv::Mat &photo);
	string time_pointToString(const time_point<system_clock> &time);

public:
	PhotoTask(const time_point<system_clock> &execution_time)
		: Task(execution_time){}

	void execute() override;
};

#endif