#ifndef OFERTA_H_
#define OFERTA_H_

#include <string>
#include <vector>
#include "data.h"

using namespace std;

class Oferta {

private:
	string barco;
	unsigned int lotacaoMax;
	string destino;
	unsigned int lotacaoAtual;
	unsigned int distancia;
	Data data;
	unsigned int nif;

public:
	Oferta();
	Oferta(string barco, unsigned int lotacaoMax, unsigned int lotacaoAtual, string destino, Data data);
	void setBarco(string barco);
	void setLotacaoMax(unsigned int lotacaoMax);
	void setLotacaoAtual(unsigned int lotacaoAtual);
	void setDestino(string destino);
	void setData(Data data);
	void setDistancia(unsigned int distancia);
	void setNif(unsigned int nif);

	string getBarco() const;
	Data getData() const;
	unsigned int getNif() const;
	unsigned int getLotacaoMax() const;
	string getDestino() const;
	unsigned int getLotacaoAtual() const;
	unsigned int getDistancia() const;

	void addToLotacao();
	bool operator<(const Oferta & f2) const;
	bool ordenaDist(const Oferta & f1, const Oferta & f2);
	bool operator ==(const Oferta &o2);

};


#endif /* OFERTA_H_ */
