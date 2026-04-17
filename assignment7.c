#include <stdio.h>

#define MAX 100

// Structure to store student details
struct Student {
    int roll;
    char name[50];
    float marks[3];
    float total;
    float percentage;
};

int main() {
    struct Student s[MAX];
    int n, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input student details
    for(i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Enter marks of 3 subjects:\n");
        s[i].total = 0;

        for(j = 0; j < 3; j++) {
            scanf("%f", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].percentage = s[i].total / 3;
    }

    // Display student results
    printf("\n--- Student Results ---\n");

    for(i = 0; i < n; i++) {
        printf("\nRoll No: %d\n", s[i].roll);
        printf("Name: %s\n", s[i].name);
        printf("Total Marks: %.2f\n", s[i].total);
        printf("Percentage: %.2f%%\n", s[i].percentage);

        // Result classification
        if(s[i].percentage >= 75)
            printf("Result: Distinction\n");
        else if(s[i].percentage >= 60)
            printf("Result: First Class\n");
        else if(s[i].percentage >= 50)
            printf("Result: Second Class\n");
        else if(s[i].percentage >= 40)
            printf("Result: Pass\n");
        else
            printf("Result: Fail\n");
    }

    return 0;
}