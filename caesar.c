#include <stdio.h>

void clearBuffer(){ // Clears std buffer to avoid unwanted characters.
    while ((getchar()) != '\n');
}

int main() {
    char message[80] = {0}; // Defines an array of characters to store the message.
    int shiftAmount = 0; // Stores the shift amount given by the user.
    int i;
    int j = 0;
    int ch;

    printf("Enter message to be encrypted : ");
    while ((ch = getchar()) != '\n'){ // Takes message as input.
        if(j<=79){
            message[j] = (char) ch;
            j++;
        }
    }
    printf("Enter shift amount (1-25) : ");
    while (1) { // Lets user try infinitely many times until they input a shift amount that is in range.
        if (scanf("%d", &shiftAmount) && shiftAmount >= 1 && shiftAmount <= 25) {
            break;
        } else {
            printf("Shift amount is not a number within range 1 - 25. Please try again.\n");
            clearBuffer(); // Clears the stdin buffer.
        }
    }
    int sizeOfMessage =
            sizeof(message) / sizeof(message[0]); // Number of characters in the array. We could hard code 80 instead.
    for (i = 0; i < sizeOfMessage; i++) {
        unsigned char newLetter = (message[i] + shiftAmount); // An unsigned char to store the new letter.
        if (message[i] >= 65 && message[i] <= 90) { // Checks if the character is a lowercase letter.
            if (newLetter > 90) { // Makes sure new letter is within the lowercase character range.
                newLetter = (newLetter % 90) + 64; // (Wrap - around)
            }
            message[i] = newLetter; // Replaces the encrypted letter with the old one.
        } else if (message[i] >= 97 && message[i] <= 122) { // Checks if the character is an uppercase letter.
            if (newLetter > 122) { // Makes sure new letter is within the uppercase character range.
                newLetter = (newLetter % 122) + 96; // (Wrap - around)
            }
            message[i] = newLetter; // Replaces the encrypted letter with the old one.
        }
    }
    printf("Encrypted message : %s\n", message);
    return 0; // Return with no problems.
}