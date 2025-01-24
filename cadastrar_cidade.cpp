#include "cadastrar_cidade.h"
#include <iostream>

void cadastrarCidade(std::vector<Cidade *> &cidades) {
  std::string nome;
  std::cout << "Digite o nome da cidade: ";
  std::cin >> nome;

  for (Cidade *cidade : cidades) {
    if (cidade->getNome() == nome) {
      std::cout << "Cidade já cadastrada!\n";
      return;
    }
  }

  cidades.push_back(new Cidade(nome));
  std::cout << "Cidade cadastrada com sucesso: " << nome << "\n";
}
