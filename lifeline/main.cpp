#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <chrono>
#include <thread>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <Windows.h>

using namespace std;
using namespace cv;
using namespace chrono;

void takePhoto(Mat &outPhoto);
void savePhoto(const Mat &photo);
string time_pointToString(const time_point<system_clock> &time);
void getRandomTimeAfter(const time_point<system_clock> &after,
	time_point<system_clock> &outTime);

const int seed = system_clock::now().time_since_epoch().count();
const int		MAX_SKIP_TIME_SEC = 60;
const string	OUTPUT_FOLDER = "C:\\Local\\Photos\\LongWayPhoto\\";

int WinMain(HINSTANCE hInsanse, HINSTANCE hPrevInstance, LPSTR str, int nShowCmd){
	srand(seed);

	Mat photo;
	time_point<system_clock> photoTime;
	while (true){
		getRandomTimeAfter(system_clock::now(), photoTime);

		cout << "Next photo time: " << time_pointToString(photoTime) << '\n';

		this_thread::sleep_until(photoTime);
		takePhoto(photo);
		savePhoto(photo);
	}
	return 0;
}

string time_pointToString(const time_point<system_clock> &time){
	time_t cTime = system_clock::to_time_t(time);
	struct tm * now = localtime(&cTime);

	ostringstream ss;
	std::streamsize sz = 2;
	ss << setfill('0');
	ss << now->tm_year + 1900 << '-'
		<< setw(2) << now->tm_mon + 1 << '-'
		<< setw(2) << now->tm_mday << ' '
		<< setw(2) << now->tm_hour << '.'
		<< setw(2) << now->tm_min;

	return ss.str();
}

void savePhoto(const Mat &photo){
	string photoName = time_pointToString(system_clock::now());
	string photoExt = ".jpg";

	imwrite(OUTPUT_FOLDER + photoName + photoExt, photo);
}

void takePhoto(Mat &outPhoto){
	VideoCapture capture = VideoCapture(0);

	if (!capture.isOpened())
		throw exception("Camera error");

	capture.read(outPhoto);

	waitKey(0);
	capture.release();
}

void getRandomTimeAfter(const time_point<system_clock> &after,
	time_point<system_clock> &outTime){
	outTime = after + duration<int>(rand() % MAX_SKIP_TIME_SEC + 60);
}