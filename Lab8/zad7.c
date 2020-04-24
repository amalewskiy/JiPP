#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define LL 200

extern void error(int, char *);

void argumenty(int, char **);

int main(int argc, char *argv[]) {
    double x, y, z, s = 0, mx, my;
    FILE *fw, *fd;
    int n, k;
    argumenty(argc, argv);
    if (!(fd = fopen(argv[1], "r"))) error(2, "dane");
    if (!(fw = fopen(argv[2], "w"))) error(2, "wyniki");
    fscanf(fd, "%d", &n);
    fscanf(fd, "%lf", &x);
    fscanf(fd, "%lf", &y);
    mx = x;
    my = y;
    z = x + y;
    fprintf(fw, "%lf ", z);
    mx = x > mx ? x : mx;
    my = y > my ? y : my;
    s += x * y;
    for (k = 1; k < n; k++){
        fscanf(fd, "%lf", &x);
        fscanf(fd, "%lf", &y);
        z = x + y;
        fprintf(fw, "%lf ", z);
        if (!((k + 1) % 5)) fprintf(fw, "\n");
        mx = x > mx ? x : mx;
        my = y > my ? y : my;
        s += x * y;
    }
    fprintf(fw, "\nilocz.skal=%lf mx=%lf my=%lf\n", s, mx, my);
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