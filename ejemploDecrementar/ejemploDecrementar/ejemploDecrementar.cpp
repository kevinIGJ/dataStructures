// ejemploDecrementar.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

void decrementa_iterativa(int a)
{
	int i;
	for (i = a; i>0; i--)
		printf("%d ", i);
	printf("Fin del algoritmo iterativo \n");
}
void decrementa_recursiva(int a)
{
	if (a>0) //CONDICIÓN DE PARADA: a==0
	{
		printf("%d ", a);
		decrementa_recursiva(a - 1); /*PASO DE LA RECURSIVIDAD*/
	}
	else
		printf("Fin del algoritmo recursivo \n");
}

int main()
{
	int a;
	cout << "Dame un numero a decrementar" << endl;
	cin >> a;
	cout << "Asi se decrementa con una funcion iterativa" << endl;
	decrementa_iterativa(a);
	cout<< endl;
	cout << "Asi se decrementa con una funcion recursiva" << endl;
	decrementa_recursiva(a);
	_getch();
    return 0;
}

