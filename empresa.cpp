#include "empresa.h"

Empresa::Empresa(string fichFornecedores,string fichOfertas,string fichClientes,string fichClientesReg)
{
	this->fichFornecedores = fichFornecedores;
	this->fichOfertas = fichOfertas;
	this->fichClientes = fichClientes;
	this->fichClientesReg = fichClientesReg;
}

Empresa::Empresa(string nome, vector<Fornecedor> fornecedores, vector<Cliente*> clientes)
{
	this->nome = nome;
	this->fornecedores = fornecedores;
	this->clientes = clientes;
}

vector<Fornecedor> Empresa::getFornecedores() const
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
	string nifTmp, precoKmTmp, precoLot20Tmp, precoLot35Tmp, precoLot50Tmp;
	unsigned long nif = 0;
	unsigned int precoKm = 0, precoLot20=0, precoLot35 = 0, precoLot50 = 0;

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

			//////////
			/* NOME */
			//////////

			getline(ssF, nome, ',');

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

			getline(ssF, morada, ',');

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

			/////////////////
			/* PRECO POR KM*/
			/////////////////

			getline(ssF, precoKmTmp, ',');

			for (unsigned int j = 0; j <precoKmTmp.length(); j++) //retira espaço no inicio do preco
			{
				if (isalnum(precoKmTmp[j]))
					break;
				if (precoKmTmp[j] == ' ')
				{
					precoKmTmp.erase(precoKmTmp.begin() + j);
					j--;
				}
			}

			precoKm = stoi(precoKmTmp);

			///////////////////////
			/* PRECOS POR LOTACAO*/
			///////////////////////

			getline(ssF, precoLot20Tmp, ',');

			for (unsigned int j = 0; j <precoLot20Tmp.length(); j++) //retira espaço no inicio do preco
			{
				if (isalnum(precoLot20Tmp[j]))
					break;
				if (precoLot20Tmp[j] == ' ')
				{
					precoLot20Tmp.erase(precoLot20Tmp.begin() + j);
					j--;
				}
			}

			precoLot20 = stoi(precoLot20Tmp);

			getline(ssF, precoLot35Tmp, ',');

			for (unsigned int j = 0; j <precoLot35Tmp.length(); j++) //retira espaço no inicio do preco
			{
				if (isalnum(precoLot35Tmp[j]))
					break;
				if (precoLot35Tmp[j] == ' ')
				{
					precoLot35Tmp.erase(precoLot35Tmp.begin() + j);
					j--;
				}
			}

			precoLot35 = stoi(precoLot35Tmp);

			getline(ssF, precoLot50Tmp, '\n');

			for (unsigned int j = 0; j <precoLot50Tmp.length(); j++) //retira espaço no inicio do preco
			{
				if (isalnum(precoLot50Tmp[j]))
					break;
				if (precoLot50Tmp[j] == ' ')
				{
					precoLot50Tmp.erase(precoLot50Tmp.begin() + j);
					j--;
				}
			}

			precoLot50 = stoi(precoLot50Tmp);

			vector<unsigned int> precoLot = { precoLot20, precoLot35, precoLot50 };
		
			f.setPrecoKm(precoKm);
			f.setPrecoLot(precoLot);
			f.setNome(nome);
			f.setNIF(nif);
			f.setMorada(morada);
			addFornecedor(f);

		}
	}
}

