//
// Created by mlind on 2/7/2019.
//

#include <sys/shm.h>
#include <stdio.h>
#include "parent.h"

int * parent()
{
//get shared memory id

    int shmid = shmget (SHMKEY, BUFF_SZ, 0777 | IPC_CREAT);

    if ( shmid == -1 )
    {
        perror("parent: Error shmid");
    }

    // get pointer to shared block
    char *paddr = ( char * ) ( shmat ( shmid, 0, 0 ) );
    int * pint = ( int *)( paddr );
    *pint = 0;
}