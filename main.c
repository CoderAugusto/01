#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "instrucoes.h"

/* 
    TIPO I
    lb, lh, lw, addi, andi, ori
    
    TIPO S
    sb, sh, sw 

    TIPO R
    add, sub, and, or, xor, sll, srl 

    TIPO SB
    bne, beq
*/

int main() {

    /**************************************************************

                            Variáveis                                

    **************************************************************/
    char linha[100];
    char nomeInstrucao[20];
    char regDestino[5];
    char regFonte1[12];
    char regFonte2[12];
    char offset[10];
    
    /**************************************************************

                            Arquivos                                

    **************************************************************/
    FILE *arquivoEntrada;
    FILE *arquivoSaida;

    // Abrir arquivo de entrada
    arquivoEntrada = fopen("entrada.asm", "r");
    if (arquivoEntrada == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    arquivoSaida = fopen("saida.asm", "w");
    if (arquivoSaida == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    
    /**************************************************************

                Tabelas das instruções com as informações                             

    **************************************************************/
   
    // Tabela de instruções TIPO I
    struct TabelaInstrucoes tabelaTipoI = {
        .opcode = "0010011",
        .tipo = "I",

        //.funct7 = {lb, lh, lw, addi, andi, ori}
        .funct3 = {"000", "001", "010", "000", "111", "110"}
    };

    // Tabela de instruções TIPO S
    struct TabelaInstrucoes tabelaTipoS = {
        .opcode = "0010011",
        .tipo = "S",

        //.funct3 = {sb, sh, sw}
        .funct3 = {"000", "001", "010"},
    };

    // Tabela de instruções TIPO R
    struct TabelaInstrucoes tabelaTipoR = {
        .opcode = "0110011",
        .tipo = "R",

        //.funct3 = {add, sub, and, or, xor, sll, srl}
        .funct3 = {"000", "000", "111", "110", "100", "001", "101"},

        //.funct7 = {add, sub, and, or, xor, sll, srl}
        .funct7 = {"0000000", "0100000", "0000000", "0000000", "0000000", "0000000", "0000000"}
    };

    // Tabela de instruções TIPO SB
    struct TabelaInstrucoes tabelaTipoSB = {
        .opcode = "1100011",
        .tipo = "SB",

        //.funct3 = {bne, beq}
        .funct3 = {"001", "000"}
    };
    

    /**************************************************************

                        Código em si                                

    **************************************************************/

    // Processar cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivoEntrada) != NULL) {

        sscanf(linha,"%s", nomeInstrucao);
        
        // TIPO S
        if (strcmp(nomeInstrucao, "sb") == 0 || strcmp(nomeInstrucao, "sh") == 0 || strcmp(nomeInstrucao, "sw") == 0) {

            sscanf(linha, "%s %[^,], %[^(](%[^)])", nomeInstrucao, regDestino, offset, regFonte1);
            
            
            printf("\n\n\n");
            printf("Linha lida: %s", linha);
            printf("Instrução: %s\n", nomeInstrucao);
            printf("Registrador destino: %s\n", regDestino);
            printf("Registrador offset: %s\n", offset);
            printf("Registrador regFonte1: %s\n", regFonte1);
            

            if (obterInstrucao(&tabelaTipoS, nomeInstrucao, regDestino, offset, regFonte1, arquivoSaida)!= 1) {
                printf("Instrução %s não encontrada\n", nomeInstrucao);
            }            
        }
        

        sscanf(linha, "%s %[^,], %[^,], %[^,]", nomeInstrucao, regDestino, regFonte1, regFonte2);
        
        
        printf("\n\n\n");

        /*
        printf("Linha lida: %s", linha);
        printf("Instrução: %s\n", nomeInstrucao);
        printf("Registrador destino: %s\n", regDestino);
        printf("Registrador fonte 1: %s\n", regFonte1);
        printf("Registrador fonte 2: %s\n", regFonte2);
        */
        
            
            
        // Verificar o tipo da instrução e obter as informações da tabela correspondente

        //TIPO I
        if (strcmp(nomeInstrucao, "lb") == 0 || strcmp(nomeInstrucao, "lh") == 0 || strcmp(nomeInstrucao, "lw") == 0 ||
            strcmp(nomeInstrucao, "addi") == 0 || strcmp(nomeInstrucao, "andi") == 0 || strcmp(nomeInstrucao, "ori") == 0) {
            if (obterInstrucao(&tabelaTipoI, nomeInstrucao, regDestino, regFonte1, regFonte2, arquivoSaida)!= 1) {
                printf("Instrução %s não encontrada\n", nomeInstrucao);
            }

        // TIPO R
        } else if (strcmp(nomeInstrucao, "add") == 0 || strcmp(nomeInstrucao, "sub") == 0 || strcmp(nomeInstrucao, "and") == 0 ||
                strcmp(nomeInstrucao, "or") == 0 || strcmp(nomeInstrucao, "xor") == 0 || strcmp(nomeInstrucao, "sll") == 0 ||
                strcmp(nomeInstrucao, "srl") == 0) {
                    
            if (obterInstrucao(&tabelaTipoR, nomeInstrucao, regDestino, regFonte1, regFonte2, arquivoSaida)!= 1) {
                printf("Instrução %s não encontrada\n", nomeInstrucao);
            }

        // TIPO SB
        } else if (strcmp(nomeInstrucao, "bne") == 0 || strcmp(nomeInstrucao, "beq") == 0) {
            if (obterInstrucao(&tabelaTipoSB, nomeInstrucao, regDestino, regFonte1, regFonte2, arquivoSaida)!= 1) {
                    printf("Instrução %s não encontrada\n", nomeInstrucao);
            }

        
        // PSEUDO CÓDIGO
        } else if (strcmp(nomeInstrucao, "mv") == 0) {
            // "mv" é equivalente a "add" em RISC-V
            if (obterInstrucao(&tabelaTipoR, "add", regDestino, regFonte1, "x0", arquivoSaida)!= 1) {
                printf("Erro ao obter instrução 'mv'.\n");
            }
        } else {
            printf("Instrução %s não suportada\n", nomeInstrucao);
        }
    }
    

    // Fechar arquivo
    fclose(arquivoEntrada);

    return 0;
}
