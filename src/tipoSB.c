#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "instrucoes.h"
#include "tipoI.h"
#include "tipoR.h"
#include "tipoS.h"
#include "tipoSB.h"

int obterInstrucaoTipoSB(struct TabelaInstrucoes *tabela, char *nomeInstrucao, char *regFonte1, char *regFonte2, char *regEndDestino, FILE *arquivoSaida){
    
    // Variáveis
    char binario_regFonte1[6];
    char binario_regFonte2[6];
    char binario_EndDestino[13];
    

    // Chamando a função para converter o registrador para binário
    registrador_para_binario(regFonte1, binario_regFonte1, 5);
    registrador_para_binario(regFonte2, binario_regFonte2, 5);
    imediato_para_binario(regEndDestino, binario_EndDestino);

    /*
    printf("\nO registrador %s em binário é: %s\n", regFonte1, binario_regFonte1);
    printf("O registrador %s em binário é: %s\n", regFonte2, binario_regFonte2);
    printf("O endereço da label %s em binário é: %s\n", regEndDestino, binario_EndDestino);
    */
    
    // Variáveis para armazenar as partes separadas do endereço do label
    char parte_bit12[2];
    char parte_bits10_5[6];
    char parte_bit11[2];
    char parte_bits4_0[6];

    // Copiando a parte do bit 12
    strncpy(parte_bit12, binario_EndDestino, 1);
    parte_bit12[1] = '\0'; // Adiciona o terminador de string

    // Copiando a parte do bit 11
    strncpy(parte_bit11, binario_EndDestino + 1, 1);
    parte_bit11[1] = '\0'; // Adiciona o terminador de string

    // Copiando a parte dos bits 10 a 5
    strncpy(parte_bits10_5, binario_EndDestino + 2, 5);
    parte_bits10_5[5] = '\0'; // Adiciona o terminador de string

    // Copiando a parte dos bits 4 a 0
    strncpy(parte_bits4_0, binario_EndDestino + 7, 5);
    parte_bits4_0[5] = '\0'; // Adiciona o terminador de string

    /*
    // Imprimir as partes separadas
    printf("Bit 12: %s\n", parte_bit12);
    printf("Bits 10 a 5: %s\n", parte_bits10_5);
    printf("Bit 11: %s\n", parte_bit11);
    printf("Bits 4 a 0: %s\n", parte_bits4_0);
    */

    if (strcmp(nomeInstrucao, "bne") == 0){

        //printf("opcode: %s\n", tabela->opcode);
        //printf("funct3: %s\n", tabela->funct3[0]);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s%s%s%s\n", parte_bit12, parte_bits10_5, binario_regFonte1, binario_regFonte2, tabela->funct3[0], parte_bits4_0, parte_bit11, tabela->opcode);

    } else if (strcmp(nomeInstrucao, "beq") == 0){

        //printf("opcode: %s\n", tabela->opcode);
        //printf("funct3: %s\n", tabela->funct3[1]);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s%s%s%s\n", parte_bit12, parte_bits10_5, binario_regFonte2, binario_regFonte1, tabela->funct3[1], parte_bits4_0, parte_bit11, tabela->opcode);
        
    }

    else {
        // Instrução não suportada
        printf("Instrução %s não suportada\n", nomeInstrucao);
        return 0; // Instrução não encontrada
    }

    return 1;
}