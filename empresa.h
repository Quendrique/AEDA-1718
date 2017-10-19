#ifndef EMPRESA_H_
#define EMPRESA_H_

#include <vector>
#include <string>
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
	Fornecedor getFornecedor() const;
	string getNome () const;
};



#endif /* EMPRESA_H_ */
