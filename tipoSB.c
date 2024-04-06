#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "instrucoes.h"
#include "tipoI.h"
#include "tipoR.h"
#include "tipoS.h"
#include "tipoSB.h"

int obterInstrucaoTipoSB(struct TabelaInstrucoes *tabela, char *nomeInstrucao, char *regDestino, char *offset, char *regEndBase, FILE *arquivoSaida){
    
    // Variáveis
    char binario_regDestino[6];
    char binario_offset[10];
    char binario_endBase[13];
    

    // Chamando a função para converter o registrador para binário
    registrador_para_binario(regDestino, binario_regDestino, 5);
    registrador_para_binario(regEndBase, binario_endBase, 5);
    registrador_para_binario(offset, binario_offset, 12);


    printf("\nO registrador %s em binário é: %s\n", regDestino, binario_regDestino);
    printf("O registrador de endereço base %s em binário é: %s\n", regEndBase, binario_endBase);
    printf("O offset %s em binário é: %s\n", offset, binario_offset);
    
    // Variáveis para armazenar as partes separadas do offset
    char parte_bit12[2];
    char parte_bits10_5[6];
    char parte_bit11[2];
    char parte_bits4_1[5];

    // Copiando a parte do bit 12
    strncpy(parte_bit12, binario_offset + 0, 1);
    parte_bit12[1] = '\0'; // Adiciona o terminador de string

    // Copiando a parte dos bits 10 a 5
    strncpy(parte_bits10_5, binario_offset + 2, 6);
    parte_bits10_5[6] = '\0'; // Adiciona o terminador de string

    // Copiando a parte do bit 11
    strncpy(parte_bit11, binario_offset + 1, 1);
    parte_bit11[1] = '\0'; // Adiciona o terminador de string

    // Copiando a parte dos bits 4 a 1
    strncpy(parte_bits4_1, binario_offset + 5, 4);
    parte_bits4_1[4] = '\0'; // Adiciona o terminador de string

    // Imprimindo as partes separadas do offset
    printf("Bit 12: %s\n", parte_bit12);
    printf("Bits 10 a 5: %s\n", parte_bits10_5);
    printf("Bit 11: %s\n", parte_bit11);
    printf("Bits 4 a 1: %s\n", parte_bits4_1);

    if (strcmp(nomeInstrucao, "bne") == 0){

        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[0]);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s%s%s%s\n", parte_bit12, parte_bits10_5, regDestino, regEndBase, tabela->funct3[0], parte_bits4_1, parte_bit11, tabela->opcode);

    } else if (strcmp(nomeInstrucao, "beq") == 0){

        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[1]);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s%s%s%s\n", parte_bit12, parte_bits10_5, regDestino, regEndBase, tabela->funct3[1], parte_bits4_1, parte_bit11, tabela->opcode);
        
    }

    else {
        // Instrução não suportada
        printf("Instrução %s não suportada\n", nomeInstrucao);
        return 0; // Instrução não encontrada
    }

    return 1;
}