#include <stdio.h>
#define ex6
/*1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    A estrutura e' uma variavel LOCAL na funcao main(). Receba via teclado o
    conteudo de cada um dos membros numa funcao e imprima-os no video no
    seguinte formato(tamb m numa fun  o).

    estrutura: char, int, long, float, double, unsigned char, unsigned int,
    unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long */

#ifdef ex1
typedef struct estrutura {
        char a;
        int b;
        long c;
        float d;
        double e;
        unsigned char f;
        unsigned int g;
        unsigned long h;
    }estrutura;

    void recebeDados(estrutura *p){
        printf("Digite um char: ");
        scanf("%c", &(p->a));
        printf("\nDigite um int: ");
        scanf("%d", &(p->b));
        getchar();
        printf("\nDigite um long: ");
        scanf("%ld", &(p->c));
        getchar();
        printf("\nDigite um float: ");
        scanf("%f", &(p->d));
        getchar();
        printf("\nDigite um double: ");
        scanf("%lf", &(p->e));
        getchar();
        printf("\nDigite um unsigned char: ");
        scanf("%c", &(p->f));
        getchar();
        printf("\nDigite um unsigned int: ");
        scanf("%ud", &(p->g));
        getchar();
        printf("\nDigite um unsigned long: ");
        scanf("%ul", &(p->h));
        getchar();
    }

    void mostraDados(estrutura *p){
        printf("        10        20        30        40        50        60        70");
        printf("\n1234567890123456789012345678901234567890123456789012345678901234567890");
        printf("\n%7d%21ld%21.2f%11l.5f",p->b,p->c,p->d,p->e);
        printf("\n%22u%21lu%11c%16c",p->g,p->h,p->a,p->f);
    }

    int main(){
    char continuar;
    struct estrutura estrutura1;
    estrutura *p = &estrutura1;
    do{
    recebeDados(p);
    mostraDados(p);
    if(continuar != 's' && continuar != 'n'){
        printf("Desculpe, nao entendi o que digitou. Digite 's' para continuar e 'n' para encerrar\n");
    }
    }while(continuar=='s');
    }
#endif // def

/*2 - Escreva um programa que receba em uma funcao 2 strings de ate' 10 caracteres
    passando como parametro ponteiro.
    Os vetores devem ser declarados como variaveis LOCAIS na funcao main().
    Escreva uma funcao para comparar as 2 strings. Passe como parametros para
    a funcao as 2 strings usando ponteiros e retorne como resultado se IGUAIS 1
    ou se DIFERENTES 0. Mostre o resultado no video na funcao main().*/

#ifdef ex2
typedef struct estrutura {
        char a[11];
        char b[11];
    }estrutura;

     void recebeDados(estrutura *p){
        printf("Digite um texto: ");
        gets(&p->a);
        printf("Digite outro texto: ");
        gets(&p->b);
    }

    int comparaDados(estrutura *p){
        int resposta;
        for(int i = 0; i < 12; i++ ){
            if(p->a[i] != p->b[i]){
                resposta =0;
                break;
            }
            if(p->a[i] == '\0' && p->b[i] == '\0'){
                resposta = 1;
                break;
            }
        }

        return resposta;
    }

int main(){
    char continuar;
    int comparar;
    struct estrutura estrutura1;
    estrutura *p = &estrutura1;
    do{
    recebeDados(p);
    comparar = comparaDados(p);

    if(comparar == 1){
        printf("São iguais");
    }
    else {
        printf("São diferentes");
    }
    printf("\nDeseja continuar?(s/n)\n");
    scanf("%c", &continuar);
    getchar();
    if(continuar != 's' && continuar != 'n'){
        printf("Desculpe, nao entendi o que digitou. Digite 's' para continuar e 'n' para encerrar\n");
    }
    }while(continuar=='s');
    }
#endif // ex2

/* 3 - Escreva um programa que receba n valores via teclado e receba tambem a
    operacao a ser executada. Quando for digitado "=" o programa deve mostrar
    o resultado acumulado dos n valores. As operacoes aritmeticas e a entrada
    de dados devem ser funcoes que recebe os valores usando ponteiros.
    As variaveis sao LOCAIS na funcao main().
*/

#ifdef ex3

    enviarDados(int *p){
        int i;
        char a;
        for(i=0; i<100; i++){
            printf("\nDigite um numero: ");
            scanf("%d", &p[i]);
            if(i>0)
            p[i] = p[i] + p[i-1];
            getchar();
            printf("Digite = para saber o total ou enter para continuar: ");
            scanf("%c", &a);
            if(a == '='){
                printf("Total: %d", p[i]);
                break;
            }
    }
    }

void main(){
    int n[100];
    int *p = n;

    enviarDados(p);
}
#endif // ex3


