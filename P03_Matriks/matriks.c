/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060124130069/Muhammad Fikri*/
/* Tanggal   : 18 September 2025*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriks.h"
#include "boolean.h"

/* KONSTRUKTOR */
/* procedure initMatriks(output M: Matriks)
    {I.S.: - }
    {F.S.: Matriks M terdefinisi}
    {Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M)
{
    // Kamus
    int i, j;

    // Algoritma
    for (i = 1; i <= 10; i++)
    {
        for (j = 1; j <= 10; j++)
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
    // Kamus

    // Algoritma
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
    {mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M)
{
    // Kamus

    // Algoritma
    return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
    {mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M)
{
    // Kamus

    // Algoritma
    return getNBaris(M) == 0 && getNKolom(M) == 0;
}

/* function isFullMatriks(M: Matriks) -> boolean
    {mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M)
{
    // Kamus

    // Algoritma
    return getNBaris(M) == 11 && getNKolom(M) == 11;
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
    {I.S.: M terdefinisi, X terdefinisi }
    {F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
    {Proses: mengisi elemen M.cell dengan nilai X} */
void addX(Matriks *M, int X, int row, int col)
{
    // Kamus
    int i;
    int count;

    // Algoritma
    if (!isFullMatriks((*M)) && ((*M).cell[row][col] == -999))
    {
        i = 1;
        count = 0;
        while (i <= 10 && count == 0)
        {
            if ((*M).cell[row][i] != -999)
            {
                count++;
            }
            i++;
        }

        if (count == 0)
        {
            (*M).nkolom = getNKolom(*M) + 1;
        }

        i = 1;
        count = 0;
        while (i <= 10 && count == 0)
        {
            if ((*M).cell[i][col] != -999)
            {
                count++;
            }
            i++;
        }

        if (count == 0)
        {
            (*M).nbaris = getNBaris(*M) + 1;
        }

        (*M).cell[row][col] = X;
    }
}

