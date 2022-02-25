#pragma once
class CNodo
{
public:
	CNodo(int v, CNodo *sig = nullptr) {
	valor=v;
	siguiente=sig;
	}
	
private:
	int valor;
	CNodo *siguiente;
	friend class CLista; 
};

typedef CNodo *pnodo;