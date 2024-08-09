#include <stdio.h>

// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Driver code
int main()
{
    int a, b;

    // Taking input from the user
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Function call
    printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));

    return 0;
}

