#include<stdio.h>
#define ex6

/*
1 - Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned, float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char
*/

/*

1 - Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned, float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char
*/
#ifdef ex1
    void main(){
        char continuar;
        //var//
        char let;
        int num;
        long longnum;
        float decnum;
        double doublenum;
        unsigned char unsiglet;
        unsigned int unsignum;
        unsigned long unsiglong;

        //pont//
        char *plet = &let;
        int *pnum = &num;
        long *plong = &longnum;
        float *pdec = &decnum;
        double *pdouble = &doublenum;
        unsigned char *punsiglet = &unsiglet;
        unsigned int *punsignum = &unsignum;
        unsigned long *punsiglong = &unsiglong;


        do{
            printf("Digite um char: ");
            scanf("%c", plet);
            getchar();
            printf("\nDigite um int: ");
            scanf("%d", pnum);
            getchar();
            printf("\nDigite um long: ");
            scanf("%ld", plong);
            getchar();
            printf("\nDigite um float: ");
            scanf("%f", pdec);
            getchar();
            printf("\nDigite um double: ");
            scanf("%lf", pdouble);
            getchar();
            printf("\nDigite um unsigned char: ");
            scanf("%c", punsiglet);
            getchar();
            printf("\nDigite um unsigned int: ");
            scanf("%ud", punsignum);
            getchar();
            printf("\nDigite um unsigned long: ");
            scanf("%ul", punsiglong);
            getchar();

            printf("\n        10        20        30        40        50        60");
            printf("\n123456789012345678901234567890123456789012345678901234567890");
            printf("\n%7d%21d%24u", *pnum, *plong, *punsignum);
            printf("\n%19.2f%21.2lf%18c", *pnum, *pdouble, *plet);
            printf("\n%22lu%20c", *punsiglong, *punsiglet);

        while(1){
        printf("\nDeseja continuar?(s/n)\n");
        continuar = getchar();
        getchar();

        if(continuar == 's' || continuar == 'n'){
                break;
            }else{
        printf("Desculpe, nao entendi o que digitou. Digite 's' para continuar e 'n' para encerrar\n");
                }
            }
        }while(continuar=='s');
    }


#endif // ex1
/*
2 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
    funcao para compara-las usando ponteiros e retorne como resultado se
    sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main().
    Imprima o resultado na funcao main(). Declare os vetores como variavel global
*/
#ifdef ex2
    char str1[11], str2[11];

    int comparaStr(){
        for(int i=0; i<10; i++){
            char *pStr1 = str1[i];
            char *pStr2 = str2[i];

            if(pStr1 != pStr2){
                return 0;
            }
        }
        return 1;
    }

    void main(){

        char continuar;

        do{
        getchar();
        printf("\nDigite uma palavra ate 10 caracteres: ");
        gets(str1);
        printf("\nDigite outra palavra ate 10 caracteres: ");
        gets(str2);

        int strigual = comparaStr();

        if(strigual == 1){
        printf("\nAs palavras sao iguais.");
        }else{
        printf("\nAs palavras sao diferentes.");}

        while(1){
        printf("\nDeseja continuar?(s/n)\n");
        continuar = getchar();
        getchar();

        if(continuar == 's' || continuar == 'n'){
                break;
            }else{
        printf("Desculpe, nao entendi o que digitou. Digite 's' para continuar e 'n' para encerrar\n");
            }
        }
        }while(continuar=='s');
    }

#endif // ex2
/*
3 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada usando ponteiros.(utilize o comando return).
    O vetor deve ser declarado como variavel global.

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y
*/
#ifdef ex3
    char vet[] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};

    int procuraLetra(char achouletra){
        for(int i=0;i<sizeof(vet);i++){
            if(vet[i] == achouletra){
                return 1;
            }
        }
        return 0;
    }

    void main(){
        char letra;
        char continuar;

        do{
        printf("\nDigite a letra para procurar no vetor: ");
        scanf("%c", &letra);
        getchar();

        char *pletra = &letra;
        int achouletra = procuraLetra(*pletra);

        if(achouletra){
            printf("\nA letra %c esta no vetor.",*pletra);
        }else{
            printf("\nA letra %c nao esta no vetor.",*pletra);
            }

        while(1){
        printf("\nDeseja continuar?(s/n)\n");
        continuar = getchar();
        getchar();

        if(continuar == 's' || continuar == 'n'){
                break;
            }else{
        printf("Desculpe, nao entendi o que digitou. Digite 's' para continuar e 'n' para encerrar\n");
            }
        }
        }while(continuar=='s');
    }

