#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;

//metodos
char** CrearMatriz(int,int);
void LiberarMatriz(char**,int);
void ImprimirMatriz(char**,int,int);
int Validar(string);
void LLenarMatriz(char**,string,int,int);
//main
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
		int vali = Validar(patron);
		cout<<"vali: "<<vali<<endl;
		cout<<"tam: "<<patron.length()<<endl;
		while(patron.length()!=columnas||vali==0){
			if(patron.length()!=columnas){
				cout<< "El patron tiene que tene la misma longitud que sus columnas("<<columnas<<")"<<endl;
				cout<< "Ingrese en un string el patron de la primera fila: ";
                		cin>> patron;
			}else{
				cout<< "El patron tiene caracteres incorrectos"<<endl;
                        	cout<< "Ingrese en un string el patron de la primera fila: ";
                        	cin>> patron;
			}
		}
		cout<< endl;
		matrix=CrearMatriz(filas,columnas);
		LlenarMatriz(matrix,patron,filas,columnas);
		ImprimirMatriz(matrix,filas,columnas);
		LiberarMatriz(matrix,filas);
		cout<<"Desea volver a entrar?[s/n]"<<endl;
		cin>>resp;
	}
return 0;
}

char** CrearMatriz(int filas,int columnas){
	char** matrix = new char*[filas];
	for(int i=0;i<filas;i++){
		matrix[i]=new char[columnas];
	}
	for(int j = 0;j<filas;j++)
		for(int k = 0; k<columnas;k++)
			matrix[j][k]=' ';

	return matrix;
}
void LiberarMatriz(char** matrix,int size){
	for(int i=0;i<size;i++){
		if(matrix[i]!=NULL){
			delete[] matrix[i];
			matrix[i]=NULL;
		}
	}
	delete[] matrix;
}
void ImprimirMatriz(char** matrix,int filas, int columnas){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<"["<<matrix[i][j]<<"]"; 
		}
		cout<<endl;
	}

}
int Validar(string cadena){
	int vali=1;
	for(int i=0;i<cadena.length();i++){
		cout<<"cadena["<<i<<"]= "<<cadena[i]<<endl;
		if(cadena[i]!='*'&&cadena[i]!='^'){
			vali=0;
		}
	}
	cout<<"vali: "<<vali<<endl;
	return vali;
}
void LLenarMatriz(char** matrix,string patron,int filas, int columnas){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(i==0){
				matrix[i][j]=patron[j];
			}
			if(j==1){

			}
			if(j==patron.length()-1){

			}
		}
	}
}
