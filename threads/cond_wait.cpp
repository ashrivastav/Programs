#include <iostream>
#include <thread>
#include <condition_variable>
#include <atomic>
#include <vector>
#include <chrono>

using namespace std;
//print_seq1 --  All threads wait on single mutex single condition variable, Causing contention 
// Voluntry context switches
/* 
   Command being timed: "./cond_wait"
   -----------------------------------------------------------------User time (seconds): 2.31
   -----------------------------------------------------------------System time (seconds): 14.67
   Percent of CPU this job got: 172%
   Elapsed (wall clock) time (h:mm:ss or m:ss): 0:09.85
   Average shared text size (kbytes): 0
   Average unshared data size (kbytes): 0
   Average stack size (kbytes): 0
   Average total size (kbytes): 0
   Maximum resident set size (kbytes): 3220
   Average resident set size (kbytes): 0
   Major (requiring I/O) page faults: 0
   Minor (reclaiming a frame) page faults: 144
   ----------------------------------------------------------Voluntary context switches: 5957233
   Involuntary context switches: 758
Swaps: 0
File system inputs: 0
File system outputs: 0
Socket messages sent: 0
Socket messages received: 0
Signals delivered: 0
Page size (bytes): 4096
Exit status: 0


==18104== 
==18104== I   refs:      3,096,168,591
==18104== I1  misses:            2,490
==18104== LLi misses:            2,023
==18104== I1  miss rate:          0.00%
==18104== LLi miss rate:          0.00%
==18104== 
==18104== D   refs:      1,356,608,055  (929,652,816 rd   + 426,955,239 wr)
==18104== D1  misses:        4,725,662  (  4,722,938 rd   +       2,724 wr)
==18104== LLd misses:            9,904  (      8,092 rd   +       1,812 wr)
==18104== D1  miss rate:           0.3% (        0.5%     +         0.0%  )
==18104== LLd miss rate:           0.0% (        0.0%     +         0.0%  )
==18104== 
==18104== LL refs:           4,728,152  (  4,725,428 rd   +       2,724 wr)
==18104== LL misses:            11,927  (     10,115 rd   +       1,812 wr)
==18104== LL miss rate:            0.0% (        0.0%     +         0.0%  )

*/
 
std::condition_variable cv;
std::mutex mut;
int global_var = 0;
const int max_val = 1000000;
const int num_threads = thread::hardware_concurrency(); //8 On my system


void print_seq1(int i)
{
	while(1) {
		unique_lock<mutex> lk(mut);
		cv.wait(lk, [i] {return ( global_var > max_val || global_var % num_threads == i);});	
		if (global_var > max_val)
			break;
		cout << "thread id " << i << "value " << global_var++ << endl;
		lk.unlock();
		cv.notify_all();
	}
	cout << "exiting" << endl;
}




//print_seq2 --  All threads wait on their mutex and condition variable, Causing less cache ping pong
// Voluntry context switches reduced by 1/6th, so less contention and less sleep/wake
/*
   Command being timed: "./cond_wait"
   User time (seconds): 1.20
--------------------------------------------------------------------   System time (seconds): 3.14
   Percent of CPU this job got: 89%
   Elapsed (wall clock) time (h:mm:ss or m:ss): 0:04.87
   Average shared text size (kbytes): 0
   Average unshared data size (kbytes): 0
   Average stack size (kbytes): 0
   Average total size (kbytes): 0
   Maximum resident set size (kbytes): 3300
   Average resident set size (kbytes): 0
   Major (requiring I/O) page faults: 0
   Minor (reclaiming a frame) page faults: 145
---------------------------------------------------------------   Voluntary context switches: 1000156
   Involuntary context switches: 20
Swaps: 0
File system inputs: 0
File system outputs: 0
Socket messages sent: 0
Socket messages received: 0
Signals delivered: 0
Page size (bytes): 4096
Exit status: 0


==17836== 
==17836== I   refs:      2,371,791,066
==17836== I1  misses:            2,367
==17836== LLi misses:            2,023
==17836== I1  miss rate:          0.00%
==17836== LLi miss rate:          0.00%
==17836== 
==17836== D   refs:      1,028,447,439  (699,351,758 rd   + 329,095,681 wr)
==17836== D1  misses:        3,142,776  (  3,140,066 rd   +       2,710 wr)
==17836== LLd misses:            9,902  (      8,097 rd   +       1,805 wr)
==17836== D1  miss rate:           0.3% (        0.4%     +         0.0%  )
==17836== LLd miss rate:           0.0% (        0.0%     +         0.0%  )
==17836== 
==17836== LL refs:           3,145,143  (  3,142,433 rd   +       2,710 wr)
==17836== LL misses:            11,925  (     10,120 rd   +       1,805 wr)
==17836== LL miss rate:            0.0% (        0.0%     +         0.0%  )

*/


