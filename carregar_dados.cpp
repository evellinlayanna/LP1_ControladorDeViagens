#include "carregar_dados.h"
#include "classes.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

// Carrega cidades
void carregarCidades(std::vector<Cidade *> &cidades,
                     const std::string &arquivo) {
  cidades.clear();
  std::ifstream planilha(arquivo);
  if (!planilha.is_open()) {
    std::cerr << "Erro ao abrir o arquivo de cidades: " << arquivo << "\n";
    return;
  }

  std::string linha;
  bool dadosCarregados = false;

  // Ignora o cabeçalho
  std::getline(planilha, linha);

  while (std::getline(planilha, linha)) {
    if (linha.empty())
      continue;
    cidades.push_back(new Cidade(linha));
    dadosCarregados = true;
  }

  planilha.close();

  if (!dadosCarregados) {
    std::cerr << "Nenhuma cidade válida encontrada no arquivo: " << arquivo
              << "\n";
  } else {
    std::cout << "Cidades carregadas com sucesso a partir de: " << arquivo
              << "\n";
  }
}

// Carrega passageiros
void carregarPassageiros(std::vector<Passageiro *> &passageiros,
                         const std::vector<Cidade *> &cidades,
                         const std::string &arquivo) {
  passageiros.clear();
  std::ifstream planilha(arquivo);
  if (!planilha.is_open()) {
    std::cerr << "Erro ao abrir o arquivo de passageiros: " << arquivo << "\n";
    return;
  }

  std::string linha;
  bool dadosCarregados = false;

  // Ignora o cabeçalho
  std::getline(planilha, linha);

  while (std::getline(planilha, linha)) {
    if (linha.empty())
      continue;

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

    if (!nome.empty() && cidadeAtual) {
      passageiros.push_back(new Passageiro(nome, cidadeAtual));
      dadosCarregados = true;
    }
  }

  planilha.close();

  if (!dadosCarregados) {
    std::cerr << "Nenhum passageiro válido encontrado no arquivo: " << arquivo
              << "\n";
  } else {
    std::cout << "Passageiros carregados com sucesso a partir de: " << arquivo
              << "\n";
  }
}

// Carrega transportes
void carregarTransportes(std::vector<Transporte *> &transportes,
                         const std::vector<Cidade *> &cidades,
                         const std::string &arquivo) {
  transportes.clear();
  std::ifstream planilha(arquivo);
  if (!planilha.is_open()) {
    std::cerr << "Erro ao abrir o arquivo de transportes: " << arquivo << "\n";
    return;
  }

  std::string linha;
  bool dadosCarregados = false;

  // Ignora o cabeçalho
  std::getline(planilha, linha);

  while (std::getline(planilha, linha)) {
    if (linha.empty())
      continue;

    std::stringstream ss(linha);
    std::string nome, tipo, cidadeNome;
    int capacidade;
    double velocidade, distanciaEntreDescansos, tempoDeDescanso;

    std::getline(ss, nome, ',');
    std::getline(ss, tipo, ',');
    ss >> capacidade;
    ss.ignore();
    ss >> velocidade;
    ss.ignore();
    ss >> distanciaEntreDescansos;
    ss.ignore();
    ss >> tempoDeDescanso;
    ss.ignore();
    std::getline(ss, cidadeNome);

    Cidade *cidadeAtual = nullptr;
    for (Cidade *cidade : cidades) {
      if (cidade->getNome() == cidadeNome) {
        cidadeAtual = cidade;
        break;
      }
    }

    // Valida dados do transporte
    if (!nome.empty() && (tipo == "A" || tipo == "T") && capacidade > 0 &&
        velocidade > 0 && distanciaEntreDescansos > 0 && tempoDeDescanso > 0 &&
        cidadeAtual) {
      transportes.push_back(new Transporte(nome, tipo[0], capacidade,
                                           velocidade, distanciaEntreDescansos,
                                           tempoDeDescanso, cidadeAtual));
      dadosCarregados = true;
    }
  }

  planilha.close();

  if (!dadosCarregados) {
    std::cerr << "Nenhum transporte válido encontrado no arquivo: " << arquivo
              << "\n";
  } else {
    std::cout << "Transportes carregados com sucesso a partir de: " << arquivo
              << "\n";
  }
}

