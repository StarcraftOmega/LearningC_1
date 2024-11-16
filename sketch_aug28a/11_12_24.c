#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


struct employee{ 
  int id;
  char name[50];
  struct employee *next;

};

void printList(struct employee *list){
  struct employee * temp=list;

   while (temp != NULL)
    {
        printf("%d\t%s |", temp->id, temp->name);
        temp = temp->next;

    }

}

struct employee * addNode(struct employee *list,int id, char *name){
  struct employee * newNode = malloc (sizeof(struct employee));
  newNode->id=id;

  strcpy(newNode->name,name);
  newNode->next=list;
  list=newNode;
  return list;
}

int main(){
  struct employee *list=NULL;

  list = addNode(list,2222,"James");
  list = addNode(list,6661,"UK");
  list = addNode(list,4123,"Madie");

  printList(list);
 
 return 0;
}