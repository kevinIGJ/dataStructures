#include "stdafx.h"
#include "P.h"




CP::~CP(void){
	pnodo aux;
	while(ultimo){
		aux=ultimo;
		ultimo=ultimo->siguiente;
		delete aux;
	}
}

void CP::Push(int x){
	pnodo nuevo=new CNodo(x,ultimo);
	ultimo=nuevo;
}
int CP::Pop(){
	int v;
	pnodo nodo;
	if(!ultimo)
		return 0;
	nodo=ultimo;
	ultimo=nodo->siguiente;
	v=nodo->valor;
	delete nodo;
	return v;
}