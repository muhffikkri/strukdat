/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124130069 & Muhammad Fikri */
/* Tanggal : 27 November 2025 */

#include "pohon1.h"
#include <stdio.h>
#include <stdlib.h>

/* DEFINISI bintree kosong = NIL = ( ) */

/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* function AlokasiTree( E: infotype)-> bintree */
/* {menghasilkan alokasi memori pohon dengan info=E, left=NIL, right=NIL  } */
bintree AlokasiTree(infotype E)
{
    // kamus lokal
    bintree P;
    // algoritma
    P = (bintree)malloc(sizeof(node));
    if (P != NIL)
    {
        info(P) = E;
        left(P) = NIL;
        right(P) = NIL;
    }
    return P;
}

/* procedure DealokasiTree (input/output P:bintree) */
/* {I.S. P terdefinisi
    F.S. P dikembalikan ke sistem
  Proses: Melakukan pengembalian bintree P} */
void DealokasiTree(bintree *P)
{
    if ((*P) != NIL)
    {
        left(*P) = NIL;
        right(*P) = NIL;
    }
}

/********** PEMBUATAN bintree KOSONG ***********/
/* function Tree(Akar:infotype, Left:BinTree, Right:BinTree)-> BinTree
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
/*representasi logik fungsi*/
bintree Tree(infotype akar, bintree left, bintree right)
{
    // kamus lokal
    bintree P;
    // algoritma
    P = AlokasiTree(akar);
    if (P != NIL)
    {
        left(P) = left;
        right(P) = right;
    }
    return P;
}

