#ifndef LEITOR_H
#define LEITOR_H

#include <string>
#include <list>
#include "Candidato.h"
#include "Partido.h"

using namespace std;

class Leitor {

    public:
        Leitor();

        const list<Candidato*>& LeCandidatos() const;
        const list<Partido*>& LePartidos() const;
        Situacao parseSituacao(string situacao);	
        DestinoVoto parseDestinoVoto(string destinoVoto);
        Sexo parseSexo(char sexo) ;
};
#endif /* LEITOR_H */