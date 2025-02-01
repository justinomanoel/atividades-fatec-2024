#include <stdio.h>
#include <locale.h>

#define ex2

#ifdef ex1
/*
1 - Escreva um programa para criar e abrir um arquivo texto de nome "arq.txt".
    Receba via teclado diversos caracteres (um por vezes) e escreva-os
    nesse arquivo. O caracter '0' finaliza a entrada de dados. Abra o arquivo
    "arq.txt", leia e imprima na tela todos os caracteres armazenados no
    arquivo (um por vezes).
*/
int main() {
    setlocale(LC_ALL, "");

    FILE *arq;
    char letra;

    arq = fopen("arq.txt", "w");

    if (!arq) {
        printf("\nErro ao abrir o arquivo.");
        return 0;
    }

    do {
        printf("\nDigite um caractere para adicionar ao arquivo (digite '0' para sair): ");
        scanf("%c", &letra);
        getchar();

        if (letra != '0') {
            fwrite(&letra, sizeof(char), 1, arq);
        }
    } while (letra != '0');

    fclose(arq);

    arq = fopen("arq.txt", "r");
    if (!arq) {
        printf("\nErro ao abrir o arquivo.");
        return 1;
    }

    printf("\nCaracteres armazenados no arquivo: ");
    while (fread(&letra, sizeof(char), 1, arq) == 1) {
        printf("%c", letra);
    }

    fclose(arq);
}
#endif // ex1


#ifdef ex2
/*
2 - Escreva um programa para gerenciar uma agenda de contatos. Para cada contato
    armazene o nome, o telefone e o aniversario (dia e mes) em uma estrutura de
    dados. Utilize um vetor de estrutura de 4 elementos como variavel LOCAL na
    funcao main(). Utilize ponteiros para passar o vetor de estrutura para
    as funcoes. Sempre que o programa for encerrado, os contatos devem ser
    escritos no arquivo e quando o programa iniciar os contatos devem ser lidos
    do arquivo.
    O programa deve ter as seguintes opcoes:(cada opcao do menu e' um funcao)
    1 - inserir contato
    2 - listar todos os contatos
    3 - pesquisar um contato pelo nome
    4 - listar os contatos cujo nome inicia com uma letra digitada
    5 - imprimir os aniversariantes do mês.
    6 - altera contato
    7 - exclui contato
    8 - saida
*/

typedef struct Agenda {
    char nome[20];
    char telefone[12];
    char aniversario[6];
} Agenda;

void inserirContato(Agenda *pAgenda) {
    FILE *arq;

    arq = fopen("contatos.txt", "a");

    if (!arq) {
        printf("\nErro ao abrir o arquivo.");
        exit(0);
    }

    printf("\nDigite o nome do contato que deseja adicionar: ");
    gets(pAgenda->nome);
    printf("Digite o numero de telefone do contato que deseja adicionar (DD+9digitos): ");
    gets(pAgenda->telefone);
    printf("Digite o aniversario do contato que deseja adicionar (DD/MM): ");
    gets(pAgenda->aniversario);

    fwrite(pAgenda, sizeof(Agenda), 1, arq);

    fclose(arq);
}

void listarContatos(Agenda *pAgenda) {
    FILE *arq;

    arq = fopen("contatos.txt", "r");

    if (!arq) {
        printf("\nErro ao abrir o arquivo.");
        exit(0);
    }

    if (fread(pAgenda, sizeof(Agenda), 1, arq)){
        printf("\n*** Contatos ***");
            do {
            if(pAgenda->nome[0] != '\0') {
                printf("\n--------------------------------------------------------------");
                printf("\nNome: %s", pAgenda->nome);
                printf("\nTelefone: %s", pAgenda->telefone);
                printf("\nAniversario: %s", pAgenda->aniversario);
            }
        } while(fread(pAgenda, sizeof(Agenda), 1, arq));
    }

    printf("\n--------------------------------------------------------------");

    fclose(arq);
}

