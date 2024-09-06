/*unit2.hw 
Group members: Jonathon Faircloth, Samuel Yang, Chey Rajavarapu
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h> // For Sleep() on Windows
#else
#include <unistd.h> // For sleep() on Linux/macOS
#endif

void clear(int delay) // So that we can just call for clear(x) and not the whole thing, and it works cross-platform :)
{
#ifdef _WIN32          // Only works on Windows
  Sleep(delay * 1000); // Windows: Convert seconds to milliseconds
  system("cls");       // For Windows Clear
#else                  // Anything but Windows
  sleep(delay);    // Linux/macOS: Delay in seconds
  system("clear"); // For Linux/MacOS Clear
#endif
}

int main(){
    float hw,projects,labs,midterm1,midterm2,final,overall;
    char* overallLetter;
    char restart[10];
    int repeat =0;
    while (1){
        clear(1);
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
            printf("Enter midterm1, midterm2 and the final *note leave a space between each: ");
            scanf("%f %f %f",&midterm1,&midterm2,&final);
            if (midterm1>100||midterm1<0||midterm2>100||midterm2<0||final>100||final<0){
               printf("Invalide: %.2f,%.2f,%.2f\n",midterm1,midterm2,final);
                continue; 
            }
            break;
        }
        overall=(hw*.2)+(projects*.2)+(labs*.05)+(((midterm1+midterm2+final)/3)*.55);
        overallLetter = (overall >= 94) ? "A" :
                (overall >= 90) ? "A-" :
                (overall >= 87) ? "B+" :
                (overall >= 84) ? "B" :
                (overall >= 80) ? "B-" :
                (overall >= 77) ? "C+" :
                (overall >= 74) ? "C" :
                (overall >= 70) ? "C-" :
                (overall >= 67) ? "D+" :
                (overall >= 64) ? "D" :
                (overall >= 61) ? "D-" : "F";
        printf("\nHere are all your average scores: \n");
        printf("    HW :%.2f \n    PROJECTS:%.2f \n    LABS:%.2f \n    MIDTERM1:%.2f \n    MIDTERM2:%.2f \n    FINAL:%.2f\n",hw,projects,labs,midterm1,midterm2,final);
        printf("-----------------------\n");
        printf("Overall Grade: %.2f\n",overall);
        printf("-----------------------\n");
        printf("            Final Grade:%s\n\n",overallLetter);
        printf("Would you like to repeat? y/n: ");
        scanf("%s",restart);
        if (strcmp(restart, "Y") == 0 || strcmp(restart, "y")==0||strcmp(restart, "yes")==0||strcmp(restart, "Yes") == 0){
            continue;
        }


        return 0;
    }

}
