
//insere os numeros aleatórios na lista
Numeros*insereNumeros(Numeros*a){
     Numeros*novo=(Numeros*)malloc(sizeof(Numeros));
     novo->info=(rand()%100);
     novo->prox=a;
     return novo;
}

void imprimeNumeros(Numeros* a){
     Numeros*p;
     for(p=a;p!=NULL;p=p->prox){
         printf("%d\n", p->info);
     }
}

Respostas*insereRespostas(Respostas*a, int v){
     Respostas*novo=(Respostas*)malloc(sizeof(Respostas));
     novo->info=v;
     novo->prox=a;
     return novo;
}

Numeros* inicializaNumeros(){
     return NULL;
}
Respostas*inicializaRespostas(){
    return NULL;
}

int NumeroDeAcertos(Numeros*a,Respostas*b){
    Numeros*p;
    Respostas*c;
    int i=0;
    for(p=a,c=b;p!=NULL&& c!=NULL;p=p->prox,c=c->prox){
        if(p->info==c->info){
            i++;
        }
    }
    return i;
}

void liberaNumeros(Numeros* a){
     Numeros*p=a;
     while(p!=NULL){
          Numeros*t=p->prox;
          free(p);
          p=t;
     }
}

void liberaRespostas(Respostas*a){
     Respostas*p=a;
     while(p!=NULL){
        Respostas*t=p->prox;
        free(p);
        p=t;
     }
}
