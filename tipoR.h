#ifndef INSTRUCOESTIPOR_H
#define INSTRUCOESTIPOR_H

#include "instrucoes.h"

int obterInstrucaoTipoR(struct TabelaInstrucoes *tabela, char *nomeInstrucao, char *regDestino, char *regFonte1, char *regFonte2, FILE *arquivoSaida);

#endif /* INSTRUCOESTIPOR_H */