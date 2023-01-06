#include <iostream>
#include <ourhdr.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;
char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main()
{
	int fd;
	if ((fd = creat("file.hole", FILE_MODE)) < 0)
	{
		cout << "creat err";
	}
	if (write(fd, buf1, 10) != 10)
	{
		cout << "buf1 wirte err";
	}
	if ((lseek(fd, 40, SEEK_SET) == -1)
	{
		cout<<"lseek err";
	}
	if (write(fd, buf2, 10) != 10)
	{
		cout<<"buf2 write err";
	}
	exit(0);

	return 0;
}