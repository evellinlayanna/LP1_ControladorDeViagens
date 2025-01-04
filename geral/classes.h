#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <vector>

class Cidade {
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
    double velocidade; // Velocidade em Km/h
    double distanciaEntreDescansos; // Distância máxima antes do descanso (Km)
    double tempoDeDescanso; // Tempo de descanso em horas
    Cidade* cidadeAtual; // Cidade onde o veículo está atualmente

public:
    Transporte(const std::string& nome, char tipo, int capacidade, double velocidade, double distanciaEntreDescansos, double tempoDeDescanso, Cidade* cidadeAtual)
        : nome(nome), tipo(tipo), capacidade(capacidade), velocidade(velocidade), distanciaEntreDescansos(distanciaEntreDescansos), tempoDeDescanso(tempoDeDescanso), cidadeAtual(cidadeAtual) {}

    std::string getNome() const { return nome; }
    char getTipo() const { return tipo; }
    int getCapacidade() const { return capacidade; }
    double getVelocidade() const { return velocidade; }
    double getDistanciaEntreDescansos() const { return distanciaEntreDescansos; }
    double getTempoDeDescanso() const { return tempoDeDescanso; }
    Cidade* getCidadeAtual() const { return cidadeAtual; }

    void setTipo(char novoTipo) { tipo = novoTipo; }
    void setCapacidade(int novaCapacidade) { capacidade = novaCapacidade; }
    void setVelocidade(double novaVelocidade) { velocidade = novaVelocidade; }
    void setDistanciaEntreDescansos(double novaDistancia) { distanciaEntreDescansos = novaDistancia; }
    void setTempoDeDescanso(double novoTempo) { tempoDeDescanso = novoTempo; }
    void setCidadeAtual(Cidade* novaCidade) { cidadeAtual = novaCidade; }
};

class Passageiro {
    std::string nome;
    Cidade* cidadeAtual;

public:
    Passageiro(const std::string& nome, Cidade* cidadeAtual = nullptr): nome(nome), cidadeAtual(cidadeAtual) {}
    std::string getNome() const { return nome; }
    Cidade* getCidadeAtual() const { return cidadeAtual; }
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


#endif // CLASSES_H
