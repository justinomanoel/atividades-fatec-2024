#include <stdio.h>
#include <locale.h>

#define desafio

#ifdef desafio

    char filme1[20];
    char filme2[20];
    char filme3[20];

    int quant1;
    int quant2;
    int quant3;

void inserirFilmes(){

    FILE *arq;

    printf("Digite o título do primeiro filme:\n");
    gets(filme1);
    printf("Digite a quantidade desse filme disponível:\n");
    scanf("%d", &quant1);
    getchar();

    printf("Digite o título do segundo filme:\n");
    gets(filme2);
    printf("Digite a quantidade desse filme disponível:\n");
    scanf("%d", &quant2);
    getchar();

    printf("Digite o título do terceiro filme:\n");
    gets(filme3);
    printf("Digite a quantidade desse filme disponível:\n");
    scanf("%d", &quant3);
    getchar();

    arq = fopen("desafioRui.txt", "w");

    fwrite(filme1, sizeof(filme1), 1, arq);
    fwrite(filme2, sizeof(filme2), 1, arq);
    fwrite(filme3, sizeof(filme3), 1, arq);
    fwrite(&quant1, sizeof(quant1), 1, arq);
    fwrite(&quant2, sizeof(quant2), 1, arq);
    fwrite(&quant3, sizeof(quant3), 1, arq);

    fclose(arq);
}

void listarFilmes(){

    FILE *arq;

    arq = fopen("desafioRui.txt", "r");

    fread(filme1, sizeof(filme1), 1, arq);
    fread(filme2, sizeof(filme2), 1, arq);
    fread(filme3, sizeof(filme3), 1, arq);
    fread(&quant1, sizeof(quant1), 1, arq);
    fread(&quant2, sizeof(quant2), 1, arq);
    fread(&quant3, sizeof(quant3), 1, arq);

    fclose(arq);
    printf("Lista de filmes\n%s - %d disponíveis em catálogo.\n%s - %d disponíveis em catálogo.\n%s - %d disponíveis em catálogo.\n",filme1,quant1,filme2,quant2,filme3,quant3);
}

void pesquisaFilmes(){

    char pesquisa[20];
    int encontrou;

    FILE *arq;

    arq = fopen("desafioRui.txt", "r");

    fread(filme1, sizeof(filme1), 1, arq);
    fread(filme2, sizeof(filme2), 1, arq);
    fread(filme3, sizeof(filme3), 1, arq);
    fread(&quant1, sizeof(quant1), 1, arq);
    fread(&quant2, sizeof(quant2), 1, arq);
    fread(&quant3, sizeof(quant3), 1, arq);


    printf("Digite o nome completo do filme.\n");
    gets(pesquisa);

    for (int i=0; filme1!='\0'; i++) {
    if (pesquisa[i] != filme1[i]){
        encontrou = 0;
        break;
    }
    if(pesquisa[i]=='\0'&&filme1[i]=='\0'){
        encontrou = 1;
        break;
    }
    }
    if(encontrou){
        printf("Resultado da pesquisa:\n%s - %d disponíveis em estoque.\n",filme1,quant1);
    }

    for (int i=0; filme2!='\0'; i++) {
    if (pesquisa[i] != filme2[i]){
        encontrou = 0;
        break;
    }
    if(pesquisa[i]=='\0'&&filme2[i]=='\0'){
        encontrou = 1;
        break;
    }
    }
    if(encontrou){
        printf("Resultado da pesquisa:\n%s - %d disponíveis em estoque.\n",filme2,quant2);
    }

    for (int i=0; filme3!='\0'; i++) {
    if (pesquisa[i] != filme3[i]){
        encontrou = 0;
        break;
    }
    if(pesquisa[i]=='\0'&&filme3[i]=='\0'){
        encontrou = 1;
        break;
    }
    }
    if(encontrou){
        printf("Resultado da pesquisa:\n%s - %d disponíveis em estoque.\n",filme3,quant3);
    }


    fclose(arq);
}

