#include "cadastrar_trajeto.h"
#include <iostream>

void cadastrarTrajeto(std::vector<Cidade*>& cidades, std::vector<Trajeto*>& trajetos) {
    if (cidades.size() < 2) {
        std::cout << "\nNão há cidades suficientes cadastradas. Cadastre pelo menos duas cidades primeiro." << std::endl;
        return;
    }

    int origem, destino, distancia;
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

    if (origem >= 0 && origem < static_cast<int>(cidades.size()) &&
        destino >= 0 && destino < static_cast<int>(cidades.size())) {

        std::cout << "\nDigite o tipo de trajeto (A aquático, T terrestre): ";
        std::cin >> tipo;
        tipo = toupper(tipo); // Converte para maiúscula

        if (tipo != 'T' && tipo != 'A') {
            std::cerr << "\nTipo de trajeto inválido. Use 'A' para aquático ou 'T' para terrestre." << std::endl;
            return;
        }

        std::cout << "Digite a distância em km: ";
        std::cin >> distancia;

        if (distancia <= 0) {
            std::cerr << "\nA distância deve ser maior que 0." << std::endl;
            return;
        }

        trajetos.push_back(new Trajeto(cidades[origem], cidades[destino], tipo, distancia));
        std::cout << "\nTrajeto cadastrado com sucesso!" << std::endl;
    } else {
        std::cerr << "\nAlgum ID de cidade é inválido. O cadastro de trajeto falhou, tente novamente." << std::endl;
    }
}
