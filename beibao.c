#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>
//#include<malloc.h>

int N, M;


int main(void) {
    pid_t pid = fork();
    if (pid == -1) {
        printf("失败！");
    }
    else if (pid == 0) {
        printf("I am child, my pid：%d, ppid：%d\n",getpid(),getppid());
        sleep(5);
    }
    else {
        printf("I am father, my pid：%d, ppid：%d\n",getpid(),getppid());
        sleep(5);
    }
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