int pesquisarContato(Agenda *pAgenda) {
    int encontrou = 0;
    char nomeProcurado[50];

    FILE *arq;

    arq = fopen("contatos.txt", "r");

    if (!arq) {
        printf("\nErro ao abrir arquivo.");
        fclose(arq);
        exit(0);
    }

    printf("\nInforme o nome do contato que deseja procurar: ");
    gets(nomeProcurado);

    while(fread(pAgenda, sizeof(Agenda), 1, arq) == 1){
        for (int i = 0; i < 20; i++) {
            if (pAgenda->nome[i] != nomeProcurado[i]) {
                break;
            }

            if (pAgenda->nome[i] == '\0') {
                encontrou = 1;
                break;
            }
        }

        if (encontrou != 0) break;
    }

    fclose(arq);

    return encontrou;
}

int pesquisarPelaInicial(Agenda *pAgenda) {
    int encontrou = 0;
    char letraProcurada;

    FILE *arq;

    arq = fopen("contatos.txt", "r");

    if (!arq) {
        printf("\nErro ao abrir arquivo.");
        fclose(arq);
        exit(0);
    }

    printf("\nInforme a inicial do contato que deseja procurar: ");
    scanf("%c", &letraProcurada);

    printf("\nContatos com a letra '%c':", letraProcurada);
    for (int i = 0; i < sizeof(pAgenda); i++) {
        if (pAgenda[i].nome[i] == letraProcurada) {
            printf("\n--------------------------------------------------------------");
            printf("\nNome: %s", pAgenda->nome);
            printf("\nTelefone: %s", pAgenda->telefone);
            printf("\nAniversario: %s", pAgenda->aniversario);
            printf("\n--------------------------------------------------------------");
        }
    }

    fclose(arq);
}

int imprimirAniversariantes(Agenda *pAgenda) {
    int encontrou = 0;
    char dataProcurada[6];

    FILE *arq;

    printf("\nDigite a data que deseja pesquisar (DD/MM): ");
    gets(dataProcurada);

    arq = fopen("contatos.txt", "r");

    if (!arq) {
        printf("\nErro ao abrir arquivo.");
        fclose(arq);
        exit(0);
    }

    while(fread(pAgenda, sizeof(Agenda), 1, arq) == 1){
        for (int i = 0; i < 6; i++) {
            if (pAgenda->aniversario[i] != dataProcurada[i]) {
                break;
            }

            if (pAgenda->aniversario[i] == '\0') {
                encontrou = 1;
                break;
            }
        }

        if (encontrou != 0) break;
    }

    return encontrou;

    fclose(arq);
}

void alterarContato(Agenda *pAgenda) {
    int nposicao;
    char nomeProcurado[20];

    int contatoEncontrado = pesquisarContato(pAgenda);

    if(!contatoEncontrado){
        printf("\nContato nao encontrado!");
    } else {
        printf("\nInforme o nome do novo contato: ");
        gets(pAgenda->nome);
        printf("Telefone: ");
        gets(pAgenda->telefone);
        printf("Aniversario (DD/MM): ");
        gets(pAgenda->aniversario);
        getchar();

        FILE *arq;

        arq = fopen("contatos.txt", "r+");

        if(!arq){
            printf("\nErro ao abrir o arquivo.");
            exit(0);
        }

        nposicao = contatoEncontrado * sizeof(Agenda);
        fseek(arq, nposicao, 0);

        fwrite(pAgenda, sizeof(Agenda), 1, arq);
        fclose(arq);

    }
}

