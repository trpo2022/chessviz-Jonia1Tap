#include <stdio.h>
#include "table_create.c"
#include "swap_pos.c"

int main()
{
    char a[9][9] = {};
    chess(a);
        
    int i, j;
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            printf("%3c", a[i][j]);
        }
    printf("\n");
    }

    char startPosN[2];
    char finalPosN[2];
    for (int i = 0; i < 2; i++){
        scanf("%1c", &startPosN[i]);
    }
    for (int i = 0; i < 2; i++){
        scanf("%1c", &finalPosN[i]);
    }
    swap(a, startPosN, finalPosN);
    
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            printf("%3c", a[i][j]);
        }
    printf("\n");
    }

}