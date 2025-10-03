#include <stdio.h>
#include <ctype.h>

int main(void) {
    // HW 3-1 Codes
    int sum = 0;

    for (int n = 1; n <= 65535; n++) {
        int digitsSum = 0;
        int temp = n;

        while (temp > 0) {
            digitsSum += temp % 10;
            temp /= 10;
        }

        if (n % 2 == 0 || n % 5 == 0) {
            sum = sum - digitsSum;
        }
        else if (digitsSum != 0 && n % digitsSum == 0) {
            sum = sum - (sum % n);
        }
        else {
            sum = sum + sum / n;
        }
    }

    // HW 3-2 Codes
    char str[100]; // array to store digits as characters
    int i = 0;
    int ch;
    int num = 0;
    int res;

    // Some codes may be here
    printf("Enter a number: ");
    // read characters until newline
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (isdigit(ch)) { // only store digits
            str[i++] = ch;
        }
    }
    str[i] = '\0'; // null-terminate the string

    // convert character array into integer
    for (int j=0; str[j] != '\0'; j++) {
        num = num * 10 + (str[j] - '0');
    }

    // Insert your own codes as here
    int tempNum = num;
    int digitNums = 0;
    while (tempNum > 0) {
        digitNums += tempNum % 10;
        tempNum /= 10;
    }

    if (digitNums % 2 == 0)
        res = num % 10; // 7 -> -1835477 5 -> -1311055 9 -> -2359899
    else
        res = 0;

    printf("the result of sum * ?: %d\n", sum * res);
    printf("%d\n", sum * res);

    return 0;
}