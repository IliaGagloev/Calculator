#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"Funcs2.h"
#include"func.h"

int fromIntToBin(const char *a, int* flag){
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
    int a1 = a;
    if(a1 < 0){
        printf("-");
        a1 = abs(a);
    }
    int y = 1;
    for (int j=sizeof(a1) * 8 -1; j>=0; j--){
        if(y == 1 && ((a1>>j)&1) == 0)
            continue;
        y = 0;
        printf("%u",(a1>>j)&1); 
    }
    if(a == 0) 
        printf("0");
    printf(" (%d)\n", a);
}
