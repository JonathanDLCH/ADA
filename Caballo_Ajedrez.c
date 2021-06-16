/*
	BUAP
	Ingenieria en Ciencias de la Computación

	Caballo de Ajedrez

	Jonathan De La Cruz Huerta	201731754
	Christiam Parraguirre Lagunes	
*/
#include <stdio.h>
#include <stdlib.h>

#define N 7

int iter=0;

void cargar_tablero(int tablero[][N]);
void mostrar(int tablero[][N]);
int final(int tablero[][N]);
void backtraking(int tablero[][N],int numero,int x, int y);

int main(int argc, char *argv[]){
	int tablero[N][N];
	int columna=0;
	int fila=0;

	cargar_tablero(tablero);
	tablero[columna][fila]=1;
	backtraking(tablero,2,columna,fila);
	printf("Solucion\ncolumna->%d fila->%d numero de iteraciones %d \n\n",columna,fila,iter);
	mostrar(tablero);
	return 0;
}

void cargar_tablero(int tablero[][N]){
	int i,j;
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			tablero[i][j]=0;
		}
	}
}

void mostrar(int tablero[][N]){
	int i,j;
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			printf(" %2d ",tablero[j][i] );
		}
		printf("\n\n");
	}
}

int final(int tablero[][N]){
	int i,j;
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			if(tablero[j][i]==0){
				return 0;
			}
		}
	}
	return 1;
}

void backtraking(int tablero[][N],int numero,int x, int y){
	int arrx[]={1,2,2,1,-1,-2,-2,-1};
	int arry[]={-2,-1,1,2,2,1,-1,-2};
	int newx=0;
	int newy=0;
	int indice=0;

	while(indice<8 && final(tablero)!=1){

		newx=arrx[indice]+x;
		newy=arry[indice]+y;

		if((tablero[newx][newy]==0) && (newx<N && newx>=0 && newy<N && newy>=0)){
			tablero[newx][newy]=numero;

			if(numero!=N*N){
				backtraking(tablero,numero+1,newx,newy);
			}
		}

		indice++;
		iter++;
	}
	if(final(tablero)!=1){
		tablero[x][y]=0;
	}
}

