/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama 24060124130069 / Muhammad Fikri: */
/* Tanggal : 6 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

int main()
{
    // kamus
    List1 L, L1, L2, L3;
    List1 LConcat;
    List1 LSplit1, LSplit2;
    List1 LCopy;
    List1 LKosong;
    infotype V;
    address A;
    int count;
    float freq;

    // algoritma
    printf("CreateList & IsEmptyList");
    CreateList(&L);
    printf("List L dibuat. IsEmpty? %s\n", IsEmptyList(L) ? "Ya" : "Tidak");

    printf("InsertVFirst");
    InsertVFirst(&L, 'A');
    InsertVFirst(&L, 'B');
    InsertVFirst(&L, 'C');
    printf("Setelah insert C, B, A di awal:");
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    printf("InsertVLast");
    InsertVLast(&L, 'D');
    InsertVLast(&L, 'E');
    InsertVLast(&L, 'A');
    printf("Setelah insert D, E, A di akhir:");
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    printf("DeleteVFirst");
    DeleteVFirst(&L, &V);
    printf("Elemen pertama yang dihapus: %c", V);
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    printf("DeleteVLast");
    DeleteVLast(&L, &V);
    printf("Elemen terakhir yang dihapus: %c", V);
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    printf("SearchX");
    SearchX(L, 'B', &A);
    if (A != NIL)
    {
        printf("Elemen 'B' ditemukan di alamat: %p\n", A);
    }
    else
    {
        printf("Elemen 'B' tidak ditemukan\n");
    }

    SearchX(L, 'Z', &A);
    printf("Elemen 'Z' %s\n", A == NIL ? "tidak ditemukan" : "ditemukan");

    printf("UpdateX");
    printf("Sebelum update 'A' -> 'X':");
    PrintList(L);
    UpdateX(&L, 'A', 'X');
    printf("\nSetelah update:");
    PrintList(L);

    printf("\n");
    printf("CountX & FrekuensiX");
    InsertVLast(&L, 'E');
    InsertVLast(&L, 'E');
    printf("List setelah tambah 2 'E':");
    PrintList(L);
    count = CountX(L, 'E');
    freq = FrekuensiX(L, 'E');
    printf("\nJumlah 'E': %d", count);
    printf("\nFrekuensi 'E': %.2f\n", freq);

    printf("SearchAllX");
    SearchAllX(L, 'E');
    printf("\n");

    printf("UpdateAllX");
    printf("Sebelum update semua 'E' -> 'F':");
    PrintList(L);
    UpdateAllX(&L, 'E', 'F');
    printf("\nSetelah update:");
    PrintList(L);

    printf("\n");
    printf("InsertVAfter");
    printf("Sebelum insert 'Y' setelah 'B':");
    PrintList(L);
    InsertVAfter(&L, 'B', 'Y');
    printf("\nSetelah insert:");
    PrintList(L);

    printf("\n");
    printf("CountVocal");
    CreateList(&L2);
    InsertVLast(&L2, 'a');
    InsertVLast(&L2, 'b');
    InsertVLast(&L2, 'i');
    InsertVLast(&L2, 'c');
    InsertVLast(&L2, 'u');
    printf("List L2:");
    PrintList(L2);
    printf("\nJumlah vokal: %d\n", CountVocal(L2));

    printf("Modus & NbModus");
    CreateList(&L3);
    InsertVLast(&L3, 'p');
    InsertVLast(&L3, 'p');
    InsertVLast(&L3, 'q');
    InsertVLast(&L3, 'p');
    InsertVLast(&L3, 'r');
    InsertVLast(&L3, 'q');
    printf("List L3:");
    PrintList(L3);
    printf("\nModus: %c", Modus(L3));
    printf("\nNbModus (frekuensi modus): %d\n", NbModus(L3));

    printf("Invers");
    printf("List L sebelum dibalik:");
    PrintList(L);
    Invers(&L);
    printf("\nList L setelah dibalik:");
    PrintList(L);

    printf("\n");
    printf("ConcatList");
    printf("List L:");
    PrintList(L);
    printf("\nList L2:");
    PrintList(L2);
    ConcatList(L, L2, &LConcat);
    printf("\nHasil concat L + L2:");
    PrintList(LConcat);

    printf("\n");
    printf("SplitList");
    printf("List LConcat sebelum split:");
    PrintList(LConcat);
    printf("\nJumlah elemen: %d", NbElm(LConcat));
    SplitList(LConcat, &LSplit1, &LSplit2);
    printf("\nHasil split - List 1:");
    PrintList(LSplit1);
    printf("\nHasil split - List 2:");
    PrintList(LSplit2);

    printf("\n");
    printf("CopyList\n");
    printf("List L3 asli:");
    PrintList(L3);
    CopyList(L3, &LCopy);
    printf("\nList hasil copy:");
    PrintList(LCopy);
    printf("\n\nUbah list copy dengan insert 's':");
    InsertVLast(&LCopy, 's');
    printf("\nList copy setelah diubah:");
    PrintList(LCopy);
    printf("\nList L3 asli (tidak berubah):");
    PrintList(L3);

    printf("\n");
    printf("Delete dari list kosong\n");
    CreateList(&LKosong);
    DeleteVFirst(&LKosong, &V);
    printf("Delete dari list kosong, nilai V: %c (harusnya '#')\n", V);
    DeleteVLast(&LKosong, &V);
    printf("Delete last dari list kosong, nilai V: %c (harusnya '#')\n", V);

    printf("Delete hingga list kosong");
    CreateList(&LKosong);
    InsertVLast(&LKosong, 'Z');
    printf("List dengan 1 elemen:");
    PrintList(LKosong);
    DeleteVFirst(&LKosong, &V);
    printf("\nSetelah delete: IsEmpty? %s, V=%c\n", IsEmptyList(LKosong) ? "Ya" : "Tidak", V);

    return 0;
}
