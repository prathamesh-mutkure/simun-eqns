#include <stdio.h>

int main() {

    int i, j;
    float x, y, z;      // Values to find

    // 2D Array to store all the co-efficients and constants of all the 6 equations
    // First 3 equations will be accepted
    // rest 3 will be calculated subsequently
    float elements[6][4];

    for (i = 0; i < 3; i++)
    {
        printf("Enter the coefficients a, b, c and the constant d for Equation %d:\n", i+1);

        for (j=0;  j<4; j++){
            scanf("%f", &elements[i][j]);
        }
    }

    printf("\nGauss Elimination: \n");

    // Eliminating x
    // And getting equations number 4 and 5 without x
    // Which will be in the form of y and z
    for (i=0; i<2; i++)
    {
        for (j = 0; j < 4; ++j) {

            elements[i+3][j] = (elements[0][j]*elements[i+1][0]) - (elements[i+1][j]*elements[0][0]);

        }
    }

    // Eliminating y
    // And getting equation number 6 without y
    // which will be directly in the form of z
    for (i = 0; i < 4; ++i)
    {
        elements[5][i] = (elements[3][i]*elements[4][1]) - (elements[4][i]*elements[3][1]);
    }

    // Calculating final values:

    z = (elements[5][3])/(elements[5][2]);

    y = (1/elements[4][1])*(elements[4][3] - elements[4][2]*z);

    x = (1/elements[0][0])*(elements[0][3] - elements[0][2]*z - elements[0][1]*y);

    // Printing final answer:

    printf("x = %f\ty = %f\tz = %f", x, y, z);

}