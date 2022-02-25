#include "pch.h"
#include "Lista.h"

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
			cout << aux->valor << endl;
			aux = aux->siguiente;
		}
	}
}

void CLista::Eliminar() {

}