/* procedure delX (input/output M:Matriks, input X:integer )
     {I.S.: M terdefinisi, X terdefinisi}
     {F.S.: elemen M.cell berkurang 1}
     {Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX(Matriks *M, int X)
{
    // Kamus
    int i, j;
    int delCol, delRow;
    int count = 0;
    int found = -999;

    // Algoritma
    if (!isEmptyMatriks(*M))
    {
        i = 1;
        j = 1;
        while (i <= 10 && found == -999)
        {
            j = 1;
            while (j <= 10 && found == -999)
            {
                if ((*M).cell[i][j] == X)
                {
                    found = (*M).cell[i][j];
                }
                j++;
            }
            i++;
        }

        delRow = i - 1;
        delCol = j - 1;

        if (i <= 10 && j <= 10)
        {
            (*M).cell[delRow][delCol] = -999;
        }

        count = 0;
        j = 1;
        while (j <= 10 && count == 0)
        {
            if ((*M).cell[delRow][j] != -999)
            {
                count++;
            }
            j++;
        }

        if (count == 0)
        {
            (*M).nbaris = getNBaris(*M) - 1;
        }

        count = 0;
        i = 1;
        while (i <= 10 && count == 0)
        {
            if ((*M).cell[i][delCol] != -999)
            {
                count++;
            }
            i++;
        }

        if (count == 0)
        {
            (*M).nkolom = getNKolom(*M) - 1;
        }
    }
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y)
{
    // Kamus
    int i, j;

    // Algoritma
    srand(time(NULL));

    for (i = 1; i <= x; i++)
    {
        for (j = 1; j <= y; j++)
        {
            (*M).cell[i][j] = rand();
        }
    }

    (*M).nbaris = x;
    (*M).nkolom = y;
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
     {I.S.: M terdefinisi}
     {F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
     {proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n)
{
    // Kamus
    int i, j;

    // Algoritma

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
            {
                (*M).cell[i][j] = 1;
            }
            else
            {
                (*M).cell[i][j] = 0;
            }
        }
    }
    (*M).nbaris = n;
    (*M).nkolom = n;
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y)
{
    // Kamus
    int i, j;

    // Algoritma
    for (i = 1; i <= x; i++)
    {
        for (j = 1; j <= y; j++)
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
    // Kamus
    int i, j;

    // Algoritma
    for (i = 1; i <= 10; i++)
    {
        for (j = 1; j <= 10; j++)
        {
            printf("   %d ", M.cell[i][j]);
        }
        printf("\n");
    }
}

/* procedure viewMatriks (input M:Matriks)
    {I.S.: M terdefinisi}
    {F.S.: -}
    {Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks(Matriks M)
{
    // Kamus
    int i, j;
    int minBaris = 1, maxBaris = 10;
    int minKolom = 1, maxKolom = 10;
    int pass = 0;

    // Algoritma
    if (!isEmptyMatriks(M))
    {
        while (minBaris <= 10 && pass == 0)
        {
            j = 1;
            while (j <= 10 && pass == 0)
            {
                if (M.cell[minBaris][j] != -999)
                {
                    pass = 1;
                }

                j++;
            }
            minBaris++;
        }
        minBaris--;

        pass = 0;
        while (minKolom <= 10 && pass == 0)
        {
            i = 1;
            while (i <= 10 && pass == 0)
            {
                if (M.cell[i][minKolom] != -999)
                {
                    pass = 1;
                }

                i++;
            }
            minKolom++;
        }
        minKolom--;

        j = 10;
        pass = 0;
        while (maxBaris >= minBaris && pass == 0)
        {
            j = 10;
            while (j >= minKolom && pass == 0)
            {
                if (M.cell[maxBaris][j] != -999)
                {
                    pass = 1;
                }
                j--;
            }
            maxBaris--;
        }
        maxBaris++;

        i = 10;
        pass = 0;
        while (maxKolom >= minKolom && pass == 0)
        {
            i = 10;
            while (i >= minBaris && pass == 0)
            {
                if (M.cell[i][maxKolom] != -999)
                {
                    pass = 1;
                }
                i--;
            }
            maxKolom--;
        }
        maxKolom++;

        for (i = minBaris; i <= maxBaris; i++)
        {
            for (j = minKolom; j <= maxKolom; j++)
            {
                if (M.cell[i][j] != -999)
                {
                    printf("%4d ", M.cell[i][j]);
                }
                else
                {
                    printf("   . ");
                }
            }
            printf("\n");
        }
    }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2)
{
    // Kamus
    int i, j;
    Matriks M3;

    // Algoritma
    initMatriks(&M3);

    for (i = 1; i <= 10; i++)
    {
        for (j = 1; j <= 10; j++)
        {
            if (M1.cell[i][j] != -999 && M2.cell[i][j] != -999)
            {
                M3.cell[i][j] = M1.cell[i][j] + M2.cell[i][j];
            }
            else if (M1.cell[i][j] != -999)
            {
                M3.cell[i][j] = M1.cell[i][j];
            }
            else if (M2.cell[i][j] != -999)
            {
                M3.cell[i][j] = M2.cell[i][j];
            }
        }
    }

    return M3;
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2)
{
    // Kamus
    int i, j;
    Matriks M3;

    // Algoritma
    initMatriks(&M3);

    for (i = 1; i <= 10; i++)
    {
        for (j = 1; j <= 10; j++)
        {
            if (M1.cell[i][j] != -999 && M2.cell[i][j] != -999)
            {
                M3.cell[i][j] = M1.cell[i][j] - M2.cell[i][j];
            }
            else if (M1.cell[i][j] != -999)
            {
                M3.cell[i][j] = M1.cell[i][j];
            }
            else if (M2.cell[i][j] != -999)
            {
                M3.cell[i][j] = -M2.cell[i][j];
            }
        }
    }

    return M3;
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2)
{
    // Kamus
    int i, j, k;
    int tempSum;
    int ValidMultiplication = 0;
    Matriks M3;

    // Algoritma
    initMatriks(&M3);

    for (i = 1; i <= 10; i++)
    {
        for (j = 1; j <= 10; j++)
        {
            tempSum = 0;
            ValidMultiplication = 0;

            for (k = 1; k <= 10; k++)
            {
                if (M1.cell[i][k] != -999 && M2.cell[k][j] != -999)
                {
                    tempSum += M1.cell[i][k] * M2.cell[k][j];
                    ValidMultiplication = 1;
                }
            }

            if (ValidMultiplication)
            {
                M3.cell[i][j] = tempSum;
            }
        }
    }

    return M3;
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M, int x)
{
    // Kamus
    int i, j;
    Matriks MOut;

    // Algoritma
    initMatriks(&MOut);

    for (i = 1; i <= 10; i++)
    {
        for (j = 1; j <= 10; j++)
        {
            if (M.cell[i][j] != -999)
            {
                MOut.cell[i][j] = M.cell[i][j] * x;
            }
        }
    }

    return MOut;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
    {I.S.: M terdefinisi}
    {F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
    {proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M)
{
    // Kamus
    int i, j, temp;
    int maxDim;

    // Algoritma
    if ((*M).nbaris > (*M).nkolom)
    {
        maxDim = (*M).nbaris;
    }
    else
    {
        maxDim = (*M).nbaris;
    }

    for (i = 1; i <= maxDim; i++)
    {
        for (j = i + 1; j <= maxDim; j++)
        {
            if (i != j)
            {
                temp = (*M).cell[i][j];
                (*M).cell[i][j] = (*M).cell[j][i];
                (*M).cell[j][i] = temp;
            }
        }
    }

    temp = (*M).nbaris;
    (*M).nbaris = (*M).nkolom;
    (*M).nkolom = temp;
}

/* function getTransposeMatriks(M: Matriks)
    {menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M)
{
    // Kamus
    int i, j;
    Matriks MT;

    // Algoritma
    initMatriks(&MT);

    for (i = 1; i <= getNBaris(M); i++)
    {
        for (j = 1; j <= getNKolom(M); j++)
        {
            MT.cell[j][i] = M.cell[i][j];
        }
    }
    MT.nbaris = getNKolom(M);
    MT.nkolom = getNBaris(M);
    return MT;
}

/* function addPadding(M: Matriks, input n:integer)
    {menghasilkan matriks baru dari M yang ditambahkan padding 0 sesuai dengan ukuran padding n */
