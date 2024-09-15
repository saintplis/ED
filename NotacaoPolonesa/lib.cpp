#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "lib.h"

using namespace std;

tipo list::front() { return head->prox->dado; }

stack::stack() : pilha(), n(0) {}

int stack::size() { return n; }

bool stack::empty() { return n == 0; }

tipo stack::top() {
  if (empty()) {
    tipo vazio;
    vazio.c = '\0'; // Retorna um char nulo
    return vazio;
  } else {
    return pilha.front();
  }
}

void stack::push(tipo elemento) {
  ++n;
  pilha.addToHead(elemento);
}

void stack::pop() {
  if (empty()) {
    return;
  } else {
    --n;
    pilha.removeNodeFromHead();
  }
}

void stack::printStack(){
    pilha.printList();
}

bool list::isEmpty() { return (head->prox == tail); }

void list::printHead() {
  cout << head->prox->dado.c; // Acessa o membro 'c' da union
}

list::list() {
  head = new node;
  tail = new node;
  head->prox = tail;
  tail->anterior = head;
}

list::~list() {
  delete head;
  delete tail;
}

void list::addNode(node *atual, tipo dado) {
  node *novo = new node;
  novo->dado = dado;
  novo->prox = atual;
  novo->anterior = atual->anterior;
  atual->anterior->prox = novo;
  atual->anterior = novo;
}

void list::addToHead(tipo dado) { addNode(head->prox, dado); }

void list::removeNode(node *atual) {
  node *antecessor = atual->anterior;
  node *sucessor = atual->prox;
  antecessor->prox = sucessor;
  sucessor->anterior = antecessor;
  delete atual;
}

void list::removeNodeFromHead() { removeNode(head->prox); }

void list::addToTail(tipo dado) { // Corrigido
  addNode(tail, dado);
}

void list::printList() {
  int firstintec = 1;
  for (node *tmp = head->prox; tmp != tail; tmp = tmp->prox) {
    if(tmp->dado.c == ' ' && firstintec == 1){
      firstintec = 0;
      continue;
    }
    if(tmp->dado.c == ' ' && tmp->prox->dado.c == ' '){
      firstintec = 0;
      continue;
    }
    firstintec = 0;
    cout << tmp->dado.c; // Acessa o membro 'c' da union
  }
  cout << endl;
}

