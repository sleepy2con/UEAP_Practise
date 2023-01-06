#include <iostream>
#include <ourhdr.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
using namespace std;

// mycp prog
int main(int argc, char* argv[])
{
	cout << "参数:"<<argc <<" | \n";
	if (argc != 2)
		cout << "usage:4.7 [target file1] [to be Copyed file2]\n";
	char filePath[30];
	char filePath2BCopyed[30];

	strcpy(filePath, argv[1]);
	strcpy(filePath2BCopyed, argv[2]);
	cout << "文件名字,f1:" << filePath <<", f2:" << filePath2BCopyed << endl;

	int targetFd, fd2BCped;

	if (access(filePath2BCopyed, R_OK) < 0)
	{
		cout << "文件路径不存在\n";
		exit(0);
	}

	//if (access(filePath, R_OK) >= 0)
	//{
	//	cout << "目标路径已存在文件，会覆盖之\n";
	//}

	// 打开文件2.获取内容
	if ((fd2BCped = open(filePath, O_RDWR)) < 0)
	{
		cout << "打开文件" << filePath2BCopyed << "失败";
		exit(0);
	}
	off_t endPos = lseek(fd2BCped, 0, SEEK_END);
	off_t curPos = lseek(fd2BCped, 0, SEEK_SET);
	cout << "末尾：" << endPos << ", 起始：" << curPos;
	off_t fileSize = endPos - curPos;
	char* tempContent = new char[fileSize + 1];
	if (read(fd2BCped, tempContent, fileSize) != fileSize)
	{
		cout << "读取文件失败";
		exit(0);
	}
	
	cout <<"\n字符长度:"<< fileSize<<", 读取字符：" <<tempContent << endl;
	cout << "\n";
	// 打开文件1.写入
	if ((targetFd = open(filePath, O_CREAT, O_CREAT)) < 0)
	{
		cout << "打开文件"<< filePath<<"失败";
		exit(0);
	}
	if (lseek(targetFd, 0, SEEK_SET) == -1)
	{
		cout << "lseek文件1失败";
	}
	if (write(targetFd, tempContent, fileSize) != fileSize)
	{
		cout << "写入文件" << filePath << "失败";
		exit(0);
	}

	cout << "success!\n";
	delete tempContent;
	return 0;
}