void inicialFilmes(){

    FILE *arq;

    arq = fopen("desafioRui.txt", "r");

    fread(filme1, sizeof(filme1), 1, arq);
    fread(filme2, sizeof(filme2), 1, arq);
    fread(filme3, sizeof(filme3), 1, arq);
    fread(&quant1, sizeof(quant1), 1, arq);
    fread(&quant2, sizeof(quant2), 1, arq);
    fread(&quant3, sizeof(quant3), 1, arq);


    printf("Digite a primeira letra do filme.\n");
    char letra = getchar();

    if(letra == filme1[0]){
        printf("Resultado da pesquisa:\n%s - %d disponíveis em estoque.\n",filme1,quant1);
    }
    if(letra == filme2[0]){
        printf("%s - %d disponíveis em estoque.\n",filme2,quant2);
    }
    if(letra == filme3[0]){
        printf("%s - %d disponíveis em estoque.\n",filme3,quant3);
    }
}


void alteraFilmes(){

    char pesquisa[20];
    int encontrou = 0;
    int escolha;
    int i;
    FILE *arq;

    arq = fopen("desafioRui.txt", "r");

    fread(filme1, sizeof(filme1), 1, arq);
    fread(filme2, sizeof(filme2), 1, arq);
    fread(filme3, sizeof(filme3), 1, arq);
    fread(&quant1, sizeof(quant1), 1, arq);
    fread(&quant2, sizeof(quant2), 1, arq);
    fread(&quant3, sizeof(quant3), 1, arq);

    fclose(arq);

    printf("Digite o nome completo do filme que deseja alterar.\n");
    gets(pesquisa);

    arq = fopen("desafioRui.txt", "w");

    for (int i=0; filme1!='\0'; i++) {
    if (pesquisa[i] != filme1[i]){
        encontrou = 0;
        break;
    }
    if(pesquisa[i]=='\0'&&filme1[i]=='\0'){
        encontrou = 1;
        break;
    }
    }
    if(encontrou){
        printf("Resultado da pesquisa:\n %s - %d disponíveis em estoque.\n",filme1,quant1);



        printf("Digite o título do filme:\n");
        gets(filme1);
        printf("Digite a quantidade desse filme disponível:\n");
        scanf("%d", &quant1);

        fwrite(filme1, sizeof(filme1), 1, arq);
        fwrite(filme2, sizeof(filme2), 1, arq);
        fwrite(filme3, sizeof(filme3), 1, arq);
        fwrite(&quant1, sizeof(quant1), 1, arq);
        fwrite(&quant2, sizeof(quant2), 1, arq);
        fwrite(&quant3, sizeof(quant3), 1, arq);

        }


    for(int i=0; filme2!='\0'; i++) {
    if (pesquisa[i] != filme2[i]){
        encontrou = 0;
        break;
    }
    if(pesquisa[i]=='\0'&&filme2[i]=='\0'){
        encontrou = 1;
        break;
    }
    }
    if(encontrou){
        printf("Resultado da pesquisa:\n %s - %d disponíveis em estoque.\n",filme2,quant2);

        printf("Digite o título do filme:\n");
        gets(filme2);
        printf("Digite a quantidade desse filme disponível:\n");
        scanf("%d", &quant2);
        getchar();

        fwrite(filme1, sizeof(filme1), 1, arq);
        fwrite(filme2, sizeof(filme2), 1, arq);
        fwrite(filme3, sizeof(filme3), 1, arq);
        fwrite(&quant1, sizeof(quant1), 1, arq);
        fwrite(&quant2, sizeof(quant2), 1, arq);
        fwrite(&quant3, sizeof(quant3), 1, arq);

    }

    for (int i=0; filme3!='\0'; i++) {
    if (pesquisa[i] != filme3[i]){
        encontrou = 0;
        break;
    }
    if(pesquisa[i]=='\0'&&filme3[i]=='\0'){
        encontrou = 1;
        break;
    }
    }
    if(encontrou){
        printf("Resultado da pesquisa:\n %s - %d disponíveis em estoque.\n",filme3,quant3);

        printf("Digite o título do filme:\n");
        gets(filme3);
        printf("Digite a quantidade desse filme disponível:\n");
        scanf("%d", &quant3);
        getchar();

        fwrite(filme1, sizeof(filme1), 1, arq);
        fwrite(filme2, sizeof(filme2), 1, arq);
        fwrite(filme3, sizeof(filme3), 1, arq);
        fwrite(&quant1, sizeof(quant1), 1, arq);
        fwrite(&quant2, sizeof(quant2), 1, arq);
        fwrite(&quant3, sizeof(quant3), 1, arq);

    }
fclose(arq);

}

