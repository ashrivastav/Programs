#include <future>
#include <thread>
#include <iostream>
#include <condition_variable>
#include <mutex>
#include <atomic>
#include <vector>

using namespace std;
const int numThreads = 10;

mutex printmutex;
condition_variable printcv[numThreads];
long long counter = 0;

void PrintNum(int threadval)
{
	while(1)
	{
		unique_lock<mutex> guard(printmutex);
		//threadval % numThreads -> condition variable index
		printcv[threadval % numThreads].wait(guard, [=]() 
										{return (counter % numThreads == threadval);});
		cout << "Thread id:" << this_thread::get_id() <<" Counter:" << counter++ << endl;
		guard.unlock();
		printcv[((threadval+1) % numThreads)].notify_one();
		this_thread::sleep_for(chrono::seconds(1));
	}
}

int main()
{
	vector<thread> pool;
	for (int i = 0; i < numThreads; i++)
	{
		pool.push_back(thread(PrintNum, i));
	}

	for(auto &th : pool)
	{
		th.join();
	}
	return 0;
}


