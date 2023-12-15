#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"Funcs16.h"
#include"Funcs8.h"
#include"Funcs2.h"
#include"check_base.h"
#include"func.h"

/*
    Here, my code praying to the God for protecting from bugs with memory
    This is really crusial step! Be advised not to remove it, even if you dont belive
    отсылка на - "https://reactor.cc/post/4851716"  
*/

int flag = 0;
int znak_a = 0;
int znak_b = 0;
char* a = NULL;
char* b = NULL;
char op;

void raz(char* vvod){
    int i = 0;
    if(vvod[0] == '~'){
        op = '~';
        i++;
    }
    if(vvod[i] == '-'){
        znak_a = 1;
        i++;
    }
    int lo = i;
    while((isdigit(vvod[i]) || isalpha(vvod[i])) && i < strlen(vvod))
        i++;
    a = (char*)calloc((i - lo + 1), sizeof(char));
    i--;
    for(int j = lo;j <= i;j++)
        a[j - lo] = vvod[j];
    i++;    
    if(op != '~')
        op = vvod[i];
    i++;
    if(vvod[i] == '-'){
        i++;
        znak_b = 1;
    }
    int k = i;
    while((isdigit(vvod[i]) || isalpha(vvod[i])) && i < strlen(vvod))
        i++;
    b = (char*)calloc((i - k + 1), sizeof(char));;
    for(int j = k;j < i;j++)
        b[j - k] = vvod[j];
    if(i < strlen(vvod) - 1){
        flag = 1;
    }
}



int main(){
    int zifr = 0;
    char *vvod = NULL;
    size_t size = 0;
    getline(&vvod, &size, stdin);
    vvod = delete_spaces(vvod);
    raz(vvod);
    if(flag == 1){
        printf("Please, type only one sign\n");
        free(a);
        free(b);
        free(vvod);
        return 0;
    }
    int res = 0;
    if(op == '~'){
        int base = basel(a);
        int a1 = 0;
        switch(base){
            case 2:
                a1 = bin(a,&zifr);
                break;
            case 8:
                a1 = o(a,&zifr);
                break;
            case 16:
                a1 = ox(a,&zifr);
                break;
        }
        if(zifr == 1){
            printf("Error. No such numbers in the base\n");
            free(a);
            free(b);
            free(vvod);
            return 0;
        }
        if(znak_a == 1)
            a1 *= (-1);
        int res = lonely(a1);
        switch(base){
            case 2:
                printBin(res);
                break;
            case 8:
                printO(res);
                break;
            case 16:
                printOx(res);
                break;
        }
    }else{
        int base = cbase(a,b);
        if(base == -1){
            printf("Error because of different base\n");
            free(a);
            free(b);
            free(vvod);
            return 0;
        }
        int a1 = 0, b1 = 0;
        switch(base){
            case 2:
                a1 = bin(a,&zifr);
                b1 = bin(b, &zifr);
                break;
            case 8:
                a1 = o(a,&zifr);
                b1 = o(b,&zifr);
                break;
            case 16:
                a1 = ox(a,&zifr);
                b1 = ox(b,&zifr);
                break;
        }
        if(zifr == 1){
            printf("Error. No such numbers in the base\n");
            free(a);
            free(b);
            free(vvod);
            return 0;
        }
        if(znak_a == 1)
            a1 *= (-1);
        if(znak_b == 1)
            b1 *= (-1);
        res = obs(a1, b1, op, &zifr);
        if(zifr == 1){
            printf("Error. The numbers must be >= 0\n");
            free(a);
            free(b);
            free(vvod);
            return 0;
        }
        switch(base){
            case 2:
                printBin(res);
                break;
            case 8:
                printO(res);
                break;
            case 16:
                printOx(res);
                break;
        }
    }
    

    free(a);
    free(b);
    free(vvod);
}