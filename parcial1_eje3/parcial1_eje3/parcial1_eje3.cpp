// parcial1_eje3.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
using namespace std;


void main(){
		int arr[4][2]={{9,8},{7,6},{5,4},{3,2}}; 

	printf("\n\nARREGLO"); 

	for (int a=0;a<4;a++) 

	{ 

		 printf("\n"); 

		 for (int b=0;b<2;b++) 

			  printf("%d ", arr[a][b]); 

	}
	printf("\n\nARREGLO CON APUNTADOR"); 
	int *ptr=&arr[0][0];
	for (int a=0;a<4;a++) 

	{ 

		 printf("\n"); 

		 for (int b=0;b<2;b++) 

			  printf("%d ", *(ptr+(a*2)+b)); 

	}


	_getch();
}
