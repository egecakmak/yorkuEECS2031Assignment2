#include <stdio.h>
#include <ctype.h>

void clearBuffer() { // Clears std buffer to avoid unwanted characters.
    while ((getchar()) != '\n');
}

int main() {
    int numberOfRows;
    int i, j, k;
    int blankSpaceInTriangleCounter = 1; // A counter to keep count of spaces to put inside the triangle.
    printf("Enter the number of rows in the triangle: ");

    while (1) { // A loop that lets user try again until they input a number from range 1 - 20.
        if (scanf("%d", &numberOfRows) == 1 && numberOfRows >= 1 &&
            numberOfRows <= 20) { // If input is a number from range 1 - 20 then break.
            break;
        } else { // If input is not a number within range then try again.
            printf("You must input a number between 1 - 20. Please try again.\n");
            clearBuffer(); // Clears the std buffer.
        }
    }

    for (i = 1; i < numberOfRows; i++) {
        int numberOfSpacesBeforeInsertingStars = numberOfRows - i + 1;
        for (j = 1;
             j < numberOfSpacesBeforeInsertingStars; j++) { // Adds the needed number of spaces before inserting stars.
            printf(" ");
        }
        if (i == 1) { // Puts just a single star if creating the first row.
            printf("*\n");
        } else { // Adds two stars with adequate number of spaces in between.
            printf("*");
            for (k = 0; k < blankSpaceInTriangleCounter; k++) {
                printf(" ");
            }
            blankSpaceInTriangleCounter += 2;
            printf("*\n");
        }
    }
    // Prints the last row of the triangle.
    int numberOfStarsInLastRow = 2 * numberOfRows - 1;
    for (i = 0; i < numberOfStarsInLastRow; i++) {
        printf("*");
    }
    printf("\n");
}
