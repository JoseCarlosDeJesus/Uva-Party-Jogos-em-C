#include"ListasFuncoesJogoOperacoesMatematicas.c"

typedef struct{
    int dificuldade;
    int operacao;
    Lista*valores;
    int resultado;
}Calcular;

void jogarOperacao();
void mostrarInfo(Calcular calc);
int somar(int resposta,Calcular calc);
int diminuir(int resposta,Calcular calc);
int multiplicar(int resposta,Calcular calc);

int pontos=0;


int main(){
    srand(time(NULL));

    jogarOperacao();
    return 0;
}

void jogarOperacao(){
   Calcular calc;
   int dificuldade;
   calc.valores=inicializa();

   printf("Informe o nivel de dificuldade desejado[1,2,3 ou 4]:\n");
   scanf("%d",&dificuldade);
   calc.dificuldade=dificuldade;

   //gera operacao randomica de 0 a 2
   calc.operacao= rand()%3;
   if(calc.dificuldade==1){
      //fácil
      insere(calc.valores,rand()%11);
      insere(calc.valores,rand()%11);//0 a 10
   }else if(calc.dificuldade==2){
      //médio
      insere(calc.valores,rand()%101);
      insere(calc.valores,rand()%101);
   }else if(calc.dificuldade==3){
       //dificil
      insere(calc.valores,rand()%1001);
      insere(calc.valores,rand()%1001);
   }else if(calc.dificuldade==4){
      //muito dificil
      insere(calc.valores,rand()%10001);
      insere(calc.valores,rand()%10001);
   }else{
     //tá trollando
     insere(calc.valores,rand()%100001);
      insere(calc.valores,rand()%100001);
   }
   int resposta;
   printf("informe o resultado para a seguinte operacao: \n");

   //somar
   if(calc.operacao=0){
      printf("A soma de:");
      imprime(calc.valores);
      scanf("%d",&resposta);
      if(somar(resposta,calc)==resposta){
        pontos+=1;
        printf("Voce tem %d ponto(s).\n", pontos);
      }
   }else if(calc.operacao=1){
       printf("A subtraçao de:");
      imprime(calc.valores);
      scanf("%d",&resposta);
      if(diminuir(resposta,calc)==resposta){
        pontos+=1;
        printf("Voce tem %d ponto(s).\n", pontos);
      }
   }else if(calc.operacao=2){
      printf("a multiplicacao de :");
      imprime(calc.valores);
      scanf("%d",&resposta);
      if(multiplicar(resposta,calc)==resposta){
        pontos+=1;
        printf("Voce tem %d ponto(s).\n", pontos);
      }
   }else{//operacao desconhecida
      printf("a operacao %d nao e reconhecida\n", calc.operacao);
      exit(1);
   }
   //Recomeçar o jogo?
   printf("Deseja continuar jogando? [1-sim, 0-nao]\n");
   int continuar;
   scanf("%d",&continuar);
   if(continuar==1){
      jogarOperacao();
   }else{
      printf("Voce finalizou com %d ponto(s).\n", pontos);
      exit(0);
   }
}

int somar(int resposta, Calcular calc){
    int resultado=0;
    Lista*p;
    for(p=calc.valores;p!=NULL;p=p->prox){
        resultado+=p->info;
    }
    calc.resultado=resultado;
    int certo=0;//0==errou 1==acertou
    if(resposta ==calc.resultado){
        printf("resposta correta!\n");
        certo=1;
    }else{
        printf("resposta errada!\n");
    }
    return certo;
}

int diminuir(int resposta,Calcular calc){
    Lista*p=calc.valores;
    int resultado=p->info;
    p=p->prox;
    resultado-=p->info;
    calc.resultado=resultado;
    int certo=0;//0==errou 1==acertou
    if(resposta ==calc.resultado){
        printf("resposta correta!\n");
        certo=1;
    }else{
        printf("resposta errada!\n");
    }
    return certo;

}

int multiplicar(int resposta,Calcular calc){
    Lista*p=calc.valores;
    int resultado=p->info;
    p=p->prox;
    resultado=resultado*p->info;
    calc.resultado=resultado;
    int certo=0;//0==errou 1==acertou
    if(resposta ==calc.resultado){
        printf("resposta correta!\n");
        certo=1;
    }else{
        printf("resposta errada!\n");
    }
    return certo;
}
