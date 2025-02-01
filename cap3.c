#include <stdio.h>
#include <locale.h>
#define ex4

#ifdef ex1
int main() {
    setlocale(LC_ALL, "");
    int numero, resultado;

        do{
        printf("Digite um número entre 0 e 6\n");
        scanf("%d", &numero);

        if (numero > 6 || numero < 0) {
            printf("Inválido");
        }
        }while(numero > 6 || numero < 0);

        resultado = somar(numero);

        printf("A soma dos algarismos de %d! é: %d\n", numero, resultado);

}


int somar(int n) {
    int n1, n2, n3;
    int fator = 1;
    int soma = 0;

    for (int i = 1; i <= n; i++) {
        fator *= i;
    }

    if (fator < 10) {
        n1 = fator;
        n2 = 0;
        n3 = 0;
    } else if (fator < 100) {
        n1 = fator / 10;
        n2 = fator - n1 * 10;
        n3 = 0;
    } else if (fator < 1000 ) {
        //321
        n1 = fator / 100;
        n2 = (fator - n1 * 100) / 10;
        n3 = fator - n1 * 100 - n2 * 10;
    }

    if (n == 0) {
        soma = 1;
    }

    soma = n1 + n2 + n3;
    printf("\n%d! é: %d\n", n, fator);
    return soma;
}
#endif // ex1

#ifdef ex2
int main() {
    setlocale(LC_ALL, "");
    int n1, n2, n3, n4;
    float div = 0;
    int mult = 1;
    int soma = 0;



    do {
        printf("Informe um número\n");
        scanf("%d", &n1);

        printf("Informe outro numero\n");
        scanf("%d", &n2);

        n3 = numero(n1);
        n4 = numero(n2);

        if (n1 == 0 || n2 == 0) {
            printf("Inválido");
            break;
        }
    }while(n1 == 0 || n2 == 0);

        if (n3 > 0 && n4 > 0) {

            if (n1 > n2) {
                for (int i = n2+1; i < n1; i++) {
                    soma += i;
                }
                printf("A soma do intervalo é %d\n",soma);
            } else if (n2 > n1) {
                for (int i = n1+1; i < n2; i++) {
                    soma += i;
                }
                printf("A soma do intervalo é %d\n",soma);
            } else {
                soma = 0;
                printf("Os números são iguais");
            }
        } else if (n3 == 0 && n4 == 0) {

            if (n1 > n2) {
                for (int i = n2+1; i < n1; i++) {
                    mult *= i;
                }
                printf("A multiplicacao do intervalo é %d\n",mult);
            } else if (n2 > n1) {
                for (int i = n1+1; i < n2; i++) {
                    mult *= i;
                }
                printf("A multiplicação do intervalo é %d\n",mult);
            } else {
                soma = 0;
                printf("Os números são iguais\n");
            }
        } else {
            div = n1 / n2;
            printf("A divisão do intervalo é %.2f.\n",div);
        }

}

int numero(int n3) {

    if (n3 > 0) {
        return 1;
    } else if (n3 < 0) {
        return 0;
    } else if (n3 == 0){
        return -1;
    }
}
#endif // ex2

#ifdef ex3
/*
3 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
    uma funcao para cada operacoes aritmeticas e passe como parametro os 2
    valores recebidos na funcao main(). Retorne os resultados usando o comando
    return e imprima os 4 resultados no video na funcao main().
*/

float mult(float a, float b);
float div(float a, float b);
float sub(float a, float b);
float soma(float a, float b);
int main() {
    setlocale(LC_ALL, "");
    float n1, n2, somar, multiplicar, subtrair, dividir;


        printf("Digite um número\n");
        scanf("%f", &n1);

        printf("Digite outro número \n");
        scanf("%f", &n2);

        somar = soma(n1, n2);
        printf("Soma = %.1f\n",somar);

        subtrair = sub(n1, n2);
        printf("Subtração = %.1f\n",subtrair);

        multiplicar = mult(n1, n2);
        printf("Multiplicação = %.1f\n",multiplicar);

        dividir = div(n1, n2);
        printf("Divisão = %.2f\n",dividir);



}



