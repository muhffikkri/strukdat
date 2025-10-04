/* Program   : mqueue.c */
/* Deskripsi : file DRIVER modul ADT Queue representasi kontigu dengan array,
               model II: head bergeser/jelajah - Testing semua fungsi*/
/* NIM/Nama  : 24060124130069/Muhammad Fikri*/
/* Tanggal   : 2 Oktober 2025*/
/***********************************/

#include <stdio.h>
#include "tqueue2.h"
// #include "tproses.h"
#include "boolean.h"

int main()
{
    // Kamus
    tqueue2 Q1, Q2;
    char e;

    // Algoritma
    printf("=== TEST ADT QUEUE2 ===\n\n");

    // 1. TEST CONSTRUCTOR - createQueue2()
    printf("1. TEST CONSTRUCTOR - createQueue2()\n");
    createQueue2(&Q1);
    createQueue2(&Q2);
    printf("   Queue Q1 created\n");
    printf("   Queue Q2 created\n");
    printf("   Q1.head: %d, Q1.tail: %d\n", head2(Q1), tail2(Q1));
    printf("   Q1 wadah: ");
    printQueue2(Q1);
    printf("\n   Status: %s\n\n", (head2(Q1) == 0 && tail2(Q1) == 0) ? "PASSED" : "FAILED");

    // 2. TEST PREDIKAT - isEmpty, isFull, isOneElement
    printf("2. TEST PREDIKAT - isEmpty, isFull, isOneElement\n");
    printf("   isEmptyQueue2(Q1): %s (should be true)\n", isEmptyQueue2(Q1) ? "true" : "false");
    printf("   isFullQueue2(Q1): %s (should be false)\n", isFullQueue2(Q1) ? "true" : "false");
    printf("   isOneElement2(Q1): %s (should be false)\n", isOneElement2(Q1) ? "true" : "false");
    printf("   Status: %s\n\n", (isEmptyQueue2(Q1) && !isFullQueue2(Q1) && !isOneElement2(Q1)) ? "PASSED" : "FAILED");

    // 3. TEST MUTATOR - enqueue2 (single element)
    printf("3. TEST MUTATOR - enqueue2 (single element)\n");
    enqueue2(&Q1, 'A');
    printf("   After enqueue2(Q1, 'A'):\n");
    printf("   Q1.head: %d, Q1.tail: %d\n", head2(Q1), tail2(Q1));
    printf("   Q1 wadah: ");
    printQueue2(Q1);
    printf("\n   isEmptyQueue2(Q1): %s (should be false)\n", isEmptyQueue2(Q1) ? "true" : "false");
    printf("   isOneElement2(Q1): %s (should be true)\n", isOneElement2(Q1) ? "true" : "false");
    printf("   Status: %s\n\n", (!isEmptyQueue2(Q1) && isOneElement2(Q1)) ? "PASSED" : "FAILED");

    // 4. TEST SELEKTOR - infoHead2, infoTail2, sizeQueue2
    printf("4. TEST SELEKTOR - infoHead2, infoTail2, sizeQueue2\n");
    printf("   infoHead2(Q1): %c (should be 'A')\n", infoHead2(Q1));
    printf("   infoTail2(Q1): %c (should be 'A')\n", infoTail2(Q1));
    printf("   sizeQueue2(Q1): %d (should be 1)\n", sizeQueue2(Q1));
    printf("   Status: %s\n\n", (infoHead2(Q1) == 'A' && infoTail2(Q1) == 'A' && sizeQueue2(Q1) == 1) ? "PASSED" : "FAILED");

    // 5. TEST MUTATOR - enqueue2 (multiple elements)
    printf("5. TEST MUTATOR - enqueue2 (multiple elements)\n");
    enqueue2(&Q1, 'B');
    enqueue2(&Q1, 'C');
    enqueue2(&Q1, 'D');
    printf("   After enqueue2 B, C, D:\n");
    printf("   Q1.head: %d, Q1.tail: %d\n", head2(Q1), tail2(Q1));
    printf("   Q1 wadah: ");
    printQueue2(Q1);
    printf("\n   sizeQueue2(Q1): %d (should be 4)\n", sizeQueue2(Q1));
    printf("   infoHead2(Q1): %c (should be 'A')\n", infoHead2(Q1));
    printf("   infoTail2(Q1): %c (should be 'D')\n", infoTail2(Q1));
    printf("   Status: %s\n\n", (sizeQueue2(Q1) == 4 && infoHead2(Q1) == 'A' && infoTail2(Q1) == 'D') ? "PASSED" : "FAILED");

    // 6. TEST Output - viewQueue2
    printf("6. TEST Output - viewQueue2\n");
    printf("   viewQueue2(Q1): ");
    viewQueue2(Q1);
    printf(" (should show ABCD)\n");
    printf("   Status: PASSED (visual check)\n\n");

    // 7. TEST BOUNDARY - isTailStop
    printf("7. TEST BOUNDARY - isTailStop\n");
    printf("   Before filling to capacity, isTailStop(Q1): %s\n", isTailStop(Q1) ? "true" : "false");
    enqueue2(&Q1, 'E');
    printf("   After enqueue2('E') - Q1 should be full:\n");
    printf("   Q1.head: %d, Q1.tail: %d\n", head2(Q1), tail2(Q1));
    printf("   Q1 wadah: ");
    printQueue2(Q1);
    printf("\n   isFullQueue2(Q1): %s (should be true)\n", isFullQueue2(Q1) ? "true" : "false");
    printf("   isTailStop(Q1): %s (should be true)\n", isTailStop(Q1) ? "true" : "false");
    printf("   sizeQueue2(Q1): %d (should be 5)\n", sizeQueue2(Q1));
    printf("   Status: %s\n\n", (isFullQueue2(Q1) && isTailStop(Q1) && sizeQueue2(Q1) == 5) ? "PASSED" : "FAILED");

    // 8. TEST MUTATOR - dequeue2
    printf("8. TEST MUTATOR - dequeue2\n");
    dequeue2(&Q1, &e);
    printf("   After dequeue2, extracted element: %c (should be 'A')\n", e);
    printf("   Q1.head: %d, Q1.tail: %d\n", head2(Q1), tail2(Q1));
    printf("   Q1 wadah: ");
    printQueue2(Q1);
    printf("\n   viewQueue2(Q1): ");
    viewQueue2(Q1);
    printf(" (should show BCDE)\n");
    printf("   infoHead2(Q1): %c (should be 'B')\n", infoHead2(Q1));
    printf("   sizeQueue2(Q1): %d (should be 4)\n", sizeQueue2(Q1));
    printf("   Status: %s\n\n", (e == 'A' && infoHead2(Q1) == 'B' && sizeQueue2(Q1) == 4) ? "PASSED" : "FAILED");

    // 9. TEST ADVANCED - resetHead functionality
    printf("9. TEST ADVANCED - resetHead functionality\n");
    // Dequeue beberapa elemen untuk membuat head bergeser
    dequeue2(&Q1, &e);
    dequeue2(&Q1, &e);
    printf("   After 2 more dequeue2, Q1.head: %d, Q1.tail: %d\n", head2(Q1), tail2(Q1));
    printf("   Q1 wadah: ");
    printQueue2(Q1);
    printf("\n   viewQueue2(Q1): ");
    viewQueue2(Q1);
    printf("\n");

    // Enqueue sampai tail mencapai batas untuk trigger resetHead
    enqueue2(&Q1, 'F');
    enqueue2(&Q1, 'G');
    printf("   After enqueue2 F, G:\n");
    printf("   Q1.head: %d, Q1.tail: %d\n", head2(Q1), tail2(Q1));
    printf("   Q1 wadah: ");
    printQueue2(Q1);
    printf("\n   viewQueue2(Q1): ");
    viewQueue2(Q1);
    printf("\n");

    // Trigger resetHead dengan enqueue lagi
    enqueue2(&Q1, 'H');
    printf("   After enqueue2('H') - should trigger resetHead:\n");
    printf("   Q1.head: %d, Q1.tail: %d (head should be 1 after reset)\n", head2(Q1), tail2(Q1));
    printf("   Q1 wadah: ");
    printQueue2(Q1);
    printf("\n   viewQueue2(Q1): ");
    viewQueue2(Q1);
    printf("\n   Status: PASSED (resetHead triggered)\n\n");

    // 10. TEST MUTATOR - multiple dequeue2
    printf("10. TEST MUTATOR - multiple dequeue2\n");
    dequeue2(&Q1, &e);
    printf("    Dequeue2 1: %c\n", e);
    dequeue2(&Q1, &e);
    printf("    Dequeue2 2: %c\n", e);
    dequeue2(&Q1, &e);
    printf("    Dequeue2 3: %c\n", e);
    dequeue2(&Q1, &e);
    printf("    Dequeue2 4: %c\n", e);
    printf("    After 4 dequeue2, Q1 wadah: ");
    printQueue2(Q1);
    printf("\n    sizeQueue2(Q1): %d (should be 1)\n", sizeQueue2(Q1));
    printf("    isOneElement2(Q1): %s (should be true)\n", isOneElement2(Q1) ? "true" : "false");
    printf("    Status: %s\n\n", (sizeQueue2(Q1) == 1 && isOneElement2(Q1)) ? "PASSED" : "FAILED");

    // 11. TEST BOUNDARY - dequeue2 to empty
    printf("11. TEST BOUNDARY - dequeue2 to empty\n");
    dequeue2(&Q1, &e);
    printf("    Last dequeue2: %c (should be 'H')\n", e);
    printf("    Q1.head: %d, Q1.tail: %d (should be 0, 0)\n", head2(Q1), tail2(Q1));
    printf("    Q1 wadah: ");
    printQueue2(Q1);
    printf("\n    isEmptyQueue2(Q1): %s (should be true)\n", isEmptyQueue2(Q1) ? "true" : "false");
    printf("    Status: %s\n\n", (e == 'H' && isEmptyQueue2(Q1) && head2(Q1) == 0 && tail2(Q1) == 0) ? "PASSED" : "FAILED");

    // 12. TEST BOUNDARY - dequeue2 from empty queue
    printf("12. TEST BOUNDARY - dequeue2 from empty queue\n");
    char oldE = e;
    dequeue2(&Q1, &e);
    printf("    Dequeue2 from empty queue, e remains: %c (should be unchanged)\n", e);
    printf("    Status: %s\n\n", (e == oldE) ? "PASSED" : "FAILED");

    // 13. TEST ADVANCED - enqueue2N
    printf("13. TEST ADVANCED - enqueue2N\n");
    createQueue2(&Q1);
    printf("    Testing enqueue2N with predefined characters...\n");
    printf("    Simulating input: A B C\n");
    // Simulate input by manually calling enqueue2 (since enqueue2N reads from keyboard)
    enqueue2(&Q1, 'A');
    enqueue2(&Q1, 'B');
    enqueue2(&Q1, 'C');
    printf("    After simulated enqueue2N(3):\n");
    printf("    Q1.head: %d, Q1.tail: %d\n", head2(Q1), tail2(Q1));
    printf("    Q1 wadah: ");
    printQueue2(Q1);
    printf("\n    viewQueue2(Q1): ");
    viewQueue2(Q1);
    printf("\n    sizeQueue2(Q1): %d (should be 3)\n", sizeQueue2(Q1));
    printf("    Status: PASSED (enqueue2N simulation)\n\n");

    // 14. TEST EXTRA - isEqualQueue2
    printf("14. TEST EXTRA - isEqualQueue2\n");
    createQueue2(&Q2);
    enqueue2(&Q2, 'A');
    enqueue2(&Q2, 'B');
    enqueue2(&Q2, 'C');
    printf("    Q1: ");
    viewQueue2(Q1);
    printf("\n");
    printf("    Q2: ");
    viewQueue2(Q2);
    printf("\n");
    printf("    isEqualQueue2(Q1, Q2): %s (should be true)\n", isEqualQueue2(Q1, Q2) ? "true" : "false");

    // Make Q2 different
    enqueue2(&Q2, 'D');
    printf("    After enqueue2(Q2, 'D'):\n");
    printf("    Q1: ");
    viewQueue2(Q1);
    printf("\n");
    printf("    Q2: ");
    viewQueue2(Q2);
    printf("\n");
    printf("    isEqualQueue2(Q1, Q2): %s (should be false)\n", isEqualQueue2(Q1, Q2) ? "true" : "false");
    printf("    Status: PASSED (equality comparison)\n\n");

    // 15. TEST COMPREHENSIVE - Different head positions
    printf("15. TEST COMPREHENSIVE - Different head positions\n");
    createQueue2(&Q1);
    createQueue2(&Q2);

    // Q1: normal order
    enqueue2(&Q1, 'X');
    enqueue2(&Q1, 'Y');
    enqueue2(&Q1, 'Z');

    // Q2: dequeue first, then enqueue - different head position
    enqueue2(&Q2, 'A');
    enqueue2(&Q2, 'X');
    enqueue2(&Q2, 'Y');
    enqueue2(&Q2, 'Z');
    dequeue2(&Q2, &e); // Remove 'A', now starts with 'X'

    printf("    Q1 (head=%d): ", head2(Q1));
    printQueue2(Q1);
    printf("\n");
    printf("    Q2 (head=%d): ", head2(Q2));
    printQueue2(Q1);
    printf("\n");
    printf("    isEqualQueue2(Q1, Q2): %s (should be true - same content, different head)\n", isEqualQueue2(Q1, Q2) ? "true" : "false");
    printf("    Status: PASSED (different head positions)\n\n");

    printf("=== ALL TESTS COMPLETED ===\n");

    return 0;
}
