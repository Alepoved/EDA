#include <iostream>

using namespace std;

struct nodo {
	int data;
	nodo *sgte;
};
void eliminar(nodo **pcab, nodo *n);
void recorrer(nodo *cab);
void insertarFinal(nodo **cab, int data);


struct nodo *extraer(struct nodo **primero)
{
	struct nodo *r = NULL;

	if (*primero != NULL) {
		r = *primero;
		*primero = (*primero)->sgte;
	}

	return r;
}


void invertir(struct nodo **primero)
{
	struct nodo *aux;
	struct nodo *p;

	aux = NULL;
	while ((p = extraer(primero)) != NULL) {
		p->sgte = aux;
		aux = p;
	}

	*primero = aux;
}

int main() {
	nodo *lista = NULL;
	int op = 0;
	int num;
	char aux;
	bool fin = false;
	do {
		//cin.get(aux);
		cin >> num;

		while (num != 0) {
			//	cin.putback(aux);

			insertarFinal(&lista, num);
			//	cin.get(aux);
			cin >> num;

		}
		invertir(&lista);
		recorrer(lista);
	} while (!fin);
	
	
	
	return 0;
}

void eliminar(nodo **pcab, nodo *n) {
	
		
		if (n != NULL) {
			if (n == *pcab) {
				*pcab = (*pcab)->sgte;
			}
			else {
				nodo *p = *pcab;
				while (p->sgte != NULL && p->sgte != n) {
					p = p->sgte;
				}
				p->sgte = n->sgte;
			}
			delete n;
			
		}
		
}


void recorrer(nodo *cab) {

		 
		nodo *p = cab;
		do {
			
			cout << p->data <<" ";
			p = p->sgte;
		} while (p != NULL);
		cout << endl;
	
}



void insertarFinal(nodo **pcab, int data) {

	
	nodo *nuevo = new nodo;
	nuevo->data = data;
	nuevo->sgte = NULL;

	if (*pcab == NULL) {

		*pcab = nuevo;

	}

	else {

		nodo *p = *pcab;
		while (p->sgte != NULL) {
			p = p->sgte;
		}
		p->sgte = nuevo;

	}

}


