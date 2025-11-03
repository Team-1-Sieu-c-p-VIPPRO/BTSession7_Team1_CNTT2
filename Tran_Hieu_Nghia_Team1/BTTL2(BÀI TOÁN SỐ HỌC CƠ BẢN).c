#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int nNum,choice,factorial;
	int sum=0;
	int originNumber, temp, tempNumber, reverseNumber = 0;
	do{	
	printf("===== PROGRAM MENU =====\n");
	printf("1. Calculate the sum of numbers from 1 to n\n");
	printf("2. Calculate the sum of even numbers from 1 to n\n");
	printf("3. Calculate the factorial of n\n");
	printf("4. Check if a number is prime\n");
	printf("5. Check if a number is a palindrome\n");
	printf("6. Exit\n");
	printf("=========================\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	

	switch (choice){
		case 1:
			printf("Enter n: ");
			scanf("%d",&nNum);
			for(int i=1;i<=nNum;i++){
				sum+=i;
			}
			printf("S = %d\n",sum);
			break;
		case 2:
			printf("Enter n: ");
			scanf("%d",&nNum);
			for(int i=1;i<=nNum;i++){
				if(i%2==0){
					sum+=i;
				}
				
			}
			printf("S = %d\n",sum);
			break;
		case 3:
			factorial=1;
			printf("Enter factorial of n!: ");
			scanf("%d",&nNum);
			for(int i=1;i<=nNum;i++){
				factorial*=i;
			}
			printf("%d! = %d\n",nNum,factorial);
			break;
        case 4: {
            printf("Enter a number (n > 1): ");
            scanf("%d", &nNum);
            if (nNum < 2) {
                printf("Not a prime number!\n");
            } else {
                int isPrime = 1;
                for (int i = 2; i <= nNum / 2; i++) {
                    if (nNum % i == 0) {
                        isPrime = 0;
                        break;
                    }
                }
                if (isPrime = 1) {printf("%d is a prime number.\n", nNum);}
                else{printf("%d is not a prime number.\n", nNum);}    
            }
            break;
        }
		case 5:
			
    
    		printf("Enter Integer Number N: ");
    		scanf("%d", &originNumber);
    
    		tempNumber = originNumber; 
    
		    while (tempNumber != 0) {
		        temp = tempNumber % 10;
		        reverseNumber = reverseNumber * 10 + temp;
		        tempNumber = tempNumber / 10;   
		    }
		
		    if (originNumber == reverseNumber) {
		        printf("%d is symmetry\n", originNumber);
		    } else {
		        printf("%d is not symmetry\n", originNumber);
		    }
			}
	}while(choice!=6);
	return 0;
}