// Trying to use cache L1 local to each processor more effectively
struct cv_s {
	condition_variable cv;
	mutex mut;
	int pad[32];
	};



struct cv_s cv1[8];


void print_seq2(int i)
{
	while(1) {
		unique_lock<mutex> lk(cv1[i].mut);
		cv1[i].cv.wait(lk, [i] {return ( global_var > max_val || global_var % num_threads == i);});	
		if (global_var > max_val) {
			for(int i =0 ; i < num_threads; i++)
				cv1[i].cv.notify_all();
			break;
		}
		cout << "thread id " << i << "value " << global_var++ << endl;
		lk.unlock();
		cv1[(i+1) % num_threads].cv.notify_one();
	}
	cout << "exiting" << endl;
}

// print_seq3 - Lets use local variables and print those, instead of going to global variable
// Similar to seq2, not much changes in time
/*
   Command being timed: "./cond_wait"
   ------------------------------------------------User time (seconds): 1.19
   ------------------------------------------------System time (seconds): 3.18
   Percent of CPU this job got: 87%
   Elapsed (wall clock) time (h:mm:ss or m:ss): 0:04.98
   Average shared text size (kbytes): 0
   Average unshared data size (kbytes): 0
   Average stack size (kbytes): 0
   Average total size (kbytes): 0
   Maximum resident set size (kbytes): 3316
   Average resident set size (kbytes): 0
   Major (requiring I/O) page faults: 0
   Minor (reclaiming a frame) page faults: 147
   ------------------------------------------Voluntary context switches: 1000158
   Involuntary context switches: 31
Swaps: 0
File system inputs: 0
File system outputs: 0
Socket messages sent: 0
Socket messages received: 0
Signals delivered: 0
Page size (bytes): 4096
Exit status: 0
 */



bool flag[8] = {false};
void print_seq3(int i)
{
	int local_var =  i;
	while(1) {
		unique_lock<mutex> lk(cv1[i].mut);
		cv1[i].cv.wait(lk, [i, local_var] {return (flag[i] == true);});	
		if (local_var > max_val) {
			for(int i =0 ; i < num_threads; i++){
				flag[i] = true;
				cv1[i].cv.notify_all();
			}
			break;
		}

		cout << "thread id " << i << "value " << local_var << endl;
		local_var+=num_threads;
		flag[(i+1) % num_threads] = true;
		flag[i] = false;
		lk.unlock();
		cv1[(i+1) % num_threads].cv.notify_one();
	}
	cout << "exiting" << endl;
}


// print_seq4 - Just use of atomic and no synchronization between threads other than access to atomic variable
// Voluntary context switches are more compared to cv queue with less contention.
// Atomic updates needs bus freeze to update memory variable and cache sync as well
/*
   Command being timed: "./cond_wait"
   User time (seconds): 0.91
   System time (seconds): 4.54
   Percent of CPU this job got: 147%
   Elapsed (wall clock) time (h:mm:ss or m:ss): 0:03.68
   Average shared text size (kbytes): 0
   Average unshared data size (kbytes): 0
   Average stack size (kbytes): 0
   Average total size (kbytes): 0
   Maximum resident set size (kbytes): 3316
   Average resident set size (kbytes): 0
   Major (requiring I/O) page faults: 0
   Minor (reclaiming a frame) page faults: 146
-----------------------------------------------------------------   Voluntary context switches: 1373667
   Involuntary context switches: 4920
Swaps: 0
File system inputs: 0
File system outputs: 0
Socket messages sent: 0
Socket messages received: 0
Signals delivered: 0
Page size (bytes): 4096
Exit status: 0

 */

atomic<int> atomic_global_var(0);
void print_seq4(int i)
{
	while(1) {
		cout << "thread id " << i << "value " << atomic_global_var++ << endl;
		if (atomic_global_var >max_val)
			break;
	}
}

int main()
{
	vector<thread> workers;
	//void (*func)(int i) = print_seq1;
	void (*func)(int i) = print_seq2; // Preferable method for multiple threads sync
	//void (*func)(int i) = print_seq3;
	//void (*func)(int i) = print_seq4;
	flag[0] = true;
	cout << "Number of theads supported" << thread::hardware_concurrency() << endl;
	for (int i =0; i < num_threads ; i++) {
		workers.push_back(thread(func, i));
	}
	for (auto &w : workers)
		w.join();
}
