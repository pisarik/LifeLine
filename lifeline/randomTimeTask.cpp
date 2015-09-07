#include "randomTimeTask.h"
#include "photoTask.h"

void RandomTimeTask::execute(){
	time_point<system_clock> now = system_clock::now();
	duration<int> rand_inc = duration<int>(rand() % (max_skip_sec - min_skip_sec) + min_skip_sec);
	time_point<system_clock> exec_time = now + rand_inc;
	
	if (!task_man.expired()){
		auto manager = task_man.lock();
		manager->add(new PhotoTask(exec_time));
		manager->add(new RandomTimeTask(task_man, exec_time + duration<int>(1),
						min_skip_sec, max_skip_sec));
	}
}