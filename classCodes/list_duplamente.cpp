#include <iostream>
using namespace std;

typedef char tipo;

// friend class // classe amiga, é uma classe que tem acesso a todos métodos privados da outra 

class node{
    // informações
    private:
        tipo dado;
        node* prox;
        node* anterior;
        friend class list;
};

class list{
    public:
        // construtor
        list();
        // destrutor
        ~list();
        bool isEmpty();
        // adiciona nó antes do nó atual
        void addNode(node* atual, const tipo& dado);
        void addToHead(const tipo& dado);
        void addToTail(const tipo& dado);
        void removeNode(node *atual);
        void removeNodeFromTail();
        void removeNodeFromHead();
        void printList();
    private:
        node* head;
        node* tail;
};

list::list(){
    head = new node;
    tail = new node;
    head->prox = tail;
    tail->anterior = head;
}

list::~list(){
    delete head;
    delete tail;
}

bool list::isEmpty(){
    return(head->prox == tail);
}

void list::addNode(node* atual, const tipo& dado){
    // add from tail
    node* novo = new node;
    novo->dado = dado;
    novo->prox = atual;
    novo->anterior = atual->anterior;
    atual->anterior->prox = novo;
    atual->anterior = novo;    
}

void list::addToTail(const tipo& dado){
    // adidiona antes do tail (dummy)
    addNode(tail, dado);
}

void list::addToHead(const tipo& dado){
    // adiciona após o head (dummy)
    addNode(head->prox, dado);
}

void list::printList(){
    for (node* tmp = head->prox; tmp != tail; tmp = tmp->prox){
        cout << tmp->dado << " ";
    }
    cout << endl;
}

void list::removeNode(node* atual){
    // salvar o nó antecessor
    node* antecessor = atual->anterior;
    // salvo o nó sucessor
    node* sucessor = atual->prox;
    antecessor->prox = sucessor;
    sucessor->anterior = antecessor;
    delete atual;
}

void list::removeNodeFromHead(){
    removeNode(head->prox);
}

void list::removeNodeFromTail(){
    removeNode(tail->anterior);
}

int main(){
    list dupla;
    dupla.addToHead('A');
    dupla.addToTail('X');
    dupla.addToHead('C');
    dupla.addToTail('X');
    dupla.printList();

    dupla.removeNodeFromHead();
    dupla.printList();
    dupla.removeNodeFromTail();
    dupla.printList();

    dupla.

    return 0;
}
