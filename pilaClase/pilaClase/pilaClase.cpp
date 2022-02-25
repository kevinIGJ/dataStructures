// pilaClase.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "P.h"
#include <conio.h>
#include <iostream>
using namespace std;
#define elementos 10
void main(){

	CP mipila;
for (int i = 1; i < elementos+1; i++)
	mipila.Push(i);
	for (int i = 1; i < elementos+1; i++)
		cout<<mipila.Pop()<<endl;
	_getch();
}

