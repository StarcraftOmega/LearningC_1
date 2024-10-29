#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


void enterString(char *ch,int *space,char **name){
    //getchar() is like scanf but it reads onley single inputs --
    // -- including spaces and when enter/retun is pressed it returns \n so that stops the loop
    
    while ((*ch = getchar()) != '\n') {
        (*space)++;
        (*name) = realloc(*name, (*space + 1) * sizeof(char));
        (*name)[*space - 1] = *ch;
        (*name)[*space] = '\0';
    }

}

void UpperReorder(int space, char *name,int upper){
    char *letterTemp;
    int i,i2;
    letterTemp=malloc(upper * sizeof(char));
    
    for (i=0,i2=0;i<space;i++){
            if(isupper(name[i])){
                letterTemp[i2++]=name[i];
            }
    }
    for (i = 0; i < upper - 1; i++) {
        for (i2 = 0; i2 < upper - i - 1; i2++) {
            if (letterTemp[i2] > letterTemp[i2 + 1]) {
                char temp = letterTemp[i2];
                letterTemp[i2] = letterTemp[i2 + 1];
                letterTemp[i2 + 1] = temp;
            }
        }
    }
    for(i=0;i<upper;i++){
        printf("%c",letterTemp[i]);
    }
    free (letterTemp);

}


int main(){
    char *name;
    char ch;
    int space=0;

    int i;
    int i2;

    char mostUsed;
    int mostUsedB=0;
    int upper=0;
    int lower=0;
    int digit=0;
    int tempA=0;
    int tempB=0;

    name = malloc(space * sizeof(char));

    printf("Sup--\nPlease enter your string (press Enter to finish): ");

    enterString(&ch,&space,&name);    

    for (i=0;i<space;i++){
        for (i2=0;i2<space;i2++){
            if (i!=i2&&mostUsed!=tolower(name[i])&&tolower(name[i2]) == tolower(name[i])){
                tempB++;
            }
        }
        if (isupper(name[i])){
            upper++;

        }
        else if(islower(name[i])){
            lower++;
        }
        else if(isdigit(name[i])){
            digit++;
        }
        if(tempB>tempA){
            tempA=tempB;
            mostUsed=tolower(name[i]);
            mostUsedB=0;
        }
        else if (tempB==tempA){
            mostUsedB=1;
        }
        tempB=0;
    }

    if (space>0){

        if(tempA==0){
            printf("All characters appears once.\n");
        }
        else if(mostUsedB==1){
            printf("There are mutiple reacuring characters with the same amount of reacurinces.\n");
        }
        else{
            printf("The most occuring character is: %c\n",mostUsed);
        }
        printf("There is/are %d lower case letter(s)\nThere is/are %d upper case letter(s)\n",lower,upper);
        printf("There is/are %d digit(s)\n-----------------\n",digit);
        UpperReorder(space,name,upper);
        printf("\n%s\n",name);
    }
    else{
        printf("Somthing went wrong. \nPleas try again later");
    }
    free(name);

    return 0;
}