#include <stdio.h>
#include <stdbool.h>

void seidal(void);
void jacobi(void);
void elimination(void);
void choices(void);

int main() {

    _Bool exit = true;
    int choice;         // To control exiting of function

    do
    {
        choices();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                elimination();
                break;
            case 2:
                seidal();
                break;
            case 3:
                jacobi();
                break;
            case 4:
                exit = false;
                break;
            default:
                printf("Enter a Valid Choice!");
                break;
        }

    } while (exit);

    return 0;
}

void seidal(void)
{
    printf("\nGauss Seidal: \n");

    int n, i, j;
    float elements[3][4];   // 2D array to store all co-efficients and constants
    float x, y = 0, z = 0;  // Initial approximation of y and z

    // Inputting all the values
    for (i = 0; i < 3; i++){

        printf("\nEnter the coefficients a, b, c and the constant d for Equation %d:\n", i+1);

        for (j=0;  j<4; j++){
            scanf("%f", &elements[i][j]);
        }
    }

    // Asking user how many iterations to run through
    printf("\nEnter maximum number of Iterations: \n");
    scanf("%d", &n);

    // Outer loop for performing Iterations
    for (i = 0; i < n; i++) {

        // Inner loop to determines which value to calculate
        // 0, 1, 2 respectively for x, y, and z
        for (j = 0; j < 3; ++j) {

            if (j == 0)
            {
                x = (1 / elements[0][0]) * (elements[0][3] - (elements[0][1] * y) - (elements[0][2] * z));
            }
            if (j == 1)
            {
                y = (1 / elements[1][1]) * (elements[1][3] - (elements[1][0] * x) - (elements[1][2] * z));
            }
            if (j == 2)
            {
                z = (1 / elements[2][2]) * (elements[2][3] - (elements[2][0] * x) - (elements[2][1] * y));

                // Printing the Iterations
                printf("\nIteration %d: x = %.3f\ty = %.3f\tz = %.3f\t", i+1, x, y, z);
            }
        }
    }
}

void jacobi(void)
{
    printf("\nJacobi's Method: \n");

    int n, i, j = 0;
    float elements[3][4];
    float x, y, z;
    float xtemp=0, ytemp=0, ztemp=0;

    for (i = 0; i < 3; i++){

        printf("\nEnter the coefficients a, b, c and the constant d for Equation %d:\n", i+1);

        for (j=0;  j<4; j++){
            scanf("%f", &elements[i][j]);
        }
    }

    printf("\nEnter maximum number of Iterations: \n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {

        for (j = 0; j < 3; ++j) {

            if (j == 0)
            {
                x = (1 / elements[0][0]) * (elements[0][3] - (elements[0][1] * ytemp) - (elements[0][2] * ztemp));
            }
            if (j == 1)
            {
                y = (1 / elements[1][1]) * (elements[1][3] - (elements[1][0] * xtemp) - (elements[1][2] * ztemp));
            }
            if (j == 2)
            {
                z = (1 / elements[2][2]) * (elements[2][3] - (elements[2][0] * xtemp) - (elements[2][1] * ytemp));

                printf("\nx = %.3f\ty = %.3f\tz = %.3f\t", x, y, z);

                xtemp = x, ytemp = y; ztemp = z;
            }
        }
    }
}


void elimination(void)
{
    printf("\nGauss Elimination: \n");

    int i, j;
    float x, y, z;      // Values to find

    // 2D Array to store all the co-efficients and constants of all the 6 equations
    // First 3 equations will be accepted
    // rest 3 will be calculated subsequently
    float elements[6][4];

    for (i = 0; i < 3; i++)
    {
        printf("\nEnter the coefficients a, b, c and the constant d for Equation %d:\n", i+1);

        for (j=0;  j<4; j++)
        {
            scanf("%f", &elements[i][j]);
        }
    }

    // Eliminating x
    // And getting equations number 4 and 5 without x
    // Which will be in the form of y and z
    for (i=0; i<2; i++)
    {
        for (j = 0; j < 4; ++j)
        {
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
    printf("\nx = %.3f\ty = %.3f\tz = %.3f", x, y, z);
}

void choices(void)
{
    printf("\n\nEnter your Choice: ");
    printf("\n1. Gauss Elimination Method");
    printf("\n2. Gauss Seidal Method");
    printf("\n3. Jacobi's Method");
    printf("\n4. Exit\n\n");
}