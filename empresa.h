#ifndef EMPRESA_H_
#define EMPRESA_H_

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include "cliente.h"
#include "fornecedor.h"
#include "reservas.h"
#include "oferta.h"
#include "BST.h"

using namespace std;
struct clientesInativosHash
{
	int operator() (const clientesInativos& cl) const
	{
		return cl.getNome().at(0) * 23;	// Random Hash function. Better than returning 0, am i right? :D
	}

	bool operator() (const clientesInativos& cl1, const clientesInativos& cl2) const
	{
		return (cl1.getNIF() == cl2.getNIF());
	}
};

typedef unordered_set<clientesInativos, clientesInativosHash, clientesInativosHash> HashTabclientesInativos;
class Empresa {

private:
	vector<Fornecedor> fornecedores;
	vector<Cliente*> clientes;
	Data data_atual;
	HashTabclientesInativos ClientesInativos;
	priority_queue<Oferta> cruzeiros_populares;
	BST<Reserva> reservas; 
	string fichFornecedores;
	string fichOfertas;
	string fichClientes;
	string fichClientesReg;
	string fichReservas;
	string nome;

public:
	/**
	*	@brief Construtor de uma empresa
	*   @param fichFornecedores ficheiro com os clientes
	*   @param fichOferta ficheiro com as ofertas
	*   @param fichClientes ficheiro com os clientes
	*   @param fichClientesReg ficheiro com os clientes registados 
	*   @param data atual 
	*/
    Empresa(string fichFornecedores, string fichOfertas, string fichClientes, string fichClientesReg, string fichReservas, Data data_Atual); // alterei
	/**
	*	@brief Construtor de uma empresa
	*   @param nome
	*   @param fornecedores
	*   @param clientes
	*/
	Empresa(string nome, vector<Fornecedor> fornecedores, vector<Cliente*> clientes);
	/**
	*	@brief Adiciona um fornecedor
	*   @param fornecedor 
	*/
	void addFornecedor(Fornecedor fornecedorNew);
	/**
	*	@brief Adiciona um cliente
	*   @param cliente
	*/
	void addCliente(Cliente * clienteNew);
	/**
	*	@brief Adiciona uma oferta a um fornecedor
	*   @param NIF
	*/
	void addOfertas(unsigned int NIF);
	
	void removeFornecedor(unsigned long fornecedorRemoveNIF);
	void removeCliente(unsigned long clienteRemoveNIF);
	void removerOferta(Oferta o1);
	bool compareData(Data data_cliente); // alterei
	Cliente * getCliente() const;
	/**
	*	@brief Devolve um vetor com fornecedores
	*/
	vector<Fornecedor> getFornecedores() const;
	/**
	*	@brief Devolve o nome da empresa
	*/
	string getNome () const;
	
	void setData_atual(int dia, int mes);// acrescentei
	/**
	*	@brief Carrega os fornecedores a partir de um ficheiro
	*   @param fichFornecedor ficheiro a utilizar 
	*/
	void carregaFornecedores(string fichFornecedor); //extrai o conteudo do ficheiro de fornecedores
	/**
	*	@brief Carrega as ofertas a partir de um ficheiro
	*   @param ficheiro_oferta ficheiro a utilizar
	*/
	void carregaOferta( string ficheiro_oferta);//extrai o conteudo do ficheiro de ofertas
	/**
	*	@brief Carrega os clientes a partir de um ficheiro
	*   @param fichClientes ficheiro a utilizar
	*/
	void carregaClientes(string fichClientes);
	/**
	*	@brief Carrega os clientes registados a partir de um ficheiro
	*   @param fichClientes ficheiro a utilizar
	*/
	void carregaClientesReg(string fichClientesR);
	
