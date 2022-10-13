#include <iostream>
#include <ourhdr.h>
using namespace std;

int main()
{
	int c;
	while ((c = getc(stdin)) != EOF)
	{
		if (putc(c, stdout) == EOF)
			cout << "output error\n";
	}
	if (ferror(stdin))
		cout << "input error\n";
	exit(0);
}