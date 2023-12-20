#include<string.h>
#include<stdlib.h>
#include"func.h"

char* delete_spaces(char* a){
    int n = strlen(a);
    char* res = (char*)calloc((n + 1), sizeof(char));
    int j = 0;
    for(int i = 0;i < n;i++){
        if(a[i] != ' '){
            res[j] = a[i];
            j++;
        }
    }
    res[j] = '\0';
    return res;
}

int obs(int a, int b, char op,int* flag){
    int res = 0;
    switch(op){
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '%':
            res = a%b;
            break;
        case '&':
            if(a < 0 || b < 0){
                *flag = 1;
                return 0;
            }
            res = a&b;
            break;
        case '|':
            if(a < 0 || b < 0){
                *flag = 1;
                return 0;
            }
            res = a|b;
            break;
        case '^':
            if(a < 0 || b < 0){
                *flag = 1;
                return 0;
            }
            res = a^b;
            break;
        default:
            printf("i cant do this opperation yet");
            *flag = 1;
    }
    return res;

}

int lonely(int a){
    int res = ~a;
    return res;
}