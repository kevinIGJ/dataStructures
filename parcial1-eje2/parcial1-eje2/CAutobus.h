#pragma once

#include <conio.h>
#include <iostream>
using namespace std;

class CCAutobus
{
public:
	static int clave;
	float precio;
	int modelo;
	CCAutobus(void);
	CCAutobus(int x);
	~CCAutobus(void);
	void arrancar();
	void apagar();
};

