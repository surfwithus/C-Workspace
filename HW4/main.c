#include <stdio.h>

void swap_ptr(int **p1, int **p2) {
    int temp = **p1;
    **p1 = **p2;
    **p2 = temp;
}

int main() {
    int x = 100, y = 200;
    int *px = &x;
    int *py = &y;
    printf("[Before]\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    swap_ptr(&px, &py);
    printf("[After]\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}