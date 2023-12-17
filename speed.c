//
//  main.c
//  speed
//


#include <stdio.h>
FILE *fp;
/*#define*/

int main(int argc, const char * argv[]) {
    float HOUR_TO_SEC = 3600;
    float METER_TO_MILE = 1600;
    float DIST = 425.5;
    float HOURS = 7.5;
    float speedhours;
    float speedmeters;
    
    fp = fopen("csis.txt", "w");

    speedhours = DIST/HOURS;
    speedmeters = (METER_TO_MILE * DIST) / (HOURS * HOUR_TO_SEC) ;
    
    printf("The speed of the car in MPH is %f MPH. \n", speedhours);
    fprintf(fp, "The speed of the car in MPH is %f MPH. \n", speedhours);
    
    printf("The speed of the car in meters/sec is %f meters/sec. \n", speedmeters);
    fprintf(fp,"The speed of the car in meters/sec is %f meters/sec. \n", speedmeters);
    
    fclose(fp);
    return 0;
}
