#include <iostream>
#include <ourhdr.h>
using namespace std;

int main()
{
	int n;
	const int SIZE = 8192;
	char buf[SIZE];
	while ((n = read(STDIN_FILENO, buf, SIZE)) > 0)
	{
		if ((write(STDOUT_FILENO, buf, n)) != n)
		{
			cout << "write err\n";
		}
		cout << "\n";
	}
	if (n < 0)
	{
		cout << "read err";
	}

	return 0;
}
