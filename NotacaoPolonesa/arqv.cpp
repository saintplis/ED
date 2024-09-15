#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "lib.h"

using namespace std;

// compila usando g++ arqv.cpp lib.cpp
// roda com ./a.out
// A entrada deve ser digitada junta EX: (4+2)*(32^-2)
 
int main() {
  string expressao;

  cout << "Digite a expressão infixa para a sua conversão: ";
  cin >> expressao;
  if(verificacao_expressao(expressao)){
    list resultado = addToStack(expressao);
    resultado.printList();
    resultado.verificacao_resultado();
  } else{
    getchar();
  }
  return 0;
}
