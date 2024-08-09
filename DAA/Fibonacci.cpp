#include <stdio.h>

// Function to generate Fibonacci sequence up to p
void generateFibonacci(int p)
{
    int a = 0, b = 1, next;

    printf("Fibonacci Sequence up to %d:\n", p);

    // Print the first two numbers
    printf("%d, %d, ", a, b);

    next = a + b;
    while (next <= p)
    {
        printf("%d, ", next);
        a = b;
        b = next;
        next = a + b;
    }
    printf("\n");
}

// Driver code
int main()
{
    int p;

    // Taking input from the user
    printf("Enter the limit (p) for Fibonacci sequence: ");
    scanf("%d", &p);

    // Function call to generate Fibonacci sequence
    generateFibonacci(p);

    return 0;
}

