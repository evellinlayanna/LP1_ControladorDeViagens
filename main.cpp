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
                break;
            }
            case 2: {
                int origem, destino, distancia;
                char tipo;
                std::cout << "Digite a origem, destino, tipo e distância do trajeto: ";
                std::cin >> origem >> destino >> tipo >> distancia;
                break;
            }
            case 3: {
                std::string nome;
                char tipo;
                int capacidade;
                std::cout << "Digite o nome, tipo e capacidade do transporte: ";
                std::cin >> nome >> tipo >> capacidade;
                transportes.push_back(new Transporte(nome, tipo, capacidade));
                break;
            }
            case 4: {
                std::string nome;
                std::cout << "Digite o nome do passageiro: ";
                std::cin >> nome;
                passageiros.push_back(new Passageiro(nome));
                break;
            }
            case 5: {
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
