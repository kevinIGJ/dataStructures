// ejercicioFila.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Fila.h"
#include <conio.h>
#include <iostream>
using namespace std;
#define datos 10;

void main(){
	int valor;
	CFila mifila;
	cout<<"¿Cuantos elementos quieres?"<<endl;
	cin>>valor;
	cout<<endl<<endl;
	cout<<"   La fila es la siguiente:"<<endl;
	for(int i=1;i<=valor;i++)
		mifila.Agregar(i);
	for(int i=1;i<=valor;i++)
		cout<<"   "<<mifila.Leer()<<endl;

	_getch();
}
