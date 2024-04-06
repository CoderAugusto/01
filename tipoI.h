#ifndef INSTRUCOESTIPOI_H
#define INSTRUCOESTIPOI_H

#include "instrucoes.h"

int obterInstrucaoTipoI(struct TabelaInstrucoes *tabela, char *nomeInstrucao, char *regDestino, char *regFonte1, char *regFonte2, FILE *arquivoSaida);

#endif /* INSTRUCOESTIPOI_H */