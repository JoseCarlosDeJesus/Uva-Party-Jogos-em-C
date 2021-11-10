#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

int main(){
    int i=0, j=0, acertos=0;
    char c;
    int numeros[5];
    int respostas[5];

    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));//gera n�meros aleat�rios
    //TODO colocar numeros e respostas em uma lista dinamica
    printf("Este programa gera n n�meros aleat�rios de 1 a 30: \n");
    printf("Voc� deve decorar os n�meros exibidos em 5 segundos e depois escrev�-los na ordem em que foram mostrados\n");
    printf("Pressione ENTER para iniciar\n");

    do{
       c=getch();
    }while(c!=13);

    for(i=0;i<5;i++){
        numeros[i]=(rand()%30);
    }

    j=5;

    do{
       system("cls");//limpa a tela prompt
       printf("Decore os numeros abaixo em %d\n\n\n", j);
       j--;
       for(i=0;i<5;i++){
          printf("%d\t", numeros[i]);
       }
       Sleep(1000);
    }while(j>0);

    system("cls");
    printf("informe os n�meros que foram exibidos\n\n\n");

    for(i=0;i<5;i++){
        printf("\t%d� n�mero: ", i+1);
        scanf("%d", &respostas[i]);
        if(respostas[i]==numeros[i]){
           acertos++;
        }
    }

    if(acertos==5){
       printf("\n\nParab�ns! Sua mem�ria � muito boa.Veja os numeros exibidos:\n\n\t");
       for(i=0;i<5;i++){
          printf("%d\t", numeros[i]);
       }
    }
    else{
       printf("\n\n Voce Errou! Veja os n�meros exibidos: \n\n\t");
       for(i=0;i<5;i++){
          printf("%d\t", numeros[i]);
       }
    }
    printf("\n\n");
    system("pause");


    return 0;
}
