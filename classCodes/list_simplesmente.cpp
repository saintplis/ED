#include <iostream>
using namespace std;

// elemento da lista, contem dados e ponteiro para o próximo elemento
class node{
    public:
        node(){
            prox = NULL;
        }
        node(int dado, node *ptr = NULL);
        int dado;
        node *prox;
};

node::node(int dado, node *ptr){
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
        void addToHead(int dado);
        void addToTail(int dado);
        void printList();
        void deleteHead();
        void deleteTail();
        void removeX();
    private:
        // informações
        node *head, *tail;
};

int list::isEmpty(){
    return head == NULL;
}

void list::addToHead(int dado){
    // cria o nó e faz com que seu próximo seja o head
    head = new node(dado, head);
    if(tail == NULL){
        tail = head;
    }
}

void list::addToTail(int dado){
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

void list::removeX(){
    for(node* tmp = head; tmp!=NULL; tmp = tmp->prox){
        if(tmp == head && tmp->dado == 0){
            delete tmp;
            printList();
        } else if(tmp->prox->dado == 0){
            node* sucessor = tmp->prox->prox;
            tmp->prox = sucessor;
            delete tmp;
            printList();
        }
    }
}

int main(){
    // node *p = new node(10);
    // p->prox = new node(8);
    // p->prox->prox = new node(50);
    // cout << p->dado << " ";
    // cout << p->prox->dado << " ";
    // cout << p->prox->prox->dado << endl;

    list l;
    l.addToHead(10);
    l.printList();
    l.addToTail(20);
    l.addToHead(0);
    l.printList();
    l.addToHead(5);
    l.printList();
    l.addToTail(50);
    l.printList();
    l.addToHead(0);
    l.printList();

    l.removeX();
    l.printList();

    return 0;
}