void Empresa::carregaOferta(string ficheiro_oferta)
{
	ifstream fichor(ficheiro_oferta);

	vector<Oferta> oferta;
	Oferta of;
	Data data;
	string linha_oferta;
	string linha_sbarco, linha_sdest;
	string linha_snif, linha_slot, linha_data;
	string barco, destino;
	int pos_nif, pos_barco, pos_destino, pos_distancia, pos_lotacao;
	unsigned int nif_oferta, lotacao, distancia;
	int pos_mes, pos_dia, pos_horainicio, pos_horafim, pos_mininicio, pos_minfim;
	int mes, dia, horainicio, horafim, mininicio, minfim;
	string linha_smes, linha_sdia, linha_shorain, linha_sminincio, linha_shorafim;
	if (fichor.is_open())
	{

		while (getline(fichor, linha_oferta))
		{
			pos_nif = linha_oferta.find(",", 0);

			nif_oferta = stol(linha_oferta.substr(0, pos_nif));

			of.setNif(nif_oferta);


			linha_snif = linha_oferta.substr(pos_nif + 2, linha_oferta.size() - 1);



			pos_barco = linha_snif.find(",", 0);
			barco = linha_snif.substr(0, pos_barco);



			of.setBarco(barco);

			linha_sbarco = linha_snif.substr(pos_barco + 2, linha_snif.size() - 1);

			pos_destino = linha_sbarco.find(",", 0);
			destino = linha_sbarco.substr(0, pos_destino);


			of.setDestino(destino);


			linha_sdest = linha_sbarco.substr(pos_destino + 2, linha_sbarco.size() - 1);


			pos_lotacao = linha_sdest.find(",", 0);
			lotacao = stoi(linha_sdest.substr(0, pos_lotacao));

			of.setLotacaoMax(lotacao);
			linha_slot = linha_sdest.substr(pos_lotacao + 2, linha_sdest.size() - 1);

			int pos_lotatual, lotatual;
			string linha_slotatual;
			pos_lotatual = linha_slot.find(",", 0);
			lotatual = stoi(linha_slot.substr(0, pos_lotatual));

			of.setLotacaoAtual(lotatual);
			linha_slotatual = linha_slot.substr(pos_lotatual + 2, linha_slot.size() - 1);


			pos_distancia = linha_slotatual.find(",", 0);
			distancia = stoi(linha_slotatual.substr(0, pos_distancia));
			of.setDistancia(distancia);


			linha_data = linha_slotatual.substr(pos_distancia + 2, linha_slotatual.size() - 1);

			pos_mes = linha_data.find(",", 0);
			mes = stoi(linha_data.substr(0, pos_mes));

			data.setMes(mes);
			linha_smes = linha_data.substr(pos_mes + 2, linha_data.size() - 1);

			pos_dia = linha_smes.find(",", 0);
			dia = stoi(linha_smes.substr(0, pos_dia));

			data.setDia(dia);
			linha_sdia = linha_smes.substr(pos_dia + 2, linha_smes.size() - 1);

			pos_horainicio = linha_sdia.find(":", 0);
			horainicio = stoi(linha_sdia.substr(0, pos_horainicio));

			data.setHoraInicio(horainicio);
			linha_shorain = linha_sdia.substr(pos_horainicio + 1, linha_sdia.size() - 1);

			pos_mininicio = linha_shorain.find(",", 0);
			mininicio = stoi(linha_shorain.substr(0, pos_mininicio));

			data.setMinutosInicio(mininicio);
			linha_sminincio = linha_shorain.substr(pos_mininicio + 2, linha_shorain.size() - 1);


			pos_horafim = linha_sminincio.find(":", 0);
			horafim = stoi(linha_sminincio.substr(0, pos_horafim));

			data.setHoraFim(horafim);
			linha_shorafim = linha_sminincio.substr(pos_horafim + 1, linha_sminincio.size() - 1);

			minfim = stoi(linha_shorafim);

			data.setMinutosFim(minfim);
			of.setData(data);


			for (unsigned int i = 0; i < fornecedores.size(); i++) {

				if (fornecedores.at(i).getNIF() == nif_oferta) {
					fornecedores.at(i).addOfertaInit(of);
				}

			}

		}
	}

}

