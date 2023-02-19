#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
//#include<malloc.h>

int cmp(const void* a, const void* b) {
    return strcmp((char*)a, (char*)b);
}

int main(void) {
    int startIndex;
    int wordCount;
    char words[20][30];
    scanf("%d\n%d", &startIndex, &wordCount);
    for (int i = 0; i < wordCount; i++) {
        scanf("%s", words[i]);
        getchar();
    }
    char str[30];
    strcpy(str, words[startIndex]);
    qsort(words, wordCount, sizeof(words[0]), cmp);
    bool found = true;
    char c = str[strlen(str) - 1];
    bool used[20] = {false};
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(str, words[i]) == 0) {
            used[i] = true;
            break;
        }
    }
    char ans[100];
    ans[0] = '\0';

    strcat(ans, str);
    while (found) {
        found = false;
        int preLenth = 0;
        int j = -1;
        for (int i = 0; i < wordCount; i++) {
            if (!used[i]) {
                if (c > words[i][0]) {
                    continue;
                }
                else if (c < words[i][0]) {
                    break;
                }
                else {                    
                    if (strlen(words[i]) > preLenth) {
                        preLenth = strlen(words[i]);
                        j = i;
                    }
                }
            }
        }
        if (j >= 0) {
            found = true;
            strcat(ans, words[j]);
            used[j] = true;
            c = words[j][strlen(words[j]) - 1];
        }
    }
    printf("%s\n", ans);
    system("pause");
    return 0;
}