void excluirContato(Agenda *pAgenda) {
    int nposicao;
    char nomeProcurado[20];

    int contatoEncontrado = pesquisarContato(pAgenda);

    if(!contatoEncontrado){
        printf("\nContato nao encontrado!");
    } else {
        pAgenda->nome[0] = '\0';

        FILE *arq;

        arq = fopen("contatos.txt", "r+");

        if(!arq){
            printf("\nErro ao abrir o arquivo.");
            exit(0);
        }

        nposicao = contatoEncontrado * sizeof(Agenda);
        fseek(arq, nposicao, 0);

        fwrite(pAgenda, sizeof(Agenda), 1, arq);
        fclose(arq);
    }


}

int main() {
    setlocale(LC_ALL, "");
    Agenda agenda[4];
    Agenda *pAgenda = &agenda;

    FILE *arq;
    int opcao;

    arq = fopen("contatos.txt", "wr");

    do {
        printf("\nSelecione a opção desejada: ");
        printf("\n1- Adicionar contato");
        printf("\n2- Listar contatos");
        printf("\n3- Pesquisar contato");
        printf("\n4- Pesquisar contato pela inicial");
        printf("\n5- Imprimir Aniversariantes");
        printf("\n6- Alterar Contato");
        printf("\n7- Excluir contato");
        printf("\n8- Sair");
        printf("\nOpção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                inserirContato(pAgenda);
                break;
            case 2:
                listarContatos(pAgenda);
                break;
            case 3: ;
                int encontrouContato = pesquisarContato(pAgenda);

                if (encontrouContato) {
                    printf("\n--------------------------------------------------------------");
                    printf("\nNome: %s", pAgenda->nome);
                    printf("\nTelefone: %s", pAgenda->telefone);
                    printf("\nAniversario: %s", pAgenda->aniversario);
                    printf("\n--------------------------------------------------------------");
                } else {
                    printf("\nContato não encontrado.\n");
                }
                break;
            case 4:
                pesquisarPelaInicial(pAgenda);
                break;
            case 5: ;
                int encontrouData = imprimirAniversariantes(pAgenda);

                if (encontrouData) {
                    printf("\n--------------------------------------------------------------");
                    printf("\nNome: %s", pAgenda->nome);
                    printf("\nTelefone: %s", pAgenda->telefone);
                    printf("\nAniversario: %s", pAgenda->aniversario);
                    printf("\n--------------------------------------------------------------");
                } else {
                    printf("\nContato não encontrado.\n");
                }
                break;
            case 6:
                alterarContato(pAgenda);
                break;
            case 7:
                excluirContato(pAgenda);
                break;
            case 8:
                printf("\n*** Agradecemos pela preferência, até breve! ***");
                break;
            default:
                printf("\nOpção inválida, tente novamente");
        }
    } while(opcao != 8);
}
#endif // ex2

#ifdef ex3
typedef struct cliente{
    char nome[30];
    char email[30];
    char celular[15];
} cliente;

void cadastrar(cliente *pa);
void listar(cliente *pa);
int listarNome(cliente *pa);
void alterar(cliente *pa);
void excluir(cliente *pa);


int main(){
    setlocale(LC_ALL, "Portuguese");
    int e;
    int x = 1;
    int buscar;
    static cliente clien;
    cliente *pp = &clien;

    do{
        printf("\nEscolha o que deseja fazer:\n");
        printf("1 - Cadastre.\n");
        printf("2 - Listar.\n");
        printf("3 - Procurar.\n");
        printf("4 - Alterar.\n");
        printf("5 - Excluir.\n");
        printf("6 - Fechar programa.\n");
        printf("Escolha: ");
        scanf("%d", &e);
        getchar();

        if(e == 1){
            cadastrar(pp);
        }
        else if(e == 2){
            listar(pp);
        }
        else if(e == 3){
            buscar = listarNome(pp);
                if(buscar != 0){
                    printf("Cliente encontrado: Nome:%s - Email: %s - Celular: %s.\n", pp->nome, pp->email, pp->celular);
                } else {
                    printf("Cliente não encontrado\n");
                }
        }
        else if(e == 4){
            alterar(pp);
        }
       else if(e == 5){
            excluir(pp);
       }
        else if(e == 6){
            x = 0;
            exit(0);
        }
        else{
            printf("Esta opção não existe.\n");
        }


    }while(x == 1);

}
#endif // ex3

