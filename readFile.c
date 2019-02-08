//
// Created by mlind on 2/7/2019.
//
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "readFile.h"

static int readFile2(const char * fileName)
{
    FILE *fPtr;
    int x = 0;

    fPtr = fopen("in.txt", "r");
    if (!fPtr) {
        perror("could not open file");
        return 1;
    }
    x =  fgetc(fPtr);

    fclose(fPtr);
    return  x;
}

int  readFile(const char * fileName, char * buf,  int lineNumber)
{

    if (lineNumber == 0){
        return readFile2(fileName);
    }
    FILE *fPtr;
    int x = 0;
    char * temp = NULL;

    fPtr = fopen("in.txt", "r");
    if (!fPtr) {
        perror("could not open file");
        return 1;
    }

    while(!feof(fPtr)){
        temp =  fgets(temp,128,fPtr);
        if (lineNumber == x){
            buf = temp;
        }
        x++;
    }
    printf("%s", buf);

    fclose(fPtr);
    return  0;
}

