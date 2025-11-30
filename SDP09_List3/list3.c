/* File : list3.c */
/* Deskripsi : ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124130069 / Muhammad Fikri */
/* Tanggal : 23 November 2025 */

#include "stdio.h"
#include "stdlib.h"
#include "list3.h"

/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) // representasi fisik fungsi
{							// kamus lokal
	// kamus lokal
	address P;

	// algoritma
	P = (address)malloc(sizeof(Elm));
	if (P != NIL)
	{
		info(P) = E;
		next(P) = NIL;
		prev(P) = NIL;
	}
	return P;
}

/* procedure Dealokasi (input/output P:address) */
/* {I.S. P terdefinisi
	F.S. P dikembalikan ke sistem
   Proses: Melakukan pengembalian address P} */
void Dealokasi(address *P)
{
	// kamus lokal

	// algoritma
	if ((*P) != NIL)
	{
		prev(*P) = NIL;
		next(*P) = NIL;
		(*P) = NIL;
	}
}

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong}
   {proses: membuat list kosong}*/
void CreateList(List3 *L)
{
	(*L).First = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList(List3 L)
{
	// kamus lokal

	// algoritma
	return First(L) == NIL;
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List3 L)
{
	// kamus lokal
	address P;

	// algoritma
	if (!IsEmptyList(L))
	{
		P = First(L);
		printf("\nElemen = ");
		do
		{
			printf("\t%c", info(P));
			P = next(P);
		} while (P != NIL);
	}
}

/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L)
{
	// kamus lokal
	address P;
	int count;

	// algoritma
	count = 0;
	if (!IsEmptyList(L))
	{
		P = First(L);
		while (P != NIL)
		{
			count++;
			P = next(P);
		}
	}
	return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V)
{
	// kamus lokal
	address baru;

	// algoritma
	baru = Alokasi(V);
	if (baru != NIL)
	{
		if (!IsEmptyList(*L))
		{
			next(baru) = First(*L);
			prev(First(*L)) = baru;
		}
		First(*L) = baru;
	}
}

/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V)
{
	// kamus lokal
	address P;
	address baru;

	// algoritma
	baru = Alokasi(V);
	if (baru != NIL)
	{
		if (!IsEmptyList(*L))
		{
			P = First(*L);
			while (next(P) != NIL)
			{
				P = next(P);
			}
			next(P) = baru;
			prev(baru) = P;
		}
		else
		{
			First(*L) = baru;
		}
	}
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V)
{
	// kamus lokal
	address P;
	address newFirst;

	// algoritma
	if (!IsEmptyList(*L))
	{
		P = First(*L);
		(*V) = info(P);
		if (next(P) == NIL)
		{
			Dealokasi(&P);
			First(*L) = NIL;
		}
		else
		{
			newFirst = next(P);
			Dealokasi(&P);
			prev(newFirst) = NIL;
			First(*L) = newFirst;
		}
	}
	else
	{
		(*V) = '#';
	}
}