void excluiFilmes(){
    char pesquisa[20];
    int i=0;
    int encontrou = 0;

    FILE *arq;

    arq = fopen("desafioRui.txt", "r");

    fread(filme1, sizeof(filme1), 1, arq);
    fread(filme2, sizeof(filme2), 1, arq);
    fread(filme3, sizeof(filme3), 1, arq);
    fread(&quant1, sizeof(quant1), 1, arq);
    fread(&quant2, sizeof(quant2), 1, arq);
    fread(&quant3, sizeof(quant3), 1, arq);

    fclose(arq);

    printf("Digite o nome completo do filme que deseja excluir.\n");
    gets(pesquisa);

    arq = fopen("desafioRui.txt", "w");

    for(int i=0; filme1!='\0'; i++) {
    if (pesquisa[i] != filme1[i]){
        encontrou = 0;
        break;
    }
    if(pesquisa[i]=='\0'&&filme1[i]=='\0'){
        encontrou = 1;
        break;
    }
    }
        if(encontrou == 1){
            filme1[0] = '\0';
            quant1 = 0;
    fwrite(filme1, sizeof(filme1), 1, arq);
    fwrite(filme2, sizeof(filme2), 1, arq);
    fwrite(filme3, sizeof(filme3), 1, arq);
    fwrite(&quant1, sizeof(quant1), 1, arq);
    fwrite(&quant2, sizeof(quant2), 1, arq);
    fwrite(&quant3, sizeof(quant3), 1, arq);
        }

        for(int i=0; filme2!='\0'; i++) {
    if (pesquisa[i] != filme2[i]){
        encontrou = 0;
        break;
    }
    if(pesquisa[i]=='\0'&&filme2[i]=='\0'){
        encontrou = 1;
        break;
    }
    }
        if(encontrou == 1){
            filme2[0] = '\0';
            quant2 = 0;
    fwrite(filme1, sizeof(filme1), 1, arq);
    fwrite(filme2, sizeof(filme2), 1, arq);
    fwrite(filme3, sizeof(filme3), 1, arq);
    fwrite(&quant1, sizeof(quant1), 1, arq);
    fwrite(&quant2, sizeof(quant2), 1, arq);
    fwrite(&quant3, sizeof(quant3), 1, arq);
        }

        for(int i=0; filme3!='\0'; i++) {
    if (pesquisa[i] != filme3[i]){
        encontrou = 0;
        break;
    }
    if(pesquisa[i]=='\0'&&filme3[i]=='\0'){
        encontrou = 1;
        break;
    }
    }
        if(encontrou == 1){
            filme3[0] = '\0';
            quant3 = 0;
    fwrite(filme1, sizeof(filme1), 1, arq);
    fwrite(filme2, sizeof(filme2), 1, arq);
    fwrite(filme3, sizeof(filme3), 1, arq);
    fwrite(&quant1, sizeof(quant1), 1, arq);
    fwrite(&quant2, sizeof(quant2), 1, arq);
    fwrite(&quant3, sizeof(quant3), 1, arq);
        }
fclose(arq);
}


void main(){
    setlocale(LC_ALL, "");
    int menu;
    do{
    printf("Digite o número referente a ação no menu: \n1 - Cadastro de filmes\n2 - Listagem dos filmes\n3 - Pesquise um filme pelo nome completo\n4 - Pesquise um filme pela primeira letra\n5 - Pesquise pelo nome e altere os dados\n6 - Pesquise pelo nome e exclua dos dados\n7 - Saída\n");
    scanf("%d", &menu);
    getchar();


    if(menu == 1){
        inserirFilmes();
    }
    if(menu == 2){
        listarFilmes();
    }
    if(menu == 3){
        pesquisaFilmes();
    }
    if(menu == 4){
        inicialFilmes();
    }
    if(menu == 5){
        alteraFilmes();
    }
    if(menu == 6){
        excluiFilmes();
    }
    if(menu == 7){
        exit(0);
    }
    }while(menu != 7);
}

#endif // desafio
