#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    float gpa;
    char *name;
} student;


int main(){

    student s1,s2, array[10],*p;
    s2.id =111;
    s2.gpa=5;
    s1.gpa = 4;
    s1.id=125;

    s1.name = malloc(sizeof(100));
    //s2.name = malloc(sizeof(100));

    strcpy (s1.name, "jimmy");
    //strcpy (s2.name, "Amiy");

    printf("%d\n%.2f\n%s\n",s1.id,s1.gpa,s1.name);
    
    s2=s1;
    p=&s1;
   

    //printf("%d\n%.2f\n%s\n",(*p).id,(*p).gpa,(*p).name);
    printf("%d\n%.2f\n%s\n",s2.id,s2.gpa,s2.name);


}