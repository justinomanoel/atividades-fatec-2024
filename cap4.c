#include<stdio.h>
#include<locale.h>

#define ex1

#ifdef ex1

void main(){
    setlocale(LC_ALL, "");
    int ordem[10];
    int valor;

        int cont = 0;
        int numero;
        do {
            printf("\nDigite um número inteiro:\n");
            scanf("%d", &numero);

            ordem[cont] = numero;
            cont++;
        } while(cont < 10);

        do {

            valor = 0;

            for(int i = 0; i < cont-1; i++) {
                if(ordem[i] > ordem[i+1]) {
                    int temp = ordem[i];
                    ordem[i] = ordem[i+1];
                    ordem[i+1] = temp;
                    valor = 1;
                }
            }
        } while(valor);

        for(int i = 0; i < cont; i++) {
            printf("%d ", ordem[i]);
        }
}
#endif // ex1

#ifdef ex2
int main() {
    setlocale(LC_ALL, "");
    int ints[3];
    long int longs[3];
    unsigned int unsigneds[3];
    float floats[3];
    double doubles[3];

            for(int i = 0; i < 3; i++) {
                printf("Escreva um inteiro:\n");
                scanf("%d", &ints[i]);

                printf("Escreva um numero longo:\n");
                scanf("%ld", &longs[i]);

                printf("Escreva um numero unsigned:\n");
                scanf("%ud", &unsigneds[i]);

                printf("Escreva um numero float:\n");
                scanf("%f", &floats[i]);

                printf("um numero double:\n");
                scanf("%f", &doubles[i]);
            }

        printf("\n        10        20        30        40        50");
        printf("\n12345678901234567890123456789012345678901234567890");
        for(int i = 0; i < 3; i++) {
            printf("\n%5d %20ld %23u", ints[i], longs[i], unsigneds[i]);
            printf("\n%17.2f %20.2f", floats[i], doubles[i]);
        }
}
#endif // ex2

#ifdef ex3

int main() {
    setlocale(LC_ALL, "");

    int numeros[10];
    int par[5];
    int impar[5];

        int contPar = 0;
        int contImpar = 0;

        for(int i = 0; i < 10; i++) {
            printf("Escreva um número inteiro:\n");
            scanf("%d", &numeros[i]);

            if (i % 2 == 0) {
                par[contPar] = numeros[i];
                contPar++;
            }
            if (i % 2 != 0){
                impar[contImpar] = numeros[i];
                contImpar++;
            }
        }

        printf("V = {");
        for(int i = 0; i < 10; i++) {
            printf("%d ", numeros[i]);
        }
        printf("}\n");

        printf("U = {");
        for(int i = 0; i < 5; i++) {
            printf("%d ", impar[i]);
        }
        printf("}\n");

        printf("W = {");
        for(int i = 0; i < 5; i++) {
            printf("%d ", par[i]);
        }
        printf("}\n");

}
#endif // ex3

#ifdef ex4
int main() {
    setlocale(LC_ALL, "");

        int inteiros[10];
        int par[10];
        int impar[10];
        int pares = 0;
        int impares = 0;
        int i;

        for(i = 0; i < 10; i++) {
            printf("Escreva um número inteiro:\n");
            scanf("%d", &inteiros[i]);

            if (inteiros[i] % 2 == 0) {
                par[pares] = inteiros[i];
                pares++;
            }
            if (inteiros[i] % 2 != 0){
                impar[impares] = inteiros[i];
                impares++;
            }
        }

        printf("V = {");
        for(int i = 0; i < 10; i++) {
            printf("%d ", inteiros[i]);
        }
        printf("}\n");

        if (pares > 0) {
            printf("U = {");
            for(int i = 0; i < pares; i++) {
                printf("%d ", par[i]);
            }
        printf("}\n");
        }
        if (impares > 0) {
            printf("W = {");
            for(int i = 0; i < impares; i++) {
                printf("%d ", impar[i]);
            }
        printf("}\n");
        }

}
#endif // ex4

#ifdef ex5
int main() {
    setlocale(LC_ALL, "");
    int v1[2][3];
    int v2[2][3];
    int soma[2][3];
    int i, j;

        for(i = 0; i < 2; i++) {
            for(j = 0; j < 3; j++) {
                printf("Digite um número inteiro:\n");
                scanf("%d", &v1[i][j]);
                printf("Digite outro número inteiro: ");
                scanf("%d", &v2[i][j]);

                soma[i][j] = v1[i][j] + v2[i][j];
            }
        }

        printf("V =");
        for(int i = 0; i < 2; i++) {
            printf(" {");
            for(int j = 0; j < 3; j++) {
                printf("%d ", v1[i][j]);
            }
        }
        printf("}\n");

        printf("U =");
        for(int i = 0; i < 2; i++) {
            printf(" {");
            for(int j = 0; j < 3; j++) {
                printf("%d ", v2[i][j]);
            }
        }
        printf("}\n");

        printf("W =");
        for(int i = 0; i < 2; i++) {
            printf(" {");
            for(int j = 0; j < 3; j++) {
                printf("%d ", soma[i][j]);
            }
        }
}
#endif // ex5
