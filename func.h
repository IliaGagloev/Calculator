#ifndef FUNC_H
#define FUNC_H

#include<stdio.h>

typedef struct{
    char* a;
    char* b;
    char op;
} chisla;

char* delete_spaces(char* a);
int obs(int a, int b,char op);
int lonely(int a);
#endif