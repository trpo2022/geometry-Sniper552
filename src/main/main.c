#include <libmain/okr.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE_STR 100


int main()
{
    FILE* file;
    char* fname = "lab_input.txt";
    file = fopen(fname, "r");

    int a[SIZE_STR];
    int i = 0;

    if (file == NULL) {
        printf("unable to open file '%s'", fname);
        return 1;
    }

    a[i] = fgetc(file);

    while (a[i] != EOF) {
        i++;
        a[i] = fgetc(file);
    }
    printf("Your input data: ");
    int end1 = i - 1;
    for (i = 0; i <= end1; i++) {
        printf("%c", a[i]);
    }
    int end = i - 1, j = 0, flag = 1, countsym = 0;
    i = 0;
    for (j = 0; j < end; j++) {
        if (a[j] != ' ') {
            countsym++;
        }
    }
    countsym += 2;
    int endstr = countsym;
    char* sbor = (char*)malloc(countsym * sizeof(char));
    countsym = 0;
    while (i < end) {
        if (a[i] != ' ') {
            sbor[countsym] = a[i];
            countsym++;
            i++;
        } else if (a[i - 1] <= '9' && a[i - 1] >= '0' && flag == 1) {
            sbor[countsym] = ' ';
            countsym++;
            i++;
            flag = 0;
        } else if (a[i - 1] == ',') {
            sbor[countsym] = ' ';
            countsym++;
            i++;
        } else {
            for (; a[i] == ' '; i++)
                ;
        }
    }
    int ernum = 0;
    i = 0, countsym = 0;
    while (i < endstr) {
        if (sbor[i] >= 'a' && sbor[i] <= 'z') {
            countsym++;
            i++;
        } else
            break;
    }
    if (countsym == 6) {
        i = 0;
        if ((sbor[i] == 'c' || sbor[i] == 'C')
            && (sbor[i + 1] == 'i' || sbor[i + 1] == 'I')
            && (sbor[i + 2] == 'r' || sbor[i + 2] == 'R')
            && (sbor[i + 3] == 'c' || sbor[i + 3] == 'C')
            && (sbor[i + 4] == 'l' || sbor[i + 4] == 'L')
            && (sbor[i + 5] == 'e' || sbor[i + 5] == 'E')) {
        } else {
            printf("You data input is not correct(circle)");
            ernum = 1;
        }
    } else {
        printf("You data input is not correct(circle)");
        ernum = 1;
    }

    i = 0;
    if (sbor[6] != '(') {
        printf("\nYou data input is not correct(open bracket)");
        ernum = 2;
    }
    int trash = 0;
    for (int i = endstr; i > 0; i--) {
        if (sbor[i - 1] >= '0' && sbor[i - 1] <= '9') {
            break;
        } else {
            trash++;
        }
    }
    if (trash - 1 != 0) {
        printf("\nYou data input is not correct(after close bracket)");
        ernum = 3;
    }
    if (sbor[endstr - trash] != ')') {
        printf("\nYou data input is not correct(close bracket)");
        ernum = 4;
    }
    for (int i = 7; i < endstr - trash - 1; i++) {
        if ((sbor[i] >= '0' && sbor[i] <= '9') || (sbor[i] == '.')
            || (sbor[i] == ' ') || (sbor[i] == ',')) {
        } else {
            ernum = 5;
            printf("\nYou data input is not correct(in brackets)");
            break;
        }
    }
    if (ernum == 0) {
        for (int i = 0; i < endstr; i++) {
            printf("%c", sbor[i]);
        }
    }
    int otbordozap, otborendi, otbori;
    if (ernum == 0) {
        i = 7;
        while (sbor[i + 1] != ' ') {
            i++;
        }
        i += 2;
        otbordozap = i;
        while (sbor[i + 1] != ',') {
            otbordozap++;
            i++;
        }
        i += 3;
        otbori = i;
        otborendi = i;
        while (sbor[i + 1] != ')') {
            otborendi++;
            i++;
        }
    }
    flag = 1, countsym = 0;
    int flag1 = 1;
    int chislo1 = 0, chislo2 = 0;
    for (i = otbori; i < otborendi + 1; i++) {
        if (sbor[i] >= '0' && sbor[i] <= '9' && flag1 == 1) {
            chislo1 = chislo1 * 10 + (sbor[i] - 48);
        } else if (sbor[i] - 48 == -2) {
            i++;
            flag1 = 0;
        }
        if (sbor[i] >= '0' && sbor[i] <= '9' && flag1 == 0) {
            countsym++;
            chislo2 = chislo2 * 10 + (sbor[i] - 48);
        }
    }
    if ((chislo1 >= 0) && (chislo2 >= 0) && ernum == 0) {
        float rad = chislo1 + chislo2 * pow(10, -countsym);
        okr(rad);
    }
    free(sbor);
    return 0;
}
