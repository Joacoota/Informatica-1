#include <stdio.h>
#include <math.h>

///////////////PROTOTIPOS//////////////
float calcularPerimetro (float, float);
float calcularArea (float, float);
float calcularDiagonal (float, float);
float calcularAreaCir (float);
float calcularPerimetroCir (float);
void ImprimirResultados (float , float, float);
float rectangulo (void);
float circulo (void);


/////////////////FUNCIONES///////////////////////////
float calcularArea ( float base, float altura){ //Area Rectangulo
	float area;
	area = base * altura;
	
return area;	
}

float calcularPerimetro (float base, float altura){ ////Perimetro Rectangulo
	float perimetro;
	perimetro = (base*2 + altura*2);

return perimetro;
}

float calcularDiagonal ( float base, float altura){ //Diagonal Rectangulo
	float diagonal;
	diagonal = sqrt((base*base)+(altura*altura));

return diagonal;
}

float calcularAreaCir (float radio){
	float areaC;
	areaC = (M_PI*(pow(radio,2)));

return areaC;
}

float calcularPerimetroCir (float radio){
	float perimetroC;
	perimetroC = (2*M_PI*radio);

return perimetroC;
}
	
void ImprimirResultados(float A, float P, float D){
	printf("El area es %.2f cm\n", A);
	printf("El perimetro es de %.2f cm\n", P);

	if (D>=0){
		printf("La diagonal es de %.2f cm\n", D);
	}
	
}
	
float rectangulo (void){
	float a, b, A, P, D;
	printf("opcion del rectangulo seleccionada: \n");
	
	printf("ingrese los valores de base y altura: ");
	scanf("%f %f", &a, &b);

	A = calcularArea(a, b);
	P = calcularPerimetro(a, b);
	D = calcularDiagonal(a, b);

	ImprimirResultados(A, P, D);

return 0;
}
	
	
float circulo(void){
	float a, A, P;
	printf("opcion del circulo seleccionada: \n");

	printf("ingrese el radio del circulo: ");
	scanf("%f", &a);
	
	A = calcularAreaCir(a);
	P = calcularPerimetroCir(a);

	ImprimirResultados(A, P, -1100);
	
return 0;
}





int main(int argc, char *argv[]) {
	int i;

	printf("seleccione la figura que desea calcular:\n 1) rectangulo \n 2) circulo\n ");
	scanf("%d", &i);

	switch (i){
		case 1:
			rectangulo();
			break;
			
		case 2:
			circulo();
			break;
			
		default:
			printf("Esta no es una opcion valida");
			break;
		}
		
return 0;
}
