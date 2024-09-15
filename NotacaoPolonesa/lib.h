#ifndef LIB_H
#define LIB_H

using namespace std;

typedef union {
  char c;
  float n;
} tipo;

class node {
private:
  tipo dado; // Corrigido: Removido o ponto
  node *prox;
  node *anterior;
  friend class list;
};

class list {
public:
  list();
  ~list();
  bool isEmpty();
  void addNode(node *atual, tipo dado);
  void addToHead(tipo dado);
  void addToTail(tipo dado);
  void removeNode(node *atual);
  void removeNodeFromHead();
  void printHead();
  void printList();
  void verificacao_resultado();
  tipo front(); // retorna o primeiro elemento da pilha
private:
  node *head;
  node *tail;
};

class stack {
public:
  stack();
  int size();               // função que retorna o tamanho da pilha
  bool empty();             // retorna se a pilha está vazia ou não
  tipo top();               // retorna elemento do topo da lista
  void push(tipo elemento); // empilha
  void pop();               // desempilha
  void printStack();
private:
  list pilha; // lista de elementos
  int n;      // número de elementos
};

list addToStack(string expressao);

bool verificacao_expressao(string expressao);

#endif