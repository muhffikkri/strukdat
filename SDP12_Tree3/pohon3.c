/* File : pohon3.h */
/* Deskripsi : ADT bintree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124130069 / Muhammad Fikri */
/* Tanggal : 11 Desember 2025*/

#include "pohon3.h"
#include <stdio.h>
#include <stdlib.h>

/************************ PROTOTYPE ************************/
/********** MANAJEMEN MEMORI ***********/
/* function AlokasiTree(X:infotype)->bintree3
{mengembalikan alamat elemen X bila berhasil, Nil bila gagal} */
bintree3 AlokasiTree(infotype X)
{
    // kamus lokal
    bintree3 P;

    // algoritma
    P = (bintree3)malloc(sizeof(node3));
    if (P != NIL)
    {
        info(P) = X;
        parent(P) = NIL;
        visited(P) = false;
        left(P) = NIL;
        right(P) = NIL;
    }
    return P;
}

/********** PEMBUATAN POHON BARU ***********/
/* function Tree3 (A:bintree3, X:infotype, V:boolean, kiri:bintree3, kanan:bintree3)-> bintree3
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree3 Tree3(bintree3 A, infotype X, boolean V, bintree3 kiri, bintree3 kanan)
{
    // kamus lokal
    bintree3 P;

    // algoritma
    P = AlokasiTree(X);
    if (P != NIL)
    {
        parent(P) = A;
        visited(P) = V;
        left(P) = kiri;
        right(P) = kanan;
    }
    return P;
}

/* penelusuran */
/* procedure printDFS( input P:bintree3)
{mencetak node-node P dari elemen terkiri mendalam baru ke kanan} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void printDFS(bintree3 P)
{
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P))
    {
        printf("%c(", info(P));
        if (IsBiner(P))
        {
            printDFS(left(P));
            printf(", ");
            printDFS(right(P));
        }
        else
        {
            if (IsUnerLeft(P))
            {
                printDFS(left(P));
            }
            else
            {
                printDFS(right(P));
            }
        }
        printf(")");
    }
    else
    {
        printf("()");
    }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b)
{
    // kamus lokal

    // algoritma
    return (a > b) ? a : b;
}

/* function Tinggi(P:bintree3)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi(bintree3 P)
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

/*procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel(bintree3 P, int N)
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

/* procedure PrintBFS( input P:bintree3)
{mencetak node-node P dari generasi paling terkecil ke terbesar}*/
/*contoh: A B C D */
void PrintBFS(bintree3 P)
{
    // kamus lokal
    int h, i;

    // algoritma
    if (!IsEmptyTree(P))
    {
        h = Tinggi(P);
        for (i = 0; i <= h; i++)
        {
            PrintLevel(P, i);
        }
    }
}

/****** SELEKTOR *****/
/* menggunakan macro */

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree3) --> boolean
   {mengembalikan true bila bintree3 L kosong} */
boolean IsEmptyTree(bintree3 P)
{
    // kamus lokal

    // algoritma
    return P == NIL;
}

/* function IsDaun (P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree3 P)
{
    return left(P) == NIL && right(P) == NIL;
}

/* function IsBiner (P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree3 P)
{
    return left(P) != NIL && right(P) != NIL;
}

/* function IsUnerLeft(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree3 P)
{
    return left(P) != NIL && right(P) == NIL;
}

/* function IsUnerRight(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree3 P)
{
    return left(P) == NIL && right(P) != NIL;
}

/*PENELUSURAN*/
/*procedure resetVisited( input/output P : bintree3 )
{I.S: P terdefinisi; F.S: -}
{proses mengubah status visited semua node di P menjadi false}*/
void resetVisited(bintree3 P)
{
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P))
    {
        if (visited(P))
        {
            visited(P) = false;
        }

        resetVisited(left(P));
        resetVisited(right(P));
    }
}

/*function searchNode(P:bintree3, X:infotype) -> boolean
{mengembalikan true jika node X ditemukan di pohon P}*/
boolean searchNode(bintree3 P, infotype X)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P))
    {
        return false;
    }

    if (info(P) == X)
    {
        return true;
    }

    return searchNode(left(P), X) || searchNode(right(P), X);
}

