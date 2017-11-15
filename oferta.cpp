#include "oferta.h"

Oferta::Oferta()
{

}

Oferta::Oferta(string barco, unsigned int lotacaoMax,unsigned int lotacaoAtual, string destino, Data data)
{
	this->barco = barco;
	this->lotacaoMax = lotacaoMax;
	this->lotacaoAtual = lotacaoAtual;
	this->destino = destino;
	this->data=data;
}

/*/////////////////////////
/////////SET //////////////
*/////////////////////////
void Oferta::setData(Data data)
{
this->data=data;
}

void Oferta::setBarco(string barco)
{
	this->barco = barco;
}

void Oferta::setNif(unsigned int id)
{
	this->nif = nif;
}

void Oferta::setLotacaoMax(unsigned int lotacaoMax)
{
	this->lotacaoMax = lotacaoMax;
}

void Oferta::setLotacaoAtual(unsigned int lotacaoAtual)
{
	this->lotacaoAtual = lotacaoAtual;
}

void Oferta::setDestino(string destino)
{
	this->destino = destino;
}

void Oferta::setDistancia(unsigned int distancia)
{
	this->distancia = distancia;
}


/*/////////////////////////
/////////GET //////////////
*/////////////////////////

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

unsigned int Oferta::getLotacaoAtual() const
{
	return lotacaoAtual;
}

unsigned int Oferta::getNif() const
{
	return nif;
}

unsigned int Oferta::getDistancia() const
{
	return distancia;
}

Data Oferta::getData() const { return data; }


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
	this->lotacaoAtual = lotacaoAtual + 1;
}

