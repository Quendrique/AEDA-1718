#include "cliente.h"

/**
	Clientes
*/

Cliente::Cliente()
{
}

Cliente::Cliente(string nome, unsigned int NIF, string morada)
{
	this->nome = nome;
	this->NIF = NIF;
	this->morada = morada;
}

void Cliente::setNome(string nome)
{
	this->nome = nome;
}

void Cliente::setNIF(unsigned int NIF)
{
	this->NIF = NIF;
}

void Cliente::setMorada(string morada)
{
	this->morada = morada;
}

string Cliente::getNome() const
{
	return nome ;
}

unsigned int Cliente::getNIF() const
{
	return NIF;
}

string Cliente::getMorada() const
{
	return morada;
}

void Cliente::printInfo() const {
	cout << "Nome: " << nome << endl
			<< "NIF: " << NIF << endl
			<< "Morada: " << morada << endl;
}

/**
Clientes Registados
*/

ClienteReg::ClienteReg(string nome, unsigned int NIF, string morada)
{
	Cliente(nome, NIF, morada);
	this->pontos = 0;
}

void ClienteReg::printInfo() const {
	Cliente::printInfo();
	cout<< "Pontos: " << pontos << endl;
}

void ClienteReg::printPontos() const {
	cout << "Tem " << pontos << " acumulados" << endl;
}
