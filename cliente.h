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
	
        /**
	*	@brief Construtor vazio de um cliente
	*/
	Cliente();
	/**
	*	@brief Construtor de um cliente
	*       @param Nome do cliente
	*	@param NIF do cliente
	*	@param morada do cliente
	*/
	Cliente(string nome, unsigned int NIF, string morada);
	/**
	*	@brief Altera o nome de um cliente
	*   @param Nome do cliente
	*/
	void setNome(string nome);
	/**
	*	@brief Altera o NIF de um cliente
	*   @param NIF do cliente
	*/
	void setNIF(unsigned int NIF);
	/**
	*	@brief Altera a morada de um cliente
	*   @param Morada do cliente
	*/
	void setMorada(string morada);
	/**
	*	@brief Altera a data da ultima reserva
	*       @param Data
	*/
	void setUltimaReserva(Data data);
	
	/**
	*	@brief Altera o parametro inativo
	*       @param inativo
	*/
	void setInativo(unsigned int inativo);
	/**
	*	@brief Retorna o parametro inativo
	*       @return inativo
	*/
	unsigned int getInativo() const;
	/**
	*	@brief Adiciona uma oferta a um cliente
	*   @param Reserva que vai ser adicionada
	*/
	void addReserva(Reserva reserva);
	/**
	*	@brief Retorna as ofertas correspondentes as reservas feitas pelos fornecedores
	*   @return Vetor com apontadores para as ofertas 
	*/
	vector<Reserva> getReservas()const;
	/**
	*	@brief Retorna o nome do cliente
	*   @return Nome do cliente
	*/
	string getNome() const;
	/**
	*	@brief Retorna o NIF do cliente
	*   @return NIF do cliente
	*/
	unsigned int getNIF() const;
	/**
	*	@brief Retorna a morada do cliente
	*   @return Morada do cliente
	*/
	string getMorada() const;
	/**
	*	@brief Atualiza contador de Reservas
	*/
	void updateContadorReservas();
	/**
	*	@brief Retorna contador reservas
	*/
	size_t getContadorReservas();
	/**
	*	@brief Retorna o data da ultima reserva
	*      @return ultima reserva
	*/
	Data getUltimaReserva() const;
	/**
	*	@brief Imprime informação relativa ao cliente
	*
	*/
	virtual void printInfo() const;
	/**
	*	@brief Overload do operador ==
	*/
	bool operator ==(const Cliente &c2);
	/**
	* @brief Imprime os pontos no ecra (se nao for registado, imprime essa informacao no ecra
	*/
	virtual void printPontos() const;
	/**
	*	@brief Determina se o cliente e ou nao registado
	*   @return true se for registado, false caso contrario
	*/
	virtual bool isRegistado() { return false; }
	/**
	*	@brief Devolve os pontos de um cliente registado; caso nao o seja, devolve 0
	*   @return Pontos
	*/
	virtual double getPontos() const;
	/**
	*	@brief Remove uma reserva, caso o fornecedor a qual ela pertence seja removido
	*       @param fornecedorNif NIF do fornecedor removido
	*       @return reserva
	*/
	Reserva removeReservaByFornecedor(long double fornecedorNIF);
	/**
	*	@brief Remove uma reserva
	*       @param reserva
	*       @return reserva
	*/
	Reserva removeReservaByIndex(unsigned int reserva);
	/**
	*	@brief Remove uma reserva
	*   @param oferta
	*/
	void removeReservaByOferta(Oferta o1);
	/**
	*	@brief Imprime as reservas do cliente no ecra 
	*/
	void printReservas() const;

};


class ClienteReg: public Cliente {

private:
	unsigned int pontos;

public:
	/**
	*	@brief Construtor de um cliente Registados
	*       @param Nome do cliente
	*	@param NIF do cliente
	*	@param morada do cliente
	*	@param pontos
	*/
	ClienteReg(string nome, unsigned int NIF, string morada,double pontos);
        /**
	*	@brief Altera os pontos de um cliente registado
	*   @param pontos 
	*/
	void setPontos(double pontos);
	/**
	*	@brief Devolve os pontos de um cliente registado
	*   @return Pontos
	*/
	double getPontos();
	/**
	*	@brief Imprime informação relativa ao cliente registado
	*
	*/
	void printInfo() const;
	/**
	*	@brief Imprime os pontos de um cliente registado
	*/
	void printPontos() const;
	/**
	*	@brief Determina se o cliente e ou nao registado
	*   @return true se for registado, false caso contrario
	*/
	bool isRegistado() { return true; }
};
class clientesInativos
{
	Cliente* clienterprt;
public:
	/**
	*	@brief Construtor de um cliente Inativo
	*       @param Apontador de clientes
	*/
	clientesInativos(Cliente* clienterprt);
	/**
	*	@brief Retorna o nome do cliente
	*   @return Nome do cliente
	*/
	string getNome() const;
	/**
	*	@brief Retorna a morada do cliente
	*   @return Morada do cliente
	*/
	string getMorada() const;
	/**
	*	@brief Retorna o NIF do cliente
	*   @return NIF do cliente
	*/
	unsigned int getNIF() const;
	/**
	*	@brief Altera a morada 
	*   @param Nova morada
	*/
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
