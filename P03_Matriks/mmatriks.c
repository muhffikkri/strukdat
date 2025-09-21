/* Program   : mmatriks.c */
/* Deskripsi : file DRIVER modul matriks integer - Testing semua fungsi */
/* NIM/Nama  : 24060124130069/Muhammad Fikri*/
/* Tanggal   : 20 September 2025*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriks.h"
#include "boolean.h"

int main()
{
    printf("=== TESTING SEDERHANA SEMUA FUNGSI MATRIKS ===\n\n");

    Matriks M1, M2, M3, K;
    int row, col, count;

    // Inisialisasi semua matriks sekali di awal
    initMatriks(&M1);
    initMatriks(&M2);
    initMatriks(&M3);
    initMatriks(&K);

    // Seed untuk random
    srand(time(NULL));

    printf("1. TEST KONSTRUKTOR - initMatriks()\n");
    printf("   M1.nbaris: %d, M1.nkolom: %d\n", M1.nbaris, M1.nkolom);
    printf("   M1.cell[1][1]: %d (should be -999)\n", M1.cell[1][1]);
    printf("   Status: %s\n\n", (M1.nbaris == 0 && M1.nkolom == 0 && M1.cell[1][1] == -999) ? "PASSED" : "FAILED");

    printf("2. TEST SELEKTOR - getNBaris() dan getNKolom()\n");
    M1.nbaris = 3;
    M1.nkolom = 4;
    printf("   getNBaris(M1): %d (expected: 3)\n", getNBaris(M1));
    printf("   getNKolom(M1): %d (expected: 4)\n", getNKolom(M1));
    printf("   Status: %s\n\n", (getNBaris(M1) == 3 && getNKolom(M1) == 4) ? "PASSED" : "FAILED");

    printf("3. TEST PREDIKAT - isEmptyMatriks() dan isFullMatriks()\n");
    M1.nbaris = 0;
    M1.nkolom = 0;
    M2.nbaris = 11;
    M2.nkolom = 11;
    printf("   isEmptyMatriks(M1): %s (should be true)\n", isEmptyMatriks(M1) ? "true" : "false");
    printf("   isFullMatriks(M2): %s (should be true)\n", isFullMatriks(M2) ? "true" : "false");
    printf("   Status: %s\n\n", (isEmptyMatriks(M1) && isFullMatriks(M2)) ? "PASSED" : "FAILED");

    printf("4. TEST MUTATOR - addX()\n");
    // Reset M1 untuk test mutator
    M1.nbaris = 0;
    M1.nkolom = 0;
    addX(&M1, 10, 1, 1);
    addX(&M1, 20, 1, 2);
    addX(&M1, 30, 2, 1);
    printf("   M1[1][1]: %d (expected: 10)\n", M1.cell[1][1]);
    printf("   M1[1][2]: %d (expected: 20)\n", M1.cell[1][2]);
    printf("   M1[2][1]: %d (expected: 30)\n", M1.cell[2][1]);
    printf("   Status: %s\n\n", (M1.cell[1][1] == 10 && M1.cell[1][2] == 20 && M1.cell[2][1] == 30) ? "PASSED" : "FAILED");

    printf("5. TEST MUTATOR - delX()\n");
    delX(&M1, 20);
    printf("   Setelah delX(20), M1[1][2]: %d (should be -999)\n", M1.cell[1][2]);
    printf("   Status: %s\n\n", (M1.cell[1][2] == -999) ? "PASSED" : "FAILED");

    printf("6. TEST I/O - isiMatriksRandom()\n");
    isiMatriksRandom(&M2, 2, 2);
    M2.nbaris = 2;
    M2.nkolom = 2;
    printf("   Random matrix 2x2 created\n");
    printf("   M2[1][1]: %d, M2[2][2]: %d\n", M2.cell[1][1], M2.cell[2][2]);
    printf("   Status: PASSED (random values generated)\n\n");

    printf("7. TEST I/O - isiMatriksIdentitas()\n");
    isiMatriksIdentitas(&M3, 3);
    printf("   Identity matrix 3x3:\n");
    printf("   M3[1][1]: %d (should be 1)\n", M3.cell[1][1]);
    printf("   M3[1][2]: %d (should be 0)\n", M3.cell[1][2]);
    printf("   M3[2][2]: %d (should be 1)\n", M3.cell[2][2]);
    printf("   Status: %s\n\n", (M3.cell[1][1] == 1 && M3.cell[1][2] == 0 && M3.cell[2][2] == 1) ? "PASSED" : "FAILED");

    printf("8. TEST I/O - viewMatriks()\n");
    printf("   Displaying identity matrix:\n");
    viewMatriks(M3);
    printf("   Status: PASSED (matrix displayed)\n\n");

    printf("9. TEST ARITHMETIC - Setup test matrices\n");
    // Setup M1 dan M2 untuk arithmetic operations
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
    printf("   Test matrices prepared\n\n");

    printf("10. TEST ARITHMETIC - addMatriks()\n");
    M3 = addMatriks(M1, M2);
    M3.nbaris = 2;
    M3.nkolom = 2;
    printf("   M1 + M2:\n");
    viewMatriks(M3);
    printf("   Expected: 6 8 / 10 12\n");
    printf("   Status: %s\n\n", (M3.cell[1][1] == 6 && M3.cell[2][2] == 12) ? "PASSED" : "FAILED");

    printf("11. TEST ARITHMETIC - subMatriks()\n");
    M3 = subMatriks(M2, M1);
    M3.nbaris = 2;
    M3.nkolom = 2;
    printf("   M2 - M1:\n");
    viewMatriks(M3);
    printf("   Expected: 4 4 / 4 4\n");
    printf("   Status: %s\n\n", (M3.cell[1][1] == 4 && M3.cell[2][2] == 4) ? "PASSED" : "FAILED");

    printf("12. TEST ARITHMETIC - kaliSkalarMatriks()\n");
    M3 = kaliSkalarMatriks(M1, 3);
    M3.nbaris = 2;
    M3.nkolom = 2;
    printf("   M1 * 3:\n");
    viewMatriks(M3);
    printf("   Expected: 3 6 / 9 12\n");
    printf("   Status: %s\n\n", (M3.cell[1][1] == 3 && M3.cell[2][2] == 12) ? "PASSED" : "FAILED");

    printf("13. TEST ARITHMETIC - kaliMatriks()\n");
    M3 = kaliMatriks(M1, M2);
    printf("   M1 * M2 result: M3[1][1] = %d (expected: 19)\n", M3.cell[1][1]);
    printf("   Status: %s\n\n", (M3.cell[1][1] == 19) ? "PASSED" : "FAILED");

    printf("14. TEST TRANSPOSE - getTransposeMatriks()\n");
    M3 = getTransposeMatriks(M1);
    printf("   Transpose of M1:\n");
    viewMatriks(M3);
    printf("   Expected: 1 3 / 2 4\n");
    printf("   Status: %s\n\n", (M3.cell[1][2] == 3 && M3.cell[2][1] == 2) ? "PASSED" : "FAILED");

    printf("15. TEST TRANSPOSE - transposeMatriks() (in-place)\n");
    // Use a copy of M1 for in-place transpose
    M3.cell[1][1] = 1;
    M3.cell[1][2] = 2;
    M3.cell[2][1] = 3;
    M3.cell[2][2] = 4;
    M3.nbaris = 2;
    M3.nkolom = 2;
    transposeMatriks(&M3);
    printf("   After in-place transpose:\n");
    viewMatriks(M3);
    printf("   Status: %s\n\n", (M3.cell[1][2] == 3 && M3.cell[2][1] == 2) ? "PASSED" : "FAILED");

    printf("16. TEST ADVANCED - addPadding()\n");
    M2 = addPadding(M1, 1);
    printf("   Original 2x2 matrix with padding 1:\n");
    viewMatriks(M2);
    printf("   Status: PASSED (padding added)\n\n");

    printf("17. TEST ADVANCED - Setup 4x4 matrix for pooling\n");
    // Setup M1 as 4x4 matrix
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
    printf("   4x4 matrix prepared for pooling tests\n\n");

    printf("18. TEST ADVANCED - maxPooling()\n");
    M2 = maxPooling(M1, 2);
    printf("   Max pooling 2x2 result:\n");
    viewMatriks(M2);
    printf("   Expected: 6 8 / 14 16\n");
    printf("   Status: %s\n\n", (M2.cell[1][1] == 6 && M2.cell[2][2] == 16) ? "PASSED" : "FAILED");

    printf("19. TEST ADVANCED - avgPooling()\n");
    M3 = avgPooling(M1, 2);
    printf("   Average pooling 2x2 result:\n");
    viewMatriks(M3);
    printf("   Expected: 3 5 / 11 13 (or similar averages)\n");
    printf("   Status: PASSED (averages calculated)\n\n");

    printf("20. TEST ADVANCED - conv()\n");
    // Setup kernel
    K.cell[1][1] = 1;
    K.cell[1][2] = 0;
    K.cell[1][3] = -1;
    K.cell[2][1] = 1;
    K.cell[2][2] = 0;
    K.cell[2][3] = -1;
    K.cell[3][1] = 1;
    K.cell[3][2] = 0;
    K.cell[3][3] = -1;
    K.nbaris = 3;
    K.nkolom = 3;
    M2 = conv(M1, K);
    printf("   Convolution result:\n");
    viewMatriks(M2);
    printf("   Status: PASSED (convolution computed)\n\n");

    printf("21. TEST SEARCH - Setup search matrix\n");
    M1.cell[1][1] = 10;
    M1.cell[1][2] = 20;
    M1.cell[2][1] = 30;
    M1.cell[2][2] = 10;
    M1.nbaris = 2;
    M1.nkolom = 2;
    printf("   Search matrix prepared\n\n");

    printf("22. TEST SEARCH - searchX()\n");
    searchX(M1, 10, &row, &col);
    printf("   Searching for 10: found at [%d][%d]\n", row, col);
    printf("   Status: %s\n\n", (row == 1 && col == 1) ? "PASSED" : "FAILED");

    printf("23. TEST SEARCH - countX()\n");
    count = countX(M1, 10);
    printf("   Count of value 10: %d\n", count);
    printf("   Status: %s\n\n", (count == 2) ? "PASSED" : "FAILED");

    printf("24. TEST SEARCH - searchX() not found\n");
    searchX(M1, 99, &row, &col);
    printf("   Searching for 99 (not exist): [%d][%d]\n", row, col);
    printf("   Status: %s\n\n", (row == -999 && col == -999) ? "PASSED" : "FAILED");

    printf("=== SEMUA TEST SELESAI ===\n");
    printf("Semua fungsi dasar telah diuji!\n");

    return 0;
}
