/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060124130069/Muhammad Fikri*/
/* Tanggal   : 25 September 2025*/
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
    // Kamus
    int i = 1;

    // Algoritma
    for (i; i <= 10; i++)
    {
        (*T).wadah[i] = '#';
    }
    (*T).top = 0;
}

/*function isEmptyStack( T: Tstack) -> boolean
    {mengembalikan True jika T kosong } */
boolean isEmptyStack(Tstack T)
{
    // Kamus

    // Algoritma
    return top(T) == 0;
}

/*function isFullStack( T: Tstack) -> boolean
    {mengembalikan True jika T penuh } */
boolean isFullStack(Tstack T)
{
    // Kamus

    // Algoritma
    return top(T) == 10;
}

/*procedure push ( input/output T:Tstack, input E: character )
    {I.S.: T,E terdefinisi}
    {F.S.: infotop tetap, atau berisi nilai E }
    {Proses: mengisi elemen top baru, bila belum penuh }*/
void push(Tstack *T, char E)
{
    // Kamus

    // Algoritma
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
    // Kamus

    // Algoritma
    if (!isEmptyStack(*T))
    {
        *X = infotop(*T);
        (*T).wadah[top(*T)] = '#';
        (*T).top = top(*T) - 1;
    }
    else
    {
        *X = '#';
    }
}

/*procedure printStack ( input T:Tstack )
    {I.S.: T terdefinisi}
    {F.S.: -}
    {Proses: menampilkan kondisi wadah T ke layar}
    {setiap elemen dipisah tanda titik koma } */
void printStack(Tstack T)
{
    // Kamus
    int i;

    // Algoritma
    for (i = 1; i <= 10; i++)
    {
        printf("%c", T.wadah[i]);
        if (i < 10)
        {
            printf("; ");
        }
    }
    printf("\n");
}

/*procedure viewStack ( input T:Tstack )
    {I.S.: T terdefinisi}
    {F.S.: -}
    {Proses: menampilkan elemen tak kosong T ke layar}
    {setiap elemen dipisah tanda titik koma } */
void viewStack(Tstack T)
{
    // Kamus
    int i = top(T);

    // Algoritma
    for (i; i >= 1; i--)
    {
        printf("%c", T.wadah[i]);
    }
}

/* boolean isPalindrom(kata:String)
   {mengembalikan true jika kata merupakan palindrom, false jika tidak},
   {asumsi panjang kata maksimum adalah 30 karakter} */
boolean isPalindrom(Tstack T)
{
    // Kamus
    int i;

    // Algoritma
    for (i = 1; i <= (T.top / 2); i++)
    {
        if (T.wadah[i] != T.wadah[T.top - i + 1])
        {
            return false;
        }
    }
    return true;
}

/*procedure pushN ( input/output T:Tstack, input N: integer )
    {I.S.: T,N terdefinisi}
    {F.S.: infotop tetap, atau top=N }
    {Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN(Tstack *T, int N)
{
    // Kamus
    int i = 1;
    char e;

    // Algoritma
    if (!isFullStack(*T))
    {
        for (i; i <= N && !isFullStack(*T); i++)
        {
            scanf(" %c", &e);
            push(&(*T), e);
        }
    }
}

/*procedure PushBabel(input/output T:TStack)
    {I.S.: T terdefinisi, masukan terdefinisi }
    {F.S.: T bertambah 1 elemen (E) bila belum penuh atau menjadi kosong bila stack penuh }
    {Proses: menumpuk top atau menghapus semua elemen }*/
void PushBabel(Tstack *T)
{
    // Kamus
    char input;

    // Algoritma
    printf("Input karakter : ");
    scanf(" %c", &input);
    push(T, input);
}

/*Procedure Backward(Input/Output T1, T2:TStack, Input/Output X:char)
     {I.S.: T1 terdefinisi, T2 terdefinisi }
    {F.S.: T berkurang 1 elemen  bila T1 tidak kosong}
    {Proses: menghapus 1 elemen di T1 dan menyimpan di T2}*/
void Backward(Tstack *T1, Tstack *T2)
{
    // Kamus
    char X;

    // Algoritma
    pop(T1, &X);
    push(T2, X);
}

/*Procedure Forward(Input/Output T1, T2:TStack, Input/Output X:char)
     {I.S.: T1 terdefinisi, T2 terdefinisi }
    {F.S.: T2 berkurang 1 elemen  bila T2 tidak kosong}
    {Proses: menghapus 1 elemen di T2 dan menyimpan di T1}*/
void Forward(Tstack *T1, Tstack *T2)
{
    // Kamus
    char X;

    // Algoritma
    pop(T2, &X);
    push(T1, X);
}
