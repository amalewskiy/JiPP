#include"util_2.h"

extern void error(int, char *);

double *DajWekt(int n) {
    double *we;
    if (!(we = (double *) malloc((unsigned) n * sizeof(double)))){
        error(0, "wektor");
    }
    return we;
}

void CzytWekt(FILE *fd, double *we, int n) {
    for (int k = 0; k < n; k++) {
        fscanf(fd, "%lf", &we[k]);
    }
}

void PiszWekt(FILE *fw, double *we, int n) {
    for (int k = 0; k < n; k++) {
        fprintf(fw, "%lf ", we[k]);
        if (!((k + 1) % 5)) fprintf(fw, "\n");
    }
}