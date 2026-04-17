#Without recursion
int factorial_iterative(int n) {
    int fact = 1;

    for(int i = 1; i <= n; i++) {
        fact *= i;
    }

    return fact;
}



#With recursion
int factorial_recursive(int n) {
    if(n == 0 || n == 1)
        return 1;
    else
        return n * factorial_recursive(n - 1);
}