#include "empresa.h"

Empresa::Empresa(){}

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

void Empresa::guardaFornecedores()
{
	ofstream os;
}
