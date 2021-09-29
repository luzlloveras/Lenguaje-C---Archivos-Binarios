/* ARCHIVOS BINARIOS */  
/* BAJAS EN UN ARCHIVO BINARIO */  
/* USANDO UN ARCHIVO AUXILIAR */ 

#include <stdio.h>
#include <stdlib.h>

struct ALUMNO {
		char NOM[20] ;
		char SEX ;
		int EDAD ;
};


int main()
{
		FILE * FP , * FPAUX ;
		struct ALUMNO X ;
				
		if ( (FP = fopen ("BD","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);			
		};
		
		if ( (FPAUX = fopen ("BDAUX","wb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);			
		};
		
		fread ( &X , sizeof(X) , 1 , FP );
		while ( ! feof(FP)) {
				if ( X.SEX == 'F' )
					fwrite ( &X , sizeof(X) , 1 , FPAUX );
				
				fread ( &X , sizeof(X) , 1 , FP );
		}
				
		fclose(FP);
		fclose(FPAUX);
		
		remove ("BD");
		rename ("BDAUX","BD");
		
		printf("\n\n");
		return 0 ;
}
