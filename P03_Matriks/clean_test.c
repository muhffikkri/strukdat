#include "matriks.h"
#include "boolean.h"
#include <stdio.h>

int main() {
    Matriks M;
    int i, j;
    
    printf("=== CLEAN TEST initMatriks ===\n");
    
    // Initialize matrix
    initMatriks(&M);
    
    // Check matrix is clean
    for (i = 1; i <= 11; i++) {
        for (j = 1; j <= 11; j++) {
            if (M.cell[i][j] != -999) {
                printf("ERROR at init: cell[%d][%d] = %d\n", i, j, M.cell[i][j]);
                return 1;
            }
        }
    }
    
    printf("initMatriks: OK - all cells are -999\n");
    printf("nbaris=%d, nkolom=%d\n", M.nbaris, M.nkolom);
    
    // Now add one element
    addX(&M, 42, 3, 4);
    
    // Check what happened
    printf("After addX(42, 3, 4):\n");
    for (i = 1; i <= 11; i++) {
        for (j = 1; j <= 11; j++) {
            if (M.cell[i][j] != -999) {
                printf("cell[%d][%d] = %d\n", i, j, M.cell[i][j]);
            }
        }
    }
    printf("nbaris=%d, nkolom=%d\n", M.nbaris, M.nkolom);
    
    return 0;
}