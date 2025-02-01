/*
OBS.: Todos os programa devem ser finalizados pelo usuario.

1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    Receba dados via teclado em uma funcao e imprima estes conteudos no video,
    em outra funcao, no seguinte formato.
     estrutura: char, int, long, float, double, unsigned char, unsigned int,
                unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        int                 long                float     double
              unsigned int        unsigned long       char      unsigned char

*/

#include <stdio.h>
#define ex3

#ifdef ex1

struct estrutura {
        char a;
        int b;
        long c;
        float d;
        double e;
        unsigned char f;
        unsigned int g;
        unsigned long h;
    };

    struct estrutura estrutura1;

    void recebeDados(){
        printf("Digite um char: ");
        scanf("%c", &estrutura1.a);
        getchar();
        printf("\nDigite um int: ");
        scanf("%d", &estrutura1.b);
        getchar();
        printf("\nDigite um long: ");
        scanf("%ld", &estrutura1.c);
        getchar();
        printf("\nDigite um float: ");
        scanf("%f", &estrutura1.d);
        getchar();
        printf("\nDigite um double: ");
        scanf("%lf", &estrutura1.e);
        getchar();
        printf("\nDigite um unsigned char: ");
        scanf("%c", &estrutura1.f);
        getchar();
        printf("\nDigite um unsigned int: ");
        scanf("%ud", &estrutura1.g);
        getchar();
        printf("\nDigite um unsigned long: ");
        scanf("%ul", &estrutura1.h);
        getchar();
    }

    void mostraDados(){
        printf("        10        20        30        40        50        60        70");
        printf("\n1234567890123456789012345678901234567890123456789012345678901234567890");
        printf("\n%7d%21d%21.2f%11.2f",estrutura1.b,estrutura1.c,estrutura1.d,estrutura1.e);
        printf("\n%22u%21lu%11c%16c",estrutura1.g,estrutura1.h,estrutura1.a,estrutura1.f);
    }

    int main(){
        char continuar;
    do{
        recebeDados();
        mostraDados();
        printf("\nDeseja continuar?(s/n)\n");
        continuar = getchar();
    if(continuar != 's' && continuar != 'n'){
        printf("Desculpe, nao entendi o que digitou. Digite 's' para continuar e 'n' para encerrar\n");
    }
    }while(continuar=='s');
    return 0;
    }


#endif // ex1

/*
2 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estruturas de 4 elementos. Receba os dados pelo teclado em uma funcao
    e imprima-os no video em uma funcao. Utilize vetor de estruturas.
    Fa a um menu com uma opcao para saida do programa.
		estrutura: nome, end, cidade, estado, cep
*/
#ifdef ex2

struct casa{
    char nome[40];
    char end[60];
    char cidade[30];
    char estado[30];
    };
main(){
    struct casa pessoa[4];
    int i;
    int menu;
    do{
    printf("Digite o nome e endereco dos quatro participantes\n");
    for(i=0;i<4;i++){
        printf("\nDigite o nome: ");
        gets(pessoa[i].nome);

        printf("\nDigite o endereco: ");
        gets(pessoa[i].end);

        printf("\nDigite a cidade: ");
        gets(pessoa[i].cidade);

        printf("\nDigite o estado: ");
        gets(pessoa[i].estado);

        printf("\nNome: %s - Endereco: %s, %s - %s\n", pessoa[i].nome, pessoa[i].end, pessoa[i].cidade, pessoa[i].estado);
    }
    printf("Os participantes são:");
    printf("\nNome: %s - Endereco: %s, %s - %s\n", pessoa[0].nome, pessoa[0].end, pessoa[0].cidade, pessoa[0].estado);

    printf("\nNome: %s - Endereco: %s, %s - %s\n", pessoa[1].nome, pessoa[1].end, pessoa[1].cidade, pessoa[1].estado);

    printf("\nNome: %s - Endereco: %s, %s - %s\n", pessoa[2].nome, pessoa[2].end, pessoa[2].cidade, pessoa[2].estado);

    printf("\nNome: %s - Endereco: %s, %s - %s\n", pessoa[3].nome, pessoa[3].end, pessoa[3].cidade, pessoa[3].estado);

    printf("Digite 1 para continuar: ");
    scanf("%d", &menu);
    getchar();

    }while(menu==1);
}


