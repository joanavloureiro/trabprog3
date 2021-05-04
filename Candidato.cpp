#include "Candidato.h"
#include "Enum.cpp"

Candidato::Candidato(int numero, int votosNominais, string nome,  string nomeUrna, Situacao situacao, Sexo sexo, DestinoVoto destinoVoto, int numeroPartido, int idade){
    this->numero = numero;
		this->votosNominais = votosNominais;
		this->nome = nome;
		this->nomeUrna = nomeUrna;
		this->situacao = situacao;
		this->sexo = sexo;
		//this->dataNascimento = dataNascimento;
		this->destinoVoto = destinoVoto;
		this->numeroPartido = numeroPartido;
		this->idade = idade;
}

string Candidato::getNome() const{
    return nome;
}

void Candidato::setNome(const string &nome){
    this->nome = nome;
}

string Candidato::getNomeUrna() const{
    return nomeUrna;
}

void Candidato::setNomeUrna(const string &nomeUrna){
    this->nomeUrna = nomeUrna;
}

int Candidato::getNumero() const{
    return numero;
}

void Candidato::setNumero(const int &numero){
    this->numero = numero;
}

int Candidato::getVotosNominais() const{
    return votosNominais;
}

void Candidato::setVotosNominais(const int &votosNominais){
    this->votosNominais = votosNominais;
}

int Candidato::getNumeroPartido() const{
    return numeroPartido;
}

void Candidato::setNumeroPartido(const int &numeroPartido){
    this->numeroPartido = numeroPartido;
}

int Candidato::getIdade() const{
    return idade;
}

void Candidato::setIdade(const int &idade){
    this->idade = idade;
}

Situacao Candidato::getSituacao() {
	return situacao;
}


void Candidato::setSituacao(Situacao situacao) {
	this->situacao = situacao;
}


Sexo Candidato::getSexo() {
	return sexo;
}


void Candidato::setSexo(Sexo sexo) {
	this->sexo = sexo;
}


//? LocalDate Candidato::getDataNascimento() {
//? 	return dataNascimento;
//? }


//? void Candidato::setDataNascimento(LocalDate dataNascimento) {
//? 	this->dataNascimento = dataNascimento;
//? }

string Candidato::getDataNascimento() const{
    return dataNascimento;
}

void Candidato::setDataNascimento(const string &data){
    this->dataNascimento = data;
}

DestinoVoto Candidato::getDestinoVoto() {
	return destinoVoto;
}


void Candidato::setDestinoVoto(DestinoVoto destinoVoto) {
	this->destinoVoto = destinoVoto;
}

// int Candidato::ComparadorVotosDesempateMaiorIdade(Candidato &c1, Candidato &c2) {
// 		int votosC1 = c1->getVotosNominais() ;
// 		int votosC2 = c2->getVotosNominais() ;
		
// 		if(votosC1 == votosC2)
// 			return c2->getIdade()-(c1->getIdade());
		
// 		return votosC2 - votosC1;
// 	}
	
// }


// int Candidato::ComparadorVotosDesempateMenorNumeroPartidario(Candidato c1, Candidato c2) {
// 		int votosC1 = c1->getVotosNominais() ;
// 		int votosC2 = c2->getVotosNominais() ;
		
// 		if(votosC1 == votosC2) {
// 			int numC1 = c1->getNumeroPartido();
// 			int numC2 = c2->getNumeroPartido();
			
// 			if(numC1 == numC2) 
// 				return c2->getIdade() - c1.getIdade();
			
// 			return numC1 -numC2;
// 		}
			
// 		return votosC2 - votosC1;
// 	}
	
// }
