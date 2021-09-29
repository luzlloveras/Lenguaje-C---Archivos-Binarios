// Archivos Binarios
// Problema propuesto

#include <stdio.h>
#include <stdlib.h>

struct ALUMNO {
	char NOM[20];
	char SEX;
	int EDAD;
};

int main ()
{
	FILE * FP;
	struct ALUMNO X;
	int TAM_ARCH;
	char CAR;
	
	if ( (FP = fopen ("BD", "rb")) == NULL ) {
		printf("\n\n ERROR APERTURA DE ARCHIVO \n\n");
		exit(1);
	}
	
	TAM_ARCH = 0;
	
	CAR = getc(FP);
	while (!feof(FP)) {
		TAM_ARCH++ ;
		CAR = getc(FP);
	}
	
	fclose(FP);
	
	printf("\n\n\t\t TAMAÑO DEL ARCHIVO = %d", TAM_ARCH);
	printf("\n\n\t\t TAMANIO DE X = %d", sizeof(X));
	printf("\n\n\t\t CANTIDAD DE REGISTROS = %d", TAM_ARCH/sizeof(X));
	getchar();
	
	if ( (FP = fopen ("BD", "rb")) == NULL ) {
		printf("\n\n ERROR DE APERTURA DE ARCHIVO");
		exit(1);
	};
	
	printf("\n\n\t %-20s %10s %10s\n\n" ,"NOMBRE","SEXO","EDAD");
	while ( ! feof(FP)) {
			fread ( &X , sizeof(X) , 1 , FP );
			printf("\n\n\t %-20s %10c %10d" ,
			X.NOM , X.SEX , X.EDAD );
	}
				
	fclose(FP);
	
	printf("\n\n");
	return 0 ;
}
