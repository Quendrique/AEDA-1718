#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <string>
#include <vector>

using namespace std;

class Cliente {

protected:
	string nome;
	unsigned int NIF;
	string morada;

public:
	Cliente();
	Cliente(string nome, unsigned int NIF, string morada);
	void setNome(string nome);
	void setNIF(unsigned int NIF);
	void setMorada(string morada);
	string getNome() const;
	unsigned int getNIF() const;
	string getMorada() const;

};


class ClienteReg: public Cliente {

private:
	unsigned int pontos;

public:
	ClienteReg(string nome, unsigned int NIF, string morada);
};

#endif /* CLIENTE_H_ */
