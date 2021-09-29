/* ARCHIVOS BINARIOS */  
/* BAJAS EN UN ARCHIVO BINARIO */  
/* USANDO UN ARCHIVO TEMPORAL */ 

#include <stdio.h>
#include <stdlib.h>

struct ALUMNO {
		char NOM[20] ;
		char SEX ;
		int EDAD ;
};


int main()
{
		FILE * FP , * FPTEMP ;
		struct ALUMNO X ;
				
		if ( (FP = fopen ("BD","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);			
		};
		
		if ( (FPTEMP = tmpfile () ) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO TEMPORAL \n\n") ;
				exit(1);			
		};
		
		fread ( &X , sizeof(X) , 1 , FP );
		while ( ! feof(FP)) {
				if ( X.SEX == 'F' )
						fwrite ( &X , sizeof(X) , 1 , FPTEMP );
				
				fread ( &X , sizeof(X) , 1 , FP );
		}
				
		fclose(FP);
		if ( (FP = fopen ("BD","wb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);			
		};
		
		rewind (FPTEMP);		
		
		fread ( &X , sizeof(X) , 1 , FPTEMP );
		while ( ! feof(FPTEMP)) {
				fwrite ( &X , sizeof(X) , 1 , FP );
				
				fread ( &X , sizeof(X) , 1 , FPTEMP );
		}
		
		fclose(FP);
		fclose(FPTEMP);
		
		
		printf("\n\n");
		return 0 ;
}
