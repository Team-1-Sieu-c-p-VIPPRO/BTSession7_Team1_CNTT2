#include <stdio.h>

int main() {
    int choice, month, editChoice;
    float capital[13] = {0};     
    float income[13] = {0};      
    float profit[13] = {0};      

    printf("=== Store Revenue Statistics for 1 Year ===\n");

    do {
        printf("\n========== Menu ==========\n");
        printf("1. Edit information\n");
        printf("2. View interest information\n");
        printf("3. Calculate total revenue for the year\n");
        printf("4. Exit\n");
        printf("==========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter month to edit (1-12): ");
                scanf("%d", &month);
                if (month < 1 || month > 12) {
                    printf("Invalid month!\n");
                    break;
                }

                do {
                    printf("\n--- Edit Month %d ---\n", month);
                    printf("1. Edit capital\n");
                    printf("2. Edit total income\n");
                    printf("3. Exit editing\n");
                    printf("Enter your choice: ");
                    scanf("%d", &editChoice);

                    switch (editChoice) {
                        case 1:
                            printf("Enter new capital: ");
                            scanf("%f", &capital[month]);
                            profit[month] = income[month] - capital[month];
                            break;
                        case 2:
                            printf("Enter new total income: ");
                            scanf("%f", &income[month]);
                            profit[month] = income[month] - capital[month];
                            break;
                        case 3:
                            printf("Finished editing month %d.\n", month);
                            break;
                        default:
                            printf("Invalid choice!\n");
                    }
                } while (editChoice != 3);
                break;

            case 2:
                printf("Enter month to view profit (1-12): ");
                scanf("%d", &month);
                if (month < 1 || month > 12) {
                    printf("Invalid month!\n");
                    break;
                }
                printf("Profit for month %d: %.2f\n", month, profit[month]);
                if (profit[month] > 0)
                    printf("Result: Profit\n");
                else if (profit[month] < 0)
                    printf("Result: Loss\n");
                else
                    printf("Result: Break-even\n");
                break;

            case 3: {
                float total = 0;
                for (int i = 1; i <= 12; i++) {
                    total += income[i];
                }
                printf("Total revenue for the year: %.2f\n", total);
                break;
            }

            case 4:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
