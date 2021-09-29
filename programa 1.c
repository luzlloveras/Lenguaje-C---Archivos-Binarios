/*  LA BASE DE DATOS BDARTICULOS ESTA ESTRUCTURADA DE LA SIGUIENTE MANERA */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ARTI {
	short int ART ;
	char COD[50];
	char DESC[100];
	char FAB[50];
	short int STOCK ;
};

/*

1.  HACER UN PROGRAMA DE LECTURA -
2.  MOSTRAR LOS ARTICULOS CUYO STOCK ES MENOR QUE 8 -
3.  DETERMINAR QUIEN ES EL PROVEEDOR QUE MAS ARTICULOS SUMINISTRA -
4.  PERMITIR EL INGRESO DE UN #ART Y BUSCARLO
5.  INDEXAR EL ARCHIVO
6.  ORDENAR EL INDICE
7.  REPETIR EL PUNTO 4 CON UNA BUSQUEDA BINARIA INDEXADA.

*/

int main()
{
	FILE * FP ;
	struct ARTI X;
	int stock_max = 0;
	char fabricante[50];
				
	if ( (FP = fopen ("BD","rb")) == NULL ) {
	printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
	exit(1);			
	};
		
	printf("\n\n\t %-10s %-20s %-40s %-20s %-10s\n\n" ,"INT","COD","DESC", "FAB", "STOCK");
	fread ( &X , sizeof(X) , 1 , FP );

	while ( ! feof(FP)) {
		printf("\n\n\t %-10d %-20s %-40s %-20s %-10d",X.ART , X.COD , X.DESC, X.FAB, X.STOCK );
	/*	if (X.STOCK < 8)
			printf("\n\n\t %-10d %-20s %-40s %-20s %-10d",X.ART , X.COD , X.DESC, X.FAB, X.STOCK );*/
		
		if(X.STOCK>stock_max) {
			stock_max = X.STOCK;
			strcpy(fabricante, X.FAB);
		}

		fread ( &X , sizeof(X) , 1 , FP );
	}
	
	printf("\n\nEl fabricante con mas suministros es %s con un stock de %d", fabricante, stock_max);
	getchar();
	printf("\n\n");
	return 0 ;
}

