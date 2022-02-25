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
	bool Buscar(int v);

private:
	pnodo primero, actual;
};


CLista::~CLista()
{
}



void CLista::Insertar(int v) {
	pnodo anterior;
	if (ListaVacia() || v <= primero->valor)
		primero = new CNodo(v, primero);
	else {
		anterior = primero;
		while (anterior->siguiente && anterior->siguiente->valor <= v)
			anterior = anterior->siguiente;
		anterior->siguiente = new CNodo(v, anterior->siguiente);
	}
}
void CLista::Primero() {
	actual = primero;
}

void CLista::Siguiente() {
	if (actual)
		actual = actual->siguiente;
}

bool CLista::Buscar(int v) {
	Primero();
	bool encontrado= false;
	while (actual) {
		if (actual->valor == v) {
			encontrado = true;
		}
		Siguiente();
	}
	return encontrado;
}

void CLista::Ultimo() {
	actual = primero;
	if (!ListaVacia())
		while (actual->siguiente)
			Siguiente();
}

void CLista::MostrarTodos() {
	pnodo aux;
	if (!primero)
		cout << "No hay nada en la lista" << endl;
	else {
		aux = primero;
		while (aux) {
			cout <<"   "<<aux->valor;
			aux = aux->siguiente;
		}
	}
}

void CLista::Eliminar() {

}