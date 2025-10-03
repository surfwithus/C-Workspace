#include "pnucse.h"

// Global variable definitions
int a = 0;

int main() {
    int i, j;

    for (i = 0; i < 3; i++) {
        printf("Enter number: ");
        scanf("%d", &j);
        DoSomething(j);
    }

    Display();
    return 0;
}
