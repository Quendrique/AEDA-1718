#ifndef EMPRESA_H_
#define EMPRESA_H_

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "cliente.h"
#include "fornecedor.h"

using namespace std;

class Empresa {

private:
	vector<Fornecedor> fornecedores;
	vector<Cliente*> clientes;
	string fichFornecedores;
	string fichOfertas;
	string fichClientes;
	string fichClientesReg;
	string nome;

public:
	Empresa(string fichFornecedores, string fichOfertas, string fichClientes, string fichClientesReg);
	Empresa(string nome, vector<Fornecedor> fornecedores, vector<Cliente*> clientes);
	void addFornecedor(Fornecedor fornecedorNew);
	void addCliente(Cliente * clienteNew);
	void removeFornecedor(unsigned int fornecedorRemoveNIF);
	void removeCliente(unsigned int clienteRemoveNIF);
	Cliente * getCliente() const;
	vector<Fornecedor> getFornecedor() const;
	string getNome () const;
	void carregaFornecedores(string fichFornecedor); //extrai o conteudo do ficheiro de fornecedores
	void carregaOferta( string ficheiro_oferta);//extrai o conteudo do ficheiro de ofertas
	void carregaClientes(string fichClientes);
	void carregaClientesReg(string fichClientesR);
	void visualizaOfertas(long double NIF);

	void guardaFornecedores(string fichFornecedores); //guarda o que esta no vetor no ficheiro de texto
	void guardaOfertas(string fichOfertas); // ""
	void guardaClientes(string fichClientesR, string fichClientes);
	void printLucrosTotais() const;
	void printClientes() const;
	void printFornecedores() const;
	bool printOfertasByDestino(string destino) const;
	bool printOfertasByData() const;
	bool checkClienteNIF(unsigned int NIF, Cliente *c1);
	bool checkFornecedorNIF(unsigned int NIF, Fornecedor *f1);
	void showPontosCliente(Cliente *c1);
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

class NotANumber {
public:
	NotANumber() {}
};

#endif /* EMPRESA_H_ */
