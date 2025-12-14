/* File : list1.c */
/* Deskripsi : realisasi body ADT list berkait representasi fisik pointer */
/* NIM & Nama 24060124130069 / Muhammad Fikri: */
/* Tanggal : 6 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List1)
   {I.S.: - ; F.S.: L list kosong}
   {proses: membuat list kosong}*/
void CreateList(List1 *L)
{
	(*L).First = NIL;
}

/********* manajemen memori ********/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E)
{
	// kamus lokal
	address P;
	// algoritma
	P = (address)malloc(sizeof(Elm));
	if (P != NIL)
	{ // ruang memori tersedia
		info(P) = E;
		next(P) = NIL;
	}
	return P;
}

/* procedure Dealokasi (input/output P:address) */
/* {I.S. P terdefinisi
	F.S. P dikembalikan ke NIL
	Proses: Melakukan pengosongan address P} */
void Dealokasi(address P)
{
	// kamus lokal

	// algoritma
	if (P != NIL)
	{
		next(P) = NIL;
	}
	P = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List1) --> boolean
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList(List1 L)
{
	// kamus lokal

	// algoritma
	return First(L) == NIL;
}

/**************** PENELUSURAN ****************/
/*procedure PrintList(input L:List1)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List1 L)
{
	// kamus lokal
	address P;

	// algoritma
	P = First(L);
	if (P != NIL)
	{
		printf("\nElemen = ");
		do
		{
			printf("\t%c", info(P));
			P = next(P);
		} while (P != NIL);
	}
}

/*function NbElm(L:List1) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List1 L)
{
	// kamus lokal
	int i;
	address P;

	// algoritma
	P = First(L);
	i = 0;
	while (P != NIL)
	{
		P = next(P);
		i++;
	}
	return i;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List1 *L, infotype V)
{
	// kamus lokal
	address P;

	// algoritma
	P = Alokasi(V);
	if (P != NIL)
	{
		next(P) = First(*L);
		First(*L) = P;
	}
}

/*Procedure InsertVLast(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List1 *L, infotype V)
{
	// kamus lokal
	address P;
	address Baru;

	// algoritma
	Baru = Alokasi(V);
	if (Baru != NIL)
	{
		if (IsEmptyList(*L))
		{
			First(*L) = Baru;
		}
		else
		{
			P = First(*L);
			while (next(P) != NIL)
			{
				P = next(P);
			}
			next(P) = Baru;
		}
	}
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi,  }
{ F.S. L tetap, atau berkurang elemen pertamanya.
Proses: Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List1 *L, infotype *V)
{
	// kamus lokal
	address P;

	// algoritma
	if (IsEmptyList(*L))
	{
		(*V) = '#';
	}
	else
	{
		P = First(*L);
		(*V) = info(P);
		First(*L) = next(P);
		Dealokasi(P);
	}
}

/*Procedure DeleteVLast(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi }
{ F.S. L tetap atau berkurang elemen terakhirnya.
Proses: Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List1 *L, infotype *V)
{
	// kamus lokal
	address P;
	address Prec;

	// algoritma
	if (IsEmptyList(*L))
	{
		(*V) = '#';
	}
	else if (next(First(*L)) == NIL)
	{
		// hanya 1 elemen
		(*V) = info(First(*L));
		Dealokasi(First(*L));
		First(*L) = NIL;
	}
	else
	{
		// lebih dari 1 elemen
		P = First(*L);
		Prec = NIL;
		while (next(P) != NIL)
		{
			Prec = P;
			P = next(P);
		}
		(*V) = info(P);
		next(Prec) = NIL;
		Dealokasi(P);
	}
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List1, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Proses: Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List1 L, infotype X, address *A)
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
			P = NIL;
		}
		else
		{
			P = next(P);
		}
	}
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Proses: Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List1 *L, infotype X, infotype Y)
{
	// kamus lokal
	address P;

	// algoritma
	P = First(*L);

	while (P != NIL && info(P) != X)
	{
		P = next(P);
	}

	if (info(P) == X)
	{
		info(P) = Y;
	}
}

/*Procedure Invers(input/output L:List1)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {'i','t','u'} menjadi {'u','t','i'} }*/
void Invers(List1 *L)
{
	// kamus lokal
	address P;
	address Prec;
	address Temp;

	// algoritma
	if (!IsEmptyList(*L) && next(First(*L)) != NIL)
	{
		P = First(*L);
		Prec = NIL;

		while (P != NIL)
		{
			Temp = next(P);
			next(P) = Prec;
			Prec = P;
			P = Temp;
		}

		First(*L) = Prec;
	}
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*function CountVocal(L:List1) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List1 L)
{
	// kamus lokal
	address P;
	int i;

	// algoritma
	P = First(L);
	i = 0;

	while (P != NIL)
	{
		if (
			info(P) == 'a' ||
			info(P) == 'i' ||
			info(P) == 'u' ||
			info(P) == 'e' ||
			info(P) == 'o')
			i++;
		P = next(P);
	}

	return i;
}

