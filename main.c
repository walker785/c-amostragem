#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include "amostragem.h"

void menu() {

    setlocale(LC_ALL, "Portuguese");

    system("color 06");

    int op;

    do {

        printf("\n\n");
        printf("----------------------------------------------THE CALCULATOR!!!--------------------------------------------\n\n\n");
        printf("                      .andAHHAbnn.                                                                  \n");
        printf("                   .aAHHHAAUUAAHHHAn.                                                               \n");
        printf("                  dHP^~'        '~^THb.                                                             \n");
        printf("            .   .AHF                YHA.   .             ESCOLHA UMA OP��O                          \n");
        printf("            |  .AHHb.              .dHHA.  |                                                        \n");
        printf("            |  HHAUAAHAbn      adAHAAUAHA  |                                                        \n");
        printf("            I  HF~'                  ]HHH  I             (1) Amostra Sistem�tica                    \n");
        printf("           HHI HAPHHHHHHUHb  dAHHHHHHHHHH IHH                                                       \n");
        printf("           HHI HHHD> .andHH  HHUUP^~YHHHH IHH            (2) Amostragem Casual ou Aleat�ria Simples \n");
        printf("           YUI ]HHP     '~Y  P~'     THH[ IUP                                                       \n");
        printf("            '  `HK                   ]HH'  '             (3) Amostragem Proporcional Estratificada  \n");
        printf("                THAn.  .d.aAAn.b.  .dHHP'                                                           \n");
        printf("                ]HHHHAAUPHHHHHHHYUAAHHHH[                (4) Sair                                   \n");
        printf("                `HHPHHHHHHHHHHHHHHHHHYHH                                                            \n");
        printf("                 YHHHHHH HHH HHH HHHHHF                                                             \n");
        printf("                  'YAHHH bdH bnd ndAP'                                                              \n");
        printf("                   THHAA HHH HHH AHHF    I'LL                                                       \n");
        printf("                    'UHHHHHHHHHHHUU'        BE                                                      \n");
        printf("                      ]HHUUHHHHHH[           BACK!                                                  \n");
        printf("                    .adHHHHHHHHHHbn.                                                                \n");
        printf("             ..andAAHHHHHHHHAHHHHHHHAAbnn..                                                         \n");
        printf("        .ndAAHHHHHHUUHHHHHHHHHHUP^~'~^YUHHHAAbn.                                                    \n");
        printf("          '~^YUHHP'   '~^YUHHUP'        '^YUP^''                                                ---> ");

        verificarop(&op);

        printf ("\nO valor digitado foi: %d\n\n", op);



        system("pause");
        system("cls");


          switch(op) {
            case 1:
                sistematica();
                system("pause");
                system("cls");
                break;

            case 2:
                casual_ou_aleatoria_simples();
                system("pause");
                system("cls");
                break;

            case 3:
                proporcial_estratificada();
                system("pause");
                system("cls");
                break;

            case 4:
                exit(1);
                break;

            default:
                 printf("Digite uma op��o v�lida!\n");
        }
    }while(op);
}

void sistematica() {

    setlocale(LC_ALL, "Portuguese");

    printf("\n\n");
    printf("\t\t*************************\n\n");
    printf("\t\t1- AMOSTRAGEM SISTEM�TICA\n\n");
    printf("\t\t*************************\n\n");

    int i=1, N=0, n=0, k=0, primeiro=0;


    printf("\n\nInsira o tamanho da amostra (n): ");

    verificarn(&n);

    printf("\n\nInsira o tamanho da popula��o (N): ");

    verificarNi(&N);

    verificarnN(&n,&N);

    k=N/n;

    srand(time(0));

    primeiro = rand()%N;

    printf("\n\nA amostra sorteada para dar inicio a selecao �: %i", primeiro);

    printf("\n\nAs amostras selecionadas foram:\n");

    while(i<=n) {

        printf("Amostra %d - %i;\n", i++, primeiro);

        primeiro+=k;

        if(primeiro>N) {
            primeiro=primeiro-N;
        }
    }

    printf("\n\nO intervalo (K): %i\n\n", k);

}

void casual_ou_aleatoria_simples() {

    setlocale(LC_ALL, "Portuguese");

    printf("\n\n");
    printf("\t\t*****************************************\n\n");
    printf("\t\t2- AMOSTRAGEM CASUAL OU ALEAT�RIA SIMPLES\n\n");
    printf("\t\t*****************************************\n\n");

    float N=0, total=0, n0=0, E0=0, E=0;

    printf("\n\nInsira o tamanho da popula��o (N): ");

    verificarNf(&N);

    printf("\n\nInsira o erro amostral toler�vel (E0): ");

    verificarE(&E);

    verificarEN(&E,&N);

    E0 =(E/100);
    n0 = 1/(E0*E0);
    total = (N*n0)/(N+n0);

    printf("\n\nO tamanho da amostra (n) � de: %f",total);

    total = ceil(total);

    printf("\n\nSeu valor arredondado �: %.0f\n\n", total);
}

