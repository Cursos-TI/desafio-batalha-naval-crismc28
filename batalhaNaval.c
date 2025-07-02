#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Matriz do tabuleiro: 10x10 preenchida com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas do navio 1 (horizontal) — escolhidas manualmente
    int navio1_linha = 2; // linha fixa
    int navio1_coluna_inicio = 4; // coluna inicial

    // Coordenadas do navio 2 (vertical) — escolhidas manualmente
    int navio2_linha_inicio = 5; // linha inicial
    int navio2_coluna = 6; // coluna fixa

    // Verificações de limite para navio horizontal
    if (navio1_coluna_inicio + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Verificações de limite para navio vertical
    if (navio2_linha_inicio + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Verificação de sobreposição
    int sobreposicao = 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[navio1_linha][navio1_coluna_inicio + i] == 3 ||
            tabuleiro[navio2_linha_inicio + i][navio2_coluna] == 3 ||
            (navio1_linha == navio2_linha_inicio + i && navio1_coluna_inicio + i == navio2_coluna)) {
            sobreposicao = 1;
        }
    }

    if (sobreposicao) {
        printf("Erro: Navios se sobrepõem. Altere as coordenadas.\n");
        return 1;
    }

    // Posicionamento do navio 1 (horizontal)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio1_linha][navio1_coluna_inicio + i] = 3;
    }

    // Posicionamento do navio 2 (vertical)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio2_linha_inicio + i][navio2_coluna] = 3;
    }

    // Exibir o tabuleiro
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
