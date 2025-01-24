#ifndef CLASSES_H
#define CLASSES_H

#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

// Cidade
class Cidade {
  std::string nome;

public:
  Cidade(const std::string &nome) : nome(nome) {}
  std::string getNome() const { return nome; }
};

// Trajeto
class Trajeto {
private:
  Cidade *origem;
  Cidade *destino;
  char tipo; // A aquático, T terrestre
  int distancia;

public:
  Trajeto(Cidade *origem, Cidade *destino, char tipo, int distancia)
      : origem(origem), destino(destino), tipo(tipo), distancia(distancia) {}
  Cidade *getOrigem() const { return origem; }
  Cidade *getDestino() const { return destino; }
  char getTipo() const { return tipo; }
  int getDistancia() const { return distancia; }
};

// Transopirte
class Transporte {
private:
  std::string nome;
  char tipo; // A aquático, T terrestre
  int capacidade;
  double velocidade;              // Velocidade em Km/h
  double distanciaEntreDescansos; // Distância máxima antes do descanso (Km)
  double tempoDeDescanso;         // Tempo de descanso em horas
  Cidade *cidadeAtual;            // Cidade onde o veículo está atualmente

public:
  Transporte(const std::string &nome, char tipo, int capacidade,
             double velocidade, double distanciaEntreDescansos,
             double tempoDeDescanso, Cidade *cidadeAtual)
      : nome(nome), tipo(tipo), capacidade(capacidade), velocidade(velocidade),
        distanciaEntreDescansos(distanciaEntreDescansos),
        tempoDeDescanso(tempoDeDescanso), cidadeAtual(cidadeAtual) {}

  std::string getNome() const { return nome; }
  char getTipo() const { return tipo; }
  int getCapacidade() const { return capacidade; }
  double getVelocidade() const { return velocidade; }
  double getDistanciaEntreDescansos() const { return distanciaEntreDescansos; }
  double getTempoDeDescanso() const { return tempoDeDescanso; }
  Cidade *getCidadeAtual() const { return cidadeAtual; }

  void setTipo(char novoTipo) { tipo = novoTipo; }
  void setCapacidade(int novaCapacidade) { capacidade = novaCapacidade; }
  void setVelocidade(double novaVelocidade) { velocidade = novaVelocidade; }
  void setDistanciaEntreDescansos(double novaDistancia) {
    distanciaEntreDescansos = novaDistancia;
  }
  void setTempoDeDescanso(double novoTempo) { tempoDeDescanso = novoTempo; }
  void setCidadeAtual(Cidade *novaCidade) { cidadeAtual = novaCidade; }
};

// Passageiro
class Passageiro {
  std::string nome;
  Cidade *cidadeAtual;

public:
  Passageiro(const std::string &nome, Cidade *cidadeAtual = nullptr)
      : nome(nome), cidadeAtual(cidadeAtual) {}
  std::string getNome() const { return nome; }
  Cidade *getCidadeAtual() const { return cidadeAtual; }
};

// Viagem
class Viagem {
private:
  Trajeto *trajeto;
  Transporte *transporte;
  std::vector<Passageiro *> passageiros;
  std::string dataHoraPartida;
  int distanciaPausa;
  int tempoDescanso;
  int velocidade;

public:
  Viagem(Trajeto *trajeto, Transporte *transporte, int distanciaPausa,
         int tempoDescanso, int velocidade)
      : trajeto(trajeto), transporte(transporte),
        distanciaPausa(distanciaPausa), tempoDescanso(tempoDescanso),
        velocidade(velocidade) {}

  Viagem(Trajeto *trajeto, Transporte *transporte)
      : trajeto(trajeto), transporte(transporte), distanciaPausa(100),
        tempoDescanso(30), velocidade(80) {}

  void adicionarPassageiro(Passageiro *passageiro) {
    passageiros.push_back(passageiro);
  }

  Cidade *getOrigem() const { return trajeto->getOrigem(); }
  Cidade *getDestino() const { return trajeto->getDestino(); }
  Transporte *getTransporte() const { return transporte; }
  const std::vector<Passageiro *> &getPassageiros() const {
    return passageiros;
  }
  Trajeto *getTrajeto() const { return trajeto; }

  const std::string &getHoraPartida() const { return dataHoraPartida; }

  void setDataHoraPartida(const std::string &dataHora) {
    dataHoraPartida = dataHora;
  }

  std::string getDataHoraPartida() const { return dataHoraPartida; }

  // Converte a string de data e hora para tm
  tm stringToTm(const std::string &dataHora) const {
    std::stringstream ss(dataHora);
    tm t = {};
    ss >> std::get_time(&t,
                        "%d/%m/%Y %H:%M"); // Formato: dd/mm/yyyy hh:mm
    return t;
  }

  int getDistancia() const { return trajeto->getDistancia(); }
  int getDistanciaPausa() const { return distanciaPausa; }
  int getTempoDescanso() const { return tempoDescanso; }
  int getVelocidade() const { return velocidade; }

  // Calcula a previsão de chegada
  tm calcularPrevisaoChegada(int distancia, int velocidade, int distanciaPausa,
                             int tempoDescanso,
                             const std::string &dataHoraPartida) const {
    // Calcula o número de pausas válidas
    int numeroPausas = distancia / distanciaPausa;
    if (distancia % distanciaPausa == 0) {
      numeroPausas--; // Desconsidera a última pausa, pois coincide com a
                      // chegada
    }

    // Calcula o tempo de viagem sem pausas
    double tempoViagemHoras = static_cast<double>(distancia) / velocidade;

    // Calcula o tempo total de descanso
    double tempoDescansoTotal = numeroPausas * tempoDescanso;

    // Calcula o tempo total de viagem
    double tempoTotalHoras = tempoViagemHoras + tempoDescansoTotal;

    // Converte dataHoraPartida (string) para tm
    tm tmHoraPartida = stringToTm(dataHoraPartida);
    time_t horaPartidaTime = mktime(&tmHoraPartida);

    // Calcula a previsão de chegada
    time_t horaChegadaTime =
        horaPartidaTime + static_cast<time_t>(tempoTotalHoras * 3600);

    // Converte time_t de volta para tm
    tm horaChegada;
    localtime_r(&horaChegadaTime, &horaChegada);

    return horaChegada;
  }

  // Calcular a previsão de chegada
  tm calcularPrevisaoChegada() const {
    return calcularPrevisaoChegada(getDistancia(), getVelocidade(),
                                   getDistanciaPausa(), getTempoDescanso(),
                                   getDataHoraPartida());
  }

  // Formato "dd/mm/yyyy hh:mm"
  std::string formatarDataHora(const tm &hora) const {
    std::stringstream ss;
    ss << std::put_time(&hora, "%d/%m/%Y %H:%M");
    return ss.str();
  }

  // Exibi o horário de partida e previsão de chegada formatados
  // void exibirRelatorio() const {
  //   tm horaPartida = stringToTm(dataHoraPartida);
  //   tm horaChegada = calcularPrevisaoChegada();

  //   std::cout << "Hora de Partida: " << formatarDataHora(horaPartida)
  //             << std::endl;
  //   std::cout << "Previsão de Chegada: " << formatarDataHora(horaChegada)
  //             << std::endl;
  // }
};

#endif // CLASSES_H
