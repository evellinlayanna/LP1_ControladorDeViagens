#include "classes.h"
#include <iostream>

void cadastrarPassageiro(std::vector<Passageiro *> &passageiros,
                         const std::vector<Cidade *> &cidades) {
  // Verifica se há cidades cadastradas
  if (cidades.empty()) {
    std::cout
        << "Nenhuma cidade cadastrada! Impossível cadastrar um passageiro.\n";
    return;
  }

  std::string nome;
  std::cout << "\nDigite o nome do passageiro: ";
  std::cin >> nome;

  // Verifica se o passageiro já foi cadastrado
  for (Passageiro *passageiro : passageiros) {
    if (passageiro->getNome() == nome) {
      std::cout << "\nPassageiro com o nome \"" << nome
                << "\" já cadastrado!\n";
      return; // Não adiciona o passageiro duplicado
    }
  }

  // Exibe as cidades cadastradas com seus IDs
  std::cout << "\nCidades cadastradas:\n";
  for (size_t i = 0; i < cidades.size(); ++i) {
    std::cout << i + 1 << ". " << cidades[i]->getNome() << "\n";
  }

  // Solicita a seleção de uma cidade pelo ID
  int cidadeId;
  std::cout << "\nDigite o ID da cidade atual do passageiro: ";
  std::cin >> cidadeId;

  // Verifica se o ID da cidade é válido
  if (cidadeId < 1 || cidadeId > cidades.size()) {
    std::cout << "\nID de cidade inválido!\n";
    return;
  }

  // Seleciona a cidade correspondente ao ID
  Cidade *cidadeAtual = cidades[cidadeId - 1];

  // Cria o novo passageiro e adiciona ao vetor
  passageiros.push_back(new Passageiro(nome, cidadeAtual));
  std::cout << "\nPassageiro \"" << nome << "\" cadastrado com sucesso!\n";
}
