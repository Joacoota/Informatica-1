#include <stdio.h>
#include <stdlib.h>

#define TAM_NOMBRE_ESTUDIANTE 80
#define TAM_NOMBRE_MATERIA 80

typedef struct {
	char nombre[TAM_NOMBRE_MATERIA];
	int cantidad_parciales;
	int *parcial;
	float promedio;
} materia_t;

struct estudiante {
	int legajo;
	char nombre[TAM_NOMBRE_ESTUDIANTE];
	int cantidad_materias;
	materia_t *materia;
};

struct estudiante cargar_estudiante(void);
void imprimir_estudiante(struct estudiante);
materia_t* reservar_materias(int);
void liberar_materias(materia_t*);
int* reservar_parciales(int);
void liberar_parciales(int*);
void cargar_materia(materia_t*);
void cargar_parciales(materia_t*);

int main(void) {
	struct estudiante est1;
	
	est1 = cargar_estudiante();
	cargar_materia(est1.materia);
	
	imprimir_estudiante(est1);
	
	liberar_parciales(est1.materia->parcial);
	liberar_materias(est1.materia);
	
	return 0;
}

struct estudiante cargar_estudiante(void) {
	struct estudiante e;
	
	printf("Ingrese legajo del estudiante: ");
	scanf("%d", &e.legajo);
	
	printf("Ingrese nombre del estudiante: ");
	scanf(" %80[^\n]s", e.nombre);
	
	e.cantidad_materias = 1;
	e.materia = reservar_materias(e.cantidad_materias);
	
	return e;
}

void imprimir_estudiante(struct estudiante e) {
	printf("%10d %s", e.legajo, e.nombre);
	
	for (int i = 0; i < e.materia->cantidad_parciales; i++)
		printf(" %d", e.materia->parcial[i]);
	
	printf("\n");
}

void cargar_materia(materia_t *p) {
	printf("Ingrese el nombre de la materia: ");
	scanf(" %80[^\n]s", p->nombre);
	printf("¿Cuántos parciales tiene %s? ", p->nombre);
	scanf("%d", &p->cantidad_parciales);
	
	p->parcial = reservar_parciales(p->cantidad_parciales);
	
	cargar_parciales(p);
}

void cargar_parciales(materia_t *p) {
	int nota;
	for (int i = 0; i < p->cantidad_parciales; i++) {
		do {
			printf("Ingrese calificación del %d° parcial (1-10): ", i + 1);
			scanf("%d", &nota);
			if (nota < 1 || nota > 10) {
				printf("??  Nota inválida. Debe estar entre 1 y 10.\n");
			}
		} while (nota < 1 || nota > 10);
		p->parcial[i] = nota;
	}
	
}

materia_t* reservar_materias(int n) {
	materia_t *p = malloc(n * sizeof(materia_t));
	if (p == NULL) {
		printf("No se pudo reservar memoria. Fin del programa.\n");
		exit(1);
	}
	return p;
}

int* reservar_parciales(int n) {
	int *p = malloc(n * sizeof(int));
	if (p == NULL) {
		printf("No se pudo reservar memoria. Fin del programa.\n");
		exit(1);
	}
	return p;
}

void liberar_parciales(int *p) {
	if (p != NULL)
		free(p);
}

void liberar_materias(materia_t *p) {
	if (p != NULL)
		free(p);
}
