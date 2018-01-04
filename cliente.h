#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <string>
#include <vector>
#include <iostream>
#include "oferta.h"
#include "reservas.h"


using namespace std;

class Cliente {

protected:
	string nome;
	unsigned int inativo; //alterei guardar no ficheiro de texto?!
	Data ultima_reserva; // acrecentei
	unsigned int NIF;
	string morada;
	vector<Reserva> reservas;
	size_t contadorReservas;
	

public:
	friend class clientesInativos;
	Cliente();
	Cliente(string nome, unsigned int NIF, string morada);
	void setNome(string nome);
	void setNIF(unsigned int NIF);
	void setMorada(string morada);
	void setUltimaReserva(Data data);
	void addReserva(Reserva reserva);
	vector<Reserva> getReservas()const;
	string getNome() const;
	unsigned int getNIF() const;
	string getMorada() const;
	void updateContadorReservas();
	size_t getContadorReservas();
	Data getUltimaReserva() const;
	virtual void printInfo() const;
	bool operator ==(const Cliente &c2);
	virtual void printPontos() const;
	virtual bool isRegistado() { return false; }
	virtual double getPontos() const;
	Reserva removeReservaByFornecedor(long double fornecedorNIF);
	Reserva removeReservaByIndex(unsigned int reserva);
	void removeReservaByOferta(Oferta o1);
	void printReservas() const;

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
class clientesInativos
{
	Cliente* clienterprt;
public:
	clientesInativos(Cliente* clienterprt);
	string getNome() const;
	string getMorada() const;
	unsigned int getNIF() const;
	void setMorada(string morada);
	//~clientesInativos();

private:

};

//////////////
/* EXCECOES */
//////////////

class SemReservas {
public:
	SemReservas() {};
};

#endif /* CLIENTE_H_ */
