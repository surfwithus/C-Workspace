#include "pnucse.h"

// Static global variable (file scope only)
static int e = 10000;

// Extern variable definitions
extern int c = 500;

// Function to add score
void DoSomething(int x) {
    // Local variable
    int d = x;

    // Static local variable (retains value between calls)
    static int b = 5;

    a += d; // (6)
    e++; // (7)
    c++;

#ifdef DEBUG
    printf("[DEBUG] DoSomething: Value1=%d, Value2=%d, Value3=%d\n", d, e, b++);
#endif
}
