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
	unsigned long NIF;
	string morada;
	vector<Oferta> ofertas;
	unsigned int lucro;
	unsigned int precoKm; //preco por km
	vector<unsigned int> precoLot; //preco por cada escalao de lotacao; so ha 3 tipos: <20, <35 e <50
								   //vector<Data>datasIndisponiveis;

public:
	Fornecedor();
	/**
	*	@brief Construtor de um fornecedor
	*   @param nome 
	*   @param NIF 
	*   @param morada 
	*/
	Fornecedor(string nome, unsigned long NIF, string morada);
	/**
	*	@brief Altera o nome do fornecedor
	*   @param nome
	*/
	void setNome(string nome);
		/**
	*	@brief Altera o NIF do fornecedor
	*   @param NIF
	*/
	void setNIF(unsigned long NIF);
	/**
	*	@brief Altera a morada do fornecedor
	*   @param morada
	*/
	void setMorada(string morada);
	
	/**
	*	@brief Altera o preco por km do fornecedor
	*   @param precoKm
	*/
	void setPrecoKm(unsigned int precoKm);
	/**
	*	@brief Altera os precos por lotacao do fornecedor
	*   @param precoLot
	*/
	void setPrecoLot(vector<unsigned int> precoLot);
		/**
	*	@brief Adiciona uma oferta em tempo de execucao 
	*   @param nif
	*   @param data
	*   @param destino
	*   @param barco
	*   @param lotacaoMax
	*   @param lotacaoAtual
	*/
	int addOferta(unsigned int nif, Data data, string destino, string barco, unsigned int distancia, unsigned int lotacaoMax, unsigned int lotacaoAtual);
	/**
	*	@brief Adiciona uma oferta durante o carregamento inicial dos ficheiros de texto
	*   @param oferta
	*/
	int addOfertaInit(Oferta oferta);
	/**
	*	@brief Remove uma oferta 
	*   @param nif
	*   @param data
	*   @param destino
	*   @param barco
	*   @param lotacaoMax
	*   @param lotacaoAtual
	*/
	int removeOferta(unsigned int nif, Data data, string destino, unsigned int distancia, string barco, unsigned int lotacaoMax, unsigned int lotacaoAtual);;
	/**
	*	@brief Devolve o nome do fornecedor
	*   @return nome
	*/
	string getNome() const;
	/**
	*	@brief Devolve o lucro do fornecedor
	*   @return lucro
	*/
	unsigned int getLucro() const;
	/**
	*	@brief Devolve o NIF do fornecedor
	*   @return NIF
	*/
	unsigned long getNIF() const;
	/**
	*	@brief Devolve a morada do fornecedor
	*   @return NIF
	*/
	string getMorada() const;
	/**
	*	@brief Devolve ofertas do fornecedor
	*   @return ofertas
	*/
	vector<Oferta> getOfertas() const;
	/**
	*	@brief Devolve o apontador para uma ofertas
	*   @return apontador para oferta
	*/
	Oferta * getOfertaPointer(unsigned int i);
	/**
	*	@brief Devolve os precos por escalao de lotacao maxima 
	*   @return precos
	*/
	vector<unsigned int> getPrecoLot() const;
	/**
	*	@brief Devolve o preco por km 
	*   @return preco
	*/
	unsigned int getPrecoKm() const;
	/**
	*	@brief Imprime as ofertas do fornecedor
	*/
	void printOfertas() const;
	/**
	*	@brief Imprime as ofertas do fornecedor para um determinado destino
	*   @param destino
	*   @return true se encontrar alguma oferta, false caso contrario
	*/
	bool printOfertasByDestino(string destino) const; //retorna true se encontrar alguma oferta com o destino especificado
	/**
	*	@brief Imprime as ofertas do fornecedor para uma determinada data
	*   @param data
	*   @return true se encontrar alguma oferta, false caso contrario
	*/
	bool printOfertasByData(Data data) const; //retorna true se encontrar alguma oferta com a data especificada
	/**
	*	@brief Imprime a informacao sobre o fornecedor
	*/
	void printInfo() const;
	//void updateLucro(unsigned int sum);
	/**
	*	@brief Remove oferta
	*   @param i
	*/
	void removeOfertaMenu(unsigned int i);
	/**
	*	@brief Imprime o lucro do fornecedor
	*/
	void printLucro() const;
	/**
	*	@brief uptade oferta
	*/
	void updateOferta(const Oferta &o1);
        /**
	*	@brief Calcula o lucro do fornecedor
	*   @return lucro
	*/ 
	unsigned int calculaLucro();
	/**
	*	@brief Calcula as taxas a pagar ao fornecedor
	*   @return taxas
	*/
	unsigned int calculaTaxas() const;

};

/////////////////////////
/////// EXCECOES ////////
/////////////////////////

class OfertaInexistente {
public:
	unsigned int i;
	OfertaInexistente(unsigned int i) { this->i = i; }
	unsigned int getI() const { return i; }
};


#endif /* FORNECEDOR_H_ */
