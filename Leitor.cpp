#include <iostream>
#include <fstream>
#include <string>
#include "Leitor.h"
#include "Partido.h"
#include "Candidato.h"
#include "Eleicao.h"

Leitor ::Leitor (){
    
}

const list<Candidato*>& Leitor::LeCandidatos() const {

    list<Candidato*> candidatos;
    return candidatos;

}

const list<Partido*>& Leitor::LePartidos(ifstream file) const {
    //string path = "./csv-exemplos/csv/ES/vitoria/partidos.csv";
    //ifstream file;
    //file.open (path);
    //if(!file.is_open()){ 
    //    cout<< "Could not open file" << endl;
     //   trhow ;
    //}

	
    int numero;
    int votosLegenda;
    string nome ;
    string sigla;
    string aux2;
    list<Partido> partidos;
    Eleicao eleicao;
    string line;

    getline(file,aux2);
    
    while (! file.eof())  { 
        getline (file,aux2, ',' );
        //cout <<"numero: " + aux2 ;
        numero = stoi(aux2);

        getline (file, aux2, ',' );
        //cout << "vl: " + aux2 << endl;
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

}


 Situacao Leitor ::parseSituacao(string situacao) {
	if(!situacao.compare("Eleito"))return ELEITO;
	if(!situacao.compare("Não Eleito"))return NAO_ELEITO;
	return SUPLENTE ;
}


 DestinoVoto Leitor ::parseDestinoVoto(string destinoVoto) {
	if(!destinoVoto.compare("Válido"))return VALIDO;
	if(!destinoVoto.compare("Anulado"))return ANULADO;
	return ANULADO_SUB_JUD ;
}	
 Sexo Leitor ::parseSexo(string sexo) {
	if(!sexo.compare("F"))return FEMININO;
	return MASCULINO;
}