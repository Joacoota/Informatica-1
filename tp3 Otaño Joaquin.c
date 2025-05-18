#include <stdio.h>

int main() {
	
	float peso, altura, imc;
	
	// Datos al usuario
	printf("Ingrese el peso en kg: ");
	scanf("%f", &peso);
	
	printf("Ingrese la altura en metros: ");
	scanf("%f", &altura);
	
	// Calculo del IMC 
	imc = peso / (altura * altura);
	
	// resultado del IMC
	printf("\nSu índice de masa corporal es: %.2f\n", imc);
	
	// categoría
	printf("Condición: ");
	if (imc < 18.5) {
		printf("Bajo peso\n");
	} else if (imc < 25.0) {
		printf("Normal\n");
	} else if (imc < 30.0) {
		printf("Sobrepeso\n");
	} else {
		printf("Obesidad\n");
	}
	
	//  Tabla de referencia
	printf("\n Indice         | Condición\n");
	printf("\n");
	printf("< 18.5         | Bajo peso\n");
	printf("18.5 a 24.9    | Normal\n");
	printf("25.0 a 29.9    | Sobrepeso\n");
	printf(">= 30          | Obesidad\n");
	
	return 0;
}
