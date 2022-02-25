//#include "pch.h"
#include <iostream>
using namespace std;

class ArbolABB {
private:
	//// 
	class Nodo {
	public:
		// 
		Nodo(const int dat, Nodo *izq = NULL, Nodo *der = NULL) :
			dato(dat), izquierdo(izq), derecho(der) {}
		// 
		int dato;
		Nodo *izquierdo;
		Nodo *derecho;
	};

	// 
	Nodo *raiz;
	Nodo *actual;
	int contador;
	int altura;

public:
	// 
	ArbolABB() : raiz(NULL), actual(NULL) {}
	~ArbolABB() { Podar(raiz); }
	// 
	void Insertar(const int dat);
	// 
	void Borrar(const int dat);
	// 
	bool Buscar(const int dat);
	// 
	bool Vacio(Nodo *r) { return r == NULL; }
	// 
	bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
	// 
	const int NumeroNodos();
	const int AlturaArbol();
	// 
	int Altura(const int dat);
	// 
	int &ValorActual() { return actual->dato; }
	// 
	void Raiz() { actual = raiz; }
	// 
	void InOrden(void(*func)(int&), Nodo *nodo = NULL, bool r = true);
	void PreOrden(void(*func)(int&), Nodo *nodo = NULL, bool r = true);
	void PostOrden(void(*func)(int&), Nodo *nodo = NULL, bool r = true);
private:
	// 
	void Podar(Nodo* &);
	void auxContador(Nodo*);
	void auxAltura(Nodo*, int);
};

// 
void ArbolABB::Podar(Nodo* &nodo)
{
	// 
	if (nodo) {
		Podar(nodo->izquierdo); // 
		Podar(nodo->derecho);   // 
		delete nodo;            // 
		nodo = NULL;
	}
}

// 
void ArbolABB::Insertar(const int dat)
{
	Nodo *padre = NULL;

	actual = raiz;
	// 
	while (!Vacio(actual) && dat != actual->dato) {
		padre = actual;
		if (dat > actual->dato) actual = actual->derecho;
		else if (dat < actual->dato) actual = actual->izquierdo;
	}

	// 
	if (!Vacio(actual)) return;
	// 
	if (Vacio(padre)) raiz = new Nodo(dat);
	// 
	else if (dat < padre->dato) padre->izquierdo = new Nodo(dat);
	// 
	else if (dat > padre->dato) padre->derecho = new Nodo(dat);
}

// 
void ArbolABB::Borrar(const int dat)
{
	Nodo *padre = NULL;
	Nodo *nodo;
	int aux;

	actual = raiz;
	// 
	while (!Vacio(actual)) {
		if (dat == actual->dato) { // 
			if (EsHoja(actual)) { // 
				if (padre) // 
				   // 
					if (padre->derecho == actual) padre->derecho = NULL;
					else if (padre->izquierdo == actual) padre->izquierdo = NULL;
				delete actual; // 
				actual = NULL;
				return;
			}
			else { // 
			   // 
				padre = actual;
				// 
				if (actual->derecho) {
					nodo = actual->derecho;
					while (nodo->izquierdo) {
						padre = nodo;
						nodo = nodo->izquierdo;
					}
				}
				// 
				else {
					nodo = actual->izquierdo;
					while (nodo->derecho) {
						padre = nodo;
						nodo = nodo->derecho;
					}
				}
				// 
				// 
				aux = actual->dato;
				actual->dato = nodo->dato;
				nodo->dato = aux;
				actual = nodo;
			}
		}
		else { // 
			padre = actual;
			if (dat > actual->dato) actual = actual->derecho;
			else if (dat < actual->dato) actual = actual->izquierdo;
		}
	}
}

