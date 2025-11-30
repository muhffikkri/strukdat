/* File : main3.c */
/* Deskripsi : Program test ADT list berkait doubly dengan representasi fisik pointer */
/* NIM & Nama : 24060124130069 / Muhammad Fikri */
/* Tanggal : 23 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list3.h"

int main()
{
    // kamus
    List3 L, L1, L2, L3, LCopy;
    infotype V;
    address A;
    int count;
    float freq;

    // algoritma
    printf("\nCreateList & IsEmptyList\n");
    CreateList(&L);
    printf("List L dibuat. IsEmpty? %s\n", IsEmptyList(L) ? "Ya" : "Tidak");

    printf("\nInsertVFirst\n");
    InsertVFirst(&L, 'C');
    InsertVFirst(&L, 'B');
    InsertVFirst(&L, 'A');
    printf("Setelah insert A, B, C di awal:");
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    printf("\nInsertVLast\n");
    InsertVLast(&L, 'D');
    InsertVLast(&L, 'E');
    InsertVLast(&L, 'F');
    printf("Setelah insert D, E, F di akhir:");
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    printf("\nDeleteVFirst\n");
    DeleteVFirst(&L, &V);
    printf("Elemen pertama yang dihapus: %c", V);
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    printf("\nDeleteVLast\n");
    DeleteVLast(&L, &V);
    printf("Elemen terakhir yang dihapus: %c", V);
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    printf("\nSearchX\n");
    SearchX(L, 'C', &A);
    if (A != NIL)
    {
        printf("Elemen 'C' ditemukan!\n");
        printf("Info: %c\n", info(A));
        if (prev(A) != NIL)
        {
            printf("Prev: %c\n", info(prev(A)));
        }
        if (next(A) != NIL)
        {
            printf("Next: %c\n", info(next(A)));
        }
    }
    else
    {
        printf("Elemen 'C' tidak ditemukan\n");
    }

    printf("\nUpdateX\n");
    printf("Sebelum update 'D' -> 'X':");
    PrintList(L);
    UpdateX(&L, 'D', 'X');
    printf("\nSetelah update:");
    PrintList(L);

    printf("\nInsertVAfterX\n");
    printf("Sebelum insert 'Y' setelah 'C':");
    PrintList(L);
    InsertVAfterX(&L, 'C', 'Y');
    printf("\nSetelah insert:");
    PrintList(L);

    printf("\nInsertVBeforeX\n");
    printf("Sebelum insert 'Z' sebelum 'E':");
    PrintList(L);
    InsertVBeforeX(&L, 'E', 'Z');
    printf("\nSetelah insert:");
    PrintList(L);

    printf("\nDeleteX\n");
    printf("Sebelum delete 'Y':");
    PrintList(L);
    DeleteX(&L, 'Y');
    printf("\nSetelah delete:");
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    printf("\nDeleteVAfterX\n");
    printf("List sebelum DeleteVAfterX('C'):");
    PrintList(L);
    DeleteVAfterX(&L, 'C', &V);
    printf("\nElemen setelah 'C' yang dihapus: %c", V);
    PrintList(L);

    printf("\nDeleteVBeforeX\n");
    printf("List sebelum DeleteVBeforeX('E'):");
    PrintList(L);
    DeleteVBeforeX(&L, 'E', &V);
    printf("\nElemen sebelum 'E' yang dihapus: %c", V);
    PrintList(L);

    printf("\nCountX & FrekuensiX\n");
    CreateList(&L2);
    InsertVLast(&L2, 'A');
    InsertVLast(&L2, 'B');
    InsertVLast(&L2, 'A');
    InsertVLast(&L2, 'C');
    InsertVLast(&L2, 'A');
    printf("List L2:");
    PrintList(L2);
    count = CountX(L2, 'A');
    freq = FrekuensiX(L2, 'A');
    printf("\nJumlah 'A': %d", count);
    printf("\nFrekuensi 'A': %.2f\n", freq);

    printf("\nModus & MaxMember\n");
    CreateList(&L3);
    InsertVLast(&L3, 'P');
    InsertVLast(&L3, 'P');
    InsertVLast(&L3, 'Q');
    InsertVLast(&L3, 'P');
    InsertVLast(&L3, 'R');
    InsertVLast(&L3, 'Q');
    printf("List L3:");
    PrintList(L3);
    printf("\nModus: %c", Modus(L3));
    printf("\nMaxMember (frekuensi modus): %d\n", MaxMember(L3));

    printf("\nCountVocal\n");
    CreateList(&L1);
    InsertVLast(&L1, 'a');
    InsertVLast(&L1, 'b');
    InsertVLast(&L1, 'i');
    InsertVLast(&L1, 'c');
    InsertVLast(&L1, 'u');
    InsertVLast(&L1, 'e');
    printf("List L1:");
    PrintList(L1);
    printf("\nJumlah vokal: %d\n", CountVocal(L1));

    printf("\nCountNG\n");
    CreateList(&L1);
    InsertVLast(&L1, 'B');
    InsertVLast(&L1, 'A');
    InsertVLast(&L1, 'N');
    InsertVLast(&L1, 'G');
    InsertVLast(&L1, 'U');
    InsertVLast(&L1, 'N');
    InsertVLast(&L1, 'G');
    printf("List L1:");
    PrintList(L1);
    printf("\nJumlah 'NG': %d\n", CountNG(L1));

    printf("\nSearchAllX\n");
    CreateList(&L1);
    InsertVLast(&L1, 'M');
    InsertVLast(&L1, 'A');
    InsertVLast(&L1, 'N');
    InsertVLast(&L1, 'D');
    InsertVLast(&L1, 'A');
    printf("List L1:");
    PrintList(L1);
    printf("\nPosisi 'A': ");
    SearchAllX(L1, 'A');
    printf("\nPosisi 'J': ");
    SearchAllX(L1, 'J');
    printf("\n");

    printf("\nDeleteAllX\n");
    CreateList(&L1);
    InsertVLast(&L1, 'X');
    InsertVLast(&L1, 'Y');
    InsertVLast(&L1, 'X');
    InsertVLast(&L1, 'Z');
    InsertVLast(&L1, 'X');
    printf("Sebelum DeleteAllX('X'):");
    PrintList(L1);
    DeleteAllX(&L1, 'X');
    printf("\nSetelah DeleteAllX('X'):");
    PrintList(L1);
    printf("\nJumlah elemen: %d\n", NbElm(L1));

    printf("\nInvers\n");
    CreateList(&L1);
    InsertVLast(&L1, '1');
    InsertVLast(&L1, '2');
    InsertVLast(&L1, '3');
    InsertVLast(&L1, '4');
    InsertVLast(&L1, '5');
    printf("List sebelum dibalik:");
    PrintList(L1);
    Invers(&L1);
    printf("\nList setelah dibalik:");
    PrintList(L1);

    printf("\nConcatList\n");
    CreateList(&L1);
    CreateList(&L2);
    InsertVLast(&L1, 'A');
    InsertVLast(&L1, 'B');
    InsertVLast(&L1, 'C');
    InsertVLast(&L2, 'D');
    InsertVLast(&L2, 'E');
    InsertVLast(&L2, 'F');
    printf("List L1:");
    PrintList(L1);
    printf("\nList L2:");
    PrintList(L2);
    List3 LConcat;
    ConcatList(L1, L2, &LConcat);
    printf("\nHasil concat L1 + L2:");
    PrintList(LConcat);

    printf("\nSplitList\n");
    printf("List LConcat sebelum split:");
    PrintList(LConcat);
    printf("\nJumlah elemen: %d", NbElm(LConcat));
    List3 LSplit1, LSplit2;
    SplitList(LConcat, &LSplit1, &LSplit2);
    printf("\nHasil split - List 1:");
    PrintList(LSplit1);
    printf("\nHasil split - List 2:");
    PrintList(LSplit2);

    printf("\nCopyList\n");
    printf("List L3 asli:");
    PrintList(L3);
    CopyList(L3, &LCopy);
    printf("\nList hasil copy:");
    PrintList(LCopy);
    printf("\n\nUbah list copy dengan insert 'S':");
    InsertVLast(&LCopy, 'S');
    printf("\nList copy setelah diubah:");
    PrintList(LCopy);
    printf("\nList L3 asli (tidak berubah):");
    PrintList(L3);

    printf("\nEdge Cases - List Kosong\n");
    List3 LKosong;
    CreateList(&LKosong);
    printf("Delete dari list kosong:");
    DeleteVFirst(&LKosong, &V);
    printf("\nDeleteVFirst, V='%c' (harusnya '#')", V);
    DeleteVLast(&LKosong, &V);
    printf("\nDeleteVLast, V='%c' (harusnya '#')", V);
    printf("\nNbElm: %d", NbElm(LKosong));
    printf("\nModus: '%c' (harusnya '#')\n", Modus(LKosong));

    printf("\nEdge Cases - Single Element\n");
    CreateList(&LKosong);
    InsertVLast(&LKosong, 'Z');
    printf("List dengan 1 elemen:");
    PrintList(LKosong);
    DeleteVFirst(&LKosong, &V);
    printf("\nSetelah delete: IsEmpty? %s, V=%c\n",
           IsEmptyList(LKosong) ? "Ya" : "Tidak", V);

    return 0;
}