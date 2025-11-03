#include <stdio.h>

int main() {
    int choice, n;

    do {
        printf("\n===== BASIC MATH PROGRAM MENU =====\n");
        printf("1. Calculate the sum from 1 to n\n");
        printf("2. Calculate the sum of even numbers from 1 to n\n");
        printf("3. Calculate the factorial of n\n");
        printf("4. Check if n is a prime number\n");
        printf("5. Check if n is a palindrome number\n");
        printf("6. Exit\n");
        printf("===================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
            	int i;
                printf("Enter n (n > 0): ");
                scanf("%d", &n);
                if (n > 0) {
                    int sum = 0;
                    for (i = 1; i <= n; i++) {
                        sum += i;
                    }
                    printf("The sum from 1 to %d is: %d\n", n, sum);
                } else {
                    printf("Invalid input.\n");
                }
                break;
            }

            case 2: {
            	int j;
                printf("Enter n: ");
                scanf("%d", &n);
                int sumEven = 0;
                for (j = 2; j <= n; j += 2) {
                    sumEven += j;
                }
                printf("The sum of even numbers from 1 to %d is: %d\n", n, sumEven);
                break;
            }

            case 3: {
                printf("Enter n (n >= 0): ");
                scanf("%d", &n);
                if (n >= 0) {
                    int e = 1;
                    unsigned long long fact = 1;
                    while (e <= n) {
                        fact *= e;
                        e++;
                    }
                    printf("The factorial of %d is: %llu\n", n, fact);
                } else {
                    printf("Invalid input.\n");
                }
                break;
            }

            case 4: {
            	int l;
                printf("Enter n (n > 1): ");
                scanf("%d", &n);
                if (n > 1) {
                    int isPrime = 1;
                    for (l = 2; l < n; l++) {
                        if (n % l == 0) {
                            isPrime = 0;
                            break;
                        }
                    }
                    if (isPrime)
                        printf("%d is a prime number.\n", n);
                    else
                        printf("%d is not a prime number.\n", n);
                } else {
                    printf("Invalid input.\n");
                }
                break;
            }

            case 5: {
                printf("Enter n (n > 0): ");
                scanf("%d", &n);
                if (n > 0) {
                    int original = n, reversed = 0;
                    do {
                        int digit = n % 10;
                        reversed = reversed * 10 + digit;
                        n /= 10;
                    } while (n > 0);

                    if (reversed == original)
                        printf("%d is a palindrome number.\n", original);
                    else
                        printf("%d is not a palindrome number.\n", original);
                } else {
                    printf("Invalid input.\n");
                }
                break;
            }

            case 6:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}

