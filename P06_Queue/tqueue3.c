#include "boolean.h"
#include <math.h>
#include "tqueue3.h"
#include <stdio.h>

/* Program   : tqueue3.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array,
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060124130069/Muhammad Fikri*/
/* Tanggal   : 9 Oktober 2005*/
/***********************************/

/*function isEmptyQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue3(tqueue3 Q)
{
    // Kamus

    // Algoritma
    return head3(Q) == 0 && tail3(Q) == 0;
}

/*function isFullQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue3(tqueue3 Q)
{
    // Kamus

    // Algoritma
    return (head3(Q) == 1 && tail3(Q) == 5) || (head3(Q) - 1 == tail3(Q));
}

/*function isOneElement3(Q:tQueue3) -> boolean
{mengembalikan true jika Q 1 elemen}*/
boolean isOneElement3(tqueue3 Q)
{
    // Kamus

    // Algoritma
    return !isEmptyQueue3(Q) && head3(Q) == tail3(Q);
}

/*procedure createQueue3 ( output Q:tQueue3)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='#'}*/
void createQueue3(tqueue3 *Q)
{
    // Kamus
    int i;

    // Algoritma
    i = 1;
    for (i; i <= 5; i++)
    {
        (*Q).wadah[i] = '#';
    }

    (*Q).head = 0;
    (*Q).tail = 0;
}

/*Function Head3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terdepan} */
int head3(tqueue3 Q)
{
    return Q.head;
}

/*Function Tail3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terakhir} */
int tail3(tqueue3 Q)
{
    return Q.tail;
}

/*Function InfoHead3(Q:tqueue3) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead3(tqueue3 Q)
{
    return Q.wadah[head3(Q)];
}

/*Function InfoTail3(Q:tqueue3) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail3(tqueue3 Q)
{
    return Q.wadah[tail3(Q)];
}

/*function sizeQueue3(Q:tQueue3)-> integer
{mengembalikan panjang antrian Q} */
int sizeQueue3(tqueue3 Q)
{
    // Kamus

    // Algoritma
    if (isEmptyQueue3(Q))
    {
        return 0;
    }
    else if (tail3(Q) >= head3(Q))
    {
        return tail3(Q) - head3(Q) + 1;
    }
    else
    {
        return (5 - head3(Q) + 1) + tail3(Q);
    }
}

/*procedure printQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak isi wadah ke layar, berisi atau kosong}*/
void printQueue3(tqueue3 Q)
{
    // Kamus
    int i;

    // Algoritma
    i = 1;
    for (i; i <= 5; i++)
    {
        printf(" %c", Q.wadah[i]);
    }
}

/*procedure viewQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue3(tqueue3 Q)
{
    // Algoritma
    int i, idx;

    if (!isEmptyQueue3(Q))
    {
        idx = head3(Q);
        for (i = 0; i < sizeQueue3(Q); i++)
        {
            printf("%c", Q.wadah[idx]);
            idx = (idx % 5) + 1;
        }
    }
}

/*procedure enQueue3( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 } */
void enqueue3(tqueue3 *Q, char E)
{
    if (!isFullQueue3(*Q))
    {
        if (isEmptyQueue3(*Q))
        {
            (*Q).head = 1;
        }

        (*Q).tail = (tail3(*Q) % 5) + 1;
        (*Q).wadah[tail3(*Q)] = E;
    }
}

/*procedure deQueue3( input/output Q:tQueue3,output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q), bila kosong E=' '}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue3(tqueue3 *Q, char *E)
{
    if (!isEmptyQueue3(*Q))
    {
        (*E) = infoHead3(*Q);
        (*Q).wadah[head3(*Q)] = '#';

        if (isOneElement3(*Q))
        {
            (*Q).head = 0;
            (*Q).tail = 0;
        }
        else
        {
            (*Q).head = (head3(*Q) % 5) + 1;
        }
    }
}

/*EKSTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*function isTailOverHead(Q:tQueue3) -> boolean
{mengembalikan true jika tail berada di depan head}*/
boolean isTailOverHead(tqueue3 Q)
{
    return !isEmptyQueue3(Q) && tail3(Q) < head3(Q);
}

/*procedure enqueue3N( input/output Q:tQueue3, input N:integer )
{I.S.: Q terdefinisi, mungkin kosong, N <= kapasitas - panjang antrean}
{F.S.: elemen wadah Q bertambah <= N elemen bila belum penuh}
{proses: mengisi elemen dari keyboard} */
void enqueue3N(tqueue3 *Q, int N)
{
    char e;
    while (N > 0 && !isFullQueue3(*Q))
    {
        scanf(" %c", &e);
        enqueue3(Q, e);
        N--;
    }
}

/*Function isEqualQueue3(Q1:tQueue3,Q2:tQueue3) -> boolean
{mengembalikan true jika Q1 dan Q2 berisi elemen yang sama}
{ingat, kondisi head Q1 dan Q2 mungkin tidak sama} */
boolean isEqualQueue3(tqueue3 Q1, tqueue3 Q2)
{
    int i, current1, current2;

    if (sizeQueue3(Q1) != sizeQueue3(Q2))
    {
        return false;
    }

    if (isEmptyQueue3(Q1) && isEmptyQueue3(Q2))
    {
        return true;
    }

    current1 = head3(Q1);
    current2 = head3(Q2);

    for (i = 0; i < sizeQueue3(Q1); i++)
    {
        if (Q1.wadah[current1] != Q2.wadah[current2])
        {
            return false;
        }
        current1 = (current1 % 5) + 1;
        current2 = (current2 % 5) + 1;
    }

    return true;
}
