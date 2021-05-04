
#ifndef ELEICAO_H
#define ELEICAO_H

#include <string>
#include <list>
#include <iostream>

#include "Partido.h"

using namespace std;

class Eleicao {
    list<Partido> partidos;

public:
    Eleicao();

    //retorno lista partidos
    const list<Partido> getPartidos() const;

    void adicionaPartido(Partido part);

};

#endif /* ELEICAO_H */