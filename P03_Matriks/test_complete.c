/* Program   : test_complete.c */
/* Deskripsi : Comprehensive test untuk semua fungsi matriks */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriks.h"
#include "boolean.h"

int main()
{
    printf("=== TESTING SEMUA FUNGSI MATRIKS ===\n\n");

    // Seed untuk random number generator
    srand(time(NULL));

    // Test 1: Konstruktor
    printf("==================== TEST KONSTRUKTOR ====================\n");
    Matriks M;
    printf("1. Testing initMatriks()...\n");
    initMatriks(&M);
    printf("   nbaris: %d, nkolom: %d\n", M.nbaris, M.nkolom);
    printf("   cell[1][1]: %d (should be -999)\n", M.cell[1][1]);
    printf("   Status: %s\n", (M.nbaris == 0 && M.nkolom == 0 && M.cell[1][1] == -999) ? "PASSED" : "FAILED");

    // Test 2: Selektor
    printf("\n==================== TEST SELEKTOR ====================\n");
    M.nbaris = 3;
    M.nkolom = 4;
    printf("1. Testing getNBaris()...\n");
    int baris = getNBaris(M);
    printf("   Expected: 3, Got: %d\n", baris);
    printf("   Status: %s\n", (baris == 3) ? "PASSED" : "FAILED");

    printf("2. Testing getNKolom()...\n");
    int kolom = getNKolom(M);
    printf("   Expected: 4, Got: %d\n", kolom);
    printf("   Status: %s\n", (kolom == 4) ? "PASSED" : "FAILED");

    // Test 3: Predikat
    printf("\n==================== TEST PREDIKAT ====================\n");
    Matriks M1, M2;
    initMatriks(&M1);
    initMatriks(&M2);

    printf("1. Testing isEmptyMatriks()...\n");
    boolean empty = isEmptyMatriks(M1);
    printf("   Empty matrix result: %s\n", empty ? "true" : "false");
    printf("   Status: %s\n", empty ? "PASSED" : "FAILED");

    M2.nbaris = 11;
    M2.nkolom = 11;
    printf("2. Testing isFullMatriks()...\n");
    boolean full1 = isFullMatriks(M1);
    boolean full2 = isFullMatriks(M2);
    printf("   Empty matrix full check: %s (should be false)\n", full1 ? "true" : "false");
    printf("   Full matrix full check: %s (should be true)\n", full2 ? "true" : "false");
    printf("   Status: %s\n", (!full1 && full2) ? "PASSED" : "FAILED");

    // Test 4: Mutator
    printf("\n==================== TEST MUTATOR ====================\n");
    initMatriks(&M);
    printf("1. Testing addX()...\n");
    addX(&M, 10, 1, 1);
    addX(&M, 20, 1, 2);
    addX(&M, 30, 2, 1);
    printf("   M[1][1] = %d (expected: 10)\n", M.cell[1][1]);
    printf("   M[1][2] = %d (expected: 20)\n", M.cell[1][2]);
    printf("   M[2][1] = %d (expected: 30)\n", M.cell[2][1]);
    printf("   Matrix dimensions: %dx%d\n", M.nbaris, M.nkolom);

    // Test 5: I/O Operations
    printf("\n==================== TEST I/O OPERATIONS ====================\n");
    initMatriks(&M1);
    printf("1. Testing isiMatriksIdentitas()...\n");
    isiMatriksIdentitas(&M1, 3);
    printf("   Identity matrix 3x3:\n");
    viewMatriks(M1);
    printf("   Diagonal elements: M[1][1]=%d, M[2][2]=%d, M[3][3]=%d\n",
           M1.cell[1][1], M1.cell[2][2], M1.cell[3][3]);
    boolean identity_ok = (M1.cell[1][1] == 1 && M1.cell[2][2] == 1 && M1.cell[3][3] == 1 &&
                           M1.cell[1][2] == 0 && M1.cell[2][1] == 0);
    printf("   Status: %s\n", identity_ok ? "PASSED" : "FAILED");

    // Test 6: Arithmetic Operations
    printf("\n==================== TEST ARITHMETIC OPERATIONS ====================\n");
    initMatriks(&M1);
    initMatriks(&M2);

    // Create simple 2x2 matrices
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
    printf("Matrix M2:\n");
    viewMatriks(M2);

    printf("1. Testing addMatriks()...\n");
    Matriks M3 = addMatriks(M1, M2);
    M3.nbaris = 2;
    M3.nkolom = 2;
    printf("   M1 + M2 =\n");
    viewMatriks(M3);

    printf("2. Testing subMatriks()...\n");
    M3 = subMatriks(M2, M1);
    M3.nbaris = 2;
    M3.nkolom = 2;
    printf("   M2 - M1 =\n");
    viewMatriks(M3);

    printf("3. Testing kaliSkalarMatriks()...\n");
    M3 = kaliSkalarMatriks(M1, 2);
    M3.nbaris = 2;
    M3.nkolom = 2;
    printf("   M1 * 2 =\n");
    viewMatriks(M3);

    // Test 7: Transpose Operations
    printf("\n==================== TEST TRANSPOSE ====================\n");
    printf("1. Testing getTransposeMatriks()...\n");
    M3 = getTransposeMatriks(M1);
    printf("   Transpose of M1:\n");
    viewMatriks(M3);

    // Test 8: Search Operations
    printf("\n==================== TEST SEARCH ====================\n");
    initMatriks(&M);
    M.cell[1][1] = 10;
    M.cell[1][2] = 20;
    M.cell[1][3] = 10;
    M.cell[2][1] = 30;
    M.cell[2][2] = 10;
    M.cell[2][3] = 40;
    M.cell[3][1] = 50;
    M.cell[3][2] = 60;
    M.cell[3][3] = 10;
    M.nbaris = 3;
    M.nkolom = 3;

    printf("Test matrix:\n");
    viewMatriks(M);

    printf("1. Testing searchX()...\n");
    int row, col;
    searchX(M, 10, &row, &col);
    printf("   Searching for 10: found at [%d][%d]\n", row, col);

    searchX(M, 99, &row, &col);
    printf("   Searching for 99: found at [%d][%d] (should be [-999][-999])\n", row, col);

    printf("2. Testing countX()...\n");
    int count = countX(M, 10);
    printf("   Count of 10: %d occurrences\n", count);

    count = countX(M, 99);
    printf("   Count of 99: %d occurrences (should be 0)\n", count);

    // Test 9: Advanced Operations
    printf("\n==================== TEST ADVANCED OPERATIONS ====================\n");
    printf("1. Testing addPadding()...\n");
    initMatriks(&M1);
    M1.cell[1][1] = 1;
    M1.cell[1][2] = 2;
    M1.cell[2][1] = 3;
    M1.cell[2][2] = 4;
    M1.nbaris = 2;
    M1.nkolom = 2;

    printf("   Original 2x2 matrix:\n");
    viewMatriks(M1);

    M2 = addPadding(M1, 1);
    printf("   After padding with 1:\n");
    viewMatriks(M2);

    printf("2. Testing maxPooling()...\n");
    // Create 4x4 matrix for pooling
    initMatriks(&M1);
    M1.cell[1][1] = 1;
    M1.cell[1][2] = 2;
    M1.cell[1][3] = 3;
    M1.cell[1][4] = 4;
    M1.cell[2][1] = 5;
    M1.cell[2][2] = 6;
    M1.cell[2][3] = 7;
    M1.cell[2][4] = 8;
    M1.cell[3][1] = 9;
    M1.cell[3][2] = 10;
    M1.cell[3][3] = 11;
    M1.cell[3][4] = 12;
    M1.cell[4][1] = 13;
    M1.cell[4][2] = 14;
    M1.cell[4][3] = 15;
    M1.cell[4][4] = 16;
    M1.nbaris = 4;
    M1.nkolom = 4;

    printf("   Original 4x4 matrix:\n");
    viewMatriks(M1);

    M2 = maxPooling(M1, 2);
    printf("   After max pooling (2x2):\n");
    viewMatriks(M2);

    printf("3. Testing avgPooling()...\n");
    M3 = avgPooling(M1, 2);
    printf("   After avg pooling (2x2):\n");
    viewMatriks(M3);

    printf("\n=== SEMUA TEST SELESAI ===\n");
    return 0;
}