/****** SELEKTOR *****/
/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P)
{
    return left(P);
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P)
{
    return right(P);
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> boolean
   {mengembalikan true bila bintree L kosong} */
boolean IsEmptyTree(bintree P)
{
    return P == NIL;
}

/* function IsDaun (P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree P)
{
    return (P != NIL) && (left(P) == NIL) && (right(P) == NIL);
}

/* function IsBiner (P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree P)
{
    return (P != NIL) && (left(P) != NIL) && (right(P) != NIL);
}

/* function IsUnerLeft(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree P)
{
    return (P != NIL) && (left(P) != NIL) && (right(P) == NIL);
}

/* function IsUnerRight(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree P)
{
    return (P != NIL) && (left(P) == NIL) && (right(P) != NIL);
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/

void PrintPrefix(bintree P)
{
    // kamus lokal

    // algoritma
    if (P == NIL)
    {
        printf("()");
    }
    else
    {
        printf("%c(", info(P));
        PrintPrefix(left(P));
        printf(",");
        PrintPrefix(right(P));
        printf(")");
    }
}

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P)
{
    // kamus lokal

    // algoritma
    if (P == NIL)
    {
        return 0;
    }
    else
    {
        return 1 + NbElm(left(P)) + NbElm(right(P));
    }
}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P)
{
    // kamus lokal

    // algoritma
    if (P == NIL)
    {
        return 0;
    }
    else
    {
        if (IsDaun(P))
        {
            return 1;
        }
        else
        {
            return NbDaun(left(P)) + NbDaun(right(P));
        }
    }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen yaitu 0 }*/
int Tinggi(bintree P)
{
    // kamus lokal

    // algoritma
    if (P == NIL)
    {
        return 0;
    }
    else
    {
        if (IsDaun(P))
        {
            return 0;
        }
        else
        {
            return 1 + max2(Tinggi(left(P)), Tinggi(right(P)));
        }
    }
}

/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> boolean
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchX(bintree P, infotype X)
{
    // kamus lokal

    // algoritma
    if (P == NIL)
    {
        return false;
    }
    else
    {
        if (info(P) == X)
        {
            return true;
        }
        else
        {
            return SearchX(left(P), X) || SearchX(right(P), X);
        }
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(bintree *P, infotype X, infotype Y)
{
    // kamus lokal

    // algoritma
    if ((*P) != NIL)
    {
        if (info(*P) == X)
        {
            info(*P) = Y;
        }

        UpdateX(&(left(*P)), X, Y);
        UpdateX(&(right(*P)), X, Y);
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(P:BinTree, X:infotype) -> integer
{ Mengirimkan banyaknya node dari P yang bernilai X }*/
int CountX(bintree P, infotype X)
{
    // kamus lokal
    int count;

    // algoritma
    if (P == NIL)
    {
        return 0;
    }
    else
    {
        count = (info(P) == X) ? 1 : 0;
        return count + CountX(left(P), X) + CountX(right(P), X);
    }
}

/*function IsSkewLeft (P : BinTree)-> boolean
{ Mengirim true jika P adalah pohon condong kiri } */
boolean IsSkewLeft(bintree P)
{
    // kamus lokal

    // algoritma
    if (P == NIL)
    {
        return true;
    }
    else
    {
        if (right(P) != NIL)
        {
            return false;
        }
        else
        {
            return IsSkewLeft(left(P));
        }
    }
}

/*function IsSkewRight (P : BinTree) -> boolean
{ Mengirim true jika P adalah pohon condong kanan }*/
boolean IsSkewRight(bintree P)
{
    // kamus lokal

    // algoritma
    if (P == NIL)
    {
        return true;
    }
    else
    {
        if (left(P) != NIL)
        {
            return false;
        }
        else
        {
            return IsSkewRight(right(P));
        }
    }
}

/* procedure PrintPrefixRingkas(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier ringkas} */
/*contoh: A(B(( ),D),C)*/
void PrintPrefixRingkas(bintree P)
{
    // kamus lokal

    // algoritma
    if (P == NIL)
    {
        printf("()");
    }
    else
    {
        printf("%c", info(P));
        if (left(P) != NIL || right(P) != NIL)
        {
            printf("(");
            if (left(P) != NIL)
            {
                PrintPrefixRingkas(left(P));
            }
            if (left(P) != NIL && right(P) != NIL)
            {
                printf(",");
            }
            if (right(P) != NIL)
            {
                PrintPrefixRingkas(right(P));
            }
            printf(")");
        }
    }
}

/*function LevelX(P:BinTree, X:infotype)-> integer
{ Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype X)
{
    // kamus lokal

    // algoritma
    if (P == NIL)
    {
        return 0;
    }
    else
    {
        if (info(P) == X)
        {
            return 1;
        }
        else
        {
            if (LevelX(left(P), X) != 0)
            {
                return 1 + LevelX(left(P), X);
            }

            if (LevelX(right(P), X) != 0)
            {
                return 1 + LevelX(right(P), X);
            }

            return 0;
        }
    }
}

/*function CountLevel(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevel(bintree P, int T)
{
    // kamus lokal

    // algoritma
    if (P == NIL)
    {
        return 0;
    }
    else
    {
        if (T == 0)
        {
            return 1;
        }
        else
        {
            T--;
            return 0 + CountLevel(left(P), T) + CountLevel(right(P), T);
        }
    }
}

/*procedure PrintLevel( input P:bintree, input N: integer )
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel(bintree P, int N)
{
    // kamus lokal

    // algoritma
    if (P != NIL)
    {
        if (N == 0)
        {
            printf("%c ", info(P));
        }
        else
        {
            PrintLevel(left(P), N - 1);
            PrintLevel(right(P), N - 1);
        }
    }
}

/*function GetDaunTerkiri(bintree P)-> infotype
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P)
{
    // kamus lokal

    // algoritma
    if (P == NIL)
    {
        return '#';
    }
    else
    {
        if (IsDaun(P))
        {
            return info(P);
        }
        else
        {
            if (left(P) != NIL)
            {
                return GetDaunTerkiri(left(P));
            }
            else
            {
                return GetDaunTerkiri(right(P));
            }
        }
    }
}

/*function FrekuensiX(P:bintree, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran bintree P }*/
float FrekuensiX(bintree P, infotype X)
{
    // kamus lokal
    int total;

    // algoritma
    if (P == NIL)
    {
        return 0.0;
    }
    else
    {
        if (NbElm(P) == 0)
        {
            return 0.0;
        }
        return (float)CountX(P, X) / (float)NbElm(P);
    }
}

/*function CountVocal(P:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree P}*/
int CountVocal(bintree P)
{
    // kamus lokal

    // algoritma
    if (P == NIL)
    {
        return 0;
    }
    else
    {
        return CountX(P, 'a') + CountX(P, 'i') + CountX(P, 'u') + CountX(P, 'e') + CountX(P, 'o') +
               CountX(P, 'A') + CountX(P, 'I') + CountX(P, 'U') + CountX(P, 'E') + CountX(P, 'O');
    }
}

/*procedure PrintVocal( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf vokal dalam bintree P}*/
void PrintVocal(bintree P)
{
    // kamus lokal

    // algoritma
    if (P != NIL)
    {
        if (info(P) == 'a' || info(P) == 'i' || info(P) == 'u' || info(P) == 'e' || info(P) == 'o' ||
            info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || info(P) == 'O')
        {
            printf("%c ", info(P));
        }
        PrintVocal(left(P));
        PrintVocal(right(P));
    }
}

/*function CountConsonant(P:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf konsonan dalam bintree L}*/
int CountConsonant(bintree P)
{
    // kamus lokal

    // algoritma
    if (P == NIL)
    {
        return 0;
    }
    else
    {
        return NbElm(P) - CountVocal(P);
    }
}

/*procedure PrintConsonant( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf konsonan dalam bintree P}*/
void PrintConsonant(bintree P)
{
    // kamus lokal

    // algoritma
    if (P != NIL)
    {
        if (info(P) != 'a' && info(P) != 'i' && info(P) != 'u' && info(P) != 'e' && info(P) != 'o' &&
            info(P) != 'A' && info(P) != 'I' && info(P) != 'U' && info(P) != 'E' && info(P) != 'O')
        {
            printf("%c ", info(P));
        }
        PrintConsonant(left(P));
        PrintConsonant(right(P));
    }
}

/*function Modus(P:bintree) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam bintree L}*/
char Modus(bintree P)
{
    // kamus lokal
    char leftModus, rightModus;
    int leftCount, rightCount, rootCount;

    // algoritma
    if (P == NIL)
    {
        return '#';
    }
    else if (IsDaun(P))
    {
        return info(P);
    }
    else
    {
        leftModus = Modus(left(P));
        rightModus = Modus(right(P));

        rootCount = CountX(P, info(P));
        leftCount = (leftModus != '#') ? CountX(P, leftModus) : 0;
        rightCount = (rightModus != '#') ? CountX(P, rightModus) : 0;

        if (rootCount >= leftCount && rootCount >= rightCount)
        {
            return info(P);
        }
        else if (leftCount >= rightCount)
        {
            return leftModus;
        }
        else
        {
            return rightModus;
        }
    }
}