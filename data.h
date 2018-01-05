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
		/**
	*	@brief Construtor de uma data
	*   @param dia
	*   @param mes
	*/
	Data(unsigned int dia, unsigned int mes);
		/**
	*	@brief Construtor de uma data
	*   @param dia
	*   @param mes
	*   @param horaInicio
	*   @param horaFim
	*   @param minutosInicio
	*   @param minutosFim
	*/
	Data(unsigned int dia, unsigned int mes, unsigned int horaInicio, unsigned int horaFim,unsigned int minutosInicio, unsigned int minutosFim);
	/**
	*	@brief Altera o dia
	*   @param dia
	*/
	void setDia(unsigned int dia);
	/**
	*	@brief Altera o mes
	*   @param mes
	*/
	void setMes(unsigned int mes);
	/**
	*	@brief Altera a hora de inicio
	*   @param horaInicio
	*/
	void setHoraInicio(unsigned int horaInicio);
	/**
	*	@brief Altera a hora de termino
	*   @param horaFim
	*/
	void setHoraFim(unsigned int horaFim);
	/**
	*	@brief Altera os minutos de inicio
	*   @param minutosInicio
	*/
	void setMinutosInicio(unsigned int minutosInicio);
	/**
	*	@brief Altera os minutos de termino
	*   @param minutosFim
	*/
	void setMinutosFim(unsigned int minutosFim);
	/**
	*	@brief Devolve o dia
	*   @return dia
	*/
	unsigned int getDia() const;
	/**
	*	@brief Devolve o mes
	*   @return mes
	*/
	unsigned int getMes() const;
		/**
	*	@brief Devolve a hora de inicio
	*   @return horaInicio
	*/
	unsigned int getHoraInicio() const;
	/**
	*	@brief Devolve a hora de termino
	*   @return horaFim
	*/
	unsigned int getHoraFim() const;
		/**
	*	@brief Devolve os minutos de inicio
	*   @return minutosInicio
	*/
	unsigned int getMinutosInicio() const;
	/**
	*	@brief Devolve os minutos de termino
	*   @return minutosFim
	*/
	unsigned int getMinutosFim() const;
	/**
	*	@brief Devolve a data no formato: dia/mes horaInicio:minutosInicio->horaFim:minutosFim
	*   @return data
	*/
	string printData() const;
	/**
	*	@brief Overload do operador ==
	*/
	bool operator ==(const Data &d2)const;
	/**
	*	@brief Overload do operador < 
	*/
	bool operator < (const Data d2)const;

};

#endif /* DATA_H_ */
