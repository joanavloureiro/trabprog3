#include <iostream>
#include <fstream>
#include <string>
#include "Leitor.h"
#include "Partido.h"
#include "Candidato.h"

Leitor ::Leitor (){
    
}

const list<Candidato*>& Leitor::LeCandidatos() const {

    string path = "./csv-exemplos/csv/ES/vitoria/canbdidatos.csv";
    ifstream file;
    file.open (path);
  string value;
    while (file.good())    
        getline (file, value, ',' );
    cout << string ( value) << endl;
    file.close();    
    system("PAUSE");
    //return 0;

}



 Situacao parseSituacao(string situacao) {
	if(!situacao.compare("Eleito"))return ELEITO;
	if(!situacao.compare("Não Eleito"))return NAO_ELEITO;
	return SUPLENTE ;
}


 DestinoVoto parseDestinoVoto(string destinoVoto) {
	if(!destinoVoto.compare("Válido"))return VALIDO;
	if(!destinoVoto.compare("Anulado"))return ANULADO;
	return ANULADO_SUB_JUD ;
}	
 Sexo parseSexo(char sexo) {
	if(sexo == 'F') return FEMININO;
	return MASCULINO;
}