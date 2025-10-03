#include <stdio.h>

void MovData(const char* srcAddr, const char* desAddr, int* memA, int* memA2, int* memB) {
    char mem1, sign1, mem2, sign2;
    int idx1, idx2;
    int *srcPtr, *dstPtr;

    sscanf(srcAddr, "%c-%c-%d", &mem1, &sign1, &idx1);
    if (mem1 == 'A') {
        if (sign1 == '$') srcPtr = &memA[idx1];
        else if (sign1 == '%') srcPtr = &memB[memA[idx1]];
    }
    else if (mem1 == 'B') srcPtr = &memB[idx1];

    sscanf(desAddr, "%c-%c-%d", &mem2, &sign2, &idx2);
    if (mem2 == 'A') {
        if (sign2 == '$') dstPtr = &memA2[idx2];
        else if (sign2 == '%') dstPtr = &memB[memA2[idx2]];
    }
    else if (mem2 == 'B') dstPtr = &memB[idx2];

    *dstPtr = *srcPtr;
}

void MovValue(const char* addr, int value, int* memB) {
    int idx;

    sscanf(addr, "B-$-%d", &idx);
    memB[idx] = value;
}

void Swap(const char* addr1, const char* addr2, int* memA, int* memB) {
    int idx1, idx2;
    int *p1, *p2;

    sscanf(addr1, "B-$-%d", &idx1);
    p1 = &memB[idx1];

    sscanf(addr2, "B-$-%d", &idx2);
    p2 = &memB[idx2];

    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int memA[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int memB[10];

    MovValue("B-$-0", 100, memB); // Store 100 at address 0 in memB
    MovValue("B-$-1", 200, memB);
    MovValue("B-$-2", 300, memB);
    MovValue("B-$-3", 400, memB);
    MovValue("B-$-4", 500, memB);
    MovValue("B-$-5", 600, memB);
    MovValue("B-$-6", 700, memB);
    MovValue("B-$-7", 800, memB);
    MovValue("B-$-8", 900, memB);
    MovValue("B-$-9", 1000, memB);

    MovData("A-$-2", "A-$-4", memA, memA, memB); // move the value stored in memA[2] to memA[4]
    MovData("A-%-5", "A-%-7", memA, memA, memB);
    MovData("A-%-3", "A-%-8", memA, memA, memB);

    Swap("B-$-7", "B-$-9", memB, memB);

    // Print output the value of each element in memA
    for (int i = 0; i < 10; i++) {
        printf("%d ", memA[i]);
    }
    printf("\n");

    // Print output the value of each element in memB
    for (int i = 0; i < 10; i++) {
        printf("%d ", memB[i]);
    }
    printf("\n");

    // Print all the values of each element (i.e. memB[memA[index]] in memB that each element of memA points to
    for (int i = 0; i < 10; i++) {
        printf("%d ", memB[memA[i]]);
    }
}

int parse(char *addr) {
    int idx;
    if (addr[0] == 'A')
        sscanf(addr, "A-$-%d", &idx);
    /*
     sscanf(addr, "A-%%-%d", &idx);
    */

    return idx;
}
