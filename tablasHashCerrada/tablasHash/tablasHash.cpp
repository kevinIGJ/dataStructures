#include "pch.h"
#include <conio.h>
#include "Cerrada.h"


int main() {
	cout << "El tamaño de la tabla es 10" << endl; // 10 en este caso de prueba
	CCerrada tabla(10);
	cout << "El numero primo mas cercano es: " << tabla.Primo() << endl;//verifica el numero primo mas cercano de la funcion h2
	tabla.Insertar(5); //modulo 10 se guarda en la posicion 5
	tabla.Insertar(11);
	tabla.Insertar(102);
	tabla.Insertar(333);
	tabla.Insertar(15); //modulo 10 se guardaria en la posicion 5, por lo que se hace la iteracion 
	cout << "Esta es toda la tabla" << endl;
	tabla.Mostrar();
	cout << "El valor en la posicion 3 es: " << tabla.Buscar(3)<<endl;
	_getch();
}
