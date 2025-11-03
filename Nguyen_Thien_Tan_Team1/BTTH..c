#include <stdio.h>

int main() {
    int choice;
    do {
        // Display menu
        printf("===== PROGRAM MENU =====\n");
        printf("1. Sum of numbers from 1 to n\n");
        printf("2. Sum of even numbers from 1 to n\n");
        printf("3. Factorial of n\n");
        printf("4. Check if n is a prime number\n");
        printf("5. Check if n is a palindrome\n");
        printf("6. Exit\n");
        printf("=========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int n;
        switch (choice) {
            case 1:
                // Sum from 1 to n
                printf("Enter n (n > 0): ");
                scanf("%d", &n);
                if (n > 0) {
                    int sum = 0;
                    int i = 1;
                    while (i <= n) {
                        sum += i;
                        i++;
                    }
                    printf("Sum from 1 to %d is: %d\n", n, sum);
                } else {
                    printf("n must be greater than 0.\n");
                }
                break;

            case 2:
                // Sum of even numbers from 1 to n
                printf("Enter n: ");
                scanf("%d", &n);
                int sum_even = 0;
                int i;
                for (i = 2; i <= n; i += 2) {
                    sum_even += i;
                }
                printf("Sum of even numbers from 1 to %d is: %d\n", n, sum_even);
                break;

            case 3:
                // Factorial of n
                printf("Enter n (n >= 0): ");
                scanf("%d", &n);
                if (n >= 0) {
                    int fact = 1;
                    int i = 1;
                    while (i <= n) {
                        fact *= i;
                        i++;
                    }
                    printf("%d! = %d\n", n, fact);
                } else {
                    printf("n must be >= 0.\n");
                }
                break;

            case 4:
                // Check prime number
                printf("Enter n (n > 1): ");
                scanf("%d", &n);
                if (n > 1) {
                    int is_prime = 1;
                    int i;
                    for (i = 2; i < n; i++) {
                        if (n % i == 0) {
                            is_prime = 0;
                            break;
                        }
                    }
                    if (is_prime)
                        printf("%d is a prime number.\n", n);
                    else
                        printf("%d is not a prime number.\n", n);
                } else {
                    printf("n must be greater than 1.\n");
                }
                break;

            case 5:
                // Check palindrome
                printf("Enter n (n > 0): ");
                scanf("%d", &n);
                if (n > 0) {
                    int original = n;
                    int reversed = 0;
                    while (n > 0) {
                        reversed = reversed * 10 + n % 10;
                        n /= 10;
                    }
                    if (original == reversed)
                        printf("%d is a palindrome.\n", original);
                    else
                        printf("%d is not a palindrome.\n", original);
                } else {
                    printf("n must be greater than 0.\n");
                }
                break;

            case 6:
                // Exit
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n"); // Line break after each operation
    } while (choice != 6);

    return 0;
}
