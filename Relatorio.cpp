#include "Relatorio.h"
#include "Ordenacao.h"
#include "Enum.cpp"
#include <vector>
#include <algorithm>
#include <iomanip>

Relatorio::Relatorio(){}

int Relatorio::NumeroVagas(vector<Partido> partidos) {
    int eleitos=0;
    for(Partido p : partidos) 
        for(Candidato c : p.getCandidatos()) 
            if(c.getSituacao() == ELEITO)
                eleitos++;
    
    return eleitos;
}

int Relatorio:: getIndexCandidato(vector<Candidato> candidatos,Candidato candidato) {
    for(int i=0; i< candidatos.size(); i++)
        if(candidatos[i].getNumero() == candidato.getNumero())
            return i;
        
    return -1;
}

int Relatorio:: getIndexPartido(vector<Partido> partidos,Partido partido) {
    for(int i=0; i< partidos.size(); i++)
        if(partidos[i].getNumero() == partido.getNumero())
            return i;
        
    return -1;
}

vector<Candidato> Relatorio::VereadoresEleitos(vector<Partido> partidos, Ordenacao ordenacao) {
    vector<Candidato> candidatos ;
    
    for(Partido p : partidos) 
        for(Candidato c : p.getCandidatos()) 
            if(c.getSituacao()== ELEITO)
                candidatos.push_back(c);


    ordenacao.OrdenaCadidatosVotos(candidatos);

    return candidatos;
}

vector<Candidato> Relatorio::VereadoresMaisVotados(vector<Candidato> candidatos,int vagas, Ordenacao ordenacao) {	
    ordenacao.OrdenaCadidatosVotos(candidatos);

    vector<Candidato> candidatosMaisVotados;
    for(int i=0; i<vagas;i++) 
        candidatosMaisVotados.push_back(candidatos[i]);

    return candidatosMaisVotados;
}

vector<Candidato> Relatorio::VereadoresMaisVotadosNaoEleitos(vector<Candidato> candidatos, int vagas, Ordenacao ordenacao) {		
    
    ordenacao.OrdenaCadidatosVotos(candidatos);

    vector<Candidato> candidatosMaisVotados;
    for(int i=0; i<vagas;i++) 		
        if(candidatos[i].getSituacao()!= ELEITO) 
            candidatosMaisVotados.push_back(candidatos[i]);
        
    return candidatosMaisVotados;
}

vector<Candidato> Relatorio::VereadoresEleitosBeneficiadosSistema(vector<Candidato> candidatos,vector<Partido>  partidos,int vagas, Ordenacao ordenacao){		
    Relatorio relatorio;
    
    ordenacao.OrdenaCadidatosVotos(candidatos);
    vector<Candidato> candidatosEBS;
    vector<Candidato> maisVotados = relatorio.VereadoresMaisVotados(candidatos,vagas, ordenacao);
    
    for(Candidato c:candidatos) 
        if(c.getSituacao()== ELEITO && relatorio.getIndexCandidato(maisVotados,c) == -1)
            candidatosEBS.push_back(c);

    return candidatosEBS;
}



void Relatorio:: printPartido(int index,Partido p) {
    int nominais =p.getTotalVotosNominais();
    int legendas = p.getVotosLegenda();
    int eleitos = p.getTotalEleitos();
    int total = legendas + nominais;
    
    string s1 = total>1?"s":"";
    string s2 = eleitos>1?"s":"";
    string s3 = nominais>1?"is":"l";
    printf("%d - %s - %d, %d voto%s (%d nomina%s e %d de legenda), %d candidato%s eleito%s\n", 
            index,p.getSigla().c_str(),p.getNumero(),total,s1.c_str(),nominais,s3.c_str(),legendas,eleitos,s2.c_str(),s2.c_str());
}


void Relatorio::printCandidato(int index,Candidato c,vector<Partido>  partidos) {
    Relatorio relatorio;
    cout << index <<" - " << c.getNome() <<" / " << c.getNomeUrna() <<
            " (" << relatorio.getPartidoByNumber(c.getNumeroPartido(), partidos) << ", " <<
            c.getVotosNominais() << " votos)" << endl;
}

