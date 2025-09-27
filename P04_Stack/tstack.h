#ifndef tstack_H
#define tstack_H

/* Program   : tstack.h */
/* Deskripsi : file HEADER modul stack karakter */
/* NIM/Nama  : 24060124130069/Muhammad Fikri*/
/* Tanggal   : 25 September 2025*/
/***********************************/

#include "boolean.h" //salin dari praktikum lalu

/* type Tstack = < wadah : array[1..10] of character,
				   top   : integer > */
typedef struct
{
	char wadah[11];
	int top;
} Tstack;
/*karakter kosong dilambangkan dengan '#'  */

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack(Tstack *T);

/*function top( T: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
// int top (Tstack T);
// dalam praktikum ini, fungsi dapat direalisasikan
// menjadi macro dalam bahasa C.
#define top(T) (T).top

/*function infotop( T: Tstack) -> character
	{mengembalikan nilai elemen top stack } */
// char infotop (Tstack T);
#define infotop(T) (T).wadah[(T).top]

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack(Tstack T);

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack(Tstack T);

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push(Tstack *T, char E);

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop(Tstack *T, char *X);

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar}
	{setiap elemen dipisah tanda titik koma } */
void printStack(Tstack T);

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}
	{setiap elemen dipisah tanda titik koma } */
void viewStack(Tstack T);

/* boolean isPalindrom(kata:String)
   {mengembalikan true jika kata merupakan palindrom, false jika tidak},
   {asumsi panjang kata maksimum adalah 30 karakter} */
boolean isPalindrom(Tstack T);

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN(Tstack *T, int N);

/*procedure PushBabel(input/output T:TStack)
	{I.S.: T terdefinisi, masukan terdefinisi }
	{F.S.: T bertambah 1 elemen (E) bila belum penuh atau menjadi kosong bila stack penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void PushBabel(Tstack *T);

/*Procedure Backward(Input/Output T1, T2:TStack, Input/Output X:char)
	 {I.S.: T1 terdefinisi, T2 terdefinisi }
	{F.S.: T1 berkurang 1 elemen  bila T1 tidak kosong}
	{Proses: menghapus 1 elemen di T1 dan menyimpan di T2}*/
void Backward(Tstack *T1, Tstack *T2);

/*Procedure Forward(Input/Output T1, T2:TStack, Input/Output X:char)
	 {I.S.: T1 terdefinisi, T2 terdefinisi }
	{F.S.: T berkurang 1 elemen  bila T2 tidak kosong}
	{Proses: menghapus 1 elemen di T2 dan menyimpan di T1}*/
void Forward(Tstack *T1, Tstack *T2);

#endif