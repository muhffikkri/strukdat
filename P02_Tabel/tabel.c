#include <stdio.h>
#include "tabel.h"
/* Deskripsi : Realisasi dari fungsi fungsi yang telah didefinisikan di tabel.h */
/* NIM/Nama : 24061024130069/Muhammad Fikri */
/* Tanggal : 11 September 2025*/

/************************KONSTRUKTOR*************************/
/* procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah dengan 1 karakter spasi, spasi dianggap karakter kosong}
	{Proses: menginisialisasi T} */
void createTable(Tabel *T)
{
	// Kamus
	int i = 1;

	// Algoritma
	for (i; i < 11; i++)
	{
		(*T).wadah[i] = ' ';
	}

	(*T).size = 0;
}

/************************SELEKTOR*************************/
/* function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize(Tabel T)
{
	// Kamus

	// Algoritma
	return T.size;
}

/*************************PREDIKAT*************************/
/* function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable(Tabel T)
{
	// Kamus

	// Algoritma
	return getSize(T) == 0;
}
/* function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable(Tabel T)
{
	// Kamus

	// Algoritma
	return getSize(T) == 10;
}

/*************************OPERASI PENCARIAN*************************/
/*  procedure searchX (input T:Tabel, input X:character, output pos:integer )
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai x dalam T.wadah} */
void searchX(Tabel T, char x, int *pos)
{
	// Kamus
	int i = 1;

	// Algoritma
	if (isEmptyTable(T))
	{
		(*pos) = -999;
	}
	else
	{
		while (i <= getSize(T) && T.wadah[i] != x)
		{
			i += 1;
		}

		if (i <= getSize(T))
		{
			(*pos) = i;
		}
		else
		{
			(*pos) = -999;
		}
	}
}

/* function countX (T:Tabel, x:character) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam T.wadah} */
int countX(Tabel T, char x)
{
	// Kamus
	int i = 1;
	int count = 0;

	// Algoritma
	if (isEmptyTable(T))
	{
		return count;
	}
	else
	{
		for (i; i <= getSize(T); i++)
		{
			if (T.wadah[i] == x)
			{
				count += 1;
			}
		}
		return count;
	}
}

/* function countVocal(T: Tabel) -> integer
	{mengembalikan banyak elemen T yang berupa karakter huruf vocal } */
int countVocal(Tabel T)
{
	// Kamus
	int i = 1;
	int count = 0;

	// Algoritma
	if (isEmptyTable(T))
	{
		return count;
	}
	else
	{
		for (i; i <= getSize(T); i++)
		{
			if (T.wadah[i] == 'a' || T.wadah[i] == 'A' ||
				T.wadah[i] == 'i' || T.wadah[i] == 'I' ||
				T.wadah[i] == 'u' || T.wadah[i] == 'U' ||
				T.wadah[i] == 'e' || T.wadah[i] == 'E' ||
				T.wadah[i] == 'o' || T.wadah[i] == 'O')
			{
				count += 1;
			}
		}
		return count;
	}
}

/*************************MUTATOR*************************/
/* procedure addXTable (input/output T:Tabel, input x: character)
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai x}
*/
void addXTable(Tabel *T, char x)
{
	// Kamus

	// Algoritma
	if (!isFullTable((*T)))
	{
		(*T).wadah[(getSize((*T))) + 1] = x;
		(*T).size = getSize((*T)) + 1;
	}
}

/* procedure addUniqueXTable (input/output T:Tabel, input x: character)
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika x unik dan tabel belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai unik x}
	*/
void addUniqueXTable(Tabel *T, char x)
{
	// Kamus
	int i = 1;

	// Algoritma
	if (!(isFullTable((*T))))
	{
		while (i <= getSize((*T)) && (*T).wadah[i] != x)
		{
			i += 1;
		}

		if (!(i <= getSize((*T))))
		{
			(*T).wadah[i] = x;
			(*T).size = i;
		}
	}
}

/* procedure delXTable (input/output T:Tabel, input x:character)
	{I.S.: T terdefinisi, x terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai x, geser semua elemen sisa}*/
void delXTable(Tabel *T, char x)
{
	// Kamus
	int i = 1;

	// Algoritma
	if (!(isEmptyTable(*T)))
	{
		while (i <= getSize((*T)) && (*T).wadah[i] != x)
		{
			i += 1;
		}

		if (i <= getSize((*T)))
		{
			(*T).wadah[i] = ' ';
			for (i; i < getSize((*T)); i++)
			{
				(*T).wadah[i] = (*T).wadah[i + 1];
				(*T).wadah[i + 1] = ' ';
			}

			(*T).size = getSize((*T)) - 1;
		}
	}
}

/* procedure delTable (input/output T:Tabel, input idx:integer)
	{I.S.: T terdefinisi, idx antara 1...getSize(T)}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen pada posisi idx, geser semua elemen sisa}*/
void delTable(Tabel *T, int idx)
{
	// Kamus

	// Algoritma
	if (!(isEmptyTable((*T))))
	{
		(*T).wadah[idx] = ' ';
		for (idx; idx < getSize((*T)); idx++)
		{
			(*T).wadah[idx] = (*T).wadah[idx + 1];
			(*T).wadah[idx + 1] = ' ';
		}

		(*T).size = getSize((*T)) - 1;
	}
}

