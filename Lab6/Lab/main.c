#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256
#define MAX_LINES 200

FILE *fd;

void zad11(char *te, int *LDL, int *LML, int *LPZ) {
    char p = ' ';
    while (p = *te++) {
        if ((int) p > 64 && (int) p < 91) {
            *LDL = *LDL + 1;
        } else if ((int) p > 96 && (int) p < 123) {
            *LML = *LML + 1;
        } else *LPZ = *LPZ + 1;
    }
}

int main() {
    if (!(fd = fopen("DANE.txt", "r"))) {
        printf("EROR WITH FILE\n");
        exit(2);
    }
    char *d[MAX_LINES], bufor[MAX_LINE];
    int len = 0, LL = 0, LDL = 0, LML = 0, LPZ = 0;
    while (LL < MAX_LINES && fgets(bufor, MAX_LINE, fd)) {
        len = strlen(bufor);
        bufor[len - 1] = '\0';
        if ((d[LL] = (char *) malloc((unsigned) len)) == (char *) NULL) {
            printf("Brak pamieci\n");
            exit(3);
        }
        strcpy(d[LL], bufor);
        zad11(d[LL], &LDL, &LML, &LPZ);
        LL++;
    }
    fclose(fd);
    fd = NULL;
    printf("Liczba linij: %d\n", LL);
    printf("Liczba duzych liter: %d\n", LDL);
    printf("Liczba malych liter: %d\n", LML);
    printf("Liczba pozostalych znakow: %d\n", LPZ);
    return 0;
}
