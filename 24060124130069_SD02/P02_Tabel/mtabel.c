#include <stdio.h>
#include "tabel.h"
/* Deskripsi : driver ADT tabel integer */
/* NIM/Nama : */
/* Tanggal : */

int main()
{
	/*kamus*/
	Tabel T1;

	/*algoritma*/
	createTable(&T1);
	addXTable(&T1, 'A');
	printf("%d", getSize(T1));
	printTable(T1);
	// addXTable(&T1,'B');
	// delXTable(&T1,'A');
	// printTable(T1);
	// dst ...
	return 0;
}
