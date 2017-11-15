#include "data.h"

Data::Data() {}

Data::Data(unsigned int dia, unsigned int mes, unsigned int horaInicio, unsigned int horaFim, unsigned int minutosInicio, unsigned int minutosFim) {
	this->dia = dia;
	this->mes = mes;
	this->horaInicio = horaInicio;
	this->horaFim = horaFim;
	this->minutosInicio = minutosInicio;
	this->minutosFim = minutosFim;
}

unsigned int Data::getMinutosInicio() const{return minutosInicio;}

unsigned int Data::getMinutosFim() const{ return minutosFim; }

unsigned int Data::getDia() const { return dia; }

unsigned int Data::getMes() const { return mes; }

unsigned int Data::getHoraInicio() const { return horaInicio; }

unsigned int Data::getHoraFim() const { return horaFim; }

string Data::printData() const {

	std::ostringstream os;
	os << dia << "/" << mes << " " << horaInicio<<":"<< minutosInicio << "->" << horaFim<<":"<< minutosFim;
	return os.str();

}
void Data::setDia(unsigned int dia)
{
	this->dia=dia;
}
void Data::setMes(unsigned int mes)
{
	this->mes=mes;
}
void Data::setHoraInicio(unsigned int horaInicio)
{
	this->horaInicio=horaInicio;
}
void Data::setHoraFim(unsigned int horaFim)
{
	this->horaFim=horaFim;
}

void Data::setMinutosInicio(unsigned int horaInicio)
{
	this->minutosInicio=minutosInicio;

}
void Data::setMinutosFim(unsigned int horaFim)
{
	this->minutosFim=minutosFim;

}

bool Data::operator==(const Data &d2) const {
	if (mes == d2.getMes() && dia == d2.getDia() && horaInicio == d2.getHoraInicio() && horaFim == d2.getHoraFim()
		&& minutosInicio == d2.getMinutosInicio() && minutosFim == d2.getMinutosFim())
		return true;
	else
		return false;
}