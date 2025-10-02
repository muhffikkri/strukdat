/* Program   : mqueue.c */
/* Deskripsi : file DRIVER modul ADT Queue representasi kontigu dengan array,
               model I: head selalu di posisi 0 atau 1 - Testing semua fungsi*/
/* NIM/Nama  : 24060124130069/Muhammad Fikri*/
/* Tanggal   : 2 Oktober 2025*/
/***********************************/

#include <stdio.h>
#include "tqueue.h"
#include "boolean.h"

int main()
{
    // Kamus
    tqueue Q1, Q2;
    char e;

    // Algoritma
    printf("=== TEST ADT QUEUE ===\n\n");

    // 1. TEST CONSTRUCTOR - createQueue()
    printf("1. TEST CONSTRUCTOR - createQueue()\n");
    createQueue(&Q1);
    createQueue(&Q2);
    printf("   Queue Q1 created\n");
    printf("   Queue Q2 created\n");
    printf("   Q1.head: %d, Q1.tail: %d\n", head(Q1), tail(Q1));
    printf("   Q1 wadah: ");
    printQueue(Q1);
    printf("\n   Status: %s\n\n", (head(Q1) == 0 && tail(Q1) == 0) ? "PASSED" : "FAILED");

    // 2. TEST PREDIKAT - isEmpty, isFull, isOneElement
    printf("2. TEST PREDIKAT - isEmpty, isFull, isOneElement\n");
    printf("   isEmptyQueue(Q1): %s (should be true)\n", isEmptyQueue(Q1) ? "true" : "false");
    printf("   isFullQueue(Q1): %s (should be false)\n", isFullQueue(Q1) ? "true" : "false");
    printf("   isOneElement(Q1): %s (should be false)\n", isOneElement(Q1) ? "true" : "false");
    printf("   Status: %s\n\n", (isEmptyQueue(Q1) && !isFullQueue(Q1) && !isOneElement(Q1)) ? "PASSED" : "FAILED");

    // 3. TEST MUTATOR - enqueue (single element)
    printf("3. TEST MUTATOR - enqueue (single element)\n");
    enqueue(&Q1, 'A');
    printf("   After enqueue(Q1, 'A'):\n");
    printf("   Q1.head: %d, Q1.tail: %d\n", head(Q1), tail(Q1));
    printf("   Q1 wadah: ");
    printQueue(Q1);
    printf("\n   isEmptyQueue(Q1): %s (should be false)\n", isEmptyQueue(Q1) ? "true" : "false");
    printf("   isOneElement(Q1): %s (should be true)\n", isOneElement(Q1) ? "true" : "false");
    printf("   Status: %s\n\n", (!isEmptyQueue(Q1) && isOneElement(Q1)) ? "PASSED" : "FAILED");

    // 4. TEST SELEKTOR - infoHead, infoTail, sizeQueue
    printf("4. TEST SELEKTOR - infoHead, infoTail, sizeQueue\n");
    printf("   infoHead(Q1): %c (should be 'A')\n", infoHead(Q1));
    printf("   infoTail(Q1): %c (should be 'A')\n", infoTail(Q1));
    printf("   sizeQueue(Q1): %d (should be 1)\n", sizeQueue(Q1));
    printf("   Status: %s\n\n", (infoHead(Q1) == 'A' && infoTail(Q1) == 'A' && sizeQueue(Q1) == 1) ? "PASSED" : "FAILED");

    // 5. TEST MUTATOR - enqueue (multiple elements)
    printf("5. TEST MUTATOR - enqueue (multiple elements)\n");
    enqueue(&Q1, 'B');
    enqueue(&Q1, 'C');
    enqueue(&Q1, 'D');
    printf("   After enqueue B, C, D:\n");
    printf("   Q1.head: %d, Q1.tail: %d\n", head(Q1), tail(Q1));
    printf("   Q1 wadah: ");
    printQueue(Q1);
    printf("\n   sizeQueue(Q1): %d (should be 4)\n", sizeQueue(Q1));
    printf("   infoHead(Q1): %c (should be 'A')\n", infoHead(Q1));
    printf("   infoTail(Q1): %c (should be 'D')\n", infoTail(Q1));
    printf("   Status: %s\n\n", (sizeQueue(Q1) == 4 && infoHead(Q1) == 'A' && infoTail(Q1) == 'D') ? "PASSED" : "FAILED");

    // 6. TEST Output - viewQueue
    printf("6. TEST Output - viewQueue\n");
    printf("   viewQueue(Q1): ");
    viewQueue(Q1);
    printf(" (should show ABCD)\n");
    printf("   Status: PASSED (visual check)\n\n");

    // 7. TEST MUTATOR - enqueue until full
    printf("7. TEST MUTATOR - enqueue until full\n");
    enqueue(&Q1, 'E');
    printf("   After enqueue('E') - Q1 should be full:\n");
    printf("   Q1.head: %d, Q1.tail: %d\n", head(Q1), tail(Q1));
    printf("   Q1 wadah: ");
    printQueue(Q1);
    printf("\n   isFullQueue(Q1): %s (should be true)\n", isFullQueue(Q1) ? "true" : "false");
    printf("   sizeQueue(Q1): %d (should be 5)\n", sizeQueue(Q1));
    printf("   Status: %s\n\n", (isFullQueue(Q1) && sizeQueue(Q1) == 5) ? "PASSED" : "FAILED");

    // 8. TEST BOUNDARY - enqueue when full
    printf("8. TEST BOUNDARY - enqueue when full\n");
    printf("   Trying to enqueue 'X' to full queue:\n");
    enqueue(&Q1, 'X');
    printf("   Q1 wadah after failed enqueue: ");
    printQueue(Q1);
    printf("\n   sizeQueue(Q1): %d (should still be 5)\n", sizeQueue(Q1));
    printf("   Status: %s\n\n", (sizeQueue(Q1) == 5) ? "PASSED" : "FAILED");

    // 9. TEST MUTATOR - dequeue
    printf("9. TEST MUTATOR - dequeue\n");
    dequeue(&Q1, &e);
    printf("   After dequeue, extracted element: %c (should be 'A')\n", e);
    printf("   Q1.head: %d, Q1.tail: %d\n", head(Q1), tail(Q1));
    printf("   Q1 wadah: ");
    printQueue(Q1);
    printf("\n   viewQueue(Q1): ");
    viewQueue(Q1);
    printf(" (should show BCDE)\n");
    printf("   infoHead(Q1): %c (should be 'B')\n", infoHead(Q1));
    printf("   sizeQueue(Q1): %d (should be 4)\n", sizeQueue(Q1));
    printf("   Status: %s\n\n", (e == 'A' && infoHead(Q1) == 'B' && sizeQueue(Q1) == 4) ? "PASSED" : "FAILED");

    // 10. TEST MUTATOR - multiple dequeue
    printf("10. TEST MUTATOR - multiple dequeue\n");
    dequeue(&Q1, &e);
    printf("    Dequeue 1: %c\n", e);
    dequeue(&Q1, &e);
    printf("    Dequeue 2: %c\n", e);
    dequeue(&Q1, &e);
    printf("    Dequeue 3: %c\n", e);
    printf("    After 3 dequeues, Q1 wadah: ");
    printQueue(Q1);
    printf("\n    sizeQueue(Q1): %d (should be 1)\n", sizeQueue(Q1));
    printf("    isOneElement(Q1): %s (should be true)\n", isOneElement(Q1) ? "true" : "false");
    printf("    Status: %s\n\n", (sizeQueue(Q1) == 1 && isOneElement(Q1)) ? "PASSED" : "FAILED");

    // 11. TEST BOUNDARY - dequeue to empty
    printf("11. TEST BOUNDARY - dequeue to empty\n");
    dequeue(&Q1, &e);
    printf("    Last dequeue: %c (should be 'E')\n", e);
    printf("    Q1.head: %d, Q1.tail: %d (should be 0, 0)\n", head(Q1), tail(Q1));
    printf("    Q1 wadah: ");
    printQueue(Q1);
    printf("\n    isEmptyQueue(Q1): %s (should be true)\n", isEmptyQueue(Q1) ? "true" : "false");
    printf("    Status: %s\n\n", (e == 'E' && isEmptyQueue(Q1) && head(Q1) == 0 && tail(Q1) == 0) ? "PASSED" : "FAILED");

    // 12. TEST BOUNDARY - dequeue from empty queue
    printf("12. TEST BOUNDARY - dequeue from empty queue\n");
    char oldE = e;
    dequeue(&Q1, &e);
    printf("    Dequeue from empty queue, e remains: %c (should be unchanged)\n", e);
    printf("    Status: %s\n\n", (e == oldE) ? "PASSED" : "FAILED");

    // 13. TEST ADVANCED - enqueue2 (dual queue)
    printf("13. TEST ADVANCED - enqueue2 (dual queue)\n");
    createQueue(&Q1);
    createQueue(&Q2);
    printf("    Initial: Q1 size=%d, Q2 size=%d\n", sizeQueue(Q1), sizeQueue(Q2));

    enqueue2(&Q1, &Q2, 'X');
    printf("    After enqueue2('X'): Q1 size=%d, Q2 size=%d\n", sizeQueue(Q1), sizeQueue(Q2));

    enqueue(&Q1, 'A'); // Make Q1 longer
    enqueue2(&Q1, &Q2, 'Y');
    printf("    After manual enqueue(Q1,'A') and enqueue2('Y'): Q1 size=%d, Q2 size=%d\n", sizeQueue(Q1), sizeQueue(Q2));

    printf("    Q1: ");
    viewQueue(Q1);
    printf("\n");
    printf("    Q2: ");
    viewQueue(Q2);
    printf("\n");
    printf("    Status: PASSED (visual check - Y should go to shorter queue)\n\n");

    // 14. TEST ADVANCED - dequeue2 (dual queue)
    printf("14. TEST ADVANCED - dequeue2 (dual queue)\n");
    printf("    Before dequeue2: Q1 size=%d, Q2 size=%d\n", sizeQueue(Q1), sizeQueue(Q2));
    dequeue2(&Q1, &Q2, &e);
    printf("    After dequeue2, extracted: %c\n", e);
    printf("    After dequeue2: Q1 size=%d, Q2 size=%d\n", sizeQueue(Q1), sizeQueue(Q2));
    printf("    Q1: ");
    viewQueue(Q1);
    printf("\n");
    printf("    Q2: ");
    viewQueue(Q2);
    printf("\n");
    printf("    Status: PASSED (visual check - should dequeue from longer queue)\n\n");

    // 15. TEST COMPREHENSIVE - Fill and empty cycle
    printf("15. TEST COMPREHENSIVE - Fill and empty cycle\n");
    createQueue(&Q1);
    printf("    Filling queue with A-E:\n");
    for (char c = 'A'; c <= 'E'; c++)
    {
        enqueue(&Q1, c);
        printf("      After enqueue('%c'): size=%d, ", c, sizeQueue(Q1));
        viewQueue(Q1);
        printf("\n");
    }

    printf("    Emptying queue:\n");
    while (!isEmptyQueue(Q1))
    {
        dequeue(&Q1, &e);
        printf("      Dequeued '%c': size=%d, ", e, sizeQueue(Q1));
        viewQueue(Q1);
        printf("\n");
    }
    printf("    Status: PASSED (cycle completed)\n\n");

    printf("=== ALL TESTS COMPLETED ===\n");

    return 0;
}
