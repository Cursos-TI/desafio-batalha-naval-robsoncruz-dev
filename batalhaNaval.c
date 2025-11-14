#include <stdio.h> // Biblioteca padrao para entrada e saida de dados

// Define o tamanho do tabuleiro (10x10)
#define TAMANHO 10
// Define o tamanho das matrizes de habilidade (5x5)
#define HABILIDADE_TAM 5

// Desafio Batalha Naval - MateCheck - Nivel Mestre
// Sistema completo com navios e habilidades especiais
int main() {
    
    // --- Nivel Novato / Aventureiro ---
    
    // 1. Representa o Tabuleiro: Declara uma matriz 10x10
    int tabuleiro[TAMANHO][TAMANHO];
    int i, j; // Variaveis de controle para os loops (linhas e colunas)

    // 2. Inicializa todas as posicoes do tabuleiro com 0 (agua)
    for (i = 0; i < TAMANHO; i++) { // Loop para as linhas
        for (j = 0; j < TAMANHO; j++) { // Loop para as colunas
            tabuleiro[i][j] = 0;
        }
    }

    // 3. Posiciona os Navios (tamanho fixo 3)
    
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
    

    // --- Nivel Mestre - Habilidades Especiais com Matrizes ---
    
    // 1. Criar Matrizes de Habilidade (5x5)
    int hab_cone[HABILIDADE_TAM][HABILIDADE_TAM];
    int hab_cruz[HABILIDADE_TAM][HABILIDADE_TAM];
    int hab_octa[HABILIDADE_TAM][HABILIDADE_TAM];
    
    // Variavel para achar o centro (indice 2 em uma matriz 5x5)
    int meio = HABILIDADE_TAM / 2; 

    // Inicializa todas as matrizes de habilidade com 0
    for (i = 0; i < HABILIDADE_TAM; i++) {
        for (j = 0; j < HABILIDADE_TAM; j++) {
            hab_cone[i][j] = 0;
            hab_cruz[i][j] = 0;
            hab_octa[i][j] = 0;
        }
    }

    // 2. Preencher Habilidade CONE (Formato de Triangulo Invertido)
    // Cone apontando para baixo: comeca com 1 ponto no topo e expande
    // Linha 0: apenas o centro (meio)
    // Linha 1: centro +/- 1
    // Linha 2: centro +/- 2
    // Usa condicional para verificar se esta dentro da largura permitida
    for (i = 0; i < HABILIDADE_TAM; i++) { 
        for (j = 0; j < HABILIDADE_TAM; j++) {
            // Condicao: a distancia do centro (j) deve ser menor ou igual a linha (i)
            // Isso cria o efeito de expansao do cone
            if (j >= (meio - i) && j <= (meio + i)) {
                hab_cone[i][j] = 1; // 1 = area afetada pela habilidade
            }
        }
    }

    // 3. Preencher Habilidade CRUZ
    // Desenha uma cruz: linha central horizontal + coluna central vertical
    // Usa condicional para verificar se esta na linha ou coluna do meio
    for (i = 0; i < HABILIDADE_TAM; i++) {
        for (j = 0; j < HABILIDADE_TAM; j++) {
            // Se estiver na linha central OU na coluna central, marca como afetado
            if (i == meio || j == meio) {
                hab_cruz[i][j] = 1; // 1 = area afetada
            }
        }
    }

    // 4. Preencher Habilidade OCTAEDRO (Formato de Losango/Diamante)
    // Vista frontal de um octaedro = losango
    // Primeira metade: expande (como cone)
    // Segunda metade: contrai (cone invertido)
    // Usa condicionais para calcular a distancia do centro em cada linha
    for (i = 0; i < HABILIDADE_TAM; i++) {
        for (j = 0; j < HABILIDADE_TAM; j++) {
            // Calcula a distancia da linha atual ate o centro
            int distancia_centro;
            if (i <= meio) {
                // Parte superior: distancia cresce de 0 ate meio
                distancia_centro = i;
            } else {
                // Parte inferior: distancia diminui de meio ate 0
                distancia_centro = HABILIDADE_TAM - 1 - i;
            }
            
            // Se a coluna estiver dentro da faixa permitida pela distancia, marca
            if (j >= (meio - distancia_centro) && j <= (meio + distancia_centro)) {
                hab_octa[i][j] = 1;
            }
        }
    }


    // 5. Integrar Habilidades ao Tabuleiro
    // Define pontos de origem para cada habilidade (centro da habilidade no tabuleiro)
    int cone_origem_i = 2;
    int cone_origem_j = 5;
    
    int cruz_origem_i = 7;
    int cruz_origem_j = 2;
    
    int octa_origem_i = 6;
    int octa_origem_j = 8;
    
    int centro_hab = HABILIDADE_TAM / 2; // Indice do centro (2 para matriz 5x5)

    // Aplicando CONE ao tabuleiro
    // Percorre toda a matriz de habilidade
    for (i = 0; i < HABILIDADE_TAM; i++) {
        for (j = 0; j < HABILIDADE_TAM; j++) {
            // Calcula a posicao correspondente no tabuleiro
            // Subtrai centro_hab para centralizar a habilidade no ponto de origem
            int tab_i = cone_origem_i + (i - centro_hab);
            int tab_j = cone_origem_j + (j - centro_hab);

            // Se a posicao da habilidade estiver ativa (== 1)
            if (hab_cone[i][j] == 1) {
                // Verifica se a posicao esta dentro dos limites do tabuleiro
                if (tab_i >= 0 && tab_i < TAMANHO && tab_j >= 0 && tab_j < TAMANHO) {
                    // Marca com 5 (area de efeito) se for agua
                    // Mantem o 3 se for navio (para visualizar impacto em navios)
                    if (tabuleiro[tab_i][tab_j] == 0) { 
                        tabuleiro[tab_i][tab_j] = 5;
                    }
                }
            }
        }
    }
    
    // Aplicando CRUZ ao tabuleiro
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
    
    // Aplicando OCTAEDRO ao tabuleiro
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
    printf("=================================================\n");
    printf("### Tabuleiro Batalha Naval (Nivel Mestre) ###\n");
    printf("=================================================\n");
    printf("Legenda: 0 = Agua | 3 = Navio | 5 = Area de Efeito\n\n");
    
    // Exibe indices das colunas
    printf("   ");
    for (j = 0; j < TAMANHO; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    // Exibe o tabuleiro linha por linha
    for (i = 0; i < TAMANHO; i++) {
        printf("%d  ", i); // Indice da linha
        for (j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]); 
        }
        printf("\n");
    }
    
    printf("\n=================================================\n");
    printf("Posicoes das Habilidades:\n");
    printf("- Cone:     Linha %d, Coluna %d\n", cone_origem_i, cone_origem_j);
    printf("- Cruz:     Linha %d, Coluna %d\n", cruz_origem_i, cruz_origem_j);
    printf("- Octaedro: Linha %d, Coluna %d\n", octa_origem_i, octa_origem_j);
    printf("=================================================\n");

    return 0;
}
