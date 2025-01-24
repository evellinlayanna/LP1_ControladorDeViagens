#ifndef CADASTRAR_PASSAGEIRO_H
#define CADASTRAR_PASSAGEIRO_H

#include "classes.h"
#include <vector>

void cadastrarPassageiro(std::vector<Passageiro *> &passageiros,
                         const std::vector<Cidade *> &cidades);

#endif // CADASTRAR_PASSAGEIRO_H
