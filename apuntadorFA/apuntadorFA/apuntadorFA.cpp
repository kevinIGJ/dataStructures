// apuntadorFA.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "conio.h"
#include <iostream>
using namespace std;


int main()
{
	float fa = 20.9, fb = 100.0;
	float *flp, *flq;
	flp = &fa;
	flq = &fb;	++*flp;
	(*flp)++;
	cout << *flp << endl;
	flq = flp;
	cout << *flq << endl;
	_getch();
}


