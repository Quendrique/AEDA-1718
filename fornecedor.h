#ifndef FORNECEDOR_H_
#define FORNECEDOR_H_

#include <string>
#include <vector>
#include <iostream>
#include "oferta.h"

using namespace std;

class Fornecedor {
private:
	string nome;
	long double NIF;
	string morada;
	vector<Oferta> ofertas;
	unsigned int lucro;
	unsigned int precoKm; //preco por km
	vector<unsigned int> precoLot; //preco por cada escalao de lotacao; so ha 3 tipos: <20, <35 e <50
	vector<Data>datasIndisponiveis;

public:
	Fornecedor();
	Fornecedor(string nome, long double NIF, string morada);
	void setNome(string nome);
	void setNIF(unsigned int NIF);
	void setMorada(string morada);
	int addOferta(Data data, string destino, string barco, unsigned int lotacaoMax); //necessario?
	int addOfertaInit(Oferta oferta);
	int removeOferta(Data data, string destino, string barco, unsigned int lotacaoMax); //necessario? parametros errados?
	string getNome() const;
	unsigned int getLucro() const;
	unsigned int getNIF() const;
	string getMorada() const;
	vector<Oferta> getOfertas() const;
	void printOfertas() const ;
	bool printOfertasByDestino(string destino) const; //retorna true se encontrar alguma oferta com o destino especificado
	bool printOfertasByData(Data data) const; //retorna true se encontrar alguma oferta com a data especificada
	void printInfo() const;
	//void updateLucro(unsigned int sum);
	void removeOfertaMenu(unsigned int i);
	int calculaLucro();
	void printLucro() const;
	void updateOferta(const Oferta &o1);

};

/////////////////////////
/////// EXCECOES ////////
/////////////////////////

class OfertaInexistente {
public:
	unsigned int i;
	OfertaInexistente(unsigned int i) {this->i=i;}
	unsigned int getI() const {return i;}
};


#endif /* FORNECEDOR_H_ */
