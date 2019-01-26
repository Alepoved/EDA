#include <iostream>
using namespace std;

const int MAX_SUPERMERCADOS = 20;
const int MAX_PRODUCTOS = 200;

typedef bool tSupermercado[MAX_SUPERMERCADOS];
typedef bool tProductos[MAX_PRODUCTOS];
typedef int tArray[MAX_SUPERMERCADOS][MAX_PRODUCTOS];
typedef int tComprado[MAX_SUPERMERCADOS];


void compra(int numSuper, int numProd, tSupermercado super, tProductos prod, tArray array, tComprado comprado);
bool lleno(int i, tComprado comprado,int numProd);
void inicializar(tComprado comprado);

int main() {
	int casosPrueba, numSuper, numProd;
	tSupermercado super;
	tProductos prod;
	tArray array;
	tComprado comprado;

	cin >> casosPrueba;
	

	for (int i = 0; i < casosPrueba; i++) {
		cin >> numSuper;
	cin >> numProd;
		for (int j = 0; j < numSuper; j++) {
			for (int k = 0; k < numProd; k++) {
				cin >> array[j][k];
				

			}
			
		}
		inicializar(comprado);
		compra(numSuper, numProd, super, prod, array, comprado);
	}	
	system("pause");
	return 0;
}

void inicializar(tComprado comprado) {
	for (int i = 0; i < MAX_SUPERMERCADOS; i++) {
		
			comprado[i] = false;
		
	}

}

bool lleno(int i,tComprado comprado,int numProd) {

	bool full = false;
	int contador = 0;

	
	if (comprado[i]==3)full = true;

	return full;

}
	

void compra(int numSuper, int numProd, tSupermercado super, tProductos prod, tArray array, tComprado comprado) {
	
	int barato;
	int cuenta = 0,pos=-1;
	bool encontrado = false;
	int k = 0;
	
		for (int j = 0; j < numProd; j++) {
			barato = array[0][k]*10; k++;
			for (int i = 0; i < numSuper; i++) {
			if (array[i][j] < barato && !lleno(i,comprado,numProd)) {
				barato = array[i][j];
				pos = i;
			}

		}
			comprado[pos]++;
			cuenta += barato;
	}



		if (cuenta == 0)cout << "Sin solucion factible" << endl;
	
		cout << cuenta<<endl;



}