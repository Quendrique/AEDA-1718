#include "empresa.h"

Empresa::Empresa()
{
}

Empresa::Empresa(string nome, vector<Fornecedor> fornecedores, vector<Cliente*> clientes)
{
	this->nome = nome;
	this->fornecedores = fornecedores;
	this->clientes = clientes;
}

vector<Fornecedor> Empresa::getFornecedor() const
{
	return fornecedores;
}

string Empresa::getNome() const
{
	return nome;
}

//////////////////////////////////////////////
/* Metodos para ler informacao dos ficheiros*/
//////////////////////////////////////////////

void Empresa::carregaFornecedores(string fichFornecedor)
{
	stringstream ssF;
	ifstream forne(fichFornecedor);
	vector <Fornecedor> fornecedor;
	char comma;
	string nome, morada;
	string nifTmp;
	long unsigned int nif = 0;

	if (forne.is_open())
	{
		string line;

		while (getline(forne, line))
		{
			Fornecedor f;
			ssF.clear();
			nome.clear();
			morada.clear();
			nifTmp.clear();
			nif = 0;
			ssF.str(line);

			getline(ssF, nome, ',');

			//////////
			/* NOME */
			//////////

			for (unsigned int j = 0; j < nome.length(); j++) //retira espaço no inicio do nome
			{
				if (isalpha(nome[j]))
					break;
				if (nome[j] == ' ')
				{
					nome.erase(nome.begin() + j);
					j--;
				}
			}

			for (int j = nome.length() - 1; j >= 0; j--) // retira espaço no fim do nome
			{
				if (isalpha(nome[j]))
					break;
				if (nome[j] == ' ')
				{
					nome.erase(nome.begin() + j);
					j--;
				}

			}

			/////////
			/* NIF */
			/////////

			getline(ssF, nifTmp, ',');

			for (unsigned int j = 0; j < nifTmp.length(); j++) //retira espaço no inicio do nif
			{
				if (isalnum(nifTmp[j]))
					break;
				if (nifTmp[j] == ' ')
				{
					nifTmp.erase(nifTmp.begin() + j);
					j--;
				}
			}

			nif = stol(nifTmp);

			////////////
			/* MORADA */
			////////////

			getline(ssF, morada, '\n');

			for (unsigned int j = 0; j < morada.length(); j++) //retira espaço no inicio da morada
			{
				if (isalpha(morada[j]))
					break;
				if (morada[j] == ' ')
				{
					morada.erase(morada.begin() + j);
					j--;
				}
			}


			f.setNome(nome);
			f.setNIF(nif);
			f.setMorada(morada);
			addFornecedor(f);

		}
	}
}




/////////////////////////////////////
/* Metodos de imprimir informações */
/////////////////////////////////////

void Empresa::printLucrosTotais() const {

	for (unsigned int i=0 ; i < fornecedores.size(); i++) {
		fornecedores.at(i).printLucro();
	}

}

void Empresa::printClientes() const {
	for (unsigned int i=0; i < clientes.size() ; i++) {
		clientes.at(i)->printInfo();
	}

}

void Empresa::printFornecedores() const {
	for (unsigned int i=0; i < fornecedores.size(); i++) {
		fornecedores.at(i).printInfo();
	}
}


//////////////////////////////////////////////////
/* Metodos de adicionar clientes e fornecedores */
//////////////////////////////////////////////////

void Empresa::addCliente(Cliente * clienteNew) {

	for (unsigned int i=0; i < clientes.size() ; i++) {
		if ((clientes.at(i)) == clienteNew)
			throw ClienteExistente(clientes.at(i)->getNIF());
	}

	clientes.push_back(clienteNew);

}

void Empresa::addFornecedor(Fornecedor fornecedorNew) {
	for (unsigned int i = 0; i < fornecedores.size(); i++) {
		if (fornecedores.at(i).getNIF() == fornecedorNew.getNIF()) {
			throw FornecedorExistente(fornecedores.at(i).getNIF());
		}
	}

	fornecedores.push_back(fornecedorNew);
}


////////////////////////////////////////////////
/* Metodos de remover clientes e fornecedores */
////////////////////////////////////////////////

void Empresa::removeCliente(unsigned int clienteRemoveNIF) {

}

void Empresa::removeFornecedor(unsigned int  fornecedorRemoveNIF) {
	for (unsigned int i = 0; i < fornecedores.size(); i++)
		if (fornecedores.at(i).getNIF() == fornecedorRemoveNIF)
		{

		}
}

////////////////////////////////////////////////////////////////////
/* Metodos para verificar a existencia de clientes e fornecedores */
////////////////////////////////////////////////////////////////////

bool Empresa::checkClienteNIF(unsigned int NIF, Cliente *c1) {

	for (unsigned int i=1; i < clientes.size(); i++) {
		if (clientes.at(i)->getNIF() == NIF) {
			c1 = clientes.at(i);
			return true;
		}
	}

	throw ClienteInexistente(NIF);

}

bool Empresa::checkFornecedorNIF(unsigned int NIF, Fornecedor *f1) {

	for (unsigned int i=1; i < fornecedores.size(); i++) {
		if (fornecedores.at(i).getNIF() == NIF) {
			f1 = &(fornecedores.at(i));
			return true;
		}
	}

		throw FornecedorInexistente(NIF);

}

/////////////////////////////////////////
/* Metodos para consulta de informacao */
/////////////////////////////////////////


/////////////////////////////////////////////////
/* Metodos para guardar informacao em ficheiro */
/////////////////////////////////////////////////

void Empresa::guardaFornecedores(string fichFornecedores) {

	ofstream fornecedoresFile(fichFornecedores.c_str());

	for (unsigned int i=0; i < fornecedores.size(); i++) {

		fornecedoresFile << fornecedores.at(i).getNome() << ", " << fornecedores.at(i).getNIF() << ", " << fornecedores.at(i).getMorada();
		if (i != (fornecedores.size()-1))
			fornecedoresFile << endl;

	}

}

void Empresa::guardaOfertas(string fichOfertas) {

	ofstream ofertasFile(fichOfertas.c_str());

	for (unsigned int i=0; i < fornecedores.size(); i++) {

		for(unsigned int j = 0; j < fornecedores.at(i).getOfertas().size(); j++) {

			ofertasFile << fornecedores.at(i).getNIF() << fornecedores.at(i).getOfertas().at(j).getBarco() << ", " << fornecedores.at(i).getOfertas().at(j).getDestino() << ", "
					<< fornecedores.at(i).getOfertas().at(j).getLotacao() << ", " << fornecedores.at(i).getOfertas().at(j).getLotacaoMax() << ", "
					<< fornecedores.at(i).getOfertas().at(j).getData().getHoraInicio() << ":00, " << fornecedores.at(i).getOfertas().at(j).getData().getHoraFim()
					<< ":00, ";
			if(i != (fornecedores.size()-1))
				ofertasFile << endl;

		}

	}

}