string Relatorio::getPartidoByNumber(int numero, vector<Partido>  partidos) {
    for(Partido p : partidos) 
        if(numero == p.getNumero()) return p.getSigla();
    return "";
}


vector<Candidato> Relatorio::PrimeiroEUltimoColocados(Partido p) {
	vector<Candidato> candidatosPartido = p.getCandidatos();		
	if(candidatosPartido.size()<1) return candidatosPartido;
	
	Ordenacao ordenacao;

	ordenacao.OrdenaCandidatosVotosDesempateMenorNumeroPartido(candidatosPartido);
	
	vector<Candidato> candidatos ;	
	candidatos.push_back(candidatosPartido[0]);
	candidatos.push_back(candidatosPartido[candidatosPartido.size()-1]);
	return candidatos;
}


void Relatorio::printPartidoColocacoesCandidatos(int index, Partido p) {
	char str[256];
	Relatorio relatorio;

     if(p.getCandidatos().size() > 1){
    		sprintf(str,"%d - %s - %d, %s / %s\n", 
    				index,p.getSigla().c_str(),p.getNumero(),
    				formatedCandidatoSimples(relatorio.PrimeiroEUltimoColocados(p)[0]).c_str(),
    				formatedCandidatoSimples(relatorio.PrimeiroEUltimoColocados(p)[1]).c_str());

			printf("%s", str);
     }
	}
	
 string Relatorio::formatedCandidatoSimples(Candidato c) {
	string s = c.getVotosNominais()>1?"s":"";
	char str[256];
	sprintf(str,"%s (%d, %d voto%s)", c.getNomeUrna().c_str(),c.getNumero(),c.getVotosNominais(),s.c_str());

	string formated = str;
	return formated ;
}
	
void Relatorio:: printCandidatosFaixaetaria(vector<Candidato> candidatos, int vagas) {
	double i = 100.0/vagas;
	int eleitos[] = {0,0,0,0,0};

	for(Candidato c: candidatos){
		int idade = c.getIdade();

		if(idade<30) eleitos[0]++;
		else if(idade<40) eleitos[1]++;
		else if(idade<50) eleitos[2]++;
		else if(idade<60) eleitos[3]++;
		else eleitos[4]++;
	}

	cout << "      Idade < 30: "<<eleitos[0] <<" (" << fixed << setprecision(2) <<(eleitos[0]*i)<<"%)\n" << 
			"30 <= Idade < 40: "<<eleitos[1] <<" (" << fixed << setprecision(2) <<(eleitos[1]*i)<<"%)\n" << 
			"40 <= Idade < 50: "<<eleitos[2] <<" (" << fixed << setprecision(2) <<(eleitos[2]*i)<<"%)\n" << 
			"50 <= Idade < 60: "<<eleitos[3] <<" (" << fixed << setprecision(2) <<(eleitos[3]*i)<<"%)\n" << 
			"60 <= Idade"<<" "<<" "<<"   : "<<eleitos[4] <<" (" << fixed << setprecision(2) <<(eleitos[4]*i)<<"%)\n" ;
}
	
void Relatorio::printCandidatosPorGenero(vector<Candidato> candidatos,int vagas) {
	int f =0;
	int m = 0;
	double i = 100.0/vagas;
	
	for(Candidato c: candidatos)
		if(c.getSexo()== FEMININO) f++;
		else m++;
	
	
	cout <<	"Feminino:  " << f<<  " ("<< fixed << setprecision(2) <<(f*i)<< "%)\n" <<  
			"Masculino: " << m<<  " ("<< fixed << setprecision(2) <<(m*i)<< "%)";
}
	
void Relatorio:: printTotaisVotos(vector<Partido> partidos) {
	int nominais =0;
	int legendas =0;
	
	for(Partido p: partidos) {
		nominais += p.getTotalVotosNominais();
		legendas += p.getVotosLegenda();
	}
	int total = nominais+legendas;
	double i = 100.0/total;		 	
	
	cout<<	"\nTotal de votos v??lidos:    " << total    <<
			"\nTotal de votos nominais:   " << nominais << " ("<< fixed << setprecision(2) <<(nominais*i)<<"%)\n"
		<<    "Total de votos de Legenda: " << legendas << " ("<< fixed << setprecision(2) <<(legendas*i)<<"%)";
}
