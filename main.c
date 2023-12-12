#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Funcs16.h"
#include"Funcs8.h"
#include"Funcs2.h"
#include"check_base.h"
//#include"check.h"
#include"func.h"

char* a;
char* b;
char op;

void raz(char* vvod){
    int i = 0;
    while(vvod[i]!=' ' && i < strlen(vvod))
        i++;
    a = (char*)malloc((i+1) * sizeof(char));
    for(int j = 0;j <= i;j++)
        a[j] = vvod[j];
    i++;
    while(vvod[i] == ' ' && i < strlen(vvod))
        i++;
    if(i == strlen(vvod)){
        op = '~';
        return;
    }    
    op = vvod[i];
    i++;
    while(vvod[i] == ' ' && i < strlen(vvod))
        i++;
    int k = i;
    while(vvod[i] != ' ' && i < strlen(vvod))
        i++;
    b = (char*)malloc((i - k + 1) * sizeof(char));;
    for(int j = k;j < i;j++)
        b[j - k] = vvod[j];
}



int main(){
    char *vvod = NULL;
    size_t size = 0;
    getline(&vvod, &size, stdin);
    raz(vvod);
    printf("%s %c %s\n", a, op, b);
    if(op == '~'){
            printf("123");
    }else{
        int base = cbase(a, b);
        if(base == -1){
            printf("Error because of base\n");

        }else{
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
            int res = obs(a1, b1, op);
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
        }

    }
}