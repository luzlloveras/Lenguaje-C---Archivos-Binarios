/* ARCHIVOS BINARIOS */  
/* MODIFICACIONES duplicar edad de laura */  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ALUMNO {
		char NOM[20] ;
		char SEX ;
		int EDAD ;
};

int main()
{
		FILE * FP;
		struct ALUMNO X ;
		int ENCONTRADO;
						
		if ( (FP = fopen ("BD","r+b")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);			
		};
		
		ENCONTRADO = 0;
		fread ( &X , sizeof(X) , 1 , FP );
		while ( ! feof(FP) && !ENCONTRADO ) {
				if ( ! strcmp(X.NOM, "LAURA" )) {
				X.EDAD = 2 * X.EDAD ;
				fseek(FP, (long)(-1)*sizeof(X), SEEK_CUR);
				fwrite ( &X , sizeof(X) , 1 , FP );			
				ENCONTRADO = 1;	
				}
				fread ( &X , sizeof(X) , 1 , FP );
		}
					
		fclose(FP);	


	
		printf("\n\n");
		return 0 ;
}
