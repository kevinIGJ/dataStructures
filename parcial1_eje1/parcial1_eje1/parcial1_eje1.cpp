// parcial1_eje1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
using namespace std;

void cal(int x){
	if(x>1){
	cal(x-1);
	if(x%2==0||x%3==0)
		cout<<x<<" ";
	}
}
void main(){
	int n;
cout<<"Dame el numero"<<endl;
cin>>n;
cal(n);
_getch();
}
