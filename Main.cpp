#include <iostream>
#include <fstream>
#include <string>
#include "Partido.h"
#include "Candidato.h"
//#include "Leitor.h"
//#include "Enum.cpp"
using namespace std;

int main () {
    //Leitor leitor;
    //leitor.LeCandidatos();
    //ELEITO, FEMININO, VALIDO
    Candidato joana(177, 1010, "Joana", "JOJA", ELEITO, FEMININO, VALIDO, 12, 20), 
    mirelly(127, 1012, "Mirelly", "MIMI", ELEITO, FEMININO, VALIDO, 12, 20), 
    jp(177, 1014, "jp", "JOAO", ELEITO, FEMININO, VALIDO, 12, 29);

    Partido oi("OIE", "OI", 12, 123);

    oi.adicionaCandidato(joana);
    oi.adicionaCandidato(mirelly);
    oi.adicionaCandidato(jp);

    cout << oi.getNome();
    for(Candidato* c : oi.getCandidatos()){
        cout << c->getNome() << endl;
    }


    cout << oi.getTotalVotosNominais();
    //cout << joana.getVotosNominais();
    return 0;
}