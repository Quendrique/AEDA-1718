#include "oferta.h"

Oferta::Oferta()
{

}

Oferta::Oferta(unsigned int nif, string barco, unsigned int lotacaoMax, unsigned int lotacaoAtual, string destino, unsigned int distancia, Data data)
{
	this->distancia = distancia;
	this->nif = nif;
	this->destino = destino;
	this->barco = barco;
	this->lotacaoMax = lotacaoMax;
	this->lotacaoAtual = lotacaoAtual;
	this->data = data;
	this->preco = 0;
	this->ultima_data = Data(1,1);
}

Data Oferta::getUltimaData() const
{
	return ultima_data;
}

/*/////////////////////////
/////////SET //////////////
*/////////////////////////
void Oferta::setData(Data data)
{
	this->data = data;
}

void Oferta::setBarco(string barco)
{
	this->barco = barco;
}

void Oferta::setNif(unsigned int nif)
{
	this->nif = nif;
}

bool Oferta::operator<(const Oferta o2) const
{
	return this->ultima_data < o2.getUltimaData();
}

void Oferta::setLotacaoMax(unsigned int lotacaoMax)
{
	this->lotacaoMax = lotacaoMax;
}
void Oferta::setPreco(int preco)
{
	this->preco = preco;
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

void Oferta::setUltimaData(Data data) {
	this->ultima_data = data;
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
int Oferta::getPreco()const
{
	return preco;
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

void Oferta::removeFromLotacao()
{
	this->lotacaoAtual -= 1;
}

bool Oferta::operator<(const Oferta & f2) 
{
	return this->getUltimaData() < f2.getUltimaData();
}

bool Oferta::ordenaDist(const Oferta &f1, const Oferta &f2)
{
	return f1.getDistancia() < f2.getDistancia();
}


