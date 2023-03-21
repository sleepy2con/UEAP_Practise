#include <sys/types.h>
#include "ourhdr.h"
#include <errno.h>
#include <pwd.h>
#include <signal.h>
#include <unistd.h>
#include <iostream>
using namespace std;
static void sig_cld();
int main(int argc,char* argv[])
{
	pid_t pid;
	if(signal(SIGCLD,sig_cld) == -1)
	{
		perror("signal err");
	}
	if((pid = fork()) < 0)
	{
		perror("fork err");
	}
	else if(pid == 0)
	{
		sleep(2);
		_exit(0);
	}
	return;
}
static void sig_cld()
{
	pid_t pid;
	int status;
	cout<<"SIGCLD received\n";
	if(signal(SIGCLD,sig_cld) == -1)
	{
		perror("signal err");
	}
	if((pid = wait(&status)) < 0)
	{
		perror("wait err");
	}
	cout<<"pid = "<<pid<<"\n";
	return;
}