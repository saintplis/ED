#include <iostream>
using namespace std;

typedef int tipo;

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
        void addNode(node* atual, tipo dado);
        void addToHead(tipo dado);
        void addToTail(tipo dado);
        void removeNode(node *atual);
        void removeNodeFromTail();
        void removeNodeFromHead();
        void printList();
        tipo front();
        tipo back();
    private:
        node* head;
        node* tail;
};

class deck{
    public:
        deck(); // contrutor
        void insereInicio(tipo dado);
        void insereFim(tipo dado);
        void removeInicio();
        void removeFim();
        int size();
        bool isEmpty();
        tipo front();
        tipo back();
        void printDeck();
    private:
        list dq; // lista de elementos
        int n; // número de elementos
};

deck::deck() : dq(), n(0) {}

void deck::insereInicio(tipo dado){
    ++n;
    dq.addToHead(dado);
}

void deck::insereFim(tipo dado){
    ++n;
    dq.addToTail(dado);
}

void deck::removeInicio(){
    if(isEmpty()){
        cout << "Lista vazia";
    } else{
        --n;
        dq.removeNodeFromHead();
    }
}

int deck::size(){
    return n;
}

bool deck::isEmpty(){
    return dq.isEmpty();
}

tipo deck::front(){
    return dq.front();
}

tipo deck::back(){
    return dq.back();
}

void deck::printDeck(){
    dq.printList();
}
void deck::removeFim(){
    if(isEmpty()){
        cout << "Lista Vazia!!" << endl;
    } else{
        --n;
        dq.removeNodeFromTail();
    }
}

tipo list::front(){
    return head->prox->dado;
}

tipo list::back(){
    return tail->anterior->dado;
}

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

void list::addNode(node* atual, tipo dado){
    // add from tail
    node* novo = new node;
    novo->dado = dado;
    novo->prox = atual;
    novo->anterior = atual->anterior;
    atual->anterior->prox = novo;
    atual->anterior = novo;    
}

void list::addToTail(tipo dado){
    // adidiona antes do tail (dummy)
    addNode(tail, dado);
}

void list::addToHead(tipo dado){
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
    deck dq;

    dq.insereInicio(5);
    dq.printDeck();
    dq.insereFim(4);
    dq.printDeck();
    dq.insereInicio(7);
    dq.printDeck();
    dq.removeFim();
    dq.printDeck();
    dq.removeInicio();
    dq.printDeck();
    dq.removeFim();
    dq.removeFim();

    cout << dq.front() << endl;
    cout << dq.size() << endl;
        
    return 0;
}
