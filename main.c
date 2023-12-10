#include<stdio.h>
#include<stdlib.h>
#include"Funcs16.h"
#include"Funcs8.h"
#include"Funcs2.h"
#include"check_base.h"
//#include"check.h"
#include"func.h"
int main(){
    char *a;
    char *b;
    char op;
    scanf("%s ", &a);
    //if(a[0] == '~'){

    //}else{
        scanf("%c %s", &op, &b);
        const char* a_c = &a;
        const char* b_c = &b;
        int base = cbase(a_c, b_c);
        if(base == -1){
            printf("Error because of base\n");

        }else{
            int a1 = ox(a_c);
            int b1 = ox(b_c);
            int res = obs(a1, b1, op);
            printOx(res);
        }

    //}
}