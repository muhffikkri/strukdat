/* Program   : test_simple.c */
/* Deskripsi : Simple test untuk debug matriks */

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "boolean.h"

int main()
{
    printf("=== SIMPLE TEST MATRIKS ===\n\n");

    Matriks M;
    printf("1. Testing initMatriks()...\n");
    initMatriks(&M);
    printf("   nbaris: %d, nkolom: %d\n", M.nbaris, M.nkolom);
    printf("   cell[1][1]: %d\n", M.cell[1][1]);

    printf("\n2. Testing getNBaris() and getNKolom()...\n");
    M.nbaris = 3;
    M.nkolom = 4;
    printf("   getNBaris(): %d\n", getNBaris(M));
    printf("   getNKolom(): %d\n", getNKolom(M));

    printf("\n3. Testing isEmptyMatriks()...\n");
    M.nbaris = 0;
    M.nkolom = 0;
    boolean empty = isEmptyMatriks(M);
    printf("   Empty matrix: %s\n", empty ? "true" : "false");

    printf("\n4. Testing isFullMatriks()...\n");
    M.nbaris = 11;
    M.nkolom = 11;
    boolean full = isFullMatriks(M);
    printf("   Full matrix: %s\n", full ? "true" : "false");

    printf("\n5. Testing addX()...\n");
    initMatriks(&M);
    addX(&M, 10, 1, 1);
    printf("   Added 10 at [1][1]: %d\n", M.cell[1][1]);

    printf("\n6. Testing viewMatriks()...\n");
    M.cell[1][1] = 1;
    M.cell[1][2] = 2;
    M.cell[2][1] = 3;
    M.cell[2][2] = 4;
    M.nbaris = 2;
    M.nkolom = 2;
    printf("   Matrix contents:\n");
    viewMatriks(M);

    printf("\n=== SIMPLE TEST COMPLETED ===\n");
    return 0;
}