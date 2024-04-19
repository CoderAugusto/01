#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "instrucoes.h"
#include "tipoI.h"
#include "tipoR.h"
#include "tipoS.h"
#include "tipoSB.h"

int obterInstrucaoTipoR(struct TabelaInstrucoes *tabela, char *nomeInstrucao, char *regDestino, char *regFonte1, char *regFonte2, FILE *arquivoSaida) {

    // Variáveis
    char binario_regDestino[6];
    char binario_regFonte1[6];
    char binario_regFonte2[12];

    // Chamando a função para converter o registrador para binário
    registrador_para_binario(regDestino, binario_regDestino, 5);
    registrador_para_binario(regFonte1, binario_regFonte1, 5);
    registrador_para_binario(regFonte2, binario_regFonte2, 5);

    /*
    printf("\nO registrador %s em binário é: %s\n", regDestino, binario_regDestino);
    printf("O registrador %s em binário é: %s\n", regFonte1, binario_regFonte1);
    printf("O registrador %s em binário é: %s\n", regFonte2, binario_regFonte2);
    */

    if (strcmp(nomeInstrucao, "add") == 0){
        
        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[0]);
        printf("funct7: %s\n", tabela->funct7[0]);

        // Mostra na tela o código de máquina
        //printf("%s%s%s%s%s%s", tabela->funct7[0], binario_regFonte2, binario_regFonte1, tabela->funct3[0], binario_regDestino, tabela->opcode);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s%s\n", tabela->funct7[0], binario_regFonte2, binario_regFonte1, tabela->funct3[0], binario_regDestino, tabela->opcode);
        
        // Verifica se houve erro durante a escrita
        if (ferror(arquivoSaida)) {
            printf("Erro ao escrever no arquivo de saída.\n");
            return 0; // Indica que ocorreu um erro
        }       

    }
    else if (strcmp(nomeInstrucao, "sub") == 0){

        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[1]);
        printf("funct7: %s\n", tabela->funct7[1]);

        // Mostra na tela o código de máquina
        //printf("%s%s%s%s%s%s", tabela->funct7[1], binario_regFonte2, binario_regFonte1, tabela->funct3[1], binario_regDestino, tabela->opcode);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s%s\n", tabela->funct7[1], binario_regFonte2, binario_regFonte1, tabela->funct3[1], binario_regDestino, tabela->opcode);
        
        // Verifica se houve erro durante a escrita
        if (ferror(arquivoSaida)) {
            printf("Erro ao escrever no arquivo de saída.\n");
            return 0; // Indica que ocorreu um erro
        }

    }
    else if (strcmp(nomeInstrucao, "and") == 0){

        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[2]);
        printf("funct7: %s\n", tabela->funct7[2]);
        

        // Mostra na tela o código de máquina
        //printf("%s%s%s%s%s%s", tabela->funct7[2], binario_regFonte2, binario_regFonte1, tabela->funct3[2], binario_regDestino, tabela->opcode);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s%s\n", tabela->funct7[2], binario_regFonte2, binario_regFonte1, tabela->funct3[2], binario_regDestino, tabela->opcode);
        
        // Verifica se houve erro durante a escrita
        if (ferror(arquivoSaida)) {
            printf("Erro ao escrever no arquivo de saída.\n");
            return 0; // Indica que ocorreu um erro
        }
    }
    else if (strcmp(nomeInstrucao, "or") == 0){

        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[3]);
        printf("funct7: %s\n", tabela->funct7[3]);
        

        // Mostra na tela o código de máquina
        //printf("%s%s%s%s%s%s", tabela->funct7[3], binario_regFonte2, binario_regFonte1, tabela->funct3[3], binario_regDestino, tabela->opcode);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s%s\n", tabela->funct7[3], binario_regFonte2, binario_regFonte1, tabela->funct3[3], binario_regDestino, tabela->opcode);
        
        // Verifica se houve erro durante a escrita
        if (ferror(arquivoSaida)) {
            printf("Erro ao escrever no arquivo de saída.\n");
            return 0; // Indica que ocorreu um erro
        }
    }
    else if (strcmp(nomeInstrucao, "xor") == 0){

        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[4]);
        printf("funct7: %s\n", tabela->funct7[4]);
        

        // Mostra na tela o código de máquina
        //printf("%s%s%s%s%s%s", tabela->funct7[4], binario_regFonte2, binario_regFonte1, tabela->funct3[4], binario_regDestino, tabela->opcode);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s%s\n", tabela->funct7[4], binario_regFonte2, binario_regFonte1, tabela->funct3[4], binario_regDestino, tabela->opcode);
        
        // Verifica se houve erro durante a escrita
        if (ferror(arquivoSaida)) {
            printf("Erro ao escrever no arquivo de saída.\n");
            return 0; // Indica que ocorreu um erro
        }
    }
    else if (strcmp(nomeInstrucao, "sll") == 0){
        
        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[5]);
        printf("funct7: %s\n", tabela->funct7[5]);
        

        // Mostra na tela o código de máquina
        //printf("%s%s%s%s%s%s", tabela->funct7[5], binario_regFonte2, binario_regFonte1, tabela->funct3[5], binario_regDestino, tabela->opcode);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s%s\n", tabela->funct7[5], binario_regFonte2, binario_regFonte1, tabela->funct3[5], binario_regDestino, tabela->opcode);
        
        // Verifica se houve erro durante a escrita
        if (ferror(arquivoSaida)) {
            printf("Erro ao escrever no arquivo de saída.\n");
            return 0; // Indica que ocorreu um erro
        }
    }
    else if (strcmp(nomeInstrucao, "srl") == 0){

        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[6]);
        printf("funct7: %s\n", tabela->funct7[6]);
        

        // Mostra na tela o código de máquina
        //printf("%s%s%s%s%s%s", tabela->funct7[6], binario_regFonte2, binario_regFonte1, tabela->funct3[6], binario_regDestino, tabela->opcode);

        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s%s\n", tabela->funct7[6], binario_regFonte2, binario_regFonte1, tabela->funct3[6], binario_regDestino, tabela->opcode);
        
        // Verifica se houve erro durante a escrita
        if (ferror(arquivoSaida)) {
            printf("Erro ao escrever no arquivo de saída.\n");
            return 0; // Indica que ocorreu um erro
        }
    
    }
    return 1;
}