	void carregaReservas(string ficheiro_reservas);
	/**
	*	@brief Imprime as ofertas de um fornecedor
	*   @param NIF do fornecedor
	*/
	void visualizaOfertas(unsigned long NIF);
/**
	*	@brief Guarda os fornecedores num ficheiro
	*   @param fichFornecedor ficheiro a utilizar
	*/
	void guardaFornecedores(string fichFornecedores); //guarda o que esta no vetor no ficheiro de texto
	/**
	*	@brief Guarda as ofertas num ficheiro
	*   @param fichOfertas ficheiro a utilizar
	*/
	void guardaOfertas(string fichOfertas); // ""
	/**
	*	@brief Guarda os clientes num ficheiro
	*   @param fichClientesR ficheiro a utilizar
	*   @param fichClientes ficheiro a utilizar
	*/
	void guardaClientes(string fichClientesR, string fichClientes);
	/**
	*	@brief Imprime os lucros dos fornecedores
	*/
	void printLucrosTotais() const;
	/**
	*	@brief Imprime os clientes
	*/
	void printClientes() const;
		/**
	*	@brief Imprime os fornecedores
	*/
	void printFornecedores() const;
	/**
	*	@brief Verifica se o fornecedor existe ou nao
	*	@param NIF do fornecedor
	*	@return true se existir, false caso contrario 
	*/
	bool checkFornecedorNIFBool(unsigned long NIF);
	/**
	*	@brief Remove reserva de um determinado cliente
	*	@param clienteNif NIF do cliente
	*	@param reserva numero da reserva a cancelar 
	*/
	void removeReserva(unsigned long clienteNIF, unsigned int reserva);
	/**
	*	@brief Imprime ofertas com um determinado destino 
	*	@param destino 
	*/
	bool printOfertasByDestino(string destino) const;
	/**
	*	@brief Imprime ofertas com uma determinada data 
	*	@param data
	*/
	bool printOfertasByData(Data data) const;
	/**
	*	@brief Imprime todas as ofertas disponiveis
	*/
	void printOfertas() const;
	/**
	*	@brief Verifica se o cliente existe ou nao e atribui o apontador correspondente a c1
	*	@param NIF do cliente
	*	@return true se existir, false caso contrario
	*/
	bool checkClienteNIF(unsigned long NIF, Cliente **c1);
	/**
	*	@brief Verifica se o cliente existe ou nao e atribui o apontador correspondente a f1
	*	@param NIF do fornecedor
	*	@return true se existir, false caso contrario
	*/
	bool checkFornecedorNIF(unsigned long NIF, Fornecedor **f1); //verifica se existe o fornecedor com o NIF especificado e atribui o apontador correspondente a f1
	/**
	*	@brief Verifica se o cliente existe ou nao, atira uma excecao caso exista
	*	@param NIF do fornecedor
	*/
	void checkFornecedorNIF(unsigned long NIF); // so verifica se o fornecedor em questao existe, atira uma excecao se for esse o caso 
	
	void showPontosCliente(Cliente *c1);
	/**
	*	@brief Atribui uma oferta a um cliente
	*	@param fornecedorNif 
	*	@param clienteNif 
	*	@param numeroOferta 
	*/
	void atribuiReserva(unsigned long fornecedorNif, unsigned long clienteNIF, int numeroOferta, Data dataReserva);
	/**
	*	@brief Remove um fornecedor
	*	@param NIF do fornecedor
 	*/
	void removerFornecedor(unsigned long NIF);
	/**
	*	@brief Imprime as reservas de um cliente
	*	@param NIF do cliente
	*/
	void printReservasByCliente(unsigned long NIF) const;

	//BST e reservas

//	void inicializaBST(); //depois de as reservas serem carregadas, esta funcao e chamada
	void printFaturas(); //percorre a bst e imprime as "faturas" uma a uma 
	bool is_reservas_empty();
	void guardaReservas(string fichReservas);
	int procurar_reservas_nif_cliente(unsigned long nif);
	int procurar_reservas_nif_fornecedor(unsigned long nif);

	//priority queue

	int Descontos();
	void inicializa_queue();
	// hash
	void changeClienteMorada(int nif_cli, string newMorada);
	void PrintClientesInativos();
	void colocaClientesInativos();
};

/////////////////////////
/////// EXCECOES ////////
/////////////////////////

class ClienteExistente {
public:
	unsigned int NIF;
	ClienteExistente(unsigned int NIF) {this->NIF=NIF;}
	unsigned int getNIF() const {return NIF;}
};

class FornecedorExistente {
public:
	unsigned int NIF;
	FornecedorExistente(unsigned int NIF) {this->NIF=NIF;}
	unsigned int getNIF() const {return NIF;}
};

class ClienteInexistente {
public:
	unsigned int NIF;
	ClienteInexistente(unsigned int NIF) {this->NIF=NIF;}
	unsigned int getNIF() const {return NIF;}
};

class FornecedorInexistente {
public:
	unsigned int NIF;
	FornecedorInexistente(unsigned int NIF) {this->NIF=NIF;}
	unsigned int getNIF() const {return NIF;}
};

class CruzeiroCheio {
	public:
		CruzeiroCheio() {};
		
};

class ReservaJaFeita {
public:
		ReservaJaFeita() {};
		
};

class NotANumber {
public:
	NotANumber() {}
};

class IndexOutOfBounds {
public:
	IndexOutOfBounds() {}
};

#endif /* EMPRESA_H_ */
