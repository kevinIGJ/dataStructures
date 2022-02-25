#pragma once
class CNodo
{
public:
	CNodo(int v,CNodo *sig=NULL){
	valor=v;
	siguiente=sig;
	}
	~CNodo(void);
private:
	int valor;
	CNodo *siguiente;
	friend class CP; 
};

typedef CNodo *pnodo;