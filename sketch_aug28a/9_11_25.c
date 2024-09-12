#include <stdio.h>
#include <math.h>

int main(){
    int inputNumber;
    int tempCounter;
    int mainLooper=0;
    int error;
    int index=0;
    int index2;

    while(1){
        while(mainLooper<=3){            
            printf("Enter your netural number: ");
            error=scanf("%d",&inputNumber);
            if(error!=1||inputNumber<0){
                printf("Please try agian. ");
                mainLooper++;
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
            else{
                break;
            }
        }
        if(mainLooper>3){
            printf("\nExperinced 3 errors. Shuting down.");
            return(0);
        }
        else if(inputNumber==2){
            printf("There is no prime numbers after the prime 2");
        }
        else if(inputNumber==1){
            printf("There are no primes after the number 1");
        }
        else{
            printf("Prime Numbers:");
            for (index=2;index<=inputNumber;index++){
                tempCounter=1;
                for(index2=2;index2<index;index2++){
                    if(fmod(index,index2)==0.0){
                        tempCounter=0;
                        break;
                    }                  
                }
                if(tempCounter==1){
                    printf(" %d",index);
                }                 
            }            
        }
        return(0);



    }

}