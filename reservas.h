#pragma once

#include <string>
#include "oferta.h"
#include "data.h"

using namespace std;

class Reserva {
private:
	Data data;
	unsigned long nif;
	string nomeCliente;
	Oferta* oferta;
	string fornecedor;
public:
	Reserva();
	/**
	*	@brief Construtor de uma reserva
	*   @param data
	*   @param nif
	*   @param nomecliente
	*   @param oferta
	*   @param fornecedor
	*/
	Reserva(Data data, unsigned long nif, string nomeCliente, Oferta* oferta, string fornecedor);
	/**
	*	@brief Devolve a data da reserva
	*   @return data
	*/
	Data getData() const;
	/**
	*	@brief Devolve o nif 
	*   @return nif
	*/
	unsigned long getNif() const;
	/**
	*	@brief Devolve o nome do cliente
	*   @return nomecliente
	*/
	string getNomeCliente() const;
	/**
	*	@brief Altera o NIF 
	*   @param nif
	*/
	void setNif(unsigned long Nif);
	/**
	*	@brief Altera o nome do cliente
	*   @param nome
	*/
	void setNomeCliente(string nome);
	/**
	*	@brief Altera a data da reserva
	*   @param data
	*/
	void setData(int dia, int mes);
	/**
	*	@brief Altera a oferta
	*   @param reserva
	*/
	void setOferta(Oferta* oferta);
	/**
	*	@brief Altera o  fornecedor 
	*   @param fornecedor
	*/
	void setFornecedor(string fornecedor);
	/**
	*	@brief Devolve a oferta
	*   @return oferta
	*/
	Oferta* getOferta() const;
	/**
	*	@brief Devolve o fornededor
	*   @return fornecedor
	*/
	string getFornecedor() const;
	/**
	*	@brief Overload do operador <
	*/
	bool operator < (const Reserva &r2) const;
	/**
	*	@brief Overload do operador ==
	*/
	bool operator == (const Reserva &r2) const;

};
