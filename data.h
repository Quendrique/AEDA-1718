#ifndef DATA_H_
#define DATA_H_

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Data {

private:
	unsigned int dia;
	unsigned int mes;
	unsigned int horaInicio;
	unsigned int minutosInicio;
	unsigned int horaFim;
	unsigned int minutosFim;

public:
	Data();
	Data(unsigned int dia, unsigned int mes, unsigned int horaInicio, unsigned int horaFim,unsigned int minutosInicio, unsigned int minutosFim);
	void setDia(unsigned int dia);
	void setMes(unsigned int mes);
	void setHoraInicio(unsigned int horaInicio);
	void setHoraFim(unsigned int horaFim);
	void setMinutosInicio(unsigned int horaInicio);
	void setMinutosFim(unsigned int horaFim);
	unsigned int getDia() const;
	unsigned int getMes() const;
	unsigned int getHoraInicio() const;
	unsigned int getHoraFim() const;
	unsigned int getMinutosInicio() const;
	unsigned int getMinutosFim() const;
	string printData() const;

};

#endif /* DATA_H_ */
