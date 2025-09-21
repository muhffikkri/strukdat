/* Program   : test_dimensi.c */
/* Deskripsi : Test untuk memverifikasi perhitungan nbaris dan nkolom yang benar */
/* NIM/Nama  : 24060124130069/Muhammad Fikri*/
/* Tanggal   : 21 September 2025*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "boolean.h"

int main()
{
    Matriks M;

    printf("1. Test: Matriks kosong kemudian ditambah di (3,3)\n");
    initMatriks(&M);
    printf("   Awal: nbaris=%d, nkolom=%d\n", getNBaris(M), getNKolom(M));

    addX(&M, 100, 3, 3);
    printf("   Setelah addX(100, 3, 3): nbaris=%d, nkolom=%d\n", getNBaris(M), getNKolom(M));
    printf("   Expected: nbaris=1, nkolom=1 (1 baris terisi, 1 kolom terisi)\n");
    printf("   Status: %s\n\n", (getNBaris(M) == 1 && getNKolom(M) == 1) ? "PASSED" : "FAILED");

    printf("2. Test: Tambah di (3,5) - kolom baru terisi\n");
    addX(&M, 200, 3, 5);
    printf("   Setelah addX(200, 3, 5): nbaris=%d, nkolom=%d\n", getNBaris(M), getNKolom(M));
    printf("   Expected: nbaris=1, nkolom=2 (1 baris terisi, 2 kolom terisi)\n");
    printf("   Status: %s\n\n", (getNBaris(M) == 1 && getNKolom(M) == 2) ? "PASSED" : "FAILED");

    printf("3. Test: Tambah di (5,3) - baris baru terisi\n");
    addX(&M, 300, 5, 3);
    printf("   Setelah addX(300, 5, 3): nbaris=%d, nkolom=%d\n", getNBaris(M), getNKolom(M));
    printf("   Expected: nbaris=2, nkolom=2 (2 baris terisi, 2 kolom terisi)\n");
    printf("   Status: %s\n\n", (getNBaris(M) == 2 && getNKolom(M) == 2) ? "PASSED" : "FAILED");

    printf("4. Test: Tambah di (1,1) - baris dan kolom baru terisi\n");
    addX(&M, 400, 1, 1);
    printf("   Setelah addX(400, 1, 1): nbaris=%d, nkolom=%d\n", getNBaris(M), getNKolom(M));
    printf("   Expected: nbaris=3, nkolom=3 (3 baris terisi, 3 kolom terisi)\n");
    printf("   Status: %s\n\n", (getNBaris(M) == 3 && getNKolom(M) == 3) ? "PASSED" : "FAILED");

    printf("5. Test: Tambah di (5,5) - tidak menambah jumlah baris/kolom terisi\n");
    addX(&M, 500, 5, 5);
    printf("   Setelah addX(500, 5, 5): nbaris=%d, nkolom=%d\n", getNBaris(M), getNKolom(M));
    printf("   Expected: nbaris=3, nkolom=3 (masih 3 baris dan 3 kolom terisi)\n");
    printf("   Status: %s\n\n", (getNBaris(M) == 3 && getNKolom(M) == 3) ? "PASSED" : "FAILED");

    printf("6. Test: Tampilkan matriks hasil (smart view)\n");
    printf("   Current matrix (viewMatriks with smart range detection):\n");
    viewMatriks(M);

    printf("\n7. Test: Hapus elemen di (5,5) - mengurangi jumlah baris/kolom terisi\n");
    delX(&M, 500);
    printf("   Setelah delX(500): nbaris=%d, nkolom=%d\n", getNBaris(M), getNKolom(M));
    printf("   Expected: nbaris=2, nkolom=2 (baris 5 dan kolom 5 tidak terisi lagi)\n");
    printf("   Status: %s\n\n", (getNBaris(M) == 2 && getNKolom(M) == 2) ? "PASSED" : "FAILED");

    printf("8. Test: Hapus elemen di (3,5) - mengurangi jumlah kolom terisi\n");
    delX(&M, 200);
    printf("   Setelah delX(200): nbaris=%d, nkolom=%d\n", getNBaris(M), getNKolom(M));
    printf("   Expected: nbaris=2, nkolom=1 (kolom 5 tidak terisi lagi)\n");
    printf("   Status: %s\n\n", (getNBaris(M) == 2 && getNKolom(M) == 1) ? "PASSED" : "FAILED");

    printf("9. Test: Matrix final\n");
    printf("   Final matrix:\n");
    viewMatriks(M);

    printf("\n10. Test: Contoh ekstrem - elemen di (1,1) dan (9,9)\n");
    initMatriks(&M);
    addX(&M, 100, 1, 1);
    addX(&M, 200, 9, 9);
    printf("   Setelah addX(100, 1, 1) dan addX(200, 9, 9):\n");
    printf("   nbaris=%d, nkolom=%d\n", getNBaris(M), getNKolom(M));
    printf("   Expected: nbaris=2, nkolom=2 (2 baris terisi, 2 kolom terisi)\n");
    printf("   Status: %s\n", (getNBaris(M) == 2 && getNKolom(M) == 2) ? "PASSED" : "FAILED");

    printf("   Matrix display (9x9 dengan titik untuk posisi kosong):\n");
    viewMatriks(M);
    printf("   ^ Matrix 9x9 ditampilkan karena rentang dari (1,1) sampai (9,9)\n");

    printf("\n11. Test: Contoh sparse matrix\n");
    initMatriks(&M);
    addX(&M, 10, 2, 3);
    addX(&M, 20, 5, 1);
    addX(&M, 30, 5, 7);
    printf("   Setelah addX di (2,3), (5,1), (5,7):\n");
    printf("   nbaris=%d, nkolom=%d\n", getNBaris(M), getNKolom(M));
    printf("   Expected: nbaris=2, nkolom=3 (2 baris terisi: 2,5; 3 kolom terisi: 1,3,7)\n");
    printf("   Status: %s\n", (getNBaris(M) == 2 && getNKolom(M) == 3) ? "PASSED" : "FAILED");

    printf("   Matrix display (4x7 dengan banyak titik untuk posisi kosong):\n");
    viewMatriks(M);
    printf("   ^ Matrix 4x7 ditampilkan (baris 2-5, kolom 1-7) dengan titik untuk kosong\n");

    printf("\n=== TEST SELESAI ===\n");
    return 0;
}