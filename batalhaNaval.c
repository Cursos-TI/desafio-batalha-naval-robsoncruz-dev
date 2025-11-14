#include <stdio.h> // Biblioteca padrao para entrada e saida de dados

// Define o tamanho do tabuleiro (10x10)
#define TAMANHO 10
// Define o tamanho das matrizes de habilidade (5x5)
#define HABILIDADE_TAM 5

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
int main() {
    
    // --- Nível Novato / Aventureiro ---
    
    // 1. Representa o Tabuleiro: Declara uma matriz 10x10
    int tabuleiro[TAMANHO][TAMANHO];
    int i, j; // Variaveis de controle para os loops (linhas e colunas)

    // 2. Inicializa todas as posicoes do tabuleiro com 0 (agua)
    //
    for (i = 0; i < TAMANHO; i++) { // Loop para as linhas
        for (j = 0; j < TAMANHO; j++) { // Loop para as colunas
            tabuleiro[i][j] = 0;
        }
    }

    // 3. Posiciona os Navios (tamanho fixo 3)
    //
    
    // Navio 1: Horizontal (Tamanho 3)
    // Ocupara as posicoes: [1][1], [1][2], [1][3]
    int navioH_linha = 1;
    int navioH_coluna = 1;
    for (j = 0; j < 3; j++) { 
        if (navioH_coluna + j < TAMANHO) {
            tabuleiro[navioH_linha][navioH_coluna + j] = 3; 
        }
    }

    // Navio 2: Vertical (Tamanho 3)
    // Ocupara as posicoes: [3][5], [4][5], [5][5]
    int navioV_linha = 3;
    int navioV_coluna = 5;
    for (i = 0; i < 3; i++) { 
        if (navioV_linha + i < TAMANHO) {
            tabuleiro[navioV_linha + i][navioV_coluna] = 3;
        }
    }
    
    // Navio 3: Diagonal (Tamanho 3)
    // Ocupara as posicoes: [3][1], [4][2], [5][3]
    int navioD1_linha = 3;
    int navioD1_coluna = 1;
    for (i = 0; i < 3; i++) {
        if (navioD1_linha + i < TAMANHO && navioD1_coluna + i < TAMANHO) {
            tabuleiro[navioD1_linha + i][navioD1_coluna + i] = 3;
        }
    }

    // Navio 4: Diagonal (Tamanho 3)
    // Ocupara as posicoes: [7][7], [6][8], [5][9]
    int navioD2_linha = 7;
    int navioD2_coluna = 7;
    for (i = 0; i < 3; i++) {
        if (navioD2_linha - i >= 0 && navioD2_coluna + i < TAMANHO) {
            tabuleiro[navioD2_linha - i][navioD2_coluna + i] = 3;
        }
    }
    

    // --- Nível Mestre - Habilidades Especiais com Matrizes ---
    
    // 1. Criar Matrizes de Habilidade (5x5)
    int hab_cone[HABILIDADE_TAM][HABILIDADE_TAM];
    int hab_cruz[HABILIDADE_TAM][HABILIDADE_TAM];
    int hab_octa[HABILIDADE_TAM][HABILIDADE_TAM];
    
    // Variavel para achar o centro (indice 2)
    int meio = HABILIDADE_TAM / 2; 

    // Inicializa todas as matrizes de habilidade com 0
    for (i = 0; i < HABILIDADE_TAM; i++) {
        for (j = 0; j < HABILIDADE_TAM; j++) {
            hab_cone[i][j] = 0;
            hab_cruz[i][j] = 0;
            hab_octa[i][j] = 0;
        }
    }

    // 2. Preencher Habilidade Cone (Formato de Triangulo)
    // Logica: comeca do topo (i=0) e vai alargando
    int altura_cone = 3; // O exemplo do desafio mostra 3 linhas
    for (i = 0; i < altura_cone; i++) { 
        for (j = 0; j < HABILIDADE_TAM; j++) {
            // Condicao para desenhar o triangulo
            if (j >= (meio - i) && j <= (meio + i)) {
                hab_cone[i][j] = 1; // 1 = area afetada
            }
        }
    }

    // 3. Preencher Habilidade Cruz
    // Logica: Pinta a linha central (i == meio) e a coluna central (j == meio)
    for (i = 0; i < HABILIDADE_TAM; i++) {
        for (j = 0; j < HABILIDADE_TAM; j++) {
            if (i == meio || j == meio) {
                hab_cruz[i][j] = 1; // 1 = area afetada
            }
        }
    }

    // 4. Preencher Habilidade Octaedro (Formato de Losango)
    // Logica: E um "cone" crescendo ate o meio, e um "cone" invertido depois
    for (i = 0; i < HABILIDADE_TAM; i++) {
        for (j = 0; j < HABILIDADE_TAM; j++) {
            
            if (i <= meio) { // Parte de cima do losango
                if (j >= (meio - i) && j <= (meio + i)) {
                    hab_octa[i][j] = 1;
                }
            } else { // Parte de baixo do losango
                int i_invertido = (HABILIDADE_TAM - 1) - i; // Faz o i "voltar" (ex: 3 vira 1, 4 vira 0)
                if (j >= (meio - i_invertido) && j <= (meio + i_invertido)) {
                    hab_octa[i][j] = 1;
                }
            }
        }
    }


    // 5. Integrar Habilidades ao Tabuleiro
    // Define um ponto de origem para cada habilidade (posicao no tabuleiro)
    // Essas coordenadas serao o *centro* da habilidade 5x5
    int cone_origem_i = 1;
    int cone_origem_j = 5;
    
    int cruz_origem_i = 8;
    int cruz_origem_j = 2;
    
    int octa_origem_i = 7;
    int octa_origem_j = 8;
    
    int centro_hab = HABILIDADE_TAM / 2; // 2

    // Aplicando Cone
    for (i = 0; i < HABILIDADE_TAM; i++) {
        for (j = 0; j < HABILIDADE_TAM; j++) {
            // Achar a coordenada correspondente no tabuleiro 10x10
            int tab_i = cone_origem_i + (i - centro_hab);
            int tab_j = cone_origem_j + (j - centro_hab);

            // Se a habilidade estiver ativa (== 1)
            if (hab_cone[i][j] == 1) {
                // E se estiver dentro dos limites do tabuleiro 10x10
                if (tab_i >= 0 && tab_i < TAMANHO && tab_j >= 0 && tab_j < TAMANHO) {
                    // Marca com 5 (area de efeito), mas so se for agua (0)
                    if (tabuleiro[tab_i][tab_j] == 0) { 
                        tabuleiro[tab_i][tab_j] = 5;
                    }
                }
            }
        }
    }
    
    // Aplicando Cruz
    for (i = 0; i < HABILIDADE_TAM; i++) {
        for (j = 0; j < HABILIDADE_TAM; j++) {
            int tab_i = cruz_origem_i + (i - centro_hab);
            int tab_j = cruz_origem_j + (j - centro_hab);

            if (hab_cruz[i][j] == 1) {
                if (tab_i >= 0 && tab_i < TAMANHO && tab_j >= 0 && tab_j < TAMANHO) {
                    if (tabuleiro[tab_i][tab_j] == 0) { 
                        tabuleiro[tab_i][tab_j] = 5;
                    }
                }
            }
        }
    }
    
    // Aplicando Octaedro
    for (i = 0; i < HABILIDADE_TAM; i++) {
        for (j = 0; j < HABILIDADE_TAM; j++) {
            int tab_i = octa_origem_i + (i - centro_hab);
            int tab_j = octa_origem_j + (j - centro_hab);

            if (hab_octa[i][j] == 1) {
                if (tab_i >= 0 && tab_i < TAMANHO && tab_j >= 0 && tab_j < TAMANHO) {
                    if (tabuleiro[tab_i][tab_j] == 0) { 
                        tabuleiro[tab_i][tab_j] = 5;
                    }
                }
            }
        }
    }


    // 6. Exibe o Tabuleiro Final no console
    //
    printf("### Tabuleiro Batalha Naval (Nivel Mestre) ###\n");
    printf("   0 = Agua | 3 = Navio | 5 = Efeito\n\n");
    
    for (i = 0; i < TAMANHO; i++) { // Loop para as linhas
        for (j = 0; j < TAMANHO; j++) { // Loop para as colunas
            
            // Imprime o valor da posicao e um espaco para separar
            printf("%d ", tabuleiro[i][j]); 
        }
        
        // Pula uma linha ao final de cada linha da matriz
        printf("\n");
    }

    return 0;
}







    








































      



























    












