#include <stdio.h>
#include "tabel.c"
/* Deskripsi : driver ADT tabel integer */
/* NIM/Nama : 24060124130069/Muhammad Fikri*/
/* Tanggal : 11 September 2025*/

int main()
{
	/* Kamus */
	Tabel T1, T2, T3;
	int idx;

	/* Algoritma */
	createTable(&T1);
	createTable(&T2);
	createTable(&T3);
	printf("createTable, ukuran = %d\n", getSize(T1));
	printTable(T1);
	viewTable(T1);

	printf("\nTambah elemen 'A', 'B', 'C'...\n");
	addXTable(&T1, 'A');
	addXTable(&T1, 'B');
	addXTable(&T1, 'C');
	printf("Ukuran tabel sekarang = %d\n", getSize(T1));
	printTable(T1);

	printf("\nHapus elemen 'B'...\n");
	delXTable(&T1, 'B');
	printf("Ukuran tabel sekarang = %d\n", getSize(T1));
	printTable(T1);

	printf("\nTambah elemen 'A'...\n");
	addXTable(&T1, 'A');
	addXTable(&T1, 'A');
	addXTable(&T1, 'A');
	printf("Ukuran tabel sekarang = %d\n", getSize(T1));
	printTable(T1);

	printf("\nCoba hapus elemen 'X' (tidak ada di tabel)...\n");
	delXTable(&T1, 'X');
	printf("Ukuran tabel sekarang = %d\n", getSize(T1));
	printTable(T1);

	printf("\nCari elemen 'A'");
	searchX(T1, 'A', &idx);
	printf("\n%d", idx);
	searchX(T1, 'B', &idx);
	printf("\n%d", idx);

	printf("\nModus: %d", Modus(T1));

	printf("\nHitung elemen A: %d", countX(T1, 'A'));
	printf("\nHitung vokal: %d", countVocal(T1));
	printf("\nTambah A dengan addUniqueTable");
	addUniqueXTable(&T1, 'A');
	printf("\nUkuran tabel sekarang = %d\n", getSize(T1));
	printf("\nTambah Z dengan addUniqueTable");
	addUniqueXTable(&T1, 'Z');
	printf("\nUkuran tabel sekarang = %d\n", getSize(T1));
	printTable(T1);

	printf("\nHapus elemen terakhir...\n");
	delTable(&T1, getSize(T1));
	printf("\nUkuran tabel sekarang = %d\n", getSize(T1));
	printTable(T1);

	printf("\nInput dari keyboard sesuai size T1 ");
	populateTable(&T2, getSize(T1));
	printTable(T2);

	printf("\nisEqual T1 dan T2: %d", isEqualTable(T1, T2));

	printf("\ngetInverseTable T2 ");
	T2 = getInverseTable(T2);
	printTable(T2);

	printf("\ninverseTable T1 ");
	printTable(T1);
	printf(" menjadi ");
	inverseTable(&T1);
	printTable(T1);

	printf("\nSort asc T1 ");
	sortAsc(&T1);
	printTable(T1);

	printf("\nSort desc T2 ");
	sortDesc(&T2);
	printTable(T2);

	return 0;
}
