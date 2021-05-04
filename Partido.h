
#ifndef PARTIDO_H
#define PARTIDO_H

#include <string>
#include <list>
#include <iostream>

#include "Candidato.h"

using namespace std;

class Partido {
    string nome;
    string sigla;
    int numero;
    int votosLegenda;
    list<Candidato> candidatos;

public:
    Partido(string nome, string sigla, int numero, int votosLegenda);

    string getNome() const;
    void setNome(const string &nome);

    string getSigla() const;
    void setSigla(const string &sigla);

    int getNumero() const;
    void setNumero(const int &numero);

    int getVotosLegenda() const;
    void setVotosLegenda(const int &votosLegenda);

    //retorno lista candidatos
    const list<Candidato> getCandidatos() const;

    void adicionaCandidato(Candidato cand);

    //void criaPartido(const string &nome);

    int getTotalVotosNominais();
    
    int getTotalEleitos() const;
};

#endif /* PARTIDO_H */