#endif // ex2
/*
3 - Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via
    teclado na funcao main(). Faca uma funcao que calcule o numero de dias
    entre elas e mostre o resultado no video na funcao main().
    Utilize vetor de estruturas.
                estrutura: dia, mes, ano

*/
#ifdef ex3

    int qntdias = 0;

    struct estrutura {
        int dia;
        int mes;
        int ano;
    };

    struct estrutura data1;
    struct estrutura data2;



    void calculaDias(){
        int maiorano, menorano, maiormes, menormes, maiordia, menordia, qtddias=0;

        maiorano = (data1.ano > data2.ano) ? data1.ano : data2.ano;
        menorano = (data1.ano < data2.ano) ? data1.ano : data2.ano;
        maiormes = (data1.ano > data2.ano) ? data1.mes : data2.mes; //DEFINI COMO MAIOR MES O MES DO MAIOR ANO//
        menormes = (data1.ano < data2.ano) ? data1.mes : data2.mes; //DEFINI COMO MENOR MES O MES DO MENOR ANO//
        maiordia = (data1.ano > data2.ano) ? data1.dia : data2.dia; //DEFINI COMO MAIOR DIA O DIA DO MAIOR ANO//
        menordia = (data1.ano < data2.ano) ? data1.dia : data2.dia; //DEFINI COMO MENOR DIA O DIA DO MENOR ANO//

        //ANOS//
        for(int i=maiorano-1;i>menorano;i--){
            if(i%4==0 || i%400==0){
                qtddias += 366;
            }else{
                qtddias += 365;}
            }
        //MESES//
        for(int v=menormes;v<=12;v++){
                switch(v){
            case 12:
                if(menormes==12){
                    qtddias+=31-menordia;}
                else{
                    qtddias+=31;}
                break;
            case 11:
                if(menormes==11){
                    qtddias+=30-menordia;}
                else{
                    qtddias+=30;}
                break;
            case 10:
                if(menormes==10){
                    qtddias+=31-menordia;}
                else{
                    qtddias+=31;}
                break;
            case 9:
                if(menormes==9){
                    qtddias+=30-menordia;}
                else{
                    qtddias+=30;}
                break;
            case 8:
                if(menormes==8){
                qtddias+=31-menordia;}
                    else{
                qtddias+=31;}
                break;
            case 7:
                if(menormes==7){
                    qtddias+=31-menordia;}
                else{
                    qtddias+=31;}
                break;
            case 6:
                if(menormes==6){
                    qtddias+=30-menordia;}
                else{
                    qtddias+=30;}
                break;
            case 5:
                if(menormes==5){
                    qtddias+=31-menordia;}
                else{
                    qtddias+=31;}
                break;
            case 4:
                if(menormes==4){
                    qtddias+=30-menordia;}
                else{
                    qtddias+=30;}
                break;
            case 3:
                if(menormes==3){
                    qtddias+=31-menordia;}
                else{
                    qtddias+=31;}
                break;
            case 2:
                if(menormes==2){
                if(menorano%4==0 || menorano%400==0){
                    qtddias+=29-menordia;}}
                else{
                if(menorano%4==0 || menorano%400==0){
                    qtddias+=29;}
                else{
                    qtddias+=28;}
                }
                break;
            case 1:
                if(menormes==12){
                    qtddias+=31-menordia;}
                else{
                    qtddias+=31;}
                break;
            }
        }
        for(int a=maiormes;a>0;a--){
                switch(a){
            case 12:
                if(maiormes==12){
                qtddias+=maiordia;}else{
                qtddias+=31;}
                break;
            case 11:
                if(maiormes==11){
                qtddias+=maiordia;}else{
                qtddias+=30;}
                break;
            case 10:
                if(maiormes==10){
                qtddias+=maiordia;}else{
                qtddias+=31;}
                break;
            case 9:
                if(maiormes==9){
                qtddias+=30-menordia;}else{
                qtddias+=30;}
                break;
            case 8:
                if(maiormes==8){
                qtddias+=maiordia;}else{
                qtddias+=31;}
                break;
            case 7:
                if(maiormes==7){
                qtddias+=maiordia;}else{
                qtddias+=31;}
                break;
            case 6:
                if(maiormes==6){
                qtddias+=maiordia;}else{
                qtddias+=30;}
                break;
            case 5:
                if(maiormes==5){
                qtddias+=maiordia;}else{
                qtddias+=31;}
                break;
            case 4:
                if(maiormes==4){
                qtddias+=maiordia;}else{
                qtddias+=30;}
                break;
            case 3:
                if(maiormes==3){
                qtddias+=maiordia;}else{
                qtddias+=31;}
                break;
            case 2:
                if(maiormes==2){
                if(maiorano%4==0 || maiorano%400==0){
                    qtddias+=maiordia;}}
                else{
                if(maiorano%4==0 || maiorano%400==0){
                    qtddias+=29;}
                else{
                    qtddias+=28;}
                }
                break;
            case 1:
                if(maiormes==12){
                qtddias+=maiordia;}else{
                qtddias+=31;}
                break;
            }
        }
    printf("\nEntre as duas datas se passaram %d dias.\n",qtddias);
    }


    void main(){
        char continuar;
        do{
        do{
        printf("\nDigite um dia, de 1 a 31: ");
        scanf("%d",&data1.dia);
        if(data1.dia < 1 || data1.dia > 31){
            printf("Voce digitou um dia invalido.");}
        }while(data1.dia < 1 || data1.dia > 31);
        do{
        printf("\nDigite um mes, de 1 a 12: ");
        scanf("%d",&data1.mes);
        if(data1.mes < 1 || data1.mes > 12){
            printf("Voce digitou um mes invalido.");}
        }while(data1.mes < 1 || data1.mes > 12);
        printf("\nDigite um ano: ");
        scanf("%d",&data1.ano);
        do{
        printf("\nDigite um dia, de 1 a 31: ");
        scanf("%d",&data2.dia);
        if(data2.dia < 1 || data2.dia > 31){
            printf("Voce digitou um dia invalido.");}
        }while(data2.dia < 1 || data2.dia > 31);
        do{
        printf("\nDigite um mes, de 1 a 12: ");
        scanf("%d",&data2.mes);
        if(data1.mes < 1 || data1.mes > 12){
            printf("Voce digitou um mes invalido.");}
        }while(data2.mes < 1 || data2.mes > 12);
        printf("\nDigite um ano: ");
        scanf("%d",&data2.ano);
        getchar();
        calculaDias();

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
        return;
    }


#endif // ex3
/*
4 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estrutura de 4 elementos. Receba dados via teclado e imprima-os no video.
    Faca um menu com as seguintes opcoes:
    1 - receber todos os dados
    2 - imprime todos os dados
    3 - calcula o IMC de todas as pessoas.
    4 - sair
        Calculo do IMC = peso/(altura*altura).
        estrutura: nome, peso, altura
*/
#ifdef ex4

struct dados{
    char nome[20];
    float altura;
    float peso;
};

void main(){
    int retorno = 0;
    int menu;
    int i;
    struct dados pessoa[4];
    do{
    printf("\nDigite o numero da acao desejada:\n");
    printf("1 - receber todos os dados\n2 - imprime todos os dados\n3 - calcula o IMC de todas as pessoas\n4 - sair\n");
    scanf("%d", &menu);
    if(menu == 1){
        for(i=0;i<4;i++){
            printf("\nPessoa %d:\nDigite o nome: ", i+1);
            scanf("%s", &pessoa[i].nome[0]);

            printf("\nDigite a altura em metros: ");
            scanf("%f", &pessoa[i].altura);
            getchar();

            printf("\nDigite o peso em Kg: ");
            scanf("%f", &pessoa[i].peso);

            printf("\n%s, %.2fm, %.2fkg\n", pessoa[i].nome, pessoa[i].altura, pessoa[i].peso);
        }
    }
    else if(menu == 2){
        for(i=0;i<4;i++){
            printf("\nPessoa %d: %s, %.2fm, %.2fkg\n", i+1, pessoa[i].nome, pessoa[i].altura, pessoa[i].peso);
        }
    }

    else if(menu == 3){
        for(i=0;i<4;i++){
            printf("\nIMC %s: %.2f\n", pessoa[i].nome, pessoa[i].peso/(pessoa[i].altura*pessoa[i].altura));
        }
    }

    else if(menu == 4){
        retorno = 1;
    }
    }while(retorno == 0);
}
#endif // ex4

