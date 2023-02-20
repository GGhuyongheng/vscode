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
    char ch;
    char preChar;
    int start = 0;
    int lenth = 0;
    int ans = 0;
    while ((ch = fgetc(fp)) != EOF) {
        if (isdigit(ch)) {
            if (lenth == 0){
                lenth++;
            }
            else if (ch == preChar + 1 || ch == preChar) {
                lenth++;
            }
            else {
                ans = fmax(ans, lenth);
                lenth = 1;
            }
            preChar = ch;
        }
        else {
            lenth = 0;
        }
    }
    ans = fmax(ans, lenth);
    printf("%d\n", ans);
    system("pause");
    return 0;
}