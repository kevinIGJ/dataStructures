#include "stdafx.h"
#include "Hanoi.h"



Hanoi::Hanoi()
{
}


Hanoi::~Hanoi()
{
}

void Hanoi::mover(int disco, int a, int b, int c)
{
	contar++;
	if (disco == 1)
		cout << "Mueve el disco " << disco << " del poste: " << a << " al poste: " << b << endl;
	else
	{
		mover(disco - 1, a, c, b);
		cout <<"Mueve el disco " << disco << " del poste: " << a << " al poste: " << b << endl;
		mover(disco - 1, c, b, a);
	}
}
