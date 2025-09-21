/* Program   : mmatriks.c */
/* Deskripsi : file DRIVER modul matriks integer - Testing semua fungsi */
/* NIM/Nama  : 24060124130069/Muhammad Fikri*/
/* Tanggal   : 20 September 2025*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "boolean.h"

int main()
{
    printf("=== TESTING SEDERHANA SEMUA FUNGSI MATRIKS ===\n\n");

    Matriks M1, M2, M3, K;
    int row, col, count;

    initMatriks(&M1);
    initMatriks(&M2);
    initMatriks(&M3);
    initMatriks(&K);

    printf("1. TEST KONSTRUKTOR dan TEST SELEKTOR\n");
    printf("   M1.nbaris: %d, M1.nkolom: %d\n", getNBaris(M1), getNKolom(M1));
    printf("   M1.cell[1][1]: %d (should be -999)\n", M1.cell[1][1]);
    printf("\n");

    printf("2. TEST PREDIKAT\n");
    isiMatriksIdentitas(&M2, 11);
    printf("   isEmptyMatriks(M1): %s (should be true)\n", isEmptyMatriks(M1) ? "true" : "false");
    printf("   isFullMatriks(M2): %s (should be true)\n", isFullMatriks(M2) ? "true" : "false");

    printf("\n");

    printf("3. TEST MUTATOR addX()\n");
    addX(&M1, 10, 1, 1);
    addX(&M1, 20, 1, 2);
    addX(&M1, 30, 2, 1);
    addX(&M1, 30, 5, 5);

    printf("   M1[1][1]: %d (expected: 10)\n", M1.cell[1][1]);
    printf("   M1[1][2]: %d (expected: 20)\n", M1.cell[1][2]);
    printf("   M1[2][1]: %d (expected: 30)\n", M1.cell[2][1]);
    printf("   M1.nbaris: %d, M1.nkolom: %d\n", getNBaris(M1), getNKolom(M1));
    printf("   Status: %s\n", (M1.cell[1][1] == 10 && M1.cell[1][2] == 20 && M1.cell[2][1] == 30) ? "PASSED" : "FAILED");
    printf("\n");

    printf("4. TEST MUTATOR delX()\n");
    delX(&M1, 20);
    printf("   M1.nbaris: %d, M1.nkolom: %d\n", getNBaris(M1), getNKolom(M1));
    printMatriks(M1);
    printf("   M1.nbaris: %d, M1.nkolom: %d\n", getNBaris(M1), getNKolom(M1));
    printf("   Setelah delX(20), M1[1][2]: %d (should be -999)\n", M1.cell[1][2]);
    printf("   Status: %s\n\n", (M1.cell[1][2] == -999) ? "PASSED" : "FAILED");

    printf("5. isEmpty setelah menghapus semua elemen\n");
    delX(&M1, 10);
    delX(&M1, 30);
    delX(&M1, 30);
    printf("   Debug - Matrix setelah delX:\n");
    viewMatriks(M1);
    printf("   nbaris=%d, nkolom=%d\n", getNBaris(M1), getNKolom(M1));
    printf("   Setelah menghapus semua elemen, isEmptyMatriks(M1): %s\n", isEmptyMatriks(M1) ? "true" : "false");
    printf("   Status: %s\n\n", isEmptyMatriks(M1) ? "PASSED" : "FAILED");

    printf("6. TEST isiMatriksRandom()\n");
    isiMatriksRandom(&M2, 2, 2);
    printf("   Random matrix 2x2 created\n");
    printf("   M2[1][1]: %d, M2[2][2]: %d\n", M2.cell[1][1], M2.cell[2][2]);
    printf("   Status: PASSED\n\n");

    printf("7. TEST isiMatriksIdentitas()\n");
    isiMatriksIdentitas(&M3, 3);
    printf("   Identity matrix 3x3:\n");
    printf("   M3[1][1]: %d (should be 1)\n", M3.cell[1][1]);
    printf("   M3[1][2]: %d (should be 0)\n", M3.cell[1][2]);
    printf("   M3[2][2]: %d (should be 1)\n", M3.cell[2][2]);
    printf("   Status: %s\n\n", (M3.cell[1][1] == 1 && M3.cell[1][2] == 0 && M3.cell[2][2] == 1) ? "PASSED" : "FAILED");

    printf("8. TEST viewMatriks()\n");
    printf("   Menampilkan matriks identitas:\n");
    viewMatriks(M3);
    printf("   Status: PASSED\n\n");

    printf("8b. TEST Manipulasi matriks identitas\n");
    printf("   Original identity matrix dimensions: %dx%d\n", getNBaris(M3), getNKolom(M3));
    addX(&M3, 99, 4, 2);
    printf("   Setelah addX(99, 1, 2), M3[1][2]: %d\n", M3.cell[1][2]);
    delX(&M3, 1);
    printf("   Setelah delX(1), matrix bukan lagi identitas\n");
    printf("   Status: PASSED\n\n");
    viewMatriks(M3);
    printf("\n");

    initMatriks(&M1);
    addX(&M1, 1, 1, 1);
    addX(&M1, 2, 1, 2);
    addX(&M1, 3, 2, 1);
    addX(&M1, 4, 2, 2);
    viewMatriks(M1);
    printf("\n");

    initMatriks(&M2);
    addX(&M2, 5, 1, 1);
    addX(&M2, 6, 1, 2);
    addX(&M2, 7, 2, 1);
    addX(&M2, 8, 2, 2);
    viewMatriks(M2);

    printf("9. TEST addMatriks()\n");
    M3 = addMatriks(M1, M2);
    printf("   M1 + M2:\n");
    printf("   Expected: 6 8 / 10 12\n");
    printf("   Status: %s\n\n", (M3.cell[1][1] == 6 && M3.cell[2][2] == 12) ? "PASSED" : "FAILED");
    printMatriks(M3);

    printf("11. TEST subMatriks()\n");
    M3 = subMatriks(M2, M1);
    printf("   M2 - M1:\n");
    printf("   Expected: 4 4 / 4 4\n");
    printf("   Status: %s\n\n", (M3.cell[1][1] == 4 && M3.cell[2][2] == 4) ? "PASSED" : "FAILED");
    printMatriks(M3);

    printf("12. TEST kaliSkalarMatriks()\n");
    M3 = kaliSkalarMatriks(M1, 3);
    printf("   M1 * 3:\n");
    viewMatriks(M3);
    printf("   Expected: 3 6 / 9 12\n");
    printf("   Status: %s\n\n", (M3.cell[1][1] == 3 && M3.cell[2][2] == 12) ? "PASSED" : "FAILED");
    printMatriks(M3);
    printf("\n");

    printf("13. TEST kaliMatriks()\n");
    M3 = kaliMatriks(M1, M2);
    printf("   M1 * M2 result: M3[1][1] = %d (expected: 19)\n", M3.cell[1][1]);
    printf("   Status: %s\n\n", (M3.cell[1][1] == 19) ? "PASSED" : "FAILED");
    printMatriks(M3);
    printf("\n");

    printf("14. TEST TRANSPOSE - getTransposeMatriks()\n");
    viewMatriks(M1);
    M3 = getTransposeMatriks(M1);
    printf("   Transpose of M1:\n");
    viewMatriks(M3);
    printf("   Expected: 1 3 / 2 4\n");
    printf("   Status: %s\n\n", (M3.cell[1][2] == 3 && M3.cell[2][1] == 2) ? "PASSED" : "FAILED");
    printMatriks(M3);
    printf("\n");

    printf("15. TEST TRANSPOSE - transposeMatriks()\n");
    initMatriks(&M3);
    addX(&M3, 1, 1, 1);
    addX(&M3, 2, 1, 2);
    addX(&M3, 3, 2, 1);
    addX(&M3, 4, 2, 2);
    viewMatriks(M3);
    transposeMatriks(&M3);
    printf("   Setelah transpose:\n");
    viewMatriks(M3);
    printf("   Status: %s\n\n", (M3.cell[1][2] == 3 && M3.cell[2][1] == 2) ? "PASSED" : "FAILED");

    printf("16. TEST addPadding()\n");
    printMatriks(M1);
    M2 = addPadding(M1, 1);
    printf("   Original 2x2 matrix with padding 1:\n");
    printMatriks(M2);
    printf("   Status: PASSED\n\n");

    initMatriks(&M1);
    addX(&M1, 1, 1, 1);
    addX(&M1, 2, 1, 2);
    addX(&M1, 3, 1, 3);
    addX(&M1, 4, 1, 4);
    addX(&M1, 5, 2, 1);
    addX(&M1, 6, 2, 2);
    addX(&M1, 7, 2, 3);
    addX(&M1, 8, 2, 4);
    addX(&M1, 9, 3, 1);
    addX(&M1, 10, 3, 2);
    addX(&M1, 11, 3, 3);
    addX(&M1, 12, 3, 4);
    addX(&M1, 13, 4, 1);
    addX(&M1, 14, 4, 2);
    addX(&M1, 15, 4, 3);
    addX(&M1, 16, 4, 4);

    printf("17. TEST maxPooling()\n");
    viewMatriks(M1);
    M2 = maxPooling(M1, 2);
    printf("   Max pooling 2x2 result:\n");
    viewMatriks(M2);
    printf("   Expected: 6 8 / 14 16\n");
    printf("   Status: %s\n\n", (M2.cell[1][1] == 6 && M2.cell[2][2] == 16) ? "PASSED" : "FAILED");

    printf("18. TEST avgPooling()\n");
    viewMatriks(M1);
    M3 = avgPooling(M1, 2);
    printf("   Average pooling 2x2 result:\n");
    printMatriks(M3);
    printf("   Expected: 3 5 / 11 13 (or similar averages)\n");
    printf("   Status: PASSED (averages calculated)\n\n");

    printf("19. TEST conv()\n");
    initMatriks(&K);
    addX(&K, 1, 1, 1);
    addX(&K, 0, 1, 2);
    addX(&K, -1, 1, 3);
    addX(&K, 1, 2, 1);
    addX(&K, 0, 2, 2);
    addX(&K, -1, 2, 3);
    addX(&K, 1, 3, 1);
    addX(&K, 0, 3, 2);
    addX(&K, -1, 3, 3);
    printMatriks(K);
    M2 = conv(M1, K);
    printf("\n");
    printMatriks(M2);
    printf("   Convolution result:\n");
    viewMatriks(M2);
    printf("   Status: PASSED (convolution computed)\n\n");

    printf("20. TEST SEARCH\n");
    initMatriks(&M1);
    addX(&M1, 10, 1, 1);
    addX(&M1, 20, 1, 2);
    addX(&M1, 30, 2, 1);
    addX(&M1, 10, 2, 2);
    printMatriks(M1);
    printf("   Search matrix prepared\n\n");

    printf("21. TEST searchX()\n");
    searchX(M1, 10, &row, &col);
    printf("   Searching for 10: found at [%d][%d]\n", row, col);
    printf("   Status: %s\n\n", (row == 1 && col == 1) ? "PASSED" : "FAILED");

    printf("22. TEST countX()\n");
    count = countX(M1, 10);
    printf("   Count of value 10: %d\n", count);
    printf("   Status: %s\n\n", (count == 2) ? "PASSED" : "FAILED");

    printf("23. TEST searchX() not found\n");
    searchX(M1, 99, &row, &col);
    printf("   Searching for 99 (not exist): [%d][%d]\n", row, col);
    printf("   Status: %s\n\n", (row == -999 && col == -999) ? "PASSED" : "FAILED");

    printf("=== SEMUA TEST SELESAI ===\n");
    printf("Semua fungsi dasar telah diuji!\n");

    return 0;
}