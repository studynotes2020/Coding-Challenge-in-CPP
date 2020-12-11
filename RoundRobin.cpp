#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

int totalQuantum = 0;
class Job{
public:
	float arrival_time;
	float service_time;
	char name;
	int priority;
	Job(float myArrival_time, float myService_time, char myName, int myPriority) :
		arrival_time(myArrival_time), service_time(myService_time),
		name(myName), priority(myPriority){}
};
Job getAJob(char name) {
	int arrival_timeInt = rand() % 1000; // will return num between 0 and 99
	float arrival_time = arrival_timeInt / 10.0;
	if (arrival_time > 99.0)
		arrival_time = 99.0;
	int service_timeInt = (rand() % 101); // will return num between 0 and 10
	float service_time = service_timeInt / 10.0;
	if (service_time == 0.0)
		service_time += 0.1; // service_time = 0.1 .. 10
	int priority = rand() % 5;
	if (priority == 0)
		priority += 1; // priority between 1 .. 4
	return Job(arrival_time, service_time, name, priority);
}

struct less_than_key
{
	inline bool operator() (const Job& job1, const Job& job2)
	{
		return (job1.arrival_time < job2.arrival_time);
	}
};


int roundRobin(vector<Job> jobs, float q) {
	queue<Job> queue;
	float currTime = 0, waitTime = 0, execTime = 0, initialWaitTime = 0;
	int nextJobIndex = 0;
	while (!queue.empty() || nextJobIndex < jobs.size())
	{
		if (!queue.empty())
		{
			Job cur = queue.front();
			queue.pop();
			cout << cur.name;
			waitTime += currTime - cur.arrival_time;
			currTime += min(cur.service_time, q);
			execTime += min(cur.service_time, q);
			for (int i = nextJobIndex; i < jobs.size(); i++)
			{
				if (jobs[i].arrival_time <= currTime)
				{
					queue.push(Job(jobs[i].arrival_time, jobs[i].service_time,
						jobs[i].name, jobs[i].priority));
					nextJobIndex = i + 1;
				}
				else
				{
					break;
				}
			}
			if (cur.service_time > q)
			{
				queue.push(Job(currTime, cur.service_time - q, cur.name, cur.priority));
			}
		}
		else
		{
			queue.push(Job(jobs[nextJobIndex].arrival_time, jobs[nextJobIndex].service_time,
				jobs[nextJobIndex].name, jobs[nextJobIndex].priority));
			if (jobs[nextJobIndex].arrival_time - currTime > 2)
			{
				if (currTime > 0.0)
				{
					cout << endl << "CPU is idle for more than 2 consecutive quanta; program quit." << endl;
					return -1;
				}
				else
				{
					initialWaitTime = jobs[nextJobIndex].arrival_time;
				}
			}
			currTime = jobs[nextJobIndex++].arrival_time;
		}
	}
	cout << endl << "average wait time: " << waitTime / jobs.size() << endl;
	cout << "average response time: " << waitTime / jobs.size() << endl;
	cout << "average turnaround time: " << (waitTime + execTime) / jobs.size() << endl;
	cout << "throughput: " << jobs.size() / (currTime - initialWaitTime) << endl;
	return 0;
}


int main()
{
	vector<Job> jobList;
	int seed = time(NULL);
	srand(seed); // guarantee consistency when debugging

	char initialName = 'A';
	int validRun = 0;
	while (validRun < 5)
	{
		cout << endl << "name " << "arrival_time " << "expected_run_time " << "priority" << endl;

		for (int i = 0; i < 26; i++)
		{
			Job job = getAJob(initialName++);
			jobList.push_back(job);
			cout << job.name << std::setw(16) << job.arrival_time << std::setw(18)
				<< job.service_time << std::setw(9) << job.priority << endl;
		}
		sort(jobList.begin(), jobList.end(), less_than_key());
		cout << "Running sequence:" << endl;
		if (roundRobin(jobList, 1) == 0)
			validRun++;
		initialName = 'A';
	}
	// system("pause");
	return 0;
}
