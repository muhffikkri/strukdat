/* Program   : main_program.c */
/* Deskripsi : Program simulasi penjadwalan proses CPU dengan algoritma Round Robin */
/* NIM/Nama  : 24060124130069/Muhammad Fikri */
/* Tanggal   : 5 Oktober 2025 */
/******************************************************************************/

#include <stdio.h>
#include "boolean.h"
#include "tproses.h"
#include "tqueue2.h"

/* Program PenjadwalanProsesCPU */
/* {program untuk mensimulasikan penjadwalan proses pada CPU menggunakan algoritma Round Robin} */

int main()
{
    // Kamus
    tqueue2 Q;                  // antrian proses di CPU
    tproses P1, P2, P3, P4, P5; // 5 proses yang akan dijadwalkan
    tproses currentProses;      // proses yang sedang dieksekusi
    int quantumTime = 5;        // quantum time untuk Round Robin
    int currentTime = 0;        // waktu sistem saat ini
    int processCount = 1;       // counter untuk nomor eksekusi
    int startTime = currentTime;
    int executionTime;

    // Algoritma
    printf("=== SIMULASI PENJADWALAN PROSES CPU - ROUND ROBIN ===\n");
    printf("NIM: 24060124130069\n");
    printf("Quantum Time: %d satuan waktu\n\n", quantumTime);

    // Pembentukan 5 proses berdasarkan 5 digit terakhir NIM: 30069
    printf("=== PEMBENTUKAN PROSES BERDASARKAN NIM ===\n");
    printf("5 digit terakhir NIM: 30069\n");

    createProses(&P1, 'A', 3); // Proses A: BT = 3
    printf("Proses A: BT = 3\n");

    createProses(&P2, 'B', 6); // Proses B: BT = 0 -> 3+3 = 6
    printf("Proses B: BT = 0 -> 3+3 = 6\n");

    createProses(&P3, 'C', 9); // Proses C: BT = 0 -> 6+3 = 9
    printf("Proses C: BT = 0 -> 6+3 = 9\n");

    createProses(&P4, 'D', 6); // Proses D: BT = 6
    printf("Proses D: BT = 6\n");

    createProses(&P5, 'E', 9); // Proses E: BT = 9
    printf("Proses E: BT = 9\n\n");

    createQueue2(&Q);

    printf("=== URUTAN KEDATANGAN PROSES ===\n");
    enqueue2(&Q, P1);
    printf("Proses A masuk antrian (BT: 3)\n");

    enqueue2(&Q, P2);
    printf("Proses B masuk antrian (BT: 6)\n");

    enqueue2(&Q, P3);
    printf("Proses C masuk antrian (BT: 9)\n");

    enqueue2(&Q, P4);
    printf("Proses D masuk antrian (BT: 6)\n");

    enqueue2(&Q, P5);
    printf("Proses E masuk antrian (BT: 9)\n\n");

    printf("=== ANTRIAN PROSES AWAL ===\n");
    viewQueue2(Q);
    printf("\n");

    printf("=== SIMULASI EKSEKUSI DENGAN ROUND ROBIN ===\n");
    printf("Eksekusi | Proses | Waktu Mulai | Waktu Selesai | Burst Time Sisa\n");
    printf("---------|--------|-------------|---------------|----------------\n");

    while (!isEmptyQueue2(Q))
    {
        dequeue2(&Q, &currentProses);

        startTime = currentTime;

        if (burstTime(currentProses) <= quantumTime)
        {
            executionTime = burstTime(currentProses);
            currentProses.burstTime = 0;
        }
        else
        {
            executionTime = quantumTime;
            currentProses.burstTime = burstTime(currentProses) - quantumTime;
        }

        currentTime = currentTime + executionTime;

        printf("   %-6d| %-6c | %-11d | %-13d | %-14d\n",
               processCount, currentProses.idProses, startTime, currentTime, currentProses.burstTime);

        processCount++;

        if (currentProses.burstTime > 0)
        {
            enqueue2(&Q, currentProses);
        }
    }

    printf("\n=== SIMULASI SELESAI ===\n");
    printf("Total waktu eksekusi: %d satuan waktu\n", currentTime);
    printf("Semua proses telah selesai dieksekusi.\n");

    return 0;
}