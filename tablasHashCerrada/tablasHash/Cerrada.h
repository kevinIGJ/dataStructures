#pragma once
#include <iostream>
using namespace std;

class CCerrada {
public:
	CCerrada(int tam);
	~CCerrada();
	void Insertar(int k);
	int Buscar(int p);
	void Mostrar();
	int Primo();

private:
	int tabla[100]={NULL};  //tabla hash desde 
	int tamaño;
	int h1(int k);
	int h2(int k);
};

CCerrada::CCerrada(int tam) {
	tamaño = tam;
}

CCerrada::~CCerrada() {

}

void CCerrada::Insertar(int k) {
	bool guardado = false;
	int i = 0;
	while (!guardado) {
		int posicion = (h1(k) + (i*h2(k))) % tamaño;
		if (!tabla[posicion]) {
			tabla[posicion] = k;
			guardado = true;
		}
		else
			i++;
	}
}

int CCerrada::Buscar(int p)
{
	if (p >= tamaño || p<0) {
		cout << "La posicion esta fuera de rango" << endl;
		return 0;
	}
	else {
		return tabla[p];
	}

}

void CCerrada::Mostrar() {
	for (int i = 0; i < tamaño; i++) {
		cout << i<<"-  "<<tabla[i]<<endl;
	}
}

int CCerrada::Primo() {
	for (int numeroCercano = tamaño - 1; numeroCercano > 1; numeroCercano--) {
		bool divisible = NULL;
		for (int i = numeroCercano - 1; i > 1; i--) {
			if (numeroCercano % i == 0)
				divisible = true;
		}
		if (!divisible) {
			return numeroCercano;
		}
	}
}

 int CCerrada::h1(int k) {
	 return k % tamaño;
}

 int CCerrada::h2(int k) {
	 return 1 + (k % Primo());
}
