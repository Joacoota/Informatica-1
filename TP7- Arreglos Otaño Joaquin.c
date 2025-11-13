#include <stdio.h>
#define TAM 5

int main() {
	int cod[TAM];
	float precio[TAM];
	int i, posMax = 0, posMin = 0;
	
	printf("Ingrese %d productos, se pedira codigo y precio:\n\n", TAM);
	
	for (i = 0; i < TAM; i++) {
		// leer codigo valido
		do {
			printf("Codigo de barras (1 a 999999999): ");
			scanf("%d", &cod[i]);
			if (cod[i] < 1 || cod[i] > 999999999) {
				printf("Error, codigo fuera de rango\n");
			}
		} while (cod[i] < 1 || cod[i] > 999999999);
		
		// leer precio valido
		do {
			printf("Precio: ");
			scanf("%f", &precio[i]);
			if (precio[i] < 0) {
				printf("Error, el precio no puede ser negativo\n");
			}
		} while (precio[i] < 0);
		
		printf("\n");
	}
	
	// mostrar lista
	printf("Codigo        Precio\n\n");
	for (i = 0; i < TAM; i++) {
		printf("%-13d %.2f\n\n", cod[i], precio[i]);
	}
	
	// buscar mas caro y mas barato
	for (i = 1; i < TAM; i++) {
		if (precio[i] > precio[posMax]) posMax = i;
		if (precio[i] < precio[posMin]) posMin = i;
	}
	
	printf("Mas caro: [%d] %.2f\n", cod[posMax], precio[posMax]);
	printf("Mas barato: [%d] %.2f\n", cod[posMin], precio[posMin]);
	
	return 0;
}

