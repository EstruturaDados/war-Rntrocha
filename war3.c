#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// -------- PROTÓTIPOS --------
void atribuirMissao(char* destino, char* missoes[], int totalMissoes);
void exibirMissao(char* missao);
int verificarMissao(char* missao, Territorio* mapa, int tamanho);
void atacar(Territorio* atacante, Territorio* defensor);
void exibirMapa(Territorio* mapa, int tamanho);
void liberarMemoria(Territorio* mapa, char* missao1, char* missao2);

// -------- IMPLEMENTAÇÕES --------

// Sorteia missão
void atribuirMissao(char* destino, char* missoes[], int totalMissoes) {
    int indice = rand() % totalMissoes;
    strcpy(destino, missoes[indice]);
}

// Mostra missão
void exibirMissao(char* missao) {
    printf("Sua missão: %s\n", missao);
}

// Verifica missão (simples)
int verificarMissao(char* missao, Territorio* mapa, int tamanho) {
    int i, cont = 0;

    if (strstr(missao, "3 territorios") != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, "Azul") == 0) {
                cont++;
            }
        }
        if (cont >= 3) return 1;
    }

    if (strstr(missao, "vermelha") != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, "Vermelho") == 0) {
                return 0;
            }
        }
        return 1;
    }

    return 0;
}

// Ataque entre territórios
void atacar(Territorio* atacante, Territorio* defensor) {
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("Nao pode atacar territorio da mesma cor!\n");
        return;
    }

    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("Ataque: %d | Defesa: %d\n", dadoAtacante, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("Atacante venceu!\n");

        strcpy(defensor->cor, atacante->cor);
        int tropasTransferidas = atacante->tropas / 2;

        defensor->tropas = tropasTransferidas;
        atacante->tropas -= tropasTransferidas;
    } else {
        printf("Defensor venceu!\n");
        atacante->tropas--;
    }
}

// Mostra mapa
void exibirMapa(Territorio* mapa, int tamanho) {
    int i;
    printf("\n--- MAPA ---\n");
    for (i = 0; i < tamanho; i++) {
        printf("%s | Cor: %s | Tropas: %d\n",
               mapa[i].nome,
               mapa[i].cor,
               mapa[i].tropas);
    }
}

// Libera memória
void liberarMemoria(Territorio* mapa, char* missao1, char* missao2) {
    free(mapa);
    free(missao1);
    free(missao2);
}

// -------- MAIN --------

int main() {
    srand(time(NULL));

    int tamanhoMapa = 5;

    Territorio* mapa = (Territorio*) malloc(tamanhoMapa * sizeof(Territorio));

    // Inicialização
    strcpy(mapa[0].nome, "A");
    strcpy(mapa[0].cor, "Azul");
    mapa[0].tropas = 5;

    strcpy(mapa[1].nome, "B");
    strcpy(mapa[1].cor, "Vermelho");
    mapa[1].tropas = 4;

    strcpy(mapa[2].nome, "C");
    strcpy(mapa[2].cor, "Azul");
    mapa[2].tropas = 3;

    strcpy(mapa[3].nome, "D");
    strcpy(mapa[3].cor, "Vermelho");
    mapa[3].tropas = 6;

    strcpy(mapa[4].nome, "E");
    strcpy(mapa[4].cor, "Neutro");
    mapa[4].tropas = 2;

    // Missões
    char* missoes[] = {
        "Conquistar 3 territorios",
        "Eliminar todas as tropas da cor vermelha",
        "Controlar todos os territorios",
        "Conquistar 2 territorios seguidos",
        "Dominar metade do mapa"
    };

    int totalMissoes = 5;

    char* missaoJogador1 = (char*) malloc(100 * sizeof(char));
    char* missaoJogador2 = (char*) malloc(100 * sizeof(char));

    atribuirMissao(missaoJogador1, missoes, totalMissoes);
    atribuirMissao(missaoJogador2, missoes, totalMissoes);

    printf("Jogador 1:\n");
    exibirMissao(missaoJogador1);

    printf("\nJogador 2:\n");
    exibirMissao(missaoJogador2);

    int turno = 0;
    int vencedor = 0;

    while (!vencedor && turno < 10) {
        printf("\nTurno %d\n", turno + 1);

        exibirMapa(mapa, tamanhoMapa);

        atacar(&mapa[0], &mapa[1]);

        if (verificarMissao(missaoJogador1, mapa, tamanhoMapa)) {
            printf("\nJogador 1 venceu!\n");
            vencedor = 1;
        }

        if (verificarMissao(missaoJogador2, mapa, tamanhoMapa)) {
            printf("\nJogador 2 venceu!\n");
            vencedor = 1;
        }

        turno++;
    }

    liberarMemoria(mapa, missaoJogador1, missaoJogador2);

    return 0;
}