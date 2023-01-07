#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include<malloc.h>

// 中缀转后缀**
struct arrayStack;
typedef struct arrayStack* Stack;
struct arrayStack {
    char operator[100];
    int topOfStack;
};



int isEmpty(Stack S) {
    if(S->topOfStack == -1)
        return 1;
    return 0;
}
void Spush(Stack S, char c) {
    //S->topOfStack++;
    S->operator[++S->topOfStack] = c;
}
char Spop(Stack S) {
    if(!isEmpty(S))
        return S->operator[S->topOfStack--];
    else 
        return 0;
}
char Stop(Stack S) {
    return S->operator[S->topOfStack];
}



// 后缀转中缀**
struct stringStack;
typedef struct stringStack* strStack;
struct stringStack {
    char str[20][20];
    int topOfStack;
};

int isEmptyS(strStack S) {
    if(S->topOfStack == -1)
        return 1;
    return 0;
}

void SpushS(strStack S, char* str){
    strcpy(S->str[++S->topOfStack], str);
}

char* SpopS(strStack S) {
    if (!isEmptyS(S))
        return S->str[S->topOfStack--];
    else
        return 0;
}

char* StopS(strStack S) {
    return S->str[S->topOfStack];
}

int isOperator(char c) {
    if( c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/') {
        return 1;
    }
    return 0;
}

int priority(char c) {
    if( c == '+' || c == '-') 
        return 0;
    if( c == '*' || c == '/')
        return 1;
    if( c == '(' || c == ')')
        return 2;
}


void* postfix(Stack S, char* str, char* outStr) {
    char c = str[0];
    int i = 0;
    // char outStr[100];
    while (c != '\0') {
        if((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A')) {
            outStr[i++] = c;
        }
        else if(isOperator(c)) {
            if( c == ')') {
                while(!isEmpty(S) && Stop(S) != '('){
                    outStr[i++] = Spop(S);
                }
                outStr[i++] = c;
                if(Stop(S) == '(')
                    Spop(S);
            }
            // else if(isEmpty(S)) {
            //     Spush(S, c);
            // } 
            else {
                //if(priority(c) > priority(Stop(S))) {
                    //Spush(S, c);
                //}
                //else {
                    if(c == '(') {
                        outStr[i++] = c;
                    }
                    else {
                        while(!isEmpty(S) && priority(c) <= priority(Stop(S)) && Stop(S) != '(')
                            outStr[i++] = Spop(S);
                    }
                    Spush(S, c);
                //}
            }
        }
        c = *(++str);
    }
    while(!isEmpty(S))
        outStr[i++] = Spop(S);
    outStr[i] = '\0';
    for(int j = 0; j < i; j++) {
        printf("%c", outStr[j]);
    }
    putchar('\n');
}

char* postTOprefix(strStack S, char* str) {
    char c = str[0];
    char result[100];
    char temp[3];
    char* temp1;
    char* temp2;
    int i = 0;
    while (c != '\0') {
        temp[0] = c;
        temp[1] = '\0';
        if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A') || c == '(' || c == ')') {
            if(c == '(') {
                temp[1] = *(++str);
                temp[2] = '\0';
            }
            SpushS(S, temp);
        }
        else {
            temp2 = SpopS(S);
            // 以下处理 "("和 ")"
            if(*(str + 1) == ')'){
                strcat(temp2, ")");
                str++;
            }
            temp1 = SpopS(S);
            strcat(temp1, temp);
            strcat(temp1, temp2);
            SpushS(S, temp1);
        }
        c = *(++str);
    }
    printf("%s\n", S->str[S->topOfStack]);
}

int main(void) {
    char string[200];
    char outStr[200];
    Stack S;
    S = (Stack)malloc(sizeof(struct arrayStack));
    S->topOfStack = -1;
    strStack SS;
    SS = (strStack)malloc(sizeof(struct stringStack));
    SS->topOfStack = -1;
    scanf("%s", string);
    postfix(S, string, outStr);
    postTOprefix(SS, outStr);

    system("pause");
    return 0;
}