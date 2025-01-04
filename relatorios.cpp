#include <iostream>
#include <vector>
#include "classes.h"
#include "relatorios.h"

void Relatorio::mostrarRelatorios(std::vector<Passageiro*>& passageiros, 
                                   std::vector<Transporte*>& transportes,
                                   std::vector<Viagem*>& viagens, 
                                   std::vector<Cidade*>& cidades) {

    int opcaoRelatorio;
    do {
        std::cout << "\n--- ESCOLHA O TIPO DE RELATÓRIO ---\n";
        std::cout << "1. Relatório de Passageiros\n";
        std::cout << "2. Relatório de Transportes\n";
        std::cout << "3. Relatório de Viagens\n";
        std::cout << "4. Relatório de Cidades\n";
        std::cout << "0. Voltar ao Menu Principal\n";
        std::cout << "\nEscolha uma opção: ";
        std::cin >> opcaoRelatorio;

        switch (opcaoRelatorio) {
            case 1:
                if (passageiros.empty()) {
                    std::cout << "\nNenhum passageiro cadastrado no sistema.\n";
                break;
                }
                
                std::cout << "\nRelatório de Passageiros:\n";
                for (size_t i = 0; i < passageiros.size(); ++i) {
                    Passageiro* passageiro = passageiros[i];
                    std::cout << "Passageiro: " << passageiro->getNome() << "\n";

                    // Verifica se o passageiro está em uma viagem
                    bool emViagem = false;
                    Viagem* viagemAtual = nullptr;
                    for (Viagem* viagem : viagens) {
                        for (Passageiro* p : viagem->getPassageiros()) {
                            if (p == passageiro) {
                                emViagem = true;
                                viagemAtual = viagem;
                                break;
                            }
                        }
                        if (emViagem) break;
                    }

                    if (emViagem) {
                        // O passageiro está em trânsito (em viagem)
                        std::cout << "Status: Em Trânsito (Viagem)\n";
                        std::cout << "Origem: " << viagemAtual->getOrigem()->getNome() << "\n";
                        std::cout << "Destino: " << viagemAtual->getDestino()->getNome() << "\n";
                        std::cout << "Transporte: " << viagemAtual->getTransporte()->getNome() << "\n";
                        std::cout << "Tipo de Transporte: " << viagemAtual->getTransporte()->getTipo() << "\n";
                    } else {
                        // O passageiro está na cidade
                        std::cout << "Status: Na Cidade\n";
                        // std::cout << "Cidade atual: " << passageiro->getCidadeAtual()->getNome() << "\n";
                    }

                    std::cout << "\n";
                }
                break;

            case 2:
                if (transportes.empty()) {
                    std::cout << "\nNenhum transporte cadastrado no sistema.\n";
                break;
                }
                
                std::cout << "\nRelatório de Transportes:\n";
                for (size_t i = 0; i < transportes.size(); ++i) {
                    Transporte* transporte = transportes[i];
                    std::cout << "Transporte: " << transporte->getNome() << "\n";
            
                    // Verifica se o transporte está em uma viagem
                    bool emViagem = false;
                    Viagem* viagemAtual = nullptr;
                    for (Viagem* viagem : viagens) {
                        if (viagem->getTransporte() == transporte) {
                            emViagem = true;
                            viagemAtual = viagem;
                            break;
                        }
                    }
            
                    if (emViagem) {
                        std::cout << "Status: Em trânsito de " << viagemAtual->getOrigem()->getNome() << " para "<< viagemAtual->getDestino()->getNome() << "\n";
                    } else {
                        std::cout << "Status: Na cidade " << transporte->getCidadeAtual()->getNome() << "\n";
                    }
            
                    std::cout << "\n";
                }
                break;

            case 3:
                if (viagens.empty()) {
                    std::cout << "\nNenhuma viagem cadastrada no sistema.\n";
                break;
                }
                
                std::cout << "\nRelatório de Viagens:\n";
                for (size_t i = 0; i < viagens.size(); ++i) {
                    Viagem* viagem = viagens[i];
                    std::cout << "Viagem: " << "\n";
                    std::cout << "Origem: " << viagem->getOrigem()->getNome() << "\n";
                    std::cout << "Destino: " << viagem->getDestino()->getNome() << "\n";
                    std::cout << "Transporte: " << viagem->getTransporte()->getNome() << "\n";
                    std::cout << "Tipo de Transporte: " << viagem->getTransporte()->getTipo() << "\n";
                    std::cout << "Passageiros: \n";
                    for (Passageiro* p : viagem->getPassageiros()) {
                        std::cout << "- " << p->getNome() << "\n";
                    }
                    std::cout << "\n";
                }
                break;

            case 4:
                if (cidades.empty()) {
                    std::cout << "\nNenhuma cidade cadastrada no sistema.\n";
                break;
                }
            
                std::cout << "\nRelatório de Cidades:\n";
                for (size_t i = 0; i < cidades.size(); ++i) {
                    Cidade* cidade = cidades[i];
                    std::cout << "Cidade: " << cidade->getNome() << "\n";
                    std::cout << "\n";
                }
                break;

            case 0:
                std::cout << "Voltando ao Menu Principal...\n";
                break;

            default:
                std::cerr << "\nOpção inválida!\n";
                break;
        }
    } while (opcaoRelatorio != 0);
}
