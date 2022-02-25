#pragma once
#include "Nodo.h"
class CFila
{
public:
	CFila():primero(NULL),ultimo(NULL){};
	~CFila(void);
	void Agregar(int v);
	int Leer();
private:
	pnodo primero, ultimo;
};

