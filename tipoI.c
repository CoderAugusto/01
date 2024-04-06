#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "instrucoes.h"
#include "tipoI.h"
#include "tipoR.h"
#include "tipoS.h"
#include "tipoSB.h"

int obterInstrucaoTipoI(struct TabelaInstrucoes *tabela, char *nomeInstrucao, char *regDestino, char *regFonte1, char *regFonte2, FILE *arquivoSaida) {

    // Variáveis
    char binario_regDestino[6];
    char binario_regFonte1[6];
    char binario_regFonte2[12];
    char binario_imediato[13];

    // Chamando a função para converter o registrador para binário
    registrador_para_binario(regDestino, binario_regDestino, 5);
    registrador_para_binario(regFonte1, binario_regFonte1, 5);
    registrador_para_binario(regFonte2, binario_regFonte2, 12);


    printf("\nO registrador %s em binário é: %s\n", regDestino, binario_regDestino);
    printf("O registrador %s em binário é: %s\n", regFonte1, binario_regFonte1);
    printf("O registrador %s em binário é: %s\n", regFonte2, binario_regFonte2);


    /**************************************************************

                                TIPO I                                

    **************************************************************/

    // Verificar o nome da instrução e executar ação correspondente
    if (strcmp(nomeInstrucao, "lb") == 0) {

        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[0]);

        // Convertendo imediato para binário
        imediato_para_binario(regFonte2, binario_imediato);
        printf("O imediato %s em binário de 12 bits é: %s\n", regFonte2, binario_imediato);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s\n", binario_imediato, binario_regFonte1, tabela->funct3[0], binario_regDestino, tabela->opcode);
        
        // Verifica se houve erro durante a escrita
        if (ferror(arquivoSaida)) {
            printf("Erro ao escrever no arquivo de saída.\n");
            return 0; // Indica que ocorreu um erro
        }
        
    }
    else if (strcmp(nomeInstrucao, "lh") == 0) {
        
        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[1]);

        // Convertendo imediato para binário
        imediato_para_binario(regFonte2, binario_imediato);
        printf("O imediato %s em binário de 12 bits é: %s\n", regFonte2, binario_imediato);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s\n", binario_imediato, binario_regFonte1, tabela->funct3[1], binario_regDestino, tabela->opcode);
        
        // Verifica se houve erro durante a escrita
        if (ferror(arquivoSaida)) {
            printf("Erro ao escrever no arquivo de saída.\n");
            return 0; // Indica que ocorreu um erro
        }
    }
    else if (strcmp(nomeInstrucao, "lw") == 0) {

        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[2]);

        // Convertendo imediato para binário
        imediato_para_binario(regFonte2, binario_imediato);
        printf("O imediato %s em binário de 12 bits é: %s\n", regFonte2, binario_imediato);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s\n", binario_imediato, binario_regFonte1, tabela->funct3[2], binario_regDestino, tabela->opcode);
        
        // Verifica se houve erro durante a escrita
        if (ferror(arquivoSaida)) {
            printf("Erro ao escrever no arquivo de saída.\n");
            return 0; // Indica que ocorreu um erro
        }
    }
    else if (strcmp(nomeInstrucao, "addi") == 0) {

        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[3]);
        
        // Convertendo imediato para binário
        imediato_para_binario(regFonte2, binario_imediato);
        printf("O imediato %s em binário de 12 bits é: %s\n", regFonte2, binario_imediato);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s\n", binario_imediato, binario_regFonte1, tabela->funct3[3], binario_regDestino, tabela->opcode);
        
        // Verifica se houve erro durante a escrita
        if (ferror(arquivoSaida)) {
            printf("Erro ao escrever no arquivo de saída.\n");
            return 0; // Indica que ocorreu um erro
        }

    }
    else if (strcmp(nomeInstrucao, "andi") == 0) {
        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[4]);

        // Convertendo imediato para binário
        imediato_para_binario(regFonte2, binario_imediato);
        printf("O imediato %s em binário de 12 bits é: %s\n", regFonte2, binario_imediato);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s\n", binario_imediato, binario_regFonte1, tabela->funct3[4], binario_regDestino, tabela->opcode);
        
        // Verifica se houve erro durante a escrita
        if (ferror(arquivoSaida)) {
            printf("Erro ao escrever no arquivo de saída.\n");
            return 0; // Indica que ocorreu um erro
        }
        
    }
    else if (strcmp(nomeInstrucao, "ori") == 0) {
        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[5]);

        // Convertendo imediato para binário
        imediato_para_binario(regFonte2, binario_imediato);
        printf("O imediato %s em binário de 12 bits é: %s\n", regFonte2, binario_imediato);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s\n", binario_imediato, binario_regFonte1, tabela->funct3[5], binario_regDestino, tabela->opcode);
        
        // Verifica se houve erro durante a escrita
        if (ferror(arquivoSaida)) {
            printf("Erro ao escrever no arquivo de saída.\n");
            return 0; // Indica que ocorreu um erro
        }
    }

    else {
        // Instrução não suportada
        printf("Instrução %s não suportada\n", nomeInstrucao);
        return 0; // Instrução não encontrada
    }

    return 1;
    
}