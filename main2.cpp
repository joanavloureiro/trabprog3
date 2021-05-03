#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "Partido.h"
#include "Candidato.h"
#include "Leitor.h"

using namespace std;

int main () {

    // string path = "./csv-exemplos/csv/ES/vitoria/candidatos.csv";
    // ifstream file;
    // file.open (path);
    // if(!file.is_open()) cout<< "Could not open file";

    // while (file.good())  { 
    //     getline (file, numero, ',' );
    //     getline (file, votosNominais, ',' );
    //     getline (file, situacao, ',' );
    //     getline (file, nome, ',' );
    //     getline (file, nomeUrna, ',' );
    //     getline (file, sexo, ',' );
    //     getline (file, dataNascimento, ',' );
    //     getline (file, destinoVoto, ',' );
    //     getline (file, numeroPartido, ',' );

    // }
    // file.close();    



    string path = "./csv-exemplos/csv/ES/vitoria/partidos.csv";
    ifstream file;
    file.open (path);
    if(!file.is_open()) cout<< "Could not open file";

	
    list<Partido*> partidos;
    int numero;
    int votosLegenda;
    string nome ;
    string sigla;
    string aux;

    int i = 0;

    getline(file,aux);
    while (! file.eof())  { 
        getline (file,aux, ',' );
        numero = stoi(aux);
        //cout<<  aux ;

        getline (file, aux, ',' );
        votosLegenda = stoi(aux);
        //cout<< ", " + aux ;

        getline (file, nome, ',' );
        //cout<< ", " + nome ;

        getline (file, sigla );
        //cout<< ", " +  sigla <<endl;



        Partido partido(nome,sigla,numero,votosLegenda);
        partidos.push_back(&partido);

    }

    
    // for(Partido* p : partidos)
    //     cout << p->getNome() << endl;
    list<Partido*>::iterator iter ;
    for(iter = partidos.begin(); iter != partidos.end(); iter++){
            Partido* p  = *iter;
             cout << p->getNome() << endl;
    }

    file.close(); 

    
    return 0;
}