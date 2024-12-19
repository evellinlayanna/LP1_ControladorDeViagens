#include "cadastrar_passageiro.h"
#include <iostream>

void cadastrarPassageiro(std::vector<Passageiro*>& passageiros) {
    std::cout << "\nDigite o nome do passageiro: ";
    std::cin.ignore(); // Limpa dados antigos
    std::string nome;
    std::getline(std::cin, nome);

    if (nome.empty()) {
        std::cerr << "\nO nome do passageiro não pode estar vazio.\n";
    } else {
        passageiros.push_back(new Passageiro(nome));
        std::cout << "\nPassageiro cadastrado com sucesso!" << std::endl;
    }
}