#ifdef ex4
typedef struct produto{
    int codigo;
    char nome[30];
    int atual;
} produto;

void cadastrar(produto *pa);
void listar(produto *pa);
int listarNome(produto *pa);
void listarNada(produto *pa);
void alterarAtual(produto *pa);
void alterarProduto(produto *pa);
void excluir(produto *pa);

int main(){
    setlocale(LC_ALL, "Portuguese");
    int e;
    int x = 1;
    int buscar;
    static produto prod;
    produto *pp = &prod;

    do{
        printf("\nEscolha o que deseja fazer:\n");
        printf("1 - Cadastre produto.\n");
        printf("2 - Listar produtos.\n");
        printf("3 - Listar produto pelo nome.\n");
        printf("4 - Listar produtos em falta.\n");
        printf("5 - Alterar estoque atual.\n");
        printf("6 - Alterar produto.\n");
        printf("7 - Excluir produto.\n");
        printf("8 - Fechar programa.\n");
        printf("Escolha: ");
        scanf("%d", &e);
        getchar();

        if(e == 1){
            cadastrar(pp);
        }
        else if(e == 2){
            listar(pp);
        }
        else if(e == 3){
            buscar = listarNome(pp);
                if(buscar != 0){
                    printf("Produto encontrado: Cod:%d - %s - %d em estoque.\n", pp->codigo, pp->nome, pp->atual);
                } else {
                    printf("Produto não encontrado\n");
                }
        }
        else if(e == 4){
            listarNada(pp);
        }
       else if(e == 5){
            alterarAtual(pp);
       }
        else if(e == 6){
            alterarProduto(pp);
        }
        else if(e == 7){
            excluir(pp);
        }
        else if(e == 8){
            x = 0;
            exit(0);
        }
        else{
            printf("Esta opção não existe.\n");
        }


    }while(x == 1);

}


void cadastrar(produto *pa){

    FILE *arq;

    if((arq = fopen("ex4cap10.txt", "a")) == NULL){
        printf("\nErro ao abrir o arquivo.");
        exit(0);
    }

    printf("Digite os dados do novo produto:\n");
    printf("Digite o codigo do produto: ");
    scanf("%d", &(pa->codigo));
    getchar();
    printf("Nome: ");
    gets(pa->nome);
    printf("Quantidade em estoque: ");
    scanf("%d", &(pa->atual));

    fwrite(pa, sizeof(produto), 1 , arq);

    fclose(arq);

}

void listar(produto *pa){

   FILE *arq;

    if((arq = fopen("ex4cap10.txt", "r")) == NULL){
        printf("\nErro ao abrir o arquivo.");
        exit(0);
    }

    if(fread(pa, sizeof(produto), 1, arq) == 1){
        printf("Produtos:\n");
        do {
            if(pa->nome[0] != '\0'){
                printf("Cod:%d - %s - %d em estoque.\n", pa->codigo, pa->nome, pa->atual);
            }

        } while(fread(pa, sizeof(produto), 1, arq) == 1);

    }

    fclose(arq);
}

int listarNome(produto *pa){

    int buscar = 0;
    int cont = 0;
    char nome[30];

    FILE *arq;

    if((arq = fopen("ex4cap10.txt", "r")) == NULL){
        printf("\nErro ao abrir o arquivo.");
        exit(0);
    }

    printf("\nProcure o produto pelo nome: ");
    gets(nome);
    while(fread(pa, sizeof(produto), 1, arq) == 1){
        for(int i = 0; i <= 30; i++ ){
            if(pa->nome[i] != nome[i]){
                break;
            }
            if(pa->nome[i] == '\0'){
                buscar = cont;
                break;
            }
        }
        if(buscar != 0){
            break;
        }
        cont++;
    }

    fclose(arq);

    return buscar;

}

