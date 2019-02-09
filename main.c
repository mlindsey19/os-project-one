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


#include "readFile.h"
#include "child.h"
#include "parent.h"
#include "checkArgs.h"




int main (int argc, char **argv)
{

    char *inFilename = "input.dat";
    char *outFilename = "output.dat";
    pid_t  currentpid;
    int status, errno;
    int i, j, x;
    int * pos;


    checkArgs(&inFilename, &outFilename, argc, argv);

    pos = parent();
    readFile(inFilename, outFilename, &x, pos);


    printf("x: %i\n", x);

    for (i = 0; i < x; i++) {
        if (currentpid == 0) {
            if ((currentpid = fork()) < 0) {
                perror("error forking child");
                return (1);
            }
            if (currentpid != 0) {
                child(inFilename, outFilename, x, pos);
            }
        } wait(NULL);
    }

    parent();

    wait(NULL);
    return 0;
}







