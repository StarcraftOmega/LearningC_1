//unit4.hw
//Group members: Jonathon Faircloth, Samuel Yang, Chanakya Rajavarapu

# include <stdio.h>
# include <stdlib.h>

int main(){
    int *myArray;
    int *index;
    int *indexB;
    int *duplicate;
    int *largest;
    float *average;

    index=malloc(sizeof(int));
    indexB=malloc(sizeof(int));
    duplicate=malloc(sizeof(int));
    largest=malloc(sizeof(int));
    average=malloc(sizeof(float));
    myArray=malloc(10 * sizeof(int));

    *duplicate=0;
    *largest=0;

    
    for (*index=0;*index<10;(*index)++){ 
        myArray[*index]=(*index==0) ? 1:
            (*index==1) ? 56:
            (*index==2) ? 4:
            (*index==3) ? 0:
            (*index==4) ? (-1):
            (*index==5) ? 5:
            (*index==6) ? 4:
            (*index==7) ? 1:
            (*index==8) ? 9:
            (*index==9) ? 78: 0;
        //printf("%d\n",myArray[*index]);
    }  
    


    for (*index=0;*index<10;(*index)++){
        if(myArray[*index]>*largest){
        *largest=myArray[*index];
        }
        for(*indexB=0;*indexB<10;(*indexB)++){
            if (myArray[*index]==myArray[*indexB]){
                (*duplicate)++;
            }
        }
        *average=*average+myArray[*index];
    }

    *average=(*average)/10;
    *duplicate=((*duplicate)-10)/2;
    printf("the largest value is %d\n",*largest);
    printf("the average value is %.02f\n",*average);
    printf("the ray has duplicated %d times",*duplicate);

    return 0;
}
