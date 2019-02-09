//
// Created by mlind on 2/7/2019.
//

#include <sys/shm.h>
#include <stdio.h>
#include "parent.h"
#include <assert.h>


int * parent()
{
//get shared memory id
int pos[128];
    int shmid = shmget (SHMKEY, sizeof(pos[2]) , 0777 | IPC_CREAT);

    if ( shmid == -1 )
    {
        perror("parent: Error shmid");
    }

    // get pointer to shared block
    char *paddr = ( char * ) ( shmat ( shmid, 0, 0 ) );
    int * pint = ( int *)( paddr );
    pint[0]=0;
    pint[1]= 0;
    return pint;
}