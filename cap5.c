

/*
1 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
    funcao para compara-las e retorne como resultado se são IGUAIS 1 ou se
    DIFERENTES 0 para a funcao main(). Imprima o resultado na funcao main().
    (Declare os vetores como variavel global) (nao pode usar funcao de biblioteca)

2 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
    e imprima-os no video no seguinte formato:(Declare os 5 vetores como variaveis
    globais)

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome1                                   nome5
                nome2               nome4
                          nome3

3 - Escreva um programa que receba uma string na funcao main(). Faca uma funcao que
    calcula o comprimento de uma string recebida via teclado. Mostre o valor do
    comprimento na funcao main().
    (Declare o vetor como variavel global) (nao pode usar funcao de biblioteca)

4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras maiusculas. (nao pode usar funcao de biblioteca)

5 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras minusculas. (nao pode usar funcao de biblioteca)
*/

#include <stdio.h>
#define ex2

#ifdef ex1

char a[10];
char b[10];

int comparaPalavra(){
    int encontrou = 0;
    int i;

    for(i=0;b!='\0';i++){
        if(a[i] != b[i]){
            encontrou = 0;
            break;
        }
        if(a[i] =='\0' && b[i] =='\0'){
            encontrou = 1;
            break;
        }
    }
    return encontrou;
}

int main(){
    int encontrou;

    printf("Digite uma palavra de ate 10 letras.\n");
    scanf("%s",&a);
    printf("Digite outra palavra de ate 10 letras.\n");
    scanf("%s",&b);

    encontrou = comparaPalavra(a,b);
    if(encontrou == 1){
    printf("As palavras sao iguais.\n");
    }else{
        printf("As palavras sao diferentes.\n");
    }
    return 0;
    }

#endif

#ifdef ex2
int main(){
    char a[7];
    char b[7];
    char c[7];
    char d[7];
    char e[7];
    int repetir;

    do{
        printf("Digite um nome de ate 7 caracteres:\n");
        scanf("%s",&a[0]);

        printf("Digite um nome de ate 7 caracteres:\n");
        scanf("%s",&b[0]);

        printf("Digite um nome de ate 7 caracteres:\n");
        scanf("%s",&c[0]);

        printf("Digite um nome de ate 7 caracteres:\n");
        scanf("%s",&d[0]);

        printf("Digite um nome de ate 7 caracteres:\n");
        scanf("%s",&e[0]);

        printf("\n        10        20        30        40        50");
        printf("\n12345678901234567890123456789012345678901234567890");
        printf("\n%7s %39s", a, b);
        printf("\n%17s %19s", c, d);
        printf("\n%27s\n", e);

        printf("Deseja repetir? Digite 1 para sim e 0 para nao.\n");
        scanf("%d",&repetir);
    }while(repetir == 1);

return 0;
}
#endif

#ifdef ex3
char nome[99];

int main(){
    int repetir;

    do {
        int cont = 1;

        printf("\nDigite qualquer palavra:\n");
        scanf("%s", &nome[0]);

        while (nome[cont] != '\0') {
            cont++;
        }

        printf("\nA palavra %s possui %d letras.\n", nome, cont);

        printf("\nDeseja repetir? 1 para sim e 0 para nao.\n");
        scanf("%d", &repetir);
    } while(repetir == 1);
}


#endif // ex3

#ifdef ex4

    int repetir;
    char palavra[99];

int main(){
    do {
        printf("Digite qualquer coisa (com letras minusculas):\n");
        scanf("%s", &palavra[0]);

        int cont = 0;

        while (palavra[cont] != '\0') {

            if (palavra[cont]>='a' && palavra[cont]<='z') {
                palavra[cont] -= 32;
            }

            cont++;
        }

        printf("%s", palavra);

       printf("\nDeseja repetir? 1 para sim e 0 para nao.\n");
        scanf("%d", &repetir);

    } while(repetir == 1);
}

#endif // ex4

#ifdef ex5

    int repetir;
    char palavra[99];

int main(){
    do {
        printf("Digite qualquer coisa (com letras minusculas):\n");
        scanf("%s", &palavra[0]);

        int cont = 0;

        while (palavra[cont] != '\0') {

            if (palavra[cont]>='A' && palavra[cont]<='Z') {
                palavra[cont] += 32;
            }

            cont++;
        }

        printf("%s", palavra);

       printf("\nDeseja repetir? 1 para sim e 0 para nao.\n");
        scanf("%d", &repetir);

    } while(repetir == 1);
}

#endif // ex5
