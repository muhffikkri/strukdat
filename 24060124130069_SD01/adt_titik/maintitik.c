/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060124130069/Muhammad Fikri */
/* Tanggal   : 04 September 2025 */
/***********************************/
#include <stdio.h>
#include "titik.c"

int main()
{
	// kamus main
	Titik T1;

	// algoritma
	printf("Halo, ini driver modul Titik");
	printf("\nMakeTitik T1");
	makeTitik(&T1, 4, 5);

	printf("\n");

	printf("\nNilai absis = %d", getAbsis(T1));
	printf("\nNilai ordinat = %d", getOrdinat(T1));

	printf("\n");

	printf("\nMakeTitik0 T1");
	makeTitik0(&T1);
	printf("\nNilai absis = %d", getAbsis(T1));
	printf("\nNilai ordinat = %d", getOrdinat(T1));

	printf("\n");

	setAbsis(&T1, 2);
	setOrdinat(&T1, 2);
	printf("\nSetAbsis T1->2");
	printf("\nSetOrdinat T1->2");
	printf("\nNilai absis = %d", getAbsis(T1));
	printf("\nNilai ordinat = %d", getOrdinat(T1));

	printf("\n");

	printf("\nisOrigin %d", isOrigin(T1));
	printf("\nisOnSumbuX %d", isOnSumbuX(T1));
	printf("\nisOnSumbuY %d", isOnSumbuY(T1));
	Titik T2;
	makeTitik(&T2, 2, 2);
	printf("\nisEqual %d", isEqual(T1, T2));

	printf("\n");

	geser(&T1, 2, 3);
	printf("\nGeser T1->2");
	printf("\nNilai absis = %d", getAbsis(T1));
	printf("\nNilai ordinat = %d", getOrdinat(T1));

	printf("\n");

	refleksiX(&T1);
	printf("\nRelfeksiX T1");
	printf("\nNilai absis = %d", getAbsis(T1));
	printf("\nNilai ordinat = %d", getOrdinat(T1));

	printf("\n");

	refleksiY(&T1);
	printf("\nRelfeksiY T1");
	printf("\nNilai absis = %d", getAbsis(T1));
	printf("\nNilai ordinat = %d", getOrdinat(T1));

	printf("\n");

	dilatasi(&T2, 2);
	printf("\nDilatasi T2->2");
	printf("\nNilai absis = %d", getAbsis(T2));
	printf("\nNilai ordinat = %d", getOrdinat(T2));

	printf("\n");

	Titik T3;
	printf("\nMakeTitik T3");
	makeTitik(&T3, 1, 1);
	printf("\nNilai absis = %d", getAbsis(T3));
	printf("\nNilai ordinat = %d", getOrdinat(T3));

	dilatasiX(&T2, T3, 2);
	printf("\nDilatasiX T2.absis->2 dengan T3");
	printf("\nNilai absis = %d", getAbsis(T2));
	printf("\nNilai ordinat = %d", getOrdinat(T2));

	printf("\n");

	printf("\nKuadran T1 %d", kuadran(T1));
	printf("\nNilai absis = %d", getAbsis(T1));
	printf("\nNilai ordinat = %d", getOrdinat(T1));

	return 0;
}
