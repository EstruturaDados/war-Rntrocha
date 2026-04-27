#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} territorio;

// função de ataque
void atacar(territorio* atacante, territorio* defensor) {
    int dadoA = rand() % 6 + 1;
    int dadoD = rand() % 6 + 1;

    printf("\n%s ataca %s\n", atacante->nome, defensor->nome);
    printf("Dado atacante: %d | Dado defensor: %d\n", dadoA, dadoD);

    if (dadoA > dadoD) {
        printf("Atacante venceu!\n");

        strcpy(defensor->cor, atacante->cor);

        int tropas = atacante->tropas / 2;
        defensor->tropas = tropas;
        atacante->tropas -= tropas;

    } else {
        printf("Defensor venceu!\n");

        if (atacante->tropas > 1)
            atacante->tropas--;
    }
}

int main() {
    srand(time(NULL));

    int qtd;

    printf("=====================\n");
    printf("Diga quantos territorios irão batalhar ? ");
    scanf("%d", &qtd);

    territorio* territorios = (territorio*) calloc(qtd, sizeof(territorio));

    // cadastro
    for (int i = 0; i < qtd; i++) {
        printf("\n--- Cadastro do territorio %d ---\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", territorios[i].nome);

        printf("Cor: ");
        scanf("%s", territorios[i].cor);

        printf("Tropas: ");
        scanf("%d", &territorios[i].tropas);
    }

    // exibição 
    printf("\n--- Territorios disponiveis ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("[%d] %s (%s) - %d tropas\n",
               i + 1,
               territorios[i].nome,
               territorios[i].cor,
               territorios[i].tropas);
    }

    printf("\n--- Fase de Ataque ---\n");

    int a, d;

    // escolha do atacante
    printf("Selecionar territorio atacante: ");
    scanf("%d", &a);

    // escolha do defensor
    printf("Selecionar territorio defensor: ");
    scanf("%d", &d);

    // CONVERSAO PARA INDICE REAL DO C
    a = a - 1;
    d = d - 1;

    // validação
    if (a >= 0 && a < qtd && d >= 0 && d < qtd) {

        if (strcmp(territorios[a].cor, territorios[d].cor) != 0) {
            atacar(&territorios[a], &territorios[d]);
        } else {
            printf("Nao pode atacar territorio da mesma cor!\n");
        }

    } else {
        printf("Selecao invalida!\n");
    }

    // resultado final
    printf("\n--- Estado final ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("%s | %s | %d tropas\n",
               territorios[i].nome,
               territorios[i].cor,
               territorios[i].tropas);
    }

    free(territorios);
    printf("Limpando a memoria, Obrigado!!! \n");

    return 0;
}