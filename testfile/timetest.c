#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
int main()
{
struct timeval tv;
gettimeofday(&tv,NULL);
printf("time is:%ld%ldms\n",tv.tv_sec,tv.tv_usec/1000);
sleep(1);
gettimeofday(&tv,NULL);
printf("time is:%ld%ldms\n",tv.tv_sec,tv.tv_usec/1000);
suseconds_t ms = tv2.tv_usec-tv1.usec;
time_t sec = tv2.tv_sec-tv1.tv_sec;
printf("child process run time:%u.%us\n",sec,ms);
return 0;
}
