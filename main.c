#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE_STR 500

void okr(float r)
{
    float a, b;
    b = 2 * M_PI * r;
    a = M_PI * r * r;
    printf("length ring - %f\n", b);
    printf("Square ring - %f", a);
}
int main()
{
    setlocale(0, "rus");
    FILE* file;
    char* fname = "/home/vlad/trpo/geometry-Sniper552/lab_input.txt";
    file = fopen(fname, "r");

    int A[SIZE_STR];
    int i = 0;

    if (file == NULL) {
        printf("unable to open file '%s'", fname);
        return 0;
    }

    A[i] = fgetc(file);

    while (A[i] != EOF) {
        i++;
        A[i] = fgetc(file);
    }

    int n = i;
    i = 0;
    int j = 0, t = 1;

    //	for(i=0;A[i]==' ';i++);
    //	if((A[i]=='c' ||A[i]=='C') && (A[i+1]=='i' ||A[i+1]=='I') &&
    //(A[i+2]=='r' ||A[i+2]=='R') && (A[i+3]=='c' ||A[i+3]=='C') && (A[i+4]=='l'
    //||A[i+4]=='L') && (A[i+5]=='e' ||A[i+5]=='E') ){ 		for(;i<n;i++){
    //		printf("%c",A[i]);
    //		}
    //	while(i<n){
    //    if(A[i]!=' '){
    //        printf("%c",A[i]);
    //        i++;
    //    }else if((A[i-1]<='9' && A[i-1]>='0' && t==1) || (A[i-1]==',')){
    //        printf(" ");
    //        t=0;i++;
    //    }else for(;A[i]==' ';i++);
    //}
    //	}else printf("Ââåäèòå êîððåêòíûå äàííûå(circle)");

    int k = 0;
    for (j = 0; j < n; j++) {
        if (A[j] != ' ') {
            k++;
        }
    }
    k += 2;
    int p = k;
    char* c = (char*)malloc(k * sizeof(char));
    i = 0;
    k = 0;
    while (i < n) {
        if (A[i] != ' ') {
            c[k] = A[i];
            k++;
            i++;
        } else if (A[i - 1] <= '9' && A[i - 1] >= '0' && t == 1) {
            c[k] = ' ';
            k++;
            i++;
            t = 0;
        } else if (A[i - 1] == ',') {
            c[k] = ' ';
            k++;
            i++;
        } else {
            for (; A[i] == ' '; i++)
                ;
        }
    }
    // for(i=0;i<p;i++){
    //	printf("%c",c[i]);
    //}

    i = 0, k = 0;
    while (i < p) {
        if (c[i] >= 'a' && c[i] <= 'z') {
            k++;
            i++;
        } else
            break;
    }
    // printf("%d",k);
    int q1 = 1, q2 = 1, q3 = 1;
    if (k == 6) {
        i = 0;
        if ((c[i] == 'c' || c[i] == 'C') && (c[i + 1] == 'i' || c[i + 1] == 'I')
            && (c[i + 2] == 'r' || c[i + 2] == 'R')
            && (c[i + 3] == 'c' || c[i + 3] == 'C')
            && (c[i + 4] == 'l' || c[i + 4] == 'L')
            && (c[i + 5] == 'e' || c[i + 5] == 'E')) {
            //    for(i=0;i<p;i++){
            //        printf("%c",c[i]);
            //    }
        } else {
            printf("Please,enter the correct data(circle)");
            q3 = 0;
        }
    } else {
        printf("\nPlease,enter the correct data(circle)");
        q3 = 0;
    }

    i = 0;

    if (c[6] != '(') {
        printf("\nPlease, enter the correct data(open bracket)");
        q1 = 0;
    }
    int p1 = 0;
    for (i = p; i > 0; i--) {
        if (c[i] >= '0' && c[i] <= '9') {
            break;
        } else {
            p1++;
        }
    }
    p1 -= 2;
    if (p1 != 0) {
        printf("\nPlease, enter the correct data(after close bracket)");
        q3 = 0;
    }
    i = p - 1;
    if (c[i] != ')') {
        printf("\nPlease, enter the correct data(close bracket)");
        q2 = 0;
    }
    int cr = p - p1, q5 = 1;
    for (i = 6; i <= cr-1; i++) {
     if((c[i]>='0' && c[i]<='9')||(c[i]=='.')||(c[i]==' ')||(c[i]==',')){
        
    }else{
        q5=0;
        printf("\nPlease,enter the correct data(in brackets)");
        break;
    }   
    }
    if (q1 == 1 && q2 == 1 && q3 == 1 && q5 == 1) {
        for (i = 0; i < p; i++) {
            printf("%c", c[i]);
        }
    }

    return 0;
}

