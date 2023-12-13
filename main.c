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
char* a = NULL;
char* b = NULL;
char op;

void raz(char* vvod){
    int i = 0;
    while((isdigit(vvod[i]) || isalpha(vvod[i])) && i < strlen(vvod))
        i++;
    a = (char*)calloc((i+1), sizeof(char));
    i--;
    for(int j = 0;j <= i;j++)
        a[j] = vvod[j];
    i++;
    if(i == strlen(vvod)){
        op = '~';
        b = a;
        return;
    }    
    op = vvod[i];
    i++;
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
    char *vvod = NULL;
    size_t size = 0;
    getline(&vvod, &size, stdin);
    vvod = delete_spaces(vvod);
    if(vvod[0] == '~'){
        return 0;
    }
    raz(vvod);
    if(flag == 1){
        printf("Please, type only one sign\n");
        return 0;
    }
    int base = cbase(a,b);
    if(base == -1){
        printf("Error because of different base\n");
        return 0;
    }
    int a1 = 0, b1 = 0;
    switch(base){
        case 2:
            a1 = bin(a);
            b1 = bin(b);
            break;
        case 8:
            a1 = o(a);
            b1 = o(b);
            break;
        case 16:
            a1 = ox(a);
            b1 = ox(b);
            break;
    }
    int res = 0;
    if(op == '~'){
        printf("123");
    }else{
        res = obs(a1, b1, op);
    }
    switch(base){
            case 2:
                printf("%d", res);
                break;
            case 8:
                printO(res);
                break;
            case 16:
                printOx(res);
                break;
        }

    free(a);
    free(b);
    free(vvod);
}