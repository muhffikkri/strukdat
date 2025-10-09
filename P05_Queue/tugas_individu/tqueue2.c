#include <stdio.h>
#include "tqueue2.h"
#include "boolean.h"
#include "tproses.h"

/* Program   : tqueue2.h */
/* Deskripsi : ADT Queue representasi kontigu dengan array,
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060124130069/Muhammad Fikri*/
/* Tanggal   : 5 Oktober 2025*/
/***********************************/

/*procedure createQueue2 ( output Q:tQueue2 )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi head dan tail dengan 0, elemen kosong=tProses: <#, 0>}*/
void createQueue2(tqueue2 *Q)
{
    // Kamus
    int i;
    tproses prosesKosong;

    // Algoritma
    i = 1;
    createProses(&prosesKosong, '#', 0);
    for (i; i <= 5; i++)
    {
        (*Q).wadah[i] = prosesKosong;
    }

    (*Q).head = 0;
    (*Q).tail = 0;
}

/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head2(tqueue2 Q)
{
    return Q.head;
}

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail2(tqueue2 Q)
{
    return Q.tail;
}

/*Function InfoHead2(Q:Tqueue2) -> tProses
{mengembalikan nilai elemen terdepan} */
tproses infoHead2(tqueue2 Q)
{
    return Q.wadah[head2(Q)];
}

/*Function InfoTail2(Q:Tqueue2) -> tProses
{mengembalikan nilai elemen terakhir} */
tproses infoTail2(tqueue2 Q)
{
    return Q.wadah[tail2(Q)];
}

/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q)
{
    // Kamus

    // Algoritma
    return head2(Q) == 0 && tail2(Q) == 0;
}

/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q)
{
    // Kamus

    // Algoritma
    return head2(Q) == 1 && tail2(Q) == 5;
}

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tqueue2 Q)
{
    // Kamus

    // Algoritma
    return head2(Q) == tail2(Q) && head2(Q) != 0 && tail2(Q) != 0;
}

/*function sizeQueue2(Q:tQueue2)-> integer
{mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q)
{
    // Kamus

    // Algoritma
    if (isEmptyQueue2(Q))
        return 0;
    else
        return tail2(Q) - head2(Q) + 1;
}

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua isi wadah ke layar}*/
void printQueue2(tqueue2 Q)
{
    // Kamus
    int i;

    // Algoritma
    for (i = 1; i <= 5; i++)
    {
        printf("[%c,%d] ", Q.wadah[i].idProses, Q.wadah[i].burstTime);
    }
    printf("\n");
}

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue2(tqueue2 Q)
{
    // Kamus
    int i;

    // Algoritma
    if (!isEmptyQueue2(Q))
    {
        for (i = head2(Q); i <= tail2(Q); i++)
        {
            printf("[%c,%d] ", Q.wadah[i].idProses, Q.wadah[i].burstTime);
        }
        printf("\n");
    }
    else
    {
        printf("Queue is empty\n");
    }
}

/*Function IsTailStop(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
boolean isTailStop(tqueue2 Q)
{
    // Kamus

    // Algoritma
    return tail2(Q) == 5;
}

/*Procedure ResetHead(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
void resetHead(tqueue2 *Q)
{
    // Kamus
    int i, j;
    tproses prosesKosong;

    // Algoritma
    j = head2(*Q);
    i = 1;
    createProses(&prosesKosong, '#', 0);
    if (isTailStop(*Q) && !isFullQueue2(*Q) && i != j)
    {
        for (i; i <= sizeQueue2(*Q); i++)
        {
            (*Q).wadah[i] = (*Q).wadah[j];
            (*Q).wadah[j] = prosesKosong;
            j++;
        }
        (*Q).head = 1;
        (*Q).tail = sizeQueue2(*Q);
    }
}

/*procedure enQueue2( input/output Q:tQueue2, input P: tProses )
{I.S.: P terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas,
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, tproses P)
{
    // Kamus

    // Algoritma
    if (!isFullQueue2(*Q))
    {
        if (isEmptyQueue2(*Q))
        {
            (*Q).head = 1;
            (*Q).tail = 1;
            (*Q).wadah[head2(*Q)] = P;
        }
        else
        {
            if (tail2(*Q) < 5)
            {
                (*Q).tail = tail2(*Q) + 1;
                (*Q).wadah[tail2(*Q)] = P;
            }
        }
    }
}

/*procedure deQueue2( input/output Q:tQueue2, output P: tProses )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
{proses: mengurangi elemen wadah Q, bila 1 elemen,
maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, tproses *P)
{
    // Kamus
    tproses prosesKosong;

    // Algoritma
    createProses(&prosesKosong, '#', 0);
    if (!isEmptyQueue2(*Q))
    {
        (*P) = infoHead2(*Q);
        (*Q).wadah[head2(*Q)] = prosesKosong;

        if (isOneElement2(*Q))
        {
            (*Q).head = 0;
            (*Q).tail = 0;
        }
        else
        {
            (*Q).head = head2(*Q) + 1;
        }
    }
}
