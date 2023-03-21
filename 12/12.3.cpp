#include "unpipc.h"

#define SEM_NAME "mysem"
int count = 0;

int main(int argc,char **argv)
{
 int i,nloop;
 sem_t* mutex;
 if(argc != 2)
 {
  err_quit("usage:incrl <#loops>");
 }
 nloop = atoi(argv[1]);
}