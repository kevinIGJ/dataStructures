#pragma once
class CNodo
{
public:
	CNodo(int v,CNodo *sig=NULL){
	valor=v;
	siguiente=sig;
	}
	
private:
	int valor;
	CNodo *siguiente;
	friend class CFila; 
};

typedef CNodo *pnodo;