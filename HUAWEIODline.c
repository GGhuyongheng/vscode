#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int cmp(const void* a, const void* b) {
    return ((int*)a)[0] - ((int*)b)[0]; 
}
int main () {
    int N;
    freopen("C:\\Users\\Administrator\\Desktop\\input.txt", "r", stdin);
    scanf("%d", &N);
    getchar();
    int line[N][2];
    for (int i = 0; i < N; i++) {
        scanf("%d,%d", line[i], line[i] + 1);
        getchar();
    }
    qsort(line, N, sizeof(line[0]), cmp);
    int start = line[0][0];
    int end = line[0][1];
    int result = 1;
    for (int i = 1; i < N; i++) {
        if (line[i][0] > start && line[i][1] > end) {
            start = end;
            end = line[i][1];
            result++;
        }
        else {
            if (line[i][1] > end) {
                end = line[i][1];
            }
            else if (line[i][0] > start) {
                continue;
            }
        }
    }
    printf("%d", result);
    while (1);
    return 0;    
}