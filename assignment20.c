// assignment20.c
#include <stdio.h>

void swap_val(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("After swap (value): %d %d\n", a, b);
}

void swap_ref(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;

    printf("Enter two numbers: ");
    scanf("%d %d",&x,&y);

    swap_val(x,y);

    swap_ref(&x,&y);
    printf("After swap (reference): %d %d\n", x, y);

    return 0;
}