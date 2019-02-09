//David Lindsey
//cs4760
//2-5-19
//
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "readFile.h"
#include "writeFile.h"
#include <assert.h>


static int getNextInt(const char * fileName, int * x, int *pos)
{
    FILE *fPtr;
    fPtr = fopen(fileName, "r");
    if (!fPtr) {
        perror("rf: could not open file");
        return 1;
    }
    fseek(fPtr, *pos, SEEK_SET); // moves to correct position in file

    fscanf(fPtr, "%d", x); // get next integer after pos in file

    *pos = (int) ftell(fPtr); //this tells where the current position in file is

    fclose(fPtr);
    return  0;
}

int  readFile(const char * infileName,const char *outfilename, int * x,  int *pos)
{
    int i = 0; // iterator
    if (*pos == 0) {
        getNextInt(infileName, x, pos); // gets first line
        return 0;
    }
    if (*pos != 0 ){
        getNextInt(infileName, x, pos); // gets first integer in line before line
        const int n = *x; // number of integers to be read on next line
        int temp[n];
        for (i = 0; i < n; i++){
            getNextInt(infileName, x, pos); // reads each integer
            temp [i] = *x; // put them in array
        }
        writeFile(outfilename, temp, n); // send to be formatted and written to file
    }
    return  0;
}

