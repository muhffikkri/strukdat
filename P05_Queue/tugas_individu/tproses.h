#ifndef tproses_H
#define tproses_H
#include "boolean.h"

/* Program   : tproses.h */
/* Deskripsi : ADT Proses representasi kontigu dengan array */
/* NIM/Nama  : 24060124130069/Muhammad Fikri*/
/* Tanggal   : 5 Oktober 2025*/
/***********************************/

/* type tProses = < idProses: character,
                    burstTime: integer >
{cara akses: P:tProses, p.idProses = idProses(P),
                        p.burstTime = burstTime(P)}*/
typedef struct
{
    char idProses;
    int burstTime;
} tproses;

/*procedure createProses ( output P:tProses input c:character, n:integer)
{I.S.: -}
{F.S.: P terdefinisi, kosong}
{Proses: mengisi burstTime dengan n, idProses=c}*/
void createProses(tproses *P, char c, int n);

/*Function idProses(P:TProses) -> character
{mengembalikan nilai idProses} */
char idProses(tproses P);

/*Function burstTime(P:TProses) -> integer
{mengembalikan nilai burstTime} */
int burstTime(tproses P);

#endif