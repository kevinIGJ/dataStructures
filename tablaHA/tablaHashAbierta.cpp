// tablaHashAbierta.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

//#include "pch.h"
#include <iostream>
#include "Abierta.h"

int main() {
	cout << "Valores de la tabla" << endl;
	CAbierta tabla(10);

	tabla.Insertar(1);
	tabla.Insertar(2);
	tabla.Insertar(3);
	tabla.Insertar(4);
	tabla.Insertar(5);
	tabla.Insertar(6);
	tabla.Insertar(7);
	tabla.Insertar(8);
	tabla.Insertar(9);
	tabla.Insertar(10);
	tabla.Insertar(11);
	tabla.Insertar(110);
	tabla.Insertar(321);
	tabla.Insertar(457);

	tabla.Mostrar();

	tabla.Buscar(500);
	tabla.Buscar(321);

	//_getch();
	return 0;
}