void proporcial_estratificada() {

    setlocale(LC_ALL, "Portuguese");

    printf("\n\n");
    printf("\t\t****************************************\n\n");
    printf("\t\t3- AMOSTRAGEM PROPORCIONAL ESTRATIFICADA\n\n");
    printf("\t\t****************************************\n\n");

    float N=0, ind=0, total=0, n0=0, E0=0, E=0, resul=0, A=0, x=0;
    int v=0, c=0, soma=0;

    printf("\n\nInsira o tamanho da popula��o (N): ");

    verificarNf(&N);

    printf("\n\nInsira o erro amostral toler�vel (E0): ");

    verificarE(&E);

    verificarEN(&E,&N);

    E0 = (E/100);
    n0 = 1/(E0*E0);
    total = (N*n0)/(N+n0);
    x = total;
    x = ceil(x);
    printf("\nTamanho m�nimo da amostra (n): %f\n", x);
    x = (x*100/N);
    ind = x/100;

    printf("\nP�s regra de tr�s (N-100 n-x): %f\n\n", x);

    printf("\nQuantas amostras deseja verificar?: ");

    verificarv(&v);

    for(c=0; c<v; c++) {

        printf("\nInsira o valor da %d� amostra a ser retirada: ", c+1);

        verificarA(&A);

        resul=ind*A;

        printf("\nO tamanho da amostra � de : %f",resul);

        resul = round(resul);

        printf("\n\nArredondada seu valor �: %.0f\n\n",resul);

        soma = soma+=resul;
    }

    printf("\nO valor total �: %d\n\n",soma);

}

void verificarop(int* op) {
    while (scanf("%d", &*op) != 1 || *op<0){
        static char temp[256];
        fgets(temp, sizeof(temp), stdin);
        printf("\nValor inv�lido, tente novamente (n�o insira letras ou n�meros negativos): ");
    }
}

void verificarn(int* n) {
    while (scanf("%d", &*n) != 1 || *n<0){
        static char temp[256];
        fgets(temp, sizeof(temp), stdin);
        printf("\nValor inv�lido, tente novamente (n�o insira letras ou n�meros negativos): ");
    }
    return (void)n;
}

void verificarNi(int* N) {
    while (scanf("%d", &*N) != 1 || *N<0){
        static char temp[256];
        fgets(temp, sizeof(temp), stdin);
        printf("\nValor inv�lido, tente novamente (n�o insira letras ou n�meros negativos): ");
    }
    return (void)N;
}

void verificarNf(int* N) {
    while (scanf("%f", &*N) != 1 || *N<0){
        static char temp[256];
        fgets(temp, sizeof(temp), stdin);
        printf("\nValor inv�lido, tente novamente (n�o insira letras ou n�meros negativos): ");
    }
    return (void)N;
}

void verificarE(int* E) {
    while (scanf("%f", &*E) != 1 || *E<0){
        static char temp[256];
        fgets(temp, sizeof(temp), stdin);
        printf("\nValor inv�lido, tente novamente (n�o insira letras ou n�meros negativos): ");
    }
    return (void)E;
}

void verificarv(int* v) {
    while (scanf("%d", &*v) != 1 || *v<0){
        static char temp[256];
        fgets(temp, sizeof(temp), stdin);
        printf("\nValor inv�lido, tente novamente (n�o insira letras ou n�meros negativos): ");
    }
    return (void)v;
}

void verificarA(float* A) {
    while (scanf("%f", &*A) != 1 || *A<0){
        static char temp[256];
        fgets(temp, sizeof(temp), stdin);
        printf("\nValor inv�lido, tente novamente (n�o insira letras ou n�meros negativos): ");
    }
    return (void)A;
}

void verificarnN(int* n, int* N) {
    if(*n>*N){
        system("color 04");

        printf("\n\nValores inv�lidos!\nTamanho da amostra maior que o tamanho da popula��o.\nRetornando ao menu...\n\n");

        system("pause");
        system("cls");
        menu();
    }
}

void verificarEN(float* E, float* N) {
        if(*E>*N){
        system("color 04");

        printf("\n\nValores inv�lidos!\nErro amostral maior que o tamanho da popula��o.\nRetornando ao menu...\n\n");

        system("pause");
        system("cls");
        menu();
    }
}

int main() {

    menu();

    return 0;
}