void listarNada(produto *pa){

    int buscar = 0;
    int i;
    int cont = 0;
    int atual;


    FILE *arq;

    if((arq = fopen("desafioponteiro.txt", "r")) == NULL){
        printf("\nErro ao abrir o arquivo.");
        exit(0);
    }

    printf("\nProdutos zerados:\n");

    while(fread(pa, sizeof(produto), 1, arq) == 1){
        if(pa->atual == 0){
            printf("Cod: %d - %s - %d em estoque.\n", pa->codigo, pa->nome, pa->atual);
            }
        }
    fclose(arq);
}

void alterarAtual(produto *pa) {
    int nposicao;
    printf("Primeiro você pesquisar escolher o produto que deseja alterar.\n");
    int posicao = listarNome(pa);
    if(posicao == 0){
        printf("produto não encontrado!\n");
    }
    if(posicao > 0){

        int movimentacao;
        int valor = 0;
        do{
        printf("\nEscolha a opção desejada:\n");
        printf("1 - Adicionar unidades.\n");
        printf("2 - Remover unidades.\n");
        printf("Digite: ");
        scanf("%d", &movimentacao);
        if(movimentacao != 1 && movimentacao !=2){
            printf("Escolha uma das duas opçoes!\n");
        }
        }while(movimentacao != 1 && movimentacao !=2);

       if(movimentacao == 1){
                printf("Digite a quantidade de exemplares: \n");
                scanf("%d", &valor);
                pa->atual = pa->atual + valor;
       }
       if(movimentacao == 2){
                printf("Digite a quantidade de exemplares: \n");
                scanf("%d", &valor);
                pa->atual = pa->atual - valor;
                if(pa->atual < 0){
                    pa->atual = 0;
                }
       }

            FILE *arq;

            if((arq = fopen("ex4cap10.txt", "r+")) == NULL){
                printf("\nErro ao abrir o arquivo.");
                exit(0);
            }

            nposicao = posicao * sizeof(produto); //forma de posicionar o ponteiro que está no CAP10
            fseek(arq, nposicao, 0);
            fwrite(pa, sizeof(produto), 1, arq);
            fclose(arq);
    }
}


void alterarProduto(produto *pa){
    int nposicao;
    printf("Primeiro você pesquisar escolher o produto que deseja alterar.\n");
    int posicao = listarNome(pa);
    if(posicao == 0){
        printf("Produto não encontrado!\n");
    }
    if(posicao > 0){
        printf("Digite os novos dados do filme:\n");
        printf("Digite o codigo do produto: ");
    scanf("%d", &(pa->codigo));
    getchar();
    printf("Nome: ");
    gets(pa->nome);
    printf("Quantidade em estoque: ");
    scanf("%d", &(pa->atual));

        FILE *arq;

        if((arq = fopen("ex4cap10.txt", "r+")) == NULL){
            printf("\nErro ao abrir o arquivo.");
            exit(0);
        }

        nposicao = posicao * sizeof(produto);
        fseek(arq, nposicao, 0);

        fwrite(pa, sizeof(produto), 1, arq);
        fclose(arq);

    }
}

void excluir(produto *pa){
    int nposicao;
    printf("Primeiro você pesquisar escolher o produto que deseja excluir.\n");
    int posicao = listarNome(pa);
    if(posicao == 0){
        printf("Produto não encontrado!\n");
    }
    if(posicao > 0){

        pa->nome[0] = '\0';

        FILE *arq;

        if((arq = fopen("ex4cap10.txt", "r+")) == NULL){
            printf("\nErro ao abrir o arquivo.");
            exit(0);
        }

        nposicao = posicao * sizeof(produto);
        fseek(arq, nposicao, 0);

        fwrite(pa, sizeof(produto), 1, arq);
        fclose(arq);
    }
}
#endif // ex4

