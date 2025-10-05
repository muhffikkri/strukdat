#ifndef tqueue2_H
#define tqueue2_H
#include "boolean.h"
#include "tproses.h"

/* Program   : tqueue2.h */
/* Deskripsi : ADT Queue representasi kontigu dengan array,
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060124130069/Muhammad Fikri*/
/* Tanggal   : 4 Oktober 2025*/
/***********************************/

/* type tQueue2 = < wadah: array [1..5] of tProses,
                head: integer,
                tail: integer >
{cara akses: Q:tQueue2, Q.head = head(Q) ...} */
typedef struct
{
    tproses wadah[6]; // kapasitas 5 elemen, indeks 0 tidak dipakai
    int head;
    int tail;
} tqueue2;

/*procedure createQueue2 ( output Q:tQueue2 )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi head dan tail dengan 0, elemen kosong=tProses: <#, 0>}*/
void createQueue2(tqueue2 *Q);

/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head2(tqueue2 Q);

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail2(tqueue2 Q);

/*Function InfoHead2(Q:Tqueue2) -> tProses
{mengembalikan nilai elemen terdepan} */
tproses infoHead2(tqueue2 Q);

/*Function InfoTail2(Q:Tqueue2) -> tProses
{mengembalikan nilai elemen terakhir} */
tproses infoTail2(tqueue2 Q);

/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q);

/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q);

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tqueue2 Q);

/*function sizeQueue2(Q:tQueue2)-> integer
{mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q);

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua isi wadah ke layar}*/
void printQueue2(tqueue2 Q);

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue2(tqueue2 Q);

/*Function IsTailStop(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
boolean isTailStop(tqueue2 Q);

/*Procedure ResetHead(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
void resetHead(tqueue2 *Q);

/*procedure enQueue2( input/output Q:tQueue2, input P: tProses )
{I.S.: P terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas,
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, tproses P);

/*procedure deQueue2( input/output Q:tQueue2, output P: tProses )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
{proses: mengurangi elemen wadah Q, bila 1 elemen,
maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, tproses *P);

#endif
