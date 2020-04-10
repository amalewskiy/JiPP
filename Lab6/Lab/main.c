#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256
#define MAX_LINES 200

FILE *fd = NULL;

void zad11() {
    fd = NULL;
    if (!(fd = fopen("DANE.txt", "r"))) {
        printf("Blad otwarcia zbioru\n");
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
    fd = NULL;
    if (!(fd = fopen("DANE.txt", "r"))) {
        printf("Blad otwarcia zbioru\n");
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
    char PL[MAX_LINE], DL[MAX_LINE], q[MAX_LINE], *d[MAX_LINES];
    int len, i = -1, pl, dl, max = liczba_linij();
    fd = NULL;
    if (!(fd = fopen("DANE.txt", "r"))) {
        printf("Blad otwarcia zbioru\n");
        exit(2);
    }
    while (1) {
        printf("Podaj numer pierwszej linii "
               "(max %d, min 1): ", max);
        scanf("%d", &pl);
        if (!(pl <= max && pl > 0)) {
            printf("Niepoprawne wprowadzanie liczby!\n"
                   "Sprobuj ponownie\n");
            continue;
        } else break;
    }
    while (1) {
        printf("Podaj numer drugiej linii "
               "(max %d, min 1): ", max);
        scanf("%d", &dl);
        if (!(dl <= max && dl > 0)) {
            printf("Niepoprawne wprowadzanie liczby!\n"
                   "Sprobuj ponownie\n");
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
    FILE *fd15;
    fd15 = fopen("DANE_ZAD15.txt", "w");
    for (int j = 0; j < i; j++) {
        fprintf(fd15, "%s\n", d[j]);
    }
    fclose(fd);
    fclose(fd15);
    fd = NULL;
    fd15 = NULL;
}

void zad16() {
    if (!(fd = fopen("DANE.txt", "r"))) {
        printf("Blad otwarcia zbioru\n");
        exit(2);
    }
    char tekst[MAX_LINE], q[MAX_LINE];
    int len_tekst, len, i = -1;
    printf("Podaj tekst jaki szukasz: ");
    fgets(tekst, MAX_LINE, stdin);
    len_tekst = strlen(tekst);
    tekst[len_tekst - 1] = '\0';
    printf("Wybrany tekst znajduje sie na linijach: ");
    while (++i < MAX_LINES && fgets(q, MAX_LINE, fd)) {
        int k = 0, poruwnianie_tekstu = 0;
        len = strlen(q);
        q[len - 1] = '\0';
        for (int j = 0; q[j]; j++) {
            if (tekst[k] == q[j]) {
                poruwnianie_tekstu++;
                k++;
            } else {
                break;
            }
            if (poruwnianie_tekstu == len_tekst - 1) {
                printf("%d ", i + 1);
                break;
            }
        }
    }
    fclose(fd);
    fd = NULL;
}

void zad17() {
    char LU[MAX_LINE], bufor[MAX_LINE], *d[MAX_LINES];
    memset(d, ' ', MAX_LINES);
    int linia_uzytkownika, po_linii, max = liczba_linij();
    int i = -1, len;
    fd = NULL;
    if (!(fd = fopen("DANE.txt", "r"))) {
        printf("Blad otwarcia zbioru\n");
        exit(2);
    }
    while (1) {
        printf("Podaj linije ktora chcesz przeniesc"
               " (max %d, min 1): ", max);
        scanf("%d", &linia_uzytkownika);
        if (!(linia_uzytkownika <= max
              && linia_uzytkownika > 0)) {
            printf("Niepoprawne wprowadzanie liczby!\n"
                   "Sprobuj ponownie\n");
            continue;
        } else break;
    }
    while (1) {
        printf("Podaj numer linii po ktorej chcesz "
               "wstawic swoja linije (max %d, min 1): ", max);
        scanf("%d", &po_linii);
        if (!(po_linii <= max && po_linii > 0)) {
            printf("Niepoprawne wprowadzanie liczby!\n"
                   "Sprobuj ponownie\n");
            continue;
        } else break;
    }
    while (++i < MAX_LINES && fgets(bufor, MAX_LINE, fd)) {
        if (linia_uzytkownika == i + 1) {
            strcpy(LU, bufor);
            break;
        }
    }
    i = -1;
    fseek(fd, 0, SEEK_SET);
    while (++i < MAX_LINES && fgets(bufor, MAX_LINE, fd)) {
        if (i == linia_uzytkownika - 1) {
            fgets(bufor, MAX_LINE, fd);
            len = strlen(bufor);
            bufor[len - 1] = '\0';
            if ((d[i] = (char *) malloc((unsigned) len)) == (char *) NULL) {
                printf("Brak pamieci\n");
                exit(3);
            }
            strcpy(d[i], bufor);
        } else if (i == po_linii) {
            linia_uzytkownika++;
            len = strlen(LU);
            LU[len - 1] = '\0';
            if ((d[i] = (char *) malloc((unsigned) len)) == (char *) NULL) {
                printf("Brak pamieci\n");
                exit(3);
            }
            strcpy(d[i], LU);
            i++;
            len = strlen(bufor);
            bufor[len - 1] = '\0';
            if ((d[i] = (char *) malloc((unsigned) len)) == (char *) NULL) {
                printf("Brak pamieci\n");
                exit(3);
            }
            strcpy(d[i], bufor);
        } else {
            len = strlen(bufor);
            bufor[len - 1] = '\0';
            if ((d[i] = (char *) malloc((unsigned) len)) == (char *) NULL) {
                printf("Brak pamieci\n");
                exit(3);
            }
            strcpy(d[i], bufor);
        }
    }
    FILE *fd17;
    fd17 = fopen("DANE_ZAD17.txt", "w");
    for (int j = 0; j < i; j++) {
        fprintf(fd17, "%s\n", d[j]);
    }
    fclose(fd);
    fclose(fd17);
    fd = NULL;
    fd17 = NULL;
}

void zad18() {
    FILE *fdd = NULL;
    if (!(fdd = fopen("DANE_Z_DWUKROPKEM.txt", "r"))) {
        printf("Blad otwarcia zbioru\n");
        exit(2);
    }
    char bufor[MAX_LINE], *slowa[MAX_LINE], tmp[MAX_LINE];
    memset(slowa, ' ', MAX_LINE);
    memset(tmp, ' ', MAX_LINE);
    memset(bufor, ' ', MAX_LINE);
    int i = -1, i_tmp = 0, len = 0, i_slowa = 0, len_buffor;
    while (++i < MAX_LINES && fgets(bufor, MAX_LINE, fdd)) {
        len_buffor = strlen(bufor);
        bufor[len_buffor - 1] = '\0';
        for (int j = 0; bufor[j] != '\0'; j++) {
            if (bufor[j] != ':' && bufor[j] != '\0') {
                tmp[i_tmp] = bufor[j];
                i_tmp++;
            } else if (bufor[j] == ':') {
                len = strlen(tmp);
                tmp[len] = '\0';
                if ((slowa[i_slowa] = (char *) malloc((unsigned) len)) == (char *) NULL) {
                    printf("Brak pamieci\n");
                    exit(3);
                }
                strcpy(slowa[i_slowa], tmp);
                i_slowa++;
                i_tmp = 0;
                memset(tmp, ' ', MAX_LINE);
            } else continue;
        }
    }
    int nomer_slowa;
    while (1) {
        printf("Podaj numer slowa jakie chcesz znalesc"
               " (min 1, max %d): ", i_slowa);
        scanf("%d", &nomer_slowa);
        if (!(nomer_slowa <= i_slowa && nomer_slowa > 0)) {
            printf("Niepoprawne wprowadzanie liczby!\n"
                   "Sprobuj ponownie\n");
            continue;
        } else break;
    }
    printf("To slowo: %s", slowa[nomer_slowa - 1]);
    fclose(fdd);
    fdd = NULL;
}

void zad19() {
    FILE *fd19;
    fd = NULL;
    if (!(fd = fopen("DANE.txt", "r"))) {
        printf("Blad otwarcia zbioru\n");
        exit(2);
    }
    char litery[] = {'a', 165, 'b', 'c', 134, 'd', 'e', 169, 'f', 'g', 'h', 'i', 'j', 'k', 'l', 136,
                     'm', 'n', 228, 'o', 162, 'p', 'q', 'r', 's', 152, 't', 'u', 'v', 'w', 'x', 'y',
                     'z', 190, 171, 'A', 164, 'B', 'C', 143, 'D', 'E', 168, 'F', 'G', 'H', 'I', 'J',
                     'K', 'L', 157, 'M', 'N', 227, 'O', 224, 'P', 'Q', 'R', 'S', 151, 'T', 'U', 'V',
                     'W', 'X', 'Y', 'Z', 189, 141, ' ', '.', ',', '?', ':', '-', '0', '1', '2', '3',
                     '4', '5', '6', '7', '8', '9', '!', '\0'};

    char *mors[] = {".-", ".-.-", "-...", "-.-.", "-.-..", "-..", ".", "..-..", "..-.", "--.",
                    "....", "..", ".---", "-.-", ".-..", ".-..-", "--", "-.", "--.--", "---", "---.", ".--.", "--.-",
                    ".-.", "...", "...-...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "--..-", "--", ".-",
                    ".-.-", "-...", "-.-.", "-.-..", "-..", ".", "..-..", "..-.", "--.", "....", "..", ".---", "-.-",
                    ".-..", ".-..­", "--", "-.", "--.--", "---", "---.", ".--.", "--.-", ".-.", "...", "...-...", "-",
                    "..-", "...-", ".--", "-..-", "-.--", "--..", "--..-", "--", "   ", ".-.-.-", "--..--", "..--..",
                    "---...", "-....-", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..",
                    "----.", "!", 0};


    char bufor[MAX_LINE];
    memset(bufor, ' ', MAX_LINE);
    int i = -1, len, len_litery = strlen(litery);
    int typ_kodowania;
    while (1) {
        printf("Chcesz tekst zakodowac (1) lub dekodowac (0)?: ");
        scanf("%d", &typ_kodowania);
        if (typ_kodowania != 1 && typ_kodowania != 0) {
            printf("Niepoprawne wprowadzanie liczby!\n"
                   "Sprobuj ponownie\n");
            continue;
        } else break;
    }
    if (typ_kodowania) {
        fd19 = fopen("DANE_ZAKODOWANE.txt", "w");
        while (++i < MAX_LINES && fgets(bufor, MAX_LINE, fd)) {
            len = strlen(bufor);
            bufor[len - 1] = '\0';
            for (int j = 0; bufor[j] != '\0'; j++) {
                if ((int) bufor[j] < 0) { continue; }
                for (int k = 0; k < len_litery; k++) {
                    if ((int) bufor[j] == (int) litery[k]) {
                        fprintf(fd19, "%s ", mors[k]);
                        break;
                    }
                }
            }
            fprintf(fd19, "\n");
        }
    } else {
        fd19 = fopen("DANE_DEKODOWANE.txt", "w");
        char nowa_litera[7];
        int i_tmp = 0, space = 0;
        memset(nowa_litera, ' ', 7);
        while (++i < MAX_LINES && fgets(bufor, MAX_LINE, fd)) {
            len = strlen(bufor);
            bufor[len - 1] = '\0';
            for (int j = 0; bufor[j] != '\0'; j++) {
                if ((int) bufor[j] < 0) { continue; }
                if (bufor[j] != ' ') {
                    space = 0;
                    nowa_litera[i_tmp++] = bufor[j];
                } else if (bufor[j] == ' ' && (space == 0 || space == 4)) {
                    space++;
                    nowa_litera[i_tmp] = '\0';
                    for (int k = 0; k < len_litery; k++) {
                        if (!(strcmp(nowa_litera, mors[k]))) {
                            fprintf(fd19, "%c", litery[k]);
                            memset(nowa_litera, ' ', 7);
                            i_tmp = 0;
                            break;
                        }
                    }
                } else if (space < 4) {
                    space++;
                    nowa_litera[i_tmp++] = bufor[j];
                }
            }
            fprintf(fd19, "\n");
        }
    }
    fclose(fd);
    fclose(fd19);
    fd = NULL;
    fd19 = NULL;
}

int main() {
    //zad11();
    //zad15();
    //zad16();
    //zad17();
    //zad18();
    //zad19();
    return 0;
}