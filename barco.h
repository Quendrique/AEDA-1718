#ifndef BARCO_H_
#define BARCO_H_

#include <string>

using namespace std;

class Barco {

private:
	string tipo;
	unsigned int lotacaoMax;

public:
	Barco();
	Barco(string tipo, unsigned int lotacaoMax);
	void setTipo(string tipo);
	void setLotacaoMax(unsigned int lotacaoMax);

};



#endif /* BARCO_H_ */
