// proyectolista.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "Lista.h"
#define cantidad 5
void main() {
	CLista mylist;
	mylist.MostrarTodos();
	 
	for (int i = 1; i <= cantidad; i++) {
		int aux;
		cout << "Dame un valor a insertar" << endl;
		cin >> aux;
		mylist.Insertar(aux);
	}
	cout << endl << endl;

	mylist.MostrarTodos();

		
}


