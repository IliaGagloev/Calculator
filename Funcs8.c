#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"Funcs2.h"
#include"func.h"

int o(const char *a){
    int res = 0;
    for(int i = 1;i < strlen(a) - 1;i++){
        res <<= 3;
        res += a[i] - '0';
    }
    return res;
}


void printO(int a){
    if(a < 0){
        printf("-");
        a = abs(a);
    }
    printf("0x%o\n", a);
}
