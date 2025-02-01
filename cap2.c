/*****************************************************************************

			EXERCICIOS

******************************************************************************
OBS.: Todos os programa devem ser finalizados pelo usuario.

1 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
    pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
    comando if-else.

2 - Reescreva o programa do exercicio anterior agora utilizando o comando switch.
    Conte o n. de tentativas e imprima o resultado no video.

3 - Escreva um programa que receba via teclado numeros inteiros positivos.
    Quando o numero digitado for negativo o programa deve parar e calcula a
    media dos valores positivos digitados.

4 - Receba via teclado a distancia em km e a quantidade de litros de gasolina
    consumidos por um carro em um percurso.
    Calcule o consumo em km/l e escreva uma mensagem de acordo com a tabela
    abaixo:
    CONSUMO (km/l) MENSAGEM
    menor que 8    Venda o carro!
    entre 8 e 14   Economico!
    maior que 14   Super economico!

5 - As ligacoes telefonicas são cobradas pela sua duracao. O sistema registra os
    instantes em que a ligacao foi iniciada e concluida.
    Escreva um programa que recebe via teclado dois instantes dados em
    horas, minutos e segundo e determina o intervalo de tempo
    (em horas, minutos e segundos) decorrido entre eles.

*/

#define ex5
#include <stdio.h>
#include <locale.h>

#ifdef ex1
int main() {
    setlocale(LC_ALL, "");

    int chute, chuteMax, chuteMin;
    char continuar, resultado;

    do {
        printf("\n *** Jogo de Adivinhação *** \n");
        int acertou = 0;
        chuteMax = 99;
        chuteMin = 1;

        do {
            chute = (chuteMax + chuteMin) / 2;
            printf("\nÉ o número %d? (Digite '>' se for seu número for maior, '<' se seu número for menor ou '=' se eu acertei): ", chute);
            scanf("%c",  &resultado);
            getchar();

            if (resultado == '=') {
                printf("\nAcertei, o número que você pensou foi %d.\n", chute);
                acertou = 1;
            } else if (resultado == '>') {
                chuteMin = chute + 1;
            } else if (resultado == '<') {
                chuteMax = chute - 1;
            } else {
                printf("\nDigite '>' se meu palpite foi muito alto, '<' se foi muito baixo ou '=' se eu acertei.\n");
            }
        } while (!acertou);

        printf("\nDeseja continuar jogando? (s/n)\n");
        scanf("%s", &continuar);
        getchar();

    } while (continuar != 'n' && continuar != 'N');
}
#endif // ex1

#ifdef ex2
int main() {
    setlocale(LC_ALL, "");

    int chute, chuteMax, chuteMin, tentativas;
    char continuar, resultado;

    do {
        printf("\n *** Jogo de Adivinhação *** \n");
        int acertou = 0;
        tentativas = 1;
        chuteMax = 99;
        chuteMin = 1;

        do {
            chute = (chuteMax + chuteMin) / 2;
            printf("\nÉ o número %d? (Digite '>' se for seu número for maior, '<' se seu número for menor ou '=' se eu acertei): ", chute);
            scanf("%c",  &resultado);
            getchar();

            switch (resultado) {
                case '=':
                    printf("\nAcertei em %d tentativas, o número que você pensou foi %d.\n", tentativas, chute);
                    acertou = 1;
                    tentativas++;
                    break;
                case '>':
                    chuteMin = chute + 1;
                    tentativas ++;
                    break;
                case '<':
                    chuteMax = chute - 1;
                    tentativas ++;
                    break;
                default:
                    printf("\nDigite '>' se meu palpite foi muito alto, '<' se foi muito baixo ou '=' se eu acertei.\n");
            }

        } while (!acertou);

        printf("\nDeseja continuar jogando? (s/n)\n");
        scanf("%s", &continuar);
        getchar();

    } while (continuar != 'n' && continuar != 'N');
}
#endif // ex2
/*3 - Escreva um programa que receba via teclado numeros inteiros positivos.
    Quando o numero digitado for negativo o programa deve parar e calcula a
    media dos valores positivos digitados.*/

