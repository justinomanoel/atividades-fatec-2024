/*****************************************************************************

			EXERCICIOS

*****************************************************************************

1 - Escreva um programa que permute o conteúdo de duas variáveis sem utilizar uma
    variável auxiliar.

2 - Escreva um programa que receba dados via teclado para variaveis do tipo short,
    long, int, float, double e um char e imprima-os no video no seguinte
    formato:
             10        20        30        40        50        60
     12345678901234567890123456789012345678901234567890123456789012345
         short               long                int
                   float               double              char
3 - Escreva um programa que receba via teclado um tempo em segundos e converta
    para horas, minutos e segundos.
    Ex.: recebe 3850 segundos que converte para 1h 4min 10s.


4 - Faça um programa para ler um numero inteiro, positivo de tres digitos, e gerar
    outro número formado pelos dígitos invertidos do número lido.
    Ex:   NúmeroLido = 123
        NúmeroGerado = 321

5 - Escreva um programa que determine o menor multiplo de um numero inteiro. Este
    multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
    teclado.
    Ex: menor multiplo de 13 maior que 100. Resultado: 104.
*/

#define ex3
#include <stdio.h>

#ifdef ex1
void main(){

    int a;
    int b;

    printf("Digite o primeiro numero:\n");
    scanf("%d", &a);

    printf("Digite o segundo numero:\n");
    scanf("%d", &b);

    a = a - b;
    b = b + a;
    a = b - a;

    printf("\n%d e %d", a,b);

}
#endif // ex1

#ifdef ex2
      /*     10        20        30        40        50        60
     12345678901234567890123456789012345678901234567890123456789012345
         short               long                int
                   float               double              char */

void main(){
short s = 10;
long l = 1000;
int i = 100;
float f = 10.10;
double d = 10.101010;
char c = 'D';

printf("\t10 \t  20 \t    30 \t      40 \t50 \t  60\n");
printf("12345678901234567890123456789012345678901234567890123456789012345\n");
printf("%9hd%19ld%19d\n", s,l,i);
printf("%19.2f%21e%18c", f,d,c);
}
#endif // ex2

#ifdef ex3
void main(){
    int tempo, hora, minuto, segundo;

    printf("Digite um tempo em segundos.\n");
    scanf("%d",&tempo);
    hora=tempo/3600;
    printf("O tempo digitado foi de %d horas.\n",hora);
    minuto=(tempo%3600)/60;
    printf("O tempo digitado foi de %d minutos.\n",minuto);
    segundo=(minuto%60)/60;
    printf("O tempo digitado foi de %d segundos.\n",segundo);

}

#endif // ex3

#ifdef ex4
void main(){
    int numero;
    int unidade;
    int dezena;
    int centena;
    int numeroNovo;

    printf("Digite um numero com 3 digitos: \n");
    scanf("%d", &numero);

    unidade = numero / 100;
    dezena = (numero % 100) / 10;
    centena = numero % 10;

    numeroNovo = (centena * 100) + (dezena * 10) + unidade;
    printf("O novo numero e %d", numeroNovo);
}
#endif // ex4

/* 5 - Escreva um programa que determine o menor multiplo de um numero inteiro. Este
    multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
    teclado.
    Ex: menor multiplo de 13 maior que 100. Resultado: 104.
*/

#ifdef ex5
void main(){
    int numero;
    int soma=0;
    int limite;
  printf("Digite um numero inteiro.\n");
  scanf("%d",&numero);
  printf("Digite um limite minimo.\n");
  scanf("%d",&limite);
  if(limite<numero){
    printf("O menor multiplo de %d maior que %f e igual a %d",numero,limite,numero);
  }else{
        while(soma<limite){
        soma++;
        }while(soma%numero!=0){
                soma++;
        }
  printf("O menor multiplo de %d maior que %d e igual a %d",numero,limite,soma);
    }
}

#endif // ex5

