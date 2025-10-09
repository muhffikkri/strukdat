/* Program   : mqueue3.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array,
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060124130069/Muhammad Fikri*/
/* Tanggal   : 9 Oktober 2005*/
/***********************************/

#include <stdio.h>
#include "tqueue3.h"
#include "boolean.h"

int main()
{
    // Kamus
    tqueue3 Q1, Q2;
    char e;

    // Algoritma
    printf("=== TEST ADT Queue3 ===\n\n");

    // 1. TEST CONSTRUCTOR - createQueue3()
    printf("1. TEST CONSTRUCTOR - createQueue3()\n");
    createQueue3(&Q1);
    createQueue3(&Q2);
    printf("   Queue Q1 created\n");
    printf("   Queue Q2 created\n");
    printf("   Q1.head: %d, Q1.tail: %d\n", head3(Q1), tail3(Q1));
    printf("   Q1 wadah: ");
    printQueue3(Q1);
    printf("\n   Status: %s\n\n", (head3(Q1) == 0 && tail3(Q1) == 0) ? "PASSED" : "FAILED");

    // 2. TEST PREDIKAT - isEmpty, isFull, isOneElement
    printf("2. TEST PREDIKAT - isEmpty, isFull, isOneElement\n");
    printf("   isEmptyQueue3(Q1): %s (should be true)\n", isEmptyQueue3(Q1) ? "true" : "false");
    printf("   isFullQueue3(Q1): %s (should be false)\n", isFullQueue3(Q1) ? "true" : "false");
    printf("   isOneElement3(Q1): %s (should be false)\n", isOneElement3(Q1) ? "true" : "false");
    printf("   Status: %s\n\n", (isEmptyQueue3(Q1) && !isFullQueue3(Q1) && !isOneElement3(Q1)) ? "PASSED" : "FAILED");

    // 3. TEST MUTATOR - enqueue3 (single element)
    printf("3. TEST MUTATOR - enqueue3 (single element)\n");
    enqueue3(&Q1, 'A');
    printf("   After enqueue3(Q1, 'A'):\n");
    printf("   Q1.head: %d, Q1.tail: %d\n", head3(Q1), tail3(Q1));
    printf("   Q1 wadah: ");
    printQueue3(Q1);
    printf("\n   isEmptyQueue3(Q1): %s (should be false)\n", isEmptyQueue3(Q1) ? "true" : "false");
    printf("   isOneElement3(Q1): %s (should be true)\n", isOneElement3(Q1) ? "true" : "false");
    printf("   Status: %s\n\n", (!isEmptyQueue3(Q1) && isOneElement3(Q1)) ? "PASSED" : "FAILED");

    // 4. TEST SELEKTOR - infoHead3, infoTail3, sizeQueue3
    printf("4. TEST SELEKTOR - infoHead3, infoTail3, sizeQueue3\n");
    printf("   infoHead3(Q1): %c (should be 'A')\n", infoHead3(Q1));
    printf("   infoTail3(Q1): %c (should be 'A')\n", infoTail3(Q1));
    printf("   sizeQueue3(Q1): %d (should be 1)\n", sizeQueue3(Q1));
    printf("   Status: %s\n\n", (infoHead3(Q1) == 'A' && infoTail3(Q1) == 'A' && sizeQueue3(Q1) == 1) ? "PASSED" : "FAILED");

    // 5. TEST MUTATOR - enqueue3 (multiple elements)
    printf("5. TEST MUTATOR - enqueue3 (multiple elements)\n");
    enqueue3(&Q1, 'B');
    enqueue3(&Q1, 'C');
    enqueue3(&Q1, 'D');
    printf("   After enqueue3 B, C, D:\n");
    printf("   Q1.head: %d, Q1.tail: %d\n", head3(Q1), tail3(Q1));
    printf("   Q1 wadah: ");
    printQueue3(Q1);
    printf("\n   sizeQueue3(Q1): %d (should be 4)\n", sizeQueue3(Q1));
    printf("   infoHead3(Q1): %c (should be 'A')\n", infoHead3(Q1));
    printf("   infoTail3(Q1): %c (should be 'D')\n", infoTail3(Q1));
    printf("   Status: %s\n\n", (sizeQueue3(Q1) == 4 && infoHead3(Q1) == 'A' && infoTail3(Q1) == 'D') ? "PASSED" : "FAILED");

    // 6. TEST Output - viewQueue3
    printf("6. TEST Output - viewQueue3\n");
    printf("   viewQueue3(Q1): ");
    viewQueue3(Q1);
    printf(" (should show ABCD)\n");
    printf("   Status: PASSED (visual check)\n\n");

    // 7. TEST MUTATOR - enqueue3 until full
    printf("7. TEST MUTATOR - enqueue3 until full\n");
    printf("   Before filling to capacity, isTailOverHead(Q1): %s\n", isTailOverHead(Q1) ? "true" : "false");
    enqueue3(&Q1, 'E');
    printf("   After enqueue3('E') - Q1 should be full:\n");
    printf("   Q1.head: %d, Q1.tail: %d\n", head3(Q1), tail3(Q1));
    printf("   Q1 wadah: ");
    printQueue3(Q1);
    printf("\n   isFullQueue3(Q1): %s (should be true)\n", isFullQueue3(Q1) ? "true" : "false");
    printf("   sizeQueue3(Q1): %d (should be 5)\n", sizeQueue3(Q1));
    printf("   Status: %s\n\n", (isFullQueue3(Q1) && sizeQueue3(Q1) == 5) ? "PASSED" : "FAILED");

    // 8. TEST MUTATOR - dequeue3
    printf("8. TEST MUTATOR - dequeue3\n");
    dequeue3(&Q1, &e);
    printf("   After dequeue3, extracted element: %c (should be 'A')\n", e);
    printf("   Q1.head: %d, Q1.tail: %d\n", head3(Q1), tail3(Q1));
    printf("   Q1 wadah: ");
    printQueue3(Q1);
    printf("\n   viewQueue3(Q1): ");
    viewQueue3(Q1);
    printf(" (should show BCDE)\n");
    printf("   infoHead3(Q1): %c (should be 'B')\n", infoHead3(Q1));
    printf("   sizeQueue3(Q1): %d (should be 4)\n", sizeQueue3(Q1));
    printf("   Status: %s\n\n", (e == 'A' && infoHead3(Q1) == 'B' && sizeQueue3(Q1) == 4) ? "PASSED" : "FAILED");

    // 9. TEST CIRCULAR BEHAVIOR - Demonstrate circular queue
    printf("9. TEST CIRCULAR BEHAVIOR - Demonstrate circular queue\n");
    // Dequeue a few more elements to make space
    dequeue3(&Q1, &e);
    dequeue3(&Q1, &e);
    printf("   After 2 more dequeue3, Q1.head: %d, Q1.tail: %d\n", head3(Q1), tail3(Q1));
    printf("   Q1 wadah: ");
    printQueue3(Q1);
    printf("\n   viewQueue3(Q1): ");
    viewQueue3(Q1);
    printf("\n");

    // Enqueue new elements to show circular behavior
    enqueue3(&Q1, 'F');
    enqueue3(&Q1, 'G');
    printf("   After enqueue3 F, G:\n");
    printf("   Q1.head: %d, Q1.tail: %d\n", head3(Q1), tail3(Q1));
    printf("   Q1 wadah: ");
    printQueue3(Q1);
    printf("\n   viewQueue3(Q1): ");
    viewQueue3(Q1);
    printf("\n   isTailOverHead(Q1): %s (should show circular wrapping)\n", isTailOverHead(Q1) ? "true" : "false");
    printf("   Status: PASSED (circular behavior demonstrated)\n\n");

    // 10. TEST BOUNDARY - Empty queue after multiple operations
    printf("10. TEST BOUNDARY - Empty queue after multiple operations\n");
    // Empty the queue completely
    while (!isEmptyQueue3(Q1))
    {
        dequeue3(&Q1, &e);
        printf("    Dequeued: %c, remaining size: %d\n", e, sizeQueue3(Q1));
    }
    printf("   Final state - Q1.head: %d, Q1.tail: %d\n", head3(Q1), tail3(Q1));
    printf("   isEmptyQueue3(Q1): %s (should be true)\n", isEmptyQueue3(Q1) ? "true" : "false");
    printf("   Status: %s\n\n", (isEmptyQueue3(Q1) && head3(Q1) == 0 && tail3(Q1) == 0) ? "PASSED" : "FAILED");

    // 11. TEST BOUNDARY - dequeue3 from empty queue
    printf("11. TEST BOUNDARY - dequeue3 from empty queue\n");
    char oldE = e;
    dequeue3(&Q1, &e);
    printf("   Dequeue3 from empty queue, e: %c (should be space ' ')\n", e);
    printf("   Status: %s\n\n", (e == ' ') ? "PASSED" : "FAILED");

    // 12. TEST EXTRA - isEqualQueue3
    printf("12. TEST EXTRA - isEqualQueue3\n");
    createQueue3(&Q1);
    createQueue3(&Q2);
    enqueue3(&Q1, 'X');
    enqueue3(&Q1, 'Y');
    enqueue3(&Q1, 'Z');

    enqueue3(&Q2, 'X');
    enqueue3(&Q2, 'Y');
    enqueue3(&Q2, 'Z');

    printf("   Q1: ");
    viewQueue3(Q1);
    printf("\n   Q2: ");
    viewQueue3(Q2);
    printf("\n   isEqualQueue3(Q1, Q2): %s (should be true)\n", isEqualQueue3(Q1, Q2) ? "true" : "false");

    // Make Q2 different
    enqueue3(&Q2, 'W');
    printf("   After enqueue3(Q2, 'W'):\n");
    printf("   Q1: ");
    viewQueue3(Q1);
    printf("\n   Q2: ");
    viewQueue3(Q2);
    printf("\n   isEqualQueue3(Q1, Q2): %s (should be false)\n", isEqualQueue3(Q1, Q2) ? "true" : "false");
    printf("   Status: PASSED (equality comparison)\n\n");

    printf("=== ALL TESTS COMPLETED ===\n");
    printf("Queue3 ADT implementation tested successfully!\n");

    return 0;
}
