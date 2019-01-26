#include <iostream>
#include <sstream>
#include "Exceptions.h"
#include "Lista.h"
using namespace std;


void resolver(List <int> a, List <int> b){
	int i = 0, j = 0, t = 0;
	int elemA, elemB;
	int numA = 0, numB = 0;
	List <int> c;

	List <int>:: Iterator itA = a.begin();
	List <int>:: Iterator itB = b.begin();
	List <int>:: Iterator itC = c.begin();

	int maxA = a.size() -1;
	int maxB = b.size()-1;
	
	bool list1 = a.empty();
	bool list2 = b.empty();

	if (list1 == false && list2 == false){ //miramos que ninguna este vacia
		
		while ((numA <= maxA) && (numB <= maxB)){

			elemA = itA.elem();
			elemB = itB.elem();

			if (elemA < elemB){ //A menor que B
				c.push_back(elemA);
				itA.next();
				numA++;
			}
			else{
				if (elemA > elemB){ //B menor que A
					c.push_back(elemB);
					itB.next();
					numB++;
				}
				else{ //Iguales a y b
					c.push_back(elemA);
					itA.next();
					itB.next();
					numA++; 
					numB++;
				}
			}
			//numA++; numB++;
		}


		if (numA >= maxA){ // a ya esta vacio

			while (numB < maxB){
				c.push_back(elemB);
				itB.next();
				elemB = itB.elem();
				numB++;
			}

		} // b ya esta vacio
		else{
			while (numA <= maxA){
				c.push_back(elemA);
				itA.next();
				elemA = itA.elem();
				numA++;
			}
		}

	}
	else{//alguna lista esta vacia

		if (a.empty()){ // b vacia
			while (numB < maxB){
				elemB = itB.elem();
				c.push_back(elemB);
				itB.next();
				numB++;
			}
		}
		else{ // a vacia
			while (numA < maxA){
				elemA = itA.elem();
				c.push_back(elemA);
				itA.next();
				numA++;
			}
		}

	}

	
	//MOSTRAR

	/*
	while (i < (a.size() -1)){
		cout << a.at(i) <<" ";
		i++;
	}

	cout << endl;

	while (j < (b.size()-1)){
		cout << b.at(j) << " ";
		j++;
	}

	cout << endl;
	*/

	while (t < c.size()){
		cout << c.at(t) << " ";
		t++;
	}

	cout << endl;
}

int main(){
	List <int> a;
	List <int> b;
	int num;
	string linea1, linea2;

	int numCasos;
	cin >> numCasos;
	
	getline(cin, linea1);//PONGO UNO DE MAS PORQUE SE LO SALTA SOLO XD

	for (int i = 0; i < numCasos; i++){

		char aux;
		a.~List();
		b.~List();

		a.begin();//Los colocamos al principio
		b.begin();

		
		//getline(cin, linea1);
		//getline(cin, linea2);

		/*stringstream a1 = stringstream(linea1);
		stringstream b2 = stringstream(linea2);

		while (a1){
			a1 >> num;
			a.push_back(num);
		}

		num = NULL;

		while (b2){
			b2 >> num;
			b.push_back(num);
		}*/
		cin.get(aux);


		while (aux != '\n') {
			cin.putback(aux);
			cin >> num;
			a.push_back(num);
			cin.get(aux);

		}
		num = NULL;
		cin.get(aux);
		if (aux == '\n')b.~List();
		else {
			while (aux != '\n') {
				cin.putback(aux);
				cin >> num;
				b.push_back(num);
				cin.get(aux);

			}
		}

	//	if (linea2 == "") b.~List();
		resolver(a, b);
	}

	system("pause");
	return 0;
}