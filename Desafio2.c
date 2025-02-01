#include <stdio.h>
#include <locale.h>

typedef struct Filme{
    char nome[30];
    int atual;
    float preco;
    char lanc[8];
} Filme;

void cadastrarFilme(Filme *pa);
void listarFilme(Filme *pa);
int listarNome(Filme *pa);
int listarLancamento(Filme *pa);
void listarPreco(Filme *pa);
void alterarQuantidade(Filme *pa);
void alterarPreco(Filme *pa);
void alterarFilme(Filme *pa);
void excluirCadastro(Filme *pa);

int main(){
    setlocale(LC_ALL, "Portuguese");
    int e;
    int x = 1;
    int buscar;
    static Filme catalogo;
    Filme *pf = &catalogo;

    printf("---------------------------------------------------------\n");
    printf("---------Bem-vindo ao sistema Fatecano de filmes---------\n");
    printf("---------------------------------------------------------\n");
    do{
        printf("\nEscolha o que deseja fazer:\n");
        printf("1 - Cadastre um novo filme.\n");
        printf("2 - Lista de todos os filmes em estoque.\n");
        printf("3 - Pesquise um filme pelo nome completo.\n");
        printf("4 - Pesquisar filme pelo lancamento.\n");
        printf("5 - Lista dos filmes por faixa de pre�o.\n");
        printf("6 - Altera quantidade de um filme.\n");
        printf("7 - Altera o preco de um filme.\n");
        printf("8 - Altera as informa��es de um filme.\n");
        printf("9 - Excluir um filme.\n");
        printf("10 - Fechar programa.\n");
        printf("Escolha: ");
        scanf("%d", &e);
        getchar();

        if(e == 1){
            cadastrarFilme(pf);
        }
        else if(e == 2){
            listarFilme(pf);
        }
        else if(e == 3){
            buscar = listarNome(pf);
                if(buscar != 0){
                    printf("Filme encontrado: %s - Lancamento: %s - %.2f reais, %d em estoque.\n", pf->nome, pf->lanc, pf->preco, pf->atual);
                } else {
                    printf("Filme n�o encontrado\n");
                }
        }
        else if(e == 4){
            buscar = listarLancamento(pf);
                if(buscar != 0){
                    printf("Filme encontrado: %s - Lancamento: %s - %.2f reais, %d em estoque.\n", pf->nome, pf->lanc, pf->preco, pf->atual);
                } else {
                    printf("Filme n�o encontrado\n");
                }
        }
        else if(e == 5){
            listarPreco(pf);
        }
        else if(e == 6){
            alterarQuantidade(pf);
       }
        else if(e == 7){
            alterarPreco(pf);
        }
        else if(e == 8){
            alterarFilme(pf);
        }
        else if(e == 9){
            excluirCadastro(pf);
        }
        else if(e == 10){
            x = 0;
            printf("---------------------------------------------------------\n");
            printf("----------------------Volte sempre!----------------------\n");
            printf("---------------------------------------------------------\n");
            exit(0);
        }
        else{
            printf("Esta op��o n�o existe.\n");
        }


    }while(x == 1);

}


void cadastrarFilme(Filme *pa){

    FILE *arq;

    if((arq = fopen("desafioponteiro.txt", "a")) == NULL){
        printf("\nErro ao abrir o arquivo.");
        exit(0);
    }

    printf("Digite os dados do novo filme:\n");
    printf("Nome: ");
    gets(pa->nome);
    printf("Quantidade em estoque: ");
    scanf("%d", &(pa->atual));
    printf("Preco: ");
    scanf("%f", &(pa->preco));
    getchar();
    printf("Lancamento (MM/AAAA): ");
    gets(pa->lanc);

    fwrite(pa, sizeof(Filme), 1 , arq);

    fclose(arq);

}

void listarFilme(Filme *pa){

   FILE *arq;

    if((arq = fopen("desafioponteiro.txt", "r")) == NULL){
        printf("\nErro ao abrir o arquivo.");
        exit(0);
    }

    if(fread(pa, sizeof(Filme), 1, arq) == 1){
        printf("Filmes:\n");
        do {
            if(pa->nome[0] != '\0'){
                printf("%s - %d em estoque com o valor de R$ %.2f cada - Lan�amento: %s.\n", pa->nome, pa->atual, pa->preco, pa->lanc);
            }

        } while(fread(pa, sizeof(Filme), 1, arq) == 1);

    }

    fclose(arq);
}

