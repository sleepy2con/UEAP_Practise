#include <iostream>
#include <ourhdr.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
using namespace std;

int main(int argc, char* argv[])
{
	struct stat fileState;
	for (int i = 1; i < argc; i++)
	{
		int tempFd = open(argv[i], O_RDWR);
		if (tempFd == -1)
		{
			cout << "open " << argv[i] << " failed\n";
			continue;
		}
		if (fstat(tempFd, &fileState) != 0)
			cout << "查看文件状态失败";
		else
		{
			cout << argv[i] << ", size:" << fileState.st_size 
				<< ",block(number of 512-byte blocks allocated):" << fileState.st_blocks 
				<<"blksize(best IO block size):"<<fileState.st_blksize << endl;
		}
	}
	return 0;
}