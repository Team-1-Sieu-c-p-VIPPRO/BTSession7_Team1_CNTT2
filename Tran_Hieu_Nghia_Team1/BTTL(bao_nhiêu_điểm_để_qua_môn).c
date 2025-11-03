#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int mid, final, choice, choice1;
    float averageP;
    int tpoint = -1, ppoint = -1;   
    int tpoint1 = -1, ppoint1 = -1;
    int tpoint2;

    do {
        printf("--------------Menu--------------\n");
        printf("1.Enter midterm score\n");
        printf("2.Enter final grade\n");
        printf("3.Calculate average score\n");
        printf("4.Check how many points are needed on the final exam to pass the course.\n");
        printf("5.Check if you have passed the course.\n");
        printf("6.Retake the exam\n");
        printf("7.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter theoretical point: ");
                scanf("%d", &tpoint);
                printf("Enter practice point: ");
                scanf("%d", &ppoint);	
                if(tpoint>100||ppoint>100||tpoint<0||ppoint<0){
                    printf("Value error!\n");
                }		
                break;

            case 2:
                printf("Enter theoretical point: ");
                scanf("%d", &tpoint1);
                printf("Enter practice point: ");
                scanf("%d", &ppoint1);
                if(tpoint1>100||ppoint1>100||tpoint1<0||ppoint1<0){
                    printf("Value error!\n");
                }	
                break;	

            case 3:	
                if(ppoint1==-1||tpoint1==-1||ppoint==-1||tpoint==-1){
                    printf("Please enter your scores!!!\n");
                } else {
                    float miAverageP=0.3*(0.5*(tpoint+ppoint));
                    float lastAverageP=0.7*(0.5*(tpoint1+ppoint1));
                    averageP = miAverageP + lastAverageP;
                    printf("Your average score: %.2f\n",averageP);
                }
                break;

            case 4:
                printf("---- Calculate required score to pass ----\n");
                printf("1. Have theoretical score\n");
                printf("2. Don't have any final scores yet\n");
                printf("Enter your choice: ");
                scanf("%d", &choice1);

                if(tpoint == -1 || ppoint == -1) {
                    printf("Please enter midterm scores first!\n");
                    break;
                }

                switch (choice1) {
                    case 1: {
                        printf("Enter your final theoretical score: ");
                        scanf("%d", &tpoint1);

                        if (tpoint1 > 100 || tpoint1 < 0) {
                            printf("Value error!\n");
                            break;
                        }

                        float midPart = 0.3 * (0.5 * (tpoint + ppoint));
                        float needAvg = 50.0 - midPart;
                        float needPrac = (needAvg / 0.7 - (tpoint1 / 2.0)) * 2.0;

                        if (needPrac > 100)
                            printf("Even with full marks, you cannot pass.\n");
                        else if (needPrac < 0)
                            printf("You have already passed the subject!\n");
                        else
                            printf("You need at least %.2f points on the final practical test to pass.\n", needPrac);
                        break;
                    }

                    case 2: {
                        float midPart = 0.3 * (0.5 * (tpoint + ppoint));
                        float needAvg = 50.0 - midPart;
                        float needFinalEach = (needAvg / 0.7);
                        float needScoreEach = needFinalEach * 2.0; 

                        if (needScoreEach > 200)
                            printf("Even with full marks, you cannot pass.\n");
                        else if (needScoreEach < 0)
                            printf("You have already passed the subject!\n");
                        else
                            printf("You need an average of %.2f points for both final theoretical and practical exams to pass.\n",
                                   needScoreEach / 2.0);
                        break;
                    }

                    default:
                        printf("Invalid choice!\n");
                        break;
                }
                break;

            case 5:
                if(averageP>=50){
                    printf("Pass the subject\n");
                } else {
                    printf("Fail the subject\n");
                }
                break;

            case 6:
                printf("Enter mid theoretical point: ");
                scanf("%d",&tpoint);
                printf("Enter mid practice point: ");
                scanf("%d",&ppoint);
                if(tpoint>100||ppoint>100||tpoint<0||ppoint<0){
                    printf("Value error!\n");
                }
                printf("Enter last theoretical point: ");
                scanf("%d",&tpoint1);
                printf("Enter last practice point: ");
                scanf("%d",&ppoint1);
                if(tpoint1>100||ppoint1>100||tpoint1<0||ppoint1<0){
                    printf("Value error!\n");
                }	
                break;
        }
    } while(choice != 7);

    return 0;
}

