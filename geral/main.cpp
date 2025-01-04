#include "cadastrar_cidade.h"
#include "cadastrar_passageiro.h"
#include "cadastrar_trajeto.h"
#include "cadastrar_transporte.h"
#include "cadastrar_viagem.h"
#include "carregar_dados.h"
#include "classes.h"
#include "relatorios.h"
#include "salvar_dados.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<Cidade *> cidades;
  std::vector<Trajeto *> trajetos;
  std::vector<Transporte *> transportes;
  std::vector<Passageiro *> passageiros;
  std::vector<Viagem *> viagens;

  int opcao;

  Relatorio relatorio;
  do {
    std::cout << "\n=== BEM VINDO AO CONTROLADOR DE VIAGENS ===\n";
    std::cout << "1. Cadastrar Cidade\n";
    std::cout << "2. Cadastrar Trajeto\n";
    std::cout << "3. Cadastrar Transporte\n";
    std::cout << "4. Cadastrar Passageiro\n";
    std::cout << "5. Cadastrar Viagem\n";
    std::cout << "6. Relatórios\n";
    std::cout << "7. Salvar Dados\n";
    std::cout << "8. Carregar Dados\n"; // Nova opção para carregar dados
    std::cout << "0. Sair\n";
    std::cout << "\nEscolha uma opção: ";
    std::cin >> opcao;

    switch (opcao) {
    case 1:
      cadastrarCidade(cidades);
      break;
    case 2:
      cadastrarTrajeto(cidades, trajetos);
      break;
    case 3:
      cadastrarTransporte(cidades, transportes);
      break;
    case 4:
      cadastrarPassageiro(passageiros, cidades);
      break;
    case 5:
      cadastrarViagem(trajetos, passageiros, viagens, transportes);
      break;
    case 6:
      relatorio.mostrarRelatorios(passageiros, transportes, viagens, cidades);
      break;
    case 7:
      salvarPassageirosEmPlanilha(passageiros, "passageiros.csv");
      salvarTransportesEmPlanilha(transportes, "transportes.csv");
      salvarCidadesEmPlanilha(cidades, "cidades.csv");
      break;
    case 8:
      carregarDados(cidades, passageiros, transportes, "cidades.csv",
                    "passageiros.csv", "transportes.csv");
      std::cout << "Dados carregados com sucesso!\n";
      break;
    case 0:
      break;
    default:
      std::cout << "\nOpção inválida!" << std::endl;
    }
  } while (opcao != 0);

  return 0;
}
