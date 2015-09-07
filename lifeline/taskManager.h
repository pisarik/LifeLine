#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H
#include "task.h"
#include <queue>
#include <memory>

class TaskManager{
	std::priority_queue<std::unique_ptr<Task>> tasks_que;
public:
	void executeTasks();
	void add(Task *task);
};

#endif