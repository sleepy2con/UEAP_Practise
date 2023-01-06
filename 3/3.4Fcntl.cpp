#include <iostream>
#include <ourhdr.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;

int main(int argc,char* argv[])
{
	int accmode, val;
	if (argc != 2)
		cout << "ÓÃ·¨£º3.4 <descriptor#>";
	if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
		cout << "fcntl err for fd" << atoi(argv[1]);

	accmode = val & O_ACCMODE;
	if (accmode == O_RDONLY) cout << "read only";
	else if (accmode == O_WRONLY) cout << "write only";
	else if (accmode == O_RDWR) cout << "read only";
	else cout << "unknown access mode";

	if (val & O_APPEND) cout << ", append";
	if (val & O_NONBLOCK) cout << ",nonblocking";
#if !defined(_POSIX_SOURCE) && defined(O_SYNC)
	if (val & O_SYNC) cout << ", synchronous writes";
#endif 
	cout << "\n";
	
	return 0;
}