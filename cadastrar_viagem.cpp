#include "cadastrar_viagem.h"
#include <iostream>

void cadastrarViagem(std::vector<Trajeto*>& trajetos, std::vector<Passageiro*>& passageiros, std::vector<Viagem*>& viagens, std::vector<Transporte*>& transportes) {
    if (trajetos.empty()) {
        std::cout << "\nNenhum trajeto cadastrado. Cadastre trajetos primeiro!" << std::endl;
        return;
    }

    if (passageiros.empty()) {
        std::cout << "\nNenhum passageiro cadastrado. Cadastre passageiros primeiro!" << std::endl;
        return;
    }

    int trajetoID, numPassageiros;

    // Lista os trajetos
    std::cout << "\nTrajetos cadastrados:\n";
    for (size_t i = 0; i < trajetos.size(); ++i) {
        std::cout << "ID: " << i << ", Origem: " << trajetos[i]->getOrigem()->getNome()
                  << ", Destino: " << trajetos[i]->getDestino()->getNome()
                  << ", Tipo: " << trajetos[i]->getTipo()
                  << ", Distância: " << trajetos[i]->getDistancia() << " km\n";
                  //adicionar a vaga no transporte
    }

    std::cout << "\nDigite o ID do trajeto: ";
    std::cin >> trajetoID;

    if (trajetoID >= 0 && trajetoID < static_cast<int>(trajetos.size())) {
        Cidade* origem = trajetos[trajetoID]->getOrigem();

        Transporte* transporteSelecionado = nullptr;

        // Verificar se tem transporte disponível na cidade de origem
        for (const auto& transporte : transportes) {
            if (transporte->getCidadeAtual() == origem) {
                transporteSelecionado = transporte;
                break;
            }
        }

        if (!transporteSelecionado) {
            std::cerr << "\nAinda não há transportes disponíveis na cidade de origem indicada. Cadastre um transporte na cidade que deseja partir e tente novamente." << std::endl;
            return;
        }

        // Verificar as vagas no transporte
        std::cout << "\nQuantos passageiros irão na viagem? ";
        std::cin >> numPassageiros;

        if (numPassageiros > transporteSelecionado->getCapacidade()) {
            std::cerr << "\nO transporte que você selecionou não possui vagas suficientes. Por favor, tente novamente." << std::endl;
            return;
        }

        // Verificar se há passageiros suficientes cadastrados
        if (numPassageiros > static_cast<int>(passageiros.size())) {
            std::cerr << "\nHá apenas " << passageiros.size() << " passageiros cadastrados. Cadastre mais passageiros e tente novamente." << std::endl;
            return;
        }

        Viagem* novaViagem = new Viagem(trajetos[trajetoID]->getOrigem(), trajetos[trajetoID]->getDestino(), transporteSelecionado);

        for (int i = 0; i < numPassageiros; ++i) {
            int passageiroID;

            // Lista os passageiros
            std::cout << "\nPassageiros cadastrados:\n";
            for (size_t j = 0; j < passageiros.size(); ++j) {
                std::cout << "ID: " << j << ", Nome: " << passageiros[j]->getNome() << "\n";
            }

            std::cout << "\nDigite o ID do passageiro: ";
            std::cin >> passageiroID;

            if (passageiroID >= 0 && passageiroID < static_cast<int>(passageiros.size())) {
                novaViagem->adicionarPassageiro(passageiros[passageiroID]);
            } else {
                std::cerr << "\nID de passageiro inválido." << std::endl;
            }
        }

        viagens.push_back(novaViagem);
        std::cout << "\nViagem cadastrada com sucesso!" << std::endl;
    } else {
        std::cerr << "\nID de trajeto inválido." << std::endl;
    }
}
