#ifndef DATA_H_
#define DATA_H_

#include <vector>
#include <string>

using namespace std;

class Data {

private:
	unsigned int dia;
	unsigned int mes;
	unsigned int horaInicio;
	unsigned int horaFim;

public:
	Data();
	Data(unsigned int dia, unsigned int mes, unsigned int horaInicio, unsigned int horaFim);
	void setDia(unsigned int dia);
	void setMes(unsigned int mes);
	void setHoraInicio(unsigned int horaInicio);
	void setHoraFim(unsigned int horaFim);
	unsigned int getDia() const;
	unsigned int getMes() const;
	unsigned int getHoraInicio() const;
	unsigned int getHoraFim() const;

};

#endif /* DATA_H_ */
