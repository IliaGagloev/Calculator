#include<string.h>
#include<ctype.h>
#include"Funcs16.h"
int ox(const char *a,int* flag){
    int res = 0;
    for(int i = 2;i < strlen(a);i++){
        if(isdigit(a[i])){
            res <<= 4;
            res += a[i] - '0';
        }else{
            if(a[i] - '0' - 39 > 15 || a[i] - '0' - 39 < 10){
                *flag = 1;
                return 0;
            }
            res <<= 4;
            res += (a[i] - '0') - 39;
        }
    }
    return res;
}


void printOx(int a){
    int a1 = a;
    if(a < 0){
        printf("-");
        a1 = abs(a);
    }
    printf("0x%X (%d)\n", a1, a);
}

