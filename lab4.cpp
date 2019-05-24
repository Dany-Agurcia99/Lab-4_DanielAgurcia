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
void LlenarMatriz(char**,string,int,int);
int ConteoSafe(char**,int,int);
//main
int main(){
	char resp='s';
	while(resp=='s'||resp=='S'){
		int filas;
		int columnas;
		string patron;
		char** matrix=NULL;
		//pedir datos
		cout<< "Ingrese las filas de la matriz: "<<endl;
		cin>> filas;
		cout<<"Ingrese las columnas de la matriz: "<<endl;
		cin>> columnas;
		cout<< "Ingrese en un string el patron de la primera fila: ";
		cin>> patron;
		int vali = Validar(patron);
		//validacion
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
		//utilizacion de metodos
		matrix=CrearMatriz(filas,columnas);
		LlenarMatriz(matrix,patron,filas,columnas);
		ImprimirMatriz(matrix,filas,columnas);
		int CasillasSafe = ConteoSafe(matrix,filas,columnas);
		cout<<"El numero de casillas seguras es de: "<<CasillasSafe<<endl;
		LiberarMatriz(matrix,filas);
		cout<<"Desea volver a entrar?[s/n]"<<endl;
		cin>>resp;
	}
return 0;
}
//Crear Matriz
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
//Liberar Matriz
void LiberarMatriz(char** matrix,int size){
	for(int i=0;i<size;i++){
		if(matrix[i]!=NULL){
			delete[] matrix[i];
			matrix[i]=NULL;
		}
	}
	delete[] matrix;
}
//Imprimir Matriz
void ImprimirMatriz(char** matrix,int filas, int columnas){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<"["<<matrix[i][j]<<"]"; 
		}
		cout<<endl;
	}

}
//Validacion del patron
int Validar(string cadena){
	int vali=1;
	for(int i=0;i<cadena.length();i++){
		if(cadena[i]!='.'&&cadena[i]!='^'){
			vali=0;
		}
	}
	return vali;
}
//llenado de la matriz
void LlenarMatriz(char** matrix,string patron,int filas, int columnas){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(i==0){
				matrix[i][j]=patron[j];
			}else{
				if(j==0){
					if(matrix[i-1][j]=='.' && matrix[i-1][j+1]=='^'){
						matrix[i][j]='^';
					}else if(matrix[i-1][j]=='^' && matrix[i-1][j+1]=='^'){
						matrix[i][j]='^';
					}else{
						matrix[i][j]='.';
					}
				}else if(j==patron.length()-1){
					if(matrix[i-1][patron.length()-2] == '^'&&matrix[i-1][patron.length()-1]=='^'){
						matrix[i][j]='^';
					}else if(matrix[i-1][patron.length()-2] =='^'&&matrix[i-1][patron.length()-1]=='.'){
						matrix[i][j]='^';
					}else{
						matrix[i][j]='.';
					}
				}else{
					if(matrix[i-1][j-1]=='^'&&matrix[i-1][j]=='^'&&matrix[i-1][j+1]=='.'){
						matrix[i][j]='^';
					}else if(matrix[i-1][j-1]=='.'&&matrix[i-1][j]=='^'&&matrix[i-1][j+1]=='^'){
						matrix[i][j]='^';
					}else if(matrix[i-1][j-1]=='^'&&matrix[i-1][j]=='.'&&matrix[i-1][j+1]=='.'){
						matrix[i][j]='^';
					}else if(matrix[i-1][j-1]=='.'&&matrix[i-1][j]=='.'&&matrix[i-1][j+1]=='^'){
						matrix[i][j]='^';
                                        }else{
						matrix[i][j]='.';
					}
				}
			}
		}
	}
}
//conteo de las casillas seguras
int ConteoSafe(char** matrix,int filas,int columnas){
	int cont=0;
	for(int i=0;i<filas;i++){
                for(int j=0;j<columnas;j++){
                        if(matrix[i][j]=='.'){
				cont++;
			}
                }
                cout<<endl;
        }
	return cont;
}
