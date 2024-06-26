#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "instrucoes.h"
#include "tipoI.h"
#include "tipoR.h"
#include "tipoS.h"
#include "tipoSB.h"
#include "bin_para_hex.h"

#define ARQUIVO_ENTRADA "entrada.asm"
#define ARQUIVO_SAIDA "saida_bin.asm"
#define ARQUIVO_SAIDA_HEX "saida_hex.asm"

/* 
    TIPO I
    lb, lh, lw, addi, andi, ori
    
    TIPO S
    sb, sh, sw 

    TIPO R
    add, sub, and, or, xor, sll, srl 

    TIPO SB
    bne, beq

    PSEUDO INSTRUÇÕES
    mv
*/

int main() {

    /**************************************************************

                            Variáveis                                

    **************************************************************/
    char linha[100];
    char nomeInstrucao[20];
    char regDestino[6];
    char regFonte1[13];
    char regFonte2[13];
    char offset[13];
    
    /**************************************************************

                            Arquivos                                

    **************************************************************/
    FILE *arquivoEntrada;
    FILE *arquivoSaidaBin;
    FILE *arquivoSaidaHex;

    // Caminho das pastas de saída
    char pastaSaidas[100];
    strcpy(pastaSaidas, "saidas/"); // Pasta raiz onde os arquivos serão salvos

    // Caminho do arquivo de saída binário
    char caminhoArquivoBin[100]; 
    strcpy(caminhoArquivoBin, pastaSaidas);
    strcat(caminhoArquivoBin, ARQUIVO_SAIDA);

    // Caminho do arquivo de saída hexadecimal
    char caminhoArquivoHex[100]; 
    strcpy(caminhoArquivoHex, pastaSaidas);
    strcat(caminhoArquivoHex, ARQUIVO_SAIDA_HEX);

    // Abrir arquivo de entrada
    arquivoEntrada = fopen(ARQUIVO_ENTRADA, "r");
    if (arquivoEntrada == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    /*ABRINDO OS ARQUIVOS DE SAÍDA*/

    // Instruções em binário
    arquivoSaidaBin = fopen(caminhoArquivoBin, "w");
    if (arquivoSaidaBin == NULL) {
        printf("Erro ao abrir o arquivo de saída binário.\n");
        return 0; // Indica que ocorreu um erro
    }

    // Instruções em hexadecimal
    arquivoSaidaHex = fopen(caminhoArquivoHex, "w");
    if (arquivoSaidaHex == NULL) {
        printf("Erro ao abrir o arquivo de saída hexadecimal.\n");
        return 0; // Indica que ocorreu um erro
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

        printf("\n---------------------------------------------------\n");
        printf("->%s", linha);

        sscanf(linha,"%s", nomeInstrucao);
        
        // TIPO S
        if (strcmp(nomeInstrucao, "sb") == 0 || strcmp(nomeInstrucao, "sh") == 0 || strcmp(nomeInstrucao, "sw") == 0) {

            sscanf(linha, "%s %[^,], %[^(](%[^)])", nomeInstrucao, regDestino, offset, regFonte1);            

            if (obterInstrucaoTipoS(&tabelaTipoS, nomeInstrucao, regDestino, offset, regFonte1, arquivoSaidaBin)!= 1) {
                printf("Instrução %s não encontrada\n", nomeInstrucao);
            }            
        }        

        sscanf(linha, "%s %[^,], %[^,], %[^,]", nomeInstrucao, regDestino, regFonte1, regFonte2);
        
        // Verificar o tipo da instrução e obter as informações da tabela correspondente

        //TIPO I
        if(strcmp(nomeInstrucao, "lw") == 0 || strcmp(nomeInstrucao, "lb") == 0 || strcmp(nomeInstrucao, "lh") == 0){

            sscanf(linha, "%s %[^,], %[^(](%[^)])", nomeInstrucao, regDestino, offset, regFonte1);            

            if (obterInstrucaoTipoI(&tabelaTipoI, nomeInstrucao, regDestino, offset, regFonte1, arquivoSaidaBin)!= 1) {
                printf("Instrução %s não encontrada\n", nomeInstrucao);
            }

        } else if (strcmp(nomeInstrucao, "addi") == 0 || strcmp(nomeInstrucao, "andi") == 0 || strcmp(nomeInstrucao, "ori") == 0) {

            if (obterInstrucaoTipoI(&tabelaTipoI, nomeInstrucao, regDestino, regFonte1, regFonte2, arquivoSaidaBin)!= 1) {
                printf("Instrução %s não encontrada\n", nomeInstrucao);
            }

        // TIPO R
        } else if (strcmp(nomeInstrucao, "add") == 0 || strcmp(nomeInstrucao, "sub") == 0 || strcmp(nomeInstrucao, "and") == 0 || strcmp(nomeInstrucao, "or") == 0 || strcmp(nomeInstrucao, "xor") == 0 || strcmp(nomeInstrucao, "sll") == 0 ||
        strcmp(nomeInstrucao, "srl") == 0) {
                    
            if (obterInstrucaoTipoR(&tabelaTipoR, nomeInstrucao, regDestino, regFonte1, regFonte2, arquivoSaidaBin)!= 1) {
                printf("Instrução %s não encontrada\n", nomeInstrucao);
            }
        
        // TIPO SB
        } else if(strcmp(nomeInstrucao, "bne") == 0 || strcmp(nomeInstrucao, "beq") == 0){

            if (obterInstrucaoTipoSB(&tabelaTipoSB, nomeInstrucao, regDestino, regFonte1, regFonte2, arquivoSaidaBin)!= 1) {
                printf("Instrução %s não encontrada\n", nomeInstrucao);
            }


        // PSEUDO CÓDIGO
        } else if (strcmp(nomeInstrucao, "mv") == 0) {
            // "mv" é equivalente a "add" em RISC-V
            if (obterInstrucaoTipoR(&tabelaTipoR, "add", regDestino, regFonte1, "x0", arquivoSaidaBin)!= 1) {
                printf("Erro ao obter instrução 'mv'.\n");

            }
        } else {
            // Instrução não suportada
            printf("Instrução %s não suportada\n", nomeInstrucao);
            return 0; // Instrução não encontrada
        }
    }

    // Fecha o aqruivo de saída em binário para abrir em modo leitura
    fclose(arquivoSaidaBin);

    // Abrindo o arquivo de instruções em binário agora em modo leitura
    arquivoSaidaBin = fopen(caminhoArquivoBin, "r");
    if (arquivoSaidaBin == NULL) {
        printf("Erro ao abrir o arquivo de saída binário.\n");
        return 0; // Indica que ocorreu um erro
    }
    
    // Chamando a função para converter e escrever a saída no arquivo de saída
    binParaHex(arquivoSaidaBin, arquivoSaidaHex);
    

    // Fechar arquivos
    fclose(arquivoEntrada);
    fclose(arquivoSaidaHex);

    return 0;
}
