// practicaApuntador.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include "conio.h"
int main()
{
	int *i;
	int a;
	i = &a;
	printf("Dame tu edad ");
	scanf_s("%d", i);
	printf("%d", *i);
	_getch();
    return 0;
}

