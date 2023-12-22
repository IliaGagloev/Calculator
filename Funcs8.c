#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"Funcs2.h"
#include"func.h"

int fromIntToOctal(const char *a,int* flag ){
    int res = 0;
    for(int i = 1;i < strlen(a);i++){
        if(a[i] - '0' >= 8){
            *flag = 1;
            return 0;
        }
        res <<= 3;
        res += a[i] - '0';
    }
    return res;
}


void printOctal(int a){
    if(a < 0){
        printf("-");
        a = abs(a);
    }
    printf("0%o (%d)\n", a, a);

}
