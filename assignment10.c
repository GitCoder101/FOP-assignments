#include <stdio.h>
#include <math.h>

int main()
{
    int choice, num, i;
    float a, b, result = 1;

    printf("Simple Calculator\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Factorial\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter two numbers: ");
            scanf("%f %f", &a, &b);
            printf("Result = %.2f", a + b);
            break;

        case 2:
            printf("Enter two numbers: ");
            scanf("%f %f", &a, &b);
            printf("Result = %.2f", a - b);
            break;

        case 3:
            printf("Enter two numbers: ");
            scanf("%f %f", &a, &b);
            printf("Result = %.2f", a * b);
            break;

        case 4:
            printf("Enter two numbers: ");
            scanf("%f %f", &a, &b);
            if(b != 0)
                printf("Result = %.2f", a / b);
            else
                printf("Division by zero not allowed");
            break;

        case 5:
            printf("Enter base and exponent: ");
            scanf("%f %f", &a, &b);
            printf("Result = %.2f", pow(a, b));
            break;

        case 6:
            printf("Enter a natural number: ");
            scanf("%d", &num);
            result = 1;
            for(i = 1; i <= num; i++)
            {
                result = result * i;
            }
            printf("Factorial = %.0f", result);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}