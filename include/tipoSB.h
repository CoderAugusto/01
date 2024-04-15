#ifndef INSTRUCOESTIPOSB_H
#define INSTRUCOESTIPOSB_H

#include "instrucoes.h"

int obterInstrucaoTipoSB(struct TabelaInstrucoes *tabela, char *nomeInstrucao, char *regDestino, char *offset, char *regFonte1, FILE *arquivoSaida);

#endif /* INSTRUCOESTIPOSB_H */