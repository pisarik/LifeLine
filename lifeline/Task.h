#ifndef TASK_H
#define TASK_H

#include <chrono>
using namespace std::chrono;

class Task{
	const time_point<system_clock> exec_time;
public:
	Task(const time_point<system_clock> &execution_time)
		: exec_time(execution_time){}
	virtual ~Task(){}

	virtual void execute() = 0;

	bool operator<(const Task &right){
		return this->exec_time < right.exec_time;
	};

	const time_point<system_clock>& execution_time() const{
		return exec_time;
	}
};

#endif