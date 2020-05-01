#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern void error(int, char *);

void zad_6(float **arr, int n, int m) {
    float sum = 0;
    int start, finish, k = 1;
    printf("Podaj przedzial przez spacje: ");
    scanf("%d %d", &start, &finish);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j < i && k >= start && k <= finish) sum += arr[i][j];
            k++;
        }
    }
    printf("Summa tych elementow: %f\n", sum);
}

void zad_7(float **arr, int n, int m) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == i) {
                float res = sin(arr[i][j]);
                if (res >= 0) sum += arr[i][j];
            } else if (j == n - i) {
                float res = sin(arr[i][j]);
                if (res >= 0.5) sum += arr[i][j];
            }
        }
    }
    printf("Summa tych elementow: %f\n", sum);
}

int main() {
    int n, m;
    printf("Podaj rozmiar macierzy przez spacje: ");
    scanf("%d %d", &n, &m);
    float **arr;
    arr = (float **) malloc(sizeof(float *) * n);
    if (!arr) error(0, "Alokacja arr");
    for (int i = 0; i < n; i++) {
        arr[i] = (float *) malloc(sizeof(float) * m);
        if (!arr[i]) error(0, "Alokacja arr[i]");
    }
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = (float) rand() / (float) (RAND_MAX / 50.0); //losuje od 0 do 50
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }
    //zad_6(arr, n, m);
    //zad_7(arr, n, m);
}