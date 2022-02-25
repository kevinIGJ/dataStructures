// examrap2.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
using namespace std;

class nodo {
   public:
    nodo(int v, nodo *sig = NULL)
    {
       valor = v;
       siguiente = sig;
    }

   private:
    int valor;
    nodo *siguiente;
        
   friend class lista;
};

typedef nodo *pnodo;

class lista {
   public:
    lista() { primero = actual = NULL; }
    ~lista();
    
    void Insertar(int v);
    void Borrar(int v);
	void Borrarrepetido();
	void BorraMenor(int v);
    bool ListaVacia() { return primero == NULL; } 
    void Mostrar();
    void Siguiente();
    void Primero();
    void Ultimo();
	void ImprimeImpare();
    bool Actual() { return actual != NULL; }
    int ValorActual() { return actual->valor; }
    
   private:
    pnodo primero;
    pnodo actual;
};

lista::~lista()
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   actual = NULL;
}

void lista::Insertar(int v)
{
   pnodo anterior;
 
 
   if(ListaVacia() || primero->valor < v) {//inverti el ">", ahora guarda de mayor a menor
                     
      primero = new nodo(v, primero); //
   }
   else {
      
      anterior = primero;
      
      while(anterior->siguiente && anterior->siguiente->valor >= v) //inverti el "<=", ahora guarda de mayor a menor
         anterior = anterior->siguiente;
     
      anterior->siguiente = new nodo(v, anterior->siguiente);
   }
}

void lista::Borrar(int v)
{
   pnodo anterior, nodo;
   
   nodo = primero;
   anterior = NULL;
   while(nodo && nodo->valor > v) {//inverti el "<", ahora guarda de mayor a menor
      anterior = nodo; 
      nodo = nodo->siguiente;
   }
   if(!nodo || nodo->valor != v) return;
   else { 
      if(!anterior) 
         primero = nodo->siguiente;
      else 
         anterior->siguiente = nodo->siguiente;
      delete nodo;
   }   
}

void lista::Mostrar()
{
   nodo *aux;
   
   aux = primero;
   while(aux) {
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
   }
   cout << endl;
}

void lista::Siguiente()
{
   if(actual) actual = actual->siguiente;
}

void lista::Primero()
{
   actual = primero;
}

void lista::Ultimo()
{
   actual = primero;  
   if(!ListaVacia()) 
      while(actual->siguiente) Siguiente();
}

//borra numeros menores
void lista::BorraMenor(int v) { 
	pnodo anterior, nodo;
	anterior = NULL;
	nodo = primero;
	while (nodo && nodo->valor >= v) {
		anterior = nodo;
		nodo = nodo->siguiente;
	}
	if (!nodo)
		return;
	else {
		anterior->siguiente = NULL;
		actual = anterior;
		pnodo aux;
		while (nodo) {
			aux = nodo;
			nodo = nodo->siguiente;
			delete aux;
		}
		
	}
	
}
	
//borra numeros repetidos
void lista::Borrarrepetido() {//Borra numeros repetidos
	Primero();
	pnodo aux;
	while (actual&&actual->siguiente)
	{
		if (actual->valor == actual->siguiente->valor) {
			aux=actual->siguiente;
			actual->siguiente = actual->siguiente->siguiente;
			delete aux;
			if (actual&&actual->siguiente&&actual->valor == actual->siguiente->valor)
				Borrarrepetido();
		}
		Siguiente();
	}
}

//imprime numeros en posicion impar
void lista::ImprimeImpare() {
	nodo *aux;
	int con = 1;
	aux = primero;
	while (aux) {
		if (con % 2 != 0)
			cout << aux->valor<< "-> ";
		aux = aux->siguiente;
		con++;
	}
	cout << endl;
}

int main()
{
   lista Lista;
   
   Lista.Insertar(20);
   Lista.Insertar(20);
   Lista.Insertar(20);
   Lista.Insertar(20);
   Lista.Insertar(10);
   Lista.Insertar(30);
   Lista.Insertar(40);
   Lista.Insertar(40);
   Lista.Insertar(40);
   Lista.Insertar(40);
   Lista.Insertar(30);

   Lista.Mostrar();

   Lista.ImprimeImpare();

   Lista.BorraMenor(30);

   cout << "Lista de elementos:" << endl;
   Lista.Primero();
   while(Lista.Actual()) {
      cout << Lista.ValorActual() << endl;
      Lista.Siguiente();
   }
   Lista.Primero();
   cout << "Primero: " << Lista.ValorActual() << endl;
   
   Lista.Ultimo();
   cout << "Ultimo: " << Lista.ValorActual() << endl;
  
   
   Lista.Mostrar();

   Lista.Borrarrepetido();

   Lista.Mostrar();

   cin.get();
   return 0;
}

