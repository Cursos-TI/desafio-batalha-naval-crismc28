#include <stdio.h>

#define TAM 10
#define NAVIO 3

// Função para verificar se posição está livre
int podePosicionar(int tabuleiro[TAM][TAM], int linha[], int coluna[]) {
    for (int i = 0; i < NAVIO; i++) {
        if (linha[i] < 0 || linha[i] >= TAM || coluna[i] < 0 || coluna[i] >= TAM)
            return 0; // fora dos limites
        if (tabuleiro[linha[i]][coluna[i]] != 0)
            return 0; // já ocupado
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM][TAM], int linha[], int coluna[]) {
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha[i]][coluna[i]] = 3;
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Tabuleiro 10x10 inicializado com 0 (água)
    int tabuleiro[TAM][TAM] = {0};

    // --- NAVIO 1: horizontal em (2,2) a (2,4)
    int navio1_linha[] = {2, 2, 2};
    int navio1_coluna[] = {2, 3, 4};

    // --- NAVIO 2: vertical em (5,6) a (7,6)
    int navio2_linha[] = {5, 6, 7};
    int navio2_coluna[] = {6, 6, 6};

    // --- NAVIO 3: diagonal ↘ em (0,0) a (2,2)
    int navio3_linha[] = {0, 1, 2};
    int navio3_coluna[] = {0, 1, 2};

    // --- NAVIO 4: diagonal ↙ em (0,9) a (2,7)
    int navio4_linha[] = {0, 1, 2};
    int navio4_coluna[] = {9, 8, 7};

    // Validar e posicionar os navios
    if (!podePosicionar(tabuleiro, navio1_linha, navio1_coluna)) {
        printf("Erro ao posicionar navio 1.\n"); return 1;
    }
    posicionarNavio(tabuleiro, navio1_linha, navio1_coluna);

    if (!podePosicionar(tabuleiro, navio2_linha, navio2_coluna)) {
        printf("Erro ao posicionar navio 2.\n"); return 1;
    }
    posicionarNavio(tabuleiro, navio2_linha, navio2_coluna);

    if (!podePosicionar(tabuleiro, navio3_linha, navio3_coluna)) {
        printf("Erro ao posicionar navio 3.\n"); return 1;
    }
    posicionarNavio(tabuleiro, navio3_linha, navio3_coluna);

    if (!podePosicionar(tabuleiro, navio4_linha, navio4_coluna)) {
        printf("Erro ao posicionar navio 4.\n"); return 1;
    }
    posicionarNavio(tabuleiro, navio4_linha, navio4_coluna);

    // Exibir o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
