#include <stdio.h>

int main() {

    int n, i, j = 0;
    float elements[3][4];
    float x, y, z;
    float xtemp=0, ytemp=0, ztemp=0;

    for (i = 0; i < 3; i++){

        printf("Enter the coefficients a, b, c and the constant d for Equation %d:\n", i+1);

        for (j=0;  j<4; j++){
            scanf("%f", &elements[i][j]);
        }
    }

    printf("\nEnter maximum number of Iterations: \n");
    scanf("%d", &n);

    printf("\nJacobi's Method: ");

    for (i = 0; i < n; i++) {

        for (j = 0; j < 3; ++j) {

            if (j == 0){
                x = (1 / elements[0][0]) * (elements[0][3] - (elements[0][1] * ytemp) - (elements[0][2] * ztemp));
            }
            if (j == 1) {
                y = (1 / elements[1][1]) * (elements[1][3] - (elements[1][0] * xtemp) - (elements[1][2] * ztemp));
            }
            if (j == 2) {
                z = (1 / elements[2][2]) * (elements[2][3] - (elements[2][0] * xtemp) - (elements[2][1] * ytemp));

                printf("\nx=%.3f\ty=%.3f\tz=%.3f\t", x, y, z);

                xtemp = x, ytemp = y; ztemp = z;
            }
        }
    }

}