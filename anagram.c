#include <stdio.h>
#include <ctype.h>

typedef int bool;
#define true 1;
#define false 0;

void addChars(int wordChars[]) { // Adds inputted word's characters into the parameterized array.
    int ch;
    while ((ch = getchar()) != '\n') { // Gets characters from user's input and check if it is a letter in alphabet.
        if (isalpha(ch)) {
            ch = tolower(ch); // Turns the character to lowercase incase it is uppercase.
            ch = ch - 97; /* Subtracts 97 from the character to find the position to place in our array.
                      97 is where lowercase characters start in ASCII. In English, letter b is the second letter in the
                      alphabet and b is 98 in ASCII. 98-97 = 1 which is the second place in the array. */
            wordChars[ch]++; // Increments the element at ch.
        }
    }
}

bool checkWords(int firstWordChars[], int secondWordChars[]) { // Compares two given arrays.
    bool areAnagrams = true;
    int i;
    for (i = 0; i < 26 && areAnagrams; i++) {
        if (firstWordChars[i] != secondWordChars[i]) { // Loop breaks if both elements are not equal.
            areAnagrams = false;
        }
    }
    return areAnagrams; // Return result.
}

int main() {
    int firstWordChars[26] = {0}; // Defines array filled with 0s.
    int secondWordChars[26] = {0}; // Defines array filled with 0s.
    printf("Enter first word: ");
    addChars(firstWordChars);
    printf("Enter second word: ");
    addChars(secondWordChars);
    bool result = checkWords(firstWordChars, secondWordChars);
    if (result) {
        printf("The words are anagrams.\n");
    } else {
        printf("The words are not anagrams.\n");
    }
    return 0; // Return with no problems.
}