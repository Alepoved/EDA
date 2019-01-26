#include <iostream>
using namespace std;

struct nodo {
	int nro;
	struct nodo *sgte;
	int tam=0;
};

typedef nodo *ptrPila;   // creando nodo tipo puntero( tipo de dato )

						
void push(ptrPila &p, int valor)
{
	ptrPila aux;
	aux = new(struct nodo);  // apuntamos al nuevo nodo creado
	aux->nro = valor;

	aux->sgte = p;
	p = aux;
	p->tam++;
}


int pop(ptrPila &p)
{
	int num;
	ptrPila aux;

	aux = p;
	num = aux->nro;   // asignamos el primer vamor de la pila

	p = aux->sgte;
	delete(aux);

	return num;
}





void destruir_pila(ptrPila &p)
{
	ptrPila aux;

	while (p != NULL)
	{
		aux = p;
		p = aux->sgte;
		delete(aux);
	}
}


int sumar_dig(int n, int resultado, int &i,ptrPila &p)
{

	if (n == 0)      //caso base
		return resultado;
	else {
		int dig = n % 10;
		//cout << dig << endl;
		push(p, dig);
		resultado += dig;
		i = i + 1;
		return sumar_dig(n / 10, resultado, i,p);

	}


}


int main()
{
	ptrPila p = NULL;  // creando pila
	int dato;
	int op;
	int i = 0;
	int x; // numero que devuelve la funcon pop


	cin >> dato;
	
	while (dato != -1) {
		
		op=sumar_dig(dato, 0, i, p);
		
		for (int j = 0; j < i; j++) {
			x = pop(p);
			cout << x;
			if(j<i-1)cout<< " + ";
		}

		cout << " = " << op << endl;

		destruir_pila(p);
		i = 0;
		cin >> dato;
	}

	

	
	system("pause");
	return 0;
}