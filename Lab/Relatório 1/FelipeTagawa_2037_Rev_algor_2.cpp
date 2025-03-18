#include <iostream>
#include <locale>
using namespace std;

int main(){
	setlocale(LC_ALL, "ptb"); // Acentos e Ç.
	
	int valor; // Valor a ser lido para fazer as divisões.
	
	cin >> valor; // Lendo o valor.

	for(int i = valor - 1; i > 0; i--){
		// Exibe o resto da divisão de todos valores menores que o valor inserido até 1.
		cout << "Resto da divisão de " << valor << " por " << i << ": " << valor % i << endl;
	}
	
	return 0;
}