#include <iostream>
#include <locale> // Biblioteca para suportar acentos
using namespace std;

// Função para contar números positivos, negativos, pares e ímpares em um vetor
void conta(int n, int vetor[]){
	int pos = 0, neg = 0, par = 0, impar = 0;
	
	// Percorre o vetor e faz a contagem das identidades.
	for(int i = 0; i < n; i++){
		if(vetor[i] >= 0) pos++; // Conta números positivos
		if(vetor[i] < 0) neg++; // Conta números negativos
		if(vetor[i] % 2 == 0) par++; // Conta números pares
		if(vetor[i] % 2 != 0) impar++; // Conta números ímpares
	}

	// Exibe os resultados
	cout << "Quantidade de números pares: " << par << endl;
	cout << "Quantidade de números ímpares: " << impar << endl;
	cout << "Quantidade de números positivos: " << pos << endl;
	cout << "Quantidade de números negativos: " << neg  << endl;
}

int main(){
	setlocale(LC_ALL, "ptb"); // Acentos e Ç.
	
	int n; // Quantidade de testes a serem feitos (conjuntos de 5 números)
	cin >> n; // Lendo a quantidade de testes.
	
	int vetor[5]; // Vetor fixo de 5 posições.
	
	for(int i = 0; i < n; i++){
		// Lendo os 5 números e armazenando no vetor.
		for(int j = 0; j < 5; j++){
			cin >> vetor[j];
		}
		conta(5, vetor);
	}
	
	return 0;
}
