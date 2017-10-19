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

public:
	Fornecedor();
	Fornecedor(string nome, unsigned int NIF, string morada);
	void setNome(string nome);
	void setNIF(unsigned int NIF);
	void setMorada(string morada);
	void addOferta(Oferta *ofertaNew); //necessario?
	void removeOferta(Oferta *ofertaRemove); //necessario? parametros errados?
	string getNome() const;
	unsigned int getNIF() const;
	string getMorada() const;
	vector<Oferta> getOfertas() const;

};



#endif /* FORNECEDOR_H_ */
