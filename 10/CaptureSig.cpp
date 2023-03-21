#include <iostream>
#include <signal.h>
#include <unistd.h>
using namespace std;

// typedef void Sigfunc(int);
static void sig_usr(int);
// Sigfunc* signal(int,Sigfunc*);
// void (*signal (int s i g n o, void (f u n * c)(int))) (int);
int main()
{
    cout<<getpid()<<"\n";
    if(signal(SIGUSR1,sig_usr) == SIG_ERR)
    {
        cout<<"can't catch SIGUSR1";
    }
    if(signal(SIGUSR2,sig_usr) == SIG_ERR)
    {
        cout<<"can't catch SIGUSR2";
    }
    while(1)
    {
        pause();
    }
    return 0;
}

static void sig_usr(int signo)
{
    if(signo == SIGUSR1)
    {
        cout<<"received SIGUSR1\n";
    }
    else if(signo == SIGUSR2)
    {
        cout<<"received SIGUSR2\n";
    }
    else
    {
        cout<<"received signal "<<signo<<"\n";
    }
    return;
}