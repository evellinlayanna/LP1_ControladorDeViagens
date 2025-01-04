#ifndef CARREGAR_DADOS_H
#define CARREGAR_DADOS_H

#include "classes.h"
#include <string>
#include <vector>

// Função para carregar dados dos arquivos CSV
void carregarDados(std::vector<Cidade *> &cidades,
                   std::vector<Passageiro *> &passageiros,
                   std::vector<Transporte *> &transportes,
                   const std::string &cidadesFile,
                   const std::string &passageirosFile,
                   const std::string &transportesFile);

#endif // CARREGAR_DADOS_H
