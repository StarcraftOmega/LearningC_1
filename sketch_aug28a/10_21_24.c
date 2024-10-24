#include <stdio.h>
#include <stdlib.h>


int main(){
    float *array;
    int count;

    printf("How manny number will you be entering?");
    scanf("%d",&count);

    array=malloc(count * sizeof(int));

    printf("Enter in your %d number(s) with a space in between them: ",count);
    for (int i =0;i<count;i++){
        scanf("%f",&array[i]);
    }

    for (int i=0;i<count;i++){
        printf("[%f] ",array[i]);
    }



    return 0;
}