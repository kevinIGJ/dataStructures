#pragma once
#include "Nodo.h"
#include <iostream>
#include <conio.h>
using namespace std;
class CLista
{
public:
	CLista() { primero = actual = nullptr; }
	~CLista();
	void Insertar(int v);
	void Eliminar();
	void MostrarTodos();
	bool ListaVacia() {
		return primero == nullptr;
	}
	bool ExisteActual() {
		return actual != nullptr;
	}
	void Primero();
	void Ultimo();
	void Siguiente();
	int ValorActual() { return actual->valor; }

private:
	pnodo primero, actual;
};

