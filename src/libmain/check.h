#pragma once

#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE_STR 300

void okr(float);
void printint(int a[], int);
void printchar(char a[], int);
int checkcircle(char sbor[], int);
int countsum(int a[], int);
int checkcircle(char sbor[], int);
int countsum(int a[], int end);
float radius(char sbor[], int, int, int);
float koor_x(char sbor[], int, int);
float koor_y(char sbor[], int, int);
void circle(char sbor[], int endstr, float rez[3]);
void peresech(float rez1[], float rez2[]);
int circles(const char*);
