#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"Funcs16.h"
int ox(const char *a){
    int res = 0;
    for(int i = 2;i < strlen(a) - 1;i++){
        if(isdigit(a[i])){
            res <<= 4;
            res += a[i] - '0';
        }else{
            res <<= 4;
            res += (a[i] - '0') - 7;
        }
        printf("%d ", res);
    }
    printf("%d\n", res);
    return res;
}


void printOx(int a){
    if(a < 0){
        printf("-");
        a = abs(a);
    }
    printf("0x%X\n", a);
}
