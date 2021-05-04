#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "Partido.h"
#include "Candidato.h"
#include "Leitor.h"
#include "Eleicao.h"

using namespace std;

// void adicionaPartido( list<Partido*> partidos, Partido p){
//    partidos.push_back(p);
// }



int main () {

    string path = "./csv-exemplos/csv/ES/vitoria/candidatos.csv";
    ifstream file;
    file.open (path);
    if(!file.is_open()) cout<< "Could not open file";

    int numero;
	int votosNominais;
	string nome;
	string nomeUrna;
	Situacao situacao;
	Sexo sexo;
	//LocalDate 
    string dataNascimento;
	DestinoVoto destinoVoto;
	int numeroPartido;
	int idade;
    string aux;

    getline(file,aux);
    while (! file.eof())  {
        getline (file,aux, ',' );
        numero = stoi(aux);

        getline (file, aux, ',' );
        votosNominais = stoi(aux);

        getline (file, situacao, ',' );

        getline (file, nome, ',' );

        getline (file, nomeUrna, ',' );

        //! Criar parse para sexo/situacao/destinoVoto
        getline (file, sexo, ',' );

        getline (file, dataNascimento, ',' );

        getline (file, destinoVoto, ',' );

        getline (file, aux, ',' );
        numeroPartido = stoi(aux);
    }
    // &partido)ile, numero, ',' );
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

	
    int numero;
    int votosLegenda;
    string nome ;
    string sigla;
    string aux2;
    list<Partido> partidos;
    Eleicao eleicao;

    getline(file,aux2);
    while (! file.eof())  { 
        getline (file,aux2, ',' );
        numero = stoi(aux2);

        getline (file, aux2, ',' );
        votosLegenda = stoi(aux2);

        getline (file, nome, ',' );
        getline (file, sigla );



        Partido partido(nome,sigla,numero,votosLegenda);
    
        //cout << "Estou inserindo o partido: "+ partido.getSigla() << endl;
        
        eleicao.adicionaPartido(partido);
        //adicionaPartido(partido);
    }

    
    //cout << partidos.size() << endl;

    for(Partido p : eleicao.getPartidos())
        cout << p.getNome() << endl;


    file.close(); 

    
    return 0;
}