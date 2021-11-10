#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

//struct dos números aleatórios que serão memorizados
struct numerosMemoria{
       int info;
       struct numerosMemoria*prox;
};
typedef struct numerosMemoria Numeros;

//struct das respostas dadas pelo usuário sobre os números que serão memorizados
struct respostasMemoria{
       int info;
       struct respostasMemoria*prox;
};
typedef struct respostasMemoria Respostas;

//insere os numeros aleatórios na lista Numeros
Numeros*insereNumeros(Numeros*a);

//imprime os numeros aleatórios
void imprimeNumeros(Numeros* a);

//insere as respostas dadas pelo usuário na lista de Respostas
Respostas*insereRespostas(Respostas*a, int v);

//inicializa com NULL a lista de Numeros
Numeros* inicializaNumeros();

//inicializa com NULL a lista de Respostas
Respostas*inicializaRespostas();

//retorna o número de acertos, ou seja quando numeros->info=respostas->info
int NumeroDeAcertos(Numeros*a,Respostas*b);

//libera a memória alocada para a lista de números
void liberaNumeros(Numeros* a);

//libera a memória alocada para a lista de respostas
void liberaRespostas(Respostas*a);
