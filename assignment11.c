#include <stdio.h>
#include <math.h>

int main()
{
    int num, choice, i, fact = 1, isPrime = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("\nMenu\n");
    printf("1. Square Root\n");
    printf("2. Square\n");
    printf("3. Cube\n");
    printf("4. Check Prime\n");
    printf("5. Factorial\n");
    printf("6. Prime Factors\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Square Root = %.2f\n", sqrt(num));
            break;

        case 2:
            printf("Square = %d\n", num * num);
            break;

        case 3:
            printf("Cube = %d\n", num * num * num);
            break;

        case 4:
            if(num <= 1)
                isPrime = 0;
            else
            {
                for(i = 2; i <= num/2; i++)
                {
                    if(num % i == 0)
                    {
                        isPrime = 0;
                        break;
                    }
                }
            }

            if(isPrime)
                printf("%d is Prime\n", num);
            else
                printf("%d is Not Prime\n", num);
            break;

        case 5:
            for(i = 1; i <= num; i++)
                fact = fact * i;

            printf("Factorial = %d\n", fact);
            break;

        case 6:
            printf("Prime Factors: ");
            for(i = 2; i <= num; i++)
            {
                while(num % i == 0)
                {
                    printf("%d ", i);
                    num = num / i;
                }
            }
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}