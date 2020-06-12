//Nr projektu: 26

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE 256
#define MAX_LINES 200

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
    int sizeTekst1 = 0, sizeTekst2 = 0, sizeLine1 = 0, sizeLine2 = 0, line = 0, longerLine = 0;
    int differentLines[MAX_LINES], differentSymbolInLine[MAX_LINES][MAX_LINE], iteratorForDifLines = -1;
    bool diffLines = true;
    fseek(fd1, 3, SEEK_SET);
    fseek(fd2, 3, SEEK_SET);
    while (fgets(line1, MAX_LINE, fd1) && fgets(line2, MAX_LINE, fd2)) {
        int j = 0;
        line++;
        sizeTekst1 += sizeLine1 = strlen(line1);
        sizeTekst2 += sizeLine2 = strlen(line2);
        if (sizeLine1 > sizeLine2) longerLine = sizeLine1;
        else if (sizeLine2 > sizeLine1) longerLine = sizeLine2;
        else longerLine = sizeLine1;
        for (int i = 0; i < longerLine; i++) {
            if (line1[i] != line2[i]) {
                if (diffLines) {
                    differentLines[++iteratorForDifLines] = line;
                    diffLines = false;
                }
                differentSymbolInLine[iteratorForDifLines][j++] = i + 1;
            }
        }
        if (!diffLines) differentSymbolInLine[iteratorForDifLines][j] = -1;
        diffLines = true;
    }
    if (sizeTekst1 == sizeTekst2) printf("Teksty są jednakowe, mają po %d bajtów\n", sizeTekst1);
    else {
        printf("Teksty nie są jednakowe");
        for (int i = 0; i <= iteratorForDifLines; i++) {
            printf("\nRoznica w linii %d, na mejscach: ", differentLines[i]);
            for (int j = 0; differentSymbolInLine[i][j] != -1; j++) {
                printf("%d ", differentSymbolInLine[i][j]);
            }
        }
    }
    fclose(fd1);
    fd1 = NULL;
    fclose(fd2);
    fd2 = NULL;
    return 0;
}