#include <stdio.h>

int main() {
    int choice, number;

    do {
        printf("\n===== PROGRAM MENU =====\n");
        printf("1. Calculate the sum from 1 to n\n");
        printf("2. Calculate the sum of even numbers from 1 to n\n");
        printf("3. Calculate the factorial of n\n");
        printf("4. Check if a number is prime\n");
        printf("5. Check if a number is a palindrome\n");
        printf("6. Exit\n");
        printf("========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter number: ");
                scanf("%d", &number);
                int sum = 0;
                for (int i = 1; i <= number; i++) {
                    sum += i;
                }
                printf("Sum from 1 to %d is: %d\n", number, sum);
                break;
            }
            case 2: {
                printf("Enter number: ");
                scanf("%d", &number);
                int sum = 0;
                for (int i = 2; i <= number; i += 2) {
                    sum += i;
                }
                printf("Sum of even numbers from 1 to %d is: %d\n", number, sum);
                break;
            }
            case 3: {
                printf("Enter number: ");
                scanf("%d", &number);
                int i = 1;
                long long factorial = 1;
                while (i <= number) {
                    factorial *= i;
                    i++;
                }
                printf("Factorial of %d is: %lld\n", number, factorial);
                break;
            }
            case 4: {
                printf("Enter number: ");
                scanf("%d", &number);
                int isPrime = 1;
                if (number <= 1) {
                    isPrime = 0;
                } else {
                    for (int i = 2; i <= number / 2; i++) {
                        if (number % i == 0) {
                            isPrime = 0;
                            break;
                        }
                    }
                }
                if (isPrime)
                    printf("%d is a prime number.\n", number);
                else
                    printf("%d is not a prime number.\n", number);
                break;
            }
            case 5: {
                printf("Enter number: ");
                scanf("%d", &number);
                int original = number, reversed = 0;
                do {
                    reversed = reversed * 10 + number % 10;
                    number /= 10;
                } while (number > 0);
                if (original == reversed)
                    printf("%d is a palindrome.\n", original);
                else
                    printf("%d is not a palindrome.\n", original);
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
