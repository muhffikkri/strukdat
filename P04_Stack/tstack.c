/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"
/* include tstack+boolean */

/*procedure createStack( output T: Tstack)
    {I.S.: -}
    {F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
    {Proses: menginisialisasi T} */
void createStack(Tstack *T)
{
    int i = 1;

    for (i; i <= 10; i++)
    {
        (*T).wadah[i] = '#';
    }
    (*T).top = 0;
}

/*function top( T: Tstack) -> integer
    {mengembalikan posisi puncak stack } */
// int top (Tstack T);
// dalam praktikum ini, fungsi dapat direalisasikan
// menjadi macro dalam bahasa C.
#define top(T) (T).top

/*function infotop( T: Tstack) -> character
    {mengembalikan nilai elemen top stack } */
// char infotop (Tstack T);
#define infotop(T) (T).wadah[(T).top]

/*function isEmptyStack( T: Tstack) -> boolean
    {mengembalikan True jika T kosong } */
boolean isEmptyStack(Tstack T)
{
    return top(T) == 0;
}

/*function isFullStack( T: Tstack) -> boolean
    {mengembalikan True jika T penuh } */
boolean isFullStack(Tstack T)
{
    return top(T) == 10;
}

/*procedure push ( input/output T:Tstack, input E: character )
    {I.S.: T,E terdefinisi}
    {F.S.: infotop tetap, atau berisi nilai E }
    {Proses: mengisi elemen top baru, bila belum penuh }*/
void push(Tstack *T, char E)
{
    if (!isFullStack(*T))
    {
        (*T).wadah[top(*T) + 1] = E;
    }
    (*T).top = top(*T) + 1;
}

/*procedure pop ( input/output T:Tstack, output X: character )
    {I.S.: T terdefinisi}
    {F.S.: X= infotop stack lama, atau '#' }
    {Proses: mengambil elemen top, bila belum kosong }*/
void pop(Tstack *T, char *X)
{
    if (!isEmptyStack(*T))
    {
        (*T).wadah[top(*T)] = '#';
    }
    (*T).top = top(*T) - 1;
}

/*procedure printStack ( input T:Tstack )
    {I.S.: T terdefinisi}
    {F.S.: -}
    {Proses: menampilkan kondisi wadah T ke layar}
    {setiap elemen dipisah tanda titik koma } */
void printStack(Tstack T)
{
    int i = 10;

    for (i; i >= 1; i--)
    {
        printf("%c", T.wadah[i]);
    }
}

/*procedure viewStack ( input T:Tstack )
    {I.S.: T terdefinisi}
    {F.S.: -}
    {Proses: menampilkan elemen tak kosong T ke layar}
    {setiap elemen dipisah tanda titik koma } */
void viewStack(Tstack T)
{
    int i = top(T);

    for (i; i >= 1; i--)
    {
        printf("%c", T.wadah[i]);
    }
}

/* boolean isPalindrom(kata:String)
   {mengembalikan true jika kata merupakan palindrom, false jika tidak},
   {asumsi panjang kata maksimum adalah 30 karakter} */
bool isPalindrom(char kata[30])
{
}

/*procedure pushN ( input/output T:Tstack, input N: integer )
    {I.S.: T,N terdefinisi}
    {F.S.: infotop tetap, atau top=N }
    {Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN(Tstack *T, int N)
{
    int i = 1;
    char e;

    if (!isEmptyStack(*T))
    {
        for (i; i <= N; i++)
        {
            scanf(" %c", e);
            push((&T), e);
        }
    }
}

/* kerjakan latihan aplikasi stack di file mbrowser.c */