Matriks addPadding(Matriks M, int n)
{
    // Kamus
    int i, j;
    Matriks MPad;

    // Algoritma
    initMatriks(&MPad);
    if (!isFullMatriks(M) && M.nbaris + (2 * n) <= 10 && M.nkolom + (2 * n) <= 10)
    {
        for (i = 1; i <= M.nbaris; i++)
        {
            for (j = 1; j <= M.nkolom; j++)
            {
                MPad.cell[i + n][j + n] = M.cell[i][j];
            }
        }

        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= M.nkolom + (2 * n); j++)
            {
                MPad.cell[i][j] = 0;
                MPad.cell[M.nbaris + n + i][j] = 0;
            }
        }

        for (i = n + 1; i <= M.nbaris + n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                MPad.cell[i][j] = 0;
                MPad.cell[i][M.nkolom + n + j] = 0;
            }
        }

        MPad.nbaris = M.nbaris + (2 * n);
        MPad.nkolom = M.nkolom + (2 * n);
        return MPad;
    }
    else
    {
        return M;
    }
}

/* function maxPooling(M: Matriks, input size:integer)
    {menghasilkan matriks hasil max pooling matriks M dengan pool size = size  */
Matriks maxPooling(Matriks M, int size)
{
    // Kamus
    int i, j, pi, pj;
    int maxVal, currentVal;
    int newRows, newCols;
    Matriks MPool;

    // Algoritma
    initMatriks(&MPool);

    if (size <= 0 || M.nbaris < size || M.nkolom < size)
    {
        return M;
    }
    else
    {
        newRows = M.nbaris / size;
        newCols = M.nkolom / size;

        for (i = 0; i < newRows; i++)
        {
            for (j = 0; j < newCols; j++)
            {
                maxVal = M.cell[(i * size) + 1][(j * size) + 1];

                for (pi = 0; pi < size; pi++)
                {
                    for (pj = 0; pj < size; pj++)
                    {
                        currentVal = M.cell[(i * size) + pi + 1][(j * size) + pj + 1];
                        if (currentVal > maxVal)
                        {
                            maxVal = currentVal;
                        }
                    }
                }
                MPool.cell[i + 1][j + 1] = maxVal;
            }
        }

        MPool.nbaris = newRows;
        MPool.nkolom = newCols;

        return MPool;
    }
}

