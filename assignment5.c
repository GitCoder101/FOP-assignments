#include <stdio.h>

#define MAX 10

// Function for matrix addition
void addMatrices() {
    int a[MAX][MAX], b[MAX][MAX], sum[MAX][MAX];
    int r, c, i, j;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter first matrix:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&a[i][j]);

    printf("Enter second matrix:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&b[i][j]);

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            sum[i][j] = a[i][j] + b[i][j];

    printf("Resultant Matrix:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }
}

// Function for saddle point
void saddlePoint() {
    int a[MAX][MAX], r, c, i, j, k, min, col;
    int found = 0;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&a[i][j]);

    for(i=0;i<r;i++) {
        min = a[i][0];
        col = 0;

        for(j=1;j<c;j++) {
            if(a[i][j] < min) {
                min = a[i][j];
                col = j;
            }
        }

        for(k=0;k<r;k++) {
            if(a[k][col] > min)
                break;
        }

        if(k == r) {
            printf("Saddle Point: %d\n", min);
            found = 1;
        }
    }

    if(!found)
        printf("No Saddle Point found\n");
}

// Function for inverse of 2x2 matrix
void inverseMatrix() {
    float a[2][2], det;

    printf("Enter 2x2 matrix:\n");
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            scanf("%f",&a[i][j]);

    det = a[0][0]*a[1][1] - a[0][1]*a[1][0];

    if(det == 0) {
        printf("Inverse does not exist\n");
        return;
    }

    printf("Inverse Matrix:\n");
    printf("%.2f %.2f\n", a[1][1]/det, -a[0][1]/det);
    printf("%.2f %.2f\n", -a[1][0]/det, a[0][0]/det);
}

// Function to check magic square
void magicSquare() {
    int a[MAX][MAX], n, i, j, sum=0, diag1=0, diag2=0;
    int isMagic = 1;

    printf("Enter order of square matrix: ");
    scanf("%d",&n);

    printf("Enter matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    for(j=0;j<n;j++)
        sum += a[0][j];

    for(i=0;i<n;i++) {
        int rowSum=0, colSum=0;
        for(j=0;j<n;j++) {
            rowSum += a[i][j];
            colSum += a[j][i];
        }
        if(rowSum != sum || colSum != sum)
            isMagic = 0;
    }

    for(i=0;i<n;i++) {
        diag1 += a[i][i];
        diag2 += a[i][n-i-1];
    }

    if(diag1 != sum || diag2 != sum)
        isMagic = 0;

    if(isMagic)
        printf("It is a Magic Square\n");
    else
        printf("Not a Magic Square\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n--- Matrix Operations ---\n");
        printf("1. Addition of two matrices\n");
        printf("2. Saddle Point\n");
        printf("3. Inverse of matrix (2x2 only)\n");
        printf("4. Magic Square check\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1: addMatrices(); break;
            case 2: saddlePoint(); break;
            case 3: inverseMatrix(); break;
            case 4: magicSquare(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}