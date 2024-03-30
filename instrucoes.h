#ifndef INSTRUCOES_H
#define INSTRUCOES_H

#include <stdio.h>

struct TabelaInstrucoes {
    char *nome[10];
    char *opcode;
    char *tipo;
    char *funct3[8];
    char *funct7[8];
};

int obterInstrucao(struct TabelaInstrucoes *tabela, char *nomeInstrucao, char *regDestino, char *regFonte1, char *regFonte2, FILE *arquivoSaida);
void registrador_para_binario(char *reg, char *binario);
void inteiro_para_binario(int numero, char *binario, int bits);
void imediato_para_binario(char *imediato, char *binario);
void escrever_no_arquivo(FILE *arquivo, const char *codigo_maquina);


#endif /* INSTRUCOES_H */
