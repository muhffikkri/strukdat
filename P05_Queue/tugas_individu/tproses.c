#include "boolean.h"
#include <stdio.h>
#include "tproses.h"

/* Program   : tproses.c */
/* Deskripsi : ADT Proses representasi kontigu dengan array */
/* NIM/Nama  : 24060124130069/Muhammad Fikri*/
/* Tanggal   : 5 Oktober 2025*/
/***********************************/

/*procedure createProses ( output P:tProses )
{I.S.: -}
{F.S.: P terdefinisi, kosong}
{Proses: mengisi burstTime dengan 0, id kosong='#'}*/
void createProses(tproses *P, char c, int n)
{
    (*P).idProses = c;
    (*P).burstTime = n;
}

/*Function idProses(P:TProses) -> character
{mengembalikan nilai idProses} */
char idProses(tproses P)
{
    return P.idProses;
}

/*Function burstTime(P:TProses) -> integer
{mengembalikan nilai burstTime} */
int burstTime(tproses P)
{
    return P.burstTime;
}