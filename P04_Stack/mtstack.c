/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"

int main()
{			  /* kamus main */
	Tstack A; // variabel A bertipe tStack
	char input;
	boolean Palindrom;

	/* algoritma */
	createStack(&A);
	printStack(A);
	printf("IsEmptyStack : %d \n", isEmptyStack(A));
	printf("IsFullStack : %d \n", isFullStack(A));
	input = 'X';
	push(&A, input);
	input = 'Y';
	push(&A, input);
	printf("Stack A Setelah dipush X dan Y \n");
	printStack(A);
	input = 'Y';
	pop(&A, &input);
	printf("Stack A setelah dipop X \n");
	printStack(A);

	printf("View stack sekarang \n");
	viewStack(A);
	input = 'M';
	push(&A, input);
	input = 'N';
	push(&A, input);
	printStack(A);
	printf("IsPalindrom : %d \n", isPalindrom(A));
	pushN(&A, 3);
	viewStack(A);

	return 0;
}
