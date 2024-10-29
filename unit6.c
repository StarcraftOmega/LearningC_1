//unit6.hw
//Group members: Jonathan Faircloth, Samuel Yang

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char most_occuring_character ( char *str);
void count_low_up_digit ( char *str, int *lower, int *upper , int *digit);
char * Up_letters ( char *str);

char most_occuring_character(char *str) {
    int freq[256] = {0};
    int max_count = 0;
    char most_occurring = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
        if (freq[(unsigned char)str[i]] > max_count) {
            max_count = freq[(unsigned char)str[i]];
            most_occurring = str[i];
        }
    }

    // If no character appears more than once
    if (max_count == 1) return -1;
    return most_occurring;
}

void count_low_up_digit(char *str, int *lower, int *upper, int *digit) {
    *lower = *upper = *digit = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) (*lower)++;
        else if (isupper(str[i])) (*upper)++;
        else if (isdigit(str[i])) (*digit)++;
    }
}

char *Up_letters(char *str) {
    static char upper_sorted[50];
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            upper_sorted[count++] = str[i];
        }
    }

    upper_sorted[count] = '\0';


    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (upper_sorted[i] > upper_sorted[j]) {
                char temp = upper_sorted[i];
                upper_sorted[i] = upper_sorted[j];
                upper_sorted[j] = temp;
            }
        }
    }

    return upper_sorted;
}


int main() {
    char str[50] = "";
    char *upper_sorted;
    char most_occur = -1;
    int lower_case = 0, upper_case = 0, digits = 0;

    printf("Enter your string: ");
    gets(str);

    most_occur = most_occuring_character(str);
    if (most_occur == -1) 
        printf("All characters appear once\n");
    else 
        printf("The most occurring character is: %c \n", most_occur);

    count_low_up_digit(str, &lower_case, &upper_case, &digits);
    printf("There is/are %d lower case letter(s)\n", lower_case);
    printf("There is/are %d upper case letter(s)\n", upper_case);
    printf("There is/are %d digit(s)\n", digits);

    upper_sorted = Up_letters(str);
    printf("%s\n", upper_sorted);
    printf("%s\n", str);

    return 0;
}
