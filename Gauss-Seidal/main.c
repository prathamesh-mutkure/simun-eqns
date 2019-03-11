#include <stdio.h>

int main() {

    int n, i, j;
    float elements[3][4];   // 2D array to store all co-efficients and constants
    float x, y = 0, z = 0;  // Initial approximation of y and z

    // Inputting all the values
    for (i = 0; i < 3; i++){

        printf("Enter the coefficients a, b, c and the constant d for Equation %d:\n", i+1);

        for (j=0;  j<4; j++){
            scanf("%f", &elements[i][j]);
        }
    }

    // Asking user how many iterations to run through
    printf("\nEnter maximum number of Iterations: \n");
    scanf("%d", &n);

    printf("\nGauss Seidal: ");

    // Outer loop for performing Iterations
    for (i = 0; i < n; i++) {

        // Inner loop to determines which value to calculate
        // 0, 1, 2 respectively for x, y, and z
        for (j = 0; j < 3; ++j) {

            if (j == 0){
                x = (1 / elements[0][0]) * (elements[0][3] - (elements[0][1] * y) - (elements[0][2] * z));
            }
            if (j == 1) {
                y = (1 / elements[1][1]) * (elements[1][3] - (elements[1][0] * x) - (elements[1][2] * z));
            }
            if (j == 2) {
                z = (1 / elements[2][2]) * (elements[2][3] - (elements[2][0] * x) - (elements[2][1] * y));

                // Printing the Iterations
                printf("\nIteration %d: x=%.2f\ty=%.2f\tz=%.2f\t", i+1, x, y, z);
            }
        }
    }

}