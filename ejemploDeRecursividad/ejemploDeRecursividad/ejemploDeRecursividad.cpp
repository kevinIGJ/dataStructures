// ejemploDeRecursividad.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "conio.h"
#include <iostream>
using namespace std;
int magia(int n);

int factorial(int n) {
	if (n <= 1) return 1;
	else return n * factorial(n - 1);
}
int que(int n) {
	if (n <= 1) return n;
	else
		if (n%2 == 0) return magia((int)n / 2);
		else return 1 + magia(n * 3 + 1);
}
int magia(int n) {
	if (n == 1) return 1;
	else
		if ((n%2) == 1) return que(n - 1);
		else return que((int)n / 2);
}

int main()
{
	int a;
	cout << "Introdusca un numero a calcular el factorial y a hacer magia" <<endl;
	cin >> a;
	cout << "El factorial de " << a << " es " << factorial(a) << " la magia con "<< a <<" es "<<magia(a)<<endl;
	_getch();
    return 0;
}

