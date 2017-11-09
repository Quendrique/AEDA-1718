#include "empresa.h"

Empresa::Empresa()
{
}

Empresa::Empresa(string nome, vector<Fornecedor> fornecedores, vector<Cliente*> clientes)
{
	this->nome = nome;
	this->fornecedores = fornecedores;
	this->clientes = clientes;
}

vector<Fornecedor> Empresa::getFornecedor() const
{
	return fornecedores;
}

string Empresa::getNome() const
{
	return nome;
}

/**
métodos de imprir informações
*/
void Empresa::printLucrosTotais() const {

	for (unsigned int i=0 ; i < fornecedores.size(); i++) {
		fornecedores.at(i).printLucro();
	}

}

void Empresa::printClientes() const {
	for (unsigned int i=0; i < clientes.size() ; i++) {
		clientes.at(i)->printInfo();
	}

}

void Empresa::printFornecedores() const {
	for (unsigned int i=0; i < fornecedores.size(); i++) {
		fornecedores.at(i).printInfo();
	}
}



/**
Métodos de adicionar clientes e fornecedores
*/
void Empresa::addCliente(Cliente * clienteNew) {

	for (unsigned int i=0; i < clientes.size() ; i++) {
		if (*(clientes.at(i)) == *clienteNew)
			; //throw ClienteExistente
	}

	clientes.push_back(clienteNew);

}

void Empresa::addFornecedor(Fornecedor fornecedorNew)
{
	for (unsigned int i = 0; i < fornecedores.size(); i++)
		if (fornecedores.at(i).getNIF() == fornecedorNew.getNIF())
			//throw FornecedorExistente
			fornecedores.push_back(fornecedorNew);
}



/**
Métodos de remover clientes e fornecedores
*/

void Empresa::removeCliente()
{

}

void Empresa::removeFornecedor(double fornecedorRemoveNif)
{
	for (unsigned int i = 0; i < fornecedores.size(); i++)
		if (fornecedores.at(i).getNIF() == fornecedorRemoveNif)
		{

		}
}