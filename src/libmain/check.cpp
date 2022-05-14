#include "check.h"

void okr(float radius)
{
    printf("\nSquare: ");
    printf("%f", M_PI * radius * radius);
    printf("\nPerimeter: ");
    printf("%f\n", M_PI * 2 * radius);
}

void printint(int a[], int end)
{
    int i;
    for (i = 0; i <= end; i++) {
        printf("%c", a[i]);
    }
}

void printchar(char a[], int end)
{
    int i;
    for (i = 0; i < end; i++) {
        printf("%c", a[i]);
    }
}
int checkcircle(char sbor[], int endstr)
{
    int i = 0, countsym = 0, ernum = 0;
    while (i < endstr) {
        if (sbor[i] >= 'a' && sbor[i] <= 'z') {
            countsym++;
            i++;
        } else
            break;
    }
    if (countsym == 6) {
        i = 0;
        if ((sbor[i] == 'c') && (sbor[i + 1] == 'i') && (sbor[i + 2] == 'r')
            && (sbor[i + 3] == 'c') && (sbor[i + 4] == 'l')
            && (sbor[i + 5] == 'e')) {
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
    if (sbor[endstr - trash] != ')') {
        printf("\nYou data input is not correct(close bracket)");
        ernum = 3;
    }
    for (int i = 7; i < endstr - trash - 1; i++) {
        if ((sbor[i] >= '0' && sbor[i] <= '9') || (sbor[i] == '.')
            || (sbor[i] == ' ') || (sbor[i] == ',')) {
        } else {
            ernum = 4;
            printf("\nYou data input is not correct(in brackets)");
            break;
        }
    }
    printf("\n");
    if (ernum == 0) {
        printchar(sbor, endstr);
    }
    return ernum;
}

int countsum(int a[], int end)
{
    int i = 0, countsym = 0;
    for (i = 0; i < end; i++) {
        if (a[i] != ' ') {
            countsym++;
        }
    }
    return countsym;
}

float radius(char sbor[], int otbori, int otborendi, int ernum)
{
    int flag1 = 1, i = 0;
    float chislo1 = 0, chislo2 = 0, countsym = 0;
    float rad = 0;
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
        rad = chislo1 + chislo2 * pow(10, -countsym);
        okr(rad);
    }
    return rad;
}

float koor_x(char sbor[], int otbori, int otborendi)
{
    int flag1 = 1, i = 0;
    float chislo1 = 0, chislo2 = 0, countsym = 0;
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

    return chislo1 + chislo2 * pow(10, -countsym);
}
float koor_y(char sbor[], int otbori, int otborendi)
{
    int flag1 = 1, i = 0;
    float chislo1 = 0, chislo2 = 0, countsym = 0;
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
    return chislo1 + chislo2 * pow(10, -countsym);
}

void circle(char sbor[], int endstr, float rez[3])
{
    int left_otbor1 = 7, right_otbor1 = 7, left_otbor2 = 0, left_otbor3 = 0,
        right_otbor2 = 0, right_otbor3 = 0;

    int ernum = checkcircle(sbor, endstr);
    if (ernum == 0) {
        int i = 7;
        while (sbor[i + 1] != ' ') {
            right_otbor1++;
            i++;
        }
        i += 2;
        left_otbor2 = i;
        right_otbor2 = i;
        while (sbor[i + 1] != ',') {
            right_otbor2++;
            i++;
        }
        i += 3;
        left_otbor3 = i;
        right_otbor3 = i;
        while (sbor[i + 1] != ')') {
            right_otbor3++;
            i++;
        }
    }

    rez[1] = koor_x(sbor, left_otbor1, right_otbor1);
    rez[2] = koor_y(sbor, left_otbor2, right_otbor2);
    rez[0] = radius(sbor, left_otbor3, right_otbor3, ernum);
}
void peresech(float rez1[], float rez2[])
{
    float delta
            = sqrt((rez1[0] - rez2[0]) * (rez1[0] - rez2[0])
                   + (rez1[1] - rez2[1]) * (rez1[1] - rez2[1]));
    if (rez1[0] == rez2[0] && rez1[1] == rez2[1]) {
        if (rez1[2] == rez2[2]) {
            printf("Sovpadenie");
        } else {
            printf("Peresecheniya net");
        }
    } else {
        if (rez1[2] + rez2[2] > delta) {
            printf("Peresechenie est");
        } else if (rez1[2] + rez2[2] == delta) {
            printf("Peresechenie - 1 tochka");
        } else {
            printf("Peresecheniya net");
        }
    }
}

int circles()
{
    FILE* file;
    const char* fname = "lab_input.txt";
    file = fopen(fname, "r");

    int a[SIZE_STR];
    int i = 0;
    float rez1[3] = {0, 0, 0}, rez2[3] = {0, 0, 0};
    if (file == nullptr) {
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
    printint(a, end1);
    int end = i + 2;
    i = 0;
    int countsym = countsum(a, end) + 1;

    char* sbor = new char[countsym];
    int prob = 0;
    while (i < end) {
        if (a[i] != ' ') {
            sbor[prob] = a[i];
            prob++;
            i++;
        } else if (a[i] == ' ' && a[i - 1] == ',') {
            sbor[prob] = ' ';
            prob++;
            i++;
        } else if (a[i] == ' ') {
            for (; a[i] == ' '; i++)
                ;
        }
    }
    i = 0;
    while (sbor[i] != '\n') {
        i++;
    }

    int endcirc1 = i, endcirc2 = 0;
    char* sborcir1 = new char[endcirc1];
    i++;
    while (sbor[i] != ')') {
        if (sbor[i] == ',' || sbor[i] == ' ' || sbor[i] == '.'
            || (sbor[i] >= '0' && sbor[i] <= '9')
            || (sbor[i] >= 'a' && sbor[i] <= 'z') || sbor[i] >= '('
            || sbor[i] <= ')') {
            i++;
        } else
            break;
    }
    while (sbor[i] != ')') {
        i++;
    }
    endcirc2 = i + 1;
    char* sborcir2 = new char[endcirc2 - endcirc1];
    for (i = 0; i < endcirc1; i++) {
        sborcir1[i] = sbor[i];
    }
    int stok = 0;
    for (i = endcirc1 + 1; i < endcirc2; i++) {
        sborcir2[stok] = sbor[i];
        stok++;
    }
    circle(sborcir1, endcirc1, rez1);
    printf("\n");
    circle(sborcir2, prob - endcirc1 - 1, rez2);
    printf("\n");
    peresech(rez1, rez2);
    free(sbor);
    free(sborcir1);
    free(sborcir2);
    fclose(file);
    return 0;
}
