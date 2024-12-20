//unit8.hw
//Group members: Jonathan Faircloth, Samuel Yang, Chanakya Rajavarapu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Employee structure
struct employee {
    int id;
    char name[50];
    float salary;
    int numberOfDependents;
    struct employee *next;
    struct employee *below;
};


//0. Compute employee ID based on the ASCII values of uppercase letters
int getId ( char * name ){
    int sum=0;
    for(int i=0;name[i]!='\0';i++){
        sum += (int)name[i];
    }
    return sum;
}

//1. Print an individual employee's details
void printEmployee(struct employee e) {
    float netSalary = e.salary * 0.91 + (e.numberOfDependents * 0.01 * e.salary);
    printf("[%d, %s, %.2f]\n", e.id, e.name, netSalary);
}

//2. Print all employees in the linked list
void printAllEmployees(struct employee *list) {
    struct employee *current = list;
    while (current) {
        struct employee *subList = current;
        while (subList) {
            printEmployee(*subList);
            subList = subList->below;
        }
        current = current->next;
    }
}

//3. Add a new employee to the list
struct employee *addEmployee(struct employee *list, struct employee e) {
    struct employee *newEmployee = (struct employee *)malloc(sizeof(struct employee));
    *newEmployee = e;
    newEmployee->next = NULL;
    newEmployee->below = NULL;

    if (!list) {
        return newEmployee;
    }

    struct employee *current = list, *previous = NULL;
    while (current && current->id != e.id) {
        previous = current;
        current = current->next;
    }

    if (current && current->id == e.id) {
        struct employee *collisionList = current;
        while (collisionList->below) {
            collisionList = collisionList->below;
        }
        collisionList->below = newEmployee;
    } else {
        if (previous) {
            newEmployee->next = previous->next;
            previous->next = newEmployee;
        } else {
            newEmployee->next = list;
            list = newEmployee;
        }
    }

    return list;
}

//4. Search for an employee by name
int searchEmployee(struct employee *list, char *name) {
    struct employee *current = list;
    while (current) {
        struct employee *subList = current;
        while (subList) {
            if (strcmp(subList->name, name) == 0) {
                return 1;
            }
            subList = subList->below;
        }
        current = current->next;
    }
    return 0;
}

//5. Find the highest net salary in the list
float highestNetSalary(struct employee *list) {
    float maxNetSalary = 0;
    struct employee *current = list;

    while (current) {
        struct employee *subList = current;
        while (subList) {
            float netSalary = subList->salary * 0.91 + (subList->numberOfDependents * 0.01 * subList->salary);
            if (netSalary > maxNetSalary) {
                maxNetSalary = netSalary;
            }
            subList = subList->below;
        }
        current = current->next;
    }

    return maxNetSalary;
}


int main() {
    struct employee *company = NULL, tempEmployee;
    int tempInt = 0;
    char tempName[50] = "Allal Kamch";
    char dummy;
    printf("Enter 1 to add a new employee, 0 to stop: ");
    scanf("%d", &tempInt);
    while (tempInt == 1) {
        printf("Enter Full Name: ");
        scanf("%c", &dummy);
        fgets(tempEmployee.name, 50, stdin);
        tempEmployee.name[strcspn(tempEmployee.name, "\n")] = 0; 
        tempEmployee.id = getId(tempEmployee.name);
        printf("Enter salary-numberOfDependents: ");
        scanf("%f-%d", &tempEmployee.salary, &tempEmployee.numberOfDependents);
        company = addEmployee(company, tempEmployee);
        printf("Enter 1 to add a new employee, 0 to stop: ");
        scanf("%d", &tempInt);
    }
    printAllEmployees(company);
    printf("Highest Net Salary = %.2f\n", highestNetSalary(company));
    tempInt = searchEmployee(company, tempName);
    if (tempInt == 1)
        printf("%s is found!\n", tempName);
    else
        printf("%s is NOT found!\n", tempName);
    return 0;
}

