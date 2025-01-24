#ifndef SALVAR_DADOS_H
#define SALVAR_DADOS_H

#include "classes.h"
#include <string>
#include <vector>

void salvarPassageirosEmPlanilha(const std::vector<Passageiro *> &passageiros,
                                 const std::string &arquivo);
void salvarTransportesEmPlanilha(const std::vector<Transporte *> &transportes,
                                 const std::string &arquivo);
void salvarCidadesEmPlanilha(const std::vector<Cidade *> &cidades,
                             const std::string &arquivo);
void salvarTrajetosEmPlanilha(const std::vector<Trajeto *> &trajetos,
                              const std::string &arquivo);
void salvarViagensEmPlanilha(const std::vector<Viagem *> &viagens,
                             const std::string &arquivo);

#endif // SALVAR_DADOS_H
