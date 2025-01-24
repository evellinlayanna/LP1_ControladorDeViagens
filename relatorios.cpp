#include "relatorios.h"
#include "classes.h"
#include <ctime>
#include <iostream>
#include <vector>

tm stringParaHora(const std::string &dataHora) {
  tm hora = {};
  strptime(dataHora.c_str(), "%d/%m/%Y %H:%M", &hora);
  return hora;
}

void Relatorio::mostrarRelatorios(std::vector<Passageiro *> &passageiros,
                                  std::vector<Transporte *> &transportes,
                                  std::vector<Viagem *> &viagens,
                                  std::vector<Cidade *> &cidades) {

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

      std::cout << "\n~~ Relatório de Passageiros ~~\n";
      for (size_t i = 0; i < passageiros.size(); ++i) {
        Passageiro *passageiro = passageiros[i];
        std::cout << "\nPassageiro: " << passageiro->getNome() << "\n";

        // Verifica se o passageiro está em uma viagem
        bool emViagem = false;
        Viagem *viagemAtual = nullptr;
        for (Viagem *viagem : viagens) {
          for (Passageiro *p : viagem->getPassageiros()) {
            if (p == passageiro) {
              emViagem = true;
              viagemAtual = viagem;
              break;
            }
          }
          if (emViagem)
            break;
        }

        if (emViagem) {
          // O passageiro está em trânsito (em viagem)
          std::cout << "\nStatus: Em Trânsito (Viagem)\n";
          std::cout << "Origem: " << viagemAtual->getOrigem()->getNome()
                    << "\n";
          std::cout << "Destino: " << viagemAtual->getDestino()->getNome()
                    << "\n";
          std::cout << "Transporte: " << viagemAtual->getTransporte()->getNome()
                    << "\n";
          std::cout << "Tipo de Transporte: "
                    << viagemAtual->getTransporte()->getTipo() << "\n";
        } else {
          // O passageiro está na cidade
          std::cout << "Status: Na Cidade\n";
          // std::cout << "Cidade atual: " <<
          // passageiro->getCidadeAtual()->getNome() << "\n";
        }

        std::cout << "\n";
      }
      break;

    case 2:
      if (transportes.empty()) {
        std::cout << "\nNenhum transporte cadastrado no sistema.\n";
        break;
      }

      std::cout << "\n~~ Relatório de Transportes ~~\n";
      for (size_t i = 0; i < transportes.size(); ++i) {
        Transporte *transporte = transportes[i];
        std::cout << "\nTransporte: " << transporte->getNome() << "\n";

        // Verifica se o transporte está em uma viagem
        bool emViagem = false;
        Viagem *viagemAtual = nullptr;
        for (Viagem *viagem : viagens) {
          if (viagem->getTransporte() == transporte) {
            emViagem = true;
            viagemAtual = viagem;
            break;
          }
        }

        if (emViagem) {
          std::cout << "Status: Em trânsito de "
                    << viagemAtual->getOrigem()->getNome() << " para "
                    << viagemAtual->getDestino()->getNome() << "\n";
        } else {
          std::cout << "Status: Na cidade "
                    << transporte->getCidadeAtual()->getNome() << "\n";
        }

        std::cout << "\n";
      }
      break;

    case 3:
      if (viagens.empty()) {
        std::cout << "\nNenhuma viagem cadastrada no sistema.\n";
        break;
      }

      std::cout << "\n~~ Relatório de Viagens ~~\n";
      for (size_t i = 0; i < viagens.size(); ++i) {
        Viagem *viagem = viagens[i];
        std::cout << "Viagem: \n";
        std::cout << "Origem: " << viagem->getOrigem()->getNome() << "\n";
        std::cout << "Destino: " << viagem->getDestino()->getNome() << "\n";
        std::cout << "Transporte: " << viagem->getTransporte()->getNome()
                  << "\n";
        std::cout << "Tipo de Transporte: "
                  << viagem->getTransporte()->getTipo() << "\n";
        std::cout << "Passageiros: \n";
        for (Passageiro *p : viagem->getPassageiros()) {
          std::cout << "- " << p->getNome() << "\n";
        }

        // Converte a string para tm
        std::string horaPartidaStr =
            viagem->getHoraPartida(); // Pega a hora como string
        tm horaPartida =
            stringParaHora(horaPartidaStr); // Converte a string para tm
        std::cout << "Data e Hora de Partida: " << horaPartida.tm_mday << "/"
                  << horaPartida.tm_mon + 1 << "/" << horaPartida.tm_year + 1900
                  << " " << horaPartida.tm_hour << ":"
                  << (horaPartida.tm_min < 10 ? "0" : "") << horaPartida.tm_min
                  << "\n";

        // Calcula a previsão de chegada
        tm horaChegada = viagem->calcularPrevisaoChegada();

        std::cout << "Previsão de Chegada: " << horaChegada.tm_mday << "/"
                  << horaChegada.tm_mon + 1 << "/" << horaChegada.tm_year + 1900
                  << " " << horaChegada.tm_hour << ":"
                  << (horaChegada.tm_min < 10 ? "0" : "") << horaChegada.tm_min
                  << "\n";

        std::cout << "\n";
      }
      break;

    case 4:
      if (cidades.empty()) {
        std::cout << "\nNenhuma cidade cadastrada no sistema.\n";
        break;
      }

      std::cout << "\n~~ Relatório de Cidades ~~\n";
      for (size_t i = 0; i < cidades.size(); ++i) {
        Cidade *cidade = cidades[i];
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
