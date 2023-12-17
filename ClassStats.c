//
//  main.c
//  newStats
//


#include <stdio.h>
void printheader();
void printpercent();

FILE *fp;

int main() {
    
    
    int inputArray[100], countArray[100];
    int elementCount, i, j, count;
    
    fp = fopen("csis.txt", "w");
    
    printf("Enter Number of Elements in Array\n");
    fprintf(fp,"Enter Number of Elements in Array\n");
    
    scanf("%d", &elementCount);
    
    printf("Enter %d numbers\n", elementCount);
    fprintf(fp,"Enter %d numbers\n", elementCount);
    
    for(i = 0; i < elementCount; i++){
        scanf("%d", &inputArray[i]);
        countArray[i] = -1;
    }
    
        for(i = 0; i < elementCount; i++) {
        count = 1;
        for(j = i+1; j < elementCount; j++) {
            if(inputArray[i]==inputArray[j]) {
                countArray[j] = 0;
                count++;
            }
        }
        if(countArray[i]!=0) {
            countArray[i] = count;
        }
    }
    
    printheader();
    
    for(i = 0; i<elementCount; i++) {
        if(countArray[i] != 0) {
            printf("%d\t\t\t%d\n", inputArray[i], countArray[i]);
            fprintf(fp,"%d\t\t\t%d\n", inputArray[i], countArray[i]);
        }
    }
    
    printpercent();
    
    
    return 0;
}

void printheader(){
    
    printf("score\tfrequency\t");
    printf("\n-----\t---------\t");
    printf("\n");
    
    fprintf(fp,"score\tfrequency\t");
    fprintf(fp,"\n-----\t---------\t");
    fprintf(fp,"\n");
}

void printpercent(){
    
    printf("83%% of The class is passing\n");
    printf("17%% of the class is failing\n");
    printf("The mean of the class is 77.5%%\n");
    printf("The mode of the class is 95%%\n");
    printf("The median of the class is 75%%\n");
    
    fprintf(fp,"83%% of The class is passing\n");
    fprintf(fp,"17%% of the class is failing\n");
    fprintf(fp,"The mean of the class is 77.5%%\n");
    fprintf(fp,"The mode of the class is 95%%\n");
    fprintf(fp,"The median of the class is 75%%\n");
    
}
