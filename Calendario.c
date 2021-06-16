/*
	BUAP
	Ingenieria en Ciencias de la Computación

	Calendario

	Jonathan De La Cruz Huerta	201731754
	Christiam Parraguirre Lagunes	
*/

#include <stdio.h>
#define n 8 //Participantes
int calendario[n][n-1]; //Participante-dia

void formar_tabla(int tabla[][n-1],int primero,int ultimo);
void completar_tabla(int tabla[][n-1],int equipoInf,int equipoSup,int diaInf,int diaSup,int equipoInicial);

int main(int argc, char *argv[]){
	int i,j;
	char equipo[]={"T E A M     "};
	formar_tabla(calendario,1,n);
	printf("-------Dia del torneo-------\n");
	for (i=0; i<n; i++){
		for (j=0; j<n-1; j++){
			printf(" %2d ",calendario[i][j]);
		}
		printf("\n%c",equipo[i]);
	}
	return 0;
}

void formar_tabla(int tabla[][n-1],int primero,int ultimo){
	int medio;

	if((ultimo-primero)==1){ //Caso base
		tabla[primero-1][0]=ultimo;
		tabla[ultimo-1][0]=primero;
	}else{
		medio=(primero+ultimo)/2;
		formar_tabla(tabla,primero,medio);
		formar_tabla(tabla,medio+1,ultimo);

		completar_tabla(tabla,primero,medio,medio-primero+1,ultimo-primero,medio+1);
		completar_tabla(tabla,medio+1,ultimo,medio-primero+1,ultimo-primero,primero);
	}
}

void completar_tabla(int tabla[][n-1],int equipoInf,int equipoSup,int diaInf,int diaSup,int equipoInicial){
	int i,j;
	for (j=diaInf; j<=diaSup; j++){
		tabla[equipoInf-1][j-1]=equipoInicial+j-diaInf;
	}

	for (i=equipoInf; i<equipoSup; i++){
		tabla[i][diaInf-1]=tabla[i-1][diaSup-1];

		for (j=diaInf; j<diaSup; j++){
			tabla[i][j]=tabla[i-1][j-1];
		}
	}
}