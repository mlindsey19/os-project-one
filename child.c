//David Lindsey
//cs4760
//2-5-19
//
#include <unistd.h>
#include <sys/shm.h>
#include <stdio.h>

#include "child.h"
#include "parent.h"
#include "readFile.h"
#include <assert.h>


void child( const char * infilename,const char * outfilename,int *x, int  *pos)
{
    int p[128]; // for size - im sure there is a better way
    int shmid = shmget (SHMKEY, sizeof(p[128]), 0777); //shared memory

    if (shmid == -1)
    {
        perror("child: Error shmid");
    }

   pos = ( int * ) ( shmat ( shmid, 0, 0 ) ); // attach shared memory

    readFile(infilename, outfilename, x,  pos); //this starts process of reading the line indicating number of integers
    //                                         to come in the next line. x: used to store each read integer
    //                                          pos:   keep track of position in file

}
