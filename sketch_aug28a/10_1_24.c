#include <stdio.h>
#include <stdlib.h>

/*
int main(){
    int var=15;
    int *pvar;
    int **ppvar;
    int ***pppvar;

    pvar=&var,*pvar=20,var=*pvar;
    printf("var=%d,pvar=%d",var,*pvar);
    ppvar=&pvar,**ppvar=25,var=**ppvar;
    printf("var=%d,ppvar=%d",var,**ppvar);
    pppvar=&ppvar,***pppvar=30,var=***pppvar;
    printf("var=%d,pppvar=%d\n\n",var,***pppvar);

    printf("Enter a new value for var: ");
    scanf("%d", pvar);
    printf("Updated var = %d\n", var);
    printf("Enter another new value for var: ");
    scanf("%d", *ppvar);
    printf("Updated var = %d\n", var);



    return(0);
}
*/
/*
int main(){
    int var=10;
    int *pvar;
    int **ppvar;

    pvar=&var;
    ppvar=&pvar;
    *pvar=4;


    printf("\n------------\n%d,%d,%d\n-----------\n",*pvar,**ppvar,var);


    return(0);
}
*/
/*
int main(){
    int * pointer;
    int counter;
    int *temp;
    int data=3;
    pointer = malloc(10 * sizeof(int));
    
    pointer[0]=7;//or
    *pointer=7;
    
    pointer[2]=4;//or
    *(pointer+2)=4;
    for(counter=0;counter<10;counter++)
        pointer[counter]=8;

    
    pointer = realloc(pointer, 20 * sizeof(int));
    free(pointer);
    //pointer= &data;

    for (counter=10;counter<20;counter++)
        pointer[counter]=4;
    
    for(temp = pointer;temp<pointer+20;temp++)
        printf ("%d\n",*temp);
    
    
    return(0);
}
*/

int main(){
    float *px,*py;
    float *psum;
    float *pmult;
    float *pdiv;

    px=malloc(sizeof(int));
    py=malloc(sizeof(int));
    psum=malloc(sizeof(int));
    pmult=malloc(sizeof(int));
    pdiv=malloc(sizeof(int));


    printf("Enter the first number: ");
    scanf("%f",px);

    printf("Enter the secound number: ");
    scanf("%f",py);

    *psum= *px + *py;
    *pmult= *px * *py;

    if (*py !=0){
        *pdiv=*px / *py;
        printf("%.2f / %.2f= %.2f\n", *px, *py, *pdiv);
    }

    printf("%.2f + %.2f= %.2f\n", *px, *py, *psum);
    printf("%.2f * %.2f=%.2f\n",*px,*py,*pmult);


    return(0);
}