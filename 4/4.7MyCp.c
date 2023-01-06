#include <iostream>
#include <ourhdr.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
using namespace std;

int my_cp(const char* f1, const char* f2)
{
	const int BUF_SIZE = 4096;
	int fd1, fd2;	// fd1,���������ļ���fd2��Ŀ���ļ�
	char buffer[BUF_SIZE];
	int res, current_position = 0;
	int byte_count = 0,have_holes = 0;
	struct stat st;

	fd1 = open(f1, O_RDWR);
	if (fd1 == -1)
	{
		cout << "open " << f1 << " failed\n";
		return -1;
	}
	if(fstat(fd1,&st) != 0)
		cout<< "�鿴�ļ�״̬ʧ��"��
	else
	{
		// �ж�����ͨ�ļ����ж��Ƿ��пն����ļ���С���ļ����С > ���� ��
		if (S_ISREG(st.st_mode)		
			&& st.st_size > 512 * st.st_blocks)	
		{
			have_holes = 1��
				cout << f1 << " �пն�\n";
		}
		else
		{
			cout << f1 << " �޿ն�\n";
		}
	}
	fd2 = open(f2, O_RDWR | O_APPEND | O_CREAT | OTRUNC, 0666);
	if (fd2 = -1)
	{
		cout << "open " << f2 << "failed";
		return -1;
	}
	memset(buffer, '\0', BUF_SIZE);
	res = read(fd1, buffer, BUF_SIZE);
	if (res == -1)
	{
		cout << "read " << f1 << "err";
		return -1;
	}
	if (have_holes)
	{

	}

}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "usage error : ./a.out file1 file2\n";
		return -1;
	}
	int res = my_cp(argv[1], argv[2]);
	if (res == -1)
	{
		cout << "mycp error";
		return -1;
	}
	exit(0);
}


// mycp prog
//int main(int argc, char* argv[])
//{
//	cout << "����:"<<argc <<" | \n";
//	if (argc != 2)
//		cout << "usage:4.7 [target file1] [to be Copyed file2]\n";
//	char filePath[30];
//	char filePath2BCopyed[30];
//
//	strcpy(filePath, argv[1]);
//	strcpy(filePath2BCopyed, argv[2]);
//	cout << "�ļ�����,f1:" << filePath <<", f2:" << filePath2BCopyed << endl;
//
//	int targetFd, fd2BCped;
//
//	if (access(filePath2BCopyed, R_OK) < 0)
//	{
//		cout << "�ļ�·��������\n";
//		exit(0);
//	}
//
//	//if (access(filePath, R_OK) >= 0)
//	//{
//	//	cout << "Ŀ��·���Ѵ����ļ����Ḳ��֮\n";
//	//}
//
//	// ���ļ�2.��ȡ����
//	if ((fd2BCped = open(filePath, O_RDWR)) < 0)
//	{
//		cout << "���ļ�" << filePath2BCopyed << "ʧ��";
//		exit(0);
//	}
//	off_t endPos = lseek(fd2BCped, 0, SEEK_END);
//	off_t curPos = lseek(fd2BCped, 0, SEEK_SET);
//	cout << "ĩβ��" << endPos << ", ��ʼ��" << curPos;
//	off_t fileSize = endPos - curPos;
//	char* tempContent = new char[fileSize + 1];
//	if (read(fd2BCped, tempContent, fileSize) != fileSize)
//	{
//		cout << "��ȡ�ļ�ʧ��";
//		exit(0);
//	}
//	
//	cout <<"\n�ַ�����:"<< fileSize<<", ��ȡ�ַ���" <<tempContent << endl;
//	cout << "\n";
//	// ���ļ�1.д��
//	if ((targetFd = open(filePath, O_CREAT, O_CREAT)) < 0)
//	{
//		cout << "���ļ�"<< filePath<<"ʧ��";
//		exit(0);
//	}
//	if (lseek(targetFd, 0, SEEK_SET) == -1)
//	{
//		cout << "lseek�ļ�1ʧ��";
//	}
//	if (write(targetFd, tempContent, fileSize) != fileSize)
//	{
//		cout << "д���ļ�" << filePath << "ʧ��";
//		exit(0);
//	}
//
//	cout << "success!\n";
//	delete tempContent;
//	return 0;
//}