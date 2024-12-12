#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class Cidade {
private:
    std::string nome;
    
public:
    Cidade(const std::string& nome) : nome(nome) {}
    std::string getNome() const { return nome; }
};

class Trajeto {
private:
    Cidade* origem;
    Cidade* destino;
    char tipo; // A aquático, T terrestre
    int distancia;
    
public:
    Trajeto(Cidade* origem, Cidade* destino, char tipo, int distancia)
        : origem(origem), destino(destino), tipo(tipo), distancia(distancia) {}
    Cidade* getOrigem() const { return origem; }
    Cidade* getDestino() const { return destino; }
    char getTipo() const { return tipo; }
    int getDistancia() const { return distancia; }
};

class Transporte {
private:
    std::string nome;
    char tipo; // A aquático, T terrestre
    int capacidade;
    
public:
    Transporte(const std::string& nome, char tipo, int capacidade) : nome(nome), tipo(tipo), capacidade(capacidade) {}
    std::string getNome() const { return nome; }
    char getTipo() const { return tipo; }
    int getCapacidade() const { return capacidade; }
};

class Passageiro {
private:
    std::string nome;
    
public:
    Passageiro(const std::string& nome) : nome(nome) {}
    std::string getNome() const { return nome; }
};

class Viagem {
private:
    Cidade* origem;
    Cidade* destino;
    Transporte* transporte;
    std::vector<Passageiro*> passageiros;
    
public:
    Viagem(Cidade* origem, Cidade* destino, Transporte* transporte) : origem(origem), destino(destino), transporte(transporte) {}
    void adicionarPassageiro(Passageiro* passageiro) { passageiros.push_back(passageiro); }
    Cidade* getOrigem() const { return origem; }
    Cidade* getDestino() const { return destino; }
    Transporte* getTransporte() const { return transporte; }
    const std::vector<Passageiro*>& getPassageiros() const { return passageiros; }
};

void salvarCidades(const std::vector<Cidade*>& cidades) {
    std::ofstream arquivo("cidades.xls");
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo cidades.xls." << std::endl;
        return;
    }
    arquivo << "ID\tNome\n";
    for (size_t i = 0; i < cidades.size(); ++i) {
        arquivo << i << "\t" << cidades[i]->getNome() << "\n";
    }
    arquivo.close();
    std::cout << "Cidades salvas com sucesso." << std::endl;
}

void salvarTrajetos(const std::vector<Trajeto*>& trajetos) {
    std::ofstream arquivo("trajetos.xls");
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo trajetos.xls." << std::endl;
        return;
    }
    arquivo << "Origem\tDestino\tTipo\tDistancia\n";
    for (const auto& trajeto : trajetos) {
        arquivo << trajeto->getOrigem()->getNome() << "\t"
                << trajeto->getDestino()->getNome() << "\t"
                << trajeto->getTipo() << "\t"
                << trajeto->getDistancia() << "\n";
    }
    arquivo.close();
    std::cout << "Trajetos salvos com sucesso." << std::endl;
}

void salvarTransportes(const std::vector<Transporte*>& transportes) {
    std::ofstream arquivo("transportes.xls");
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo transportes.xls." << std::endl;
        return;
    }
    arquivo << "Nome\tTipo\tCapacidade\n";
    for (const auto& transporte : transportes) {
        arquivo << transporte->getNome() << "\t"
                << transporte->getTipo() << "\t"
                << transporte->getCapacidade() << "\n";
    }
    arquivo.close();
    std::cout << "Transportes salvos com sucesso." << std::endl;
}

void salvarPassageiros(const std::vector<Passageiro*>& passageiros) {
    std::ofstream arquivo("passageiros.xls");
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo passageiros.xls." << std::endl;
        return;
    }
    arquivo << "Nome\n";
    for (const auto& passageiro : passageiros) {
        arquivo << passageiro->getNome() << "\n";
    }
    arquivo.close();
    std::cout << "Passageiros salvos com sucesso." << std::endl;
}

void salvarViagens(const std::vector<Viagem*>& viagens) {
    std::ofstream arquivo("viagens.xls");
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo viagens.xls." << std::endl;
        return;
    }
    arquivo << "Origem\tDestino\tTransporte\tPassageiros\n";
    for (const auto& viagem : viagens) {
        arquivo << viagem->getOrigem()->getNome() << "\t"
                << viagem->getDestino()->getNome() << "\t"
                << viagem->getTransporte()->getNome() << "\t";

        for (const auto& passageiro : viagem->getPassageiros()) {
            arquivo << passageiro->getNome() << ",";
        }
        arquivo << "\n";
    }
    arquivo.close();
    std::cout << "Viagens salvas com sucesso." << std::endl;
}

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
        std::cout << "6. Salvar Dados\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        if (opcao == 1) {
            std::string nome;
            std::cout << "Digite o nome da cidade: ";
            std::cin >> nome;
            cidades.push_back(new Cidade(nome));
        } else if (opcao == 2) {
            int origem, destino, distancia;
            char tipo;
            
            std::cout << "\nCidades cadastradas:\n";
            for (size_t i = 0; i < cidades.size(); ++i) {
                std::cout << "ID: " << i << ", Nome: " << cidades[i]->getNome() << "\n";
            }
            
            std::cout << "Escolha a cidade de origem (ID): ";
            std::cin >> origem;
            std::cout << "Escolha a cidade de destino (ID): ";
            std::cin >> destino;
            std::cout << "Digite o tipo de trajeto (A/T): ";
            std::cin >> tipo;
            std::cout << "Digite a distancia em km: ";
            std::cin >> distancia;
            
            trajetos.push_back(new Trajeto(cidades[origem], cidades[destino], tipo, distancia));
        } else if (opcao == 3) {
            std::string nome;
            char tipo;
            int capacidade;
            std::cout << "Digite o nome do transporte: ";
            std::cin >> nome;
            std::cout << "Digite o tipo (A/T): ";
            std::cin >> tipo;
            std::cout << "Digite a capacidade: ";
            std::cin >> capacidade;
            transportes.push_back(new Transporte(nome, tipo, capacidade));
        } else if (opcao == 4) {
            std::string nome;
            std::cout << "Digite o nome do passageiro: ";
            std::cin >> nome;
            passageiros.push_back(new Passageiro(nome));
        } else if (opcao == 5) {
            int origem, destino, transporte;
            std::cout << "Escolha a cidade de origem (ID): ";
            std::cin >> origem;
            std::cout << "Escolha a cidade de destino (ID): ";
            std::cin >> destino;
            std::cout << "Escolha o transporte (ID): ";
            std::cin >> transporte;

            Viagem* viagem = new Viagem(cidades[origem], cidades[destino], transportes[transporte]);

            int numPassageiros;
            std::cout << "Quantos passageiros na viagem? ";
            std::cin >> numPassageiros;

            for (int i = 0; i < numPassageiros; ++i) {
                int passageiroID;
                std::cout << "Escolha o passageiro (ID): ";
                std::cin >> passageiroID;
                viagem->adicionarPassageiro(passageiros[passageiroID]);
            }

            viagens.push_back(viagem);
        } else if (opcao == 6) {
            salvarCidades(cidades);
            salvarTrajetos(trajetos);
            salvarTransportes(transportes);
            salvarPassageiros(passageiros);
            salvarViagens(viagens);
        }

    } while (opcao != 0);

    for (auto cidade : cidades) delete cidade;
    for (auto trajeto : trajetos) delete trajeto;
    for (auto transporte : transportes) delete transporte;
    for (auto passageiro : passageiros) delete passageiro;
    for (auto viagem : viagens) delete viagem;

    return 0;
}
