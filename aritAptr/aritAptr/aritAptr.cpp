// aritAptr.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "conio.h"
#include <iostream>
#include <cmath>
using namespace std;



int main()
{
	double x[5] = { 1.1, 2.1, 3.1, 4.1, 5.1 };
	double *p = &x[1];
		double *q = &x[4];
	int n;
	n = q - p;
	cout << n << endl;
	cout << pow(2, n)<<endl;
	_getch();
}