/* function avgPooling(M: Matriks, input size:integer)
    {menghasilkan matriks hasil average pooling matriks M dengan pool size = size  */
Matriks avgPooling(Matriks M, int size)
{
    // Kamus
    int i, j, pi, pj;
    int sumVal;
    int newRows, newCols;
    Matriks MPool;

    // Algoritma
    initMatriks(&MPool);

    if (size <= 0 || M.nbaris < size || M.nkolom < size)
    {
        return M;
    }
    else
    {
        newRows = M.nbaris / size;
        newCols = M.nkolom / size;

        for (i = 0; i < newRows; i++)
        {
            for (j = 0; j < newCols; j++)
            {
                sumVal = 0;

                for (pi = 0; pi < size; pi++)
                {
                    for (pj = 0; pj < size; pj++)
                    {
                        sumVal += M.cell[(i * size) + pi + 1][(j * size) + pj + 1];
                    }
                }

                MPool.cell[i + 1][j + 1] = sumVal / (size * size);
            }
        }

        MPool.nbaris = newRows;
        MPool.nkolom = newCols;

        return MPool;
    }
}

/* function conv(M: Matriks, K:Matriks)
    {menghasilkan matriks hasil konvolusi matriks M dengan kernel K  */
Matriks conv(Matriks M, Matriks K)
{
    // Kamus
    int i, j, ki, kj;
    int convSum;
    int newRows, newCols;
    int centerK;
    int mi, mj;
    Matriks MConv;

    // Algoritma
    initMatriks(&MConv);

    if (K.nbaris <= 0 || K.nkolom <= 0 || K.nbaris % 2 == 0 || K.nkolom % 2 == 0 ||
        K.nbaris > M.nbaris || K.nkolom > M.nkolom)
    {
        return M;
    }
    else
    {
        newRows = M.nbaris - K.nbaris + 1;
        newCols = M.nkolom - K.nkolom + 1;

        centerK = K.nbaris / 2;

        for (i = 0; i < newRows; i++)
        {
            for (j = 0; j < newCols; j++)
            {
                convSum = 0;

                for (ki = 0; ki < K.nbaris; ki++)
                {
                    for (kj = 0; kj < K.nkolom; kj++)
                    {
                        mi = i + ki + 1;
                        mj = j + kj + 1;

                        convSum += M.cell[mi][mj] * K.cell[ki + 1][kj + 1];
                    }
                }

                MConv.cell[i + 1][j + 1] = convSum;
            }
        }

        MConv.nbaris = newRows;
        MConv.nkolom = newCols;
        return MConv;
    }
}

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
    {I.S.: M terdefinisi, X terdefinisi }
    {F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
    {Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col)
{
    // Kamus
    int i, j;
    int found;

    // Algoritma
    found = 0;
    *row = -999;
    *col = -999;

    i = 1;
    while (i <= 10 && !found && !isEmptyMatriks(M))
    {
        j = 1;
        while (j <= 10 && !found)
        {
            if (M.cell[i][j] == X)
            {
                *row = i;
                *col = j;
                found = 1;
            }
            j++;
        }
        i++;
    }
}

/* function countX (M:Matriks, X: integer) -> integer
    {mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX(Matriks M, int X)
{
    // Kamus
    int i, j;
    int count;

    // Algoritma
    count = 0;

    for (i = 1; i <= M.nbaris; i++)
    {
        for (j = 1; j <= M.nkolom; j++)
        {
            if (M.cell[i][j] == X)
                count++;
        }
    }
    return count;
}