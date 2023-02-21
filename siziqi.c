#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
//#include<malloc.h>


int main(void) {
    FILE* fp = NULL;
    fp = fopen("C:\\Users\\Administrator\\Desktop\\input.txt", "r");
    if (fp == NULL) {
        printf("failed to open file!\n");
        getchar();
        return -1;
    }
    int N, M;
    scanf("%d %d", &N, &M);
    getchar();
    

    system("pause");
    return 0;
}