/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V)
{
	// kamus lokal
	address P;
	address newLast;

	// algoritma
	if (!IsEmptyList(*L))
	{
		P = First(*L);
		if (next(P) == NIL)
		{
			// hanya 1 elemen
			(*V) = info(P);
			Dealokasi(&P);
			First(*L) = NIL;
		}
		else
		{
			// lebih dari 1 elemen - cari elemen terakhir
			while (next(P) != NIL)
			{
				newLast = P;
				P = next(P);
			}
			(*V) = info(P);
			Dealokasi(&P);
			next(newLast) = NIL;
		}
	}
	else
	{
		(*V) = '#';
	}
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L terdefinisi }
{ F.S. List mungkin menjadi kosong, atau berkurang 1 elemen. }
{ Proses: Elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteX(List3 *L, infotype X)
{
	// kamus lokal
	address P;

	// algoritma
	if (!IsEmptyList(*L))
	{
		P = First(*L);
		while (P != NIL && info(P) != X)
		{
			P = next(P);
		}

		if (P != NIL && info(P) == X)
		{
			// elemen ditemukan
			if (P == First(*L))
			{
				// hapus elemen pertama
				First(*L) = next(P);
				if (next(P) != NIL)
				{
					prev(next(P)) = NIL;
				}
			}
			else if (next(P) == NIL)
			{
				// hapus elemen terakhir
				next(prev(P)) = NIL;
			}
			else
			{
				// hapus elemen tengah
				next(prev(P)) = next(P);
				prev(next(P)) = prev(P);
			}
			Dealokasi(&P);
		}
	}
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X. }
{ Proses : Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A)
{
	// kamus lokal
	address P;

	// algoritma
	P = First(L);
	(*A) = NIL;

	while (P != NIL)
	{
		if (info(P) == X)
		{
			(*A) = P;
			break;
		}
		P = next(P);
	}
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.}
{ Proses : Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List3 *L, infotype X, infotype Y)
{
	// kamus lokal
	address P;

	// algoritma
	P = First(*L);

	while (P != NIL && info(P) != X)
	{
		P = next(P);
	}

	if (P != NIL && info(P) == X)
	{
		info(P) = Y;
	}
}

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L)
{
	// kamus lokal
	address P;
	address Temp;
	address Last;

	// algoritma
	if (!IsEmptyList(*L) && next(First(*L)) != NIL)
	{
		P = First(*L);
		Last = NIL;

		while (P != NIL)
		{
			// swap next dan prev
			Temp = prev(P);
			prev(P) = next(P);
			next(P) = Temp;

			// simpan elemen terakhir yang diproses
			Last = P;

			// lanjut ke elemen berikutnya (yang ada di prev sekarang)
			P = prev(P);
		}

		// Last sekarang adalah elemen terakhir yang sudah jadi first
		First(*L) = Last;
	}
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V)
{
	// kamus lokal
	address P;
	address baru;

	// algoritma
	if (!IsEmptyList(*L))
	{
		P = First(*L);
		while (P != NIL && info(P) != X)
		{
			P = next(P);
		}

		if (P != NIL && info(P) == X)
		{
			baru = Alokasi(V);
			if (baru != NIL)
			{
				next(baru) = next(P);
				prev(baru) = P;
				if (next(P) != NIL)
				{
					prev(next(P)) = baru;
				}
				next(P) = baru;
			}
		}
	}
}

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V)
{
	// kamus lokal
	address P;
	address baru;

	// algoritma
	if (!IsEmptyList(*L))
	{
		P = First(*L);
		while (P != NIL && info(P) != X)
		{
			P = next(P);
		}

		if (P != NIL && info(P) == X)
		{
			baru = Alokasi(V);
			if (baru != NIL)
			{
				if (P == First(*L))
				{
					// insert before first
					next(baru) = P;
					prev(P) = baru;
					First(*L) = baru;
				}
				else if (prev(P) != NIL)
				{
					// insert before P (bukan first) - pastikan prev(P) tidak NULL
					prev(baru) = prev(P);
					next(baru) = P;
					next(prev(P)) = baru;
					prev(P) = baru;
				}
			}
		}
	}
}

/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V)
{
	// kamus lokal
	address P;
	address Del;

	// algoritma
	(*V) = '#';
	if (!IsEmptyList(*L))
	{
		P = First(*L);
		while (P != NIL && info(P) != X)
		{
			P = next(P);
		}

		if (P != NIL && next(P) != NIL)
		{
			Del = next(P);
			(*V) = info(Del);
			next(P) = next(Del);
			if (next(Del) != NIL)
			{
				prev(next(Del)) = P;
			}
			Dealokasi(&Del);
		}
	}
}

/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V)
{
	// kamus lokal
	address P;
	address Del;

	// algoritma
	(*V) = '#';
	if (!IsEmptyList(*L))
	{
		P = First(*L);
		while (P != NIL && info(P) != X)
		{
			P = next(P);
		}

		if (P != NIL && prev(P) != NIL)
		{
			Del = prev(P);
			(*V) = info(Del);
			if (Del == First(*L))
			{
				First(*L) = P;
				prev(P) = NIL;
			}
			else
			{
				prev(P) = prev(Del);
				next(prev(Del)) = P;
			}
			Dealokasi(&Del);
		}
	}
}

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X)
{
	// kamus lokal
	address P;
	int count;

	// algoritma
	P = First(L);
	count = 0;

	while (P != NIL)
	{
		if (info(P) == X)
		{
			count++;
		}
		P = next(P);
	}

	return count;
}

/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List3 L, infotype X)
{
	// kamus lokal
	int total;
	int freq;

	// algoritma
	total = NbElm(L);
	if (total == 0)
	{
		return 0.0;
	}
	freq = CountX(L, X);
	return (float)freq / (float)total;
}

