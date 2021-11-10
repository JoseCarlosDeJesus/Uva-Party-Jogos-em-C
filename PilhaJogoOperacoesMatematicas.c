#include<stdlib.h>
#include<stdio.h>

struct no{
    int info;
    struct no* prox;
};
typedef struct no No;

struct pilha{
    No*prim;
};
typedef struct pilha Pilha;

//cria uma pilha vazia
Pilha*cria(){
    Pilha*p=(Pilha*)malloc(sizeof(Pilha));
    p->prim=NULL;
    return p;
}

//função que insere no inicio da pilha

 //função auxiliar:insere no inicio
No*ins_ini(No*l,int v){
     No*p=(No*)malloc(sizeof(No));
     p->info=v;
     p->prox=l;
     return p;
}

 //função auxiliar:retira do inicio
No*ret_ini(No*l){
    No*p=l->prox;
    free(l);
    return p;
}

//função que coloca na pilha

void push(Pilha*p,int v){
    p->prim=ins_ini(p->prim,v);
}

//função que retira da pilha

int pop(Pilha*p){
      int v;
      if(vazia(p)){
         printf("Pilha Vazia\n");
         exit(1);
      }
      v=p->prim->info;
      p->prim=ret_ini(p->prim);
      return v;
}

int vazia(Pilha*p){
    return(p->prim==NULL);
}

void libera(Pilha*p){
     No*q=p->prim;
     while(q!=NULL){
         No*t=q->prox;
         free(q);
         q=t;
     }
     free(p);
}

void imprime(Pilha*p){
     No*q;
     for(q=p->prim;q!=NULL;q=q->prox){//laço que percorre uma pilha de lista
        printf("%d\n", q->info);
     }
}


//estrutura da calculadora
struct calc{
    char f[21];//formato para impressão
    Pilha* p;//pilha de operandos
};
typedef struct calc Calc;

Calc* cria_calc()
{
   Calc* c = (Calc*) malloc(sizeof(Calc));
   c->p = cria(); /* cria pilha vazia */
   return c;
}

void operando(Calc* c, int v)
{
    /* empilha operando */
    push(c->p,v);
    /* imprime topo da pilha */
    printf(c->f,v);
}

void operador(Calc* c, char op)
{
    int v1, v2, v;
    /* desempilha operandos */
    if (vazia(c->p)){
      v2 = 0;
    }
    else{
      v2 = pop(c->p);
    }

   if(vazia(c->p)){
       v1 = 0;
   }
   else{
       v1 = pop(c->p);
   }
/* faz operação */
 switch (op) {
    case '+': v = v1+v2; break;
    case '-': v = v1-v2; break;
    case '*': v = v1*v2; break;
    case '/': v = v1/v2; break;
 }
 /* empilha resultado */
    push(c->p,v);
}
