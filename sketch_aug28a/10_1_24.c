#include <stdio.h>



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