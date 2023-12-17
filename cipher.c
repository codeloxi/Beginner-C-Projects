//
//  main.c
//  cipher
//
/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void processFile(char *original_congress, char *stripped_congress, char *p_original_congress);
void cipher(char *original_congress, char *stripped_congress);
void outputCode(char *stripped_congress);
void welcome(void);

FILE *fp;
FILE *finput, *foutput;

int main(void) {
    
    char original_congress[500];
    char stripped_congress[500];
    char * p_original_congress = original_congress;
    
    fp = fopen("csis.txt", "w");
    
    if(!(finput = fopen("congress1.txt", "r"))){
        printf("Cannot Open file for input\n");
        exit(-1);
    }
  
    welcome();
    
    printf("\n");
    fprintf(fp,"\n");
    
    processFile(original_congress, stripped_congress, p_original_congress);
    
    cipher(original_congress, stripped_congress);
    
    outputCode(stripped_congress);
    
    fclose(fp);
    fclose(finput);
    fclose(foutput);
    return 0;
}

void processFile(char *original_congress, char *stripped_congress, char *p_original_congress){
    
    int i;
    
    /*this is to make everything uppercase and gets rid of whitespace/other puncuation*/
    for (i = 0; i < 501 ; ++i){
        fscanf(finput, "%s", &original_congress[i]);
        if (islower(original_congress[i])){
            original_congress[i] = toupper(original_congress[i]);

    }
    
    }
    
    return;
}


void cipher(char *original_congress, char *stripped_congress){
    
    int i, shift;
    char ch;
    
    printf("How much would you like to shift your cipher?\n");
    fprintf(fp,"How much would you like to shift your cipher?\n");
    
    scanf("%d", &shift);
    
    for ( i=0; original_congress[i] != '\0'; i++ ){
        ch = original_congress[i];
        
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + shift;
            
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            original_congress[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z'){
            ch = ch + shift;
            
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            original_congress[i] = ch;
        }
        strcpy(stripped_congress, original_congress);
        
    }
    
    return;
}


void outputCode(char *stripped_congress){
    
    int i = 0, columns, rows, columns2, rows2, j = 0;
    
    for(rows=1; rows<= 5; rows++){
        
        for(columns=1; columns <= 10; columns++){
            printf("%c%c%c%c%c ", stripped_congress[i++],stripped_congress[i++],stripped_congress[i++],stripped_congress[i++],stripped_congress[i++]);
        }
       
        printf("\n");
        
    }
    
    for(rows2=1; rows2<= 5; rows2++){
        
        for(columns2=1; columns2 <= 10; columns2++){
            fprintf(fp,"%c%c%c%c%c ", stripped_congress[j++],stripped_congress[j++],stripped_congress[j++],stripped_congress[j++],stripped_congress[j++]);
        }
        
        printf("\n");
        
    }
    
    return;
}

void welcome(void){
    
    printf("Welcome to the Cipher program!\n");
    printf("\nThis program will encode a message that is stored in a text file.\n");
    printf("\nCreated By:\tJacob Bennett\n");
           
    fprintf(fp,"Welcome to the Cipher program!\n");
    fprintf(fp,"\nThis program will encode a message that is stored in a text file\n");
    fprintf(fp,"\nCreated By:\tJacob Bennett\n");
    
    return;

}