int listarNome(Filme *pa){

    int buscar = 0;
    int cont = 0;
    char nome[30];

    FILE *arq;

    if((arq = fopen("desafioponteiro.txt", "r")) == NULL){
        printf("\nErro ao abrir o arquivo.");
        exit(0);
    }

    printf("\nProcure o filme pelo nome: ");
    gets(nome);
    while(fread(pa, sizeof(Filme), 1, arq) == 1){
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

int listarLancamento(Filme *pa){

    int buscar = 0;
    int i;
    int cont = 0;
    char lanc[8];


    FILE *arq;

    if((arq = fopen("desafioponteiro.txt", "r")) == NULL){
        printf("\nErro ao abrir o arquivo.");
        exit(0);
    }

    printf("\nProcure o filme pelo lan�amento (formato mm/aaaa): ");
    gets(lanc);

    while(fread(pa, sizeof(Filme), 1, arq) == 1){
        for(i = 0; i < 30; i++ ){
            if(pa->lanc[i] != lanc[i]){
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

void listarPreco(Filme *pa){

    FILE *arq;
    float maximo;
    float minimo;
    int a;
    int buscar = 0;

    do{
    printf("\nPesquise o filme pelo pre�o - Digite a op��o desejada:\n");
    printf("1 - Entre R$ 00,00 e R$ 50,00.\n");
    printf("2 - Entre R$ 50,01 e R$ 75,00.\n");
    printf("3 - Entre R$ 75,01 e R$ 100,00.\n");
    printf("4 - Entre R$ 100,01 e R$ 1000,00.\n");
    printf("5 - Digite valores personalizados.\n");
    scanf("%d", &a);
    if(a == 1){
        maximo = 50;
        minimo = 0;
    }
    else if(a == 2){
        maximo = 75;
        minimo = 50.01;
    }
    else if(a == 3){
        maximo = 100;
        minimo = 75.01;
    }
    else if(a == 4){
        maximo = 1000;
        minimo = 100.01;
    }
    else if(a == 5){
        printf("Digite o valor m�nimo: ");
        scanf("%f", &minimo);
        printf("Digite o valor m�ximo: ");
        scanf("%f", &maximo);
        getchar();
    }
    else{
        printf("Escolha uma op��o v�lida!\n");
    }
    }while(a < 1 || a > 5);


    if((arq = fopen("desafioponteiro.txt", "r")) == NULL){
        printf("\nErro ao abrir o arquivo.");
        exit(0);
    }
    printf("\nFilmes pela faixa de pre�o:\n");
    while(fread(pa, sizeof(Filme), 1, arq) == 1){
        if(pa->preco <= maximo && pa->preco >= minimo){
            if(pa->nome[0] != '?'){
                printf("%s - Lancamento: %s - %.2f reais, %d em estoque.\n", pa->nome, pa->lanc, pa->preco, pa->atual);
            }
        }
    }
    fclose(arq);

}

void alterarQuantidade(Filme *pa) {
    int nposicao;
    printf("Primeiro voc� pesquisar escolher o filme que deseja alterar.\n");
    int posicao = listarNome(pa);
    if(posicao = 0){
        printf("Filme n�o encontrado!\n");
    }
    if(posicao > 0){

        int movimentacao;
        int valor = 0;
        do{
        printf("\nEscolha a op��o desejada:\n");
        printf("1 - Adicionar exemplares.\n");
        printf("2 - Remover exemplares.\n");
        printf("Digite: ");
        scanf("%d", &movimentacao);
        if(movimentacao != 1 && movimentacao !=2){
            printf("Escolha uma das duas op�oes!\n");
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

            if((arq = fopen("desafioponteiro.txt", "r+")) == NULL){
                printf("\nErro ao abrir o arquivo.");
                exit(0);
            }

            nposicao = posicao * sizeof(Filme); //forma de posicionar o ponteiro que est� no CAP10
            fseek(arq, nposicao, 0);
            fwrite(pa, sizeof(Filme), 1, arq);
            fclose(arq);
    }
}

void alterarPreco(Filme *pa){
    int nposicao;
    printf("Primeiro voc� pesquisar escolher o filme que deseja alterar.\n");
    int posicao = listarNome(pa);
    if(posicao == 0){
        printf("Filme n�o encontrado!\n");
    }
    if(posicao > 0){
        FILE *arq;
        printf("Digite o valor atualizado do filme: \n");
        scanf("%f", &(pa->preco));

        if((arq = fopen("desafioponteiro.txt", "r+")) == NULL){
            printf("\nErro ao abrir o arquivo.");
            exit(0);
        }

        nposicao = posicao * sizeof(Filme);
        fseek(arq, nposicao, 0);

        fwrite(pa, sizeof(Filme), 1, arq);
        fclose(arq);

    }
}

void alterarFilme(Filme *pa){
    int nposicao;
    printf("Primeiro voc� pesquisar escolher o filme que deseja alterar.\n");
    int posicao = listarNome(pa);
    if(posicao == 0){
        printf("Filme n�o encontrado!\n");
    }
    if(posicao > 0){
        printf("Digite os novos dados do filme:\n");
        printf("Nome: ");
        gets(pa->nome);
        printf("Quantidade em estoque: ");
        scanf("%d", &(pa->atual));
        printf("Preco: ");
        scanf("%f", &(pa->preco));
        getchar();
        printf("Lancamento (MM/AAAA): ");
        gets(pa->lanc);

        FILE *arq;

        if((arq = fopen("desafioponteiro.txt", "r+")) == NULL){
            printf("\nErro ao abrir o arquivo.");
            exit(0);
        }

        nposicao = posicao * sizeof(Filme);
        fseek(arq, nposicao, 0);

        fwrite(pa, sizeof(Filme), 1, arq);
        fclose(arq);

    }
}

void excluirCadastro(Filme *pa){
    int nposicao;
    printf("Primeiro voc� pesquisar escolher o filme que deseja excluir.\n");
    int posicao = listarNome(pa);
    if(posicao == 0){
        printf("Filme n�o encontrado!\n");
    }
    if(posicao > 0){

        pa->nome[0] = '\0';

        FILE *arq;

        if((arq = fopen("desafioponteiro.txt", "r+")) == NULL){
            printf("\nErro ao abrir o arquivo.");
            exit(0);
        }

        nposicao = posicao * sizeof(Filme);
        fseek(arq, nposicao, 0);

        fwrite(pa, sizeof(Filme), 1, arq);
        fclose(arq);
    }
}