#endif // ex3
/*
4 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
    feitos usando ponteiro.
*/
#ifdef ex4
    void main(){
        char continuar;
        int num = 0;
        int qtd = 0;
        int soma = 0;
        float media;

        int *pnum = &num;
        int *psoma = &soma;
        float *pmedia = &media;

    do{
        do{

            printf("\nDigite um numero inteiro: ");
            scanf("%d", pnum);
            getchar();
            qtd++;
            soma += *pnum;

        }while (*pnum >= 0);

        *pmedia = (float) soma / qtd;

        printf("\nA media dos valores digitados e %.2f", *pmedia);

        while(1){
        printf("\nDeseja continuar?(s/n)\n");
        continuar = getchar();
        getchar();

        if(continuar == 's' || continuar == 'n'){
                break;
            }else{
        printf("Desculpe, nao entendi o que digitou. Digite 's' para continuar e 'n' para encerrar\n");
            }
        }
        }while(continuar=='s');

    }

#endif // ex4
/*
5 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
    recebidos no video numa usando ponteiros. Utilize um comando de loop.
    O vetor de estruturas deve ser declarado como variavel global
       estrutura: nome, end, cidade, estado, cep
*/
#ifdef ex5

    struct cadastro{
        char nome[20];
        char end[40];
        char cidade[20];
        char estado [20];
        int cep;
    };



    void main(){
        char continuar;
        struct cadastro cadastros[4];
        struct cadastro *pcadastros = cadastros;

        do{
        for(int i=0;i<4;i++){
          printf("\nDigite o nome da %da pessoa:\n",i+1);
          gets(pcadastros->nome);

          printf("\nDigite o endereco:\n");
          gets(pcadastros->end);

          printf("\nDigite a cidade:\n");
          gets(pcadastros->cidade);

          printf("\nDigite o estado:\n");
          gets(pcadastros->estado);

          printf("\nDigite o cep:\n");
          scanf("%d",&pcadastros->cep);
          getchar();

        pcadastros++;
        }

        pcadastros = cadastros;

        for(int i=0;i<4;i++){
            printf("\nO nome da %da pessoa e: %s",i+1,pcadastros->nome);
            printf("\nO endereco e: %s, %s - %s",pcadastros->end, pcadastros->cidade, pcadastros->estado);
            printf("\nCEP: %d",pcadastros->cep, pcadastros->cidade, pcadastros->estado);
            pcadastros++;
        }

        while(1){
        printf("\nDeseja continuar?(s/n)\n");
        continuar = getchar();
        getchar();

        if(continuar == 's' || continuar == 'n'){
                break;
            }else{
        printf("Desculpe, nao entendi o que digitou. Digite 's' para continuar e 'n' para encerrar\n");
            }
        }
        }while(continuar=='s');
    }

#endif // ex5
/*

6 - Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado
    usando ponteiros. Calcule e exiba o numero de dias entre as duas datas
    usando ponteiros. Utilize um vetor de estruturas.
    	estrutura: dia, mes e ano
*/
#ifdef ex6
#include <stdio.h>

struct datas {
    int dia;
    int mes;
    int ano;
};

