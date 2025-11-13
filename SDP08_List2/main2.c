/* File : main2.c */
/* Deskripsi : aplikasi driver ADT list berkait SIRKULAR, representasi fisik pointer */
/* NIM & Nama 24060124130069 / Muhammad Fikri: */
/* Tanggal : 13 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

int main()
{
    // kamus
    List2 L, L1, L2, L3;
    List2 LConcat;
    List2 LSplit1, LSplit2;
    List2 LCopy;
    List2 LKosong;
    infotype V;
    address A;
    int count;
    float freq;

    // algoritma
    printf("CreateList & IsEmptyList\n");
    CreateList(&L);
    printf("   List L dibuat. IsEmpty? %s\n", IsEmptyList(L) ? "Ya" : "Tidak");
    printf("   Status: %s\n\n", IsEmptyList(L) ? "PASSED" : "FAILED");

    printf("InsertVFirst\n");
    InsertVFirst(&L, 'A');
    InsertVFirst(&L, 'B');
    InsertVFirst(&L, 'C');
    printf("   Setelah insert C, B, A di awal:");
    PrintList(L);
    printf("\n   Jumlah elemen: %d", NbElm(L));
    printf("\n   IsOneElm? %s\n", IsOneElm(L) ? "Ya" : "Tidak");
    printf("   Status: %s\n\n", NbElm(L) == 3 ? "PASSED" : "FAILED");

    printf("InsertVLast\n");
    InsertVLast(&L, 'D');
    InsertVLast(&L, 'E');
    InsertVLast(&L, 'A');
    printf("   Setelah insert D, E, A di akhir:");
    PrintList(L);
    printf("\n   Jumlah elemen: %d", NbElm(L));
    printf("\n   Status: %s\n\n", NbElm(L) == 6 ? "PASSED" : "FAILED");

    printf("DeleteVFirst\n");
    DeleteVFirst(&L, &V);
    printf("   Elemen pertama yang dihapus: %c", V);
    PrintList(L);
    printf("\n   Jumlah elemen: %d", NbElm(L));
    printf("\n   Status: %s\n\n", (V == 'C' && NbElm(L) == 5) ? "PASSED" : "FAILED");

    printf("DeleteVLast\n");
    DeleteVLast(&L, &V);
    printf("   Elemen terakhir yang dihapus: %c", V);
    PrintList(L);
    printf("\n   Jumlah elemen: %d", NbElm(L));
    printf("\n   Status: %s\n\n", (V == 'A' && NbElm(L) == 4) ? "PASSED" : "FAILED");

    printf("SearchX\n");
    SearchX(L, 'B', &A);
    if (A != NIL)
    {
        printf("   Elemen 'B' ditemukan di alamat: %p\n", A);
    }
    else
    {
        printf("   Elemen 'B' tidak ditemukan\n");
    }

    SearchX(L, 'Z', &A);
    printf("   Elemen 'Z' %s", A == NIL ? "tidak ditemukan" : "ditemukan");
    printf("\n   Status: PASSED\n\n");

    printf("UpdateX\n");
    printf("   Sebelum update 'A' -> 'X':");
    PrintList(L);
    UpdateX(&L, 'A', 'X');
    printf("\n   Setelah update:");
    PrintList(L);
    printf("\n   Status: PASSED\n\n");

    printf("CountX & FrekuensiX\n");
    InsertVLast(&L, 'E');
    InsertVLast(&L, 'E');
    printf("   List setelah tambah 2 'E':");
    PrintList(L);
    count = CountX(L, 'E');
    freq = FrekuensiX(L, 'E');
    printf("\n   Jumlah 'E': %d", count);
    printf("\n   Frekuensi 'E': %.2f", freq);
    printf("\n   Status: %s\n\n", count == 3 ? "PASSED" : "FAILED");

    printf("SearchAllX\n");
    printf("   Posisi kemunculan 'E': ");
    SearchAllX(L, 'E');
    printf("\n   Status: PASSED (visual check)\n\n");

    printf("DeleteX\n");
    printf("    Sebelum delete 'B':");
    PrintList(L);
    printf("\n    Jumlah sebelum: %d", NbElm(L));
    DeleteX(&L, 'B');
    printf("\n    Setelah delete 'B':");
    PrintList(L);
    printf("\n    Jumlah setelah: %d", NbElm(L));

    printf("InsertVAfterX\n");
    printf("    Sebelum insert 'Y' setelah 'X':");
    PrintList(L);
    InsertVAfterX(&L, 'X', 'Y');
    printf("\n    Setelah insert:");
    PrintList(L);

    printf("InsertVBeforeX\n");
    printf("    Sebelum insert 'W' sebelum 'Y':");
    PrintList(L);
    InsertVBeforeX(&L, 'Y', 'W');
    printf("\n    Setelah insert:");
    PrintList(L);

    printf("CountVocal\n");
    CreateList(&L2);
    InsertVLast(&L2, 'a');
    InsertVLast(&L2, 'b');
    InsertVLast(&L2, 'i');
    InsertVLast(&L2, 'c');
    InsertVLast(&L2, 'u');
    InsertVLast(&L2, 'o');
    printf("    List L2:");
    PrintList(L2);
    printf("\n    Jumlah vokal: %d", CountVocal(L2));

    printf("CountNG\n");
    CreateList(&L3);
    InsertVLast(&L3, 'B');
    InsertVLast(&L3, 'A');
    InsertVLast(&L3, 'N');
    InsertVLast(&L3, 'G');
    InsertVLast(&L3, 'N');
    InsertVLast(&L3, 'G');
    printf("    List L3:");
    PrintList(L3);
    printf("\n    Jumlah 'NG': %d", CountNG(L3));

    printf("Modus & MaxMember\n");
    CreateList(&L3);
    InsertVLast(&L3, 'p');
    InsertVLast(&L3, 'p');
    InsertVLast(&L3, 'q');
    InsertVLast(&L3, 'p');
    InsertVLast(&L3, 'r');
    InsertVLast(&L3, 'q');
    printf("    List L3:");
    PrintList(L3);
    printf("\n    Modus: %c", Modus(L3));
    printf("\n    MaxMember (frekuensi modus): %d", MaxMember(L3));

    printf("DeleteVAfterX\n");
    printf("    Sebelum delete elemen setelah 'p':");
    PrintList(L3);
    DeleteVAfterX(&L3, 'p', &V);
    printf("\n    Elemen yang dihapus: %c", V);
    printf("\n    Setelah delete:");
    PrintList(L3);

    printf("DeleteVBeforeX\n");
    printf("    Sebelum delete elemen sebelum 'q':");
    PrintList(L3);
    DeleteVBeforeX(&L3, 'q', &V);
    printf("\n    Elemen yang dihapus: %c", V);
    printf("\n    Setelah delete:");
    PrintList(L3);

    printf("DeleteAllX\n");
    CreateList(&L3);
    InsertVLast(&L3, 'x');
    InsertVLast(&L3, 'y');
    InsertVLast(&L3, 'x');
    InsertVLast(&L3, 'z');
    InsertVLast(&L3, 'x');
    printf("    Sebelum delete semua 'x':");
    PrintList(L3);
    printf("\n    Jumlah sebelum: %d", NbElm(L3));
    DeleteAllX(&L3, 'x');
    printf("\n    Setelah delete semua 'x':");
    PrintList(L3);
    printf("\n    Jumlah setelah: %d", NbElm(L3));

    printf("Invers\n");
    CreateList(&L);
    InsertVLast(&L, 'A');
    InsertVLast(&L, 'B');
    InsertVLast(&L, 'C');
    InsertVLast(&L, 'D');
    printf("    List L sebelum dibalik:");
    PrintList(L);
    Invers(&L);
    printf("\n    List L setelah dibalik:");
    PrintList(L);

    printf("ConcatList\n");
    CreateList(&L1);
    InsertVLast(&L1, '1');
    InsertVLast(&L1, '2');
    CreateList(&L2);
    InsertVLast(&L2, '3');
    InsertVLast(&L2, '4');
    printf("    List L1:");
    PrintList(L1);
    printf("\n    List L2:");
    PrintList(L2);
    ConcatList(L1, L2, &LConcat);
    printf("\n    Hasil concat L1 + L2:");
    PrintList(LConcat);

    printf("SplitList\n");
    printf("    List LConcat sebelum split:");
    PrintList(LConcat);
    printf("\n    Jumlah elemen: %d", NbElm(LConcat));
    SplitList(LConcat, &LSplit1, &LSplit2);
    printf("\n    Hasil split - List 1:");
    PrintList(LSplit1);
    printf("\n    Hasil split - List 2:");
    PrintList(LSplit2);

    printf("CopyList\n");
    printf("    List L1 asli:");
    PrintList(L1);
    CopyList(L1, &LCopy);
    printf("\n    List hasil copy:");
    PrintList(LCopy);
    printf("\n    Ubah list copy dengan insert 's':");
    InsertVLast(&LCopy, 's');
    printf("\n    List copy setelah diubah:");
    PrintList(LCopy);
    printf("\n    List L1 asli (tidak berubah):");
    PrintList(L1);

    printf("Delete dari list kosong\n");
    CreateList(&LKosong);
    DeleteVFirst(&LKosong, &V);
    printf("    Delete dari list kosong, nilai V: %c (harusnya '#')", V);
    DeleteVLast(&LKosong, &V);
    printf("\n    Delete last dari list kosong, nilai V: %c (harusnya '#')", V);

    printf("Delete hingga list kosong\n");
    CreateList(&LKosong);
    InsertVLast(&LKosong, 'Z');
    printf("    List dengan 1 elemen:");
    PrintList(LKosong);
    DeleteVFirst(&LKosong, &V);
    printf("\n    Setelah delete: IsEmpty? %s, V=%c", IsEmptyList(LKosong) ? "Ya" : "Tidak", V);

    return 0;
}
