#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
//#include<malloc.h>

int N, M;

int checkWin(int **board, int row, int column) {
    int p = board[row][column];
    int count = 0;
    for (int i = column - 1; i >=0 && board[row][i] == p; i--) {
        count++;
        if (count >= 3) return 1;
    }
    for (int i = column + 1; i < M && board[row][i] == p; i++) {
        count++;
        if (count >= 3) return 1;
    }
    count = 0;
    for (int i = row - 1; i >=0 && board[i][column] == p; i--) {
        count++;
        if (count >= 3) return 1;
    }
    for (int i = row + 1; i < N && board[i][column] == p; i++) {
        count++;
        if (count >= 3) return 1;
    }
    count = 0;
    for (int i = column - 1, j = row - 1; i >=0 && j >= 0 && board[i][j] == p; i--, j--) {
        count++;
        if (count > 3) return 1;
    }
    for (int i = column + 1, j = row + 1; i < M && j < N && board[i][j] == p; i++, j++) {
        count++;
        if (count >= 3) return 1;
    }
    return 0;
}

int main(void) {
    FILE* fp = NULL;
    fp = fopen("C:\\Users\\Administrator\\Desktop\\input.txt", "r");
    if (fp == NULL) {
        printf("failed to open file!\n");
        getchar();
        return -1;
    }
    scanf("%d %d", &N, &M);
    getchar();
    int **board;
    board = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) {
        board[i] = (int*)malloc(sizeof(int) * M);
        for (int j = 0; j < M; j++) {
            board[i][j] = 0;
            printf("+ ");
        }
        putchar('\n');
    }
    bool win = false;
    int player = 1;
    while (!win) {
        printf("Player%d: ", player);
        int column;
        scanf("%d", &column);
        getchar();
        column--;
        if (board[0][column]) {
            printf("this column is full!plz input again!");
            continue;
        }
        else {
            int i = 1;
            while (i < N && board[i][column] == 0) i++;
            board[i - 1][column] = player;
            win = checkWin(board, i - 1, column);
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                printf("%d ", board[i][j]);
            }
            putchar('\n');
        }
        if (win) printf("player%d win!\n", player);
        player ^= 0B11;
    }
    system("pause");
    return 0;
}