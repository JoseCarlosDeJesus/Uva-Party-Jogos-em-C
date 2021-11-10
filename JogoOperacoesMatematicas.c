#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int dificuldade;
    int operacao;
    int valor1;
    int valor2;
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

   printf("Informe o nivel de dificuldade desejado[1,2,3 ou 4]:\n");
   scanf("%d",&dificuldade);
   calc.dificuldade=dificuldade;

   //gera operacao randomica de 0 a 2
   calc.operacao= rand()%3;
   if(calc.dificuldade==1){
      //fácil
      calc.valor1=rand()%11;//0 a 10

      calc.valor2=rand()%11;//0 a 10
   }else if(calc.dificuldade==2){
      //médio
      calc.valor1=rand()%101;//0 a 100
      calc.valor2=rand()%101;
   }else if(calc.dificuldade==3){
       //dificil
      calc.valor1=rand()%1001;
      calc.valor2=rand()%1001;
   }else if(calc.dificuldade==4){
      //muito dificil
      calc.valor1=rand()%10001;
      calc.valor2=rand()%10001;
   }else{
     //tá trollando
     calc.valor1=rand()%100001;
     calc.valor2=rand()%100001;
   }
   int resposta;
   printf("informe o resultado para a seguinte operacao: \n");

   //somar
   if(calc.operacao=0){
      printf("%d+%d\n", calc.valor1, calc.valor2);
      scanf("%d",&resposta);
      if(somar(resposta,calc)==resposta){
        pontos+=1;
        printf("Voce tem %d ponto(s).\n", pontos);
      }
   }else if(calc.operacao=1){
       printf("%d-%d\n", calc.valor1, calc.valor2);
      scanf("%d",&resposta);
      if(diminuir(resposta,calc)==resposta){
        pontos+=1;
        printf("Voce tem %d ponto(s).\n", pontos);
      }
   }else if(calc.operacao=2){
        printf("%d*%d\n", calc.valor1, calc.valor2);
      scanf("%d",&resposta);
      if(multiplicar(resposta,calc)==resposta){
        pontos+=1;
        printf("Voce tem %d ponto(s).\n", pontos);
      }
   }else{//operacao desconhecida
      printf("a operacao %d nao e reconhecida\n", calc.operacao);
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

void mostrarInfo(Calcular calc){
     char op[25];
     if(calc.operacao == 0){ //aqui zero quer dizer que vai ser uma soma
        sprintf(op, "Somar");
     }else if(calc.operacao ==1){//1==diminuir
        sprintf(op, "Diminuir");
     }else if(calc.operacao==2){//2=multiplicar
        sprintf(op, "Multiplicar");
     }else{
        sprintf(op, "Operacao Desconhecida");
     }
     printf("Valor 1: %d\n Valor 2: %d\n Dificuldade: %d \n Operacao: %s",
            calc.valor1, calc.valor2, calc.dificuldade, op);
}

int somar(int resposta, Calcular calc){
    int resultado=calc.valor1+calc.valor2;
    calc.resultado=resultado;
    int certo=0;//0==errou 1==acertou
    if(resposta ==calc.resultado){
        printf("resposta correta!\n");
        certo=1;
    }else{
        printf("resposta errada!\n");
    }
    printf("%d +%d=%d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}

int diminuir(int resposta,Calcular calc){
    int resultado=calc.valor1-calc.valor2;
    calc.resultado=resultado;
    int certo=0;//0==errou 1==acertou
    if(resposta ==calc.resultado){
        printf("resposta correta!\n");
        certo=1;
    }else{
        printf("resposta errada!\n");
    }
    printf("%d -%d=%d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;

}

int multiplicar(int resposta,Calcular calc){
   int resultado=calc.valor1*calc.valor2;
    calc.resultado=resultado;
    int certo=0;//0==errou 1==acertou
    if(resposta ==calc.resultado){
        printf("resposta correta!\n");
        certo=1;
    }else{
        printf("resposta errada!\n");
    }
    printf("%d *%d=%d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}
