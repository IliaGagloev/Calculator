#include<stdio.h>

#include"func.h"

int obs(int a, int b, char op){
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
            res = a&b;
            break;
        case '|':
            res = a|b;
            break;
        case '^':
            res = a^b;
            break;
    }
    return res;

}

int lonely(int a){
    printf("%d", a);
    return ~a;
}