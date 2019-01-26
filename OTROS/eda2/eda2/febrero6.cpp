#include <iostream>
using namespace std;

typedef int tArray[10];
 void contarC(int num, int divisor, int cifras_aux,int residuo);
void cifras(int num, int cifras);

int main() {
	int num;
	cin >> num;

	contarC(num, 10, 0, 0);
	//cifras(num, contarC(num,10,0,0));
	system("pause");
	return 0;
}


void cifras(int num, int cifras) {
	tArray array;
	int divisor = 10, cifras_aux = cifras;
	 divisor = pow(divisor, cifras);
	int digito, residuo = 0,i=0;

	while (cifras >= 0) {
		digito = num / divisor;
		residuo = num % divisor;
		num = residuo;
		divisor = divisor / 10;
		cifras--;
		array[i] = digito;
		i++;
	}

	for (int i = cifras_aux; i >= 0; i--) {
		cout << array[i];
	}
	cout << endl;

}

void contarC(int num, int divisor, int cifras_aux, int residuo) {

	int aux = 0;
	if (residuo != num) {
		//	residuo = num % divisor;
			//divisor = divisor * 10;
		contarC(num, divisor * 10, cifras_aux + 1, num%divisor);
		//cifras_aux++;
	}


	cifras(num, cifras_aux);
}