// torreDeHanoi.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Hanoi.h"

int main()
{
	Hanoi torre;
	int disco, a, b, c;
	cout<< "Cuantos discos va a jugar" << endl;
	cin >> disco;
	torre.mover(disco, 1, 3, 2);
	_getch();
    return 0;
}

