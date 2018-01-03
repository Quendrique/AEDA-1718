#include "cliente.h"

/**
	Clientes
*/

Cliente::Cliente()
{
}

Cliente::Cliente(string nome, unsigned int NIF, string morada) //alterei
{
	this->nome = nome;
	this->NIF = NIF;
	this->morada = morada;
	this->inativo = 0;//partimos do principio que esta ativo
	this->ultima_reserva = Data(1, 1);
	this->contadorReservas = 0; 
}


clientesInativos::clientesInativos(Cliente* clienterprt)
{
	this->clienterprt = clienterprt;

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

void Cliente::setUltimaReserva(Data data) {
	this->ultima_reserva = data;
}

void Cliente::addReserva(Reserva reserva)
{
	reservas.push_back(reserva);
}

vector<Reserva> Cliente::getReservas() const
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

Data Cliente::getUltimaReserva() const {
	return ultima_reserva;
}

void Cliente::updateContadorReservas() {
	this->contadorReservas = reservas.size();
}

size_t Cliente::getContadorReservas() {
	return contadorReservas;
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

Reserva Cliente::removeReservaByFornecedor(long double fornecedorNIF)
{

	for (unsigned int i = 0; i < reservas.size(); i++) {

		if (reservas.at(i).getOferta()->getNif() == fornecedorNIF) {
			Reserva to_return = reservas.at(i);
			reservas.erase(reservas.begin() + i);
			return to_return;
		}
	}
}

Reserva Cliente::removeReservaByIndex(unsigned int reserva)
{
	reservas.at(reserva - 1).getOferta()->removeFromLotacao();
	Reserva to_return = reservas.at(reserva-1);
	reservas.erase(reservas.begin() + (reserva - 1));
	return to_return;
}

void Cliente::printReservas() const
{
	if (reservas.size() == 0)
	{
		cout << "Nao existe" << endl;
	}
	for (unsigned int i = 0; i < reservas.size(); i++) {

		cout << "Reserva " << i + 1 << endl;
		cout << "Fornecedor: " << reservas.at(i).getFornecedor() << endl
			<< "Barco: " << reservas.at(i).getOferta()->getBarco() << endl
			<< "Lotacao maxima: " << reservas.at(i).getOferta()->getLotacaoMax() << endl
			<< "Lotacao atual: " << reservas.at(i).getOferta()->getLotacaoAtual() << endl
			<< "Destino: " << reservas.at(i).getOferta()->getDestino() << endl
			<< "Data: " << reservas.at(i).getOferta()->getData().printData() << endl << endl;
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
/**
Clientes Inativos
*/
string clientesInativos::getNome() const
{
	return this->clienterprt->nome;
}
string clientesInativos::getMorada() const
{
	return this->clienterprt->morada;
}
unsigned int clientesInativos::getNIF() const
{
	return this->clienterprt->NIF;
}
void clientesInativos::setMorada(string morada)
{
	this->clienterprt->morada = morada;
}
