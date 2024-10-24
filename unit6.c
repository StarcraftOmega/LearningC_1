#include <stdio.h>
#include <stdlib.h>


int main(){
    char *name = NULL;
    char ch;
    int space = 0;

    name = malloc(space * sizeof(char));

    printf("Please enter your sentence (press Enter to finish): ");

    while ((ch = getchar()) != '\n') {
        space++;
        
        name = realloc(name, (space + 1) * sizeof(char));
        name[space - 1] = ch;
        name[space] = '\0';
    }

    printf("Final string: %s\n", name);

    free(name);

    return 0;
}