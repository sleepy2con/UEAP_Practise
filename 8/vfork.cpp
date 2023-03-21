#include <iostream>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

void printWhoIam(int pid);

int glob = 5;

int main(int argc,char* argv[])
{
	cout << "before fork\n";
	pid_t pid;
	
	int var = 88;

	if ((pid = vfork()) < 0)
	{
		cout << "vfork err\n";
	}
	else if (pid == 0)
	{
		var++;
		glob++;
        _exit(0);
	}

	printWhoIam(pid);
	cout << getpid() << " : glob,var " << glob<<" "<< var << "\n";
	return 0;
}



void printWhoIam(int pid)
{
	if (pid == 0)
	{
		cout << "I am son process now\n";
	}
	else
	{
		cout << "I am father,not a daemon\n";
	}
}
