#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <string>
#include <vector>
#include <iostream>
#include "oferta.h";

using namespace std;

class Cliente {

protected:
	string nome;
	unsigned int NIF;
	string morada;
	vector<Oferta *> reservas;
	

public:
	Cliente();
	Cliente(string nome, unsigned int NIF, string morada);
	void setNome(string nome);
	void setNIF(unsigned int NIF);
	void setMorada(string morada);
	void addReserva(Oferta *reserva);
	vector< Oferta *> getReservas()const;
	string getNome() const;
	unsigned int getNIF() const;
	string getMorada() const;
	virtual void printInfo() const;
	bool operator ==(const Cliente &c2);
	virtual void printPontos() const;
	virtual bool isRegistado() { return false; }
	virtual double getPontos() const;
	void removeReservaByFornecedor(long double fornecedorNIF);

};


class ClienteReg: public Cliente {

private:
	unsigned int pontos;

public:
	ClienteReg(string nome, unsigned int NIF, string morada,double pontos);
	void setPontos(double pontos);
	double getPontos();
	void printInfo() const;
	void printPontos() const;
	bool isRegistado() { return true; }
};

#endif /* CLIENTE_H_ */
