#include <stdio.h>
#include <stdlib.h>

int main() 
{
    long l = 222377;

    // Store each value and the number of times it was encoutered which translates to its power
    int digits[10] = {0,0,0,0,0,0,0,0,0,0};
    int powers[10] = {0,0,0,0,0,0,0,0,0,0};

    // We copy the first digit at the end of the array so it will be outputed first when printing to stdout
    int x = 9;

    // Compute l mod 10 and store its value in i
    int i = l % 10;
    digits[x] = i;
    powers[x] = 1;
    l /= 10;

    while (l > 0) {
        i = l % 10;
        // If the digit was already encountered we simply increase its power 
        if ((digits[x] == i) && (digits[x] != 0)) {
            powers[x]++;
        } 
        // If a new digit is found copy it at the previous index and save its power 
        else {
            x--;
            digits[x] = i;
            powers[x] = 1;
        }

        l /= 10;
    }

    // Output the result
    for (int j = 0; j < 10; j++) {
        if ((digits[j] > 0) && (powers[j] > 0)) {
            printf("%d^%d", digits[j], powers[j]);
            if (j != 9) {
                printf("*");
            }
        }
    }
    printf("\n");

    return 0;
}
