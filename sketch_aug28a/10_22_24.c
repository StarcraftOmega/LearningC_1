#include <stdio.h>
#include <stdlib.h>

// all strings end with \0



int main(){
    char *name;
    char ext[10]="0000000000";
    int space=10;
    int temp;
    int i;
    int i2;

    name= malloc(space * sizeof(char));

    printf("Pleas enter your sentence: ");
    for (i = 0; ext[i] != '\0'; i++) {
        for (temp=0,i2=0;i2<space;i2++){
            if(ext[i2]!=0)temp++;
        } 
        space = space + temp;
        name= realloc(name, space * sizeof(char));
        for (i2=0;i2<temp;i2++){
            name[temp+i2]=ext[i2];
        }

        scanf("%c",&ext);
        
    }

   for (i = 0; i < 10 && ext[i] != '\0'; i++) {
        printf("%c", ext[i]); // Use %c to print each character
    }
    



    return 0;
}