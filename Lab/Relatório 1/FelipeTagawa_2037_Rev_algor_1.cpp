#include <iomanip>
#include <iostream>
#include <locale>
using namespace std;

int main(){
	setlocale(LC_ALL, "ptb"); // Acentos e Ç.
	int quant; // Quantidade de frutas compradas.
	float preco; // Valor flutuante relativo ao preço final.
	
	cin >> quant; // Lendo a quantidade de itens.
	
	// Condição para uma quantidade menor do que 12 frutas.
	if(quant < 12){
		preco = quant * 0.8;
		cout << "Preço da unidade = R$0.80" << endl;
	}
	else{ // Restante
		preco = quant * 0.65;
 		cout << "Preço da unidade = R$0.65" << endl;
	}
	
	cout << fixed << setprecision(2); // Arredondamento.
	// Mostrando o preço total da compra.
	cout << "Preço total = " << preco << endl;
	
	
	return 0;
	
}