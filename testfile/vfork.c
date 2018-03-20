#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int glob = 3;
int main (void)
{
	pid_t pid;
	int loc = 3;
	if ((pid = vfork())<0){
		printf("vfork()error.\n");
		exit(0);
	}
	if(pid == 0){
		glob++;
		loc--;
		printf("child process changes glob and loc:\n");
		printf("glob=%d,loc=%d.\n",glob,loc);
	} 
	else{
		printf("parent process doesnt change the glob and loc.\n");
		printf("glob = %d,loc = %d.\n",glob,loc);
	}
exit(0);
}
