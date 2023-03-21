#include <iostream>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

static void f1(), f2();

int main() {
    f1();
    f2();
    return 0;
}

static void f1() {
    pid_t pid;
    if ((pid = vfork()) < 0) {
        cout<<"vfork error";
    }
}

static void f2() {
    char buf[1000];
    int i;

    for (i = 0; i < sizeof(buf); i++) {
        buf[i] = 0;
    }
}
