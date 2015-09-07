#ifndef RANDOM_TIME_TASK_H
#define RANDOM_TIME_TASK_H

#include "Task.h"
#include "TaskManager.h"
#include <memory>

using namespace std;

class RandomTimeTask : public Task{
	const weak_ptr<TaskManager> task_man;
	const unsigned int min_skip_sec;
	const unsigned int max_skip_sec;
public:
	RandomTimeTask(const weak_ptr<TaskManager> &task_manager, 
		time_point<system_clock> execute_time,
		unsigned int min_skip_seconds = 60,
		unsigned int max_skip_seconds = 120)
		: Task(system_clock::now())
		, task_man(task_manager)
		, min_skip_sec(min_skip_seconds)
		, max_skip_sec(max_skip_seconds){};

	void execute() override;
};

#endif 