#ifdef ex3
int main() {
    setlocale(LC_ALL, "Portuguese");

    int numero;
    int soma = 0;
    int contagem = 0;
    float media;

    printf("Digite um número inteiro\n");

    do{

        scanf("%d", &numero);
        if(numero>=0){
        soma = soma + numero;
        contagem++;
        printf("Digite outro inteiro\n");
        }

    }while(numero>=0);
    media = soma/contagem;
    printf("A media dos valores positivos digitados é:%.2f", media);
}
#endif // ex3

/*4 - Receba via teclado a distancia em km e a quantidade de litros de gasolina
    consumidos por um carro em um percurso.
    Calcule o consumo em km/l e escreva uma mensagem de acordo com a tabela
    abaixo:
    CONSUMO (km/l) MENSAGEM
    menor que 8    Venda o carro!
    entre 8 e 14   Economico!
    maior que 14   Super economico! */
#ifdef ex4
int main() {
    float km,consumo,lt;
    char continuar;
    do{
        printf("Digite a distancia percorrida em km.\n");
        scanf("%f", &km);
        printf("Digite o consumo de gasolina do carro em litros.\n");
        scanf("%f", &lt);
        consumo = km/lt;
    if(consumo < 8){
        printf("O consumo do carro foi de: %.2f.\nVenda o carro!\n",consumo);
    }else if(consumo <= 14){
        printf("O consumo do carro foi de: %.2f.\nEconomico!\n",consumo);
    }else{
        printf("O consumo do carro foi de: %.2f.\nSuper economico!\n",consumo);
    }
    printf("Deseja calcular o consumo de outro carro? Digite 's' para sim e 'n' para encerrar o programa.\n");
    scanf("%s", &continuar);

    }while(continuar == 's');
}
#endif // ex4

/*5 - As ligacoes telefonicas são cobradas pela sua duracao. O sistema registra os
    instantes em que a ligacao foi iniciada e concluida.
    Escreva um programa que recebe via teclado dois instantes dados em
    horas, minutos e segundo e determina o intervalo de tempo
    (em horas, minutos e segundos) decorrido entre eles. */

#ifdef ex5
int main(){
    int hora,minuto,segundo,hora2,minuto2,segundo2,duracaoh,duracaom,duracaos,x;

    do{
    printf("Digite a hora que a ligacao foi iniciada.\n");
    scanf("%d", &hora);
    if(hora>24){
        printf("As horas devem ir no maximo ate 24.\n");
    }
    }while(hora>24);
    do{
    printf("Digite os minutos em que a ligacao foi iniciada.\n");
    scanf("%d", &minuto);
    if(minuto>60){
            printf("Os minutos devem ir no maximo ate 60.\n");
    }
    }while(minuto>60);
    do{
    printf("Digite os segundos em que a ligacao foi iniciada.\n");
    scanf("%d", &segundo);
    if(segundo>60){
            printf("Os segundos devem ir no maximo ate 60.\n");
    }
    }while(segundo>60);

    do{
    printf("Digite a hora que a ligacao terminou.\n");
    scanf("%d", &hora2);
    if(hora2>24){
        printf("As horas devem ir no maximo ate 24.\n");
    }
    }while(hora2>24);
    do{
    printf("Digite os minutos em que a ligacao terminou.\n");
    scanf("%d", &minuto2);
    if(minuto2>60){
            printf("Os minutos devem ir no maximo ate 60.\n");
    }
    }while(minuto2>60);
    do{
    printf("Digite os segundos em que a ligacao terminou.\n");
    scanf("%d", &segundo2);
    if(segundo2>60){
            printf("Os segundos devem ir no maximo ate 60.\n");
    }
    }while(segundo2>60);

    if(hora2<hora){
        x=hora2+24;
        duracaoh = x-hora;
    }else{
    duracaoh = hora-hora2;
    }
    if(minuto+minuto2>=60){
        duracaoh++;
        duracaom = minuto+minuto2-60;
    }else{
    duracaom = minuto+minuto2;
    }
    if(segundo+segundo2>=60){
        duracaom++;
        duracaos = segundo+segundo2-60;
    }else{
    duracaos = segundo+segundo2;
    }
    printf("A duracao da ligacao foi de %d horas %d minutos e %d segundos.\n",duracaoh, duracaom, duracaos);


}

#endif // ex5
