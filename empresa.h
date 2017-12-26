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
	string fichFornecedores;
	string fichOfertas;
	string fichClientes;
	string fichClientesReg;
	string nome;

public:
	//prioritty_queue

	int Descontos();
	//....
    Empresa(string fichFornecedores, string fichOfertas, string fichClientes, string fichClientesReg, Data data_Atual); // alterei
	Empresa(string nome, vector<Fornecedor> fornecedores, vector<Cliente*> clientes);
	void changeClienteMorada(Cliente* cliente, string newMorada); // added
	void addFornecedor(Fornecedor fornecedorNew);
	void addCliente(Cliente * clienteNew);
	void addOfertas(unsigned int NIF);
	void removeFornecedor(unsigned long fornecedorRemoveNIF);
	void removeCliente(unsigned long clienteRemoveNIF);
	void removerOferta(Oferta o1);
	bool compareData(Data data_cliente); // alterei
	Cliente * getCliente() const;
	vector<Fornecedor> getFornecedores() const;
	string getNome () const;
	void setData_atual(int dia, int mes);// acrescentei
	void carregaFornecedores(string fichFornecedor); //extrai o conteudo do ficheiro de fornecedores
	void carregaOferta( string ficheiro_oferta);//extrai o conteudo do ficheiro de ofertas
	void carregaClientes(string fichClientes);
	void carregaClientesReg(string fichClientesR);
	void visualizaOfertas(unsigned long NIF);

	void guardaFornecedores(string fichFornecedores); //guarda o que esta no vetor no ficheiro de texto
	void guardaOfertas(string fichOfertas); // ""
	void guardaClientes(string fichClientesR, string fichClientes);
	void printLucrosTotais() const;
	void printClientes() const;
	void printFornecedores() const;
	bool checkFornecedorNIFBool(unsigned long NIF);
	void removeReserva(unsigned long clienteNIF, unsigned int reserva);
	bool printOfertasByDestino(string destino) const;
	bool printOfertasByData(Data data) const;
	void printOfertas() const;
	bool checkClienteNIF(unsigned long NIF, Cliente **c1);
	bool checkFornecedorNIF(unsigned long NIF, Fornecedor **f1); //verifica se existe o fornecedor com o NIF especificado e atribui o apontador correspondente a f1
	void checkFornecedorNIF(unsigned long NIF); // so verifica se o fornecedor em questao existe, atira uma excecao se for esse o caso 
	void showPontosCliente(Cliente *c1);
	void atribuiReserva(unsigned long fornecedorNif, unsigned long clienteNIF, int numeroOferta);
	void removerFornecedor(unsigned long NIF);
	void printReservasByCliente(unsigned long NIF) const;
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
