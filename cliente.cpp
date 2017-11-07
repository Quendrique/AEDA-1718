#include "cliente.h"

Cliente::Cliente()
{
}

void Cliente::printInfo() const {
	cout << "Nome: " << nome << endl
			<< "NIF: " << NIF << endl
			<< "Morada: " << morada << endl;
}

void ClienteReg::printInfo() const {
	cout << "Nome: " << nome << endl
			<< "NIF: " << NIF << endl
			<< "Morada: " << morada << endl
			<< "Pontos: " << pontos << endl;
}
