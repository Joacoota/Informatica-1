#include <stdio.h>
#include <stdlib.h>

#define N_MAX 10
#define M_MAX 10

// Estructura para guardar las matrices
typedef struct {
	int filas;
	int columnas;
	float mat[N_MAX][M_MAX];
} matrix_t;

// Prototipos
void cargar_matriz(matrix_t *p, char *file);
void sumar_matrices(matrix_t A, matrix_t B, matrix_t *pC);
void imprimir_matriz(matrix_t m);
void guardar_matriz(matrix_t m, char *file);

int main(void) {
	matrix_t A = {0}, B = {0}, C = {0};
	
	// Carga de matrices desde los archivos
	cargar_matriz(&A, "mat_A.txt");
	cargar_matriz(&B, "mat_B.txt");
	
	printf("Matriz A:\n");
	imprimir_matriz(A);
	
	printf("\nMatriz B:\n");
	imprimir_matriz(B);
	
	// Suma de matrices A + B
	sumar_matrices(A, B, &C);
	
	printf("\nMatriz resultante (A + B):\n");
	imprimir_matriz(C);
	
	// Guardar la matriz resultado en un archivo nuevo
	guardar_matriz(C, "mat_C.txt");
	
	return 0;
}

// Función que carga una matriz desde un archivo
void cargar_matriz(matrix_t *p, char *file) {
	FILE *f = fopen(file, "r");
	if (f == NULL) {
		printf("Error al abrir el archivo %s\n", file);
		exit(1);
	}
	
	fscanf(f, "%d %d", &p->filas, &p->columnas);
	
	for (int i = 0; i < p->filas; i++) {
		for (int j = 0; j < p->columnas; j++) {
			fscanf(f, "%f", &p->mat[i][j]);
		}
	}
	
	fclose(f);
}

// Muestra la matriz por pantalla
void imprimir_matriz(matrix_t m) {
	for (int i = 0; i < m.filas; i++) {
		for (int j = 0; j < m.columnas; j++) {
			printf("%8.2f", m.mat[i][j]);
		}
		printf("\n");
	}
}

// Suma de matrices A y B  resultado guarda en C
void sumar_matrices(matrix_t A, matrix_t B, matrix_t *pC) {
	if (A.filas != B.filas || A.columnas != B.columnas) {
		printf("Error: las matrices no tienen las mismas dimensiones.\n");
		exit(1);
	}
	
	pC->filas = A.filas;
	pC->columnas = A.columnas;
	
	for (int i = 0; i < A.filas; i++) {
		for (int j = 0; j < A.columnas; j++) {
			pC->mat[i][j] = A.mat[i][j] + B.mat[i][j];
		}
	}
}

// Guarda la matriz en un archivo de texto
void guardar_matriz(matrix_t m, char *file) {
	FILE *f = fopen(file, "w");
	if (f == NULL) {
		printf("Error al guardar el archivo %s\n", file);
		exit(1);
	}
	
	fprintf(f, "%d %d\n", m.filas, m.columnas);
	
	for (int i = 0; i < m.filas; i++) {
		for (int j = 0; j < m.columnas; j++) {
			fprintf(f, "%.2f ", m.mat[i][j]);
		}
		fprintf(f, "\n");
	}
	
	fclose(f);
}
