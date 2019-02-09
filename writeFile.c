//David Lindsey
//cs4760
//2-5-19
//
#include "writeFile.h"
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>



int writeFile(const char * outfilename, int temp[], int n){
    pid_t currentpid = getpid();
    FILE *fPtr = fopen(outfilename, "a");
    if (!fPtr) {
        perror("wf: could not open file");
        return 1;
    }

    char  string[50] = "";
    sprintf(string, "%d: ", currentpid); // concatenate pid of child reading this line

    int i =0;
    for (i = n ; i > 0; i--){ //creats a string of integers from line read in reverse order
        sprintf(string, "%s %d", string, temp[i - 1]);
    }
    fprintf(fPtr, "%s\n", string); //write final formated line to file

    fclose(fPtr);

    return 0;
}
