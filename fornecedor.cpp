#include "fornecedor.h"

Fornecedor::Fornecedor() {};

Fornecedor::Fornecedor(string nome, long double NIF, string morada) {
	this->nome = nome;
	this->NIF = NIF;
	this->morada = morada;
	lucro = 0;
}

/////////
/* SET */
/////////

void Fornecedor::setNome(string nome) {
	this->nome = nome;
}

void Fornecedor::setNIF(unsigned int NIF) {
	this->NIF = NIF;
}

void Fornecedor::setMorada(string morada) {
	this->morada = morada;
}

void Fornecedor::setPrecoKm(unsigned int precoKm)
{
	this->precoKm = precoKm;
}

void Fornecedor::setPrecoLot(vector<unsigned int> precoLot)
{
	this->precoLot = precoLot;
}

/////////
/* Get */
/////////

string Fornecedor::getNome() const {
	return nome;
}

unsigned int Fornecedor::getNIF() const {
	return NIF;
}

string Fornecedor::getMorada() const {
	return morada;
}

vector<Oferta> Fornecedor::getOfertas() const {
	return ofertas;
}

vector<unsigned int> Fornecedor::getPrecoLot() const
{
	return precoLot;
}

unsigned int Fornecedor::getPrecoKm() const
{
	return precoKm;
}


/////////////
/* metodos */
////////////

int Fornecedor::addOferta(unsigned int nif,Data data, string destino, string barco, unsigned int distancia, unsigned int lotacaoMax,unsigned int lotacaoAtual) {
	Oferta * o1 = new Oferta(nif,barco, lotacaoMax,lotacaoAtual, destino ,distancia, data);

	for (unsigned int i = 0; i < ofertas.size(); i++) {
		if (ofertas[i] == *o1)
			return 1;
	}
	ofertas.push_back(*o1);
	return 0;
}

int Fornecedor::addOfertaInit(Oferta oferta) {

	for (unsigned int i = 0; i < ofertas.size(); i++) {
		if (ofertas[i] == oferta)
			return 1;
	}
	ofertas.push_back(oferta);
	return 0;
}

int Fornecedor::removeOferta(unsigned int nif,Data data, string destino, unsigned int distancia, string barco, unsigned int lotacaoMax, unsigned int lotacaoAtual) {
	Oferta o1( nif,barco, lotacaoMax,lotacaoAtual, destino,distancia, data);

	for (unsigned int i = 0; i < ofertas.size(); i++) {
		if (ofertas[i] == o1) {
			ofertas.erase(ofertas.begin() + i);
			return 0;
		}
	}
	return 1;
}


void Fornecedor::printOfertas() const {

	cout << "**** " << nome << " ****" << endl;

	for (unsigned int i = 0; i < ofertas.size(); i++) {

		cout << "Oferta " << i << ":" << endl
			<< "Barco: " << ofertas.at(i).getBarco() << endl
			<< "Lotacao maxima: " << ofertas.at(i).getLotacaoMax() << endl
			<< "Destino: " << ofertas.at(i).getDestino() << endl
			<< "Data: " << ofertas.at(i).getData().printData() << endl
			<< "Lotacao atual: " << ofertas.at(i).getLotacaoAtual() << endl << endl;
	}
}

bool Fornecedor::printOfertasByDestino(string destino) const {

	bool test = false;

	for (unsigned int i = 0; i < ofertas.size(); i++) {

		if (ofertas.at(i).getDestino() == destino) {

			test = true;

			cout << "Barco: " << ofertas.at(i).getBarco() << endl
				<< "Lotacao maxima: " << ofertas.at(i).getLotacaoMax() << endl
				<< "Destino: " << ofertas.at(i).getDestino() << endl
				<< "Data: " << ofertas.at(i).getData().printData() << endl
				<< "Lotacao atual: " << ofertas.at(i).getLotacaoAtual() << endl << endl;
		}
	}

	return test;

}

bool Fornecedor::printOfertasByData(Data data) const {

	bool test = false;

	cout << "Fornecedor: " << nome << " (NIF: " << NIF << ")" << endl << endl;

	for (unsigned int i = 0; i < ofertas.size(); i++) {

		if (ofertas.at(i).getData() == data) {

			test = true;

			cout << "Oferta " << i << ":" << endl
				<< "Barco: " << ofertas.at(i).getBarco() << endl
				<< "Lotacao maxima: " << ofertas.at(i).getLotacaoMax() << endl
				<< "Destino: " << ofertas.at(i).getDestino() << endl
				<< "Data: " << ofertas.at(i).getData().printData() << endl
				<< "Lotacao atual: " << ofertas.at(i).getLotacaoAtual() << endl << endl;

		}

	}

	return test;

}

void Fornecedor::printInfo() const {

	cout << "Fornecedor: " << this->nome << endl
		<< "NIF: " << this->NIF << endl
		<< "Morada: " << this->morada << endl
		<< "Lucro: " << this->lucro << endl
		<< "Preco por kilometro: " << this->precoKm << endl
		<< "Preco por escalao de lotacao maxima:" << endl;

	if (this->precoLot.size() >= 3)
	{
		cout << " - 20 pessoas: " << this->precoLot.at(0) << endl
			<< " - 35 pessoas: " << this->precoLot.at(1) << endl
			<< " - 50 pessoas: " << this->precoLot.at(2) << endl << endl;
	}

}

int Fornecedor::calculaLucro() {

	int sum = 0;
	unsigned int lotacaoType;

	for (unsigned int i = 0; i < ofertas.size(); i++) {

		lotacaoType = ofertas.at(i).getLotacaoMax();

		switch (lotacaoType) {

		case 20:
			sum += precoLot.at(0) * ofertas.at(i).getLotacaoAtual() + precoKm * ofertas.at(i).getDistancia();
			break;
		case 35:
			sum += precoLot.at(1) * ofertas.at(i).getLotacaoAtual() + precoKm * ofertas.at(i).getDistancia();
			break;
		case 50:
			sum += precoLot.at(2) * ofertas.at(i).getLotacaoAtual() + precoKm * ofertas.at(i).getDistancia();
			break;
		}
	}

	lucro = sum;
	return sum;

}

void Fornecedor::printLucro() const {

	cout << "**** " << nome << " ****" << endl << "Lucro: " << lucro << endl;

}

void Fornecedor::updateOferta(const Oferta &o1) {

	for (unsigned int i = 0; i < ofertas.size(); i++) {

		if (ofertas.at(i) == o1) {
			ofertas.at(i).addToLotacao();
			calculaLucro();
		}

	}

}

void Fornecedor::removeOfertaMenu(unsigned int i) {

	if ((i - 1) >= 0 && (i - 1) < ofertas.size()) {
		ofertas.erase(ofertas.begin() + i);
	}
	else
		throw OfertaInexistente(i);

}

/*
* para voltar a utilizar esta funcao temos de modificar os parametros de printOfertas para std::ostream &os
*
ostream & operator <<(ostream &os, const Fornecedor &fornecedor) {
fornecedor.printOfertas(os);
return os;
}
*/