int main() {
    struct datas cadastros[2];
    struct datas *data1 = &cadastros[0];
    struct datas *data2 = &cadastros[1];

    char continuar;

    do {
        do {
            printf("\nDigite um dia, de 1 a 31 para a primeira data: ");
            scanf("%d", &data1->dia);
            if (data1->dia < 1 || data1->dia > 31) {
                printf("Voce digitou um dia invalido.\n");
            }
        } while (data1->dia < 1 || data1->dia > 31);

        do {
            printf("\nDigite um mes, de 1 a 12 para a primeira data: ");
            scanf("%d", &data1->mes);
            if (data1->mes < 1 || data1->mes > 12) {
                printf("Voce digitou um mes invalido.\n");
            }
        } while (data1->mes < 1 || data1->mes > 12);

        printf("\nDigite um ano para a primeira data: ");
        scanf("%d", &data1->ano);

        do {
            printf("\nDigite um dia, de 1 a 31 para a segunda data: ");
            scanf("%d", &data2->dia);
            if (data2->dia < 1 || data2->dia > 31) {
                printf("Voce digitou um dia invalido.\n");
            }
        } while (data2->dia < 1 || data2->dia > 31);

        do {
            printf("\nDigite um mes, de 1 a 12 para a segunda data: ");
            scanf("%d", &data2->mes);
            if (data2->mes < 1 || data2->mes > 12) {
                printf("Voce digitou um mes invalido.\n");
            }
        } while (data2->mes < 1 || data2->mes > 12);

        printf("\nDigite um ano para a segunda data: ");
        scanf("%d", &data2->ano);
        getchar();
        int maiorano, menorano, maiormes, menormes, maiordia, menordia, qtddias = 0;

        maiorano = (data1->ano > data2->ano) ? data1->ano : data2->ano;
        menorano = (data1->ano < data2->ano) ? data1->ano : data2->ano;
        maiormes = (data1->ano > data2->ano) ? data1->mes : data2->mes;
        menormes = (data1->ano < data2->ano) ? data1->mes : data2->mes;
        maiordia = (data1->ano > data2->ano) ? data1->dia : data2->dia;
        menordia = (data1->ano < data2->ano) ? data1->dia : data2->dia;

        for (int i = maiorano - 1; i > menorano; i--) {
            if (i % 4 == 0 || i % 400 == 0) {
                qtddias += 366;
            } else {
                qtddias += 365;
            }
        }
        for (int v = menormes; v <= 12; v++) {
            switch (v) {
                case 12:
                    if(menormes == 12) {
                    qtddias += 31 - menordia;
                    }else{
                    qtddias += 31;}
                    break;
                case 11:
                    if(menormes == 11) {
                    qtddias += 30 - menordia;
                    }else{
                    qtddias += 30;}
                    break;
                case 10:
                    if(menormes == 10) {
                    qtddias += 31 - menordia;
                    }else{
                    qtddias += 31;}
                    break;
                case 9:
                    if(menormes == 9) {
                    qtddias += 30 - menordia;
                    }else{
                    qtddias += 30;}
                    break;
                case 8:
                    if(menormes == 8) {
                    qtddias += 31 - menordia;
                    }else{
                    qtddias += 31;}
                    break;
                case 7:
                    if (menormes == 7) {
                    qtddias += 31 - menordia;
                    }else{
                    qtddias += 31;}
                    break;
                case 6:
                    if (menormes == 6) {
                    qtddias += 30 - menordia;
                    }else{
                    qtddias += 30;}
                    break;
                case 5:
                    if(menormes == 5) {
                    qtddias += 31 - menordia;
                    }else{
                    qtddias += 31;}
                    break;
                case 4:
                    if (menormes == 4) {
                    qtddias += 30 - menordia;
                    }else{
                    qtddias += 30;}
                    break;
                case 3:
                    if (menormes == 3) {
                    qtddias += 31 - menordia;
                    }else {
                    qtddias += 31;}
                    break;
                case 2:
                    if (menormes == 2) {
                        if (menorano % 4 == 0 || menorano % 400 == 0) {
                        qtddias += 29 - menordia;
                        }else {
                        qtddias += 28 - menordia;}
                    } else {
                        if (menorano % 4 == 0 || menorano % 400 == 0) {
                        qtddias += 29;
                        }else {
                        qtddias += 28;}
                    }
                    break;
                case 1:
                    if (menormes == 12) {
                    qtddias += 31 - menordia;
                    }else {
                    qtddias += 31;}
                    break;
            }
        }

        for (int a = maiormes; a > 0; a--) {
            switch (a) {
                case 12:
                    if(maiormes == 12) {
                    qtddias += maiordia;
                    }else {
                    qtddias += 31;}
                    break;
                case 11:
                    if(maiormes == 11) {
                    qtddias += maiordia;
                    }else {
                    qtddias += 30;}
                    break;
                case 10:
                    if(maiormes == 10) {
                    qtddias += maiordia;
                    }else {
                    qtddias += 31;}
                    break;
                case 9:
                    if(maiormes == 9) {
                    qtddias += 30 - menordia;
                    }else {
                    qtddias += 30;}
                    break;
                case 8:
                    if(maiormes == 8) {
                    qtddias += maiordia;
                    }else {
                    qtddias += 31;}
                    break;
                case 7:
                    if(maiormes == 7) {
                    qtddias += maiordia;
                    }else {
                    qtddias += 31;}
                    break;
                case 6:
                    if(maiormes == 6) {
                    qtddias += maiordia;
                    }else {
                    qtddias += 30;}
                    break;
                case 5:
                    if(maiormes == 5) {
                    qtddias += maiordia;
                    }else {
                    qtddias += 31;}
                    break;
                case 4:
                    if(maiormes == 4) {
                    qtddias += maiordia;
                    }else {
                    qtddias += 30;}
                    break;
                case 3:
                    if(maiormes == 3) {
                    qtddias += maiordia;
                    }else {
                    qtddias += 31;}
                    break;
                case 2:
                    if (maiormes == 2) {
                        if (maiorano % 4 == 0 || maiorano % 400 == 0) {
                        qtddias += maiordia;}
                    } else{
                        if (maiorano % 4 == 0 || maiorano % 400 == 0) {
                        qtddias += 29;
                        }else {
                        qtddias += 28;}
                    }
                    break;
                case 1:
                    if(maiormes == 12) {
                    qtddias += maiordia;
                    }else {
                    qtddias += 31;}
                    break;
            }
        }

        printf("\nEntre as duas datas se passaram %d dias.\n", qtddias);

        while(1){
        printf("\nDeseja continuar?(s/n)\n");
        continuar = getchar();
        getchar();

        if(continuar == 's' || continuar == 'n'){
                break;
            }else{
        printf("Desculpe, nao entendi o que digitou. Digite 's' para continuar e 'n' para encerrar\n");
            }
        }
    }while (continuar == 's');

    return 0;
}

#endif // ex6