/*function searchDaun(P:bintree3, X:infotype) -> boolean
{mengembalikan true jika daun X ditemukan di pohon P}*/
boolean searchDaun(bintree3 P, infotype X)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P))
    {
        return false;
    }

    if (IsDaun(P) && info(P) == X)
    {
        return true;
    }

    return searchDaun(left(P), X) || searchDaun(right(P), X);
}

/*function searchHasDaun(P:bintree3) -> boolean
{mengembalikan true jika pohon P memiliki daun}*/
boolean searchHasDaun(bintree3 P)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P))
    {
        return false;
    }

    if (IsDaun(P))
    {
        return true;
    }

    return searchHasDaun(left(P)) || searchHasDaun(right(P));
}

/*procedure printPathX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga node bernilai X }*/
void printPathX(bintree3 P, infotype X)
{
    // kamus lokal

    // algoritma
    if (searchNode(P, X))
    {
        if (!IsEmptyTree(P))
        {
            printf("%c ", info(P));

            if (info(P) != X)
            {
                if (searchNode(left(P), X))
                {
                    printPathX(left(P), X);
                }
                else if (searchNode(right(P), X))
                {
                    printPathX(right(P), X);
                }
            }
        }
    }
    else
    {
        printf("Node %c tidak ditemukan", X);
    }
}

/*procedure printPathDaunX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga daun bernilai X }*/
void printPathDaunX(bintree3 P, infotype X)
{
    // kamus lokal

    // algoritma
    if (searchDaun(P, X))
    {
        if (!IsEmptyTree(P))
        {
            printf("%c ", info(P));

            if (!(IsDaun(P) && info(P) == X))
            {
                if (searchDaun(left(P), X))
                {
                    printPathDaunX(left(P), X);
                }
                else if (searchDaun(right(P), X))
                {
                    printPathDaunX(right(P), X);
                }
            }
        }
    }
    else
    {
        printf("Daun %c tidak ditemukan", X);
    }
}

/*helper procedure untuk printAllPaths dengan parameter path*/
void printAllPathsRec(bintree3 P, infotype *path, int pathLen)
{
    // kamus lokal
    int i;

    // algoritma
    if (searchHasDaun(P))
    {
        if (!IsEmptyTree(P))
        {
            path[pathLen] = info(P);
            pathLen++;

            if (IsDaun(P))
            {
                for (i = 0; i < pathLen; i++)
                {
                    printf("%c ", path[i]);
                }
                printf("\n");
            }
            else
            {
                if (searchHasDaun(left(P)))
                {
                    printAllPathsRec(left(P), path, pathLen);
                }
                if (searchHasDaun(right(P)))
                {
                    printAllPathsRec(right(P), path, pathLen);
                }
            }
        }
    }
}

/*procedure printAllPaths( input P:bintree3)
{menampilkan semua jalur yang mungkin dari akar P hingga setiap daun}*/
void printAllPaths(bintree3 P)
{
    // kamus lokal
    infotype *path;
    int maxDepth;

    // algoritma
    maxDepth = Tinggi(P) + 1;
    path = (infotype *)malloc(maxDepth * sizeof(infotype));

    if (path != NIL)
    {
        printAllPathsRec(P, path, 0);
        free(path);
    }
}

/* function NbElmTree(P:bintree3) --> integer
{ menghitung banyaknya elemen bintree3 P} */
int NbElmTree(bintree3 P)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P))
    {
        return 0;
    }
    else
    {
        return 1 + NbElmTree(left(P)) + NbElmTree(right(P));
    }
}

/* function NbDaun(P:bintree3)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree3 P)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P))
    {
        return 0;
    }
    else if (IsDaun(P))
    {
        return 1;
    }
    else
    {
        return NbDaun(left(P)) + NbDaun(right(P));
    }
}

/* function Level(P:bintree3)-> integer
{menghitung tingkat/generasi node pohon P, level akar=1 }*/
int Level(bintree3 P)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P))
    {
        return 0;
    }
    else
    {
        return Tinggi(P) + 1;
    }
}

/*function CountLevelT(P:bintree3, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT(bintree3 P, int T)
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
            return 0 + CountLevelT(left(P), T) + CountLevelT(right(P), T);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*** operator khusus LIST1 ***/
// printList sudah ADA di list1.h

