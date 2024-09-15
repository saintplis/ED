#include <iostream>

using namespace std;

// Programa que representa um semáforo
// 1 - qual o objetivo: ser um semáforo
// 2 - quais propriedade e capacidades o objeto vai possuir e COMO será a interação: semáforo (estado atual dele: verde, vermelho ou amarelo)
// 3 - quais operações o semáforo vai realizar: mostrar estado, trocar de estado...
// 4 - solidifica a interface da classe ou seja, escreve a declaraão da classe e explora as funções e dados. Decidir quais dados vão ser expostos e quais ocultados

class semaforo{
    // membros da classe - funções ou dados
    public: // dados ou funções PÚBLICOS que podem ser utilizados por outros objetos/funções
        int getEstado(); // função que consegue ACESSAR o dado mas não modifica ele
        void mudaEstado(); // fnção que vai executar exatamente o que esta descrito
        void setEstado(int est); // método para modificar o estado inicial (inicializadora)
        void traduzEstado(int est);
        semaforo(int est = 0); // CONSTRUTOR
    private: // é visível APENAS para o objeto pertencete a classe
        int estado;
};

semaforo::semaforo(int est){
    setEstado(est);
};

// :: acessa o que tá dentro da classe
void semaforo::setEstado(int est){
    // this->estado = est;
    semaforo::estado = est;
};

int semaforo::getEstado(){
    return semaforo::estado;
};

void semaforo::mudaEstado(){
    // 0 - verde, 1 - amarelo, 2 - vermelho
    if(semaforo::estado == 0){
        setEstado(1);
    } else if(semaforo::estado == 1){
        setEstado(2);
    } else{
        setEstado(0);  
    }
};

void semaforo::traduzEstado(int est){
    if(semaforo::estado == 0){
        cout << "Verde" << endl;
    } else if(semaforo::estado == 1){
        cout << "Amarelo" << endl;
    } else{
        cout << "Vermelho" << endl;
    }
};
int main(){
    int est;

    cout << "Digite o estado inicial (0 - verde, 1 - amarelo, 2 - vermelho): ";
    cin >> est;
    semaforo sem(est); // cria o objeto da classe semaforo
    // sem.setEstado(est); // inicializo meu semaforo sem
    cout << "O estado atual do semáforo é: " << sem.getEstado() << endl;
    // sem.setEstado(est);
    // cout << "O estado atual do semáforo é: " << sem.getEstado() << endl;
    
    semaforo aux;
    cout << "O estado atual do semáforo é: " << aux.getEstado() << endl;

    while(aux.getEstado() != 2){    
        aux.traduzEstado(est);        
        aux.mudaEstado();       
        // cout << "O estado atual do semáforo é: " << aux.getEstado() << endl;
    }
    return 0;
};
