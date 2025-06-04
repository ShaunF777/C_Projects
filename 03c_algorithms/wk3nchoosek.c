#include <stdio.h>

unsigned long long factorial(int n);
unsigned long long combination(int n, int k);

int main()
{
    //Ensure that n >= k in order for the calculation to be valid
    int n = 5; // Total number of elements
    int k = 3; // Number of elements to choose

    // Calculate and print the combination
    unsigned long long result = combination(n, k);
    printf("C(%d, %d) = %llu\n", n, k, result);

    return 0;
}
// Function to calculate combinations
unsigned long long combination(int n, int k)
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}
// Function to calculate factorial
unsigned long long factorial(int n)
{
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

