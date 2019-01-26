#include <iostream>
using namespace std;


typedef int solucion[2][2];



bool ordenarAux(int limite, solucion solucion,int x,int y);
void ordenar(int limite, solucion solucion);
bool esFactible(solucion solucion, int x, int y, int i,int limite);
int sumaF(solucion solucion, int x);
int sumaC(solucion solucion, int y);
int nuevaX(int x, int y);
int nuevaY(int x, int y,int newX);

int main() {


	solucion solucion;
	int limite;

	cin >> limite;

	ordenar(limite,solucion);



	system("pause");

	return 0;
}

void ordenar(int limite, solucion solucion) {
	
	bool ok = ordenarAux(limite, solucion, 0, 0);

	
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << solucion[i][j] << " ";
			}
			cout << endl;
		}
	

}

bool ordenarAux( int limite, solucion solucion,int x,int y) {
	bool exito = false;
	
	for (int i = 1; i < limite && !exito; i++) {
		if (esFactible(solucion, x, y, i,limite)) {
			solucion[x][y] = i;
			if (x == 2 && y == 2)exito = true;
			else {
				int newX = nuevaX(x, y);
				int newY = nuevaY(x, y,newX);
					
				
					
			
				exito = ordenarAux(limite, solucion, newX, newY);
			}
			if (!exito)solucion[x][y] = 0;

		}
	}

	return exito;
}

int nuevaX(int x, int y) {
	if (y == 2)x++;
	else {
		x = y + 1;
	}

	return x;
	
}
int nuevaY(int x, int y,int newX) {
	if (newX != x) {
		if (x == 2)y++;
		else {
			y = x + 1;
		}
	}
	else
		y++;
	
	return y;
}

bool esFactible(solucion solucion, int x, int y, int i,int limite) {
	bool exito = false;

	for (int i = 0; i <= y - 1 && !exito; i++) {
		if (solucion[x][i] == i)exito = false;
	}

	for (int i = 0; i <= y - 1 && !exito; i++) {
			if (solucion[i][x] == i)exito = false;
		}
	

	int sumaF2 = sumaF(solucion, x)+i;
	
	int sumaC2 = sumaC(solucion, y) + i;

	exito = ((sumaF2 < limite && y < 2) || (sumaF2 == limite && y == 2));

	if (exito) {
		exito = ((sumaC2 < limite && x < 2) || (sumaC2 == limite && x == 2));

	}

	return exito;

}

int sumaF(solucion solucion, int x) {
	int suma = 0;
	for (int i = 0; i < x; i++) {
		suma += solucion[x][i];
	}

	return suma;
}

int sumaC(solucion solucion, int y) {
	int suma = 0;
	for (int i = 0; i < y; i++) {
		suma += solucion[i][y];
	}

	return suma;
}

