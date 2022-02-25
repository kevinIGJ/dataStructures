#include "stdafx.h"
#include "CAutomobil.h"


int CCAutomobil::clave=13445433;

CCAutomobil::CCAutomobil(void)
{
}
CCAutomobil::CCAutomobil(int x)
{
	cout<<"creado con sobrecarga "<<x<<" veces"<<endl;
}

CCAutomobil::~CCAutomobil(void)
{
}


void CCAutomobil::arrancar()
{
	cout<<"El auto esta encendido"<<endl;
}
void CCAutomobil::apagar()
{
	cout<<"El auto esta apagado"<<endl;
}