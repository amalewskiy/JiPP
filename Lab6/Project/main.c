#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

FILE *fd1 = NULL;
FILE *fd2 = NULL;

int main() {
    if (!(fd1 = fopen("TEKST_1.txt", "r"))) {
        printf("Blad otwarcia TEKST_1.txt\n");
        exit(2);
    }
    if (!(fd2 = fopen("TEKST_2.txt", "r"))) {
        printf("Blad otwarcia TEKST_2.txt\n");
        exit(2);
    }
    char line1[MAX_LINE], line2[MAX_LINE];
    memset(line1, ' ', MAX_LINE);
    memset(line2, ' ', MAX_LINE);
    while (fgets(line1, MAX_LINE, fd1) && fgets(line2, MAX_LINE, fd2)) {
        if (strcmp(line1, line2) < 0) {
            printf("Teksty nie sa jednakowe, "
                   "drugi tekst wiekszy od pierwszego");
            exit(1);
        } else if (strcmp(line1, line2) > 0) {
            printf("Teksty nie sa jednakowe, "
                   "pierwszy tekst wiekszy od drugiego");
            exit(1);
        }
    }
    printf("Teksty sa jednakowe");
    fclose(fd1);
    fd1 = NULL;
    fclose(fd2);
    fd2 = NULL;
    return 0;
}
