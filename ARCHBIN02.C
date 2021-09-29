// Archivos Binarios
// Lectura en un archivo binario

#include <stdio.h>
#include <stdlib.h>

struct ALUMNO {
	char NOM[20];
	char SEX;
	int EDAD;
};

#define N 8

int main ()
{

	FILE * FP;
	struct ALUMNO X;
	
	if ( (FP = fopen("BD", "rb")) == NULL ) {
		printf("\n\n Error apertura de archivo \n\n");	
		exit(1);
	}; 
	
		printf("\n\n\t %-20s %10s %10s", "NOMBRE", "SEXO", "EDAD");
		fread ( &X, sizeof(X), 1, FP );
		while ( ! feof(FP) ){
			printf("\n\n\t %-20s %10c %10d", X.NOM, X.SEX, X.EDAD);
			
			fread ( &X, sizeof(X), 1, FP );
		}
		
	fclose(FP);
		
	return 0;
}
