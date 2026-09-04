/*Nama file: main.c  */
/*Deskripsi: Program testing ADT bintree3   */
/*Tanggal  : 14 Desember 2025  */
/*Pembuat  : Muhammad Fikri   */
#include <stdio.h>
#include <stdlib.h>
#include "pohon3.h"

int main()
{
      // kamus
      bintree3 W, W2, W3, PEmpty;
      List1 L1, L2, L3, L4, ListA, ListB, ListC, ListD, ListE;
      int tinggi, level, nbElm, nbDaun;

      // algoritma
      printf("Membuat pohon W:\n");
      printf("       A\n");
      printf("      / \\\n");
      printf("     B   C\n");
      printf("      \\   / \\\n");
      printf("       D E   F\n\n");

      W = Tree3(NIL, 'A', false,
                Tree3(NIL, 'B', false,
                      NIL,
                      Tree3(NIL, 'D', false, NIL, NIL)),
                Tree3(NIL, 'C', false,
                      Tree3(NIL, 'E', false, NIL, NIL),
                      Tree3(NIL, 'F', false, NIL, NIL)));

      printf("Test IsEmptyTree pada W: ");
      if (IsEmptyTree(W))
      {
            printf("Pohon kosong\n");
      }
      else
      {
            printf("Pohon tidak kosong\n");
      }

      printf("\nTest printDFS (Depth First Search):\n");
      printf("W = ");
      printDFS(W);
      printf("\n");

      printf("\nTest PrintBFS (Breadth First Search):\n");
      printf("W = ");
      PrintBFS(W);
      printf("\n");

      printf("\nTest Tinggi pohon W: ");
      tinggi = Tinggi(W);
      printf("%d\n", tinggi);

      printf("\nTest Level pohon W: ");
      level = Level(W);
      printf("%d\n", level);

      printf("\nTest NbElmTree pohon W: ");
      nbElm = NbElmTree(W);
      printf("%d\n", nbElm);

      printf("\nTest NbDaun pohon W: ");
      nbDaun = NbDaun(W);
      printf("%d\n", nbDaun);

      printf("\nTest PrintLevel untuk setiap level:\n");
      printf("Level 0: ");
      PrintLevel(W, 0);
      printf("\nLevel 1: ");
      PrintLevel(W, 1);
      printf("\nLevel 2: ");
      PrintLevel(W, 2);
      printf("\n");

      printf("\nTest CountLevelT untuk setiap level:\n");
      printf("Jumlah node di level 0: %d\n", CountLevelT(W, 0));
      printf("Jumlah node di level 1: %d\n", CountLevelT(W, 1));
      printf("Jumlah node di level 2: %d\n", CountLevelT(W, 2));

      printf("\nTest IsDaun, IsBiner, IsUnerLeft, IsUnerRight:\n");
      printf("Node A - IsDaun: %d, IsBiner: %d\n", IsDaun(W), IsBiner(W));
      printf("Node B - IsDaun: %d, IsUnerRight: %d\n", IsDaun(left(W)), IsUnerRight(left(W)));
      printf("Node C - IsDaun: %d, IsBiner: %d\n", IsDaun(right(W)), IsBiner(right(W)));
      printf("Node D - IsDaun: %d\n", IsDaun(right(left(W))));

      printf("\nTest printPathX untuk mencari node D:\n");
      printf("Path dari A ke D: ");
      printPathX(W, 'D');
      printf("\n");

      printf("\nTest printPathDaunX untuk mencari daun D:\n");
      printf("Path dari A ke daun D: ");
      printPathDaunX(W, 'D');
      printf("\n");

      printf("\nTest printAllPaths untuk menampilkan semua jalur:\n");
      printf("Semua jalur dari akar ke daun:\n");
      printAllPaths(W);

      printf("\nTest resetVisited:\n");
      visited(W) = true;
      visited(left(W)) = true;
      printf("Sebelum reset - visited A: %d, visited B: %d\n", visited(W), visited(left(W)));
      resetVisited(W);
      printf("Setelah reset - visited A: %d, visited B: %d\n", visited(W), visited(left(W)));

      printf("\n=== TEST LINEARISASI POHON ===\n");

      printf("\nTest LinearPrefix (Akar-Kiri-Kanan):\n");
      L1 = LinearPrefix(W);
      printf("Hasil LinearPrefix:");
      PrintList(L1);
      printf("\n");

      printf("\nTest LinearPosfix (Kiri-Kanan-Akar):\n");
      L2 = LinearPosfix(W);
      printf("Hasil LinearPosfix:");
      PrintList(L2);
      printf("\n");

      printf("\nTest LinearInfix (Kiri-Akar-Kanan):\n");
      L3 = LinearInfix(W);
      printf("Hasil LinearInfix:");
      PrintList(L3);
      printf("\n");

      printf("\nTest LinearBreadthFS (Level demi Level):\n");
      L4 = LinearBreadthFS(W);
      printf("Hasil LinearBreadthFS:");
      PrintList(L4);
      printf("\n");

      printf("\n=== TEST OPERASI LIST ===\n");

      printf("\nTest Pconcat:\n");
      CreateList(&ListA);
      CreateList(&ListB);
      InsertVLast(&ListA, 'X');
      InsertVLast(&ListA, 'Y');
      InsertVLast(&ListB, 'Z');
      InsertVLast(&ListB, 'W');
      printf("List A sebelum concat:");
      PrintList(ListA);
      printf("\nList B:");
      PrintList(ListB);
      Pconcat(&ListA, ListB);
      printf("\nList A setelah concat:");
      PrintList(ListA);
      printf("\n");

      printf("\nTest Fconcat:\n");
      CreateList(&ListC);
      CreateList(&ListD);
      InsertVLast(&ListC, 'M');
      InsertVLast(&ListC, 'N');
      InsertVLast(&ListD, 'O');
      InsertVLast(&ListD, 'P');
      printf("List C:");
      PrintList(ListC);
      printf("\nList D:");
      PrintList(ListD);
      ListE = Fconcat(ListC, ListD);
      printf("\nList E hasil concat:");
      PrintList(ListE);
      printf("\nList C tetap:");
      PrintList(ListC);
      printf("\nList D tetap:");
      PrintList(ListD);
      printf("\n");

      printf("\n=== TEST POHON LAIN ===\n");

      printf("\nMembuat pohon W2 (hanya satu node):\n");
      W2 = Tree3(NIL, 'R', false, NIL, NIL);
      printf("Test IsDaun W2: %d\n", IsDaun(W2));
      printf("Test Tinggi W2: %d\n", Tinggi(W2));
      printf("Test Level W2: %d\n", Level(W2));
      printf("printDFS W2: ");
      printDFS(W2);
      printf("\n");

      printf("\nMembuat pohon W3 (pohon linear kiri):\n");
      printf("   A\n");
      printf("  /\n");
      printf(" B\n");
      printf("/\n");
      printf("C\n");
      W3 = Tree3(NIL, 'A', false,
                 Tree3(NIL, 'B', false,
                       Tree3(NIL, 'C', false, NIL, NIL),
                       NIL),
                 NIL);
      printf("Test IsUnerLeft W3: %d\n", IsUnerLeft(W3));
      printf("Test Tinggi W3: %d\n", Tinggi(W3));
      printf("printDFS W3: ");
      printDFS(W3);
      printf("\n");
      printf("PrintBFS W3: ");
      PrintBFS(W3);
      printf("\n");

      printf("\nTest IsEmptyTree pada pohon NIL: ");
      PEmpty = NIL;
      if (IsEmptyTree(PEmpty))
      {
            printf("Benar, pohon kosong\n");
      }
      else
      {
            printf("Salah\n");
      }

      return 0;
}