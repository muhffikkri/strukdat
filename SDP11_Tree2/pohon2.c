/* File : pohon2.h */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : 24060124130069 / Muhammad Fikri */
/* Tanggal : 04 Desember 2025 */

#include "pohon2.h"
#include <stdio.h>
#include <stdlib.h>

/*PENELUSURAN*/
/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang,mirip file explorer} */
void PrintTreeInden(bintree P, int H)
{
    // kamus lokal
    int i;

    // algoritma
    if (!IsEmptyTree(P))
    {
        for (i = 0; i < H; i++)
        {
            printf("  ");
        }
        printf("%c\n", akar(P));
        PrintTreeInden(left(P), H + 1);
        PrintTreeInden(right(P), H + 1);
    }
}

/* procedure PrintLevel2(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N} */
void PrintLevel2(bintree P, int N)
{
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P))
    {
        if (N == 0)
        {
            printf("%c \t", akar(P));
        }
        else
        {
            PrintLevel2(left(P), N - 1);
            PrintLevel2(right(P), N - 1);
        }
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y)
{
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(*P))
    {
        if (akar(*P) == X)
        {
            akar(*P) = Y;
        }

        UpdateAllX(&(left(*P)), X, Y);
        UpdateAllX(&(right(*P)), X, Y);
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree P, infotype X)
{
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P))
    {
        if (IsDaun(P))
        {
            left(P) = Tree(X, NIL, NIL);
        }
        else
        {
            if (IsUnerLeft(P))
            {
                AddDaunTerkiri(left(P), X);
            }
            else
            {
                if (IsUnerRight(P))
                {
                    AddDaunTerkiri(right(P), X);
                }
                else
                {
                    // IsBiner(P)
                    AddDaunTerkiri(left(P), X);
                }
            }
        }
    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree P, infotype X, infotype Y, boolean Kiri)
{
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P))
    {
        if (IsDaun(P) && akar(P) == X)
        {
            if (Kiri)
            {
                left(P) = Tree(Y, NIL, NIL);
            }
            else
            {
                right(P) = Tree(Y, NIL, NIL);
            }
        }
        else
        {
            AddDaun(left(P), X, Y, Kiri);
            AddDaun(right(P), X, Y, Kiri);
        }
    }
}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(*P))
    {
        (*P) = Tree(X, NIL, NIL);
    }
    else
    {
        AddDaunTerkiri(*P, X);
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype *X)
{
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(*P))
    {
        if (IsDaun(*P))
        {
            (*X) = akar(*P);
            DealokasiTree(P);
            (*P) = NIL;
        }
        else
        {
            if (IsUnerLeft(*P))
            {
                DelDaunTerkiri(&(left(*P)), X);
            }
            else
            {
                if (IsUnerRight(*P))
                {
                    DelDaunTerkiri(&(right(*P)), X);
                }
                else
                {
                    // IsBiner(*P)
                    DelDaunTerkiri(&(left(*P)), X);
                }
            }
        }
    }
}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X)
{
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(*P))
    {
        if (IsDaun(*P) && akar(*P) == X)
        {
            DealokasiTree(P);
            (*P) = NIL;
        }
        else
        {
            if (IsUnerLeft(*P))
            {
                DelDaun(&(left(*P)), X);
            }
            else
            {
                if (IsUnerRight(*P))
                {
                    DelDaun(&(right(*P)), X);
                }
                else
                {
                    if (IsBiner(*P))
                    {
                        if (akar(left(*P)) == X && IsDaun(left(*P)))
                        {
                            DealokasiTree(&(left(*P)));
                            left(*P) = NIL;
                        }
                        else
                        {
                            if (akar(right(*P)) == X && IsDaun(right(*P)))
                            {
                                DealokasiTree(&(right(*P)));
                                right(*P) = NIL;
                            }
                            else
                            {
                                DelDaun(&(left(*P)), X);
                                DelDaun(&(right(*P)), X);
                            }
                        }
                    }
                }
            }
        }
    }
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X)
{
    // kamus lokal
    bintree temp, rightmost;

    // algoritma
    if (!IsEmptyTree(*P))
    {
        if (akar(*P) == X)
        {
            if (IsDaun(*P))
            {
                DealokasiTree(P);
                (*P) = NIL;
            }
            else
            {
                if (IsUnerLeft(*P))
                {
                    temp = *P;
                    (*P) = left(*P);
                    DealokasiTree(&temp);
                }
                else
                {
                    if (IsUnerRight(*P))
                    {
                        temp = *P;
                        (*P) = right(*P);
                        DealokasiTree(&temp);
                    }
                    else
                    {
                        // IsBiner(*P)
                        temp = *P;
                        (*P) = left(*P);
                        rightmost = *P;
                        while (right(rightmost) != NIL)
                        {
                            rightmost = right(rightmost);
                        }
                        right(rightmost) = right(temp);
                        DealokasiTree(&temp);
                    }
                }
            }
        }
        else
        {
            DeleteX(&(left(*P)), X);
            DeleteX(&(right(*P)), X);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n)
{
    // kamus lokal
    infotype X;
    bintree P;

    // algoritma
    if (n <= 0)
    {
        return NIL;
    }
    else
    {
        printf("Masukkan karakter: ");
        scanf(" %c", &X);
        P = Tree(X, NIL, NIL);
        left(P) = BuildBalanceTree(n / 2);
        right(P) = BuildBalanceTree(n - n / 2 - 1);
        return P;
    }
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P))
    {
        return true;
    }
    else
    {
        return (abs(NbElm(left(P)) - NbElm(right(P))) <= 1) &&
               IsBalanceTree(left(P)) &&
               IsBalanceTree(right(P));
    }
}

