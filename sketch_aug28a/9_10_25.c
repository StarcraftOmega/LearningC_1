//Just for testing random code
#include <stdio.h>
#include <stdlib.h>

int main(){
    int number=0;
    int repeat=0;
    while(1){
        while(repeat==0){
            printf("Input number: ");
            if (scanf("%d",&number)!=1){//both uses scanf and reads it
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
            if (number<101&&number>0){
                printf("All good\n");
                break;
            }
        }
        printf("All good -2-\n");
        return(0);
    }
}