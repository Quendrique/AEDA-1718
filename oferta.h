#ifndef OFERTA_H_
#define OFERTA_H_

#include <string>
#include <vector>
#include "data.h"

using namespace std;

class Oferta {

private:
	string barco; //nao estou a utilizar a class barco ainda
	unsigned int lotacaoMax; //deixa de ser necessario se utilizarmos a classe barco
	string destino;
	unsigned int lotacao;
	unsigned int distancia;
	Data data;

public:
	Oferta();
	Oferta(string barco, unsigned int lotacaoMax, string destino, Data data);
	void setBarco(string barco);
	void setLotacaoMax(unsigned int lotacaoMax);
	void setDestino(string destino);
	string getBarco() const;
	unsigned int getLotacaoMax() const;
	string getDestino() const;
	unsigned int getLotacao() const;
	void addToLotacao();

};


#endif /* OFERTA_H_ */
