#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
//#include<malloc.h>


int main(void) {
    int count[15] = {0};
    FILE* fp = NULL;
    fp = fopen("C:\\Users\\Administrator\\Desktop\\input.txt", "r");
    if (fp == NULL) {
        printf("failed to open file!\n");
        getchar();
        return -1;
    }
    char c = fgetc(fp);
    while ((c) != EOF) {
        if (isdigit(c)) {
            if (c != '1') {
                count[c - '0']++;
                c = fgetc(fp);
            }
            else {
                c =fgetc(fp);
                if (c == '0') {
                    count[10]++;
                    c = fgetc(fp);
                }
                else count[1]++;
            }
        }
        else if (isalpha(c)) {
            if (c == 'J')
                count[11]++;
            else if (c == 'Q')
                count[12]++;
            else if (c == 'K') count[13]++;
            else count[14]++;
            c= fgetc(fp);
        }
        else c = fgetc(fp);
    }
    int found = 0;
    int length = 0;
    for (int i = 3; i <= 14; i++) {
        if (count[i] > 0) {
            length++;
            if (i == 14) {
                if (length < 5) break;
                else {
                    for (int j = i - length + 1; j <= i; j++) {
                        count[j]--;
                        if (j <= 10) printf("%d ", j);
                        if (j == 11) printf("J ");
                        if (j == 12) printf("Q ");
                        if (j == 13) printf("K " );
                        if (j == 14) printf("A ");
                    }
                    putchar('\n');
                    i = i - length - 1;
                    length = 0;
                }
            }
        }
        else {
            if (length < 5) {
                length = 0;
            }
            else {
                for (int j = i - length; j < i; j++) {
                    count[j]--;
                    if (j <= 10) printf("%d ", j);
                    if (j == 11) printf("J ");
                    if (j == 12) printf("Q ");
                    if (j == 13) printf("K " );
                    if (j == 14) printf("A ");
                }
                putchar('\n');
                i = i - length - 1;
                length = 0;
            }
        }
    }
    system("pause");
    return 0;
}