#include "oferta.h"

Oferta::Oferta()
{

}
Oferta::Oferta(string barco, unsigned int lotacaoMax, string destino, Data data)
{
	this->barco = barco;
	this->lotacaoMax = lotacaoMax;
	this->destino = destino;
	// falta a data
}
string Oferta::getBarco() const
{
	return barco;
}
unsigned int Oferta::getLotacaoMax() const
{
	return lotacaoMax;
}
string Oferta::getDestino() const
{
	return destino;
}
unsigned int Oferta::getId() const
{
	return id;
}
unsigned int Oferta::getLotacao() const
{
	return lotacao;
}
void Oferta::setBarco(string barco)
{
	this->barco = barco;
}
void Oferta::setLotacaoMax(unsigned int lotacaoMax)
{
	this->lotacaoMax = lotacaoMax;
}
void Oferta::setDestino(string destino)
{
	this->destino = destino;
}
bool Oferta::operator ==(const Oferta &o2)
{
	if (this->barco == o2.barco)
	{
		if (this->destino == o2.destino)
		{
			if (this->lotacaoMax == o2.lotacaoMax)
			{
				if (this->distancia == o2.distancia)
				{
					if (this->data.getMes() == o2.data.getMes())
					{
						if (this->data.getDia() == o2.data.getDia())
						{
							if (this->data.getHoraInicio() == o2.data.getHoraInicio())
							{
								if (this->data.getHoraFim() == o2.data.getHoraFim())
								{
									return true;
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}
void Oferta::addToLotacao()
{
	this->lotacao = lotacao + 1;
}
Data Oferta::getData() const {return data;}

