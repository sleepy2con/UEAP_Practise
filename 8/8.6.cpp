#include <sys/types.h>
#include <errno.h>
#include <pwd.h>
#include <signal.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
using namespace std;

void charatatime( char* str);
int main(int argc,char* argv[])
{
	pid_t pid;
	if((pid = fork()) < 0)
		cout<<"fork err\n";
	else if(pid == 0)
		charatatime("output from child\n");
	else 
		charatatime("output from parent\n");
	return 0;
}
void charatatime(char* str)
{
	char* ptr;
	int c;
	setbuf(stdout,NULL);
	for(ptr = str;c= *ptr++;)
	{
		putc(c,stdout);
	}
}