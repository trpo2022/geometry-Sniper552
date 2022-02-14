#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
float okr(float r){
    float a,b;
    b=2*M_PI*r;
    a=M_PI*r*r;
    printf("Длина окружности - %f\n",b);
    printf("Площадь окружности - %f",a);
}
int main(){
    setlocale(0,"rus");
    float r;
    printf("Введите радиус окружности:\n");
    scanf("%f",&r);
    okr(r);
    return 0;
}

