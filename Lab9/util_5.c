void DodMac(double **ma1, double **ma2, double **ma3, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ma3[i][j] = ma1[i][j] + ma2[i][j];
        }
    }
}

void Mac_x_Wekt(double **ma, double *we, double *wy, int n, int m) {
    for (int i = 0; i < n; i++) {
        double r = 0;
        for (int k = 0; k < m; k++)
            r += ma[i][k] * we[k];
        wy[i] = r;
    }
}

void Mac_x_Mac(double **x, double **y, double **z, int n, int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            double r = 0;
            for (int k = 0; k < m; k++) {
                r += x[i][k] * y[k][j];
            }
            z[i][j] = r;
        }
    }
}