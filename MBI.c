//
//  main.c
//  bmi
//


#include <stdio.h>
FILE *fp;

double calculateBMI ();

int main (void) {
    int i;
    fp = fopen("csis.txt", "w");
    for (i = 1; i <= 4; ++i){
        calculateBMI();
    }
    fclose(fp);
    return 0;
}


double calculateBMI () {
    double weight = 0;
    double height = 0;
    double bmi = 0;

    fp = fopen("csis.txt", "w");
    
    
    
    printf("Enter your weight in pounds \n");
    fprintf(fp, "Enter your weight in pounds \n");
    scanf("%lf", &weight);
    
    printf("Enter your height in inches \n");
    fprintf(fp, "Enter your height in inches \n");
    scanf("%lf", &height);
   
    bmi = (weight * 703) / (height * height);
    
    if (bmi < 18.5)
        printf("You are underweight \n");
        fprintf(fp, "You are underweight \n");

    if (bmi >= 18.5 && bmi < 25.0)
        printf("You have a normal BMI \n");
        fprintf(fp, "You have a normal BMI \n");

    if (bmi >= 25.0 && bmi < 30.0)
        printf("You are overweight \n");
        fprintf(fp, "You are overweight \n");

    if (bmi > 30)
        printf("You are obese \n");
        fprintf(fp, "You are obese \n");





    fclose(fp);
    return 0;
}
