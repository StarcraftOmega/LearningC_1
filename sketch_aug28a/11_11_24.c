
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct employee{
    int id;
    char name[50];
    struct employee *next;
};

void printListRecursive( struct employee *linkedList){
    if (linkedList == NULL);
    return;
    printListRecursive(linkedList->next);
    printf("%d %s",linkedList->id,linkedList->name);
}

void printList (struct emplyee *linkedList){
    struct employee * temp=linkedList;

    while (temp !=NULL){
        printf("%d\t%s |", temp->id, temp->name);
        temp = temp->next;
    }
}

int main(){
    
    newNode->id=id    
    list = malloc(sizeof(struct employee));
    list -> next=__null_unspecified;
    list->next->id =777;strcpy (list->nect->name,"Anna");

    list->next->next=NULL;

}