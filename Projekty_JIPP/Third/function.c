#include "function.h"

#define MAX_ERR 2

static char *p[] = {" blad alokacji ",
                    " zle dane",
                    " nieznany ",
};

void error(int nr) {
    int k;
    k = nr >= MAX_ERR ? MAX_ERR : nr;
    printf("\nBlad(%d) ­%s\n", nr, p[k]);
    exit(nr);
}

float arithmeticAverage(float A[], int N) {
    int choice = 2;
    printf("\nZnalezc srednia arytmetyczna elementow tej macierzy:\n"
           "\t\t\t\tlezacych w l-tym wierszu (0)\n"
           "\t\t\t\tlezacych w l-tej kolumnie (1)\n"
           "\t\t\t\tlezacych na glownej przekatnej (2)\n"
           "\t\t\t\tlezacych pod przekatna (3)\n"
           "\t\t\t\tz drugiej przekatnej (4)\n"
           "Podaj liczbe (0-4): ");
    scanf("%d", &choice);
    if (choice < 0 || choice > 4) error(1);
    int l = 1;
    if (choice == 0 || choice == 1) {
        printf("Podaj wierz lub kolumny l (min 1, max %d): ", N);
        scanf("%d", &l);
        if (l < 1 || l > N) error(1);
    }
    float sum = 0.0;
    l--;
    int q = N, iq = N;
    switch (choice) {
        case 0:
            for (int i = N * l; i < (N * l) + N; i++) {
                sum += A[i];
            }
            break;
        case 1:
            for (int i = l; i < (N * N) - (N - (l + 1)); i += N) {
                sum += A[i];
            }
            break;
        case 2:
            for (int i = 0; i < N * N; i += N + 1) {
                sum += A[i];
            }
            break;
        case 3:
            for (int i = iq; q < N * N; i++) {
                if (i > q) {
                    q += N + 1;
                    iq += N;
                    i = iq - 1;
                    continue;
                }
                sum += A[i];
            }
            break;
        case 4:
            for (int i = N - 1; i <= (N * N) - N; i += N - 1) {
                sum += A[i];
            }
            break;
        default:
            printf("Wprowadzone zle dane");
            exit(0);
    }
    return sum;
}