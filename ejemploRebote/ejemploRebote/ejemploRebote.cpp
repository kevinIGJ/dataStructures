// ejemploRebote.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include "conio.h"
#include <iostream>
using namespace std;
void P7(int a)
{
	printf("%d \t", a);/* (1) */
	if (a>0) //CONDICIÓN DE PARADA, a==0
	{
		a--;
		P7(a); //PASO DE LA RECURSIVIDAD
	}
	printf("%d \t", a);	/* (2) ESTO HAY QUE HACERLO A LA
						VUELTA DE LA RECURSIVIDAD */
}


int main()
{
	int a;
	cout << "Dame un numero para hacer rebote en la recursividad" << endl;
	cin >> a;
	cout << endl;
	P7(a);
	_getch();
    return 0;
}

