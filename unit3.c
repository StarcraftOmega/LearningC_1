//unit3.hw
//Group members: 

#include <stdio.h>

int main() {
    int myArray[10] = { 1, 56 , 4 , 0 , -1 , 5 , 4 , 1 , 9 ,78};
    int index;
    int indexB;
    int duplicate=1;
    int largest=myArray[0];

    for (index=0;index<10;index++){
        if(myArray[index]>largest){
            largest=myArray[index];
        }
    }
    for(index=0;index<10;index++){
        for(indexB=0;indexB<10;indexB++){
            if (myArray[index]==myArray[indexB])
            duplicate++;
        }
    }


    return 0;
}



/*
printf("Number %d",myArray[0]);

1) Largest value = 78
2) Average value as a float = 15.70
3) The array has duplicates.
*/
