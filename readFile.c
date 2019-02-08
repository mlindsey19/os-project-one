//
// Created by mlind on 2/7/2019.
//
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "readFile.h"


int  readFile(const char * fileName, char * buf,  int lineNumber)
{

    FILE *fPtr;
    int x = 0;
    char * temp;

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