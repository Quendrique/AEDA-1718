#include "reservas.h"

Reserva::Reserva(Data data, unsigned long nif, string nomeCliente, Oferta* oferta) {
	this->data = data;
	this->nif = nif;
	this->nomeCliente = nomeCliente;
	this->oferta = oferta;
}

Data Reserva::getData() const {
	return data;
}

unsigned long Reserva::getNif() const {
	return nif;
}

string Reserva::getNomeCliente() const {
	return nomeCliente;
}

Oferta* Reserva::getOferta() const {
	return oferta;

}

bool Reserva::operator<(const Reserva r2) const {
	if (nomeCliente == r2.getNomeCliente())
		return data < r2.getData();
	else
		return nomeCliente < r2.getNomeCliente();
}

bool Reserva::operator==(const Reserva r2) const {
	return (nif == r2.getNif() && data == r2.getData());
}