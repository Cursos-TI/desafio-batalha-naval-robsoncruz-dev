#include <stdio.h> // Biblioteca padrao para entrada e saida de dados

// Define o tamanho do tabuleiro (10x10)
#define TAMANHO 10

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
int main() {
    
    // Nível Novato - Posicionamento dos Navios
    
    // 1. Representa o Tabuleiro: Declara uma matriz 10x10
    int tabuleiro[TAMANHO][TAMANHO];
    int i, j; // Variaveis de controle para os loops (linhas e colunas)

    // 2. Inicializa todas as posicoes do tabuleiro com 0 (agua)
    // [cite: 19]
    for (i = 0; i < TAMANHO; i++) { // Loop para as linhas
        for (j = 0; j < TAMANHO; j++) { // Loop para as colunas
            tabuleiro[i][j] = 0;
        }
    }

    // 3. Posiciona os Navios (tamanho fixo 3)
    // [cite: 21, 22]
    
    // Navio 1: Horizontal (tamanho 3)
    // Vamos colocar na linha 2, comecando da coluna 1
    // Ocupara as posicoes: [2][1], [2][2], [2][3]
    int navioH_linha = 2;
    int navioH_coluna = 1;

    for (j = 0; j < 3; j++) { // Loop para preencher as 3 posicoes
        // Valida se o navio cabe no tabuleiro [cite: 29]
        if (navioH_coluna + j < TAMANHO) {
            tabuleiro[navioH_linha][navioH_coluna + j] = 3;
        }
    }

    // Navio 2: Vertical (tamanho 3)
    // Vamos colocar na coluna 5, comecando da linha 4
    // Ocupara as posicoes: [4][5], [5][5], [6][5]
    int navioV_linha = 4;
    int navioV_coluna = 5;
    
    // Validamos que os navios nao se sobrepoem apenas escolhendo
    // posicoes diferentes no codigo. [cite: 30, 39]
    
    for (i = 0; i < 3; i++) { // Loop para preencher as 3 posicoes
        // Valida se o navio cabe no tabuleiro [cite: 29]
        if (navioV_linha + i < TAMANHO) {
            tabuleiro[navioV_linha + i][navioV_coluna] = 3;
        }
    }


    // 4. Exibe o Tabuleiro no console
    // 
    printf("### Tabuleiro Batalha Naval (Nivel Novato) ###\n\n");
    
    for (i = 0; i < TAMANHO; i++) { // Loop para as linhas
        for (j = 0; j < TAMANHO; j++) { // Loop para as colunas
            
            // Imprime o valor da posicao e um espaco para separar [cite: 27]
            printf("%d ", tabuleiro[i][j]); 
        }
        
        // Pula uma linha ao final de cada linha da matriz
        printf("\n");
    }


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // ... (continua nos proximos desafios)

    // Nível Mestre - Habilidades Especiais com Matrizes
    // ... (continua nos proximos desafios)


    return 0;
}













    












