#include "cadastrar_cidade.h"
#include <iostream>

void cadastrarCidade(std::vector<Cidade*>& cidades) {
    std::cout << "\nDigite o nome da cidade: ";
    std::cin.ignore(); // Limpa dados antigos
    std::string nome;
    std::getline(std::cin, nome);

    if (nome.size() > 20) {
        std::cerr << "\nO nome da cidade não pode exceder 20 caracteres.\n";
    } else {
        cidades.push_back(new Cidade(nome));
        std::cout << "\nCidade cadastrada com sucesso!" << std::endl;
    }
}
