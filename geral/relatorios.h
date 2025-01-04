#ifndef RELATORIOS_H
#define RELATORIOS_H

#include <vector>
#include "classes.h"

class Relatorio {
public:
    void mostrarRelatorios(std::vector<Passageiro*>& passageiros, std::vector<Transporte*>& transportes, std::vector<Viagem*>& viagens, std::vector<Cidade*>& cidades);
};

#endif // RELATORIOS_H
