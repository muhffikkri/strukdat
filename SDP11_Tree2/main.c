/* File : main.c */
/* Deskripsi : Program test ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124130069 / Muhammad Fikri */
/* Tanggal : 4 Desember 2025 */

#include <stdio.h>
#include "pohon2.h"

int main()
{
    bintree P, P2, P3, BST;
    infotype X;

    // Test PrintTreeInden
    printf("Test PrintTreeInden\n");
    P = AlokasiTree('A');
    left(P) = AlokasiTree('B');
    right(P) = AlokasiTree('C');
    left(left(P)) = AlokasiTree('D');
    right(left(P)) = AlokasiTree('E');
    printf("Tree structure:\n");
    PrintTreeInden(P, 0);
    printf("\n");

    // Test PrintLevel
    printf("Test PrintLevel2\n");
    printf("Level 0: ");
    PrintLevel2(P, 0);
    printf("\n");
    printf("Level 1: ");
    PrintLevel2(P, 1);
    printf("\n");
    printf("Level 2: ");
    PrintLevel2(P, 2);
    printf("\n\n");

    // Test UpdateAllX
    printf("Test UpdateAllX\n");
    right(right(P)) = AlokasiTree('D');
    printf("PrintPrefix sebelum update: ");
    PrintPrefix(P);
    printf("\n");
    printf("UpdateAllX(P, 'D', 'Z')\n");
    UpdateAllX(&P, 'D', 'Z');
    printf("PrintPrefix setelah update: ");
    PrintPrefix(P);
    printf("\n\n");

    // Test AddDaunTerkiri
    printf("Test AddDaunTerkiri\n");
    P2 = AlokasiTree('A');
    left(P2) = AlokasiTree('B');
    right(P2) = AlokasiTree('C');
    printf("Tree sebelum AddDaunTerkiri:\n");
    PrintTreeInden(P2, 0);
    printf("\nAddDaunTerkiri(P2, 'X')\n");
    AddDaunTerkiri(P2, 'X');
    printf("Tree setelah AddDaunTerkiri:\n");
    PrintTreeInden(P2, 0);
    printf("\n");

    // Test AddDaun
    printf("Test AddDaun\n");
    P3 = AlokasiTree('A');
    left(P3) = AlokasiTree('B');
    right(P3) = AlokasiTree('C');
    printf("Tree sebelum AddDaun:\n");
    PrintTreeInden(P3, 0);
    printf("\nAddDaun(P3, 'B', 'X', true) - tambah X sebagai anak kiri B\n");
    AddDaun(P3, 'B', 'X', true);
    printf("AddDaun(P3, 'C', 'Y', false) - tambah Y sebagai anak kanan C\n");
    AddDaun(P3, 'C', 'Y', false);
    printf("Tree setelah AddDaun:\n");
    PrintTreeInden(P3, 0);
    printf("\n");

    // Test InsertX
    printf("Test InsertX\n");
    bintree P4 = NIL;
    printf("InsertX ke tree kosong\n");
    InsertX(&P4, 'A');
    printf("InsertX(&P4, 'B')\n");
    InsertX(&P4, 'B');
    printf("InsertX(&P4, 'C')\n");
    InsertX(&P4, 'C');
    printf("Tree setelah InsertX:\n");
    PrintTreeInden(P4, 0);
    printf("\n");

    // Test DelDaunTerkiri
    printf("Test DelDaunTerkiri\n");
    bintree P5 = AlokasiTree('A');
    left(P5) = AlokasiTree('B');
    right(P5) = AlokasiTree('C');
    left(left(P5)) = AlokasiTree('D');
    printf("Tree sebelum DelDaunTerkiri:\n");
    PrintTreeInden(P5, 0);
    printf("\n");
    DelDaunTerkiri(&P5, &X);
    printf("DelDaunTerkiri menghapus: %c\n", X);
    printf("Tree setelah DelDaunTerkiri:\n");
    PrintTreeInden(P5, 0);
    printf("\n");

    // Test DelDaun
    printf("Test DelDaun\n");
    bintree P6 = AlokasiTree('A');
    left(P6) = AlokasiTree('B');
    right(P6) = AlokasiTree('C');
    left(left(P6)) = AlokasiTree('D');
    right(left(P6)) = AlokasiTree('E');
    printf("Tree sebelum DelDaun:\n");
    PrintTreeInden(P6, 0);
    printf("\nDelDaun(P6, 'D')\n");
    DelDaun(&P6, 'D');
    printf("Tree setelah DelDaun:\n");
    PrintTreeInden(P6, 0);
    printf("\n");

    // Test DeleteX
    printf("Test DeleteX\n");
    bintree P7 = AlokasiTree('A');
    left(P7) = AlokasiTree('B');
    right(P7) = AlokasiTree('C');
    left(left(P7)) = AlokasiTree('D');
    right(left(P7)) = AlokasiTree('E');
    printf("Tree sebelum DeleteX:\n");
    PrintTreeInden(P7, 0);
    printf("\nDeleteX(&P7, 'B') - hapus node internal\n");
    DeleteX(&P7, 'B');
    printf("Tree setelah DeleteX:\n");
    PrintTreeInden(P7, 0);
    printf("\n");

    // Test IsBalanceTree
    printf("Test IsBalanceTree\n");
    bintree P8 = AlokasiTree('A');
    left(P8) = AlokasiTree('B');
    right(P8) = AlokasiTree('C');
    printf("Tree seimbang:\n");
    PrintTreeInden(P8, 0);
    printf("IsBalanceTree: %s\n\n", IsBalanceTree(P8) ? "true" : "false");

    bintree P9 = AlokasiTree('A');
    left(P9) = AlokasiTree('B');
    left(left(P9)) = AlokasiTree('D');
    left(left(left(P9))) = AlokasiTree('E');
    printf("Tree tidak seimbang:\n");
    PrintTreeInden(P9, 0);
    printf("IsBalanceTree: %s\n\n", IsBalanceTree(P9) ? "true" : "false");

    // Test maxTree dan minTree
    printf("Test maxTree dan minTree\n");
    bintree P10 = AlokasiTree('M');
    left(P10) = AlokasiTree('D');
    right(P10) = AlokasiTree('Z');
    left(left(P10)) = AlokasiTree('A');
    right(left(P10)) = AlokasiTree('G');
    printf("Tree:\n");
    PrintTreeInden(P10, 0);
    printf("\nmaxTree(P10): %c\n", maxTree(P10));
    printf("minTree(P10): %c\n\n", minTree(P10));

    // Test Binary Search Tree Operations
    printf("Test Binary Search Tree\n");
    BST = NIL;
    printf("Buat BST dengan InsSearch\n");
    BST = InsSearch(BST, 'M');
    BST = InsSearch(BST, 'D');
    BST = InsSearch(BST, 'S');
    BST = InsSearch(BST, 'A');
    BST = InsSearch(BST, 'G');
    BST = InsSearch(BST, 'P');
    BST = InsSearch(BST, 'Z');
    printf("BST structure:\n");
    PrintTreeInden(BST, 0);
    printf("\n");

    // Test BSearch
    printf("Test BSearch\n");
    printf("BSearch(BST, 'G'): %s\n", BSearch(BST, 'G') ? "true" : "false");
    printf("BSearch(BST, 'P'): %s\n", BSearch(BST, 'P') ? "true" : "false");
    printf("BSearch(BST, 'X'): %s\n", BSearch(BST, 'X') ? "true" : "false");
    printf("\n");

    // Test DelBtree
    printf("Test DelBtree\n");
    printf("BST sebelum delete:\n");
    PrintTreeInden(BST, 0);
    printf("\nDelBtree(&BST, 'D') - hapus node dengan 2 anak\n");
    DelBtree(&BST, 'D');
    printf("BST setelah delete:\n");
    PrintTreeInden(BST, 0);
    printf("\n");

    printf("DelBtree(&BST, 'A') - hapus daun\n");
    DelBtree(&BST, 'A');
    printf("BST setelah delete:\n");
    PrintTreeInden(BST, 0);
    printf("\n");

    // Test tree kosong
    printf("Test Kondisi Tree Kosong\n");
    bintree P_empty = NIL;
    printf("IsEmptyTree(NIL): %s\n", IsEmptyTree(P_empty) ? "true" : "false");
    printf("maxTree(NIL): %c\n", maxTree(P_empty));
    printf("minTree(NIL): %c\n", minTree(P_empty));
    printf("BSearch(NIL, 'A'): %s\n", BSearch(P_empty, 'A') ? "true" : "false");
    printf("\n");

    // Test single node
    printf("Test Tree Single Node\n");
    bintree P_single = AlokasiTree('X');
    printf("Tree:\n");
    PrintTreeInden(P_single, 0);
    printf("\nmaxTree: %c\n", maxTree(P_single));
    printf("minTree: %c\n", minTree(P_single));
    printf("IsBalanceTree: %s\n", IsBalanceTree(P_single) ? "true" : "false");
    printf("\n");

    return 0;
}