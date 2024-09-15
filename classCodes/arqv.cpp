#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

#define tamanho 10; // constante
const int x = 200; // constante

void func(void){
    cout << "Usando a função!!" << endl;
}
// inicio
int main(){
    int inteiro; // 32 bits
    char caracter[10]; // 8 bits
    float flutuante = 2.74372; // 32 bits
    bool booleano; // 8 bits (true or false)
    double real; // 64 bits
    string str(10, '\0');

    cout  << "Digite um número: ";

    cin >> inteiro;

    int resultado = inteiro + inteiro/2;

    if (resultado > 10 || inteiro == 2){
        cout << "Novo número: " << resultado << endl;
    } else{
        cout << "Número original: " << inteiro << endl;
    }

    cout << "Número original: " << flutuante << endl;
    cout << fixed << setprecision(3);
    cout << "Número com 3 casas decimais: " << flutuante << endl;
    printf("Número com 2 casa decimais %.2f\n", flutuante);


    cout << "Digite a string: " << endl;
    cin >> caracter;

    char troca[10];

    for(int i = 0, j = 9; i < 10; i++, j--){
        troca[i] = caracter[j];
        cout << troca[i];
    }

    cout << endl;

    func();

    return 0;
}
