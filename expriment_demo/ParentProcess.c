#include<sys/types.h>
#include<sys/time.h>
#include<time.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
int main (int argc,char *argv[])
{
	int status;
	struct timeval tv1,tv2;
	pid_t pid;
	char *arg[] = {argv[1],NULL};
	char path[100] = "/home/zlr/test/";
	strcat(path,argv[1]);
	char *p = path;
	if ((pid = fork())<0){
		printf("fork() error.\n");
		exit(0);
	}else if(pid == 0){
		if(execv(p,arg)<0){
			printf("exec() error!\n");
			exit(-1);
		}	
	} else {
	gettimeofday(&tv1,NULL);
	printf("child process start at:%ld%ldms\n",tv1.tv_sec,tv1.tv_usec/1000);
	wait(&status);
	gettimeofday(&tv2,NULL);
	printf("child process finish at:%ld%ldms\n",tv2.tv_sec,tv2.tv_usec/1000);
	suseconds_t ms = tv2.tv_usec-tv1.tv_usec;
	time_t sec = tv2.tv_sec-tv1.tv_sec;
	printf("child process run time:%ld.%lds\n",sec,ms);
	}
exit(0);
}
