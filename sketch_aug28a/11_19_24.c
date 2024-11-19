#include <stdio.h>

int main(){
    FILE *fptr=NULL;
    char c;
    char line [100];

    fptr = fopen("FilesProcessing.c","r");

    if (fptr ==NULL){
    printf("File does not exist");
    return 0;
    }
    while (fgets(line,100,fptr)){
        fputs(line,stdout);
    }
    return 0;
}