void Empresa::carregaClientes(string fichClientes)
{
	istringstream ssC;
	ifstream File;
	File.open(fichClientes);
	char comma;
	unsigned long nif; 
	string morada, nifTmp;

	if (File.is_open())
	{
		string line;

		while (getline(File, line))
		{
			Fornecedor f;
			ssC.clear();
			nome.clear();
			morada.clear();
			nifTmp.clear();
			nif = 0;
			ssC.str(line);

			//////////
			/* NOME */
			//////////

			getline(ssC, nome, ',');

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

			getline(ssC, nifTmp, ',');

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

			getline(ssC, morada, '\n');

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

			Cliente *c1 = new Cliente(nome, nif, morada);
			clientes.push_back(c1);

		}
	}		
			
}

void Empresa::carregaClientesReg (string fichClientesR)
{
	istringstream ssCR;
	string line;
	ifstream File;
	File.open(fichClientesR);
	char comma;
	unsigned long nif;
	double pontos;
	string nome, morada, nifTmp, pontosTmp;


	if (File.is_open())
	{
		string line;

		while (getline(File, line))
		{
			Fornecedor f;
			ssCR.clear();
			nome.clear();
			morada.clear();
			nifTmp.clear();
			nif = 0;
			ssCR.str(line);

			//////////
			/* NOME */
			//////////

			getline(ssCR, nome, ',');

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

			getline(ssCR, nifTmp, ',');

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

			getline(ssCR, morada, ',');

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

			////////////
			/* PONTOS */
			////////////

			getline(ssCR, pontosTmp, '\n');

			for (unsigned int j = 0; j < pontosTmp.length(); j++) //retira espaço no inicio do nif
			{
				if (isalnum(pontosTmp[j]))
					break;
				if (pontosTmp[j] == ' ')
				{
					pontosTmp.erase(pontosTmp.begin() + j);
					j--;
				}
			}

			pontos = stol(pontosTmp);

			Cliente *c1 = new ClienteReg(nome, nif, morada, pontos);
			clientes.push_back(c1);

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
	for (unsigned int i=0; i < fornecedores.size(); i++) 
	{
		fornecedores.at(i).printInfo();
	}
}

void Empresa::printReservasByCliente(unsigned long NIF) const {

	for (unsigned int i = 0; i < clientes.size(); i++) {

		if (clientes.at(i)->getNIF() == NIF) {
			clientes.at(i)->printReservas();
		}
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

void Empresa::addOfertas(unsigned int NIF)
{
	int distancia, lotacaoMax, mes, dia;
	string destino, barco, horainicio, horafim;
	Data data;
	cout << "Indroduza a distancia: ";
	cin >> distancia;
	cout << endl;
	cin.ignore(100, '\n');
	while (cin.fail()) {// input nao e um numero

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Por favor insira um numero: ";
		cin >> distancia;
		cin.ignore(100, '\n');
	}
	int x1 = 0;
	while (x1 == 0)
	{
		cout << "Indroduza o destino: ";
		getline(cin, destino);
		//cin.ignore(100, '\n');
		if (destino.compare("Regua") == 0 || destino.compare("Pinhao") == 0 || destino.compare("Barca d'Alva") == 0)
		{
			x1 = 1;
		}
		else
		{
			cout << "Destino nao existente! " << endl;
			cout << "Indroduza novamente! " << endl;
		}
		// iate, barco rabelo ou veleiro
		//Régua, Pinhão ou Barca d’Alva

	}

	x1 = 0;
	cout << "Indroduza a lotacao maxima: ";
	cin >> lotacaoMax;
	cin.ignore(100, '\n');
	while (cin.fail()) {// input nao e um numero

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Por favor insira um numero: ";
		cin >> lotacaoMax;
		cin.ignore(100, '\n');
	}
		while (x1 == 0)
		{
			cout << "Indroduza o tipo de barco: ";
			getline(cin, barco);
			
			if (barco.compare("barco rabelo") == 0 || barco.compare("veleiro") == 0 || barco.compare("iate") == 0)
			{
				x1 = 1;
			}
			else
			{
				cout << "Barco nao existente! " << endl;
				cout << "Indroduza novamente! " << endl;
			}
			// iate, barco rabelo ou veleiro
			//Régua, Pinhão ou Barca d’Alva

		}
		cout << "Indroduza o mês: ";
		cin >> mes;
		cout << endl;
		while (cin.fail() || mes > 12 || mes < 1) {// input nao e um numero

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Por favor insira um numero de 1 a 12: ";
			cin >> mes;

		}
		cout << "Indroduza o dia: ";
		cin >> dia;
		cout << endl;
		while (cin.fail() || dia > 31 || dia < 1) {// input nao e um numero

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Por favor insira um numero de 1 a 31: ";
			cin >> dia;

		}
		int x = 1;
		while (x == 1)
		{

			unsigned int pos = 0;
			cout << "Indroduza a hora de partida(horas:minutos): ";
			cin >> horainicio;

			cin.ignore(100, '\n');
			pos = horainicio.find(":", 0);

			if (pos == std::string::npos )
			{
				cin.clear();
				cout << "Imput invalido!" << endl << "Indroduza novamente: ";
			}
			else
			{
				x = 0;
			}
			if(isdigit(horainicio[0]) && isdigit(horainicio[1]) && isdigit(horainicio[3]) && isdigit(horainicio[4]) && pos == 2)
			{
				x = 0;
			}
		else
		{
			cout << "Imput invalido!" << endl << "Indroduza novamente: ";
			x = 1;
		}
	}	
		

		x = 1;
		while (x == 1)
		{

			unsigned int pos = 0;
			cout << "Indroduza a hora de chegada(horas:minutos): ";
			cin >> horafim;

			cin.ignore(100, '\n');
			pos = horafim.find(":", 0);

			if (pos == std::string::npos)
			{
				cin.clear();
				cout << "Imput invalido!" << endl << "Indroduza novamente: " << endl;
			}
			else
			{
				x = 0;
			}
			if (isdigit(horafim[0]) && isdigit(horafim[1]) && isdigit(horafim[3]) && isdigit(horafim[4]) && pos == 2)
			{
				x = 0;
			}
			else
			{
				cout << "Imput invalido!" << endl << "Indroduza novamente: ";
				x = 1;
			}
		}




		unsigned int pos1, pos2, horaini, minini, horafim1, minfim;

		pos1 = horainicio.find(":", 0);
		pos2 = horafim.find(":", 0);
		horaini = stoi(horainicio.substr(0, pos1));
		horafim1 = stoi(horafim.substr(0, pos2));

		minini = stoi(horainicio.substr(pos1 + 1, horainicio.size() - pos1));
		minfim = stoi(horafim.substr(pos2 + 1, horafim.size() - pos2));

		data.setHoraFim(horafim1);
		data.setHoraInicio(horaini);
		data.setMinutosFim(minfim);
		data.setMinutosInicio(minini);
		data.setDia(dia);
		data.setMes(mes);
		for (unsigned int i = 0; i < fornecedores.size(); i++) {
			if (fornecedores.at(i).getNIF() == NIF) {
				fornecedores.at(i).addOferta(NIF, data, destino, barco, distancia, lotacaoMax, 0);

			}
		}
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

void Empresa::removeCliente(unsigned long clienteRemoveNIF) {

}

void Empresa::removeFornecedor(unsigned long  fornecedorRemoveNIF) {
	for (unsigned int i = 0; i < fornecedores.size(); i++)
		if (fornecedores.at(i).getNIF() == fornecedorRemoveNIF)
		{
			// ACABAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		}
}

////////////////////////////////////////////////////////////////////
/* Metodos para verificar a existencia de clientes e fornecedores */
////////////////////////////////////////////////////////////////////

void Empresa::printOfertas() const
{
	for (unsigned int i = 0; i < fornecedores.size(); i++) {
		fornecedores.at(i).printOfertas();
	}
}

bool Empresa::checkClienteNIF(unsigned long NIF, Cliente **c1) {

	for (unsigned int i=0; i < clientes.size(); i++) {
		if (clientes.at(i)->getNIF() == NIF) {
			*c1 = clientes.at(i);
			return true;
		}
	}

	throw ClienteInexistente(NIF);

}

bool Empresa::checkFornecedorNIF(unsigned long NIF, Fornecedor **f1) { //verifica o NIF e atribui a f1 o apontador para o fornecedor correspondente

	for (unsigned int i=0; i < fornecedores.size(); i++) {
		if (fornecedores.at(i).getNIF() == NIF) {
			*f1 = &(fornecedores.at(i));
			return true;
		}
	}

		throw FornecedorInexistente(NIF);

}


void Empresa::checkFornecedorNIF(unsigned long NIF) { //so verifica se existe o fornecedor em questao 

	for (unsigned int i = 0; i < fornecedores.size(); i++) {
		if (fornecedores.at(i).getNIF() == NIF) {
			throw FornecedorExistente(NIF);
		}
	}

}

bool Empresa::checkFornecedorNIFBool(unsigned long NIF) {

	for (unsigned int i = 0; i < fornecedores.size(); i++) {
		if (fornecedores.at(i).getNIF() == NIF) {
			return true;
		}
	}

	return false;
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

bool Empresa::printOfertasByData(Data data) const
{
	bool test;

	for (unsigned int i = 0; i < fornecedores.size(); i++) {
		test = fornecedores.at(i).printOfertasByData(data);
	}

	return test;
}

void Empresa::visualizaOfertas(unsigned long NIF)
{
	for (unsigned int i = 0; i < fornecedores.size(); i++)
	{
		if (fornecedores[i].getNIF() == NIF)
		{
			fornecedores.at(i).printOfertas();

		}
	}
}

/////////////////////////////////////////
/* Metodos para fazer reservas */////////
////////////////////////////////////////

void Empresa::atribuiReserva(unsigned long fornecedorNIF, unsigned long clienteNIF, int numeroOferta) {

	for (unsigned int i = 0; i < fornecedores.size(); i++) {

		if (fornecedores.at(i).getNIF() == fornecedorNIF) { //encontrou o fornecedor com o nif dado

			//EXCECAO PARA SE O NUMERO DE OFERTA FOR INFERIOR A 1 OU SUPERIOR AO NUMERO DE ELEMENTOS DO VETOR DE OFERTAS DO FORNECEDOR EM QUESTAO

			if (numeroOferta < 1 || numeroOferta > fornecedores.at(i).getOfertas().size())
				throw IndexOutOfBounds();

			if (fornecedores.at(i).getOfertas().at(numeroOferta - 1).getLotacaoAtual() == fornecedores.at(i).getOfertas().at(numeroOferta - 1).getLotacaoMax()) { //a lotacao do cruzeiro pretendido esta cheia
				throw CruzeiroCheio();
			}
			else {

				Oferta *updateLotacao;
				updateLotacao = fornecedores.at(i).getOfertaPointer(numeroOferta - 1);
				updateLotacao->addToLotacao(); // se a lotacao nao estiver cheia, adiciona 1 a lotacao atual do respetivo cruzeiro NAO VAI MODIFICAR VALOR, GETOFERTAS SO DEVOLVE UMA COPIA DO VETOR

				for (unsigned int j = 0; j < clientes.size(); j++) {

					if (clientes.at(j)->getNIF() == clienteNIF) { //encontrou o cliente que esta a fazer a reserva

						for (unsigned int l = 0; l < clientes.at(j)->getReservas().size(); l++) {

							if (*(clientes.at(j)->getReservas().at(l)) == *(fornecedores.at(i).getOfertaPointer(numeroOferta - 1))) { //a reserva ja foi feita
								throw ReservaJaFeita();
							}

						}

						Oferta *o1;
						o1 = fornecedores.at(i).getOfertaPointer(numeroOferta-1);
						clientes.at(i)->addReserva(o1);

					}

				}

			}


		}


	}

	//EXCECAO PARA FORNECEDORE INEXISTENTE
	throw FornecedorInexistente(fornecedorNIF);

}

void Empresa::removerFornecedor(unsigned long NIF) {

	if (!checkFornecedorNIFBool(NIF)) {
		throw FornecedorInexistente(NIF);
	}

	for (unsigned int i = 0; i < clientes.size(); i++) {
		clientes.at(i)->removeReservaByFornecedor(NIF);
	}

	for (unsigned int i = 0; i < fornecedores.size(); i++) {
		if (fornecedores.at(i).getNIF() == NIF) {
			fornecedores.erase(fornecedores.begin() + i);
		}
	}


}


/////////////////////////////////////////////////
/* Metodos para guardar informacao em ficheiro */
/////////////////////////////////////////////////

void Empresa::guardaFornecedores(string fichFornecedores) {

	ofstream fornecedoresFile(fichFornecedores);

	for (unsigned int i = 0; i < fornecedores.size(); i++) {

		fornecedoresFile << fornecedores.at(i).getNome() << ", " << fornecedores.at(i).getNIF() << ", "
			<< fornecedores.at(i).getMorada() << ", " << fornecedores.at(i).getPrecoKm() << ", "
			<< fornecedores.at(i).getPrecoLot().at(0) << ", " << fornecedores.at(i).getPrecoLot().at(1) << ", " << fornecedores.at(i).getPrecoLot().at(2);

		if (i != (fornecedores.size() - 1))
			fornecedoresFile << endl;

	}

}

void Empresa::guardaOfertas(string fichOfertas) {

	ofstream ofertasFile(fichOfertas.c_str());

	for (unsigned int i = 0; i < fornecedores.size(); i++) {

		for (unsigned int j = 0; j < fornecedores.at(i).getOfertas().size(); j++) {

			ofertasFile << fornecedores.at(i).getNIF() << ", " << fornecedores.at(i).getOfertas().at(j).getBarco() << ", " << fornecedores.at(i).getOfertas().at(j).getDestino() << ", "
				<< fornecedores.at(i).getOfertas().at(j).getLotacaoMax() << ", " << fornecedores.at(i).getOfertas().at(j).getLotacaoAtual() << ", "
				<< fornecedores.at(i).getOfertas().at(j).getDistancia() << ", " << fornecedores.at(i).getOfertas().at(j).getData().getMes() << ", " << fornecedores.at(i).getOfertas().at(j).getData().getDia() << ", "
				<< fornecedores.at(i).getOfertas().at(j).getData().getHoraInicio() << ":" << fornecedores.at(i).getOfertas().at(j).getData().getMinutosInicio() << ", " << fornecedores.at(i).getOfertas().at(j).getData().getHoraFim()
				<< ":" << fornecedores.at(i).getOfertas().at(j).getData().getMinutosFim();
			if (i != (fornecedores.size() - 1))
				ofertasFile << endl;

		}

	}

}

void Empresa::guardaClientes(string fichClientesR,string fichClientes)
{
	ofstream ClientesFileR(fichClientesR);
	ofstream ClientesFile(fichClientes);

	for (unsigned int i = 0; i < clientes.size(); i++)
	{
		if (clientes.at(i)->isRegistado())
		{
			ClientesFileR << clientes[i]->getNome() << "," << clientes[i]->getNIF() << "," << clientes[i]->getMorada() << clientes[i]->getPontos();
			
			if (i != (clientes.size() - 1))
				ClientesFileR << endl;
		}
		else
		{
			ClientesFile << clientes[i]->getNome() << "," << clientes[i]->getNIF() << "," << clientes[i]->getMorada();
			
			if (i != (clientes.size() - 1))
				ClientesFileR << endl;
		}

	}
}



/*void Empresa::visualizaOfertas(long double NIF)
{
	for (unsigned int i = 0; i < fornecedores.size(); i++)
	{
		if(fornecedores[i].getNIF()==NIF)


	}
}*/
