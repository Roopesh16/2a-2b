#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    
    FILE *fp= NULL;

    fp = fopen("data.csv","r");

    if(fp == NULL){
        printf("File not opened \n");
        exit(1);
    }
    else{
        printf("File opened\n\n");
    }

    char buffer[2400];
    int column = 0;
    int row = 0;

    while(fgets(buffer,3600,fp)){
        column = 0;
        row++;
        
            if(row == 1) 
                continue;

        char *value = strtok(buffer,",");

        while(value){         

            if(column == 0){
                printf(" Name = ");
            }
            else if(column == 1){
                printf("\n Email ID = ");
            }
            else if(column == 2){
                printf("\n Github Link = ");
            }
            printf("%s",value);
            value = strtok(NULL,",");
            column++;
        }
        printf("\n");
    }

fclose(fp);

return 0;
}