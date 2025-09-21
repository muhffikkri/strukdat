/* Simple arithmetic test */
#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "boolean.h"

int main()
{
    printf("=== ARITHMETIC TEST ===\n");

    Matriks M1, M2, M3;
    initMatriks(&M1);
    initMatriks(&M2);

    // Simple 2x2 matrices
    M1.cell[1][1] = 1;
    M1.cell[1][2] = 2;
    M1.cell[2][1] = 3;
    M1.cell[2][2] = 4;
    M1.nbaris = 2;
    M1.nkolom = 2;

    M2.cell[1][1] = 5;
    M2.cell[1][2] = 6;
    M2.cell[2][1] = 7;
    M2.cell[2][2] = 8;
    M2.nbaris = 2;
    M2.nkolom = 2;

    printf("Matrix M1:\n");
    viewMatriks(M1);
    printf("\nMatrix M2:\n");
    viewMatriks(M2);

    printf("\nTesting addMatriks...\n");
    M3 = addMatriks(M1, M2);
    printf("Result M3[1][1] = %d (expected 6)\n", M3.cell[1][1]);
    printf("Result M3[2][2] = %d (expected 12)\n", M3.cell[2][2]);

    return 0;
}