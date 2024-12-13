#include <iostream>
#include "classes.h"
#include "funcoes.h"

int main() {
    std::vector<Cidade*> cidades;
    std::vector<Trajeto*> trajetos;
    std::vector<Transporte*> transportes;
    std::vector<Passageiro*> passageiros;
    std::vector<Viagem*> viagens;

    int opcao;

    do {
        std::cout << "\n=== BEM VINDO AO CONTROLADOR DE VIAGENS ===\n";
        std::cout << "1. Cadastrar Cidade\n";
        std::cout << "2. Cadastrar Trajeto\n";
        std::cout << "3. Cadastrar Transporte\n";
        std::cout << "4. Cadastrar Passageiro\n";
        std::cout << "5. Cadastrar Viagem\n";
        std::cout << "6. Listar Dados\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                std::string nome;
                std::cout << "Digite o nome da cidade: ";
                std::cin >> nome;
                cidades.push_back(new Cidade(nome));
                std::cout << "Cidade cadastrada com sucesso!" << std::endl;
                break;
            }

            case 2: {
                if (cidades.empty()) {
                    std::cout << "Nenhuma cidade cadastrada. Cadastre cidades primeiro!" << std::endl;
                    break;
                }

                if (transportes.empty()) {
                    std::cout << "Nenhum transporte cadastrado. Cadastre transportes primeiro!" << std::endl;
                    break;
                }

                int origem, destino, distancia, transporteID;
                char tipo;

                std::cout << "\nCidades cadastradas:\n";
                for (size_t i = 0; i < cidades.size(); ++i) {
                    std::cout << "ID: " << i << ", Nome: " << cidades[i]->getNome() << "\n";
                }

                std::cout << "Digite o ID da cidade de origem: ";
                std::cin >> origem;
                std::cout << "Digite o ID da cidade de destino: ";
                std::cin >> destino;

                std::cout << "\nTransportes cadastrados:\n";
                for (size_t i = 0; i < transportes.size(); ++i) {
                    std::cout << "ID: " << i << ", Nome: " << transportes[i]->getNome()
                              << ", Tipo: " << transportes[i]->getTipo()
                              << ", Capacidade: " << transportes[i]->getCapacidade() << "\n";
                }

                std::cout << "Digite o ID do transporte: ";
                std::cin >> transporteID;

                if (origem >= 0 && origem < cidades.size() &&
                    destino >= 0 && destino < cidades.size() &&
                    transporteID >= 0 && transporteID < transportes.size()) {
                    
                    std::cout << "Digite o tipo de trajeto (A/T): ";
                    std::cin >> tipo;
                    std::cout << "Digite a distância em km: ";
                    std::cin >> distancia;

                    trajetos.push_back(new Trajeto(cidades[origem], cidades[destino], tipo, distancia));
                    std::cout << "Trajeto cadastrado com sucesso!" << std::endl;
                } else {
                    std::cerr << "ID inválido(s). Cadastro de trajeto falhou." << std::endl;
                }
                break;
            }

            case 3: {
                std::string nome;
                char tipo;
                int capacidade;

                std::cout << "Digite o nome do transporte: ";
                std::cin >> nome;
                std::cout << "Digite o tipo do transporte (A/T): ";
                std::cin >> tipo;
                std::cout << "Digite a capacidade do transporte: ";
                std::cin >> capacidade;

                transportes.push_back(new Transporte(nome, tipo, capacidade));
                std::cout << "Transporte cadastrado com sucesso!" << std::endl;
                break;
            }

            case 4: {
                std::string nome;
                std::cout << "Digite o nome do passageiro: ";
                std::cin >> nome;
                passageiros.push_back(new Passageiro(nome));
                std::cout << "Passageiro cadastrado com sucesso!" << std::endl;
                break;
            }

            case 5: {
                if (trajetos.empty()) {
                    std::cout << "Nenhum trajeto cadastrado. Cadastre trajetos primeiro!" << std::endl;
                    break;
                }

                if (passageiros.empty()) {
                    std::cout << "Nenhum passageiro cadastrado. Cadastre passageiros primeiro!" << std::endl;
                    break;
                }

                int trajetoID, numPassageiros;

                std::cout << "\nTrajetos cadastrados:\n";
                for (size_t i = 0; i < trajetos.size(); ++i) {
                    std::cout << "ID: " << i << ", Origem: " << trajetos[i]->getOrigem()->getNome()
                              << ", Destino: " << trajetos[i]->getDestino()->getNome()
                              << ", Tipo: " << trajetos[i]->getTipo()
                              << ", Distância: " << trajetos[i]->getDistancia() << " km\n";
                }

                std::cout << "Digite o ID do trajeto: ";
                std::cin >> trajetoID;

                if (trajetoID >= 0 && trajetoID < trajetos.size()) {
                    Viagem* novaViagem = new Viagem(trajetos[trajetoID]->getOrigem(), 
                                                     trajetos[trajetoID]->getDestino(), 
                                                     nullptr);

                    std::cout << "Quantos passageiros irão na viagem? ";
                    std::cin >> numPassageiros;

                    for (int i = 0; i < numPassageiros; ++i) {
                        int passageiroID;

                        std::cout << "\nPassageiros cadastrados:\n";
                        for (size_t j = 0; j < passageiros.size(); ++j) {
                            std::cout << "ID: " << j << ", Nome: " << passageiros[j]->getNome() << "\n";
                        }

                        std::cout << "Digite o ID do passageiro: ";
                        std::cin >> passageiroID;

                        if (passageiroID >= 0 && passageiroID < passageiros.size()) {
                            novaViagem->adicionarPassageiro(passageiros[passageiroID]);
                        } else {
                            std::cerr << "ID de passageiro inválido." << std::endl;
                        }
                    }

                    viagens.push_back(novaViagem);
                    std::cout << "Viagem cadastrada com sucesso!" << std::endl;
                } else {
                    std::cerr << "ID de trajeto inválido." << std::endl;
                }
                break;
            }

            case 6:
                listarDados(cidades, trajetos, transportes, passageiros, viagens);
                break;

            case 0:
                break;

            default:
                std::cout << "Opção inválida!" << std::endl;
        }
    } while (opcao != 0);

    return 0;
}
