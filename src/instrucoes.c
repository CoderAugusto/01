#include "instrucoes.h"

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

void converter_offset(const char *offset, char *binario_offset) {
    // Converte a string para um número inteiro
    int numero = atoi(offset);

    // Se o número for negativo, aplicamos o complemento de dois
    if (numero < 0) {
        // Convertendo para complemento de dois
        numero = (1 << 12) + numero;
    }

    // Converte o número para sua representação binária de 12 bits
    for (int i = 11; i >= 0; i--) {
        binario_offset[i] = (numero & 1) + '0'; // Converte o dígito binário para caractere
        numero >>= 1;
    }

    binario_offset[12] = '\0'; // Adiciona o terminador de string
}

void registrador_para_binario(char *reg, char *binario, int tamanho) {

    // Extrai o número do registrador, começando a partir do índice 1
    int numero = atoi(reg + 1);

    // Converte o número para sua representação binária de tamanho bits
    for (int i = tamanho - 1; i >= 0; i--) {
        binario[i] = (numero % 2) + '0'; // Converte o dígito binário para caractere
        numero /= 2;
    }
    
    binario[tamanho] = '\0'; // Adiciona o terminador de string
}


void inteiro_para_binario(int numero, char *binario, int bits) {
    // Converte o número para binário
    for (int i = bits - 1; i >= 0; i--) {
        binario[i] = (numero & 1) + '0';
        numero >>= 1;   
    }
    binario[bits] = '\0'; // Terminador de string
}

void imediato_para_binario(char *imediato, char *binario) {

    // Converte a string em um número inteiro
    int numero = atoi(imediato);


    // Se o número for negativo, aplicamos o complemento de dois
    if (numero < 0) {
        // Convertendo para complemento de dois
        numero = (1 << 12) + numero;
    }

    // Chama a função auxiliar para converter o número para binário
    inteiro_para_binario(numero, binario, 12);
}


void escrever_no_arquivo(FILE *arquivo, const char *codigo_maquina) {
    // Escreve o código de máquina no arquivo
    fprintf(arquivo, "%s\n", codigo_maquina);
    
    // Verifica se houve erro durante a escrita
    if (ferror(arquivo)) {
        printf("Erro ao escrever no arquivo de saída.\n");
    }
}