/*function CountX(L:List1, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List1 L, infotype X)
{
	// kamus lokal
	address P;
	int i;

	// algoritma
	P = First(L);
	i = 0;

	while (P != NIL)
	{
		if (info(P) == X)
			i++;
		P = next(P);
	}

	return i;
}

/*function FrekuensiX(L:List1, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List1 L, infotype X)
{
	// kamus lokal
	address P;
	int freq;
	int total;

	// algoritma
	P = First(L);
	freq = 0;
	total = 0;

	while (P != NIL)
	{
		total++;
		if (info(P) == X)
			freq++;
		P = next(P);
	}

	if (total == 0)
		return 0.0;
	else
		return (float)freq / (float)total;
}

/*Procedure SearchAllX(input L:List1, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi (1,2,3,...nbElm(L)) kemunculan elemen X dalam list L }*/
void SearchAllX(List1 L, infotype X)
{
	// kamus lokal
	address P;
	int i;

	// algoritma
	P = First(L);
	i = 1;

	printf("Posisi elemen '%c': ", X);
	while (P != NIL)
	{
		if (info(P) == X)
		{
			printf("%d ", i);
		}
		P = next(P);
		i++;
	}
}

/*Procedure UpdateAllX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau semua elemen bernilai X berubah menjadi Y.
Proses : mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(List1 *L, infotype X, infotype Y)
{
	// kamus lokal
	address P;

	// algoritma
	P = First(*L);

	while (P != NIL)
	{
		if (info(P) == X)
		{
			info(P) = Y;
		}
		P = next(P);
	}
}

/* Procedure InsertVAfter(input/output L:List1, input V:infotype, input VA:infotype )
{ I.S. List L mungkin kosong, V, S terdefinisi }
{ F.S. L tetap, atau bertambah 1 elemen (VA) pada posisi setelah elemen berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=VA sebagai elemen setelah elemen V list linier L yg mungkin kosong } */
void InsertVAfter(List1 *L, infotype V, infotype VA)
{
	// kamus lokal
	address P;
	address temp;

	// algoritma
	P = First(*L);
	if (IsEmptyList(*L))
	{
		First(*L) = Alokasi(VA);
	}
	else
	{
		while (P != NIL && info(P) != V)
		{
			P = next(P);
		}

		if (info(P) == V)
		{
			temp = next(P);
			next(P) = Alokasi(VA);
			P = next(P);
			next(P) = temp;
		}
	}
}

/*function Modus(L:List1) -> infotype */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
infotype Modus(List1 L)
{
	// kamus lokal
	address P;
	int mod;
	infotype res;

	// algoritma
	if (IsEmptyList(L))
	{
		return '#';
	}

	P = First(L);
	mod = CountX(L, info(P));
	res = info(P);

	P = next(P);
	while (P != NIL)
	{
		if (mod < CountX(L, info(P)))
		{
			mod = CountX(L, info(P));
			res = info(P);
		}
		P = next(P);
	}

	return res;
}

/*function NbModus(L:List1) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int NbModus(List1 L)
{
	// kamus lokal
	address P;
	int mod;

	// algoritma
	if (IsEmptyList(L))
	{
		return 0;
	}

	P = First(L);
	mod = CountX(L, info(P));

	P = next(P);
	while (P != NIL)
	{
		if (mod < CountX(L, info(P)))
		{
			mod = CountX(L, info(P));
		}
		P = next(P);
	}

	return mod;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List1, input L2:List1, output L:List1)
{I.S.: L1,L2 terdefinisi ;
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List1 L1, List1 L2, List1 *L)
{
	// kamus lokal
	address P;

	// algoritma
	CreateList(&(*L));
	P = First(L1);

	while (P != NIL)
	{
		InsertVLast(&(*L), info(P));
		P = next(P);
	}

	P = First(L2);

	while (P != NIL)
	{
		InsertVLast(&(*L), info(P));
		P = next(P);
	}
}

/*Procedure SplitList(input L:List1, output L1:List1, output L2:List1)
{I.S.: L terdefinisi ;
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List1 L, List1 *L1, List1 *L2)
{
	// kamus lokal
	address P;
	int n;
	int mid;
	int i;

	// algoritma
	CreateList(&(*L1));
	CreateList(&(*L2));

	if (!IsEmptyList(L))
	{
		n = NbElm(L);
		mid = (n + 1) / 2;

		P = First(L);
		i = 1;

		while (P != NIL && i <= mid)
		{
			InsertVLast(&(*L1), info(P));
			P = next(P);
			i++;
		}

		while (P != NIL)
		{
			InsertVLast(&(*L2), info(P));
			P = next(P);
		}
	}
}

/*Procedure CopyList(input L1:List1, output L2:List1)
{I.S.: L1 terdefinisi;
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List1 L1, List1 *L2)
{
	// kamus lokal
	address P;

	// algoritma
	CreateList(&(*L2));
	P = First(L1);

	while (P != NIL)
	{
		InsertVLast(&(*L2), info(P));
		P = next(P);
	}
}