/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
infotype maxTree(bintree P)
{
    // kamus lokal
    char leftMax, rightMax;

    // algoritma
    if (P == NIL)
    {
        return '#';
    }
    else
    {
        if (IsDaun(P))
        {
            return akar(P);
        }
        else
        {
            if (IsUnerLeft(P))
            {
                leftMax = maxTree(left(P));
                if (akar(P) >= leftMax)
                {
                    return akar(P);
                }
                else
                {
                    return leftMax;
                }
            }
            else
            {
                if (IsUnerRight(P))
                {
                    rightMax = maxTree(right(P));
                    if (akar(P) >= rightMax)
                    {
                        return akar(P);
                    }
                    else
                    {
                        return rightMax;
                    }
                }
                else
                {
                    // IsBiner(P)
                    leftMax = maxTree(left(P));
                    rightMax = maxTree(right(P));

                    if (akar(P) >= leftMax && akar(P) >= rightMax)
                    {
                        return akar(P);
                    }
                    else
                    {
                        if (leftMax >= rightMax)
                        {
                            return leftMax;
                        }
                        else
                        {
                            return rightMax;
                        }
                    }
                }
            }
        }
    }
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
infotype minTree(bintree P)
{
    // kamus lokal
    char leftMin, rightMin;

    // algoritma
    if (P == NIL)
    {
        return '#';
    }
    else
    {
        if (IsDaun(P))
        {
            return akar(P);
        }
        else
        {
            if (IsUnerLeft(P))
            {
                leftMin = minTree(left(P));
                if (akar(P) <= leftMin)
                {
                    return akar(P);
                }
                else
                {
                    return leftMin;
                }
            }
            else
            {
                if (IsUnerRight(P))
                {
                    rightMin = minTree(right(P));
                    if (akar(P) <= rightMin)
                    {
                        return akar(P);
                    }
                    else
                    {
                        return rightMin;
                    }
                }
                else
                {
                    // IsBiner(P)
                    leftMin = minTree(left(P));
                    rightMin = minTree(right(P));

                    if (akar(P) <= leftMin && akar(P) <= rightMin)
                    {
                        return akar(P);
                    }
                    else
                    {
                        if (leftMin <= rightMin)
                        {
                            return leftMin;
                        }
                        else
                        {
                            return rightMin;
                        }
                    }
                }
            }
        }
    }
}

/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P))
    {
        return false;
    }
    else
    {
        if (akar(P) == X)
        {
            return true;
        }
        else
        {
            if (X < akar(P))
            {
                return BSearch(left(P), X);
            }
            else
            {
                return BSearch(right(P), X);
            }
        }
    }
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P))
    {
        return Tree(X, NIL, NIL);
    }
    else
    {
        if (X < akar(P))
        {
            if (IsEmptyTree(left(P)))
            {
                left(P) = Tree(X, NIL, NIL);
            }
            else
            {
                left(P) = InsSearch(left(P), X);
            }
        }
        else
        {
            if (X > akar(P))
            {
                if (IsEmptyTree(right(P)))
                {
                    right(P) = Tree(X, NIL, NIL);
                }
                else
                {
                    right(P) = InsSearch(right(P), X);
                }
            }
        }
        return P;
    }
}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X)
{
    // kamus lokal
    bintree temp;
    infotype successor;

    // algoritma
    if (!IsEmptyTree(*P))
    {
        if (X < akar(*P))
        {
            DelBtree(&(left(*P)), X);
        }
        else
        {
            if (X > akar(*P))
            {
                DelBtree(&(right(*P)), X);
            }
            else
            {
                if (IsDaun(*P))
                {
                    DealokasiTree(P);
                    (*P) = NIL;
                }
                else
                {
                    if (IsUnerLeft(*P))
                    {
                        temp = *P;
                        (*P) = left(*P);
                        DealokasiTree(&temp);
                    }
                    else
                    {
                        if (IsUnerRight(*P))
                        {
                            temp = *P;
                            (*P) = right(*P);
                            DealokasiTree(&temp);
                        }
                        else
                        {
                            // IsBiner(*P)
                            temp = right(*P);
                            while (!IsEmptyTree(left(temp)))
                            {
                                temp = left(temp);
                            }
                            successor = akar(temp);
                            DelBtree(P, successor);
                            akar(*P) = successor;
                        }
                    }
                }
            }
        }
    }
}
