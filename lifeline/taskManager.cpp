#include "TaskManager.h"
#include <thread>

void TaskManager::add(Task *task){
	tasks_que.push(std::unique_ptr<Task>(task));
}

void TaskManager::executeTasks(){
	while (!tasks_que.empty()){
		if (tasks_que.top()){
			Task &task = *tasks_que.top();

			std::this_thread::sleep_until(task.execution_time());
			task.execute();
		}
		tasks_que.pop();
	}
}