//14.	Write a program that calculates g.c.d. and l.c.d. of input numbers.

#include <stdio.h>

// Function to calculate the greatest common divisor (GCD) using Euclidean algorithm
int calculateGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the least common multiple (LCM)
int calculateLCM(int a, int b) {
    // LCM(a, b) = |a * b| / GCD(a, b)
    return (a * b) / calculateGCD(a, b);
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int gcd = calculateGCD(num1, num2);
    int lcm = calculateLCM(num1, num2);

    printf("GCD of %d and %d is: %d\n", num1, num2, gcd);
    printf("LCM of %d and %d is: %d\n", num1, num2, lcm);

    return 0;
}

