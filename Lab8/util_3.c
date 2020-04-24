#include<stdio.h>
#include<stdlib.h>

void DodWekt(double *w1, double *w2, double *w3, int n) {
    for (int k = 0; k < n; k++) {
        w1[k] = w2[k] + w3[k];
    }
}

double IloczynSkal(double *w1, double *w2, int n) {
    double s = 0;
    for (int k = 0; k < n; k++) {
        s += w1[k] * w2[k];
    }
    return s;
}

double MaxElem(double *w, int n) {
    double mxy = w[0];
    for (int k = 0; k < n; k++) {
        mxy = w[k] > mxy ? w[k] : mxy;
    }
    return mxy;
}