#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIDDLE_LINE 128
#define MAX_LINE 256

void zad_13()
{
    char d[MAX_LINE], znak;
    int l = 0;
    printf("Podaj tekst: ");
    fgets(d, MAX_LINE, stdin);
    printf("Podaj znak: ");
    znak = getchar();
    getchar();
    printf("\nPozycja wybranego znaku w tekście: ");
    while (d[l])
    {
        if (d[l] == znak)
            printf("%d ", l + 1);
        l++;
    }
}

void zad_14()
{
    char d[MAX_LINE], znak;
    int l = 0;
    printf("Podaj tekst: ");
    fgets(d, MAX_LINE, stdin);
    printf("Podaj znak: ");
    znak = getchar();
    getchar();
    while (d[l])
    {
        if (d[l] == znak)
        {
            d[l] = ' ';
            printf("\nZnak byl usunięty na %d pozycji: %s", l + 1, d);
            break;
        }
        l++;
    }
}

void zad_15()
{
    char d[MAX_LINE], znak, second_znak;
    int l = 0;
    printf("Podaj tekst: ");
    fgets(d, MAX_LINE, stdin);
    printf("Podaj znak: ");
    znak = getchar();
    getchar();
    printf("Podaj second znak: ");
    second_znak = getchar();
    getchar();
    while (d[l])
    {
        if (d[l] == znak)
        {
            d[l] = second_znak;
        }
        l++;
    }
    printf("Nowy tekst: %s", d);
}

void zad_16()
{
    char tekst[MIDDLE_LINE], drugi_tekst[MAX_LINE];
    int len;
    printf("Podaj tekst: ");
    fgets(tekst, MIDDLE_LINE, stdin);
    printf("Podaj drugi tekst: ");
    fgets(drugi_tekst, MAX_LINE, stdin);
    len = strlen(drugi_tekst);
    if (len > 0 && drugi_tekst[len - 1] == '\n')
        drugi_tekst[len - 1] = '\0';
    strcat(drugi_tekst, tekst);
    printf("\nNowy tekst: %s", drugi_tekst);
}

void zad_17()
{
    char tekst[MIDDLE_LINE], drugi_tekst[MAX_LINE];
    int len1, len2, pozycja, i = -1;
    printf("Podaj tekst: ");
    fgets(tekst, MIDDLE_LINE, stdin);
    printf("Podaj drugi tekst: ");
    fgets(drugi_tekst, MAX_LINE, stdin);
    printf("Podaj z ktorej pozycji: ");
    scanf("%d", &pozycja);
    len1 = strlen(tekst) - pozycja;
    len2 = strlen(drugi_tekst) - 2;
    pozycja -= 2;
    while (++i <= len1)
    {
        drugi_tekst[++len2] = tekst[++pozycja];
    }
    drugi_tekst[++len2] = '\0';
    printf("\nNowy tekst: %s\n", drugi_tekst);
}

void zad_18()
{
    char tekst[MAX_LINE];
    int len, i = 1;
    printf("Podaj tekst: ");
    fgets(tekst, MAX_LINE, stdin);
    char tmp1 = tekst[i - 1], tmp2 = tekst[i];
    len = strlen(tekst);
    while (i < len - 1)
    {
        if (i == len - 2)
        {
            tekst[i] = tmp1;
            tekst[0] = tmp2;
            i++;
            continue;
        }
        tekst[i] = tmp1;
        tmp1 = tmp2;
        tmp2 = tekst[i + 1];
        i++;
    }
    printf("\nNowy tekst: %s", tekst);
}

int moje_strcmp(const char *str1, const char *str2)
{
    int len1 = strlen(str1), len2 = strlen(str2);
    if (len1 == len2)
    {
        int i = -1;
        while (++i < len1 - 1)
        {
            if (str1[i] != str2[i])
            {
                int istr1 = str1[i], istr2 = str2[i];
                if (istr1 > istr2)
                    return 1;
                else
                    return -1;
            }
        }
        return 0;
    }
    else
    {
        if (len1 > len2)
            return 1;
        else
            return -1;
    }
}

char *moje_strcat(char *str1, const char *str2)
{
    int len1 = strlen(str1) - 2, len2 = strlen(str2), i = -1;
    while (i < len2 - 1)
    {
        str1[++len1] = str2[++i];
    }
    return str1;
}

char *moje_strcpy(char *str1, const char *str2)
{
    char *str = (char *)malloc(MAX_LINE);
    ;
    int len2 = strlen(str2) - 1, i = -1;
    while (++i < len2)
    {
        str[i] = str2[i];
    }
    return str;
}

int main()
{
    //zad_13();
    //zad_14();
    //zad_15();
    //zad_16();
    //zad_17();
    //zad_18();

    //Zadanie 19 1) moje_strcmp
    /*char tekst1[MAX_LINE], tekst2[MAX_LINE];
                    const char *d1;
                    const char *d2;
                    printf("Podaj pierwszy tekst: ");
                    d1 = fgets(tekst1, MAX_LINE, stdin);
                    printf("Podaj drugi tekst: ");
                    d2 = fgets(tekst2, MAX_LINE, stdin);
                    if(!(moje_strcmp(d1, d2))) printf("Łańcuchy d1 i d2 są takie same");
                    else printf("Łańcuchy d1 i d2 nie są takie same");*/

    //Zadanie 19 2) moje_strcat
    /*char tekst1[MAX_LINE], tekst2[MIDDLE_LINE];
                    char *d1;
                    const char *d2;
                    printf("Podaj pierwszy tekst: ");
                    d1 = fgets(tekst1, MIDDLE_LINE, stdin);
                    printf("Podaj drugi tekst: ");
                    d2 = fgets(tekst2, MIDDLE_LINE, stdin);
                    printf("%s", moje_strcat(d1, d2));*/

    //Zadanie 19 3) moje_strcpy
    /*char tekst1[MAX_LINE], tekst2[MAX_LINE];
                    char *d1;
                    const char *d2;
                    printf("Podaj pierwszy tekst: ");
                    d1 = fgets(tekst1, MAX_LINE, stdin);
                    printf("Podaj drugi tekst: ");
                    d2 = fgets(tekst2, MAX_LINE, stdin);
                    printf("%s", moje_strcpy(d1, d2));*/
}