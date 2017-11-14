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

void Empresa::carregaOferta( string ficheiro_oferta)
{
	ifstream fichor(ficheiro_oferta);

	vector<Oferta> oferta;
	Oferta of;
	Data data;
	string linha_oferta;
	string linha_sbarco,linha_sdest;
	string linha_snif,linha_slot,linha_data;
	string barco,destino;
	int pos_nif,pos_barco,pos_destino,pos_distancia, pos_lotacao;
	unsigned int nif_oferta,lotacao,distancia;
	int pos_mes,pos_dia,pos_horainicio,pos_horafim,pos_mininicio,pos_minfim;
	int mes,dia,horainicio,horafim,mininicio,minfim;
	string linha_smes,linha_sdia,linha_shorain,linha_sminincio,linha_shorafim;
	if(fichor.is_open())
	{

		while(getline(fichor,linha_oferta))
		{
			pos_nif=linha_oferta.find(",",0);

			nif_oferta= stol( linha_oferta.substr(0,pos_nif));

			of.setId(nif_oferta);


			linha_snif=linha_oferta.substr(pos_nif+2,linha_oferta.size()-1);



			pos_barco= linha_snif.find(",",0);
			barco=linha_snif.substr(0,pos_barco);



			of.setBarco(barco);

			linha_sbarco= linha_snif.substr(pos_barco+2,linha_snif.size()-1);

			pos_destino=linha_sbarco.find(",",0);
			destino=linha_sbarco.substr(0,pos_destino);


			of.setDestino(destino);


			linha_sdest= linha_sbarco.substr(pos_destino+2,linha_sbarco.size()-1);


			pos_lotacao=linha_sdest.find(",",0);
			lotacao=stoi(linha_sdest.substr(0,pos_lotacao));

			of.setLotacaoMax(lotacao);
			linha_slot=linha_sdest.substr(pos_lotacao+2,linha_sdest.size()-1);

			pos_distancia=linha_slot.find(",",0);
			distancia=stoi(linha_slot.substr(0,pos_distancia));
			of.setDistancia(distancia);


			linha_data=linha_slot.substr(pos_distancia+2,linha_slot.size()-1);

			pos_mes=linha_data.find(",",0);
			mes=stoi(linha_data.substr(0,pos_mes));

			data.setMes(mes);
			linha_smes=linha_data.substr(pos_mes+2,linha_data.size()-1);

			pos_dia=linha_smes.find(",",0);
			dia=stoi(linha_smes.substr(0,pos_dia));

			data.setDia(dia);
			linha_sdia=linha_smes.substr(pos_dia+2,linha_smes.size()-1);

			pos_horainicio=linha_sdia.find(":",0);
			horainicio=stoi(linha_sdia.substr(0,pos_horainicio));

			data.setHoraInicio(horainicio);
			linha_shorain=linha_sdia.substr(pos_horainicio+1,linha_sdia.size()-1);

			pos_mininicio=linha_shorain.find(",",0);
			mininicio=stoi(linha_shorain.substr(0,pos_mininicio));

			data.setMinutosInicio(mininicio);
			linha_sminincio=linha_shorain.substr(pos_mininicio+2,linha_shorain.size()-1);


			pos_horafim=linha_sminincio.find(":",0);
			horafim=stoi(linha_sminincio.substr(0,pos_horafim));

			data.setHoraFim(horafim);
			linha_shorafim=linha_sminincio.substr(pos_horafim+1,linha_sminincio.size()-1);

			minfim=stoi(linha_shorafim);

			data.setMinutosFim(minfim);
			of.setData(data);
			//oferta.push_back(of);

			for (unsigned int i = 0; i < fornecedores.size(); i++) {

				if (fornecedores.at(i).getNIF() == nif_oferta) {
					fornecedores.at(i).addOfertaInit(of);
				}

			}

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

	for (unsigned int i=0; i < clientes.size(); i++) {
		if (clientes.at(i)->getNIF() == NIF) {
			c1 = clientes.at(i);
			return true;
		}
	}

	throw ClienteInexistente(NIF);

}

bool Empresa::checkFornecedorNIF(unsigned int NIF, Fornecedor *f1) {

	for (unsigned int i=0; i < fornecedores.size(); i++) {
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

bool Empresa::printOfertasByDestino(string destino) const {

	bool test;

	for (unsigned int i = 0 ; i < fornecedores.size(); i++) {
		test = fornecedores.at(i).printOfertasByDestino(destino);
	}

	return test;
}



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
