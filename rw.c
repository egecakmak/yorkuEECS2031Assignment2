#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int bool;
#define true 1;
#define false 0;

char walkArray[10][10];
char charToPlace = 'B';
int firstArrayIndex = 0;
int secondArrayIndex = 0;

bool isWithinRange(int direction) { // Checks if the index at a given direction is reachable.
    int firstArrayIndexTMP = firstArrayIndex;
    int secondArrayIndexTMP = secondArrayIndex;
    switch (direction) {
        case 0: // Going Up
            firstArrayIndexTMP -= 1;
            break;
        case 1: // Going Right
            secondArrayIndexTMP += 1;
            break;
        case 2: // Going Down
            firstArrayIndexTMP += 1;
            break;
        case 3: // Going Left
            secondArrayIndexTMP -= 1;
            break;
        default:
            break;
    }
    bool firstArrayStatus = false;
    bool secondArrayStatus = false;
    if (firstArrayIndexTMP >= 0 && firstArrayIndexTMP <= 9) { // Checks if first index is in range.
        firstArrayStatus = true;
    }
    if (secondArrayIndexTMP >= 0 && secondArrayIndexTMP <= 9) { // Checks if second index is in range.
        secondArrayStatus = true;
    }

    return firstArrayStatus && secondArrayStatus;
}

bool isFull(int direction) { // Checks if index at a given direction is full or empty.
    int firstArrayIndexTMP = firstArrayIndex;
    int secondArrayIndexTMP = secondArrayIndex;
    switch (direction) {
        case 0: // Going Up
            firstArrayIndexTMP -= 1;
            break;
        case 1: // Going Right
            secondArrayIndexTMP += 1;
            break;
        case 2: // Going Down
            firstArrayIndexTMP += 1;
            break;
        case 3: // Going Left
            secondArrayIndexTMP -= 1;
            break;
        default:
            break;
    }
    if (walkArray[firstArrayIndexTMP][secondArrayIndexTMP] == '.') {
        return false;
    } else {
        return true;
    }
}

bool canGoTowardsDirection(int direction){ // Checks if we can go towards direction.
    return isWithinRange(direction) && !isFull(direction);
}

bool isBlockedCompletely() { // Checks if there is anywhere available to go.
    return !(canGoTowardsDirection(0) || canGoTowardsDirection(1) || canGoTowardsDirection(2) || canGoTowardsDirection(3));
}

void changeIndex(int direction) { // Updatse the index accordingly for a given direction.
    switch (direction) {
        case 0: // Going Up
            firstArrayIndex -= 1;
            break;
        case 1: // Going Right
            secondArrayIndex += 1;
            break;
        case 2: // Going Down
            firstArrayIndex += 1;
            break;
        case 3: // Going Left
            secondArrayIndex -= 1;
            break;
        default:
            break;
    }
}

void printResult() { // Prints out the array in 10 lines.
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            char toPrint = walkArray[i][j];
            printf("%c ", toPrint);
        }
        printf("\n");
    }
}

void initializeArray() { // Initializes an array filled with ".". Also the first element is 'A'.
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            walkArray[i][j] = '.';
        }
    }
    walkArray[0][0] = 'A';
}

void move() { // Tries to move on the table.
    int direction = rand() % 4; // Get a random number.
    if (canGoTowardsDirection(direction)) { // Moves toward the direction if possible.
        changeIndex(direction);
        walkArray[firstArrayIndex][secondArrayIndex] = charToPlace; // Updates the char at the direction moving towards.
        charToPlace++; // Assigns the next char to charToPlace.
    }
    if (!isBlockedCompletely() && charToPlace <= 'Z') {
        move();
    }
}

int main() {
    srand(time(0)); // Sets the salt from rand().
    initializeArray();
    move();
    printResult();
    return 0; // Returns with no problems.
}


