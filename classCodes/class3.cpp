#include <iostream>

#define pi 3.1415

using namespace std;

class formas_geometricas{
    // Atribuotos e funções-membro/métodos
    public:
        virtual double imprime_area() = 0; // Cria um método virtual para ser modificado pelas classes derivadas/subclasses
        virtual void getDados() = 0;
};

// Herança simples. Derivo minhas subclasses
// class novaClasse : modificador_de_acesso
// protected: as subclasses também conseguem acessar os atributos
// private: apenas as instâncias da classe conseguem acessar a própria classe
class circulo : public formas_geometricas{
    private:
        double raio;
    public:
        double imprime_area();
        void getDados();
};

class quadrado : public formas_geometricas{
    private:
        double lado;
    public:
        double imprime_area();
        void getDados();
};

class retangulo : public formas_geometricas{
    private:
        double base;
        double altura;
    public:
        double imprime_area();
        void getDados();
};

double quadrado::imprime_area(){
    double area;
    area = lado*lado;
    cout << "Área do quadrado: " << area << endl;
    return area;
}

void quadrado::getDados(){
    cout << "Digite o lado do quadrado: ";
    cin >> lado;
}

double retangulo::imprime_area(){
    double area;
    area = base * altura;
    cout << "Área do retângulo: " << area << endl;
    return area;
}

void retangulo::getDados(){
    cout << "Digite a base do retângulo: ";
    cin >> base;
    cout << "Digite a altura do retângulo: ";
    cin >> altura;
}

// Método que vai calcular a área e imprimir
double circulo::imprime_area(){
    double area;
    area = raio*raio*pi;
    cout << "Área do círculo: " << area << endl;
    return area;
}

// Método para adquirir dados da forma
void circulo::getDados(){
    cout << "Digite o raio do círculo: ";
    cin >> raio; // circulo::raio ou this->raio
}

int main(){
    // Quando eu instancio, chamo o contrutor da classe
    // Nesse caso, não alterei o construtor, uso o padrão fornecido
    quadrado q; // Intancianção de um objeto da classe quadrado
    q.getDados();
    q.imprime_area();

    retangulo r;
    r.getDados();
    r.imprime_area();

    circulo c;
    c.getDados();
    c.imprime_area();

    return 0;
}