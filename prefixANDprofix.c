#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
//#include<malloc.h>

int ans[9];
int used[9] = {0};
int n, k;
int found = 0, count = 0;
int lenth = 0;
void permutation() {
    if (lenth == n) {
        count++;
        if (count == k) {
            found = 1;
            for (int i = 0; i < lenth; i++)
                printf("%d", ans[i]);
            printf("\n");
        }
        
        return;
    }
    for (int i = 0; i < n && !found; i++) {
        if (used[i]) continue;
        used[i] = 1;
        ans[lenth] = i + 1;
        lenth++;
        permutation();
        used[i] = 0;
        lenth--; 
    }
}

int main(void) {
    scanf("%d %d", &n, &k);
    permutation();
    system("pause");
    return 0;
}