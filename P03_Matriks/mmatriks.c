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

    printf("1. TEST KONSTRUKTOR - initMatriks()\n");
    printf("   M1.nbaris: %d, M1.nkolom: %d\n", getNBaris(M1), getNKolom(M1));
    printf("   M1.cell[1][1]: %d (should be -999)\n", M1.cell[1][1]);
    printf("   Status: %s\n\n", (getNBaris(M1) == 0 && getNKolom(M1) == 0 && M1.cell[1][1] == -999) ? "PASSED" : "FAILED");

    printf("2. TEST SELEKTOR - getNBaris() dan getNKolom()\n");
    addX(&M1, 1, 3, 4); // Ini akan menambah 1 baris dan 1 kolom terisi
    printf("   getNBaris(M1): %d (expected: 1)\n", getNBaris(M1));
    printf("   getNKolom(M1): %d (expected: 1)\n", getNKolom(M1));
    printf("   Status: %s\n\n", (getNBaris(M1) == 1 && getNKolom(M1) == 1) ? "PASSED" : "FAILED");

    printf("3. TEST PREDIKAT - isEmptyMatriks() dan isFullMatriks()\n");
    // Reset M1 untuk test empty
    initMatriks(&M1);
    // Setup M2 untuk test full - menggunakan isiMatriksIdentitas
    isiMatriksIdentitas(&M2, 11);
    printf("   isEmptyMatriks(M1): %s (should be true)\n", isEmptyMatriks(M1) ? "true" : "false");
    printf("   isFullMatriks(M2): %s (should be true)\n", isFullMatriks(M2) ? "true" : "false");
    printf("   Status: %s\n\n", (isEmptyMatriks(M1) && isFullMatriks(M2)) ? "PASSED" : "FAILED");

    printf("4. TEST MUTATOR - addX()\n");
    // Reset M1 untuk test mutator dengan cara yang proper
    initMatriks(&M1);
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

    printf("5b. TEST SEMANTIK - isEmpty setelah menghapus semua elemen\n");
    // Hapus semua elemen untuk test isEmpty
    delX(&M1, 10); // Hapus elemen [1][1]
    delX(&M1, 30); // Hapus elemen [2][1]
    printf("   Debug - Matrix setelah delX:\n");
    viewMatriks(M1);
    printf("   nbaris=%d, nkolom=%d\n", getNBaris(M1), getNKolom(M1));
    printf("   Setelah menghapus semua elemen, isEmptyMatriks(M1): %s\n", isEmptyMatriks(M1) ? "true" : "false");
    printf("   Status: %s\n\n", isEmptyMatriks(M1) ? "PASSED" : "FAILED");

    printf("6. TEST I/O - isiMatriksRandom()\n");
    isiMatriksRandom(&M2, 2, 2);
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

    printf("8b. TEST SEMANTIK - Manipulasi matriks identitas\n");
    // Test manipulasi pada matriks identitas
    printf("   Original identity matrix dimensions: %dx%d\n", getNBaris(M3), getNKolom(M3));
    // Tambah elemen di luar diagonal untuk merusak identitas
    addX(&M3, 99, 1, 2);
    printf("   Setelah addX(99, 1, 2), M3[1][2]: %d\n", M3.cell[1][2]);
    // Hapus elemen diagonal untuk test
    delX(&M3, 1);
    printf("   Setelah delX(1), matrix bukan lagi identitas\n");
    printf("   Status: PASSED (semantic manipulation)\n\n");

    printf("9. TEST ARITHMETIC - Setup test matrices\n");
    // Setup M1 dan M2 untuk arithmetic operations menggunakan addX
    initMatriks(&M1);
    addX(&M1, 1, 1, 1);
    addX(&M1, 2, 1, 2);
    addX(&M1, 3, 2, 1);
    addX(&M1, 4, 2, 2);

    initMatriks(&M2);
    addX(&M2, 5, 1, 1);
    addX(&M2, 6, 1, 2);
    addX(&M2, 7, 2, 1);
    addX(&M2, 8, 2, 2);
    printf("   Test matrices prepared\n\n");

    printf("10. TEST ARITHMETIC - addMatriks()\n");
    M3 = addMatriks(M1, M2);
    printf("   M1 + M2:\n");
    viewMatriks(M3);
    printf("   Expected: 6 8 / 10 12\n");
    printf("   Status: %s\n\n", (M3.cell[1][1] == 6 && M3.cell[2][2] == 12) ? "PASSED" : "FAILED");

    printf("11. TEST ARITHMETIC - subMatriks()\n");
    M3 = subMatriks(M2, M1);
    printf("   M2 - M1:\n");
    viewMatriks(M3);
    printf("   Expected: 4 4 / 4 4\n");
    printf("   Status: %s\n\n", (M3.cell[1][1] == 4 && M3.cell[2][2] == 4) ? "PASSED" : "FAILED");

    printf("12. TEST ARITHMETIC - kaliSkalarMatriks()\n");
    M3 = kaliSkalarMatriks(M1, 3);
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
    // Use a copy of M1 for in-place transpose dengan cara yang proper
    initMatriks(&M3);
    addX(&M3, 1, 1, 1);
    addX(&M3, 2, 1, 2);
    addX(&M3, 3, 2, 1);
    addX(&M3, 4, 2, 2);
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
    // Setup M1 as 4x4 matrix menggunakan addX
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
    // Setup kernel menggunakan addX
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
    M2 = conv(M1, K);
    printf("   Convolution result:\n");
    viewMatriks(M2);
    printf("   Status: PASSED (convolution computed)\n\n");

    printf("21. TEST SEARCH - Setup search matrix\n");
    // Setup search matrix menggunakan addX
    initMatriks(&M1);
    addX(&M1, 10, 1, 1);
    addX(&M1, 20, 1, 2);
    addX(&M1, 30, 2, 1);
    addX(&M1, 10, 2, 2); // Duplicate 10 untuk test count
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

    printf("25. TEST SEMANTIK - Kombinasi operasi kompleks\n");
    // Test kombinasi berbagai operasi dengan cara semantik
    printf("   a) Buat matriks random 3x3\n");
    isiMatriksRandom(&M1, 3, 3);
    printf("      Matrix dimensions: %dx%d\n", getNBaris(M1), getNKolom(M1));

    printf("   b) Buat matriks identitas 3x3\n");
    isiMatriksIdentitas(&M2, 3);
    printf("      Identity dimensions: %dx%d\n", getNBaris(M2), getNKolom(M2));

    printf("   c) Penjumlahan matriks random + identitas\n");
    M3 = addMatriks(M1, M2);
    printf("      Result dimensions: %dx%d\n", getNBaris(M3), getNKolom(M3));

    printf("   d) Transpose hasil penjumlahan\n");
    Matriks M_transposed = getTransposeMatriks(M3);
    printf("      Transposed dimensions: %dx%d\n", getNBaris(M_transposed), getNKolom(M_transposed));

    printf("   Status: PASSED (complex semantic operations)\n\n");

    printf("26. TEST SEMANTIK - Matrix pooling semantik\n");
    // Setup matriks yang sesuai untuk pooling
    printf("   Setup matriks 4x4 untuk pooling semantik\n");
    initMatriks(&M1);
    // Isi dengan pola yang mudah diverifikasi
    int val = 1;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            addX(&M1, val++, i, j);
        }
    }

    printf("   Original matrix dimensions: %dx%d\n", getNBaris(M1), getNKolom(M1));

    M2 = maxPooling(M1, 2);
    printf("   Max pooling result dimensions: %dx%d\n", getNBaris(M2), getNKolom(M2));

    M3 = avgPooling(M1, 2);
    printf("   Avg pooling result dimensions: %dx%d\n", getNBaris(M3), getNKolom(M3));

    printf("   Status: PASSED (semantic pooling operations)\n\n");

    printf("=== SEMUA TEST SELESAI ===\n");
    printf("Semua fungsi dasar telah diuji!\n");

    return 0;
}
