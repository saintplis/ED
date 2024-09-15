// herança múltipla - a classe vai ser derivada de mais de uma classe base
#include <iostream>
#include <cstring>
using namespace std;

class livro{
    public:
        livro(char *titulo, int edicao);
        void mostra_livro(void);
    protected:
        char titulo[64];
        int edicao;
};

class disco{
    protected:
        char cantor[64];
        int segundos;
    public:
        disco(char *cantor, int segundos);
        void mostra_disco();
};

disco::disco(char *cantor, int segundos){
    strcpy(disco::cantor, cantor);
    disco::segundos = segundos;
}

void disco::mostra_disco(){
    cout << "Cantor: " << cantor << endl << "Segundos: " << segundos << endl;
}

livro::livro(char *titulo, int edicao){
    livro::edicao = edicao;
    strcpy(livro::titulo, titulo);
}

void livro::mostra_livro(){
    cout << "Título: " << titulo << endl;
    cout << "Edição: " << edicao << endl;
}

// Herança multipla, herda atributos e metodos tanto de livro quanto de disco
class pacote : public livro, public disco{
    private:
        double preco;
    public:
        pacote(char *titulo, int edicao, char *cantor, int segundos, double preco);
        void mostra_pacote();
};

pacote::pacote(char *titulo, int edicao, char *cantor, int segundos, double preco) : livro(titulo, edicao), disco(cantor, segundos){
    pacote::preco = preco;
}

void pacote::mostra_pacote(){
    cout << "Título do livro: " << titulo << " | Edição: " << edicao << endl;
    cout << "Disco do cantor: " << cantor << " | Segundos: " << segundos << endl;
    cout << "Preco do pacote: " << preco << endl;
}

int main(){
    char tit[] = "Bíblia do Programador";
    char cnt[] = "Roberto Carlos";
    char tnt[] = "Qulaquer Coisa";
    char can[] = "AgainAndAGain";
    disco roberto(cnt, 78);
    roberto.mostra_disco();
    livro biblia(tit, 4);
    biblia.mostra_livro();
    pacote p(tnt, 6, can, 90, 170.99);
    p.mostra_pacote();
    return 0;
}