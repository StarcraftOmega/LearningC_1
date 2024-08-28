/*unit1.hw 
Group members: Jonathon Faircloth, Samuel Yang, Chey Rajavarapu
Note-We where missing around and madded some things we havent learned yet
*/

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h> // For Sleep() on Windows
#else
#include <unistd.h> // For sleep() on Linux/macOS
#endif

void clear(int delay) // So that we can just call for Clear(x) and not the whole thing and it works crossplatform :)
{
#ifdef _WIN32          // Only works on windows
  Sleep(delay * 1000); // Windows: Convert seconds to milliseconds
  system("cls");       // For Windows Clear
#else                  // Anything but windows
  sleep(delay);    // Linux/macOS: Delay in seconds
  system("clear"); // For Linux/MacOS Clear
#endif
}

int main() {
  int idOfUser;
  int classId1, classId2; 
  int classHours1, classHours2;
  int num = 0; // Suppot for loops. If not 0, no loops will start or they will end so use break; to end a single loop

  while (num == 0) // Looping Incase ID is invalid. Will not start / restart if
                   // num is not = 0
  {
    printf("***********************\nHello, today we are going to generate a "
           "fee invoice\n!!!FOR YOU!!!\n");
    printf("Please Enter Your UCF ID\n(Note Your ID must be 4 numbers): ");
    scanf("%d", &idOfUser);

    if (idOfUser < 1000 ||
        idOfUser > 9999) // If the ID is not 4 digits, it will print this and
                         // restart the loop
    {
      printf("Invalid ID %d.\nPlease try again.(wait)\n", idOfUser);
      clear(3); // clears the console after 3 seconds because it looks better.

    } else {
      printf("Please enter your class number. \nClass 1: ");
      scanf("%d",&classId1); 
      printf("Class 2: ");
      scanf("%d",&classId2);

      printf("Now, please enter your Credit hours for each class.\nClass 1: ");
      scanf("%d",&classHours1);
      printf("Class 2;");
      scanf("%d",&classHours2);
      
      clear(0);
      break;
    }
  }

  printf("SIMPLE COLLEGE\nORLANDO FL 10101\n*************************\n");
  printf("");
  printf("1 Credit Hour = $120.25");

  return 0;
}
