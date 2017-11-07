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
	string nome;

public:
	Empresa();
	Empresa(string nome, vector<Fornecedor> fornecedores, vector<Cliente*> clientes);
	void addFornecedor(Fornecedor fornecedorNew);
	void addCliente(Cliente * clienteNew);
	void removeFornecedor(Fornecedor fornecedorRemove);
	void removeCliente(Cliente * clienteRemove);
	Cliente * getCliente() const;
	vector<Fornecedor> getFornecedor() const;
	string getNome () const;
	void carregaFornecedores()const; //extrai o conte�do do ficheiro de fornecedores
	void carregaOfertas()const; //extrai o conte�do do ficheiro de ofertas
	void guardaFornecedores(); //guarda o que est� no vetor no ficheiro de texto
	void guardaOfertas(); // ""
	void printLucrosTotais() const;
	void printClientes() const;
	void printFornecedores() const;
};



#endif /* EMPRESA_H_ */
