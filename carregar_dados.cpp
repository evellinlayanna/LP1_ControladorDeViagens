#include "carregar_dados.h"
#include "classes.h"
#include <fstream>
#include <iostream>
#include <sstream>

void carregarDados(std::vector<Cidade *> &cidades,
                   std::vector<Passageiro *> &passageiros,
                   std::vector<Transporte *> &transportes,
                   const std::string &cidadesFile,
                   const std::string &passageirosFile,
                   const std::string &transportesFile) {

  // Limpar os vetores antes de carregar os dados
  cidades.clear();
  passageiros.clear();
  transportes.clear();

  // Carregar as cidades
  std::ifstream cidadesStream(cidadesFile);
  std::string linha;
  if (cidadesStream.is_open()) {
    while (std::getline(cidadesStream, linha)) {
      // Ignorar o cabeçalho ou linha vazia
      if (linha.empty() || linha == "Nome") {
        continue;
      }
      cidades.push_back(new Cidade(linha)); // Adicionar cidade ao vetor
    }
    cidadesStream.close();
  } else {
    std::cerr << "Erro ao abrir o arquivo de cidades: " << cidadesFile
              << std::endl;
  }

  // Carregar os passageiros
  std::ifstream passageirosStream(passageirosFile);
  if (passageirosStream.is_open()) {
    while (std::getline(passageirosStream, linha)) {
      // Ignorar o cabeçalho ou linha vazia
      if (linha.empty() || linha == "Nome,Cidade Atual") {
        continue;
      }

      std::stringstream ss(linha);
      std::string nome, cidadeNome;
      std::getline(ss, nome, ',');
      std::getline(ss, cidadeNome);

      Cidade *cidadeAtual = nullptr;
      for (Cidade *cidade : cidades) {
        if (cidade->getNome() == cidadeNome) {
          cidadeAtual = cidade;
          break;
        }
      }

      passageiros.push_back(
          new Passageiro(nome, cidadeAtual)); // Adicionar passageiro ao vetor
    }
    passageirosStream.close();
  } else {
    std::cerr << "Erro ao abrir o arquivo de passageiros: " << passageirosFile
              << std::endl;
  }

  // Carregar os transportes
  std::ifstream transportesStream(transportesFile);
  if (transportesStream.is_open()) {
    while (std::getline(transportesStream, linha)) {
      // Ignorar o cabeçalho ou linha vazia
      if (linha.empty() ||
          linha == "Nome,Tipo,Capacidade,Velocidade,Cidade Atual") {
        continue;
      }

      std::stringstream ss(linha);
      std::string nome, tipo, cidadeNome;
      int capacidade;
      double velocidade;

      std::getline(ss, nome, ',');
      std::getline(ss, tipo, ',');
      ss >> capacidade;
      ss.ignore(); // Ignorar a vírgula
      ss >> velocidade;
      std::getline(ss, cidadeNome);

      Cidade *cidadeAtual = nullptr;
      for (Cidade *cidade : cidades) {
        if (cidade->getNome() == cidadeNome) {
          cidadeAtual = cidade;
          break;
        }
      }

      transportes.push_back(
          new Transporte(nome, tipo[0], capacidade, velocidade, 0, 0,
                         cidadeAtual)); // Adicionar transporte ao vetor
    }
    transportesStream.close();
  } else {
    std::cerr << "Erro ao abrir o arquivo de transportes: " << transportesFile
              << std::endl;
  }
}
