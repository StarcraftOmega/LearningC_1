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

// added this and valid to fix if a letter was added instead of a number
void clearBuffer() { //clears the infomation soterd for input to stop loop bug
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Discard all characters?
}

int main(){
    float hw,projects,labs,midterm1,midterm2,final,overall;
    char* overallLetter;
    char restart[10];
    int repeat =0;
    int valid;// to check if a input is a number. Usealy 1 but for loop 4 it need 3 because of 3 inputs

    while (1){
        clear(1);
        while(repeat==0){
            printf("Enter the hw average score(max of 100 for all): ");
            valid=scanf("%f",&hw);
            if (valid != 1 ||hw>100||hw<0){
                printf("Invalide %.2f\n",hw);
                clearBuffer();                
                continue;
            }
            break;
        }
        while(repeat==0){
            printf("Enter the project average score: ");
            valid=scanf("%f",&projects);
            if (valid != 1 ||projects>100||projects<0){
                printf("Invalide %.2f\n",projects);
                clearBuffer();
                continue;
            }
            break;
        }
        while(repeat==0){
            printf("Enter lab average score: ");
            valid=scanf("%f",&labs);
            if (valid != 1 ||labs>100||labs<0){
                printf("Invalide %.2f\n",labs);
                clearBuffer();
                continue;
            }
            break;
        }
        while(repeat==0){
            printf("Enter midterm1, midterm2 and the final *note leave a space between each: ");
            valid=scanf("%f %f %f",&midterm1,&midterm2,&final);
            if (valid != 3 ||midterm1>100||midterm1<0||midterm2>100||midterm2<0||final>100||final<0){
               printf("Invalide: %.2f,%.2f,%.2f\n",midterm1,midterm2,final);
                clearBuffer();
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
        valid=scanf("%s",restart);
        if (strcmp(restart, "Y") == 0 || strcmp(restart, "y")==0||strcmp(restart, "yes")==0||strcmp(restart, "Yes") == 0){            
            continue;
        }


        return 0;
    }

}
