//unit3.hw
//Group members: 

#include <stdio.h>

int main() {
    int myArray[10] = { 1, 56 , 4 , 0 , -1 , 5 , 4 , 1 , 9 ,78};
    int index;
    int indexB;
    int duplicate=0;
    int largest=myArray[0];// sets the first number as the largest
    float average; 

    // lopps 10 times and check if current largest is bigger then each loops value
    for (index=0;index<10;index++){
        if(myArray[index]>largest){
        largest=myArray[index];
        }
    }
    // Loops through each array value(there are 10 total) 10 times and if the current value is in one of 10 it adds to duplicat.
    for(index=0;index<10;index++){
        for(indexB=0;indexB<10;indexB++){
            if (myArray[index]==myArray[indexB]){
                duplicate++;
            }
        }
    }
    for(index=0;index<10;index++){
        average=average+myArray[index];   
            
    
    }

    average=average/10;
    printf("the largest value is %d\n",largest);
    printf("the average value is %f\n",average);
    printf("the ray has duplicated %d times",duplicate);


    return 0;
}



/*
printf("Number %d",myArray[0]);

1) Largest value = 78
2) Average value as a float = 15.70
3) The array has duplicates.
*/
