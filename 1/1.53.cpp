#include <iostream>
#include <ourhdr.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main()
{
	char buf[MAXLINE];
	pid_t pid;
	int status;
	cout << "%%";
	while (fgets(buf, MAXLINE, stdin) != NULL)
	{
		buf[strlen(buf) - 1] = 0;
		if ((pid == fork()) < 0)
			cout << "fork error" << endl;
		else if (pid == 0)
		{
			execlp(buf, buf, (char*)0);
			cout << "could't execute:%s:"<< buf<<endl;
			exit(127);
		}

		if ((pid = waitpid(pid, &status, 0)) < 0)
			cout<<"waitpid err"<<endl;
		cout << ("%%");
	}
	exit(0);

	return 0;
}