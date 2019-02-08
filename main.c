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

#define SHMKEY 63139 //shared memory key
#define BUFF_SZ sizeof(int)



int main (int argc, char **argv)
{

    char *inFilename = NULL;
    char *outFilename = NULL;
    FILE *fPtr;
    pid_t  rpid;
    int status, errno;
    char *lines[128];
    int i, j, x;
    char buf[128];

    checkArgs(&inFilename, &outFilename, argc, argv);
    int c;

    opterr = 0;


    for (i = optind; i < argc; i++);
    printf("Non-option argument %s\n", argv[i]);

    printf("infilename: %s\n", inFilename);
    printf("outfilename: %s\n", outFilename);


    x = readFile("in.txt", buf, 0);
    pid_t childpid[x];


    for (i = 0; i < 0; i++)
    {
        if ((childpid[i] = fork()) < 0 )
        {
            perror ( "error forking child" );
            return(1);
        }
        if (childpid[i] )
        {
            child();
        }
    }

    parent();

    wait(NULL);
    return 0;
}







