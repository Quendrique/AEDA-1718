#ifndef FORNECEDOR_H_
#define FORNECEDOR_H_

#include <string>
#include <vector>
#include "oferta.h"

using namespace std;

class Fornecedor {
private:
	string nome;
	unsigned int NIF;
	string morada;
	vector<Oferta> ofertas;
	unsigned int lucro;
	unsigned int precoKm; //preco por km
	vector<unsigned int> precoLot; //preco por cada escalao de lotacao
	vector<Data>datasIndisponiveis;

public:
	Fornecedor(string nome, unsigned int NIF, string morada);
	void setNome(string nome);
	void setNIF(unsigned int NIF);
	void setMorada(string morada);
	int addOferta(Data data, string destino, string barco, unsigned int lotacaoMax); //necessario?
	int removeOferta(Data data, string destino, string barco, unsigned int lotacaoMax); //necessario? parametros errados?
	string getNome() const;
	unsigned int getNIF() const;
	string getMorada() const;
	vector<Oferta> getOfertas() const;
	void printOfertas(ostream &os) const;
	friend ostream & operator <<(ostream &os, const Fornecedor &fornecedor);
	void updateLucro(unsigned int sum);

};



#endif /* FORNECEDOR_H_ */
