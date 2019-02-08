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

#define SHMKEY 63139 //shared memory key
#define BUFF_SZ sizeof(int)

void parent();
void child();
void helpMenu();

int checkArgs(char *, char * , int , char **);


int main (int argc, char **argv)
{

    char *inFilename = NULL;
    char *outFilename = NULL;

    checkArgs(inFilename, outFilename, argc, argv);
    printf("%s", inFilename);

    char buf[128];
    readFile("in.txt", buf, 0);


    FILE *fPtr;
    int i, j, x;


    fgets(buf, 128, fPtr) ;
    x =(int) buf[0];
    buf[0] = '\0';

    pid_t  rpid;
    int status, errno;
    pid_t childpid[x];
    char *lines[128];

    for (i = 0; i < x; i++)
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







