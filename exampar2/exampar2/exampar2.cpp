#include "stdafx.h"
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
        
   friend class pila;
};
 
typedef nodo *pnodo;
 
class pila {
   public:
    pila() : ultimo(NULL) {}
    ~pila();
    
    void Push(int v);
	void Push2(int v,int veces);
    int Pop();
    void Pop2(int v2);//saca valores hasta encontrar el valor o se quede vacia
	void clonar(pila &p);
   private:
    pnodo ultimo;
};
 
pila::~pila()
{
   pnodo aux;
   
   while(ultimo) {
      aux = ultimo;
      ultimo = ultimo->siguiente;
      delete aux;
   }
}

void pila::Push(int v)
{
   pnodo nuevo;
 
   nuevo = new nodo(v, ultimo);
   ultimo = nuevo;
}

int pila::Pop()
{

   pnodo nodo; 
   int v;      
   
   if(!ultimo) return 0; 
   
   nodo = ultimo;
   
   ultimo = nodo->siguiente;
   
   v = nodo->valor; 
   
   delete nodo;
   return v;
}
void pila::Pop2(int v2)
{

   pnodo nodo; 
   int v3;
   while(ultimo && ultimo->valor!=v2){
	   nodo = ultimo;
	   ultimo = nodo->siguiente;
	   v3 = nodo->valor; 
	   delete nodo;
	   cout<<v3<<endl;
   }
}
void pila::clonar(pila &p){
	 
	while (ultimo)
	{
	    pnodo nodo; 
   int v;      
    
   
   nodo = ultimo;
   
   ultimo = nodo->siguiente;
   
   v = nodo->valor; 
  
   p.Push(v);
	}
	
}//clona la pila
void pila::Push2(int v,int veces){
	for(int i=1;i<=veces;i++)
		Push(v);
}//inserta un numero una cantidad de veces

int main()
{
   pila Pila,pila2;

   Pila.Push(20);
   cout << "Push(20)" << endl;

   Pila.Push(10);
   cout << "Push(10)" << endl;
   cout << "Pop() = " << Pila.Pop() << endl;

   Pila.Push(40);
   cout << "Push(40)" << endl;

   Pila.Push(30);
   cout << "Push(30)" << endl;
   cout << "Pop() = " << Pila.Pop() << endl;
   cout << "Pop() = " << Pila.Pop() << endl;

   Pila.Push(90);
   cout << "Push(90)" << endl;
   cout << "Pop() = " << Pila.Pop() << endl;
   cout << "Pop() = " << Pila.Pop() << endl;

   Pila.Push(10);
   Pila.Push(20);
   Pila.Push(30);
   Pila.Push(40);
   Pila.Push(50);
   Pila.Push(60);
   Pila.Push(70);

   

   Pila.clonar(pila2);

   pila2.Pop2(70);
 

   cin.get();
   return 0;
}
