#include <stdio.h>
#define MONTHS 12 
int main() {
	// von tung thang 
    float capital[MONTHS] = {0};
    // vai tung thang 
    float income[MONTHS] = {0};
    // tien lai tung thang 
    float profit[MONTHS] = {0};

    int choice;

    do {
        printf("===== MENU =====\n");
        printf("1. Edit information\n");
        printf("2. View profit information\n");
        printf("3. Calculate total annual revenue\n");
        printf("4. Exit\n");
        printf("================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int month;
            printf("Enter month to edit (1-12): ");
            scanf("%d", &month);
            if (month < 1 || month > 12) {
                printf("Invalid month.\n");
                continue;
            }

            int edit_choice;
            do {
                printf("Select information to edit:\n");
                printf("1. Capital\n");
                printf("2. Total income\n");
                printf("3. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &edit_choice);

                switch (edit_choice) {
                    case 1:
                        printf("Enter capital for month %d: ", month);
                        scanf("%f", &capital[month - 1]);
                        break;
                    case 2:
                        printf("Enter total income for month %d: ", month);
                        scanf("%f", &income[month - 1]);
                        break;
                    case 3:
                        break;
                    default:
                        printf("Invalid choice.\n");
                }

                profit[month - 1] = income[month - 1] - capital[month - 1];

            } while (edit_choice != 3);

        } else if (choice == 2) {
            int month;
            printf("Enter month to view (1-12): ");
            scanf("%d", &month);
            if (month < 1 || month > 12) {
                printf("Invalid month.\n");
                continue;
            }

            float p = profit[month - 1];
            printf("Profit for month %d: %.2f\n", month, p);
            if (p > 0)
                printf("=> Profit\n");
            else if (p < 0)
                printf("=> Loss\n");
            else
                printf("=> Break-even\n");

        } else if (choice == 3) {
            float total_income = 0;
            int i; 
            for (i = 0; i < MONTHS; i++) {
                total_income += income[i];
            }
            printf("Total annual revenue: %.2f\n", total_income);

        } else if (choice == 4) {
            printf("Goodbye!\n");

        } else {
            printf("Invalid choice. Please try again.\n");
        }

        printf("\n");

    } while (choice != 4);

    return 0;
}
