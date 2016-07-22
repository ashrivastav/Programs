#ifdef _POSIX_THREADS
#endif

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


void printids(const char *s)
{
	pid_t pid;
	pthread_t tid;
	pid= getpid();
	tid=pthread_self();
	printf("%s pid %u tid 5u ()x%x)\n",s,(unsigned int)pid, (unsigned int)tid, (unsigned int)tid);
}

void *thr_fn(void *arg, const char *p)
{
		printids(p);
		return((void *)0);
}


int main(void)
{
	
	int err;
	void *tret;
	pthread_t t1;
	pthread_t t2;
	err=pthread_create(&t1,NULL, thr_fn,"thread no. 1");
	if(err!=0)
		printf("can't create thread: %s\n ", err);
	err=pthread_create(&t2,NULL, thr_fn,"thread no. 2");
	if(err!=0)
		printf("can't create thread: %s\n ", err);

	pthread_join(t1,&tret);
	printids("main thread:");
	//sleep(1);
	exit(0);
}
