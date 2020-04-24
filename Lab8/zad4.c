#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void zad4(int *t1, int n) {
    int max = t1[0], min = t1[0], index_max = 1, index_min = 1;
    for (int i = 0; i < n; i++) {
        if (t1[i] > max) {
            max = t1[i];
            index_max = i + 1;
        } else if (t1[i] < min) {
            min = t1[i];
            index_min = i + 1;
        }
        printf("%d ", t1[i]);
    }
    printf("\nMax element %d pod indeksem %d,"
           " min element %d pod indeksem %d",
           max, index_max, min, index_min);
    int *t2 = (int *) malloc(n);
    if (t2 == NULL) exit(1);
    memcpy(t2, t1, n * sizeof(int ));
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", t2[i]);
    }
    free(t2);
}

int main() {
    printf("Podaj rozmiar tablicy: ");
    int n;
    scanf("%d", &n);
    int *t1 = (int *) malloc(n);
    if (t1 == NULL) exit(1);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        t1[i] = rand() % 100 + 0;
    zad4(t1, n);
    free(t1);
    return 0;
}