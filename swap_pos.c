#include <stdio.h>


void swap(char a[][9], char firstpos[2], char secondpos[2])
{
    int startFirstIndex = firstpos[0] - 96;
    int startSecondIndex = 8 - ((firstpos[1] - 56)*(-1));
    
    if (startFirstIndex < 0){
        printf("Error\n");
        return;
    }
    if (startSecondIndex < 0){
        printf("Error\n");
        return;
    }
    if (startFirstIndex > 8){
        printf("Error\n");
        return;
    }
    if (startSecondIndex > 8){
        printf("Error\n");
        return;
    }    


    printf("%d - %d\n",startFirstIndex, startSecondIndex);
    printf("%c\n", a[startSecondIndex][startFirstIndex]);
    
    int finalFirstIndex = secondpos[0] - 96;
    int finalSecondIndex = 8 - ((secondpos[1] - 56)*(-1));
    
    if (finalFirstIndex < 0){
        printf("Error\n");
        return;
    }
    if (finalSecondIndex < 0){
        printf("Error\n");
        return;
    }
    if (finalFirstIndex > 8){
        printf("Error\n");
        return;
    }
    if (finalSecondIndex > 8){
        printf("Error\n");
        return;
    }
    

    printf("%c\n", a[finalSecondIndex][finalFirstIndex]);

    if (a[finalSecondIndex][finalFirstIndex] == ' '){
        a[finalSecondIndex][finalFirstIndex] = a[startSecondIndex][startFirstIndex];
        a[startSecondIndex][startFirstIndex] = ' ';
    }


}

