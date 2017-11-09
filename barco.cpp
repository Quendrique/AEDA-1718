#include "barco.h"

Barco::Barco()
{
}

Barco::Barco(string tipo, unsigned int lotacaoMax)
{
	this->tipo = tipo;
	this->lotacaoMax = lotacaoMax;
}

void Barco::setTipo(string tipo)
{
	this->tipo = tipo;
}

void Barco::setLotacaoMax(unsigned int lotacaoMax)
{
	this->lotacaoMax = lotacaoMax;
}
