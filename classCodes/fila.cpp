#include <iostream>
using namespace std;

// elemento da lista, contem dados e ponteiro para o próximo elemento

typedef int tipo;
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

class list{
    public:
        // métodos
        // construtor da lista
        list(){
            // lista vazia
            head = tail = NULL;
        }
        // destrutor
        // ~lista();
        int isEmpty(); // retorna se a lista é vazia
        void addToHead(tipo dado);
        void addToTail(tipo dado);
        void printList();
        void deleteHead();
        void deleteTail();
        tipo front();
    private:
        // informações
        node *head, *tail;
};

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
        list fila; // fila de elementos
        int n; // número de elemento
};

queue::queue() : fila(), n(0){}

int queue::size(){
    return n;
}

bool queue::empty(){
    return n == 0;
}

tipo list::front(){
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
    fila.addToTail(dado); // insere elemento no final da fila
    ++n; // incrementa no tamanho da fila
}

void queue::dequeue(){
    fila.deleteHead(); // remove elemento do inicio;
    --n; // decrementa o tamanho da fila
}

void queue::printQueue(){
    fila.printList();
}
int list::isEmpty(){
    return head == NULL;
}

void list::addToHead(tipo dado){
    // cria o nó e faz com que seu próximo seja o head
    head = new node(dado, head);
    if(tail == NULL){
        tail = head;
    }
}

void list::addToTail(tipo dado){
    if(!isEmpty() == 1){
        tail->prox = new node(dado);
        tail = tail->prox;
    } else{
        head = tail = new node(dado);
    }
}

void list::printList(){
    for(node *tmp = head; tmp != NULL; tmp = tmp->prox){
        cout << tmp->dado << " ";
    }
    cout << endl;
}

void list::deleteHead(){
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

void list::deleteTail(){
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

    fila.enqueue(1);
    fila.enqueue(2);
    fila.enqueue(3);
    fila.printQueue();
    fila.dequeue();
    fila.printQueue();

    return 0;
}