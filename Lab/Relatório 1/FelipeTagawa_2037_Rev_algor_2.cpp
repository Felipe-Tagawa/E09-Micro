#include <iostream>
#include <locale>
using namespace std;

int main(){
	setlocale(LC_ALL, "ptb"); // Acentos e �.
	
	int valor; // Valor a ser lido para fazer as divis�es.
	
	cin >> valor; // Lendo o valor.

	for(int i = valor - 1; i > 0; i--){
		// Exibe o resto da divis�o de todos valores menores que o valor inserido at� 1.
		cout << "Resto da divis�o de " << valor << " por " << i << ": " << valor % i << endl;
	}
	
	return 0;
}