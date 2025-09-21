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
    for (i = 1; i <= 11; i++)
    {
        for (j = 1; j <= 11; j++)
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
    {Proses: mengisi elemen M.cell dengan nilai X}
    {nbaris dan nkolom dihitung berdasarkan JUMLAH baris/kolom yang terisi:
     - nbaris = jumlah baris yang memiliki minimal 1 elemen valid (bukan -999)
     - nkolom = jumlah kolom yang memiliki minimal 1 elemen valid (bukan -999)
     Contoh: elemen di [1][1] dan [9][9] → nbaris=2, nkolom=2} */
void addX(Matriks *M, int X, int row, int col)
{
    // Kamus
    int i, j;
    int countBaris = 0, countKolom = 0;
    boolean barisAda[12] = {false}; // index 0 tidak dipakai
    boolean kolomAda[12] = {false}; // index 0 tidak dipakai

    // Algoritma
    if (!isFullMatriks((*M)) && ((*M).cell[row][col] == -999))
    {
        (*M).cell[row][col] = X;

        // Hitung ulang nbaris dan nkolom berdasarkan baris/kolom yang terisi
        // Reset array penanda
        for (i = 0; i <= 11; i++)
        {
            barisAda[i] = false;
            kolomAda[i] = false;
        }

        // Scan seluruh matriks untuk menandai baris/kolom yang terisi
        for (i = 1; i <= 11; i++)
        {
            for (j = 1; j <= 11; j++)
            {
                if ((*M).cell[i][j] != -999)
                {
                    barisAda[i] = true;
                    kolomAda[j] = true;
                }
            }
        }

        // Hitung jumlah baris dan kolom yang terisi
        countBaris = 0;
        countKolom = 0;
        for (i = 1; i <= 11; i++)
        {
            if (barisAda[i])
                countBaris++;
            if (kolomAda[i])
                countKolom++;
        }

        (*M).nbaris = countBaris;
        (*M).nkolom = countKolom;
    }
} /* procedure delX (input/output M:Matriks, input X:integer )
     {I.S.: M terdefinisi, X terdefinisi}
     {F.S.: elemen M.cell berkurang 1}
     {Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX(Matriks *M, int X)
{
    // Kamus
    int i, j;
    int delCol, delRow;

    // Algoritma
    i = 1;

    while (i <= 11 && !isEmptyMatriks(*M))
    {
        j = 1;
        while (j <= 11)
        {
            if ((*M).cell[i][j] == X)
            {
                delRow = i;
                delCol = j;
                (*M).cell[delRow][delCol] = -999;

                // Recalculate matrix dimensions - hitung jumlah baris/kolom terisi
                int countBaris = 0, countKolom = 0;
                boolean barisAda[12] = {false}; // index 0 tidak dipakai
                boolean kolomAda[12] = {false}; // index 0 tidak dipakai
                int k, l;

                // Reset array penanda
                for (k = 0; k <= 11; k++)
                {
                    barisAda[k] = false;
                    kolomAda[k] = false;
                }

                // Scan seluruh matriks untuk menandai baris/kolom yang terisi
                for (k = 1; k <= 11; k++)
                {
                    for (l = 1; l <= 11; l++)
                    {
                        if ((*M).cell[k][l] != -999)
                        {
                            barisAda[k] = true;
                            kolomAda[l] = true;
                        }
                    }
                }

                // Hitung jumlah baris dan kolom yang terisi
                for (k = 1; k <= 11; k++)
                {
                    if (barisAda[k])
                        countBaris++;
                    if (kolomAda[k])
                        countKolom++;
                }

                (*M).nbaris = countBaris;
                (*M).nkolom = countKolom;
                return;
            }
            j++;
        }
        i++;
    }
} /* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
     {I.S.: M terdefinisi}
     {F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
     {proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y)
{
    // Kamus
    int i, j;

    // Algoritma
    // Inisialisasi seed untuk random number generator
    srand(time(NULL));

    // Reset matriks terlebih dahulu
    initMatriks(M);

    for (i = 1; i <= x; i++)
    {
        for (j = 1; j <= y; j++)
        {
            addX(M, rand(), i, j); // Menggunakan addX untuk enkapsulasi
        }
    }
} /* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
     {I.S.: M terdefinisi}
     {F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
     {proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n)
{
    // Kamus
    int i, j;

    // Algoritma
    // Reset matriks terlebih dahulu
    initMatriks(M);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
            {
                addX(M, 1, i, j); // Menggunakan addX untuk enkapsulasi
            }
            else
            {
                addX(M, 0, i, j); // Menggunakan addX untuk enkapsulasi
            }
        }
    }
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
    for (i = 1; i <= 11; i++)
    {
        for (j = 1; j <= 11; j++)
        {
            printf("%d", M.cell[i][j]);
        }
    }
}

/* procedure viewMatriks (input M:Matriks)
    {I.S.: M terdefinisi}
    {F.S.: -}
    {Proses: menampilkan elemen M.cell yang terisi ke layar}
    {Contoh: jika ada elemen di [1][1]=10 dan [9][9]=20, maka:
     - nbaris=2, nkolom=2 (2 baris dan 2 kolom terisi)
     - viewMatriks akan menampilkan matriks 9x9 (dari baris 1-9, kolom 1-9)
     - posisi kosong ditampilkan dengan titik "."} */
void viewMatriks(Matriks M)
{
    // Kamus
    int i, j;
    int minBaris = 11, maxBaris = 0;
    int minKolom = 11, maxKolom = 0;
    boolean adaElemen = false;

    // Algoritma
    // Cari rentang baris dan kolom yang terisi
    for (i = 1; i <= 11; i++)
    {
        for (j = 1; j <= 11; j++)
        {
            if (M.cell[i][j] != -999)
            {
                adaElemen = true;
                if (i < minBaris)
                    minBaris = i;
                if (i > maxBaris)
                    maxBaris = i;
                if (j < minKolom)
                    minKolom = j;
                if (j > maxKolom)
                    maxKolom = j;
            }
        }
    }

    if (!adaElemen)
    {
        printf("Matrix is empty\n");
        return;
    }

    // Tampilkan matriks dalam rentang yang terisi
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
                printf("   . "); // Tampilkan titik untuk posisi kosong dalam rentang
            }
        }
        printf("\n");
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

    // Process all valid elements in both matrices
    for (i = 1; i <= 11; i++)
    {
        for (j = 1; j <= 11; j++)
        {
            // Only add if both elements are valid (not -999)
            if (M1.cell[i][j] != -999 && M2.cell[i][j] != -999)
            {
                addX(&M3, M1.cell[i][j] + M2.cell[i][j], i, j);
            }
            else if (M1.cell[i][j] != -999) // Only M1 has valid element
            {
                addX(&M3, M1.cell[i][j], i, j);
            }
            else if (M2.cell[i][j] != -999) // Only M2 has valid element
            {
                addX(&M3, M2.cell[i][j], i, j);
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

    // Process all valid elements in both matrices
    for (i = 1; i <= 11; i++)
    {
        for (j = 1; j <= 11; j++)
        {
            // Only subtract if both elements are valid (not -999)
            if (M1.cell[i][j] != -999 && M2.cell[i][j] != -999)
            {
                addX(&M3, M1.cell[i][j] - M2.cell[i][j], i, j);
            }
            else if (M1.cell[i][j] != -999) // Only M1 has valid element
            {
                addX(&M3, M1.cell[i][j], i, j);
            }
            else if (M2.cell[i][j] != -999) // Only M2 has valid element
            {
                addX(&M3, -M2.cell[i][j], i, j);
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
    int temp;
    Matriks M3;

    // Algoritma
    initMatriks(&M3);

    // Matrix multiplication: M1(n x m) * M2(m x p) = M3(n x p)
    // Only process valid elements based on actual matrix content
    for (i = 1; i <= 11; i++)
    {
        for (j = 1; j <= 11; j++)
        {
            temp = 0; // Initialize accumulator
            // Check if we can multiply this position
            boolean hasValidMultiplication = false;

            for (k = 1; k <= 11; k++)
            {
                if (M1.cell[i][k] != -999 && M2.cell[k][j] != -999)
                {
                    temp += M1.cell[i][k] * M2.cell[k][j];
                    hasValidMultiplication = true;
                }
            }

            // Only add to result if we had valid multiplication
            if (hasValidMultiplication)
            {
                addX(&M3, temp, i, j);
            }
        }
    }

    return M3;
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x)
{
    // Kamus
    int i, j;
    Matriks M3;

    // Algoritma
    initMatriks(&M3);

    // Process all valid elements in the matrix
    for (i = 1; i <= 11; i++)
    {
        for (j = 1; j <= 11; j++)
        {
            if (M1.cell[i][j] != -999)
            {
                addX(&M3, M1.cell[i][j] * x, i, j);
            }
        }
    }

    return M3;
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
    // For in-place transpose, we can only properly transpose square matrices
    // Use the larger dimension to ensure we don't miss any elements
    maxDim = ((*M).nbaris > (*M).nkolom) ? (*M).nbaris : (*M).nkolom;

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

    // Swap dimensions
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

    // Only process valid elements based on matrix dimensions
    for (i = 1; i <= M.nbaris; i++)
    {
        for (j = 1; j <= M.nkolom; j++)
        {
            MT.cell[j][i] = M.cell[i][j];
        }
    }
    MT.nbaris = M.nkolom;
    MT.nkolom = M.nbaris;
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
    if (!isFullMatriks(M) && M.nbaris + (2 * n) <= 11 && M.nkolom + (2 * n) <= 11)
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
    while (i <= 11 && !found && !isEmptyMatriks(M))
    {
        j = 1;
        while (j <= 11 && !found)
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

    // Only count elements within valid matrix dimensions
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