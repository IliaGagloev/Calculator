#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"Funcs16.h"

int ox(const char *a){
    int res = 0;
    for(int i = 0;i < strlen(a);i++){
        if(isdigit(a[i])){
            res <<= 4;
            res += a[i] - '0';
        }else{
            res <<= 4;
            res += (a[i] - '0') - 7;
        }
    }
    return res;
}

chisla ox_to_int(char *a,char *b){
    const char* a1 = &a;
    const char* b1 = &b;
    int res_a = ox(a1);
    int res_b = ox(b1);
    chisla ch = {res_a, res_b};
    return ch;
}

void printOx(int a){
    if(a < 0){
        printf("-");
        a = abs(a);
    }
    printf("0x%X\n", a);
}
