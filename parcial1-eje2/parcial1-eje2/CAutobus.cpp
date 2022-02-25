#include "stdafx.h"
#include "CAutobus.h"

int CCAutobus::clave=3846;
CCAutobus::CCAutobus(void)
{
}
CCAutobus::CCAutobus(int x)
{
	cout<<"Autobus creado con sobrecarga "<<x<<" veces"<<endl;
}

CCAutobus::~CCAutobus(void)
{
}
void CCAutobus::arrancar()
{
}
void CCAutobus::apagar()
{
	cout<<"El autobus esta apagado"<<endl;
}