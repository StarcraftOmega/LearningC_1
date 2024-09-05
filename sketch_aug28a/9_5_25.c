#include <stdio.h>
#include <stdlib.h>
#define size 3
int main(){
    int score[size]={5,2,67};
    int index;


    /*
    for(index=0;index<size;index++){
        score[index] = -1;
    }*/
    index=0;
    while (index<size){
        printf("score(%d)=%d\n",index,score[index]);
        index++;
    }
    
}