#ifndef CARREGAR_DADOS_H
#define CARREGAR_DADOS_H

#include "classes.h"
#include <string>
#include <vector>

void carregarDados(
    std::vector<Cidade *> &cidades, std::vector<Passageiro *> &passageiros,
    std::vector<Transporte *> &transportes, std::vector<Trajeto *> &trajetos,
    std::vector<Viagem *> &viagens, const std::string &cidadesFile,
    const std::string &passageirosFile, const std::string &transportesFile,
    const std::string &trajetosFile, const std::string &viagensFile);

#endif // CARREGAR_DADOS_H
