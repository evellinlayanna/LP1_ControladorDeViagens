#include <iostream>
#include <string>
#include <vector>

class Cidade {
private:
  std::string nome;

public:
  Cidade(const std::string &nome) : nome(nome) {}
  std::string getNome() const { return nome; }
};
