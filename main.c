/*unit1.hw 
Group members: Jonathon Faircloth, Samuel Yang, Chey Rajavarapu
Note - We were messing around and added some things we haven't learned yet like clear, so there are a lot of extra notes.
*/

#include <stdio.h>
#include <stdlib.h>

// The following are used for clear(I think) but idk if it is the best way to do it
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

int main() {
  int idOfUser; 
  int classId1, classId2; 
  float classHours1, classHours2;
  float gpa;
  float costClass1;
  float costClass2;
  float finalCost;
  int num = 0; // Support for loops. If not 0, no loops will start or they will end, so use break; to end a single loop
  clear(1); // Gets rid of starting gibberish 
  while (num == 0) // Looping in case ID is invalid. Will not start/restart if num is not = 0
  {
    printf("***********************\nHello, today we are going to generate a "
           "fee invoice\n!!!FOR YOU!!!\n");
    printf("Please Enter Your UCF ID\n(Note Your ID must be 4 digits): ");
    scanf("%d", &idOfUser);

    if (idOfUser < 1000 || idOfUser > 9999) // If the ID is not 4 digits, it will print this and restart the loop
    {
      printf("Invalid ID %d.\nPlease try again. (wait)\n", idOfUser);
      clear(3); // Clears the console after 3 seconds because it looks better.

    } else {
      printf("Enter CRN/credit hours for the first class: ");
      scanf("%d/%f", &classId1, &classHours1);

      printf("Enter CRN/credit hours for the second class: ");
      scanf("%d/%f", &classId2, &classHours2);

      printf("Finally, please enter GPA of student %d: ", idOfUser);
      scanf("%f", &gpa);
      
      costClass1 = 120.25 * classHours1;
      costClass2 = 120.25 * classHours2;
      finalCost = costClass1 + costClass2 + 35.00;
      if (gpa > 2.5) {
        printf("(25%% discount is applicable)");
        finalCost = finalCost * 0.75;
        clear(2);
      }
      else{
        printf("(25%% discount is NOT applicable)");
        clear(2);
      }
      
      break;
    }
  }

  printf("SIMPLE COLLEGE\nORLANDO FL 10101\n*************************\n\nFee Invoice Prepared for:\n[%d]\n\n", idOfUser);
  printf("1 Credit Hour = $120.25\nCRN     Hours\n");
  printf("%d      %.2f            $%.02f\n", classId1, classHours1, costClass1);
  printf("%d      %.2f            $%.02f\n\n", classId2, classHours2, costClass2);
  printf("Health & ID fees   $35.00\n\n----------------------------------\n\n");

  printf("Total cost              $%.02f\n", finalCost);
  if (gpa <= 2.5) {
    printf("Sorry, but user %d did not qualify for a discount.\n", idOfUser);
  }

  return 0;
}
