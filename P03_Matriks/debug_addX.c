#include "matriks.h"
#include "boolean.h"
#include <stdio.h>

int main()
{
    Matriks M;
    int i, j;

    printf("=== DEBUG addX Function ===\n");

    initMatriks(&M);
    printf("After init: nbaris=%d, nkolom=%d\n", getNBaris(M), getNKolom(M));

    // Check if matrix is properly initialized
    printf("Checking matrix after init:\n");
    int foundNonEmpty = 0;
    for (i = 1; i <= 11; i++)
    {
        for (j = 1; j <= 11; j++)
        {
            if (M.cell[i][j] != -999)
            {
                printf("ERROR: cell[%d][%d] = %d (should be -999)\n", i, j, M.cell[i][j]);
                foundNonEmpty++;
            }
        }
    }
    if (foundNonEmpty == 0)
    {
        printf("Matrix properly initialized - all cells are -999\n");
    }
    else
    {
        printf("ERROR: Found %d non-empty cells after init!\n", foundNonEmpty);
    }

    printf("\nCalling addX(1, 3, 4)...\n");
    addX(&M, 1, 3, 4);
    printf("After addX(1, 3, 4): nbaris=%d, nkolom=%d\n", getNBaris(M), getNKolom(M));

    // Check what changed
    printf("Checking matrix after addX:\n");
    int changedCells = 0;
    for (i = 1; i <= 11; i++)
    {
        for (j = 1; j <= 11; j++)
        {
            if (M.cell[i][j] != -999)
            {
                printf("cell[%d][%d] = %d\n", i, j, M.cell[i][j]);
                changedCells++;
            }
        }
    }
    printf("Total changed cells: %d\n", changedCells);

    return 0;
}