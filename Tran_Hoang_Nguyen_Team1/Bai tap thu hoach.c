#include <stdio.h>

int main() {
    float capital[12] = {0};
    float income[12] = {0};
    float profit[12] = {0};
    int choice;

    do {
        printf("\n===== STORE REVENUE MANAGEMENT =====\n");
        printf("1. Edit monthly information\n");
        printf("2. View profit of a month\n");
        printf("3. Calculate total annual revenue\n");
        printf("4. Exit\n");
        printf("====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int month;
                printf("Enter the month to edit (1-12): ");
                scanf("%d", &month);

                if (month < 1 || month > 12) {
                    printf("Invalid month! Please enter a value between 1 and 12.\n");
                    break;
                }

                int editChoice;
                do {
                    printf("\nEditing month %d:\n", month);
                    printf("1. Edit capital\n");
                    printf("2. Edit total income\n");
                    printf("3. Exit editing\n");
                    printf("Enter your choice: ");
                    scanf("%d", &editChoice);

                    switch (editChoice) {
                        case 1:
                            printf("Enter new capital: ");
                            scanf("%f", &capital[month - 1]);
                            profit[month - 1] = income[month - 1] - capital[month - 1];
                            printf("Capital updated successfully!\n");
                            break;

                        case 2:
                            printf("Enter new total income: ");
                            scanf("%f", &income[month - 1]);
                            profit[month - 1] = income[month - 1] - capital[month - 1];
                            printf("Income updated successfully!\n");
                            break;

                        case 3:
                            printf("Exiting edit mode for month %d.\n", month);
                            break;

                        default:
                            printf("Invalid choice! Please try again.\n");
                    }
                } while (editChoice != 3);

                break;
            }

            case 2: {
                int month;
                printf("Enter the month to view profit (1-12): ");
                scanf("%d", &month);

                if (month < 1 || month > 12) {
                    printf("Invalid month! Please enter a value between 1 and 12.\n");
                    break;
                }

                printf("Profit for month %d: %.2f\n", month, profit[month - 1]);

                if (profit[month - 1] > 0)
                    printf("Status: PROFIT\n");
                else if (profit[month - 1] < 0)
                    printf("Status: LOSS\n");
                else
                    printf("Status: BREAK EVEN\n");

                break;
            }

            case 3: {
            	int j;
                float totalRevenue = 0;
                for (j = 0; j < 12; j++) {
                    totalRevenue += income[j];
                }
                printf("Total annual revenue: %.2f\n", totalRevenue);
                break;
            }

            case 4:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

