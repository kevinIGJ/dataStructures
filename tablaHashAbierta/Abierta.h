#pragma once
#include "Lista.h"

class CAbierta
{
public:
	CAbierta(int tam);
	~CAbierta();
	void Insertar(int k);
	void Buscar(int p);
	void Mostrar();
private: 
	CLista tabla[100];
	int tamaño;
	int h1(int k);
};



CAbierta::CAbierta(int tam) {
	tamaño = tam;
}


CAbierta::~CAbierta()
{
}

void CAbierta::Insertar(int k) {
	int posicion = h1(k);
	tabla[posicion].Insertar(k);
}

void CAbierta::Buscar(int p) {
	if (tabla[h1(p)].Buscar(p))
		cout << "El valor " << p << " SI se encuentra en la tabla" << endl;
	else
		cout << "El valor " << p << " NO se encuentra en la tabla" << endl;
}

void CAbierta::Mostrar() {
	for (int i = 0; i < tamaño; i++) {
		cout << i << "-   ";
		tabla[i].MostrarTodos();
		cout << endl;
	}
}

int CAbierta::h1(int k) {
	return k % tamaño;
}