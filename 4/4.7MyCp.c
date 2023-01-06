#include <iostream>
#include <ourhdr.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
using namespace std;

// mycp prog
int main(int argc, char* argv[])
{
	cout << "����:"<<argc <<" | \n";
	if (argc != 2)
		cout << "usage:4.7 [target file1] [to be Copyed file2]\n";
	char filePath[30];
	char filePath2BCopyed[30];

	strcpy(filePath, argv[1]);
	strcpy(filePath2BCopyed, argv[2]);
	cout << "�ļ�����,f1:" << filePath <<", f2:" << filePath2BCopyed << endl;

	int targetFd, fd2BCped;

	if (access(filePath2BCopyed, R_OK) < 0)
	{
		cout << "�ļ�·��������\n";
		exit(0);
	}

	//if (access(filePath, R_OK) >= 0)
	//{
	//	cout << "Ŀ��·���Ѵ����ļ����Ḳ��֮\n";
	//}

	// ���ļ�2.��ȡ����
	if ((fd2BCped = open(filePath, O_RDWR)) < 0)
	{
		cout << "���ļ�" << filePath2BCopyed << "ʧ��";
		exit(0);
	}
	off_t endPos = lseek(fd2BCped, 0, SEEK_END);
	off_t curPos = lseek(fd2BCped, 0, SEEK_SET);
	cout << "ĩβ��" << endPos << ", ��ʼ��" << curPos;
	off_t fileSize = endPos - curPos;
	char* tempContent = new char[fileSize + 1];
	if (read(fd2BCped, tempContent, fileSize) != fileSize)
	{
		cout << "��ȡ�ļ�ʧ��";
		exit(0);
	}
	
	cout <<"\n�ַ�����:"<< fileSize<<", ��ȡ�ַ���" <<tempContent << endl;
	cout << "\n";
	// ���ļ�1.д��
	if ((targetFd = open(filePath, O_CREAT, O_CREAT)) < 0)
	{
		cout << "���ļ�"<< filePath<<"ʧ��";
		exit(0);
	}
	if (lseek(targetFd, 0, SEEK_SET) == -1)
	{
		cout << "lseek�ļ�1ʧ��";
	}
	if (write(targetFd, tempContent, fileSize) != fileSize)
	{
		cout << "д���ļ�" << filePath << "ʧ��";
		exit(0);
	}

	cout << "success!\n";
	delete tempContent;
	return 0;
}