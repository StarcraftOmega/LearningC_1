#include <stdio.h>
#include <stdlib.h>

/*
float average(int * array, int n){

    int i;
    float avg;

    for (i=0;i<n;i++){
        avg=avg+ *(array+i);
    
    }
    return avg/n;

}

int main(){
    int array[]={18,12,8};

    printf("The abverage is %.2f\n", average (array,3));
    
    
    return 0;
}
*/

void fun(int *n,int *p){

    (*n)++;
    --(*p);
    

}

int main(){
    int *x, *y;
    x = malloc(4);
    //*y = *x;
    printf("%d", &x);
    printf("\t%d", &y);
    *x=8;
    *y=7;

    fun(x,y);
    //printf("%d\t%d\n",*x,*y);


}

/*
int factorial(int n){

if (n==0) return 1;
return factorial(n-1)*n;

}


*/

/*
int main(){

int i;


for (i=0;i<1000;i++){
    printf("%c",i);
}



}
*/