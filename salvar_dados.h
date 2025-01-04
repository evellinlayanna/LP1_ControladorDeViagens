#ifndef SALVAR_DADOS_H
#define SALVAR_DADOS_H

#include <vector>
#include <string>
#include "classes.h"

void salvarPassageirosEmPlanilha(const std::vector<Passageiro*>& passageiros, const std::string& arquivo);
void salvarTransportesEmPlanilha(const std::vector<Transporte*>& transportes, const std::string& arquivo);
void salvarCidadesEmPlanilha(const std::vector<Cidade*>& cidades, const std::string& arquivo);

#endif // SALVAR_DADOS_H
