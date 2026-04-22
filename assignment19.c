// assignment19.c
#include <stdio.h>
#include <string.h>

struct emp {
    char name[50], desig[50], gender[10];
    float salary;
};

int main() {
    struct emp e[10];
    int i, n, male=0, female=0;

    printf("Enter number of employees: ");
    scanf("%d",&n);

    for(i=0;i<n;i++) {
        printf("Enter name, designation, gender, salary:\n");
        scanf("%s %s %s %f", e[i].name, e[i].desig, e[i].gender, &e[i].salary);

        if(strcmp(e[i].gender,"Male")==0) male++;
        else female++;
    }

    printf("Total = %d\n", n);
    printf("Male = %d\nFemale = %d\n", male, female);

    printf("Salary > 10000:\n");
    for(i=0;i<n;i++)
        if(e[i].salary > 10000)
            printf("%s\n", e[i].name);

    printf("AsstManager:\n");
    for(i=0;i<n;i++)
        if(strcmp(e[i].desig,"AsstManager")==0)
            printf("%s\n", e[i].name);

    return 0;
}