/*procedure Pconcat( input/output Asli:list1, input Tambahan:list1) */
/*{I.S:- ; F.S: list Asli berubah karena disambung list Tambahan}*/
/*{menyambung list Tambahan ke belakang list Asli}*/
void Pconcat(List1 *Asli, List1 Tambahan)
{
    // kamus lokal
    address P;

    // algoritma
    if (IsEmptyList(*Asli))
    {
        First(*Asli) = First(Tambahan);
    }
    else
    {
        if (!IsEmptyList(Tambahan))
        {
            P = First(*Asli);
            while (next(P) != NIL)
            {
                P = next(P);
            }
            next(P) = First(Tambahan);
        }
    }
}

/*function fconcat( Asli:list1, Tambahan:list1) -> list1 */
/*{membentuk list Baru hasil penyambungan list Tambahan ke belakang list Asli}*/
/*{periksa dampaknya, list Asli tidak boleh berubah }*/
List1 Fconcat(List1 Asli, List1 Tambahan)
{
    // kamus lokal
    address P;
    List1 ListBaru;

    // algoritma
    CreateList(&ListBaru);

    P = First(Asli);
    while (P != NIL)
    {
        InsertVLast(&ListBaru, info(P));
        P = next(P);
    }

    P = First(Tambahan);
    while (P != NIL)
    {
        InsertVLast(&ListBaru, info(P));
        P = next(P);
    }

    return ListBaru;
}

/*** LINEARISASI POHON ***/
/*helper procedure untuk linear functions*/
void LinearPrefixHelper(bintree3 P, List1 *L)
{
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P))
    {
        InsertVLast(L, info(P));
        LinearPrefixHelper(left(P), L);
        LinearPrefixHelper(right(P), L);
    }
}

/*function linearPrefix(P:bintree3) -> list1
{menghasilkan list node dari P terurut prefix akar,kiri,kanan}*/
List1 LinearPrefix(bintree3 P)
{
    // kamus lokal
    List1 ListBaru;

    // algoritma
    CreateList(&ListBaru);
    LinearPrefixHelper(P, &ListBaru);
    return ListBaru;
}

/*helper procedure untuk LinearPosfix*/
void LinearPosfixHelper(bintree3 P, List1 *L)
{
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P))
    {
        LinearPosfixHelper(left(P), L);
        LinearPosfixHelper(right(P), L);
        InsertVLast(L, info(P));
    }
}

/*function linearPosfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut posfix kiri,kanan,akar}*/
List1 LinearPosfix(bintree3 P)
{
    // kamus lokal
    List1 ListBaru;

    // algoritma
    CreateList(&ListBaru);
    LinearPosfixHelper(P, &ListBaru);
    return ListBaru;
}

/*helper procedure untuk LinearInfix*/
void LinearInfixHelper(bintree3 P, List1 *L)
{
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P))
    {
        LinearInfixHelper(left(P), L);
        InsertVLast(L, info(P));
        LinearInfixHelper(right(P), L);
    }
}

/*function linearInfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut infix kiri,akar,kanan}*/
List1 LinearInfix(bintree3 P)
{
    // kamus lokal
    List1 ListBaru;

    // algoritma
    CreateList(&ListBaru);
    LinearInfixHelper(P, &ListBaru);
    return ListBaru;
}

/*helper procedure untuk LinearBreadthFS*/
void LinearBreadthFSHelper(bintree3 P, int level, List1 *L)
{
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P))
    {
        if (level == 0)
        {
            InsertVLast(L, info(P));
        }
        else
        {
            LinearBreadthFSHelper(left(P), level - 1, L);
            LinearBreadthFSHelper(right(P), level - 1, L);
        }
    }
}

/*function linearBreadthFS(P:bintree3) -> list1
{menghasilkan list node dari P terurut level/tingkat}*/
List1 LinearBreadthFS(bintree3 P)
{
    // kamus lokal
    List1 ListBaru;
    int h, i;

    // algoritma
    CreateList(&ListBaru);
    if (!IsEmptyTree(P))
    {
        h = Tinggi(P);
        for (i = 0; i <= h; i++)
        {
            LinearBreadthFSHelper(P, i, &ListBaru);
        }
    }
    return ListBaru;
}
