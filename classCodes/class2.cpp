#include <iostream>
#include <string>

// using namespace std;

int soma(int a, int b){
    return a+b;
}

// w é o parametro default caso ele não seja chamado no código
int fatorial(int x, int w = -1){
    int v;
    for (v=1; x>1; --x){
        std::cout << x << std::endl;
        v*= x;    
    }
    std::cout << w << std::endl;
    return v;
}

#define TAM 20
// definição de uma estrutura
struct endereco{
    char rua[TAM];
    int numero;
};

struct pessoa{
    char nome[TAM];
    int idade;
    struct endereco moradia;
};

struct endereco obtem_endereco(){
    endereco end;
    std::cout << "Digite o nome da rua: " << std::endl;
    std::cin.getline(end.rua, TAM);
    std::cout << "Digite o número da casa: " << std::endl;
    std::cin >> end.numero;

    return end;
};

int main(){

    /*
    int x = 5, y;
    
    y = fatorial(x);

    std::cout << "Resultado do fatorial: " << y << std::endl;
    std::cout << "Número original: " << x << std::endl;
    
    std::cout << std::endl;
    */

    /*
    endereco residencia;
    residencia = obtem_endereco();
    std::cout << "Meu endereço é: " << residencia.rua << ", " << residencia.numero << std::endl;

    std::cout << std::endl;
    */

    /*
    struct pessoa estudante;
    estudante.moradia = obtem_endereco();
    std::cout << "Meu endereço é: " << estudante.moradia.rua << ", " << estudante.moradia.numero << std::endl;
    std::cout << std::endl;
    */

    /*
    int a = 8, b = 3;
    int& c = a; // referencia
    int *ptr; // ponteiro que aponta para um tpo inteiro;

    // ponteiro guarda endereco
    // referencia guarda o conteúdo

    ptr = &b;
    std::cout << "O valor do meu ponteiro " << ptr << std::endl;
    std::cout << "O conteúdo do endereco contido em ptr é " << *ptr << std::endl;
    std::cout << "O valor da referencia é " << c << std::endl;
    */

    /*
    // new para criar vetor dinamico
    // delete para deletar o vetor dinamico
    int *i= new int[10];
    i[0] = 4;
    std::cout << i[0] << std::endl;
    */

    return 0;
}
