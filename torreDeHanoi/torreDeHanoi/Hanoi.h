#pragma once
#include "conio.h"
#include <iostream>
using namespace std;
class Hanoi
{
public:
	Hanoi();
	~Hanoi();
	void mover(int disco, int a, int b, int c);
	int contar = 0;
};

