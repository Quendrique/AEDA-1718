#include "fornecedor.h"

Fornecedor::Fornecedor() {};

Fornecedor::Fornecedor(string nome, unsigned long NIF, string morada) {
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

void Fornecedor::setNIF(unsigned long NIF) {
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

unsigned long Fornecedor::getNIF() const {
	return NIF;
}

string Fornecedor::getMorada() const {
	return morada;
}

vector<Oferta> Fornecedor::getOfertas() const {
	return ofertas;
}

Oferta * Fornecedor::getOfertaPointer(unsigned int i) {
	return &(ofertas.at(i));
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

int Fornecedor::addOferta(unsigned int nif, Data data, string destino, string barco, unsigned int distancia, unsigned int lotacaoMax, unsigned int lotacaoAtual) {
	Oferta * o1 = new Oferta(nif, barco, lotacaoMax, lotacaoAtual, destino, distancia, data);

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

int Fornecedor::removeOferta(unsigned int nif, Data data, string destino, unsigned int distancia, string barco, unsigned int lotacaoMax, unsigned int lotacaoAtual) {
	Oferta o1(nif, barco, lotacaoMax, lotacaoAtual, destino, distancia, data);

	for (unsigned int i = 0; i < ofertas.size(); i++) {
		if (ofertas[i] == o1) {
			ofertas.erase(ofertas.begin() + i);
			return 0;
		}
	}
	return 1;
}


void Fornecedor::printOfertas() const {

	cout << "**** " << nome << "(NIF " << NIF << ")" << " ****" << endl;

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

	cout << "Fornecedor: " << nome << "(NIF " << NIF << ")" << endl << endl;

	for (unsigned int i = 0; i < ofertas.size(); i++) {

		if (ofertas.at(i).getDestino() == destino) {

			test = true;

			cout << "Oferta " << i+1 << endl
				<< "Barco: " << ofertas.at(i).getBarco() << endl
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

unsigned int Fornecedor::calculaLucro()
{
	unsigned int precoOferta, precoLotOferta, lot;

	for (unsigned int i = 0; i < ofertas.size(); i++) {

		lot = ofertas.at(i).getLotacaoMax();

		switch (lot) {
		case 20:
			precoLotOferta = precoLot.at(0);
			break;
		case 35:
			precoLotOferta = precoLot.at(1);
			break;
		case 50:
			precoLotOferta = precoLot.at(2);
			break;
		}

		precoOferta = ofertas.at(i).getDistancia() * precoKm + precoLotOferta;
		this->lucro += (precoOferta * ofertas.at(i).getLotacaoAtual());
	}

	return lucro;
}

unsigned int Fornecedor::calculaTaxas() const
{

	unsigned int taxa = 0, lot;
	string barco;
	
	for (unsigned int i = 0; i < ofertas.size(); i++) {

		if (ofertas.at(i).getLotacaoAtual() >= (ofertas.at(i).getLotacaoMax()/2)) {

			lot = ofertas.at(i).getLotacaoMax();
			barco = ofertas.at(i).getBarco();

			switch (lot) {
			case 20:
				if (barco == "rabelo")
					taxa += 25;
				else if (barco == "iate")
					taxa += 50;
				else if (barco == "veleiro")
					taxa += 75;
				break;
			case 35:
				if (barco == "rabelo")
					taxa += 30;
				else if (barco == "iate")
					taxa += 55;
				else if (barco == "veleiro")
					taxa += 80;
				break;
			case 50:
				if (barco == "rabelo")
					taxa += 35;
				else if (barco == "iate")
					taxa += 60;
				else if (barco == "veleiro")
					taxa += 85;
				break;

			}
		}
	}

	return taxa;
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

