#include <iostream>
#include <locale> // Biblioteca para suportar acentos
using namespace std;

// Fun��o para contar n�meros positivos, negativos, pares e �mpares em um vetor
void conta(int n, int vetor[]){
	int pos = 0, neg = 0, par = 0, impar = 0;
	
	// Percorre o vetor e faz a contagem das identidades.
	for(int i = 0; i < n; i++){
		if(vetor[i] >= 0) pos++; // Conta n�meros positivos
		if(vetor[i] < 0) neg++; // Conta n�meros negativos
		if(vetor[i] % 2 == 0) par++; // Conta n�meros pares
		if(vetor[i] % 2 != 0) impar++; // Conta n�meros �mpares
	}

	// Exibe os resultados
	cout << "Quantidade de n�meros pares: " << par << endl;
	cout << "Quantidade de n�meros �mpares: " << impar << endl;
	cout << "Quantidade de n�meros positivos: " << pos << endl;
	cout << "Quantidade de n�meros negativos: " << neg  << endl;
}

int main(){
	setlocale(LC_ALL, "ptb"); // Acentos e �.
	
	int n; // Quantidade de testes a serem feitos (conjuntos de 5 n�meros)
	cin >> n; // Lendo a quantidade de testes.
	
	int vetor[5]; // Vetor fixo de 5 posi��es.
	
	for(int i = 0; i < n; i++){
		// Lendo os 5 n�meros e armazenando no vetor.
		for(int j = 0; j < 5; j++){
			cin >> vetor[j];
		}
		conta(5, vetor);
	}
	
	return 0;
}
