#include <stdio.h>

int main() {
    float capital[12] = {0};
    float totalIncome[12] = {0};
    float profit[12] = {0};
    int choice, month, editChoice;
    float totalAnnualProfit = 0;
    do {
        printf("\n========== MENU ==========\n");
        printf("1. Edit month information\n");
        printf("2. View monthly profit\n");
        printf("3. Calculate total annual revenue\n");
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
                    printf("\n--- EDIT MONTH %d ---\n", month);
                    printf("1. Enter/Edit Capital\n");
                    printf("2. Enter/Edit Total Income\n");
                    printf("3. Exit editing\n");
                    printf("Enter your choice: ");
                    scanf("%d", &editChoice);

                    switch (editChoice) {
                        case 1:
                            do {
                                printf("Enter capital for month %d: ", month);
                                scanf("%f", &capital[month-1]);
                                if (capital[month-1] < 0)
                                    printf("Capital cannot be negative!\n");
                            } while (capital[month-1] < 0);
                            break;
                        case 2:
                            do {
                                printf("Enter total income for month %d: ", month);
                                scanf("%f", &totalIncome[month-1]);
                                if (totalIncome[month-1] < 0)
                                    printf("Total income cannot be negative!\n");
                            } while (totalIncome[month-1] < 0);
                            break;
                        case 3:
                            break;
                        default:
                            printf("Invalid choice!\n");
                    }
                    profit[month-1] = totalIncome[month-1] - capital[month-1];
                } while (editChoice != 3);
                break;
            case 2:
                printf("Enter month to view (1-12): ");
                scanf("%d", &month);
                if (month < 1 || month > 12) {
                    printf("Invalid month!\n");
                    break;
                }
                printf("\n--- MONTH %d INFORMATION ---\n", month);
                printf("Capital: %.2f\n", capital[month-1]);
                printf("Total income: %.2f\n", totalIncome[month-1]);
                printf("Profit: %.2f\n", profit[month-1]);
                if (profit[month-1] > 0)
                    printf("=> Status: PROFIT\n");
                else if (profit[month-1] < 0)
                    printf("=> Status: LOSS\n");
                else
                    printf("=> Status: BREAK EVEN\n");
                break;
            case 3:
                totalAnnualProfit = 0;
                for (int i = 0; i < 12; i++) {
                    totalAnnualProfit += profit[i];
                }
                printf("\nTotal annual profit: %.2f\n", totalAnnualProfit);
                if (totalAnnualProfit > 0)
                    printf("=> The store made a PROFIT this year.\n");
                else if (totalAnnualProfit < 0)
                    printf("=> The store made a LOSS this year.\n");
                else
                    printf("=> The store BROKE EVEN this year.\n");
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

