#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
char str[100] = "/home/zlr/test/";
strcat(str,argv[1]);
printf("%s\n",str);
return 0;
}
