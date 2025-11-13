/* File : List2.h */
/* Deskripsi : ADT list berkait SIRKULAR dengan representasi fisik pointer */
/* NIM & Nama 24060124130069 / Muhammad Fikri: */
/* Tanggal : 13 November 2025 */

#include "stdio.h"
#include "stdlib.h"
#include "list2.h"

/*================== PROTOTYPE =======================*/
/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E)
{
    // kamus lokal
    address P;

    // algoritma
    P = (address)malloc(sizeof(Elm)); // casting
    if (P != NULL)
    {
        info(P) = E;
        next(P) = NIL;
    }
    return P;
}

/* procedure Dealokasi (input/output P:address) */
/* {I.S. P terdefinisi
    F.S. P dikembalikan ke sistem
    Proses: Melakukan pengembalian address P} */
void Dealokasi(address *P)
{
    // kamus lokal

    // algoritma
    if ((*P) != NIL)
    {
        next(*P) = NIL;
        (*P) = NIL;
    }
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong}
   {proses: membuat list kosong}*/
void CreateList(List2 *L)
{
    (*L).First = NIL;
}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> boolean
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList(List2 L)
{
    // kamus lokal

    // algoritma
    return First(L) == NIL;
}

/* function IsOneElm(L:List2) --> boolean
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm(List2 L)
{
    // kamus lokal

    // algoritma
    return next(First(L)) == First(L);
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L)
{
    // kamus lokal
    address P;

    // algoritma
    P = First(L);
    if (!IsEmptyList(L))
    {
        printf("\nElemen = ");
        do
        {
            printf("\t%c", info(P));
            P = next(P);
        } while (P != First(L));
    }
}

/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L)
{
    // kamus lokal
    int i;
    address P;

    // algoritma
    P = First(L);
    i = 0;
    if (!IsEmptyList(L))
    {
        do
        {
            i++;
            P = next(P);
        } while (P != First(L));
    }

    return i;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V)
{
    // kamus lokal
    address P, Last;

    // algoritma
    P = Alokasi(V);
    if (P != NIL)
    {
        if (IsEmptyList(*L))
        {
            First(*L) = P;
            next(P) = P;
        }
        else
        {
            // Cari elemen terakhir
            Last = First(*L);
            while (next(Last) != First(*L))
            {
                Last = next(Last);
            }
            next(P) = First(*L);
            next(Last) = P;
            First(*L) = P;
        }
    }
}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V)
{
    // kamus lokal
    address P;
    address Baru;

    // algoritma
    Baru = Alokasi(V);
    if (Baru != NIL)
    {
        if (IsEmptyList(*L))
        {
            First(*L) = Baru;
            next(Baru) = Baru;
        }
        else
        {
            P = First(*L);
            while (next(P) != First(*L))
            {
                P = next(P);
            }
            next(P) = Baru;
            next(Baru) = First(*L);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V)
{
    // kamus lokal
    address P, Last;

    // algoritma
    if (IsEmptyList(*L))
    {
        (*V) = '#';
    }
    else
    {
        P = First(*L);
        (*V) = info(P);

        if (IsOneElm(*L))
        {
            First(*L) = NIL;
        }
        else
        {
            // Cari elemen terakhir
            Last = First(*L);
            while (next(Last) != First(*L))
            {
                Last = next(Last);
            }
            First(*L) = next(P);
            next(Last) = First(*L);
        }
        Dealokasi(&P);
    }
}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V)
{
    // kamus lokal
    address P;
    address Prec;

    // algoritma
    if (IsEmptyList(*L))
    {
        (*V) = '#';
    }
    else
    {
        if (IsOneElm(*L))
        {
            // hanya 1 elemen
            (*V) = info(First(*L));
            Dealokasi(&First(*L));
            First(*L) = NIL;
        }
        else
        {
            // lebih dari 1 elemen
            P = First(*L);
            Prec = NIL;
            while (next(P) != First(*L))
            {
                Prec = P;
                P = next(P);
            }
            (*V) = info(P);
            next(Prec) = First(*L);
            Dealokasi(&P);
        }
    }
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen bernilai X dihapus, dan didealokasi.
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X)
{
    // kamus lokal
    address P;
    address Prec;

    // algoritma
    if (IsEmptyList(*L))
    {
        return;
    }

    P = First(*L);
    Prec = NIL;

    // Cari elemen X
    do
    {
        if (info(P) == X)
        {
            break;
        }
        Prec = P;
        P = next(P);
    } while (P != First(*L));

    if (info(P) == X)
    {
        // x ditemukan
        if (IsOneElm(*L))
        {
            // hanya 1 elemen
            Dealokasi(&First(*L));
            First(*L) = NIL;
        }
        else if (P == First(*L))
        {
            // x di awal
            address Last = First(*L);
            while (next(Last) != First(*L))
            {
                Last = next(Last);
            }
            First(*L) = next(P);
            next(Last) = First(*L);
            Dealokasi(&P);
        }
        else
        {
            // x di tengah atau akhir
            next(Prec) = next(P);
            Dealokasi(&P);
        }
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A)
{
    // kamus lokal
    address P;

    // algoritma
    (*A) = NIL;

    if (!IsEmptyList(L))
    {
        P = First(L);
        do
        {
            if (info(P) == X)
            {
                (*A) = P;
                return;
            }
            P = next(P);
        } while (P != First(L));
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y)
{
    // kamus lokal
    address P;

    // algoritma
    if (!IsEmptyList(*L))
    {
        P = First(*L);
        do
        {
            if (info(P) == X)
            {
                info(P) = Y;
                return;
            }
            P = next(P);
        } while (P != First(*L));
    }
}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik,
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L)
{
    // kamus lokal
    address P, Prev, Next, First_old, Last;

    // algoritma
    if (!IsEmptyList(*L) && !IsOneElm(*L))
    {
        First_old = First(*L);
        P = First(*L);
        Prev = NIL;

        // Cari elemen terakhir terlebih dahulu
        Last = First(*L);
        while (next(Last) != First(*L))
        {
            Last = next(Last);
        }

        // Balik pointer
        do
        {
            Next = next(P);
            next(P) = Prev;
            Prev = P;
            P = Next;
        } while (P != First(*L));

        // Set first ke elemen terakhir
        First(*L) = Last;
        // Set next dari first_old (sekarang last) ke first baru
        next(First_old) = First(*L);
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X)
{
    // kamus lokal
    address P;
    int i;

    // algoritma
    i = 0;

    if (!IsEmptyList(L))
    {
        P = First(L);
        do
        {
            if (info(P) == X)
                i++;
            P = next(P);
        } while (P != First(L));
    }

    return i;
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X)
{
    // kamus lokal
    address P;
    int freq;
    int total;

    // algoritma
    freq = 0;
    total = 0;

    if (!IsEmptyList(L))
    {
        P = First(L);
        do
        {
            total++;
            if (info(P) == X)
                freq++;
            P = next(P);
        } while (P != First(L));
    }

    if (total == 0)
        return 0.0;
    else
        return (float)freq / (float)total;
}

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L)
{
    // kamus lokal
    address P;
    int i;

    // algoritma
    i = 0;

    if (!IsEmptyList(L))
    {
        P = First(L);
        do
        {
            if (
                info(P) == 'a' || info(P) == 'A' ||
                info(P) == 'i' || info(P) == 'I' ||
                info(P) == 'u' || info(P) == 'U' ||
                info(P) == 'e' || info(P) == 'E' ||
                info(P) == 'o' || info(P) == 'O')
                i++;
            P = next(P);
        } while (P != First(L));
    }

    return i;
}

/*function CountNG(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List2 L)
{
    // kamus lokal
    address P;
    int i;

    // algoritma
    i = 0;

    if (!IsEmptyList(L) && !IsOneElm(L))
    {
        P = First(L);
        do
        {
            if (info(P) == 'N' && info(next(P)) == 'G')
                i++;
            P = next(P);
        } while (P != First(L));
    }

    return i;
}

/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V)
{
    // kamus lokal
    address P;
    address Baru;

    // algoritma
    if (IsEmptyList(*L))
    {
        InsertVFirst(L, V);
    }
    else
    {
        P = First(*L);
        do
        {
            if (info(P) == X)
            {
                Baru = Alokasi(V);
                if (Baru != NIL)
                {
                    next(Baru) = next(P);
                    next(P) = Baru;
                }
                return;
            }
            P = next(P);
        } while (P != First(*L));
    }
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V)
{
    // kamus lokal
    address P, Prec, Baru;

    // algoritma
    if (IsEmptyList(*L))
    {
        InsertVFirst(L, V);
    }
    else
    {
        P = First(*L);
        Prec = NIL;

        // Cari elemen terakhir untuk Prec jika X di First
        address Last = First(*L);
        while (next(Last) != First(*L))
        {
            Last = next(Last);
        }

        do
        {
            if (info(P) == X)
            {
                Baru = Alokasi(V);
                if (Baru != NIL)
                {
                    if (P == First(*L))
                    {
                        // Insert sebelum First
                        next(Baru) = First(*L);
                        next(Last) = Baru;
                        First(*L) = Baru;
                    }
                    else
                    {
                        // Insert sebelum P
                        next(Baru) = P;
                        next(Prec) = Baru;
                    }
                }
                return;
            }
            Prec = P;
            P = next(P);
        } while (P != First(*L));
    }
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V)
{
    // kamus lokal
    address P;
    address Del;

    // algoritma
    (*V) = '#';

    if (!IsEmptyList(*L) && !IsOneElm(*L))
    {
        P = First(*L);
        do
        {
            if (info(P) == X)
            {
                Del = next(P);
                (*V) = info(Del);

                if (Del == First(*L))
                {
                    // Elemen setelah X adalah First
                    address Last = First(*L);
                    while (next(Last) != First(*L))
                    {
                        Last = next(Last);
                    }
                    First(*L) = next(Del);
                    next(P) = First(*L);
                    if (P != Last)
                    {
                        next(Last) = First(*L);
                    }
                }
                else
                {
                    next(P) = next(Del);
                }
                Dealokasi(&Del);
                return;
            }
            P = next(P);
        } while (P != First(*L));
    }
}

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V)
{
    // kamus lokal
    address P, Prec, PrecPrec, Last;

    // algoritma
    (*V) = '#';

    if (!IsEmptyList(*L) && !IsOneElm(*L))
    {
        // Cari elemen terakhir
        Last = First(*L);
        while (next(Last) != First(*L))
        {
            Last = next(Last);
        }

        P = First(*L);
        Prec = Last;
        PrecPrec = NIL;

        do
        {
            if (info(P) == X)
            {
                (*V) = info(Prec);

                if (Prec == First(*L))
                {
                    // Hapus First
                    First(*L) = next(Prec);
                    next(Last) = First(*L);
                    Dealokasi(&Prec);
                }
                else
                {
                    // Hapus Prec
                    next(PrecPrec) = P;
                    Dealokasi(&Prec);
                }
                return;
            }
            PrecPrec = Prec;
            Prec = P;
            P = next(P);
        } while (P != First(*L));
    }
}

/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi.
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X)
{
    // kamus lokal
    address P, Next, Last, Prec;
    boolean found;

    // algoritma
    if (IsEmptyList(*L))
    {
        return;
    }

    do
    {
        found = false;
        P = First(*L);
        Prec = NIL;

        // Cari elemen terakhir
        Last = First(*L);
        while (next(Last) != First(*L))
        {
            Last = next(Last);
        }

        do
        {
            if (info(P) == X)
            {
                found = true;
                Next = next(P);

                if (IsOneElm(*L))
                {
                    Dealokasi(&First(*L));
                    First(*L) = NIL;
                    return;
                }
                else if (P == First(*L))
                {
                    First(*L) = Next;
                    next(Last) = First(*L);
                    Dealokasi(&P);
                }
                else
                {
                    next(Prec) = Next;
                    if (P == Last)
                    {
                        Last = Prec;
                    }
                    Dealokasi(&P);
                }
                break;
            }
            Prec = P;
            P = next(P);
        } while (P != First(*L));

    } while (found && !IsEmptyList(*L));
}

/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X)
{
    // kamus lokal
    int i;
    address P;
    boolean found;

    // algoritma
    found = false;

    if (!IsEmptyList(L))
    {
        P = First(L);
        i = 1;

        do
        {
            if (info(P) == X)
            {
                printf("%d ", i);
                found = true;
            }
            i++;
            P = next(P);
        } while (P != First(L));
    }

    if (!found)
    {
        printf("0");
    }
}

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L)
{
    // kamus lokal
    address P;
    int maxCount;

    // algoritma
    if (IsEmptyList(L))
    {
        return 0;
    }

    P = First(L);
    maxCount = CountX(L, info(P));

    P = next(P);
    while (P != First(L))
    {
        int currentCount = CountX(L, info(P));
        if (maxCount < currentCount)
        {
            maxCount = currentCount;
        }
        P = next(P);
    }

    return maxCount;
}

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L)
{
    // kamus lokal
    address P;
    int maxCount;
    char result;

    // algoritma
    if (IsEmptyList(L))
    {
        return '#';
    }

    P = First(L);
    maxCount = CountX(L, info(P));
    result = info(P);

    P = next(P);
    while (P != First(L))
    {
        int currentCount = CountX(L, info(P));
        if (maxCount < currentCount)
        {
            maxCount = currentCount;
            result = info(P);
        }
        P = next(P);
    }

    return result;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ;
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L)
{
    // kamus lokal
    address P;

    // algoritma
    CreateList(L);

    if (!IsEmptyList(L1))
    {
        P = First(L1);
        do
        {
            InsertVLast(L, info(P));
            P = next(P);
        } while (P != First(L1));
    }

    if (!IsEmptyList(L2))
    {
        P = First(L2);
        do
        {
            InsertVLast(L, info(P));
            P = next(P);
        } while (P != First(L2));
    }
}

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ;
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2)
{
    // kamus lokal
    address P;
    int n;
    int mid;
    int i;

    // algoritma
    CreateList(L1);
    CreateList(L2);

    if (!IsEmptyList(L))
    {
        n = NbElm(L);
        mid = (n + 1) / 2;

        P = First(L);
        i = 1;

        do
        {
            if (i <= mid)
            {
                InsertVLast(L1, info(P));
            }
            else
            {
                InsertVLast(L2, info(P));
            }
            P = next(P);
            i++;
        } while (P != First(L));
    }
}

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2)
{
    // kamus lokal
    address P;

    // algoritma
    CreateList(L2);

    if (!IsEmptyList(L1))
    {
        P = First(L1);
        do
        {
            InsertVLast(L2, info(P));
            P = next(P);
        } while (P != First(L1));
    }
}