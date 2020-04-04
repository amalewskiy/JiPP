#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256
#define MAX_LINES 200

FILE *fd = NULL;

void zad11() {
    if (!(fd = fopen("DANE.txt", "r"))) {
        printf("EROR WITH FILE\n");
        exit(2);
    }
    char b[MAX_LINE];
    int len = 0, LL = -1, LDL = 0, LML = 0, LPZ = 0;
    while (++LL < MAX_LINES && fgets(b, MAX_LINE, fd)) {
        len = strlen(b);
        b[len - 1] = '\0';
        for (int j = 0; b[j]; j++) {
            if ((int) b[j] > 64 && (int) b[j] < 91) {
                LDL++;
            } else if ((int) b[j] > 96 && (int) b[j] < 123) {
                LML++;
            } else LPZ++;
        }
    }
    printf("Liczba linij: %d\nLiczba duzych liter: %d\n"
           "Liczba malych liter: %d\nLiczba pozostalych"
           " znakow: %d\n", LL, LDL, LML, LPZ);
    fclose(fd);
    fd = NULL;
}

int liczba_linij() {
    if (!(fd = fopen("DANE.txt", "r"))) {
        printf("EROR WITH FILE\n");
        exit(2);
    }
    char b[MAX_LINE];
    int len = 0, LL = -1;
    while (++LL < MAX_LINES && fgets(b, MAX_LINE, fd)) {
        len = strlen(b);
        b[len - 1] = '\0';
    }
    fclose(fd);
    fd = NULL;
    return LL;
}

void zad15() {
    FILE *fd15;
    char PL[MAX_LINE], DL[MAX_LINE], q[MAX_LINE], *d[MAX_LINES];
    int len, i = -1, pl, dl, max = liczba_linij();
    fd = NULL;
    if (!(fd = fopen("DANE.txt", "r"))) {
        printf("EROR WITH FILE\n");
        exit(2);
    }
    while (1) {
        printf("Podaj nomer pierwszej linii "
               "(max %d, min 1): ", max);
        scanf("%d", &pl);
        if (!(pl <= max && pl > 0)) {
            printf("Niepoprawne wprowadzanie liczby!\n");
            printf("Sprobuj ponownie\n");
            continue;
        } else break;
    }
    while (1) {
        printf("Podaj nomer drugiej linii "
               "(max %d, min 1): ", max);
        scanf("%d", &dl);
        if (!(dl <= max && dl > 0)) {
            printf("Niepoprawne wprowadzanie liczby!\n");
            printf("Sprobuj ponownie\n");
            continue;
        } else break;
    }
    while (++i < MAX_LINES && fgets(q, MAX_LINE, fd)) {
        len = strlen(q);
        q[len - 1] = '\0';
        if ((d[i] = (char *) malloc((unsigned) len)) == (char *) NULL) {
            printf("Brak pamieci\n");
            exit(3);
        }
        strcpy(d[i], q);
        if (i + 1 == pl) {
            strcpy(PL, d[i]);
        } else if (i + 1 == dl) {
            strcpy(DL, d[i]);
        }
    }
    d[pl - 1] = DL;
    d[dl - 1] = PL;
    fd15 = fopen("DANE_ZAD15.txt", "w");
    for (int j = 0; j < i; j++) {
        fprintf(fd15, "%s\n", d[j]);
    }
    fclose(fd);
    fclose(fd15);
    fd = NULL;
    fd15 = NULL;
}

/*void zad16(){
    if (!(fd = fopen("DANE.txt", "r"))) {
        printf("EROR WITH FILE\n");
        exit(2);
    }

}*/

int main() {
    zad11();
    zad15();
    //zad16();
    return 0;
}