// Carrega trajetos
void carregarTrajetos(std::vector<Trajeto *> &trajetos,
                      const std::vector<Cidade *> &cidades,
                      const std::string &arquivo) {
  trajetos.clear();
  std::ifstream planilha(arquivo);
  if (!planilha.is_open()) {
    std::cerr << "Erro ao abrir o arquivo de trajetos: " << arquivo << "\n";
    return;
  }

  std::string linha;
  bool dadosCarregados = false;

  // Ignora o cabeçalho
  std::getline(planilha, linha);

  while (std::getline(planilha, linha)) {
    if (linha.empty())
      continue;

    std::stringstream ss(linha);
    std::string cidadeOrigemNome, cidadeDestinoNome, tipoStr;
    double distancia;

    std::getline(ss, cidadeOrigemNome, ',');
    std::getline(ss, cidadeDestinoNome, ',');
    std::getline(ss, tipoStr, ',');
    ss >> distancia;

    Cidade *cidadeOrigem = nullptr;
    Cidade *cidadeDestino = nullptr;

    for (Cidade *cidade : cidades) {
      if (cidade->getNome() == cidadeOrigemNome) {
        cidadeOrigem = cidade;
      }
      if (cidade->getNome() == cidadeDestinoNome) {
        cidadeDestino = cidade;
      }
    }

    if (!cidadeOrigem || !cidadeDestino ||
        (tipoStr != "Aquático" && tipoStr != "Terrestre") || distancia <= 0) {
      continue;
    }

    char tipo = (tipoStr == "Aquático") ? 'A' : 'T';
    trajetos.push_back(
        new Trajeto(cidadeOrigem, cidadeDestino, tipo, distancia));
    dadosCarregados = true;
  }

  planilha.close();

  if (!dadosCarregados) {
    std::cerr << "Nenhum trajeto válido encontrado no arquivo: " << arquivo
              << "\n";
  } else {
    std::cout << "Trajetos carregados com sucesso a partir de: " << arquivo
              << "\n";
  }
}

// Carrega viagens
void carregarViagens(std::vector<Viagem *> &viagens,
                     const std::vector<Passageiro *> &passageiros,
                     const std::vector<Transporte *> &transportes,
                     const std::vector<Trajeto *> &trajetos,
                     const std::string &arquivo) {
  viagens.clear();
  std::ifstream planilha(arquivo);
  if (!planilha.is_open()) {
    std::cerr << "Erro ao abrir o arquivo de viagens: " << arquivo << "\n";
    return;
  }

  std::string linha;
  bool dadosCarregados = false;

  // Ignora o cabeçalho
  std::getline(planilha, linha);

  while (std::getline(planilha, linha)) {
    if (linha.empty())
      continue;

    std::stringstream ss(linha);
    std::string trajetoNome, transporteNome, nomePassageiro, dataHoraPartida;

    std::getline(ss, trajetoNome, ',');
    std::getline(ss, transporteNome, ',');
    std::getline(ss, nomePassageiro, ',');
    std::getline(ss, dataHoraPartida, ',');

    // Busca o trajeto
    Trajeto *trajetoSelecionado = nullptr;
    for (Trajeto *trajeto : trajetos) {
      if (trajeto->getOrigem()->getNome() == trajetoNome &&
          trajeto->getDestino()->getNome() ==
              trajetoNome) { // Considera a origem e destino
        trajetoSelecionado = trajeto;
        break;
      }
    }

    // Busca transporte
    Transporte *transporteSelecionado = nullptr;
    for (Transporte *transporte : transportes) {
      if (transporte->getNome() == transporteNome) {
        transporteSelecionado = transporte;
        break;
      }
    }

    // Busca passageiro
    Passageiro *passageiroSelecionado = nullptr;
    for (Passageiro *passageiro : passageiros) {
      if (passageiro->getNome() == nomePassageiro) {
        passageiroSelecionado = passageiro;
        break;
      }
    }

    // Verifica se todos os dados foram encontrados
    if (trajetoSelecionado && transporteSelecionado && passageiroSelecionado) {
      Viagem *novaViagem =
          new Viagem(trajetoSelecionado, transporteSelecionado);
      novaViagem->adicionarPassageiro(passageiroSelecionado);

      // Adiciona a viagem no vetor
      viagens.push_back(novaViagem);
      dadosCarregados = true;

      //   std::cout << "Carregando viagem: "
      //             << trajetoSelecionado->getOrigem()->getNome() << " - "
      //             << trajetoSelecionado->getDestino()->getNome() << ", "
      //             << transporteSelecionado->getNome() << ", "
      //             << passageiroSelecionado->getNome() << ", "
      //             << "Data: " << dataHoraPartida << std::endl;
      // }
    }

    planilha.close();

    if (!dadosCarregados) {
      std::cerr << "Nenhuma viagem válida encontrada no arquivo: " << arquivo
                << "\n";
    } else {
      std::cout << "Viagens carregadas com sucesso a partir de: " << arquivo
                << "\n";
    }
  }

  void carregarDados(
      std::vector<Cidade *> & cidades, std::vector<Passageiro *> & passageiros,
      std::vector<Transporte *> & transportes,
      std::vector<Trajeto *> & trajetos, std::vector<Viagem *> & viagens,
      const std::string &cidadesFile, const std::string &passageirosFile,
      const std::string &transportesFile, const std::string &trajetosFile,
      const std::string &viagensFile) {
    carregarCidades(cidades, cidadesFile);
    carregarPassageiros(passageiros, cidades, passageirosFile);
    carregarTransportes(transportes, cidades, transportesFile);
    carregarTrajetos(trajetos, cidades, trajetosFile);
    carregarViagens(viagens, passageiros, transportes, trajetos, viagensFile);
  }