#include <iostream>

typedef int tipo;

class cnode{
    private:
        tipo elemento;
        cnode* next;

    friend class listaCircular; // fornece acesso aos métodos privados da classe
};

class listaCircular{
    public:
        listaCircular();
        bool isEmpty();
        tipo front(); // elemento no cursor
        tipo back(); // elemento depois do cursor
        void add(tipo elemento); // adiciona depois do cursor
        void remove(); // remove antes do cursor
        void advance(); // "caminha" com o cursor
        void printClist();
    private:
        cnode* cursor;
};

listaCircular::listaCircular() : cursor(NULL) {}

bool listaCircular::isEmpty(){
    return cursor == NULL;
}

tipo listaCircular::back(){
    return cursor->elemento;
}

tipo listaCircular::front(){
    return cursor->next->elemento;
}

void listaCircular::advance(){
    cursor = cursor->next;
}

void listaCircular::add(tipo elemento){
    // cria um novo nó
    cnode* v = new cnode;
    v->elemento = elemento;
    if(isEmpty()){
        v->next = v;
        cursor = v;
    } else{ // adiciona o nó novo v depois do cursor
        v->next = cursor->next;
        cursor->next = v;
    }
}

void listaCircular::remove(){
    // não verifica se a lista está vazia
    cnode* old = cursor->next; // remove o nó depois do cursor
    if(old == cursor){
        cursor = NULL;
    } else{
        cursor->next = old->next;
    }
    delete old; // deleta o nó
}

void listaCircular::printClist(){
    for(cnode *tmp = cursor->prox; tmp != cursor; tmp = tmp->prox){
        cout << tmp->elemento << " ";
    }
    cout << cursor->elemento << endl;
}
class node{
    public:
        node(){
            prox = NULL;
        }
        node(tipo dado, node *ptr = NULL);
        tipo dado;
        node *prox;
};

node::node(tipo dado, node *ptr){
    node::dado = dado;
    node::prox = ptr;
}

class queue{
    public:
        queue(); // construtor
        void enqueue(tipo dado); // insere elemento no final da fila
        void dequeue(); // retira o elemento do inicio da fila
        int size(); // retorna o numeor de itens
        bool empty(); // retorna se a fila está vazia
        tipo front(); // retorna o primeiro elemento da fila
        void printQueue(); // printa a fila
    private:
        listaCircular fila; // fila de elementos
        int n; // número de elemento
};

queue::queue() : fila(), n(0){}

int queue::size(){
    return n;
}

bool queue::empty(){
    return n == 0;
}

tipo listaCircular::front(){
    return head->dado;
}

tipo queue::front(){
    if(empty()){
        cout << "Atenção! A lista está vazia";
        return 0;
    }
    else{
        return fila.front();
    }
}

void queue::enqueue(tipo dado){
    fila.add(dado); // insere elemento no final da fila
    ++n; // incrementa no tamanho da fila
}

void queue::dequeue(){
    fila.deleteHead(); // remove elemento do inicio;
    --n; // decrementa o tamanho da fila
}

void queue::printQueue(){
    fila.printList();
}
int listaCircular::isEmpty(){
    return head == NULL;
}

void listaCircular::addToHead(tipo dado){
    // cria o nó e faz com que seu próximo seja o head
    head = new node(dado, head);
    if(tail == NULL){
        tail = head;
    }
}

void listaCircular::addToTail(tipo dado){
    if(!isEmpty() == 1){
        tail->prox = new node(dado);
        tail = tail->prox;
    } else{
        head = tail = new node(dado);
    }
}

void listaCircular::printList(){
    for(node *tmp = head; tmp != NULL; tmp = tmp->prox){
        cout << tmp->dado << " ";
    }
    cout << endl;
}

void listaCircular::deleteHead(){
    if(isEmpty()){
        cout << "Atenção: Lista vazia!" << endl;
    } else{
        node *tmp = head;
        if(head == tail){
            head = tail = NULL;
        } else{
            head = head->prox;
        }
        delete tmp;
    }
}

void listaCircular::deleteTail(){
    if(isEmpty()){
        cout << "Atenção: Lista vazia!" << endl;
    } else{
        if(head == tail){
            head = tail = NULL;
        } else{
            node *tmp;
            for(tmp = head; tmp->prox != tail; tail = tmp->prox){}
            tail = tmp;
            tail->prox = NULL;
        }
    }
}

int main(){
    queue fila;

    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.imprime(); // lista encadeada -> lista circular


    return 0;
}
