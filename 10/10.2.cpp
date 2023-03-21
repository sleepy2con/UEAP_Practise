#include "ourhdr.h"
#include <errno.h>
#include <pwd.h>
#include <signal.h>
#include <unistd.h>

static void
my_alarm(int);

int main()
{
 struct passwd *ptr;
 signal(SIGALRM, my_alarm);
 alarm(1);
 while (1)
 {
  if ((ptr = getpwnam("vpp")) == NULL)
   printf("getpwnam err");
  if (strcmp(ptr->pw_name, "vpp") != 0)
   printf("return value corrupted!,pw_name= %s\n", ptr->pw_name);
 }
}

static void
my_alarm(int signo)
{
 struct passwd *rootPtr;
 printf("in signal handle\n");
 if ((rootPtr = getpwnam("vpp")) == NULL)
  err_sys("getpwnam(root) err");
//  alarm(1);
 return;
}