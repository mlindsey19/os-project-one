//
// Created by mlind on 2/7/2019.
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
    int p[128];
    int thislong = 1 + pos[0] / 4;
    sleep(thislong);
    int shmid = shmget (SHMKEY, sizeof(p[2]), 0777);

    if (shmid == -1)
    {
        perror("child: Error shmid");
    }

   pos = ( int * ) ( shmat ( shmid, 0, 0 ) );

    readFile(infilename, outfilename, x,  pos);

}
