// ejercicioFactorial.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "conio.h"
#include <iostream>
using namespace std;
int factorial(int n)
{
	int fact;
	if (n == 0) /* CONDICIÓN DE PARADA */
		fact = 1;
	else
		fact = n * factorial(n - 1);
	return(fact);
}

int main()
{
	int a;
	cout << "Dame un numero del que quieras el factorial" << endl;
	cin >> a;
	cout << endl;
	cout<<"El factorial de "<<a<<" es "<<factorial(a);
	_getch();
    return 0;
}

