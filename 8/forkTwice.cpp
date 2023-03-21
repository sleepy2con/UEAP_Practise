#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;

void printWhoIam(int pid);

int glob = 5;

int main(int argc,char* argv[])
{
	cout << "before fork\n";
	pid_t pid;
	if ((pid = vfork()) < 0)
	{
		cout << "fork err\n";
	}
	else if (pid == 0)
	{
        printWhoIam(pid);
        cout<<" line: "<<__LINE__<<"\n";
        if((pid == fork()) < 0)
        {
            cout<<"fork err\n";
        }
        else if (pid > 0)
        {
            printWhoIam(pid);
            cout<<" line: "<<__LINE__<<"\n";
            exit(0);
        }
        printWhoIam(pid);
        cout<<" line: "<<__LINE__<<"\n";
        sleep(2);
        cout<<"second child,parent pid = "<<getppid()<<"\n";
        exit(0);
	}
    printWhoIam(pid);
    cout<<" line: "<<__LINE__<<"\n";
    if(waitpid(pid,NULL,0) != pid)
    cout<<"waitpid err\n";
	printWhoIam(pid);
    cout<<" line: "<<__LINE__<<"\n";
	return 0;
}



void printWhoIam(int pid)
{
    cout<<getpid()<<" :father pid, "<<getppid()<<
    ((pid == 0) ? " son process":" father process")<<" pid,"<<pid
    <<"\n";
}
