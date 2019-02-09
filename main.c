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
    pid_t  currentpid;
    int errno;
    int i, x;
    int * pos;

    checkArgs(&inFilename, &outFilename, argc, argv);

    pos = parent();
    readFile(inFilename, outFilename, &x, pos);

    const int K = x;
    assert(K < 126 && "there is only enough shared memory for 126 child pids");

    for (i = 0; i < K; i++) {
        if (i==0)
            pos[1] = getppid();


        if (getppid() == pos[1] ) {
            wait(NULL);
            if ((currentpid = fork() < 0)) {
                perror("error forking child");
                return (1);
            }
            if (getppid() != pos[1]) {
                child(inFilename, outFilename, &x, pos);
                pos[i + 2] = getpid();
            }
        }
    }
    if (getppid() == pos[1] ){


        wait(NULL);
        FILE *fPtr = fopen(outFilename, "a");
        if (!fPtr) {
            perror("wf: could not open file");
            return 1;
        }

        char  string[50] = "";

        for (i = 2 ; i < (K + 2); i++){
            sprintf(string, "%s %d", string, pos[i]);
        }

        fprintf(fPtr, "%s: %s\n","all child", string);

        fclose(fPtr);
    }
    return 0;
}