// Recorrido de árbol en inorden
// void (*func)(int&)
void ArbolABB::InOrden(void(*func)(int&), Nodo *nodo, bool r)
{
	if (r) nodo = raiz;
	if (nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
	func(nodo->dato);
	if (nodo->derecho) InOrden(func, nodo->derecho, false);
}

// 
// void (*func)(int&)
void ArbolABB::PreOrden(void(*func)(int&), Nodo *nodo, bool r)
{
	if (r) nodo = raiz;
	func(nodo->dato);
	if (nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
	if (nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// 
// void (*func)(int&)
void ArbolABB::PostOrden(void(*func)(int&), Nodo *nodo, bool r)
{
	if (r) nodo = raiz;
	if (nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
	if (nodo->derecho) PostOrden(func, nodo->derecho, false);
	func(nodo->dato);
}

// 
bool ArbolABB::Buscar(const int dat)
{
	actual = raiz;

	// 
	while (!Vacio(actual)) {
		if (dat == actual->dato) return true; // 
		else if (dat > actual->dato) actual = actual->derecho; // 
		else if (dat < actual->dato) actual = actual->izquierdo;
	}
	return false; // 
}

// 
int ArbolABB::Altura(const int dat)
{
	int altura = 0;
	actual = raiz;

	// 
	while (!Vacio(actual)) {
		if (dat == actual->dato) return altura; // 
		else {
			altura++; // 
			if (dat > actual->dato) actual = actual->derecho;
			else if (dat < actual->dato) actual = actual->izquierdo;
		}
	}
	return -1; // 
}

// 
const int ArbolABB::NumeroNodos()
{
	contador = 0;

	auxContador(raiz); // 
	return contador;
}

// 
void ArbolABB::auxContador(Nodo *nodo)
{
	contador++;  // 
	// 
	if (nodo->izquierdo) auxContador(nodo->izquierdo);
	if (nodo->derecho)   auxContador(nodo->derecho);
}

// 
const int ArbolABB::AlturaArbol()
{
	altura = 0;

	auxAltura(raiz, 0); // 
	return altura;
}

// 
void ArbolABB::auxAltura(Nodo *nodo, int a)
{
	// 
	if (nodo->izquierdo) auxAltura(nodo->izquierdo, a + 1);
	if (nodo->derecho)   auxAltura(nodo->derecho, a + 1);
	// 
	if (EsHoja(nodo) && a > altura) altura = a;
}

// 
void Mostrar(int &d)
{
	cout << d << ",";
}

int main()
{
	// 
	ArbolABB ArbolInt;

	// 
	ArbolInt.Insertar(10);
	ArbolInt.Insertar(5);
	ArbolInt.Insertar(12);
	ArbolInt.Insertar(4);
	ArbolInt.Insertar(7);
	ArbolInt.Insertar(3);
	ArbolInt.Insertar(6);
	ArbolInt.Insertar(9);
	ArbolInt.Insertar(8);
	ArbolInt.Insertar(11);
	ArbolInt.Insertar(14);
	ArbolInt.Insertar(13);
	ArbolInt.Insertar(2);
	ArbolInt.Insertar(1);
	ArbolInt.Insertar(15);
	ArbolInt.Insertar(10);
	ArbolInt.Insertar(17);
	ArbolInt.Insertar(18);
	ArbolInt.Insertar(16);

	cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

	// 
	cout << "InOrden: ";
	ArbolInt.InOrden(Mostrar);
	cout << endl;
	cout << "PreOrden: ";
	ArbolInt.PreOrden(Mostrar);
	cout << endl;
	cout << "PostOrden: ";
	ArbolInt.PostOrden(Mostrar);
	cout << endl;

	// 
	cout << "N nodos: " << ArbolInt.NumeroNodos() << endl;
	ArbolInt.Borrar(5);
	cout << "Borrar   5: ";
	ArbolInt.InOrden(Mostrar);
	cout << endl;
	ArbolInt.Borrar(8);
	cout << "Borrar   8: ";
	ArbolInt.InOrden(Mostrar);
	cout << endl;
	ArbolInt.Borrar(15);
	cout << "Borrar  15: ";
	ArbolInt.InOrden(Mostrar);
	cout << endl;
	ArbolInt.Borrar(245);
	cout << "Borrar 245: ";
	ArbolInt.InOrden(Mostrar);
	cout << endl;
	ArbolInt.Borrar(4);
	cout << "Borrar   4: ";
	ArbolInt.InOrden(Mostrar);
	ArbolInt.Borrar(17);
	cout << endl;
	cout << "Borrar  17: ";
	ArbolInt.InOrden(Mostrar);
	cout << endl;

	// 
	cout << "N nodos: " << ArbolInt.NumeroNodos() << endl;
	cout << "Altura de 1 " << ArbolInt.Altura(1) << endl;
	cout << "Altura de 10 " << ArbolInt.Altura(10) << endl;
	cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

	cin.get();
	return 0;
}
