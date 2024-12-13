#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <vector>

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
    Transporte(const std::string& nome, char tipo, int capacidade) 
        : nome(nome), tipo(tipo), capacidade(capacidade) {}

    std::string getNome() const { return nome; }
    char getTipo() const { return tipo; }
    int getCapacidade() const { return capacidade; }
    
    void setTipo(char novoTipo) { tipo = novoTipo; }
    void setCapacidade(int novaCapacidade) { capacidade = novaCapacidade; }

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
    Viagem(Cidade* origem, Cidade* destino, Transporte* transporte) 
        : origem(origem), destino(destino), transporte(transporte) {}

    void adicionarPassageiro(Passageiro* passageiro) { passageiros.push_back(passageiro); }
    Cidade* getOrigem() const { return origem; }
    Cidade* getDestino() const { return destino; }
    Transporte* getTransporte() const { return transporte; }
    const std::vector<Passageiro*>& getPassageiros() const { return passageiros; }
};


#endif CLASSES_H