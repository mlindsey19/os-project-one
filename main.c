//David Lindsey
//cs4760
//2-5-19
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <errno.h>
#include <assert.h>


#include "readFile.h"
#include "child.h"
#include "parent.h"
#include "checkArgs.h"




int main (int argc, char **argv)
{

    char *inFilename = "input.dat";
    char *outFilename = "output.dat";
    pid_t  currentpid,childpid;
    int errno, status;
    int i, x;
    int * pos;

    checkArgs(&inFilename, &outFilename, argc, argv);

    pos = parent();
    readFile(inFilename, outFilename, &x, pos);

    const int K = x;
    assert(K == 3);

    for (i = 0; i < K; i++) {
        if (i==0)
            pos[1] = getppid();

        pos[K+1] = currentpid;

        if (getppid() == pos[1] ) {
            wait(NULL);
            if ((currentpid = fork() < 0)) {
                perror("error forking child");
                return (1);
            }
            if (getppid() != pos[1]) {
                child(inFilename, outFilename, &x, pos);

            }
        }
            printf("childpid: %d\n", childpid);

    }

    wait(NULL);
    return 0;
}







