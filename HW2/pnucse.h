#ifndef PNUCSE_H
#define PNUCSE_H
#include <stdio.h>

// Extern variable declarations
extern int a; // (1)
extern int c; // (2)

// Function prototypes
void DoSomething(int x);
void Display();

// Conditional compilation macro
#define DEBUG // (3)
#endif // PNUCSE_H
