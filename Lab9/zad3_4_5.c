#include "includes.h"
#include "util_2.h"
#include "util_3.h"
#include "util_4.h"
#include "util_5.h"

FILE *fw, *fd;

extern void error(int, char *);

void argumenty(int, char **);

int main(int argc, char *argv[]) {
    argumenty(argc, argv);
    if (!(fd = fopen(argv[1], "r"))) error(2, "dane");
    if (!(fw = fopen(argv[2], "w"))) error(2, "wyniki");
    double **a, **b, **c, *x, *y;
    int n, m;
    fscanf(fd, "%d %d", &n, &m);
    x = DajWekt(m);
    y = DajWekt(m);
    a = DajMac_1(n, m);
    b = DajMac_2(n, m);
    c = DajMac_1(n, m);
    CzytMac(fd, a, n, m);
    CzytMac(fd, b, n, m);
    CzytWekt(fd, x, m);
    DodMac(a, b, c, n, m);
    Mac_x_Wekt(a, x, y, n, m);
    printf("Macierz\n");
    PiszMac(stdout, c, n, m);
    fprintf(fw, "Macierz\n");
    PiszMac(fw, c, n, m);
    printf("Wektor\n");
    PiszWekt(stdout, y, n);
    fprintf(fw, "Wektor\n");
    PiszWekt(fw, y, n);
    ZwrocMac_1(x);
    ZwrocMac_1(y);
    ZwrocMac_2(a, n);
    ZwrocMac_2(b, n);
    ZwrocMac_2(c, n);
    return 0;
}

void argumenty(int argc, char *argv[]) {
    int len;
    char *usage;
    if (argc != 3) {
        len = strlen(argv[0]) + 19;
        if (!(usage = (char *) malloc((unsigned) len * sizeof(char))))
            error(3, "tablica usage");
        strcpy(usage, argv[0]);
        strcat(usage, " file_in file_out");
        error(4, usage);
    }
}