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
        void addNode(node* atual, const tipo& dado);
        void addToHead(const tipo& dado);
        void addToTail(const tipo& dado);
        void removeNode(node *atual);
        void removeNodeFromTail();
        void removeNodeFromHead();
        void printList();
        tipo front(); // retorna o primeiro elemento da pilha
    private:
        node* head;
        node* tail;
};

tipo list::front(){
    return head->dado;
}

class stack{
    public:
        stack();
        int size(); // função que retorna o tamanho da pilha
        bool empty(); // retorna se a pilha está vazia ou não
        tipo top(); // retorna elemento do topo da lista
        void push(tipo elemento); // empilha
        void pop(); // desempilha
        void printStack();
    private:
        list pilha; // lista de elementos
        int n; // número de elementos
};

stack::stack():pilha(), n(0) {}

int stack::size(){
    return n;
}

bool stack::empty(){
    return n == 0;
}

tipo stack::top(){
    if(empty()){
        cout << "Atenção! Pilha Vazia" << endl;
        return 0;
    } else{
        // retorna o elemento do topo da pilha
        return pilha.front();
    }
}

void stack::push(tipo elemento){
    // incremento tamanho da pilha
    ++n;
    // adiciono no topo
    pilha.addToHead(elemento);
}

void stack::pop(){
    if(empty()){
        cout << "Atenção! Pilha Vazia" << endl;
    } else{
        --n;
        pilha.removeNodeFromHead();
    }
}

void stack::printStack(){
    pilha.printList();
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
    stack pilha;

    pilha.push(3);
    pilha.push(4);
    pilha.top();
    pilha.printStack();
    /*
    list dupla;
    dupla.addToHead(1);
    dupla.addToTail(2);
    dupla.addToHead(0);
    dupla.addToTail(3);
    dupla.printList();

    dupla.removeNodeFromHead();
    dupla.printList();
    dupla.removeNodeFromTail();
    dupla.printList();
    */

    return 0;
}
