#include <stdio.h> // Biblioteca padrao para entrada e saida de dados

// Define o tamanho do tabuleiro (10x10)
#define TAMANHO 10

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
int main() {
    
    // Nível Novato - Posicionamento dos Navios
    // (O Nivel Aventureiro continua a partir daqui)
    
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
    
    // --- Navio 1: Horizontal (Tamanho 3) --- 
    // Vamos colocar na linha 1, comecando da coluna 1
    // Ocupara as posicoes: [1][1], [1][2], [1][3]
    int navioH_linha = 1;
    int navioH_coluna = 1;

    for (j = 0; j < 3; j++) { // Loop para preencher as 3 posicoes
        // Valida se o navio cabe no tabuleiro
        if (navioH_coluna + j < TAMANHO) {
            tabuleiro[navioH_linha][navioH_coluna + j] = 3; // 
        }
    }

    // --- Navio 2: Vertical (Tamanho 3) --- 
    // Vamos colocar na coluna 5, comecando da linha 3
    // Ocupara as posicoes: [3][5], [4][5], [5][5]
    int navioV_linha = 3;
    int navioV_coluna = 5;
        
    for (i = 0; i < 3; i++) { // Loop para preencher as 3 posicoes
        // Valida se o navio cabe no tabuleiro
        if (navioV_linha + i < TAMANHO) {
            tabuleiro[navioV_linha + i][navioV_coluna] = 3;
        }
    }


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    
    // --- Navio 3: Diagonal (Tamanho 3) --- 
    // Tipo: linha e coluna aumentam (Ex: [i][i])
    // Vamos colocar comecando em [3][1]
    // Ocupara as posicoes: [3][1], [4][2], [5][3]
    int navioD1_linha = 3;
    int navioD1_coluna = 1;
    
    for (i = 0; i < 3; i++) {
        // Precisa validar os dois limites (linha e coluna) [cite: 59]
        if (navioD1_linha + i < TAMANHO && navioD1_coluna + i < TAMANHO) {
            // Escolhemos posicoes que nao sobrepoem 
            tabuleiro[navioD1_linha + i][navioD1_coluna + i] = 3;
        }
    }

    // --- Navio 4: Diagonal (Tamanho 3) --- 
    // Tipo: linha diminui e coluna aumenta (Ex: [i][9-i])
    // Vamos colocar comecando em [7][7]
    // Ocupara as posicoes: [7][7], [6][8], [5][9]
    int navioD2_linha = 7;
    int navioD2_coluna = 7;

    for (i = 0; i < 3; i++) {
        // Valida os limites (linha diminuindo, coluna aumentando)
        if (navioD2_linha - i >= 0 && navioD2_coluna + i < TAMANHO) {
            // Escolhemos posicoes que nao sobrepoem 
            tabuleiro[navioD2_linha - i][navioD2_coluna + i] = 3;
        }
    }
    

    // 4. Exibe o Tabuleiro no console
    //
    printf("### Tabuleiro Batalha Naval (Nivel Aventureiro) ###\n\n");
    
    for (i = 0; i < TAMANHO; i++) { // Loop para as linhas
        for (j = 0; j < TAMANHO; j++) { // Loop para as colunas
            
            // Imprime o valor da posicao e um espaco para separar
            printf("%d ", tabuleiro[i][j]); 
        }
        
        // Pula uma linha ao final de cada linha da matriz
        printf("\n");
    }


    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.
    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}

























    








































      



























    












