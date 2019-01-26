#include <iostream>
using namespace std;


int cifras(int num) {
	if (num < 10)  //caso base
		return 1;
	else
		return 1 + cifras(num / 10);

}



bool polidivisible(long int num, bool r, int numCifras) {

	if (numCifras > 1){


	if (num%numCifras != 0)r = false;
	else {
		
		r = polidivisible(num /= 10, r, numCifras - 1);
	}
}
	return r;

}


bool resuelve() {
	
	long int num;
	cin >> num;
	int numCifras = cifras(num);
	if (polidivisible(num,true,numCifras))cout << "POLIDIVISIBLE";
	else cout << "NO POLIDIVISIBLE";
	cout << endl;

	return true;
}

int main() {


	while (resuelve());

	system("pause");
	return 0;
}