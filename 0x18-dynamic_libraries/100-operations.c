#include <stdio.h>

/**
 * add - Adds two integers
 * @a: First integer
 * @b: Second integer
 * Return: The sum of a and b
 */
int add(int a, int b) {
    return a + b;
}

/**
 * sub - Subtracts two integers
 * @a: First integer
 * @b: Second integer
 * Return: The difference between a and b
 */
int sub(int a, int b) {
    return a - b;
}

/**
 * mul - Multiplies two integers
 * @a: First integer
 * @b: Second integer
 * Return: The product of a and b
 */
int mul(int a, int b) {
    return a * b;
}

/**
 * div - Divides two integers
 * @a: First integer (dividend)
 * @b: Second integer (divisor)
 * Return: The result of the division of a by b
 */
int div(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero\n");
        return 0;
    }
}

/**
 * mod - Computes the remainder of the division of two integers
 * @a: First integer (dividend)
 * @b: Second integer (divisor)
 * Return: The remainder of the division of a by b
 */
int mod(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        printf("Error: Division by zero\n");
        return 0;
    }
}
