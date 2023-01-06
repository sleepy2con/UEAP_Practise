#include <iostream>
#include <ourhdr.h>
using namespace std;

void set_fl(int fd, int flags)
{
	int val;
	if ((val = fcntl(fd, F_GETFL, 0)) < 0)
		cout << "fcntl F_GETFL err";
	val |= flags;
	if (fcntl(fd, F_SETFL, val) < 0)
		cout << "fcntl F_SETFL err";
}

int main()
{


	return 0;
}