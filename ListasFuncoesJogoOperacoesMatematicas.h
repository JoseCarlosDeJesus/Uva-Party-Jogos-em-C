#include"ListasFuncoesJogoOperacoesMatematicas.c"

//inicializa a lista
Lista* inicializa();

//insere elemento na lista
Lista*insere(Lista*l,int i);

//imprime elemento da lista
void imprime(Lista* l);

//verifica se a lista está vazia
int vazia(Lista *l);

//busca elemento na lista
Lista*busca(Lista*l,int v);

//retira elemento da lista
Lista* retira(Lista* l, int v);

//libera elemento da lista
void libera(Lista* l);
