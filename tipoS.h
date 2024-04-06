#ifndef INSTRUCOESTIPOS_H
#define INSTRUCOESTIPOS_H

#include "instrucoes.h"

int obterInstrucaoTipoS(struct TabelaInstrucoes *tabela, char *nomeInstrucao, char *regDestino, char *offset, char *regFonte1, FILE *arquivoSaida);

#endif /* INSTRUCOESTIPOS_H */