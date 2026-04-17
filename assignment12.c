#include <stdio.h>

// Function to find GCD using Euclidean Algorithm
int findGCD(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2, i;
    int smallestDivisor = -1;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // a) Smallest common divisor (other than 1)
    for(i = 2; i <= num1 && i <= num2; i++) {
        if(num1 % i == 0 && num2 % i == 0) {
            smallestDivisor = i;
            break;
        }
    }

    if(smallestDivisor != -1)
        printf("Smallest Common Divisor (other than 1): %d\n", smallestDivisor);
    else
        printf("No common divisor other than 1\n");

    // b) GCD
    int gcd = findGCD(num1, num2);
    printf("Greatest Common Divisor (GCD): %d\n", gcd);

    return 0;
}