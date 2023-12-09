#include<stdio.h>
#include<stdlib.h>
#include"Funcs16.h"
#include"func.h"

int main(){
    char *a;
    char *b;
    char op;
    scanf("%s %c %s", &a, &op, &b);
    chisla ch = ox_to_int(a,b);
    int res = obs(ch.a, ch.b, op);
    printOx(res);
    return 0;
}