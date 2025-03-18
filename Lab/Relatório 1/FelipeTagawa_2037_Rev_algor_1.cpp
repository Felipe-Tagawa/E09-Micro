#include <iomanip>
#include <iostream>
#include <locale>
using namespace std;

int main(){
	setlocale(LC_ALL, "ptb"); // Acentos e �.
	int quant; // Quantidade de frutas compradas.
	float preco; // Valor flutuante relativo ao pre�o final.
	
	cin >> quant; // Lendo a quantidade de itens.
	
	// Condi��o para uma quantidade menor do que 12 frutas.
	if(quant < 12){
		preco = quant * 0.8;
		cout << "Pre�o da unidade = R$0.80" << endl;
	}
	else{ // Restante
		preco = quant * 0.65;
 		cout << "Pre�o da unidade = R$0.65" << endl;
	}
	
	cout << fixed << setprecision(2); // Arredondamento.
	// Mostrando o pre�o total da compra.
	cout << "Pre�o total = " << preco << endl;
	
	
	return 0;
	
}