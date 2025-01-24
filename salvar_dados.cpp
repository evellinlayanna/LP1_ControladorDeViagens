#include "classes.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

// Passageiros
void salvarPassageirosEmPlanilha(const std::vector<Passageiro *> &passageiros,
                                 const std::string &arquivo) {
  if (passageiros.empty()) {
    std::cerr << "Nenhum passageiro cadastrado para salvar.\n";
    return;
  }

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

// Cidades
void salvarCidadesEmPlanilha(const std::vector<Cidade *> &cidades,
                             const std::string &arquivo) {
  if (cidades.empty()) {
    std::cerr << "Nenhuma cidade cadastrada para salvar.\n";
    return;
  }

  std::ofstream planilha(arquivo);

  if (!planilha.is_open()) {
    std::cerr << "Erro ao abrir o arquivo: " << arquivo << "\n";
    return;
  }

  planilha << "Nome\n";

  for (Cidade *cidade : cidades) {
    planilha << cidade->getNome() << "\n";
  }

  planilha.close();
  std::cout << "Cidades salvas em: " << arquivo << "\n";
}

// Transportes
void salvarTransportesEmPlanilha(const std::vector<Transporte *> &transportes,
                                 const std::string &arquivo) {
  if (transportes.empty()) {
    std::cerr << "Nenhum transporte cadastrado para salvar.\n";
    return;
  }

  std::ofstream planilha(arquivo);

  if (!planilha.is_open()) {
    std::cerr << "Erro ao abrir o arquivo: " << arquivo << "\n";
    return;
  }

  planilha << "Nome,Tipo,Capacidade,Velocidade (Km/h), "
              "DistanciaEntreDescansos,TempoDeDescanso, Cidade Atual\n";

  for (Transporte *transporte : transportes) {
    std::string cidadeAtual = (transporte->getCidadeAtual() != nullptr)
                                  ? transporte->getCidadeAtual()->getNome()
                                  : "Em trânsito";
    planilha << transporte->getNome() << "," << transporte->getTipo() << ","
             << transporte->getCapacidade() << ","
             << transporte->getVelocidade() << ","
             << transporte->getDistanciaEntreDescansos() << ","
             << transporte->getTempoDeDescanso() << "," << cidadeAtual << "\n";
  }

  planilha.close();
  std::cout << "Transportes salvos em: " << arquivo << "\n";
}

// Trajetos
void salvarTrajetosEmPlanilha(const std::vector<Trajeto *> &trajetos,
                              const std::string &arquivo) {
  if (trajetos.empty()) {
    std::cerr << "Nenhum trajeto cadastrado para salvar.\n";
    return;
  }

  std::ofstream planilha(arquivo);

  if (!planilha.is_open()) {
    std::cerr << "Erro ao abrir o arquivo: " << arquivo << "\n";
    return;
  }
  planilha << "Cidade Origem,Cidade Destino,Tipo,Distância (Km)\n";

  for (Trajeto *trajeto : trajetos) {
    std::string origem =
        trajeto->getOrigem() ? trajeto->getOrigem()->getNome() : "Sem origem";
    std::string destino = trajeto->getDestino()
                              ? trajeto->getDestino()->getNome()
                              : "Sem destino";
    std::string tipo = trajeto->getTipo() == 'A' ? "Aquático" : "Terrestre";

    planilha << origem << "," << destino << "," << tipo << ","
             << trajeto->getDistancia() << "\n";
  }

  planilha.close();
  std::cout << "Trajetos salvos em: " << arquivo << "\n";
}

// Viagens
void salvarViagensEmPlanilha(const std::vector<Viagem *> &viagens,
                             const std::string &arquivo) {
  std::ofstream planilha(arquivo);
  if (!planilha.is_open()) {
    std::cerr << "Erro ao abrir o arquivo de viagens: " << arquivo << "\n";
    return;
  }

  planilha << "Trajeto,Transporte,Passageiro,DataHoraPartida\n";

  for (const Viagem *viagem : viagens) {
    Trajeto *trajeto = viagem->getTrajeto();
    Transporte *transporte = viagem->getTransporte();

    for (Passageiro *passageiro : viagem->getPassageiros()) {
      planilha << trajeto->getOrigem()->getNome() << " - "
               << trajeto->getDestino()->getNome() << ","
               << transporte->getNome() << "," << passageiro->getNome() << ","
               << viagem->getDataHoraPartida() << "\n";
    }
  }

  planilha.close();
  std::cout << "Viagens salvas com sucesso em: " << arquivo << "\n";
}
