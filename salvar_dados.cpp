#include "classes.h"
#include <fstream>
#include <iostream>
#include <vector>

// Passageiro
void salvarPassageirosEmPlanilha(const std::vector<Passageiro *> &passageiros,
                                 const std::string &arquivo) {
  std::ofstream planilha(arquivo);

  if (!planilha.is_open()) {
    std::cerr << "Erro ao abrir o arquivo: " << arquivo << "\n";
    return;
  }

  planilha << "Nome,Cidade Atual\n";

  for (Passageiro *passageiro : passageiros) {
    std::string cidadeAtual = (passageiro->getCidadeAtual() != nullptr)
                                  ? passageiro->getCidadeAtual()->getNome()
                                  : "Sem cidade";
    planilha << passageiro->getNome() << "," << cidadeAtual << "\n";
  }

  planilha.close();
  std::cout << "Passageiros salvos em: " << arquivo << "\n";
}

// Cidadse
void salvarCidadesEmPlanilha(const std::vector<Cidade *> &cidades,
                             const std::string &arquivo) {
  std::ofstream planilha(arquivo);

  if (!planilha.is_open()) {
    std::cerr << "Erro ao abrir o arquivo: " << arquivo << "\n";
    return;
  }

  planilha << "Nome\n";

  if (cidades.empty()) {
    std::cerr << "Nenhuma cidade cadastrada para salvar.\n";
  }

  for (Cidade *cidade : cidades) {
    planilha << cidade->getNome() << "\n";
  }

  planilha.close();
  std::cout << "Cidades salvas em: " << arquivo << "\n";
}

// Transporte
void salvarTransportesEmPlanilha(const std::vector<Transporte *> &transportes,
                                 const std::string &arquivo) {
  std::ofstream planilha(arquivo);

  if (!planilha.is_open()) {
    std::cerr << "Erro ao abrir o arquivo: " << arquivo << "\n";
    return;
  }

  planilha << "Nome,Tipo,Capacidade,Velocidade (Km/h),Cidade Atual\n";

  for (Transporte *transporte : transportes) {
    std::string cidadeAtual = (transporte->getCidadeAtual() != nullptr)
                                  ? transporte->getCidadeAtual()->getNome()
                                  : "Em trânsito";
    planilha << transporte->getNome() << "," << transporte->getTipo() << ","
             << transporte->getCapacidade() << ","
             << transporte->getVelocidade() << "," << cidadeAtual << "\n";
  }

  planilha.close();
  std::cout << "Transportes salvos em: " << arquivo << "\n";
}