/* procedure delAllXTable (input/output T:Tabel, input x:character)
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable(Tabel *T, char x)
{
	// Kamus
	int i, j = 1;

	// Algoritma
	if (!(isEmptyTable(*T)))
	{
		for (i = 1; i <= getSize(*T); i++)
		{
			if ((*T).wadah[i] != x)
			{
				(*T).wadah[j] = (*T).wadah[i];
				j++;
			}
		}
		(*T).size = j - 1;
		while (j <= 10)
		{
			(*T).wadah[j] = ' ';
			j++;
		}
	}
}

/*************************OPERASI BACA/TULIS*************************/
/* procedure printTable (input T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable(Tabel T)
{
	// Kamus
	int i = 1;
	// Algoritma
	for (i; i <= 10; i++)
	{
		printf("%c", T.wadah[i]);
	}
}

/* procedure viewTable (input T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable(Tabel T)
{
	// Kamus
	int i = 1;
	// Algoritma
	for (i; i <= getSize(T); i++)
	{
		printf("%c", T.wadah[i]);
	}
}

/* procedure populateTable (input/output T:Tabel, input N: integer)
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populateTable(Tabel *T, int N)
{
	// Kamus
	int i = 1;

	// Algoritma
	if (!(isFullTable((*T))))
	{
		(*T).size = N;
		while (N > 0)
		{
			scanf(" %c", &((*T).wadah[i]));
			i++;
			N--;
		}
	}
}

/*************************OPERASI STATISTIK*************************/
/*function Modus (T:Tabel ) -> integer
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
int Modus(Tabel T)
{
	// Kamus
	int idx, count = 0, freq = 0, i = 0;

	// Algoritma
	if (!isEmptyTable(T))
	{
		for (i; i <= getSize(T); i++)
		{
			count = countX(T, T.wadah[i]);
			if (count > freq)
			{
				freq = count;
				idx = i;
			}
		}
		return T.wadah[idx];
	}
	else
	{
		return ' ';
	}
}

/*************************OPERASI RELASIONAL*************************/
/* function IsEqualTable (T1:Tabel, T2: Table ) -> boolean
	{mengembalikan true jika T1 memiliki elemen dan urutan yang sama dengan T2 } */
boolean isEqualTable(Tabel T1, Tabel T2)
{
	// Kamus
	int i = 1;

	// Algoritma
	if (getSize(T1) == getSize(T2))
	{
		if (isEmptyTable(T1))
		{
			return true;
		}
		else
		{

			while (i <= getSize(T1))
			{
				if (T1.wadah[i] != T2.wadah[i])
					return false;
				i++;
			}
			return true;
		}
	}
	else
	{
		return false;
	}
}

/*************************OPERASI LAINNYA*************************/
/* function getInverseTable(T:Tabel) -> Tabel
	{mengembalikan tabel baru dengan isi elemen yang berkebalikan dengan tabel T } */
Tabel getInverseTable(Tabel T)
{
	// Kamus
	Tabel Tout;
	int i = 1;

	// Algoritma
	createTable(&Tout);

	for (i; i <= getSize(T); i++)
	{
		Tout.wadah[getSize(T) - i + 1] = T.wadah[i];
	}
	Tout.size = getSize(T);
	return Tout;
}

/* procedure inverseTable(input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah memiliki isi berkabalikan dengan isi tabel semula}
	{Proses: membalik isi elemen pada tabel T}*/
void inverseTable(Tabel *T)
{
	// Kamus
	int i = 1;
	char temp = ' ';

	// Algoritma
	for (i; i <= getSize((*T)) / 2; i++)
	{
		temp = (*T).wadah[getSize((*T)) - i + 1];
		(*T).wadah[getSize((*T)) - i + 1] = (*T).wadah[i];
		(*T).wadah[i] = temp;
	}
}

/*************************OPERASI PENGURUTAN*************************/
/* procedure SortAsc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari huruf abjad awal ke akhir}
	{Proses: mengurutkan elemen dalam T.wadah dari huruf abjad awal ke akhir}*/
void sortAsc(Tabel *T)
{
	// Kamus
	int i = 2;
	int j;
	char key = ' ';

	// Algoritma
	for (i; i <= getSize((*T)); i++)
	{
		key = (*T).wadah[i];
		j = i - 1;
		while (j >= 1 && ((*T).wadah[j] > key))
		{
			(*T).wadah[j + 1] = (*T).wadah[j];
			j--;
		}
		(*T).wadah[j + 1] = key;
	}
}

/* procedure SortDesc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari huruf abjad akhir ke awal}
	{Proses: mengurutkan elemen dalam T.wadah dari huruf abjad akhir ke awal}*/
void sortDesc(Tabel *T)
{
	// Kamus
	int i = 2;
	int j;
	char key = ' ';

	// Algoritma
	for (i; i <= getSize((*T)); i++)
	{
		key = (*T).wadah[i];
		j = i - 1;
		while (j >= 1 && ((*T).wadah[j] < key))
		{
			(*T).wadah[j + 1] = (*T).wadah[j];
			j--;
		}
		(*T).wadah[j + 1] = key;
	}
}
