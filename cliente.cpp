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

void Cliente::addReserva(Oferta * reserva)
{
	reservas.push_back(reserva);
}

vector<Oferta*> Cliente::getReservas() const
{
	return reservas;
}

void ClienteReg::setPontos(double pontos)
{
	this->pontos = pontos;
}

double ClienteReg::getPontos()
{
	return pontos;
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
		<< "Morada: " << morada << endl << endl;
}

void Cliente::printPontos() const {
	cout << " Este cliente não está registado, só os clientes registados podem usufruir dos pontos!" << endl;
}

double Cliente::getPontos() const
{
	return 0;
}

void Cliente::removeReservaByFornecedor(long double fornecedorNIF)
{
	for (unsigned int i = 0; i < reservas.size(); i++) {

		if (reservas.at(i)->getNif() == fornecedorNIF) {
			reservas.erase(reservas.begin() + i);
		}
	}
}

/**
Clientes Registados
*/

ClienteReg::ClienteReg(string nome, unsigned int NIF, string morada, double pontos) : Cliente(nome, NIF, morada)
{
	this->pontos = pontos;
}

void ClienteReg::printInfo() const {
	Cliente::printInfo();
	cout << "Pontos: " << pontos << endl;
}

void ClienteReg::printPontos() const {
	cout << "Tem " << pontos << " acumulados" << endl;
}
