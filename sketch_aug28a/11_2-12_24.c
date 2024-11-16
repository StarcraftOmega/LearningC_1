#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct employee {
    int id;
    char name [50];
    struct employee *next;
};
void printListRecursive (struct employee *linkedList) 
{
    if (linkedList == NULL) 
    {
        printf("666|NOBODY");
        return;
    }
    printf("%d|%s --> ", linkedList->id, linkedList->name);
    printListRecursive(linkedList->next);
}
void printList (struct employee *linkedList) 
{
    struct employee * temp = linkedList;

    while (temp != NULL)
    {
        printf("%d\t%s |", temp->id, temp->name);
        temp = temp->next;

    }
}
struct employee * addNode (struct employee * linkedList, int id, char * name) 
{
    struct employee * newNode = malloc (sizeof(struct employee));
    newNode -> id = id;
    
    strcpy (newNode->name, name);
    newNode->next = linkedList;
    linkedList = newNode;
    return linkedList;
}
struct employee * addNewNodeEnd(struct employee * list, int id, char * name) 
{
    struct employee * node = malloc (sizeof(struct employee));
    struct employee *temp=list;
    node->id = id;
    strcpy(node->name, name);
    node->next = NULL; 

    if (list == NULL) 
    {
        list = node; 
        return list;
    }
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=node;
    return list;
}
int main () 
{
    struct employee * list = NULL;

    list = addNode (list, 444, "Emma Jones");
    list = addNode(list, 6232, "Marie Curie");
    list = addNode (list, 321, "Parakeet Lady");

    printListRecursive(list);


   /* list = malloc (sizeof (struct employee));
    list->id = 111;
    /// or (*list).id = 111;

    strcpy (list->name,"James");

    list->next = NULL;

    list->next = malloc((sizeof (struct employee)));
    list->next->id = 777;
    strcpy(list->next->name, "Anna");

    list->next->next = NULL;
    list->next->next = malloc(sizeof(struct employee));
    list->next->next->id = 878;
    strcpy(list->next->next->name, "ANNIE");
    printListRecursive(list);

    newNode = malloc(sizeof(struct employee));
    newNode -> id = 333;
    strcpy(newNode->name, "Emma");
    newNode->next = list;
    list = newNode;
    printf("\n");
    printListRecursive(list);
    list = addNode(list, 213, "pickMe");
    printf("\n");
    printListRecursive(list); */
}