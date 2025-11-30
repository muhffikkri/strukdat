/* File : main.c */
/* Deskripsi : Program test ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124130069 / Muhammad Fikri */
/* Tanggal : 27 November 2025 */

#include <stdio.h>
#include "pohon1.h"

int main()
{
     bintree P, P2, P3;
     infotype X;

     // Test 1: Tree kosong
     printf("Test Tree Kosong\n");
     P = NIL;
     printf("IsEmptyTree(NIL): %s\n", IsEmptyTree(P) ? "true" : "false");
     printf("NbElm(NIL): %d\n", NbElm(P));
     printf("NbDaun(NIL): %d\n", NbDaun(P));
     printf("Tinggi(NIL): %d\n", Tinggi(P));
     printf("\n");

     // Test 2: Buat tree sederhana
     //     A
     //    / \
    //   B   C
     printf("Test Buat Tree Sederhana (A dengan anak B dan C)\n");
     P = AlokasiTree('A');
     left(P) = AlokasiTree('B');
     right(P) = AlokasiTree('C');
     printf("PrintPrefix: ");
     PrintPrefix(P);
     printf("\nPrintPrefixRingkas: ");
     PrintPrefixRingkas(P);
     printf("\n");
     printf("NbElm: %d\n", NbElm(P));
     printf("NbDaun: %d\n", NbDaun(P));
     printf("Tinggi: %d\n", Tinggi(P));
     printf("\n");

     // Test 3: Predikat
     printf("Test Predikat\n");
     printf("IsEmptyTree(P): %s\n", IsEmptyTree(P) ? "true" : "false");
     printf("IsDaun(P): %s\n", IsDaun(P) ? "true" : "false");
     printf("IsDaun(left(P)): %s\n", IsDaun(left(P)) ? "true" : "false");
     printf("IsBiner(P): %s\n", IsBiner(P) ? "true" : "false");
     printf("IsUnerLeft(P): %s\n", IsUnerLeft(P) ? "true" : "false");
     printf("IsUnerRight(P): %s\n", IsUnerRight(P) ? "true" : "false");
     printf("\n");

     // Test 4: Tree lebih kompleks
     //       A
     //      / \
    //     B   C
     //    / \
    //   D   E
     printf("Test Tree Kompleks\n");
     left(left(P)) = AlokasiTree('D');
     right(left(P)) = AlokasiTree('E');
     printf("PrintPrefix: ");
     PrintPrefix(P);
     printf("\nPrintPrefixRingkas: ");
     PrintPrefixRingkas(P);
     printf("\n");
     printf("NbElm: %d\n", NbElm(P));
     printf("NbDaun: %d\n", NbDaun(P));
     printf("Tinggi: %d\n", Tinggi(P));
     printf("\n");

     // Test 5: SearchX
     printf("Test SearchX\n");
     printf("SearchX(P, 'A'): %s\n", SearchX(P, 'A') ? "true" : "false");
     printf("SearchX(P, 'D'): %s\n", SearchX(P, 'D') ? "true" : "false");
     printf("SearchX(P, 'Z'): %s\n", SearchX(P, 'Z') ? "true" : "false");
     printf("\n");

     // Test 6: UpdateX
     printf("Test UpdateX\n");
     printf("UpdateX(P, 'D', 'X')\n");
     UpdateX(&P, 'D', 'X');
     printf("PrintPrefix setelah update: ");
     PrintPrefix(P);
     printf("\n\n");

     // Test 7: CountX
     printf("Test CountX\n");
     printf("CountX(P, 'A'): %d\n", CountX(P, 'A'));
     printf("CountX(P, 'X'): %d\n", CountX(P, 'X'));
     printf("CountX(P, 'Z'): %d\n", CountX(P, 'Z'));
     printf("\n");

     // Test 8: Skew tree
     printf("Test Skew Tree\n");
     P2 = AlokasiTree('A');
     left(P2) = AlokasiTree('B');
     left(left(P2)) = AlokasiTree('C');
     left(left(left(P2))) = AlokasiTree('D');
     printf("PrintPrefix (skew left): ");
     PrintPrefix(P2);
     printf("\n");
     printf("IsSkewLeft: %s\n", IsSkewLeft(P2) ? "true" : "false");
     printf("IsSkewRight: %s\n", IsSkewRight(P2) ? "true" : "false");
     printf("Tinggi: %d\n", Tinggi(P2));
     printf("\n");

     P3 = AlokasiTree('A');
     right(P3) = AlokasiTree('B');
     right(right(P3)) = AlokasiTree('C');
     right(right(right(P3))) = AlokasiTree('D');
     printf("PrintPrefix (skew right): ");
     PrintPrefix(P3);
     printf("\n");
     printf("IsSkewLeft: %s\n", IsSkewLeft(P3) ? "true" : "false");
     printf("IsSkewRight: %s\n", IsSkewRight(P3) ? "true" : "false");
     printf("Tinggi: %d\n", Tinggi(P3));
     printf("\n");

     // Test 9: LevelX
     printf("Test LevelX\n");
     printf("LevelX(P, 'A'): %d\n", LevelX(P, 'A'));
     printf("LevelX(P, 'B'): %d\n", LevelX(P, 'B'));
     printf("LevelX(P, 'X'): %d\n", LevelX(P, 'X'));
     printf("LevelX(P, 'E'): %d\n", LevelX(P, 'E'));
     printf("LevelX(P, 'Z'): %d\n", LevelX(P, 'Z'));
     printf("\n");

     // Test 10: CountLevel
     printf("Test CountLevel\n");
     printf("CountLevel(P, 1): %d\n", CountLevel(P, 1));
     printf("CountLevel(P, 2): %d\n", CountLevel(P, 2));
     printf("CountLevel(P, 3): %d\n", CountLevel(P, 3));
     printf("CountLevel(P, 4): %d\n", CountLevel(P, 4));
     printf("\n");

     // Test 11: PrintLevel
     printf("Test PrintLevel\n");
     printf("PrintLevel(P, 0): ");
     PrintLevel(P, 0);
     printf("\n");
     printf("PrintLevel(P, 1): ");
     PrintLevel(P, 1);
     printf("\n");
     printf("PrintLevel(P, 2): ");
     PrintLevel(P, 2);
     printf("\n\n");

     // Test 12: GetDaunTerkiri
     printf("Test GetDaunTerkiri\n");
     printf("GetDaunTerkiri(P): %c\n", GetDaunTerkiri(P));
     printf("GetDaunTerkiri(P3): %c\n", GetDaunTerkiri(P3));
     printf("GetDaunTerkiri(NIL): %c\n", GetDaunTerkiri(NIL));
     printf("\n");

     // Test 13: Tree dengan vocal dan consonant
     //       a
     //      / \
    //     b   e
     //    / \   \
    //   c   d   i
     printf("Test Vocal dan Consonant\n");
     bintree P4 = AlokasiTree('a');
     left(P4) = AlokasiTree('b');
     right(P4) = AlokasiTree('e');
     left(left(P4)) = AlokasiTree('c');
     right(left(P4)) = AlokasiTree('d');
     right(right(P4)) = AlokasiTree('i');

     printf("PrintPrefix: ");
     PrintPrefix(P4);
     printf("\n");
     printf("CountVocal: %d\n", CountVocal(P4));
     printf("CountConsonant: %d\n", CountConsonant(P4));
     printf("PrintVocal: ");
     PrintVocal(P4);
     printf("\n");
     printf("PrintConsonant: ");
     PrintConsonant(P4);
     printf("\n\n");

     // Test 14: FrekuensiX
     printf("Test FrekuensiX\n");
     bintree P5 = AlokasiTree('A');
     left(P5) = AlokasiTree('B');
     right(P5) = AlokasiTree('A');
     left(left(P5)) = AlokasiTree('A');
     right(left(P5)) = AlokasiTree('C');

     printf("PrintPrefix: ");
     PrintPrefix(P5);
     printf("\n");
     printf("FrekuensiX(P5, 'A'): %.2f\n", FrekuensiX(P5, 'A'));
     printf("FrekuensiX(P5, 'B'): %.2f\n", FrekuensiX(P5, 'B'));
     printf("FrekuensiX(P5, 'C'): %.2f\n", FrekuensiX(P5, 'C'));
     printf("FrekuensiX(P5, 'Z'): %.2f\n", FrekuensiX(P5, 'Z'));
     printf("\n");

     // Test 15: Modus
     printf("Test Modus\n");
     printf("Modus(P5): %c\n", Modus(P5));
     printf("Modus(P): %c\n", Modus(P));
     printf("Modus(NIL): %c\n", Modus(NIL));
     printf("\n");

     // Test 16: Tree dengan satu node saja
     printf("Test Tree Single Node\n");
     bintree P6 = AlokasiTree('Z');
     printf("PrintPrefix: ");
     PrintPrefix(P6);
     printf("\n");
     printf("PrintPrefixRingkas: ");
     PrintPrefixRingkas(P6);
     printf("\n");
     printf("IsDaun: %s\n", IsDaun(P6) ? "true" : "false");
     printf("NbElm: %d\n", NbElm(P6));
     printf("NbDaun: %d\n", NbDaun(P6));
     printf("Tinggi: %d\n", Tinggi(P6));
     printf("GetDaunTerkiri: %c\n", GetDaunTerkiri(P6));
     printf("\n");

     // Test 17: IsUnerLeft dan IsUnerRight
     printf("Test IsUnerLeft dan IsUnerRight\n");
     bintree P7 = AlokasiTree('A');
     left(P7) = AlokasiTree('B');
     printf("Tree dengan hanya anak kiri:\n");
     printf("PrintPrefix: ");
     PrintPrefix(P7);
     printf("\n");
     printf("IsUnerLeft: %s\n", IsUnerLeft(P7) ? "true" : "false");
     printf("IsUnerRight: %s\n", IsUnerRight(P7) ? "true" : "false");
     printf("IsBiner: %s\n", IsBiner(P7) ? "true" : "false");
     printf("\n");

     bintree P8 = AlokasiTree('A');
     right(P8) = AlokasiTree('C');
     printf("Tree dengan hanya anak kanan:\n");
     printf("PrintPrefix: ");
     PrintPrefix(P8);
     printf("\n");
     printf("IsUnerLeft: %s\n", IsUnerLeft(P8) ? "true" : "false");
     printf("IsUnerRight: %s\n", IsUnerRight(P8) ? "true" : "false");
     printf("IsBiner: %s\n", IsBiner(P8) ? "true" : "false");
     printf("\n");

     return 0;
}
