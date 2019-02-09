//
// Created by mlind on 2/7/2019.
//
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "readFile.h"
#include "writeFile.h"

static int getNextInt(const char * fileName, int * x, int *pos)
{
    FILE *fPtr;
    fPtr = fopen(fileName, "r");
    if (!fPtr) {
        perror("rf: could not open file");
        return 1;
    }
    fseek(fPtr, *pos, SEEK_SET);

    fscanf(fPtr, "%d", x);

    *pos = (int) ftell(fPtr);
    printf("pos: %d\n",*pos);
    fclose(fPtr);
    return  0;
}

int  readFile(const char * infileName,const char *outfilename, int * x,  int *pos)
{
    int i =0; // iterator
    if (*pos == 0)
    getNextInt(infileName, x, pos);
    if (*pos != 0 ){
        getNextInt(infileName, x, pos);
        int n =*x;
        int temp[n];
        for (i = 0; i < n; i++){
            getNextInt(infileName, x, pos);
            temp [i] = *x;
        }
        writeFile(outfilename, temp, n);
    }
    return  0;
}