/*function MaxMember(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List3 L)
{
	// kamus lokal
	address P;
	int max;
	int count;

	// algoritma
	if (IsEmptyList(L))
	{
		return 0;
	}

	P = First(L);
	max = CountX(L, info(P));

	P = next(P);
	while (P != NIL)
	{
		count = CountX(L, info(P));
		if (count > max)
		{
			max = count;
		}
		P = next(P);
	}

	return max;
}

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List3 L)
{
	// kamus lokal
	address P;
	int max;
	int count;
	char result;

	// algoritma
	if (IsEmptyList(L))
	{
		return '#';
	}

	P = First(L);
	max = CountX(L, info(P));
	result = info(P);

	P = next(P);
	while (P != NIL)
	{
		count = CountX(L, info(P));
		if (count > max)
		{
			max = count;
			result = info(P);
		}
		P = next(P);
	}

	return result;
}

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L)
{
	// kamus lokal
	address P;
	int count;

	// algoritma
	P = First(L);
	count = 0;

	while (P != NIL)
	{
		if (info(P) == 'a' || info(P) == 'A' ||
			info(P) == 'i' || info(P) == 'I' ||
			info(P) == 'u' || info(P) == 'U' ||
			info(P) == 'e' || info(P) == 'E' ||
			info(P) == 'o' || info(P) == 'O')
		{
			count++;
		}
		P = next(P);
	}

	return count;
}

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L)
{
	// kamus lokal
	address P;
	int count;

	// algoritma
	P = First(L);
	count = 0;

	while (P != NIL && next(P) != NIL)
	{
		if ((info(P) == 'N' || info(P) == 'n') &&
			(info(next(P)) == 'G' || info(next(P)) == 'g'))
		{
			count++;
		}
		P = next(P);
	}

	return count;
}

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. - }
{ Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List3 L, infotype X)
{
	// kamus lokal
	address P;
	int pos;
	int found;

	// algoritma
	P = First(L);
	pos = 1;
	found = 0;

	while (P != NIL)
	{
		if (info(P) == X)
		{
			if (found > 0)
			{
				printf(",");
			}
			printf("%d", pos);
			found++;
		}
		P = next(P);
		pos++;
	}

	if (found == 0)
	{
		printf("0");
	}
}

/*Procedure DeleteAllX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. List mungkin menjadi kosong. }
{ Proses: Semua elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteAllX(List3 *L, infotype X)
{
	// kamus lokal
	address P;
	address Del;

	// algoritma
	P = First(*L);

	while (P != NIL)
	{
		if (info(P) == X)
		{
			Del = P;
			P = next(P);

			if (Del == First(*L))
			{
				// hapus first
				First(*L) = P;
				if (P != NIL)
				{
					prev(P) = NIL;
				}
			}
			else if (next(Del) == NIL)
			{
				// hapus last
				next(prev(Del)) = NIL;
			}
			else
			{
				// hapus tengah
				next(prev(Del)) = next(Del);
				prev(next(Del)) = prev(Del);
			}
			Dealokasi(&Del);
		}
		else
		{
			P = next(P);
		}
	}
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List3, input L2:List3, output L:List3)
{I.S.: L1,L2 terdefinisi ;
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List3 L1, List3 L2, List3 *L)
{
	// kamus lokal
	address P;

	// algoritma
	CreateList(L);

	P = First(L1);
	while (P != NIL)
	{
		InsertVLast(L, info(P));
		P = next(P);
	}

	P = First(L2);
	while (P != NIL)
	{
		InsertVLast(L, info(P));
		P = next(P);
	}
}

/*Procedure SplitList(input L:List3, output L1:List3, output L2:List3)
{I.S.: L terdefinisi ;
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List3 L, List3 *L1, List3 *L2)
{
	// kamus lokal
	address P;
	int n;
	int mid;
	int i;

	// algoritma
	CreateList(L1);
	CreateList(L2);

	if (!IsEmptyList(L))
	{
		n = NbElm(L);
		mid = (n + 1) / 2;

		P = First(L);
		i = 1;

		while (P != NIL && i <= mid)
		{
			InsertVLast(L1, info(P));
			P = next(P);
			i++;
		}

		while (P != NIL)
		{
			InsertVLast(L2, info(P));
			P = next(P);
		}
	}
}

/*Procedure CopyList(input L1:List3, output L2:List3)
{I.S.: L1 terdefinisi;
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List3 L1, List3 *L2)
{
	// kamus lokal
	address P;

	// algoritma
	CreateList(L2);

	P = First(L1);
	while (P != NIL)
	{
		InsertVLast(L2, info(P));
		P = next(P);
	}
}