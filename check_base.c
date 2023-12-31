#include<stdio.h>
#include<stdlib.h>
#include"check_base.h"

int basel(const char* a){
    int base = 0;
    if(a[0] == '0' && a[1] == 'x') 
        base = 16;
    else if(a[0] == '0')
        base = 8;
    else
        base = 2;
    return base;
}

int cbase(const char* a, const char* b){
    int base_a = basel(a);
    int base_b = basel(b);
    if(base_a == base_b)
        return base_a;
    return -1;

}