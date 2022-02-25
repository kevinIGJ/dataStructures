#pragma once
#include "Nodo.h"
class CP
{
public:
	CP():ultimo(NULL){};
	void Push(int x);
	int Pop();
	~CP(void);
private:
	pnodo ultimo;
};

