#pragma once

#include <string>
#include "oferta.h"
#include "data.h"

using namespace std;

class Reserva {
private:
	Data data;
	unsigned long nif;
	string nomeCliente;
	Oferta* oferta;
	string fornecedor;
public:
	Reserva();
	Reserva(Data data, unsigned long nif, string nomeCliente, Oferta* oferta, string fornecedor);
	Data getData() const;
	unsigned long getNif() const;
	string getNomeCliente() const;
	void setNif(unsigned long Nif);
	void setNomeCliente(string nome);
	void setData(int dia, int mes);
	void setOferta(Oferta* oferta);
	void setFornecedor(string fornecedor);
	Oferta* getOferta() const;
	string getFornecedor() const;
	bool operator < (const Reserva &r2) const;
	bool operator == (const Reserva &r2) const;

};
