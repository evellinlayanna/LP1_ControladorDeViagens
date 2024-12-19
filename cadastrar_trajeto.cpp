#include "cadastrar_trajeto.h"
#include <iostream>

void cadastrarTrajeto(std::vector<Cidade*>& cidades, std::vector<Transporte*>& transportes, std::vector<Trajeto*>& trajetos) {
    if (cidades.size() < 2) {
        std::cout << "\nNão há cidades suficientes cadastradas. Cadastre pelo menos duas cidades primeiro." << std::endl;
        return;
    }

    if (transportes.empty()) {
        std::cout << "\nNão há transporte cadastrado. Cadastre transportes primeiro." << std::endl;
        return;
    }

    int origem, destino, distancia, transporteID;
    char tipo;

    // Lista as cidades
    std::cout << "\nCidades cadastradas:\n";
    for (size_t i = 0; i < cidades.size(); ++i) {
        std::cout << "ID: " << i << ", Nome: " << cidades[i]->getNome() << "\n";
    }

    std::cout << "\nDigite o ID da cidade de origem: ";
    std::cin >> origem;
    std::cout << "Digite o ID da cidade de destino: ";
    std::cin >> destino;

    // Lista os transportes
    std::cout << "\nTransportes cadastrados:\n";
    for (size_t i = 0; i < transportes.size(); ++i) {
        std::cout << "ID: " << i << ", Nome: " << transportes[i]->getNome()
                  << ", Tipo: " << transportes[i]->getTipo()
                  << ", Capacidade: " << transportes[i]->getCapacidade() << "\n";
    }

    std::cout << "\nDigite o ID do transporte: ";
    std::cin >> transporteID;

    if (origem >= 0 && origem < static_cast<int>(cidades.size()) &&
        destino >= 0 && destino < static_cast<int>(cidades.size()) &&
        transporteID >= 0 && transporteID < static_cast<int>(transportes.size())) {

        std::cout << "\nDigite o tipo de trajeto (A aquático, T terrestre): ";
        std::cin >> tipo;

        // Verifica se o tipo do transporte é compatível com o trajeto
        if ((tipo == 'T' && transportes[transporteID]->getTipo() != 'T') ||
            (tipo == 'A' && transportes[transporteID]->getTipo() != 'A')) {
            std::cerr << "\nO transporte selecionado não é compatível com o tipo de trajeto." << std::endl;
            return;
        }

        std::cout << "Digite a distância em km: ";
        std::cin >> distancia;

        trajetos.push_back(new Trajeto(cidades[origem], cidades[destino], tipo, distancia));
        std::cout << "\nTrajeto cadastrado com sucesso!" << std::endl;
    } else {
        std::cerr << "\nAlgum ID é inválido. O cadastro de trajeto falhou, tente novamente." << std::endl;
    }
}