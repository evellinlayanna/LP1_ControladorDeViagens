#include "cadastrar_transporte.h"
#include <iostream>

void cadastrarTransporte(std::vector<Cidade*>& cidades, std::vector<Transporte*>& transportes) {

    std::string nome;
    char tipo;
    int capacidade;
    double velocidade;
    double distanciaEntreDescansos;
    double tempoDeDescanso;
    int cidadeID;

    std::cout << "\nDigite o nome do transporte: ";
    std::cin.ignore(); // Limpa os dados antigos
    std::getline(std::cin, nome);

    std::cout << "Digite o tipo do transporte (A aquático, T terrestre): ";
    std::cin >> tipo;
    tipo = toupper(tipo); // Converte para maiúscula

    if (tipo != 'T' && tipo != 'A') {
            std::cerr << "\nTipo de transporte inválido. Use 'A' para aquático ou 'T' para terrestre e tente novamente." << std::endl;
            return;
    }

    std::cout << "Digite a capacidade do transporte: ";
    std::cin >> capacidade;

    std::cout << "Digite a velocidade do transporte (Km/h): ";
    std::cin >> velocidade;

    std::cout << "Digite a distância entre descansos (Km): ";
    std::cin >> distanciaEntreDescansos;

    std::cout << "Digite o tempo de descanso (horas): ";
    std::cin >> tempoDeDescanso;

    // Lista as cidadesl
    std::cout << "\nCidades cadastradas:\n";
    for (size_t i = 0; i < cidades.size(); ++i) {
        std::cout << "ID: " << i << ", Nome: " << cidades[i]->getNome() << "\n";
    }

    std::cout << "\nDigite o ID da cidade onde o transporte está localizado: ";
    std::cin >> cidadeID;

    if (cidadeID >= 0 && cidadeID < static_cast<int>(cidades.size())) {
        transportes.push_back(new Transporte(nome, tipo, capacidade, velocidade, distanciaEntreDescansos, tempoDeDescanso, cidades[cidadeID]));
        std::cout << "\nTransporte cadastrado com sucesso!" << std::endl;
    } else {
        std::cerr << "\nID de cidade inválido. Cadastro de transporte falhou, tente novamente.\n";
    }
}
