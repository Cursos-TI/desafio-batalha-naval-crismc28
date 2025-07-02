#include <stdio.h>

#define TAM 10
#define HABILIDADE 5
#define NAVIO 3
#define AREA_AFETADA 5

// Função para exibir o tabuleiro com caracteres específicos
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO COM HABILIDADES ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(". "); // Água
            } else if (tabuleiro[i][j] == NAVIO) {
                printf("N "); // Navio
            } else if (tabuleiro[i][j] == AREA_AFETADA) {
                printf("* "); // Área afetada
            } else {
                printf("? "); // Valor desconhecido
            }
        }
        printf("\n");
    }
}

// Função genérica para aplicar uma matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[HABILIDADE][HABILIDADE], int origem_linha, int origem_coluna) {
    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            // Calcula a posição no tabuleiro
            int linha_tab = origem_linha - HABILIDADE/2 + i;
            int col_tab = origem_coluna - HABILIDADE/2 + j;

            // Aplica se estiver dentro dos limites e se for área afetada
            if (linha_tab >= 0 && linha_tab < TAM && col_tab >= 0 && col_tab < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[linha_tab][col_tab] == 0) {
                    tabuleiro[linha_tab][col_tab] = AREA_AFETADA;
                }
            }
        }
    }
}

// Gera matriz em forma de cone (expande para baixo)
void gerarCone(int matriz[HABILIDADE][HABILIDADE]) {
    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            matriz[i][j] = 0;
        }
    }
    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            if (j >= HABILIDADE/2 - i && j <= HABILIDADE/2 + i) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Gera matriz em forma de cruz
void gerarCruz(int matriz[HABILIDADE][HABILIDADE]) {
    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            matriz[i][j] = (i == HABILIDADE/2 || j == HABILIDADE/2) ? 1 : 0;
        }
    }
}

// Gera matriz em forma de octaedro (losango)
void gerarOctaedro(int matriz[HABILIDADE][HABILIDADE]) {
    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            matriz[i][j] = (abs(i - HABILIDADE/2) + abs(j - HABILIDADE/2) <= HABILIDADE/2) ? 1 : 0;
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Posicionar alguns navios fixos (horizontal e vertical)
    tabuleiro[2][2] = NAVIO;
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;

    tabuleiro[5][6] = NAVIO;
    tabuleiro[6][6] = NAVIO;
    tabuleiro[7][6] = NAVIO;

    // Matrizes para habilidades
    int cone[HABILIDADE][HABILIDADE];
    int cruz[HABILIDADE][HABILIDADE];
    int octaedro[HABILIDADE][HABILIDADE];

    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Pontos de origem das habilidades no tabuleiro
    int origemCone[2] = {1, 4};       // Cone para baixo a partir do topo
    int origemCruz[2] = {6, 3};       // Cruz no meio
    int origemOctaedro[2] = {8, 8};   // Octaedro no canto inferior direito

    // Aplicar habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, cone, origemCone[0], origemCone[1]);
    aplicarHabilidade(tabuleiro, cruz, origemCruz[0], origemCruz[1]);
    aplicarHabilidade(tabuleiro, octaedro, origemOctaedro[0], origemOctaedro[1]);

    // Exibir o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
