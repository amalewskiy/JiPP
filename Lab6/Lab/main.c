#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256
#define MAX_LINES 200

FILE *fd;

void ile_slow(char *te, int *LDL, int *LML, int *LPZ) {
    char p = ' ';
    while (p = *te++)
        if ((int) p > 64 && (int) p < 91) *LDL++;
        else if ((int) p > 96 && (int) p < 123) *LML++;
        else *LPZ++;
}

int main() {
    char *d[MAX_LINES], bufor[MAX_LINE];
    int len, i = 0, LL = 0, *LDL = 0, *LML = 0, *LPZ = 0;
    if (!(fd = fopen("DANE.txt", "r"))) {
        printf("Blad otwarcia zbioru\n");
        exit(2);
    }

    while (i < MAX_LINES && fgets(bufor, MAX_LINE, fd)) {
        len = strlen(bufor);
        bufor[len - 1] = '\0';
        if ((d[i] = (char *) malloc((unsigned) len)) == (char *) NULL) {
            printf("Brak pamieci\n");
            exit(3);
        }
        strcpy(d[i], bufor);
        ile_slow(d[i], LDL, LML, LPZ);
        LL++;
        i++;
    }
    fclose(fd);
    fd = NULL;
    printf("Liczba duzych liter: %d\n", *LDL);
    printf("Liczba malych liter: %d\n", *LML);
    printf("Liczba dpozostalych znakow: %d\n", *LPZ);
    system("pause");
}
