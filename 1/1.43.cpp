#include <iostream>
#include <ourhdr.h>
using namespace std;

const int BUFFSIZE = 8192;
int main()
{
	int n;
	char buf[BUFFSIZE];
	while ((n = read(STDIN_FILENO, buf, BUFFSIZE))>0)
	{
		cout << "r:" << n << endl;
		int w = write(STDOUT_FILENO, buf, n);
		cout << "w:" << w << endl;
		if (w != n)
			cout << "write error\n";
	}
	if(n<0)
		cout<<"read error\n";

	exit(0);
}