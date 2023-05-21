#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>
//#include<malloc.h>

int N, M;

char * longestPalindrome(char * s){
    int slenth = strlen(s);
    int dp[slenth][slenth];
    memset(dp, 0, sizeof(dp));
    int i, j;
    int start;
    int result = 1;
    char* ss = malloc(sizeof(char) * 1000);
    for (i = slenth - 1; i >=0; i--)
        for(j = i; j < slenth; j++) {
            if (s[i] == s[j]) {
                if ((j - i) <= 1) {
                    dp[i][j] = 1;
                    if (result < (j - i + 1)) {
                        start = i;
                        result = j - i + 1;
                    }
                } else if(dp[i + 1][j - 1]){
                    if (result < (j - i + 1)) {
                        start = i;
                        result = j - i + 1;
                    }
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }
    for (int k = 0; k < result; k++)
        ss[k] = s[start + k];
    ss[result] = '\0';
    return ss;
}

typedef struct ListNode1 ListNode;

struct ListNode1 {
    int val;
    ListNode *next;
};
char str[3][30] = {
    "http://c.biancheng.net",
    "C语言中文网",
    "C-Language"
};

int main(void) {

    char **s = str;
    printf("%p %p %d\n", s, s + 1, sizeof(int *));
    for(int i = 0; i<3; i++){
        printf("str[%d]: %s\n", i, (s + i));
    }

    char str[100];
    float money = 123.1;
    int m = sprintf(str, "%-08.2f", money);
    printf("%s\n", str);
    char* ss = longestPalindrome("babad");
    printf("%s\n", ss);
    FILE* fp = NULL;
    fp = fopen("C:\\Users\\Administrator\\Desktop\\input.txt", "r");
    if (fp == NULL) {
        printf("failed to open file!\n");
        getchar();
        return -1;
    }
    scanf("%d %d", &N, &M);
    getchar();
    system("pause");
    return 0;
}