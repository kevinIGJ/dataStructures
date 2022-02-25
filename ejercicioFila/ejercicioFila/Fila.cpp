#include "stdafx.h"
#include "Fila.h"


CFila::~CFila(void){
	while (primero)
		Leer();
}

void CFila::Agregar(int v){
	pnodo nuevo=new CNodo(v);
	if(!primero)
		primero=nuevo;
	if(ultimo)
		ultimo->siguiente=nuevo;
	ultimo=nuevo;
}

int CFila::Leer(){
	if(!primero)
		return 0;
	int aux;
	pnodo aux2;
	aux=primero->valor;
	aux2=primero;
	primero=primero->siguiente;
	delete aux2;
	if(!primero)
		ultimo=NULL;
	return aux;
}