float mult(float n1, float n2) {
    float retorno = n1 * n2;
    return retorno;
}

float div(float n1, float n2) {
    float retorno = n1 / n2;
    return retorno;
}

float sub(float n1, float n2) {
    float retorno = n1 - n2;
    return retorno;
}

float soma(float n1, float n2) {
    float retorno = n1 + n2;
    return retorno;
}
#endif // ex3

#ifdef ex4
/*
Reescreva o programa do exercicio anterior para receber via teclado n
    valores. Os n valores nao sao definidos previamente.
*/
float soma(float a, float b);
float sub(float a, float b);
float mult(float a, float b);
float div(float a, float b);

int main() {
    setlocale(LC_ALL, "");
    float n1, n2, n3, somar, somar2, subtrair, subtrair2, multiplicar, multiplicar2, dividir, dividir2;

    printf("Escreva um número\n");
    scanf("%f", &n1);

    printf("Escreve outro número\n");
    scanf("%f", &n2);

    somar = soma(n1,n2);
    printf("Soma = %.1f\n",somar);

    subtrair = sub(n1,n2);
    printf("Subtração = %.1f\n",subtrair);

    multiplicar = mult(n1,n2);
    printf("Multiplicação = %.1f\n",multiplicar);

    dividir = div(n1, n2);
    printf("Divisão = %.1f\n",dividir);

    do {
        printf("Informe outro número\n");
        scanf("%f", &n3);

        somar2 = somar + n3;
        printf("Soma = %.2f\n",somar2);
        somar = somar2;

        subtrair2 = subtrair - n3;
        printf("Subtração = %.2f\n",subtrair2);
        subtrair = subtrair2;

        multiplicar2 = multiplicar * n3;
        printf("Multiplicação = %.2f\n",multiplicar2);
        multiplicar = multiplicar2;

        dividir2 = dividir / n3;
        printf("Divisão = %.2f\n",dividir2);
        dividir = dividir2;
    } while (n3 != 0);
}

float mult(float n1, float n2) {
    float retorno = n1 * n2;
    return retorno;
}

float div(float n1, float n2) {
    float retorno = n1 / n2;
    return retorno;
}

float sub(float n1, float n2) {
    float retorno = n1 - n2;
    return retorno;
}

float soma(float n1, float n2) {
    float retorno = n1 + n2;
    return retorno;
}
#endif // ex4

#ifdef ex5
float soma(float a, float b);
float sub(float a, float b);
float mult(float a, float b);
float div(float a, float b);

int main() {
    setlocale(LC_ALL, "");

    char operador;
    float calculo = 0;
    float x;

        printf("Digite a opção desejada:  ");
        printf("(+)\n(-)\n(x)\n(/)\n");
        scanf("%s", &operador);
        do{
        switch(operador) {
            case '+':
                printf("Digite um número\n");
                scanf("%f", &x);
                calculo = soma(calculo, x);
                break;
            case '-':
                printf("Digite um número\n");
                scanf("%f", &x);
                calculo = sub(calculo, x);
                break;
            case 'x':
                printf("Digite um número\n");
                scanf("%f", &x);
                calculo = mult(calculo, x);
                break;
            case '/':
                printf("\nDigite um número para dividir: \n");
                scanf("%f", &x);
                calculo = div(calculo, x);
                break;
        }

        printf("Calculo = %.2f\n", calculo);
        } while (operador == '+' || operador == '-' || operador == 'x' || operador == '/');
}

float mult(float n1, float n2) {
    float retorno = n1 * n2;
    return retorno;
}

float div(float n1, float n2) {
    float retorno = n1 / n2;
    return retorno;
}

float sub(float n1, float n2) {
    float retorno = n1 - n2;
    return retorno;
}

float soma(float n1, float n2) {
    float retorno = n1 + n2;
    return retorno;
}
#endif // ex5
