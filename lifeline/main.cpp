#include <chrono>
#include <iostream>
#include <Windows.h>

#include "taskManager.h"
#include "photoTask.h"
#include "randomTimeTask.h"

using namespace std;
using namespace chrono;

const int seed = system_clock::now().time_since_epoch().count();
const string	OUTPUT_FOLDER = "C:\\Local\\Photos\\LongWayPhoto\\";

int WinMain(HINSTANCE hInsanse, HINSTANCE hPrevInstance, LPSTR str, int nShowCmd){
	srand(seed);

	shared_ptr<TaskManager> manager = make_shared<TaskManager>();
	manager->add(new RandomTimeTask(manager, system_clock::now()));
	manager->executeTasks();

	return 0;
}