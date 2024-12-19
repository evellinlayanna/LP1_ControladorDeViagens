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
        std::cout << "\nEscolha uma opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: { // Cadastro de Cidade
                std::cout << "\nDigite o nome da cidade: ";
                std::cin.ignore(); // Limpa os dados antigos
                std::string nome;
                std::getline(std::cin, nome);
            
                if (nome.size() > 20) {
                    std::cerr << "\nO nome da cidade não pode exceder 20 caracteres.\n";
                } else {
                    cidades.push_back(new Cidade(nome));
                    std::cout << "\nCidade cadastrada com sucesso!" << std::endl;
                }
                break;
            }


            case 2: { // Cadastro de Trajeto
                if (cidades.empty()) {
                    std::cout << "\nNão há cidade cadastrada. Cadastre pelo menos duas cidades primeiro." << std::endl;
                    break;
                }

                if (transportes.empty()) {
                    std::cout << "\nNão há transporte cadastrado. Cadastre transportes primeiro!" << std::endl;
                    break;
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
                std::cout << "\nDigite o ID da cidade de destino: ";
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

                // Verificação de IDs válidos
                if (origem >= 0 && origem < cidades.size() &&
                    destino >= 0 && destino < cidades.size() &&
                    transporteID >= 0 && transporteID < transportes.size()) {
                    
                    std::cout << "\nDigite o tipo de trajeto (A aquático, T terrestre): ";
                    std::cin >> tipo;
                    std::cout << "\nDigite a distância em km: ";
                    std::cin >> distancia;

                    trajetos.push_back(new Trajeto(cidades[origem], cidades[destino], tipo, distancia));
                    std::cout << "\nTrajeto cadastrado com sucesso!" << std::endl;
                } else {
                    std::cerr << "\nAlgum ID é inválido. O cadastro de trajeto falhou, tente novamente" << std::endl;
                }
                break;
            }

            case 3: { // Cadastro de Transporte
                std::string nome;
                char tipo;
                int capacidade;
                double velocidade;
                double distanciaEntreDescansos;
                double tempoDeDescanso;
                int cidadeID;
            
                std::cout << "Digite o nome do transporte: ";
                std::cin.ignore(); // Limpa os dados antigos
                std::getline(std::cin, nome);
            
                std::cout << "Digite o tipo do transporte (A aquático, T terrestre): ";
                std::cin >> tipo;
            
                std::cout << "Digite a capacidade do transporte: ";
                std::cin >> capacidade;
            
                std::cout << "Digite a velocidade do transporte (Km/h): ";
                std::cin >> velocidade;
            
                std::cout << "Digite a distância entre descansos (Km): ";
                std::cin >> distanciaEntreDescansos;
            
                std::cout << "Digite o tempo de descanso (horas): ";
                std::cin >> tempoDeDescanso;
            
                if (cidades.empty()) {
                    std::cerr << "Nenhuma cidade cadastrada. Cadastre uma cidade antes de registrar um transporte.\n";
                    break;
                }
            
                // Lista as cidades
                std::cout << "\nCidades disponíveis:\n";
                for (size_t i = 0; i < cidades.size(); ++i) {
                    std::cout << "ID: " << i << ", Nome: " << cidades[i]->getNome() << "\n";
                }
            
                std::cout << "\nDigite o ID da cidade onde o transporte está localizado: ";
                std::cin >> cidadeID;
            
                if (cidadeID >= 0 && cidadeID < cidades.size()) {
                    transportes.push_back(new Transporte(nome, tipo, capacidade, velocidade, distanciaEntreDescansos, tempoDeDescanso, cidades[cidadeID]));
                    std::cout << "\nTransporte cadastrado com sucesso!" << std::endl;
                } else {
                    std::cerr << "\nID de cidade inválido. Cadastro de transporte falhou, tente novamente.";
                }
                break;
            }


            case 4: { // Cadastro de passageiro
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
                break;
            }

            case 5: {
                if (trajetos.empty()) {
                    std::cout << "\nNenhum trajeto cadastrado. Cadastre trajetos primeiro!" << std::endl;
                    break;
                }

                if (passageiros.empty()) {
                    std::cout << "\nNenhum passageiro cadastrado. Cadastre passageiros primeiro!" << std::endl;
                    break;
                }

                int trajetoID, numPassageiros;

                // Lista os trajetos
                std::cout << "\nTrajetos cadastrados:\n";
                for (size_t i = 0; i < trajetos.size(); ++i) {
                    std::cout << "ID: " << i << ", Origem: " << trajetos[i]->getOrigem()->getNome()
                              << ", Destino: " << trajetos[i]->getDestino()->getNome()
                              << ", Tipo: " << trajetos[i]->getTipo()
                              << ", Distância: " << trajetos[i]->getDistancia() << " km\n";
                }

                std::cout << "\nDigite o ID do trajeto: ";
                std::cin >> trajetoID;

                if (trajetoID >= 0 && trajetoID < trajetos.size()) {
                    Viagem* novaViagem = new Viagem(trajetos[trajetoID]->getOrigem(), 
                                                     trajetos[trajetoID]->getDestino(), 
                                                     nullptr);

                    std::cout << "\nQuantos passageiros irão na viagem? ";
                    std::cin >> numPassageiros;

                    for (int i = 0; i < numPassageiros; ++i) {
                        int passageiroID;

                        // Lista os passageiros
                        std::cout << "\nPassageiros cadastrados:\n";
                        for (size_t j = 0; j < passageiros.size(); ++j) {
                            std::cout << "ID: " << j << ", Nome: " << passageiros[j]->getNome() << "\n";
                        }

                        std::cout << "\nDigite o ID do passageiro: ";
                        std::cin >> passageiroID;

                        if (passageiroID >= 0 && passageiroID < passageiros.size()) {
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
                break;
            }

            case 6:
                listarDados(cidades, trajetos, transportes, passageiros, viagens);
                break;

            case 0:
                break;

            default:
                std::cout << "\nOpção inválida!" << std::endl;
        }
    } while (opcao != 0);

    return 0;
}
