#include <stdio.h>
int main() {
    int k=0,arm=0,n;
    printf("enter 3 digit number\n");
    scanf("%d",&n);
    int temp=n;
    for(int i=1;i<=3;i++)
    {
        k=n%10;
        arm+=(k*k*k);\
        n=n/10;
    }
    if(arm==temp)
    {
        printf("armstrong number");
    }
    else
    {
        printf("not armstrong number");
    }
    return 0;
}