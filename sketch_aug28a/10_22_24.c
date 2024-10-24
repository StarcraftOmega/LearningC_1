#include <stdio.h>
#include <stdlib.h>

// all strings end with \0

// I thoght that anfter each time space was hit for a new 
// word in scanf would run but it does not until enter is pressed 
/*
int main(){
    char *name;
    char ext[10]={0};
    int space=0;
    int oldSpace=0;
    int temp;
    int i;
    int i2;

    name= malloc(space * sizeof(char));

    printf("Pleas enter your sentence: ");
    for (i = 0; ext[i] != '\0'; i++) {
        for (temp=0,i2=0;i2<space;i2++){
            if(ext[i2]!="0")temp++;
        } 
        oldSpace=space;
        space = space + temp;
        name= realloc(name, space * sizeof(char));
        for (i2=0;i2<temp;i2++){
            name[oldSpace+i2]=ext[i2];
        }
        ext[10]="0";
        scanf("%c",&ext);
        
    }

   printf("%s",name);

free(name);


    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *name = NULL;
    char ch;
    int space = 0;

    // Initial memory allocation (optional, can start with NULL)
    name = malloc(space * sizeof(char));

    printf("Please enter your sentence (press Enter to finish): ");

    // Read input character by character, including spaces
    while ((ch = getchar()) != '\n') {
        // Increase the space counter
        space++;

        // Reallocate space for name to accommodate the new character
        name = realloc(name, (space + 1) * sizeof(char)); // +1 for the null terminator

        // Store the character
        name[space - 1] = ch;
        
        // Add null terminator to `name`
        name[space] = '\0';
    }

    printf("Final string: %s\n", name);

    // Free allocated memory
    free(name);

    return 0;
}
