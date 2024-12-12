#include "classes.h"
#include <iostream>
#include <vector>
#include <string>

void listarCidades(const std::vector<Cidade*>& cidades) {
    if (cidades.empty()) {
        std::cout << "Nenhuma cidade cadastrada." << std::endl;
    } else {
        std::cout << "Cidades cadastradas:" << std::endl;
        for (size_t i = 0; i < cidades.size(); ++i) {
            std::cout << i << ". " << cidades[i]->getNome() << std::endl;
        }
    }
}

void listarTrajetos(const std::vector<Trajeto*>& trajetos) {
    if (trajetos.empty()) {
        std::cout << "Nenhum trajeto cadastrado." << std::endl;
    } else {
        std::cout << "Trajetos cadastrados:" << std::endl;
        for (const auto& trajeto : trajetos) {
            std::cout << trajeto->getOrigem()->getNome() << " -> "
                      << trajeto->getDestino()->getNome() << ", Tipo: " 
                      << trajeto->getTipo() << ", Distância: " 
                      << trajeto->getDistancia() << std::endl;
        }
    }
}

void listarTransportes(const std::vector<Transporte*>& transportes) {
    if (transportes.empty()) {
        std::cout << "Nenhum transporte cadastrado." << std::endl;
    } else {
        std::cout << "Transportes cadastrados:" << std::endl;
        for (const auto& transporte : transportes) {
            std::cout << transporte->getNome() << ", Tipo: " 
                      << transporte->getTipo() << ", Capacidade: " 
                      << transporte->getCapacidade() << std::endl;
        }
    }
}

void listarPassageiros(const std::vector<Passageiro*>& passageiros) {
    if (passageiros.empty()) {
        std::cout << "Nenhum passageiro cadastrado." << std::endl;
    } else {
        std::cout << "Passageiros cadastrados:" << std::endl;
        for (const auto& passageiro : passageiros) {
            std::cout << passageiro->getNome() << std::endl;
        }
    }
}

void listarViagens(const std::vector<Viagem*>& viagens) {
    if (viagens.empty()) {
        std::cout << "Nenhuma viagem cadastrada." << std::endl;
    } else {
        std::cout << "Viagens cadastradas:" << std::endl;
        for (const auto& viagem : viagens) {
            std::cout << viagem->getOrigem()->getNome() << " -> "
                      << viagem->getDestino()->getNome() << ", Transporte: "
                      << viagem->getTransporte()->getNome() << ", Passageiros: ";
            for (const auto& passageiro : viagem->getPassageiros()) {
                std::cout << passageiro->getNome() << " ";
            }
            std::cout << std::endl;
        }
    }
}

void listarDados(std::vector<Cidade*>& cidades, std::vector<Trajeto*>& trajetos, 
                 std::vector<Transporte*>& transportes, std::vector<Passageiro*>& passageiros, 
                 std::vector<Viagem*>& viagens) {
    int opcaoListagem;

    do {
        std::cout << "\n=== LISTAR DADOS ===\n";
        std::cout << "1. Listar Cidades Salvas\n";
        std::cout << "2. Listar Passageiros Salvos\n";
        std::cout << "3. Listar Trajetos Salvos\n";
        std::cout << "4. Listar Transportes Salvos\n";
        std::cout << "5. Listar Viagens Salvas\n";
        std::cout << "0. Voltar ao Menu Principal\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcaoListagem;

        switch (opcaoListagem) {
            case 1: listarCidades(cidades); break;
            case 2: listarPassageiros(passageiros); break;
            case 3: listarTrajetos(trajetos); break;
            case 4: listarTransportes(transportes); break;
            case 5: listarViagens(viagens); break;
            case 0: break;
            default: std::cout << "Opção inválida!" << std::endl;
        }
    } while (opcaoListagem != 0);
}