list addToStack(string expressao) {
  char symbols[6] = {'(', '^', '*', '/', '+', '-'};
  stack pilha; // Pilha para armazenar operadores e parenteses
  list resultado; //Lista para armazenar o resutaldo final
  tipo espaco; //Adiciona os espaços
  espaco.c = ' '; //Espaço com caracter 
  for (int i = 0; expressao[i] != '\0'; i++) {
    tipo elemento; // Estrutura para o caracter auxiliar
    tipo elemento2; // para o caracter auxiliar 
    tipo elemento3; // Para o caracter auxiliar
    elemento.c = expressao[i];
    
    if(expressao[i] == symbols[0]){ //Se tiver os "("
      pilha.push(elemento); // Empilha o parentese
      resultado.addToTail(espaco); //Adiciona um espaço

      // Verifica se há um operador '-' seguido de um dígito logo após '('
      if (expressao[i+1] == symbols[5] && isdigit(expressao[i+2])){
        elemento2.c = expressao[i+1];
        resultado.addToTail(elemento2); // Adiciona o '-'
        elemento3.c = expressao[i+2];
        resultado.addToTail(elemento3); // Adiciona o digito ao resultado
        i += 2; // Avança o indice para pular os caracteres
      }

    }else if(expressao[i] == symbols[1]) { // Se tiver os "^"
      if(pilha.top().c == '-'){
        resultado.addToTail(espaco); // Adiciona um espaço
        resultado.addToTail(pilha.top()); //Adiciona '-' ao resultado
        pilha.pop(); //Remove '-' da pilha
      }
      // Se o próximo caractere for '-', empilha '-' e '^'
      if(expressao[i+1] == '-'){
        elemento2.c = expressao[i+1];
        pilha.push(elemento2); // Empilha '-'
        pilha.push(elemento); // Empilha '^'
        resultado.addToTail(espaco); // Adiciona um espaço
        i++; // Avanço o indice
      }else{
        pilha.push(elemento); //Empilha '^'
        resultado.addToTail(espaco); // Adciona um espaço
      }
    // Se tiver os "*" ou "/"
    } else if (expressao[i] == symbols[2] || expressao[i] == symbols[3]) {
      // Se o proximo caractere for '-', empilha '-' e o operador
      if(expressao[i+1] == '-'){
        elemento2.c = expressao[i+1];
        pilha.push(elemento2); //Empilha o '-'
        pilha.push(elemento); //Empilha '*' ou '/'
        resultado.addToTail(espaco); // Adiciona um espaço
        i++; // Avança o indice para pular o '-'
      } else{
        resultado.addToTail(espaco); // Adiciona um espaço
        // Enquanto houver '^', '*' ou '/' no topo da pilha, desempilha
        while (pilha.top().c == symbols[1] || pilha.top().c == symbols[2] || pilha.top().c == symbols[3]) { // Enquanto ler "^" ou "*" ou "/"
          resultado.addToTail(pilha.top()); //Adiciona ao resultado
          resultado.addToTail(espaco); //Adiciona um espaço
          pilha.pop(); //Remove o operador da pilha
        }
        pilha.push(elemento); //Empilha o operador atual
      }
      
    } else if (expressao[i] == symbols[4]) { // Se tiver os "+"
      resultado.addToTail(espaco); // Adiciona um espaço 
      while (pilha.top().c != 0 && (pilha.top().c != '(')) {
        resultado.addToTail(pilha.top()); //Adiciona ao resultado
        resultado.addToTail(espaco); // Adiciona um espaço
        pilha.pop(); // Remove o operador da pilha
      }
      pilha.push(elemento); // Empilha o '+'

    } else if (expressao[i] == symbols[5]) { // Se tiver os "-"
      resultado.addToTail(espaco); // Adiciona um espaço
      // Desempilha até encontrar '(' ou a pilha ficar vazia
      while (pilha.top().c != 0 && (pilha.top().c != '(')) {
        resultado.addToTail(pilha.top()); // Adiciona ao resultado
        pilha.pop(); //Remove o operador da pilha
      }
      pilha.push(elemento); // Empilha o '-'

    // Desempilha até encontrar o ')'  
    } else if (expressao[i] == ')') { 
      resultado.addToTail(espaco); //Adiciona um espaço
      // Desempilha até encontrar o '('  
      while (pilha.top().c != '(') {
        resultado.addToTail(pilha.top()); //Adiciona ao resultado 
        pilha.pop(); //Remove o operador da pilha 
        resultado.addToTail(espaco); //Adiciona um espaço
      }
      pilha.pop(); //Remove o '(' da pilha
    } else { // Se for Letra ou número
      resultado.addToTail(elemento);
    }
  }
  // Desempilha qualquer operador restante da pilha
  while (!pilha.empty()) {
    resultado.addToTail(espaco); // Adiciona um espaço ao resultado 
    resultado.addToTail(pilha.top()); //Adiciona o operador ao resultado
    pilha.pop(); //Remove o operador da pilha 
  }
  return resultado; // Retorna a lista com a expressão em notação pós-fixa
}

