#include "fornecedor.h"

Fornecedor::Fornecedor(string nome, unsigned int NIF, string morada) {
	this->nome=nome;
	this->NIF=NIF;
	this->morada=morada;
	lucro = 0;
}

void Fornecedor::setNome(string nome) {
	this->nome=nome;
}

void Fornecedor::setNIF(unsigned int NIF) {
	this->NIF=NIF;
}

void Fornecedor::setMorada(string morada) {
	this->morada=morada;
}

string Fornecedor::getNome() const {
	return nome;
}

unsigned int Fornecedor::getNIF() const {
	return NIF;
}

string Fornecedor::getMorada() const {
	return morada;
}

vector<Oferta> Fornecedor::getOfertas() const {
	return ofertas;
}

int Fornecedor::addOferta(Data data, string destino, string barco, unsigned int lotacaoMax) {
	Oferta * o1 = new Oferta(barco, lotacaoMax, destino, data);

	for (unsigned int i= 0; i < ofertas.size(); i++) {
		if (ofertas[i] == *o1)
			return 1;
	}
	ofertas.push_back(*o1);
	return 0;
}

int Fornecedor::removeOferta(Data data, string destino, string barco, unsigned int lotacaoMax) {
	Oferta o1(barco, lotacaoMax, destino, data);

	for(unsigned int i = 0 ; i < ofertas.size(); i++) {
		if (ofertas[i] == o1) {
			ofertas.erase(ofertas.begin()+1);
			return 0;
		}
	}
	return 1;
}

void Fornecedor::printOfertas() {

}

