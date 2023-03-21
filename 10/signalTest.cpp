#include <cstring>
#include <iostream>
#include <pwd.h>
#include <signal.h>
#include <unistd.h>
using namespace std;

static void my_alarm(int);

int main() {
  struct passwd *ptr;
  signal(SIGALRM, my_alarm);
  alarm(1); //
  while (1) {
    if ((ptr = getpwnam("vpp")) == NULL)
      cout << "getpwnam err\n";
    if (strcmp(ptr->pw_name, "vpp") != 0) {
      cout << "return value corrupted!,pw_name = " << ptr->pw_name << "\n";
    }
  }
  return 0;
}

static void my_alarm(int signo) {
  struct passwd *rootptr;
  cout << "in signal handler\n";
  if ((rootptr = getpwnam("root")) == NULL)
    cout << "getpwnam(root) err\n";
  alarm(1);
  return;
}