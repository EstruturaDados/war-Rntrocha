// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.

// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
// Funções de setup e gerenciamento de memória:
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
// Função utilitária:
#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
// Armazena nome do território, cor do exército e quantidade de tropas

struct territorio
{
    char nome[30];
    char cor[10];
    int tropas;
};

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {
    //vetor para armazenar 5 territorios , armazena 5 registros 
    struct territorio territorios[5];

    //laço para cadastrar os terrritorios
    for (int i = 0; i<5; i++) {
        printf("\n --- Cadastro do territorio %d --- \n", i + 1);

        // entrada do nome do territorio
        printf("Digite o nome do territorio: ");
        scanf(" %[^\n]", territorios[i].nome);
        //" %[^\n]" permite ler strings com espaços

        // Entrada de cor do exercito
        printf("Digite a cor do Exercito:  ");
        scanf(" %s", territorios[i].cor);

        //entrada da quantidade de tropas
        printf("Digite a quantidade de tropas: ");
        scanf(" %d", &territorios[i].tropas);
    }
    // exibir todos os territorios cadastrados 
    printf("\n **** Territorios cadastrados *****\n");

    for ( int i = 0; i < 5 ; i++){
        printf("\n Territorio %d:\n",i+1);
        printf("Nome :  %s\n", territorios[i].nome);
        printf("Cor do Exercito: %s\n", territorios[i].cor);
        printf("Quantidade de tropas: %d\n", territorios[i].tropas);
    }

    return 0;
    
}