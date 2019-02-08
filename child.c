//
// Created by mlind on 2/7/2019.
//

#include <unistd.h>
#include <sys/shm.h>
#include <stdio.h>

#include "child.h"

void child()
{
    sleep(5);
    int shmid = shmget (SHMKEY, BUFF_SZ, 0777);
    char buf[128];

    if (shmid == -1)
    {
        perror("child: Error shmid");
    }


   int *cint = ( int * ) ( shmat ( shmid, 0, 0 ) );


}
