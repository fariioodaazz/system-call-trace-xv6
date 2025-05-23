#include "types.h"
#include "stat.h"
#include "user.h"
#include "trace.h"


void forkrun()
{
    int fr = fork();
    
    if(fr < 0) {
        printf(1, "fork failed\n");
        return;
    } else if(fr == 0) {
        // Child process
        close(open("README", 0));
        exit();
    } else {
        // Parent process
        wait();
    }
}

int main()
{
    printf(1, "Process is being traced:\n");
    trace(T_TRACE);
    forkrun();
    
    trace(T_UNTRACE);
    printf(1, "Process & forks being traced:\n");
    trace(T_TRACE | T_ONFORK);
    forkrun();
    
    printf(1, "Process not being traced:\n");
    trace(T_UNTRACE);
    forkrun();
    
    exit();
}