/*4 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada e o vetor usando ponteiros e faca a pesquisa
    usando ponteiros.(utilize o comando return).
    O vetor deve ser declarado como variavel LOCAL na funcao main().

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y*/
#ifdef ex4
 char vet[] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};
 char *p = vet;

    int procuraLetra(char achouletra, char *p){
        for(int i=0;i<sizeof(p);i++){
            if(p[i] == achouletra){
                return 1;
            }
        }
        return 0;
    }

    void main(){
        char letra;
        char continuar;

        char *pletra = &letra;
        do{
        printf("\nDigite a letra para procurar no vetor: ");
        scanf("%c", &letra);
        getchar();


        int achouletra = procuraLetra(*pletra,*p);

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
#endif // ex4

/*5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos como variavel LOCAL na funcao main(). Receba os 4 registros
    sequencialmente pelo teclado numa funcao e imprima todos os registros no
    video em outra funcao. Faca um menu. Utilize ponteiros nas funcoes.
    Coloque no menu a opcao de sair tambem. Utilize o comando switch.
    (vetor de estruturas)
     estutura: nome, end, cidade, estado, cep
*/

#ifdef ex5
typedef struct estrutura{
    char nome[20];
    char end[30];
    char cidade[30];
    char estado[20];
    char cep[10];
}estrutura;

    void receberDados(estrutura *p){
        printf("Digite o nome: ");
        gets(p->nome);
        printf("Digite o endereco: ");
        gets(p->end);
        printf("Digite o cidade: ");
        gets(p->cidade);
        printf("Digite o estado: ");
        gets(p->estado);
        printf("Digite o Cep: ");
        gets(p->cep);
    }

    void mostrarDados(estrutura *p){
        printf("Nome: %s | Endereço: %s | Cidade: %s | Estado: %s | CEP: %s", p->nome,p->end,p->cidade,p->estado,p->cep);
    }

void main(){
    int escolha;
    char continuar;
    estrutura est;
    estrutura *p = &est;
    do{
    printf("Digite 1 para inserir os dados e 2 para mostrar os dados inseridos");
    scanf("%d", &escolha);
    getchar();
    if(escolha == 1){
        receberDados(p);
    }
    else if(escolha == 2){
        mostrarDados(p);
    }
    else{
        printf("Opcao invalida");
    }
     printf("\nDeseja continuar?(s/n)\n");
    scanf("%c", &continuar);
    getchar();
    if(continuar != 's' && continuar != 'n'){
        printf("Desculpe, nao entendi o que digitou. Digite 's' para continuar e 'n' para encerrar\n");
    }
    }while(continuar=='s');
}

#endif // ex5

/*6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
    exclui um registro sempre usando ponteiros.
*/
#ifdef ex6
typedef struct estrutura{
    char nome[20];
    char end[30];
    char cidade[30];
    char estado[20];
    char cep[10];
}estrutura;

    void receberDados(estrutura *p){
        printf("Digite o nome: ");
        gets(p->nome);
        printf("Digite o endereco: ");
        gets(p->end);
        printf("Digite o cidade: ");
        gets(p->cidade);
        printf("Digite o estado: ");
        gets(p->estado);
        printf("Digite o Cep: ");
        gets(p->cep);
    }

    void mostrarDados(estrutura *p){
        printf("Nome: %s | Endereço: %s | Cidade: %s | Estado: %s | CEP: %s\n", p->nome,p->end,p->cidade,p->estado,p->cep);
    }

    void alterarDados(estrutura *p){
        printf("Digite o nome: ");
        gets(p->nome);
        printf("Digite o endereco: ");
        gets(p->end);
        printf("Digite o cidade: ");
        gets(p->cidade);
        printf("Digite o estado: ");
        gets(p->estado);
        printf("Digite o Cep: ");
        gets(p->cep);
    }

    void excluirDados(estrutura *p){
        p->nome[0] = '\0';
        p->end[0] = '\0';
        p->cidade[0] = '\0';
        p->estado[0] = '\0';
        p->cep[0] = '\0';
    }

void main(){
    int escolha;
    int x = 0;
    char continuar;
    estrutura est;
    estrutura *p = &est;
    do{
    do{
    printf("Digite 1 para inserir os dados\n");
    printf("Digite 2 para mostrar os dados\n");
    printf("Digite 3 para alterar os dados\n");
    printf("Digite 4 para excluir os dados\n");
    printf("Digite 5 para encerrar o gerenciamento\n");
    printf("Escolha: ");
    scanf("%d", &escolha);
    getchar();

    switch(escolha){
        case 1:
            receberDados(p);
            break;
        case 2:
            mostrarDados(p);
            break;
        case 3:
            alterarDados(p);
            break;
        case 4:
            excluirDados(p);
            break;
        case 5:
            x=1;
            break;
        default:
        printf("Opcao invalida");
    }
    }while(x==0);
    printf("\nDeseja continuar?(s/n)\n");
    scanf("%c", &continuar);
    getchar();
    if(continuar != 's' && continuar != 'n'){
        printf("Desculpe, nao entendi o que digitou. Digite 's' para continuar e 'n' para encerrar\n");
    }
    }while(continuar=='s');
}
#endif // ex6

