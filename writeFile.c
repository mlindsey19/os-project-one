//
// Created by mlind on 2/8/2019.
//

#include "writeFile.h"
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>



int writeFile(const char * outfilename, int temp[], int n){
    pid_t currentpid = getpid();
    assert(currentpid != 0);
    FILE *fPtr = fopen(outfilename, "a");
    if (!fPtr) {
        perror("wf: could not open file");
        return 1;
    }

    char  string[50] = "";
    sprintf(string, "%d: ", currentpid);

    int i =0;
    for (i = n ; i > 0; i--){
        sprintf(string, "%s %d", string, temp[i - 1]);
    }
    fprintf(fPtr, "%s\n", string);

    fclose(fPtr);

    return 0;
}
