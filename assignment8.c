#include <stdio.h>

int main() {
    int sum=0,i,a;
    int total = 0;
    printf("enter your marks in every subject\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&a);
        if(a>40)
        {
            printf("pass\n");
        }
        else
        {
            printf("fail\n");
        }
        sum+=a;
    }
    total=sum/5;
    if(total>=75)
    {
        printf("distinction overall\n");
    }
    else if(total<75 && total>=60)
    {
        printf("first division overall\n");
    }
    else if(total<60 && total>=50)
    {
        printf("second division overall\n");
    }
    else if(total<50 && total>=40)
    {
        printf("third division overall\n");
    }
    else
    {
        printf("failed overall\n");
    }
    

    return 0;
}