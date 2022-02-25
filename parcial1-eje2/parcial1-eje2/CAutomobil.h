#pragma once

#include <conio.h>
#include <iostream>
using namespace std;

class CCAutomobil
{
public:
	CCAutomobil(void);
	CCAutomobil(int x);
	~CCAutomobil(void);
	static int clave;
	float precio;
	int modelo;
	void arrancar();
	void apagar();
};

