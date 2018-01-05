#ifndef OFERTA_H_
#define OFERTA_H_

#include <string>
#include <vector>
#include "data.h"
#include <queue>

using namespace std;


class Oferta {

private:
	string barco;
	unsigned int lotacaoMax;
	string destino;
	unsigned int lotacaoAtual;
	unsigned int distancia;
	Data data;
	unsigned int preco;
	unsigned int nif;
	Data ultima_data;

public:
	Oferta();
	/**
	*	@brief Construtor de uma oferta
	*   @param nif
	*   @param data
	*   @param destino
	*   @param barco
	*   @param lotacaoMax
	*   @param lotacaoAtual
	*/
	Oferta(unsigned int nif, string barco, unsigned int lotacaoMax, unsigned int lotacaoAtual, string destino, unsigned int distancia, Data data);
		/**
	*	@brief Altera o barco da oferta
	*   @param barco
	*/
	void setBarco(string barco);
	/**
	*	@brief Altera o preco da oferta
	*   @param preco
	*/
	void setPreco(int preco);
	/**
	*	@brief Altera a lotacao maxima da oferta
	*   @param lotacaoMax
	*/
	void setLotacaoMax(unsigned int lotacaoMax);
	/**
	*	@brief Altera a lotacao atual da oferta
	*   @param lotacaoAtual
	*/
	void setLotacaoAtual(unsigned int lotacaoAtual);
	/**
	*	@brief Altera o destino da oferta
	*   @param destino
	*/
	void setDestino(string destino);
	/**
	*	@brief Altera a distancia da oferta
	*   @param data
	*/
	void setData(Data data);
	/**
	*	@brief Altera o NIF do fornecedor ao qual corresponde a oferta
	*   @param nif
	*/
	void setDistancia(unsigned int distancia);
	/**
	*	@brief Devolve o barco da oferta
	*   @return barco
	*/
	void setNif(unsigned int nif);
	//bool operator < (const Oferta o2) const;
/**
	*	@brief Devolve a ultima data
	*   @return ultima data
	*/
	Data getUltimaData() const;
	/**
	*	@brief altera a ultima data
	*   @param ultima data
	*/
	void setUltimaData(Data data);
	/**
	*	@brief Devolve o barco da oferta
	*   @return barco
	*/
	string getBarco() const;
	/**
	*	@brief Devolve o preco da oferta
	*   @return preco
	*/
	int getPreco()const;
	/**
	*	@brief Devolve a data da oferta
	*   @return data
	*/
	Data getData() const;
	/**
	*	@brief Devolve o NIF do fornecedor ao qual corresponde a oferta
	*   @return nif
	*/
	unsigned int getNif() const;
	/**
	*	@brief Devolve a lotacao maxima da oferta
	*   @return lotacao maxima
	*/
	unsigned int getLotacaoMax() const;
	/**
	*	@brief Devolve o destino da oferta
	*   @return destino
	*/
	string getDestino() const;
	/**
	*	@brief Devolve a lotacao atual da oferta
	*   @return lotacao atual
	*/
	unsigned int getLotacaoAtual() const;
	/**
	*	@brief Devolve a distancia da oferta
	*   @return distancia
	*/
	unsigned int getDistancia() const;
/**
	*	@brief Adiciona uma pessoa a lotacao atual
	*/
	void addToLotacao();
	/**
	*	@brief Retira uma pessoa a lotacao atual
	*/
	void removeFromLotacao();
	/**
	*	@brief Overload do operador < 
	*/
	bool operator<(const Oferta & f2) const;
	/**
	*	@brief Permite ordenar uma oferta por distancia da viagem 
	*	@param f1
	*	@param f2
	*/
	bool ordenaDist(const Oferta & f1, const Oferta & f2);
	/**
	*	@brief Overload do operador ==
	*/
	bool operator ==(const Oferta &o2) const;

};


#endif /* OFERTA_H_ */
