#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE_STR 100

void okr(float r)
{
    printf("\nPerim: ");
    printf("%f\n", M_PI * 2 * r);
    printf("\nSquare: ");
    printf("%f", M_PI * r * r);
}

int main()
{
    FILE* file;
    char* fname = "lab_input.txt";
    file = fopen(fname, "r");

    int a[SIZE_STR];
    int i = 0;

    if (file == NULL) {
        printf("unable to open file '%s'", fname);
        return 0;
    }

    a[i] = fgetc(file);

    while (a[i] != EOF) {
        i++;
        a[i] = fgetc(file);
    }

    int n = i;
    i = 0;
    int j = 0, t = 1;

    int k = 0;
    for (j = 0; j < n; j++) {
        if (a[j] != ' ') {
            k++;
        }
    }
    k += 2;
    int p = k;
    char* c = (char*)malloc(k * sizeof(char));
    i = 0;
    k = 0;
    while (i < n) {
        if (a[i] != ' ') {
            c[k] = a[i];
            k++;
            i++;
        } else if (a[i - 1] <= '9' && a[i - 1] >= '0' && t == 1) {
            c[k] = ' ';
            k++;
            i++;
            t = 0;
        } else if (a[i - 1] == ',') {
            c[k] = ' ';
            k++;
            i++;
        } else {
            for (; a[i] == ' '; i++)
                ;
        }
    }
    int q1 = 1, q2 = 1, q3 = 1;
    i = 0, k = 0;
    while (i < p) {
        if (c[i] >= 'a' && c[i] <= 'z') {
            k++;
            i++;
        } else
            break;
    }
    if (k == 6) {
        i = 0;
        if ((c[i] == 'c' || c[i] == 'C') && (c[i + 1] == 'i' || c[i + 1] == 'I')
            && (c[i + 2] == 'r' || c[i + 2] == 'R')
            && (c[i + 3] == 'c' || c[i + 3] == 'C')
            && (c[i + 4] == 'l' || c[i + 4] == 'L')
            && (c[i + 5] == 'e' || c[i + 5] == 'E')) {
        } else {
            printf("Input correct data(circle)");
            q3 = 0;
        }
    } else {
        printf("Input correct data(circle)");
        q3 = 0;
    }

    i = 0;
    if (c[6] != '(') {
        printf("\nInput correct data(open bracket)");
        q1 = 0;
    }
    int u = 0;
    for (int i = p; i > 0; i--) {
        if (c[i - 1] >= '0' && c[i - 1] <= '9') {
            break;
        } else {
            u++;
        }
    }
    if (u - 1 != 0) {
        printf("\nInput correct data(after close bracket)");
        q3 = 0;
    }
    if (c[p - u] != ')') {
        printf("\nInput correct data(close bracket)");
        q2 = 0;
    }
    int q4 = 1;
    for (int i = 7; i < p - u - 1; i++) {
        if ((c[i] >= '0' && c[i] <= '9') || (c[i] == '.') || (c[i] == ' ')
            || (c[i] == ',')) {
        } else {
            q4 = 0;
            printf("\nInput correct data(in brackets)");
            break;
        }
    }
    if (q1 == 1 && q2 == 1 && q3 == 1 && q4 == 1) {
        for (int i = 0; i < p; i++) {
            printf("%c", c[i]);
        }
    }
    int  r1 = 7, l3, r2, r3;
    if (q1 == 1 && q2 == 1 && q3 == 1 && q4 == 1) {
        i = 7;
        while (c[i + 1] != ' ') {
            r1++;
            i++;
        }
        i += 2;       
        r2 = i;
        while (c[i + 1] != ',') {
            r2++;
            i++;
        }
        i += 3;
        l3 = i;
        r3 = i;
        while (c[i + 1] != ')') {
            r3++;
            i++;
        }
    }
    t = 1, k = 0;
    int o = 1;
    float r;
    int pr = 0, pl = 0;
    o = 1, k = 0;
    for (int i = l3; i < r3 + 1; i++) {
        if (c[i] >= '0' && c[i] <= '9' && o == 1) {
            pr = pr * 10 + (c[i] - 48);
        } else if (c[i] - 48 == -2) {
            i++;
            o = 0;
        }
        if (c[i] >= '0' && c[i] <= '9' && o == 0) {
            k++;
            pl = pl * 10 + (c[i] - 48);
        }
    }
    r = pr + pl * powf(10, -k);
    printf("%f", r);
    okr(r);
    return 0;
}
