#include <iostream>
#include <stdio.h>

static int q = 0;

void zad8(int (&arr)[10]) {
    arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 10 + 0;
    }
    printf("\nRozmiar tablicy po jej uzupelnieniu: %d bajtow", sizeof(arr));
}

void zad9(int *arr) {
    q++;
    printf("\nTablica: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
}

void zad11() {
    int array[5];
    printf("\nNowa 5-elementowa tablica: ");
    for(int i = 0; i < 5; i++){
        array[i] = rand() % 10 + 0;
        printf("%d ", array[i]);
    }
    int *arr = array;
    printf("\nPierwszy 3 znaki tej tablicy: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", *arr++);
    }
}

int main() {
    srand(time(NULL));
    int arr[10];
    printf("Rozmiar tablicy po jej deklaracji: %d bajtow", sizeof(arr));
    zad8(arr);
    zad9(arr);
    zad11();
    printf("\nFunkcja zad9 byla wywolana %d raz", q);
    return 0;
}
