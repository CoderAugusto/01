#include "instrucoes.h"

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
    

void registrador_para_binario(char *reg, char *binario) {
    // Extrai o número do registrador, começando a partir do índice 1
    int numero = atoi(reg + 1);

    // Converte o número para sua representação binária de 5 bits
    for (int i = 4; i >= 0; i--) {
        binario[i] = (numero % 2) + '0'; // Converte o dígito binário para caractere
        numero /= 2;
    }
    
    binario[5] = '\0'; // Adiciona o terminador de string
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


int obterInstrucao(struct TabelaInstrucoes *tabela, char *nomeInstrucao, char *regDestino, char *regFonte1, char *regFonte2, FILE *arquivoSaida) {

    // Variáveis
    char binario_regDestino[6];
    char binario_regFonte1[6];
    char binario_regFonte2[12];
    char binario_imediato[13];

    // Chamando a função para converter o registrador para binário
    registrador_para_binario(regDestino, binario_regDestino);
    registrador_para_binario(regFonte1, binario_regFonte1);
    registrador_para_binario(regFonte2, binario_regFonte2);


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
    


    /**************************************************************

                                TIPO S

    OBS precisa montar o código de máquina                                

    **************************************************************/
    else if (strcmp(nomeInstrucao, "sb") == 0){

        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[0]);




    }else if (strcmp(nomeInstrucao, "sh") == 0) {
        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[1]);
    
        // Convertendo imediato para binário
        imediato_para_binario(regFonte2, binario_imediato);
        printf("O imediato %s em binário de 12 bits é: %s\n", regFonte2, binario_imediato);
    
        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s\n", binario_imediato, binario_regFonte1, tabela->funct3[7], binario_regDestino, tabela->opcode);
    
        // Verifica se houve erro durante a escrita
        if (ferror(arquivoSaida)) {
            printf("Erro ao escrever no arquivo de saída.\n");
            return 0; // Indica que ocorreu um erro
        }
    }  
    
   else if (strcmp(nomeInstrucao, "sw") == 0) {
        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[2]);
    
        // Escreve no arquivo de saída
        fprintf(arquivoSaida, "%s%s%s%s%s\n", binario_imediato, binario_regFonte1, tabela->funct3[6], binario_regDestino, tabela->opcode);
    
        // Verifica se houve erro durante a escrita
        if (ferror(arquivoSaida)) {
            printf("Erro ao escrever no arquivo de saída.\n");
            return 0; // Indica que ocorreu um erro
        }
    }

    /**************************************************************

                                TIPO R                                

    **************************************************************/
    else if (strcmp(nomeInstrucao, "add") == 0){
        
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

    

    /**************************************************************

                                TIPO SB

    OBS precisa ainda montar o código de máquina                             

    **************************************************************/
    } else if (strcmp(nomeInstrucao, "bne") == 0){

        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[0]);

    } else if (strcmp(nomeInstrucao, "beq") == 0){

        printf("opcode: %s\n", tabela->opcode);
        printf("funct3: %s\n", tabela->funct3[1]);
        
    }

    else {
        // Instrução não suportada
        printf("Instrução %s não suportada\n", nomeInstrucao);
        return 0; // Instrução não encontrada
    }

    return 1;
    
}
