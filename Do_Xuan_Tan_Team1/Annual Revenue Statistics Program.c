#include <stdio.h>

int main() {
    double capital[12] = {0};   // capital for each month
    double income[12] = {0};    // total income for each month
    double profit[12] = {0};    // profit = income - capital
    int i;
    int month;
    int choice;

    do {
        printf("\n+=======| Annual Revenue Statistics Program |======+\n");
        printf("| 1. Edit monthly information                      |\n");
        printf("| 2. View profit of a month                        |\n");
        printf("| 3. Total annual revenue                          |\n");
        printf("| 4. Exit                                          |\n");
        printf("+==================================================+\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            // 1. Edit information for a month
            case 1: {
                printf("Enter the month to edit (1-12): ");
                scanf("%d", &month);

                if (month < 1 || month > 12) {
                    printf("Invalid month!\n");
                } else {
                    month--; // convert to 0-based index

                    int edit;
                    printf("\n--- Editing month %d ---\n", month + 1);
                    printf("1. View current information\n");
                    printf("2. Edit capital (current: %.2lf)\n", capital[month]);
                    printf("3. Edit total income (current: %.2lf)\n", income[month]);
                    printf("4. Return to main menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &edit);

                    switch (edit) {
                        case 1: {
                            printf("\nInformation for month %d:\n", month + 1);
                            printf("Capital: %.2lf\n", capital[month]);
                            printf("Income: %.2lf\n", income[month]);
                            printf("Profit: %.2lf\n", profit[month]);
                            break;
                        }
                        case 2: {
                            printf("Enter new capital: ");
                            scanf("%lf", &capital[month]);
                            break;
                        }
                        case 3: {
                            printf("Enter new total income: ");
                            scanf("%lf", &income[month]);
                            break;
                        }
                        case 4: {
                            break; // go back
                        }
                        default: {
                            printf("Invalid choice!\n");
                            break;
                        }
                    }

                    // update profit after changes
                    profit[month] = income[month] - capital[month];
                }
                break;
            }

            // 2. View profit of a specific month
            case 2: {
                printf("Enter the month to view profit (1-12): ");
                scanf("%d", &month);

                if (month < 1 || month > 12) {
                    printf("Invalid month!\n");
                } else {
                    month--;

                    printf("\n=== Month %d ===\n", month + 1);
                    printf("Capital: %.2lf\n", capital[month]);
                    printf("Income: %.2lf\n", income[month]);
                    printf("Profit: %.2lf\n", profit[month]);

                    if (profit[month] > 0) {
                        printf("Status: Profit\n");
                    } else if (profit[month] < 0) {
                        printf("Status: Loss\n");
                    } else {
                        printf("Status: Break-even\n");
                    }
                }
                break;
            }

            // 3. Calculate total annual revenue
            case 3: {
                double total = 0;
                for (i = 0; i < 12; i++) {
                    total += income[i];
                }
                printf("\nTotal annual revenue: %.2lf\n", total);
                break;
            }

            // 4. Exit the program
            case 4: {
                printf("\nGoodbye, see you again! <3\n");
                break;
            }

            // Default case
            default: {
                printf("Invalid choice! Please select between 1 and 4.\n");
                break;
            }
        }

    } while (choice != 4);

    return 0;
}
