#include<PilhaJogoOperacoesMatematicas.c>

//cria pilha
Pilha*cria();
//insere elemento na pilha
void push(Pilha*p,int v);
//retira elemento da pilha
int pop(Pilha*p);
//ver se a pilha está vazia
int vazia(Pilha*p);
//libera a pilha
void libera(Pilha*p);

// cria calculadora
Calc* cria_calc (char* f);
//coloca o operando ou seja o numero na pilha da calculadora
void operando (Calc* c, int v);
//coloca o operador na calculadora
void operador (Calc* c, char op);
//libera a calculadora
void libera_calc (Calc* c);

