#include <stdio.h>

// Function to calculate and print Pascal's Triangle
void printPascalTriangle(int numRows) {
    int coef = 1;

    for (int i = 0; i < numRows; i++) {
        for (int space = 1; space <= numRows - i; space++)
            printf("  ");

        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == 0)
                coef = 1;
            else
                coef = coef * (i - j + 1) / j;

            printf("%4d", coef);
        }
        printf("\n");
    }
}

int main() {
    int numRows;
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &numRows);

    printPascalTriangle(numRows);

    return 0;
}
