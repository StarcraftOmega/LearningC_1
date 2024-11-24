//unit8.hw
//Group members: Jonathan Faircloth, Samuel Yang

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct employee {
    int id;
    char name[50];
    float salary;
    int numberOfDependents;
    //----------------------
    struct employee * next;
    struct employee * below;
};


//0.
int getId(char *name) {
    int sum = 0;

    name[strcspn(name, "\n")] = '\0';
    for (int i = 0; name[i] != '\0'; i++) {
        sum += (int)name[i];
    }
    return sum;
}

//1.
void printEmployee ( struct employee e){
    float netSalary=e.salary * 0.91+(e.numberOfDependents * 0.01 * e.salary);
    printf("[%d, %s, %.2f]\n", e.id, e.name, netSalary);
}

//2.
void printAllEmployees ( struct employee * list){
    struct employee *temp=list;
    while (temp!=NULL){
        struct employee *temp2=temp->below;
        printEmployee(*temp);
        while(temp2!=NULL){
            printEmployee(*temp2);
            temp2=temp2->below;
        }
        temp=temp->next;
    }
}
//3.
struct employee *addEmployee(struct employee *list, struct employee e) {
    struct employee *addNew = malloc(sizeof(struct employee));
    struct employee *temp = list;

    addNew->below = NULL;

    while (temp != NULL) {
        if (strcmp(temp->name, e.name) == 0) {
            printf("Same name already in use\n");
            free(addNew);
            return list;
        }
        if (getId(temp->name) == e.id) {
            addNew->below = temp->below;
            temp->below = addNew;
            addNew->id = e.id;
            addNew->salary = e.salary;
            strcpy(addNew->name, e.name);
            return list;  
        }
        temp = temp->next; 
    }

    addNew->id = e.id;
    addNew->salary = e.salary;
    addNew->numberOfDependents = e.numberOfDependents;
    strcpy(addNew->name, e.name);
    addNew->next = list;
    return addNew;
}

//4.
int searchEmployee(struct employee *list, char *name) {
    struct employee *tempList = list;
    while (tempList != NULL) {
        struct employee *tempBelow = tempList;
        while (tempBelow != NULL) {
            if (strcmp(tempBelow->name, name) == 0) { 
                return 1; 
            }
            tempBelow = tempBelow->below; 
        }
        tempList = tempList->next;
    } 
    return 0; 
}
//5.
float highestNetSalary(struct employee *list) {
    struct employee *temp = list;
    float highest = 0.0;
    while (temp != NULL) {
        struct employee *temp2 = temp;
        while (temp2 != NULL) {
            float netSalary = temp2->salary * 0.91 + (temp2->numberOfDependents * 0.01 * temp2->salary);
            if (highest < netSalary) {
                highest = netSalary;
            }
            temp2 = temp2->below;
        }
        temp = temp->next;
    }
    return highest;
}


int main() {
    struct employee * company = NULL , tempEmployee;
    int tempInt = 0;
    char tempName [50] = "Allal Kamch" ;
    char dummy;

    printf ("Enter 1 to add a new employee, 0 to stop: ");
    scanf ("%d", &tempInt);

    while ( tempInt == 1 ){
        printf("Enter Full Name: ");
        scanf("%c",&dummy);
        fgets(tempEmployee.name, 50, stdin);

        tempEmployee.id = getId ( tempEmployee.name );

        printf ("Enter salary-numberOfDependents: ");
        scanf ("%f-%d", &tempEmployee.salary,&tempEmployee.numberOfDependents);

        company = addEmployee ( company , tempEmployee );

        printf ("Enter 1 to add a new employee, 0 to stop: ");
        scanf ("%d", &tempInt);
    }
    printAllEmployees ( company ) ;
    printf ("Highest Net Salary = %.2f\n", highestNetSalary(company) );

    tempInt = searchEmployee ( company , tempName) ;

    if ( tempInt == 1 ) printf ("%s is found!\n", tempName);

    else printf ("%s is NOT found!\n", tempName);

    return 0;
}