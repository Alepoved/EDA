#include <iostream>
#include <string>
#include <cstdlib>
#include "Queue.h"
#include "Stack.h"

using namespace std;





int main() {
	Queue <int> cola;
	Queue <int> cola2;
	Stack <int> pila;
	int num, cont = 1;

	cin >> num;

	while (num != 0) {

		for (int i = 1; i <= num; i++) {
			cola.push_back(i);
		}

		while (cola.size() > cont) {
			cola.pop_front();

			for (int j = 0; j < num / 2; j++) {
				if (cont % 2 != 0) {

					//cout << cola.front();
					cola2.push_back(cola.front());

					//cout << cola2.front();
					for (int i = 0; i <= cont &&cola.size() > 0; i++) {


						cola.pop_front();
					}
				}
			
				else {
					/*for (int q = 0; q < cola.size(); q++) {
						cola.push_back(cola.front());
						cola.pop_front();
					}*/
					//-cout << cola.front();
				//	cola2.push_back(cola.front());

					//*cola.pop_front();
					for (int i = 0; i < cont && cola.size()>0; i++) {
					//	cout<<cola.front();
						cola2.push_back(cola.front());
						cola.pop_front();
					}
				if(cola.size()>0)cola.pop_front();
				}


			}
			cont++;
			
			int tam = cola2.size();
			for (int k = 0; k < tam; k++) {
				//*cout << cola2.front();
				cola.push_back(cola2.front());
				cola2.pop_front();

			}
			
			num = num / 2;
		}
		//cola.pop_front();

			//cola.pop_front();

		while (cola.size() != 0) {
			cout << cola.front()<<" ";
			cola.pop_front();
		}




		cont = 1;
		cin >> num;
	}



	system("pause");
	return 0;
}