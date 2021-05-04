#include "Eleicao.h"
#include <string>

Eleicao::Eleicao(){

}

void Eleicao::adicionaPartido(Partido part){
    partidos.push_back(part);
}

const list<Partido> Eleicao::getPartidos() const {
    return partidos;
}
	

