#include <iostream>
#include <ourhdr.h>
#include <unistd.h>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "usage:a.out [file1] [file2]\n";
		goto _FAIL_;
	}
	
	const BUF_SIZE = 30;
	int fd1, fd2;	// fd1 target file,fd2 to be copyed file;
	char buf[30];

	fd1 = open(argv[1], O_RDWR | O_APPEND | O_CREAT | OTRUNC, 0777);
	fd2 = open(argv[2], O_RDWR, 0777);
	cout << argv[1] << ","<<argv[2]<<endl;
	if (fd1 < 0 || fd2 < 0)
	{
		cout << "open file failed\n";
		goto _FAIL_;
	}

	while (read(fd2, buf, BUF_SIZE) != BUF_SIZE)
	{

	}


_FAIL_:
	return 0;
}