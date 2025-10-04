#ifndef tproses_H
#define tproses_H
#include "boolean.h"

/* Program   : tproses.h */
/* Deskripsi : ADT Proses representasi kontigu dengan array */
/* NIM/Nama  : 24060124130069/Muhammad Fikri*/
/* Tanggal   : 4 Oktober 2025*/
/***********************************/

/* type tProses = < idProses: array [1..5] or character,
                burstTime: integer >
{cara akses: P:tProses, p.burstTime = burstTime(P)}*/
typedef struct
{
    char idProses[6];
    int burstTime;
} tproses;

/*procedure createQueue2 ( output Q:tQueue2 )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi head dan tail dengan 0, elemen kosong='#'}*/
void createQueue2(tproses *P);

/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head2(tproses P);

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail2(tproses P);

/*Function InfoHead2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead2(tproses P);

/*Function InfoTail2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail2(tproses P);

/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tproses P);

/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tproses P);

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tproses P);

#endif