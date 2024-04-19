#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "instrucoes.h"
#include "tipoI.h"
#include "tipoR.h"
#include "tipoS.h"
#include "tipoSB.h"

int obterInstrucaoTipoS(struct TabelaInstrucoes *tabela, char *nomeInstrucao, char *regDestino, char *offset, char *regEndBase, FILE *arquivoSaida){
    
    // Variáveis
    char binario_regDestino[6];
    char binario_offset[13];
    char binario_endBase[6];

    // Variáveis para armazenar as partes separadas do offset
    char parte_superior[7];
    char parte_inferior[6];
    

    // Chamando a função para converter o registrador para binário
    registrador_para_binario(regDestino, binario_regDestino, 5);
    registrador_para_binario(regEndBase, binario_endBase, 5);
    converter_offset(offset, binario_offset);

    
    printf("\nO registrador %s em binário é: %s\n", regDestino, binario_regDestino);
    printf("O registrador de endereço base %s em binário é: %s\n", regEndBase, binario_endBase);
    printf("O offset %s em binário é: %s\n", offset, binario_offset);
    
    
    
    /*
        esta função funciona da seguinte forma: 
        char *strncpy(char *destino, const char *origem, size_t n);
            
            -> destino: É a string de destino onde os caracteres serão copiados.
            -> origem: É a string de origem da qual os caracteres serão copiados.
            -> n: É o número máximo de caracteres a serem copiados.
    */

   // Copiando a parte superior do offset (bits 11 a 5)
    strncpy(parte_superior, binario_offset, 7);
    parte_superior[7] = '\0'; // Adiciona o terminador de string

    // Copiando a parte inferior do offset (bits 4 a 0)
    strncpy(parte_inferior, binario_offset + 7, 5);
    parte_inferior[5] = '\0'; // Adiciona o terminador de string

    // Imprimindo as partes separadas do offset
    printf("Parte superior (bits 11 a 5): %s\n", parte_superior);
    printf("Parte inferior (bits 4 a 0): %s\n", parte_inferior);

    if (strcmp(nomeInstrucao, "sb") == 0){

        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[0]);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s%s\n", parte_superior, binario_regDestino, binario_endBase,tabela->funct3[0], parte_inferior, tabela->opcode);

        return 1;


    }else if (strcmp(nomeInstrucao, "sh") == 0) {

        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[1]);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s%s\n", parte_superior, binario_regDestino, binario_endBase,tabela->funct3[1], parte_inferior, tabela->opcode);


    } else if (strcmp(nomeInstrucao, "sw") == 0) {
        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[2]);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s%s\n", parte_superior, binario_regDestino, binario_endBase,tabela->funct3[2], parte_inferior, tabela->opcode);

    } else {
        // Instrução não suportada
        printf("Instrução %s não suportada\n", nomeInstrucao);
        return 0; // Instrução não encontrada
    }

    return 1;
}