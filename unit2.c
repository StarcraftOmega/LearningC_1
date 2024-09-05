#include <stdio.h>
#include <stdlib.h>

int main(){
    float hw,projects,labs,midterm1,midterm2,final,overall;
    char overallLetter;
    int repeat =0;
    while (1){
        
        while(repeat==0){
            printf("Enter the hw average score(max of 100 for all): ");
            scanf("%f",&hw);
            if (hw>100||hw<0){
                printf("Invalide %.2f\n",hw);
                continue;
            }
            break;
        }
        while(repeat==0){
            printf("Enter the project average score: ");
            scanf("%f",&projects);
            if (projects>100||projects<0){
                printf("Invalide %.2f\n",projects);
                continue;
            }
            break;
        }
        while(repeat==0){
            printf("Enter lab average score: ");
            scanf("%f",&labs);
            if (labs>100||labs<0){
                printf("Invalide %.2f\n",labs);
                continue;
            }
            break;
        }
        while(repeat==0){
            printf("Enter midterm1, midterm2 and the final: ");
            scanf("%f %f %f",&midterm1,&midterm2,&final);
            if (midterm1>100||midterm1<0||midterm2>100||midterm2<0||final>100||final<0){
               printf("Invalide: %.2f,%.2f,%.2f\n",midterm1,midterm2,final);
                continue; 
            }
            break;
        }
        overall=(hw*.2)+(projects*.2)+(labs*.05)+(((midterm1+midterm2+final)/3)*.55);
        
        printf("\nHere are all your average scores: \n");
        printf("    HW :%.2f \n    PROJECTS:%.2f \n    LABS:%.2f \n    MIDTERM1:%.2f \n    MIDTERM2:%.2f \n    FINAL:%.2f\n",hw,projects,labs,midterm1,midterm2,final);
        printf("-----------------------\n");
        printf("Overall Grade: %.2f\n",overall);
        printf("-----------------------\n");
        printf("            Final Grade:%c",overallLetter);


        return 0;
    }

}