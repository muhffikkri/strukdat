/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060124130069/Muhammad Fikri*/
/* Tanggal   : 25 September 2025*/
/***********************************/

#include <stdio.h>
#include "tstack.c"
#include "boolean.h"

int main()
{
    // kamus
    Tstack A1, A2;
    int input;

    // Algoritma
    createStack(&A1);
    createStack(&A2);
    input = 0;
    while (input != 4)
    {
        printf("input sesuai kode : \n");
        printf("1. Menambahkan elemen baru ke dalam stack dengan meminta input dari keyboard\n2. Melakukan backward\n3. Melakukan forward\n4. Exit (keluar dari perulangan, selesai)\n");

        printf("input : ");
        scanf("%d", &input);
        if (input == 1)
            PushBabel(&A1);
        else if (input == 2)
            Backward(&A1, &A2);
        else if (input == 3)
            Forward(&A1, &A2);
        else
            break;

        viewStack(A1);
    }
}