void list::verificacao_resultado() {
  stack pilha;
  char eq[100];
  int i = 0;
  tipo num1;
  tipo num2;
  tipo res;

  // Desempilha a pilha e adiciona em uma string 
  while (isEmpty() == false) {
    eq[i] = front().c;
    i++;
    removeNodeFromHead();
  }

  eq[i] = '\0';  // Adiciona o terminador nulo à string
  
  char *word = strtok(eq, " ");
  while (word != NULL) {
    if (isdigit(word[0]) || (word[0] == '-' && isdigit(word[1]))) { //Se o primeiro for um numero positivo ou negativo
      res.n = atof(word); // Transforma de caracter em numero
      pilha.push(res); // Adiciona na pilha
    } else { // Caso seja um op
      num1 = pilha.top(); // Pega o primeiro numero da pilha
      pilha.pop(); // Retira da pilha
      if(pilha.empty()){  // Para os casos com "-(2*3)" fazer a multiplicação do - com o resultado do parentese
        res.n = num1.n * -1;
      }else{
        num2 = pilha.top(); // Transforma de caracter em numero
        pilha.pop(); // tira da pilha
        switch (word[0]) {
        case '+':
          res.n = num2.n + num1.n;
          break;
        case '-':
          res.n = num2.n - num1.n;
          break;
        case '*':
          res.n = num2.n * num1.n;
          break;
        case '/':
          res.n = num2.n / num1.n;
          break;
        case '^':
          res.n = pow(num2.n, num1.n);
          if(word[2] == '-'){ //Verifica se é uma potencia negativa "2^-3"
            res.n = 1/res.n; // Transforma em uma divisão
            word[2] = ' '; // tira o menos da expressão
          }
          break;
        }
      }
      pilha.push(res);
    }
    word = strtok(NULL, " ");
  }
  cout << pilha.top().n << endl; // Manda para a pilha após realizar as operações
}

bool verificacao_expressao(string expressao){
  int qty = expressao.length();

  // verificar se o primeiro elemento da expressao é (, - ou número
  if(expressao[0] == '(' || expressao[0] == '-' || isdigit(expressao[0])){
    // verifica se os parenteses estão corretos
    int parenteses = 0;
    for(int i = 0; i <= qty; i++){
      if(expressao[i] == '('){
        parenteses++;
      } else if(expressao[i] == ')'){
        parenteses--;
      }
      if((i == qty && parenteses != 0) || (parenteses < 0)){
        cout << "[ERRO]. Os parenteses da expressão estão incorretos" << endl;
        return false;
      }
    }

    char operadores[7] = {'^', '/', '*', '+', '-', '(', ')'}; 
    // verifica se toda a expressao é composta por números ou operadores
    for(int i = 0; i < qty; i++){
      for(int j = 0; j < 7; j++){
        if(isdigit(expressao[i]) || expressao[i] == operadores[j]){
          break;
        } if((expressao[i] != operadores[j]) && (j == 6)){
          cout << "[ERRO]. Expressão composta por caracteres inválidos" << endl;
          return false;
        }
      }
    }
    
    for(int i = 0; i < qty; i++){
      switch (expressao[i]){
      case '^':
        // - || digito || (
        if((expressao[i+1] != '-') && (!isdigit(expressao[i+1])) && (expressao[i+1] != '(')){
          cout << "[ERRO]. Operadores inválidos" << endl;
          return false;
        }
        break;
      case '*':
        // - || digito || (
        if((expressao[i+1] != '-') && (!isdigit(expressao[i+1])) && (expressao[i+1] != '(')){
          cout << "[ERRO]. Operadores inválidos" << endl;
          return false;
        }
        break;
      case '/':
        // - || digito || (
        if((expressao[i+1] != '-') && (!isdigit(expressao[i+1])) && (expressao[i+1] != '(')){
          cout << "[ERRO]. Operadores inválidos" << endl;
          return false;
        }
        break;
      case '+':
        // || digito || (
        if((!isdigit(expressao[i+1])) && (expressao[i+1] != '(')){
          cout << "[ERRO]. Operadores inválidos" << endl;
          return false;
        }
        break;
      case '-':
        // || digito || (
        if((!isdigit(expressao[i+1])) && (expressao[i+1] != '(')){
          cout << "[ERRO]. Operadores inválidos" << endl;
          return false;
        }
        break;
      case '(':
        // - || digito || (
        if((expressao[i+1] != '-') && (!isdigit(expressao[i+1])) && (expressao[i+1] != '(')){
          cout << "[ERRO]. Operadores inválidos" << endl;
          return false;
        }
        break;
      default:
        break;
      }
    }
  } else{
    cout << "[ERRO]. O começo da expressão está incorreto" << endl;
    return false;
  }

  return true;
}