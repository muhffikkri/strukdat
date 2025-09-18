/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060124130069/Muhammad Fikri*/
/* Tanggal   : 18 September 2025*/
/***********************************/

#include <stdio.h>
#include "matriks.h"
#include "boolean.h"

/* KONSTRUKTOR */
/* procedure initMatriks(output M: Matriks)
    {I.S.: - }
    {F.S.: Matriks M terdefinisi}
    {Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M)
{
    int i, j = 1;

    for (i; i <= 11; i++)
    {
        for (j; j <= 11; j++)
        {
            (*M).cell[i][j] = -999;
        }
    }

    (*M).nbaris = 0;
    (*M).nkolom = 0;
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
    {mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M)
{
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
    {mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M)
{
    return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
    {mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M)
{
    return getNBaris(M) == 0 && getNKolom == 0;
}

/* function isFullMatriks(M: Matriks) -> boolean
    {mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M)
{
    return getNBaris(M) == 11 && getNKolom == 11;
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
    {I.S.: M terdefinisi, X terdefinisi }
    {F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
    {Proses: mengisi elemen M.cell dengan nilai X} */
void addX(Matriks *M, int X, int row, int col)
{
    int i, j = 1;

    if (!isFullMatriks((*M)) && ((*M).cell[row][col] != -999))
    {
        (*M).cell[row][col] = X;

        while (j <= 11 && (*M).cell[row][j] == -999)
        {
            j++;
        }

        if (j > 11)
        {
            (*M).nbaris = getNBaris + 1;
        }

        while (i <= 11 && (*M).cell[i][col] == -999)
        {
            i++;
        }

        if (i > 11)
        {
            (*M).nkolom = getNKolom + 1;
        }
    }
}

/* procedure delX (input/output M:Matriks, input X:integer )
    {I.S.: M terdefinisi, X terdefinisi}
    {F.S.: elemen M.cell berkurang 1}
    {Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX(Matriks *M, int X)
{
    int i, j = 1;
    int delCol, delRow = 0;

    while (i <= 11 && !isEmptyMatriks(*M))
    {
        while (j <= 11 && ((*M).cell[i][j] != X))
        {
            j++;
        }
        i++;
    }

    if (i <= 11 && j <= 11 && ((*M).cell[i][j] != -999))
    {
        delRow = i;
        delCol = j;
        (*M).cell[delRow][delCol] = -999;

        while (j <= 11 && (*M).cell[delRow][j] == -999)
        {
            j++;
        }

        if (j > 11)
        {
            (*M).nbaris = getNBaris - 1;
        }

        while (i <= 11 && (*M).cell[i][delCol] == -999)
        {
            i++;
        }

        if (i > 11)
        {
            (*M).nkolom = getNKolom - 1;
        }
    }
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
    {I.S.: M terdefinisi}
    {F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
    {proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y)
{
    int i, j = 1;

    for (i; i <= x; i++)
    {
        for (j; j <= y; j++)
        {
            (*M).cell[i][j] = rand();
        }
    }
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
    {I.S.: M terdefinisi}
    {F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
    {proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n)
{
    int i, j = 1;

    while (i <= n && j <= n)
    {
        (*M).cell[i][j] = 1;
        i++;
        j++;
    }
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y)
{
    int i, j = 1;

    for (i; i <= x; i++)
    {
        for (j; j <= y; j++)
        {
            scanf(" %d", &((*M).cell[i][j]));
        }
    }
}

/* procedure printMatriks(input M:Matriks)
    {I.S.: M terdefinisi}
    {F.S.: -}
    {Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M)
{
    int i, j = 1;

    for (i; i <= 11; i++)
    {
        for (j; j <= 11; j++)
        {
            printf("%d", M.cell[i][j]);
        }
    }
}

/* procedure viewMatriks (input M:Matriks)
    {I.S.: M terdefinisi}
    {F.S.: -}
    {Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks(Matriks M)
{
    int i, j = 1;

    for (i; i <= getNBaris; i++)
    {
        for (j; j <= 11; j++)
        {
            printf("%d", M.cell[i][j]);
        }
    }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2);

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2);

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2);

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x);

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
    {I.S.: M terdefinisi}
    {F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
    {proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M);

/* function getTransposeMatriks(M: Matriks)
    {menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M);

/* function addPadding(M: Matriks, input n:integer)
    {menghasilkan matriks baru dari M yang ditambahkan padding 0 sesuai dengan ukuran padding n */
Matriks addPadding(Matriks M, int n);

/* function maxPooling(M: Matriks, input size:integer)
    {menghasilkan matriks hasil max pooling matriks M dengan pool size = size  */
Matriks maxPooling(Matriks M, int size);

/* function avgPooling(M: Matriks, input size:integer)
    {menghasilkan matriks hasil average pooling matriks M dengan pool size = size  */
Matriks avgPooling(Matriks M, int size);

/* function conv(M: Matriks, K:Matriks)
    {menghasilkan matriks hasil konvolusi matriks M dengan kernel K  */
Matriks conv(Matriks M, Matriks K);

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
    {I.S.: M terdefinisi, X terdefinisi }
    {F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
    {Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col)
{
    int i, j = 1;

    while (i <= 11 && !isEmptyMatriks(M))
    {
        while (j <= 11 && (M.cell[i][j] != X))
        {
            j++;
        }
        i++;
    }

    if (i <= 11 && j <= 11)
    {
        (*row) = i;
        (*col) = j;
    }
}

/* function countX (M:Matriks, X: integer) -> integer
    {mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX(Matriks M, int X)
{
    int i, j = 1;
    int count = 0;

    for (i; i <= 11; i++)
    {
        for (j; j <= 11; j++)
        {
            if (M.cell[i][j] == X)
                count++;
        }
    }
    return count;
}