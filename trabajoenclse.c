#include <stdio.h> 
#include <stdlib.h> 

void diagonalizeMatrix(int n, double *matrix) { int lda = n; int info; double *work = (double *)malloc(3 * n * sizeof(double)); double *w = (double *)malloc(n * sizeof(double));

// Diagonalizamos la matriz
info = LAPACKE_dsyev( 'V', 'U', n, matrix, lda, w);

// revisamos 
printf("Eigenvalues:\n");
for (int i = 0; i < n; ++i) {
    printf("%lf\n", w[i]);
}

// memeoria libre
free(work);
free(w);
}

int main() { int n;

// Pedri el ingreso de los datos
printf("Enter the size of the square matrix: ");
scanf("%d", &n);

// Revisar los datos de una matriz
double *matrix = (double *)malloc(n * n * sizeof(double));

// Inicializamos en 0
for (int i = 0; i < n * n; ++i) {
    matrix[i] = 0.0;
}

// Llamamos a la funcion
diagonalizeMatrix(n, matrix);


free(matrix);

return 0;
}