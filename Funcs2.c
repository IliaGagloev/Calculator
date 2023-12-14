#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"Funcs2.h"
#include"func.h"

int bin(const char *a, int* flag){
    int res = 0;
    for(int i = 0;i < strlen(a);i++){
        if(a[i] - '0' > 1){
            *flag = 1;
            return 0;
        }
        res <<= 1;
        res += a[i] - '0';
    }
    return res;
}


void printBin(int a){
    if(a < 0){
        printf("-");
        a = abs(a);
    }
    printf("0x%X\n", a);
}
