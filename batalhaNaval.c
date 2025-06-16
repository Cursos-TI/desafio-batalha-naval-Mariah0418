#include <stdio.h>

int main() {
    // === TABULEIRO ===
    int tabuleiro[10][10] = {0};

    // === POSICIONAMENTO DOS NAVIOS ===

    // Navio Vertical
    int tam_navio_vertical = 3;
    int col_vertical = 6;
    int lin_vertical_ini = 2;
    for (int i = 0; i < tam_navio_vertical; i++) {
        tabuleiro[lin_vertical_ini + i][col_vertical] = 3;
    }

    // Navio Horizontal
    int tam_navio_horizontal = 4;
    int lin_horizontal = 4;
    int col_horizontal_ini = 1;
    for (int i = 0; i < tam_navio_horizontal; i++) {
        tabuleiro[lin_horizontal][col_horizontal_ini + i] = 3;
    }

    // Navio Diagonal Principal (\)
    int tam_navio_diag1 = 3;
    int lin_diag1_ini = 5;
    int col_diag1_ini = 5;
    for (int i = 0; i < tam_navio_diag1; i++) {
        tabuleiro[lin_diag1_ini + i][col_diag1_ini + i] = 3;
    }

    // Navio Diagonal Secundária (/)
    int tam_navio_diag2 = 3;
    int lin_diag2_ini = 0;
    int col_diag2_ini = 9;
    for (int i = 0; i < tam_navio_diag2; i++) {
        tabuleiro[lin_diag2_ini + i][col_diag2_ini - i] = 3;
    }

    // === EXIBIÇÃO DAS COORDENADAS DOS NAVIOS ===

    printf("Navio Vertical:\n");
    for (int i = 0; i < tam_navio_vertical; i++) {
        printf("Linha %d, Coluna %d\n", lin_vertical_ini + i, col_vertical);
    }

    printf("\nNavio Horizontal:\n");
    for (int i = 0; i < tam_navio_horizontal; i++) {
        printf("Linha %d, Coluna %d\n", lin_horizontal, col_horizontal_ini + i);
    }

    printf("\nNavio Diagonal (\\):\n");
    for (int i = 0; i < tam_navio_diag1; i++) {
        printf("Linha %d, Coluna %d\n", lin_diag1_ini + i, col_diag1_ini + i);
    }

    printf("\nNavio Diagonal (/):\n");
    for (int i = 0; i < tam_navio_diag2; i++) {
        printf("Linha %d, Coluna %d\n", lin_diag2_ini + i, col_diag2_ini - i);
    }

    // === EXIBIÇÃO DO TABULEIRO ===

    printf("\n=== Tabuleiro Completo ===\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // ========================================================
    // === NÍVEL MESTRE — HABILIDADES ESPECIAIS ==============
    // ========================================================

    // MATRIZES 5x5 PARA AS HABILIDADES
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // === CONE ===
    // Formato:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    for (int i = 0; i < 3; i++) {          // linhas
        for (int j = 2 - i; j <= 2 + i; j++) { // colunas
            cone[i][j] = 1;
        }
    }

    // === CRUZ ===
    // Formato:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    for (int i = 0; i < 5; i++) {
        cruz[1][i] = 1;  // linha do meio
        cruz[i][2] = 1;  // coluna do meio
    }

    // === OCTAEDRO ===
    // Formato:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0
    for (int i = 0; i < 3; i++) {          // linhas
        for (int j = 2 - i; j <= 2 + i; j++) {
            octaedro[i][j] = 1;
        }
    }
    // espelha a parte de cima na parte de baixo
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            octaedro[4 - i][j] = octaedro[i][j];
        }
    }

    // === EXIBIÇÃO DAS HABILIDADES ===

    printf("\n=== Habilidade: Cone ===\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", cone[i][j]);
        }
        printf("\n");
    }

    printf("\n=== Habilidade: Cruz ===\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", cruz[i][j]);
        }
        printf("\n");
    }

    printf("\n=== Habilidade: Octaedro ===\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", octaedro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
