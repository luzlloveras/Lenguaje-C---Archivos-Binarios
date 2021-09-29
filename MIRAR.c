/* ARCHIVOS BINARIOS */  
/* LECTURA DE UN ARCHIVO BINARIO */  

#include <stdio.h>
#include <stdlib.h>

struct ALUMNO {
		char NOM[20] ;
		char SEX ;
		int EDAD ;
};


int main()
{
		FILE * FP ;
		struct ALUMNO X ;
				
		if ( (FP = fopen ("BD","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);			
		};
		
		printf("\n\n\t %-20s %10s %10s\n\n" ,"NOMBRE","SEXO","EDAD");
		fread ( &X , sizeof(X) , 1 , FP );
		while ( ! feof(FP)) {
				printf("\n\n\t %-20s %10c %10d" ,
				X.NOM , X.SEX , X.EDAD );
				
				fread ( &X , sizeof(X) , 1 , FP );
		}
				
		fclose(FP);
		
		printf("\n\n");
		return 0 ;
}
