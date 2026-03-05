#include <stdio.h>
float basicpay,hra,ta,grosssalary,pt,netsalary;//pt-proffessional tax

int main() {
    printf("enter basic pay ");
    scanf("%f",&basicpay);
    hra=0.1*basicpay;
    ta=0.05*basicpay;
    grosssalary=basicpay+ta+hra;
    pt=0.02*grosssalary;
    netsalary=grosssalary-pt;
    printf("\nbasicpay=%.1f",basicpay);
    printf("\ngrosssalary=%.1f",grosssalary);
    printf("\nnetsalary=%.1f",netsalary);
    
    
    return 0;
}