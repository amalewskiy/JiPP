//Nr albumu: 135688
//Nr projektu: 33

#include "function.h"
#define MAX_ARR 20

int main() {
    int N;
    printf("Podaj rozmiar macierzy N (min 1, max %d): ", MAX_ARR);
    scanf("%d", &N);
    if (N < 1 || N > MAX_ARR) error(1);
    float B[N][N];
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = (float) rand() / (float) (RAND_MAX / 50.0); //losuje od 0 do 50
            printf("%f ", B[i][j]);
        }
        printf("\n");
    }
    printf("Srednia arytmetyczna: %f", arithmeticAverage(B, N));
    return 0;
}