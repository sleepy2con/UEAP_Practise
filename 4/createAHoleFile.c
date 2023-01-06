#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ourhdr.h>
using namespace std;

int main()
{
	int fdHole, fdNoHole;
	char buf1[] = "ABCDEFGHIJ";
	char buf2[] = "abcdefghij";


	int len1 = strlen(buf1);
	int len2 = strlen(buf2);

	int len3 = (len1 + len2) * 2 + len2;
	char* buf3 = new char[len3];
	memset(buf3, 2, len3);


	// 制造空洞文件fdHold;
	fdHole = creat("fdHole", S_IREAD | S_IWRITE);
	if (fdHole < 0)
	{
		cout << "create fdHole err\n";
		goto ERROR_;
	}

	if (write(fdHole, buf1, len1) != len1)
	{
		cout << "write "<< fdHole<<" err\n";
		goto ERROR_;
	}
		
	if (lseek(fdHole, len3 - len2, SEEK_SET) == -1)
	{
		cout << "lseek err\n";
		goto ERROR_;
	}
		
	if (write(fdHole, buf2, len2) != len2)
	{
		cout << "write " << fdHole << " after lseek err\n";
		goto ERROR_;
	}

	// 制造非空洞文件fdNoHole;
	fdNoHole = creat("fdNoHole", S_IREAD | S_IWRITE);
	if (fdNoHole < 0)
	{
		cout << "create fdNoHole err\n";
		goto ERROR_;
	}
	if (write(fdNoHole, buf3, len3) != len3)
	{
		cout << "write3 err\n"; 
		goto ERROR_;
	}
		
ERROR_:
	delete buf3;
	return 0;

}