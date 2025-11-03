#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

// Structure to store information for each month
typedef struct {
    double capital;
    double totalIncome;
    double profit;
} Month;

// Function to recalculate profit
void recalculateProfit(Month *m) {
    m->profit = m->totalIncome - m->capital;
}

// Function to edit monthly information
void editInformation(Month year[]) {
    int month, choice;

    do {
        printf("\nEnter the month you want to edit (1-12): ");
        scanf("%d", &month);
        if (month < 1 || month > 12) {
            printf("Invalid month! Please enter again.\n");
        }
    } while (month < 1 || month > 12);

    do {
        printf("\n===== EDIT MENU (Month %d) =====\n", month);
        printf("1. Edit Capital\n");
        printf("2. Edit Total Income\n");
        printf("3. Exit Editing\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter new capital: ");
                scanf("%lf", &year[month - 1].capital);
                recalculateProfit(&year[month - 1]);
                printf("Capital updated successfully!\n");
                break;

            case 2:
                printf("Enter new total income: ");
                scanf("%lf", &year[month - 1].totalIncome);
                recalculateProfit(&year[month - 1]);
                printf("Total income updated successfully!\n");
                break;

            case 3:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 3);
}

// Function to view monthly profit
void viewProfit(Month year[]) {
    int month;

    do {
        printf("\nEnter the month you want to view (1-12): ");
        scanf("%d", &month);
        if (month < 1 || month > 12) {
            printf("Invalid month! Please enter again.\n");
        }
    } while (month < 1 || month > 12);

    Month m = year[month - 1];
    printf("\n===== MONTH %d INFORMATION =====\n", month);
    printf("Capital: %.2lf\n", m.capital);
    printf("Total Income: %.2lf\n", m.totalIncome);
    printf("Profit: %.2lf\n", m.profit);

    if (m.profit > 0)
        printf("Status: Profit\n");
    else if (m.profit < 0)
        printf("Status: Loss\n");
    else
        printf("Status: Break-even\n");
}

// Function to calculate total annual income
void totalAnnualRevenue(Month year[]) {
    double total = 0;
    for (int i = 0; i < MONTHS; i++) {
        total += year[i].totalIncome;
    }
    printf("\nTotal annual revenue: %.2lf\n", total);
}

int main() {
    Month year[MONTHS] = {0}; // Initialize all data to zero
    int choice;

    do {
        printf("\n========== STORE REVENUE MANAGEMENT ==========\n");
        printf("1. Edit monthly information\n");
        printf("2. View monthly profit\n");
        printf("3. Calculate total annual revenue\n");
        printf("4. Exit\n");
        printf("==============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                editInformation(year);
                break;
            case 2:
                viewProfit(year);
                break;
            case 3:
                totalAnnualRevenue(year);
                break;
            case 4:
                printf("Program ended. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

