#include "data.h"

Data::Data() {}

Data::Data(unsigned int dia, unsigned int mes, unsigned int horaInicio, unsigned int horaFim) {
	this->dia = dia;
	this->mes = mes;
	this->horaInicio = horaInicio;
	this->horaFim = horaFim;
}

unsigned int Data::getDia() const {return dia;}

unsigned int Data::getMes() const {return mes;}

unsigned int Data::getHoraInicio() const {return horaInicio;}

unsigned int Data::getHoraFim() const {return horaFim;}

string Data::printData() const {

	std::ostringstream os;
	os << dia << "/" << mes << " " << horaInicio << "->" << horaFim;
	return os.str();

}

