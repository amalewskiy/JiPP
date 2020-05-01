#include "util_4.h"

extern void error(int, char *);

double **DajMac_1(int n, int m) {
    double **tab;
    tab = (double **) malloc(sizeof(double *) * n);
    if (!tab) error(0, "Alokacja tab");
    for (int i = 0; i < n; i++) {
        tab[i] = (double *) malloc(sizeof(double) * m);
        if (!tab[i]) error(0, "Alokacja tab[i]");
    }
    return tab;
}

double **DajMac_2(int n, int m) {
    double **tab_a, *tab_b;
    tab_b = (double *) malloc(sizeof(double) * n * m);
    if (!tab_b) error(0, "Alokacja tab_b");
    tab_a = (double **) malloc(sizeof(double *) * n);
    if (!tab_a) error(0, "Alokacja tab_a");
    for (int i = 0; i < n; i++) {
        tab_a[i] = &tab_b[m * i];
    }
    return tab_a;
}

void ZwrocMac_1(double *ma) {
    if (ma) {
        free(ma);
        ma = NULL;
    }
}

void ZwrocMac_2(double **ma, int n) {
    if (ma) {
        for (int i = 0; i < n; i++) {
            if (ma[i]) free(ma[i]);
        }
        free(ma);
        ma = NULL;
    }
}

void CzytMac(FILE *fd, double **ma, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (fscanf(fd, "%lf", &ma[i][j]) != 1) {
                printf("blad ­ element nr %d %d\n", i, j);
            }
        }
    }
}

void PiszMac(FILE *fw, double **ma, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            fprintf(fw, "%lf ", ma[i][j]);
        fprintf(fw, "\n");
    }
}