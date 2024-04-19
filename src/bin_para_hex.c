#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin_para_hex.h"

// Função para converter uma instrução binária em hexadecimal
char* binarioParaHex(const char *binario) {
    static const char hex[] = "0123456789ABCDEF";
    char *stringHex = malloc(9 * sizeof(char)); // 4 bytes (32 bits) + 1 espaço + 1 para o caractere nulo
    if (stringHex == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    unsigned int valor = (unsigned int) strtol(binario, NULL, 2); // Converte binário para inteiro
    sprintf(stringHex, "%08X", valor); // Converte inteiro para hexadecimal com 8 dígitos

    return stringHex;
}

// Função para ler o arquivo de entrada em formato .asm e escrever o arquivo de saída em hexadecimal
void binParaHex(FILE *arquivoSaidaBin, FILE *arquivoSaidaHex) {
    
    char linha[100]; // Armazena cada linha do arquivo
    char instrucaoBinaria[33]; // Armazena a instrução binária (32 bits) + 1 para o caractere nulo

    // Processar cada linha do arquivo de entrada
    while (fgets(linha, sizeof(linha), arquivoSaidaBin) != NULL) {
        // Mostrar a linha lida do arquivo de entrada binário
        printf("Linha lida do arquivo de entrada binário: %s", linha);

        // Converter a linha para binário (supondo que cada linha já está em formato binário)
        sscanf(linha, "%32s", instrucaoBinaria);

        // Converter a instrução binária para hexadecimal
        char *stringHex = binarioParaHex(instrucaoBinaria);

        // Escrever a instrução hexadecimal no arquivo de saída
        fprintf(arquivoSaidaHex, "%s\n", stringHex);

        // Liberar a memória alocada para a string hexadecimal
        free(stringHex);
    }
}
