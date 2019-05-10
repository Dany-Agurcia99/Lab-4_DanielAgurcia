#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;

char** CrearMatriz(int,int);
void LiberarMatriz(char**,int);
void ImprimirMatriz(char**,int,int);

int main(){
	char resp='s';
	while(resp=='s'||resp=='S'){
		int filas;
		int columnas;
		string patron;
		char** matrix=NULL;
		//pedir datos
		cout<< "Ingrese las filas de la matriz: ";
		cin>> filas;
		cout<< endl;
		cout<<"Ingrese las columnas de la matriz: ";
		cin>> columnas;
		cout<< endl;
		cout<< "Ingrese en un string el patron de la primera fila: ";
		cin>> patron;
		cout<< endl;
		matrix=CrearMatriz(filas,columnas);
		ImprimirMatriz(matrix,filas,columnas);
		LiberarMatriz(matrix,filas);
		cout<<"Desea volver a entrar?[s/n]"<<endl;
		cin>>resp;
	}
return 0;
}

char** CrearMatriz(int filas,int columnas){
	char** matrix = new char*[columnas];
	for(int i=0;i<filas;i++){
		matrix[i]=new char[columnas];
	}
	return matrix;
}
void LiberarMatriz(char** matrix,int size){
	for(int i=0;i<size;i++){
		if(matrix[i]!=NULL){
			delete[] matrix[i];
			matrix[i]=NULL;
		}
	}
}
void ImprimirMatriz(char** matrix,int filas, int columnas){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<"["<<matrix[i][j]<<"]"; 
		}
		cout<<endl;
	}

}
