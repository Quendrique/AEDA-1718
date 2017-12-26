#include <iostream>

#include "cliente.h"
#include "empresa.h"
#include "fornecedor.h"
#include "oferta.h"
#include <cstdlib>
#include <limits>

using namespace std;

void clear_screen() // em linux, o comando system() nao aceita o argumento "cls", dai esta wrapper function que determina o sistema operativo
{
#ifdef _WIN32
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}

int main () 
{
	unsigned long NIF;// NIF usado para identificacao do cliente ou do fornecedor
	string FornecedoresFileName, OfertasFileName, ClientesFileName, ClientesRegFileName;
	int mes_Atual, dia_Atual;


	cout << "               __Bemvindo a empresa Porto Rivers__             " << endl << endl;

	//Inserir o nome dos ficheiros de texto

	cout << "Por favor insira o nome dos ficheiros" << endl;

	cout << "Fornecedores: ";
	cin >> FornecedoresFileName;
	cout << endl;

	cout << "Ofertas: ";
	cin >> OfertasFileName;
	cout << endl;

	cout << "Clientes registados: ";
	cin >> ClientesRegFileName;
	cout << endl;

	cout << "Clientes não registados: ";
	cin >>ClientesFileName;
	cout << endl;
cout << "Insira o dia:";
	cin >> dia_Atual;
	cout << endl;
	cout << "Insira o mes:";
	cin >> mes_Atual;
	cout << endl;
	Data d(dia_Atual, mes_Atual);
	Empresa PortoRivers(FornecedoresFileName, OfertasFileName, ClientesFileName, ClientesRegFileName,d);
	
	// TEMPORARIO - FILE PATHS PARA FICHEIROS

	PortoRivers.carregaFornecedores("C:\\Users\\up201604414\\Downloads\\AEDA-1718-master\\AEDA-1718-master\\fornecedores.txt");
	PortoRivers.carregaOferta("C:\\Users\\up201604414\\Downloads\\AEDA-1718-master\\AEDA-1718-master\\ofertas.txt");
	PortoRivers.carregaClientes("C:\\Users\\up201604414\\Downloads\\AEDA-1718-master\\AEDA-1718-master\\clientest.txt");
	PortoRivers.carregaClientesReg("C:\\Users\\up201604414\\Downloads\\AEDA-1718-master\\AEDA-1718-master\\clientesR.txt");

	clear_screen(); // limpa a janela de comando

	int option;
	while (true)
	{
		cout << "                                                       " << endl;
		cout << " ____            _          ____  _                    " << endl;
		cout << "|  _ \\ ___  _ __| |_ ___   |  _ \\(_)_   _____ _ __ ___ " << endl;
		cout << "| |_) / _ \\| '__| __/ _ \\  | |_) | \\ \\ / / _ \\ '__/ __|" << endl;
		cout << "|  __/ (_) | |  | || (_) | |  _ <| |\\ V /  __/ |  \\__ \\" << endl;
		cout << "|_|   \\___/|_|  \\__ \\___/  |_| \\_\\_| \\_/ \\___|_|  |___/" << endl;
		cout << "                                                       " << endl;
		cout << "+-----------------------------------------------------+" << endl;
		cout << "|                                                     |" << endl;
		cout << "|               __CRUZEIROS RIO DOURO__               |" << endl;
		cout << "|                                                     |" << endl;
		cout << "| Escolha a opcao pretendida:                         |" << endl;
		cout << "+-----------------------------------------------------+" << endl;
		cout << "|   1.Entrar como utilizador                          |" << endl;
		cout << "+-----------------------------------------------------+" << endl;
		cout << "|   2.Entrar como fornecedor                          |" << endl;
		cout << "+-----------------------------------------------------+" << endl;
		cout << "|   3.Entrar como gestor                              |" << endl;
		cout << "+-----------------------------------------------------+" << endl;
		cout << "|   4.Guardar informacao                              |" << endl;
		cout << "+-----------------------------------------------------+" << endl;
		cout << "|   0.Sair                                            |" << endl;
		cout << "+-----------------------------------------------------+" << endl;
		
		cout << "opção: ";
		cin >> option;

		while(cin.fail()) {// input nao e um numero

		    cin.clear();
		    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		    //cout << "Por favor insira um numero: ";
		    cin >> option;
			cin.get();
			cin.get();
		}
		clear_screen(); // limpa a janela de comando


		switch (option)
		{
		case 0: //sair	
			return 0;
			break;

		case 1: 
		{ 
			//entrar como utilizador
			int option_utilizador;
			bool clienteExiste;
			clienteExiste = false;
			Cliente *c1 = NULL; //apontador para o cliente com que estamos a trabalhar

			// VERIFICA SE CLIENTE EXISTE

			while (!clienteExiste) {
				cout << "Insira o seu NIF (0 para cancelar): ";
				cin >> NIF;
				while (cin.fail()) {// input nao e um numero

					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Por favor insira um numero: ";
					cin >> NIF;
				}
				if (NIF == 0) break;

				try {
					clienteExiste = PortoRivers.checkClienteNIF(NIF, &c1); //funcao que procura o NIF inserido no vetor de clientes, atira excecao se nao existir
				}
				catch (ClienteInexistente &e) {
					cout << "Cliente com o NIF " << e.getNIF() << " nao existe" << endl;
				}
			}

			if (NIF == 0) break;

			//FIM DE VERIFICACAO

			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   Escolha a opcao pertendida                        |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   1.Consultar pontos                                |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   2.Fazer reserva                                   |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   3.Cancelar reserva                                |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   4.Consultar reservas                              |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   5.Consultar ofertas com desconto                  |" << endl;
			cout << "+-----------------------------------------------------+" << endl;

			
			cout << "opcao: ";
			cin >> option_utilizador;

			while (cin.fail()) {// input nao e um numero

				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Por favor insira a opcao: ";
				cin >> option_utilizador;
			}
			clear_screen();


			switch (option_utilizador)
			{
			case 1: { // consultar pontos

				c1->printPontos();
				cin.get();
				cin.get();
				clear_screen();
			}
					break;

			case 2: //fazer reserva

				int option_utilizador_reserva;
				long unsigned int nif_reserva;
				int numero_oferta;

				cout << "+-----------------------------------------------------+" << endl;
				cout << "|   Escolha a opcao pertendida                        |" << endl;
				cout << "+-----------------------------------------------------+" << endl;
				cout << "|   1.Procurar por destino                            |" << endl;
				cout << "+-----------------------------------------------------+" << endl;
				cout << "|   2.Procurar por data                               |" << endl;
				cout << "+-----------------------------------------------------+" << endl;
				cout << "|   3.Consultar lista de oferta                       |" << endl;
				cout << "+-----------------------------------------------------+" << endl;

				cout << "opcao: ";
				cin >> option_utilizador_reserva;

				while (cin.fail()) {// input nao e um numero

					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Por favor insira um numero: ";
					cin >> option_utilizador_reserva;

					//verificacao do cin
				}
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				clear_screen();

				switch (option_utilizador_reserva) {
				case 1: {

					string destino;
					cout << "Insira o destino que deseja pesquisar: ";
					getline(cin, destino);

					//INCLUIR EXCECAO DESTINO INEXISTENTE

					PortoRivers.printOfertasByDestino(destino);

					cout << "Insira o NIF do fornecedor ao qual a oferta corresponde (0 para cancelar): ";
					cin >> nif_reserva;
					while (cin.fail()) {// input nao e um numero

						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Por favor insira um numero: ";
						cin >> nif_reserva;
					}

					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					if (nif_reserva == 0)
						break;

					cout << "Insira o numero da oferta (0 para cancelar): ";
					cin >> numero_oferta;
					while (cin.fail()) {// input nao e um numero

						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Por favor insira um numero: ";
						cin >> numero_oferta;
					}

					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					if (numero_oferta == 0)
						break;

					try {
						PortoRivers.atribuiReserva(nif_reserva, NIF, numero_oferta, d);
					}
					catch (ReservaJaFeita &r) {
						cout << "Esta reserva ja foi feita" << endl;
						cin.get();
						clear_screen();
						break;
					}
					catch (CruzeiroCheio &c) {
						cout << "O cruzeiro já atingiu a capacidade maxima" << endl;
						cin.get();
						clear_screen();
						break;
					}
					catch (IndexOutOfBounds &i) {
						cout << "A numero da oferta que indicou nao corresponde a nenhuma oferta existente para este fornecedor" << endl;
						cin.get();
						clear_screen();
						break;
					}
					catch (FornecedorInexistente &f) {
						cout << "Fornecedor com o NIF " << f.getNIF() << " nao existe" << endl;
						cin.get();
						clear_screen();
						break;
					}

					cout << "Reserva feita com sucesso" << endl;
					cin.get();
					clear_screen();

				}

						break;

				case 2: {

					int  lotacaoMax, mes, dia;
					string  horainicio, horafim;
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

						if (pos == std::string::npos)
						{
							cin.clear();
							cout << "Imput invalido!" << endl << "Indroduza novamente: ";
						}
						else
						{
							x = 0;
						}
						if (isdigit(horainicio[0]) && isdigit(horainicio[1]) && isdigit(horainicio[3]) && isdigit(horainicio[4]) && pos == 2)
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


					Data data;

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


					// PROCESSAR DATA ...

					PortoRivers.printOfertasByData(data);

					cout << "Insira o NIF do fornecedor ao qual a oferta corresponde (0 para cancelar): ";
					cin >> nif_reserva;
					while (cin.fail()) {// input nao e um numero

						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Por favor insira um numero: ";
						cin >> nif_reserva;
					}

					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					if (nif_reserva == 0)
						break;

					cout << "Insira o numero da oferta (0 para cancelar): ";
					cin >> numero_oferta;
					while (cin.fail()) {// input nao e um numero

						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Por favor insira um numero: ";
						cin >> numero_oferta;
					}

					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					if (numero_oferta == 0)
						break;

					try {
						PortoRivers.atribuiReserva(nif_reserva, NIF, numero_oferta,d);
					}
					catch (ReservaJaFeita &r) {
						cout << "Esta reserva ja foi feita" << endl;
						cin.get();
						clear_screen();
						break;
					}
					catch (CruzeiroCheio &c) {
						cout << "O cruzeiro já atingiu a capacidade maxima" << endl;
						cin.get();
						clear_screen();
						break;
					}
					catch (IndexOutOfBounds &i) {
						cout << "A numero da oferta que indicou nao corresponde a nenhuma oferta existente para este fornecedor" << endl;
						cin.get();
						clear_screen();
						break;
					}
					catch (FornecedorInexistente &f) {
						cout << "Fornecedor com o NIF " << f.getNIF() << " nao existe" << endl;
						cin.get();
						clear_screen();
						break;
					}

					cout << "Reserva feita com sucesso" << endl;
					cin.get();
					clear_screen();


				}
						break;

				case 3: {

					PortoRivers.printOfertas();

					cout << "Insira o NIF do fornecedor ao qual a oferta corresponde (0 para cancelar): ";
					cin >> nif_reserva;
					while (cin.fail()) {// input nao e um numero

						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Por favor insira um numero: ";
						cin >> nif_reserva;
					}

					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					if (nif_reserva == 0)
						break;

					cout << "Insira o numero da oferta (0 para cancelar): ";
					cin >> numero_oferta;
					while (cin.fail()) {// input nao e um numero

						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Por favor insira um numero: ";
						cin >> numero_oferta;
					}

					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					if (numero_oferta == 0)
						break;

					try {
						PortoRivers.atribuiReserva(nif_reserva, NIF, numero_oferta,d);
					}
					catch (ReservaJaFeita &r) {
						cout << "Esta reserva ja foi feita" << endl;
						cin.get();
						clear_screen();
						break;
					}
					catch (CruzeiroCheio &c) {
						cout << "O cruzeiro já atingiu a capacidade maxima" << endl;
						cin.get();
						clear_screen();
						break;
					}
					catch (IndexOutOfBounds &i) {
						cout << "A numero da oferta que indicou nao corresponde a nenhuma oferta existente para este fornecedor" << endl;
						cin.get();
						clear_screen();
						break;
					}
					catch (FornecedorInexistente &f) {
						cout << "Fornecedor com o NIF " << f.getNIF() << " nao existe" << endl;
						cin.get();
						clear_screen();
						break;
					}

					cout << "Reserva feita com sucesso" << endl;
					cin.get();
					clear_screen();


				}
						break;

				}

				break;

			case 3: //cancelar reserva

				unsigned int numero_reserva;

				PortoRivers.printReservasByCliente(NIF);

				cout << "Insira o numero da reserva que deseja remover:";
				cin >> numero_reserva;
				while (cin.fail()) {// input nao e um numero

					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Por favor insira um numero: ";
					cin >> numero_reserva;
				}

				PortoRivers.removeReserva(NIF, numero_reserva);

				cout << "Reserva cancelada com sucesso" << endl;
				cin.get();
				cin.get();
				clear_screen();

				break;

			case 4: {

				try {
					PortoRivers.printReservasByCliente(NIF);
				}
				catch (SemReservas &r) {
					cout << "Nao tem reservas planeadas" << endl;
				}

				cin.get();
				cin.get();
				clear_screen();

			}
					break;
			case 5: //mostrar descontos

				PortoRivers.Descontos();
				break;

			}
		}
		break;

		case 2: {

			int opcao_fornecedor;
			bool fornecedorExiste;
			fornecedorExiste = false;
			Fornecedor *f1 = NULL; //apontador para o fornecedor com que estamos a trabalhar

			// VERIFICA SE FORNECEDOR EXISTE

			while (!fornecedorExiste) {
				cout << "Insira o seu NIF (0 para cancelar): ";
				cin >> NIF;
				while (cin.fail()) {// input nao e um numero

					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Por favor insira um numero: ";
					cin >> NIF;
				}
				if (NIF == 0) break;

				try {
					fornecedorExiste = PortoRivers.checkFornecedorNIF(NIF, &f1); //funcao que procura o NIF inserido no vetor de clientes, atira excecao se nao existir
				}
				catch (FornecedorInexistente &e) {
					cout << "Fornecedor com o NIF " << e.getNIF() << " nao existe" << endl;
				}

			}

			if (NIF == 0) break;

			//FIM DE VERIFICACAO

			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   Escolha a opcao pertendida                        |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   1.Visualizar as minhas ofertas                    |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   2.Acrescentar oferta                              |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   3.Consultar saldo                                 |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			
			cin >> opcao_fornecedor;
			
			while (cin.fail()) {// input nao e um numero

				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Por favor insira um numero: ";
				cin >> opcao_fornecedor;
			}
			clear_screen();

			switch (opcao_fornecedor) {
			case 1: //visualizar as ofertas do formcecedor em causa

				PortoRivers.visualizaOfertas(NIF);
				cin.get();
				cin.get();
				clear_screen();
				break;

			case 2: // acrescentar oferta
				PortoRivers.addOfertas(NIF);
				break;

			case 3: { //consultar lucro

				cout << "O seu lucro e de " << f1->calculaLucro() << " euros" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cin.get();
				clear_screen();

				}
					break;

			}

		}
			break;

		case 3: { //entar como gestor
			int option_gestor;

			cout << "+-----------------------------------------------------+" << endl;
			cout << "| Escolha a opcao pretendida:                         |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   1. Vizualizar dados                               |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   2. Gerir saldo                                    |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   3. Registar novo fornecedor                       |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   4. Remover fornecedor                             |" << endl;
			cout << "+-----------------------------------------------------+" << endl;


			cout << "opcao: ";
			cin >> option_gestor;

			while (cin.fail()) {// input nao e um numero

				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Por favor insira um numero: ";
				cin >> option_gestor;
			}
			clear_screen(); // limpa a janela de comando

			switch (option_gestor)
			{
			case 1: //visualizar dados
				
				int option_visualiza_g;
				cout << "+-----------------------------------------------------+" << endl;
				cout << "| O que pretende visualizar:                          |" << endl;
				cout << "+-----------------------------------------------------+" << endl;
				cout << "|   1. Fornecedores                                   |" << endl;
				cout << "+-----------------------------------------------------+" << endl;
				cout << "|   2. Clientes Registados                            |" << endl;
				cout << "+-----------------------------------------------------+" << endl;

				cout << "opcao: ";
				cin >> option_visualiza_g;
				
				while (cin.fail()) {// input nao e um numero

					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Por favor insira um numero: ";
					cin >> option_visualiza_g;
				}
				clear_screen();

				switch (option_visualiza_g)
				{
				case 1: // mostra informacao sobre todos os fornecedores

					PortoRivers.printFornecedores();
					cout << "Prima enter para continuar" << endl;
					cin.get();
					cin.get();
					clear_screen();
					break;

				case 2: // mostra informacao sobre todos os clientes (registados ou nao)

					PortoRivers.printClientes();
					cout << "Prima enter para continuar" << endl;
					cin.get();
					cin.get();
					clear_screen();
					break;

				}

				break;

			case 2: {//gerir saldo

				//PortoRivers.printLucrosTotais();

				for (unsigned int i = 0; i < PortoRivers.getFornecedores().size(); i++) {
					cout << "O fornecedor " << PortoRivers.getFornecedores().at(i).getNIF() << " devera pagar uma taxa de " << PortoRivers.getFornecedores().at(i).calculaTaxas() << " euros" << endl;
				}
				cout << "Prima enter para continuar" << endl;
				cin.get();
				cin.get();
				clear_screen();
			}
				break;

			case 3: {

				string nomeFornecedor, moradaFornecedor;
				unsigned int precoKm, precoLot20, precoLot35, precoLot50;
				long double nifFornecedor;

				cout << "Insira o nome do fornecedor a adicionar: ";
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				getline(cin, nomeFornecedor);
				cout << "Insira no NIF do fornecedor a adicionar: ";
				cin >> nifFornecedor;
				while (cin.fail()) {// input nao e um numero

					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Por favor insira um numero: ";
					cin >> nifFornecedor;
				}

				try {
					PortoRivers.checkFornecedorNIF(nifFornecedor);
				}
				catch (FornecedorExistente &f) {
					cout << "Fornecedor com o NIF " << f.getNIF() << " ja existe" << endl;
					cin.get();
					cin.get();
					clear_screen();
					break;
				}

				cout << "Insira a morada do fornecedor a adicionar (cidade): ";
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				getline(cin, moradaFornecedor);

				cout << "Insira o preco por km de viagem estabelecido: ";
				cin >> precoKm;
				while (cin.fail()) {// input nao e um numero

					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Por favor insira um numero: ";
					cin >> precoKm;
				}

				cout << "Insira o preco do escalao de lotacao ate 20 lugares: ";
				cin >> precoLot20;
				while (cin.fail()) {// input nao e um numero

					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Por favor insira um numero: ";
					cin >> precoLot20;
				}

				cout << "Insira o preco do escalao de lotacao ate 35 lugares: ";
				cin >> precoLot35;
				while (cin.fail()) {// input nao e um numero

					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Por favor insira um numero: ";
					cin >> precoLot35;
				}

				cout << "Insira o preco do escalao de lotacao ate 50 lugares: ";
				cin >> precoLot50;
				while (cin.fail()) {// input nao e um numero

					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Por favor insira um numero: ";
					cin >> precoLot50;
				}



				Fornecedor *f1 = new Fornecedor(nomeFornecedor, nifFornecedor, moradaFornecedor);
				vector<unsigned int> precoLot = { precoLot20, precoLot35, precoLot50 };
				f1->setPrecoLot(precoLot);
				f1->setPrecoKm(precoKm);
				PortoRivers.addFornecedor(*f1);

				cout << "Fornecedor adicionado com sucesso" << endl << endl;
				cin.get();
				cin.get();
				clear_screen();
			}
				break;

			case 4: { //remove forneceedor do vetor de fornecedores

				long double nifFornecedor;

				cout << "Insira o NIF do fornecedor que deseja remover: ";
				cin >> nifFornecedor;
				while (cin.fail()) {// input nao e um numero

					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Por favor insira um numero: ";
					cin >> nifFornecedor;
				}
				
				try {
					PortoRivers.removerFornecedor(nifFornecedor);
				}
				catch (FornecedorInexistente &f) {
					cout << "Fornecedor com o NIF " << f.getNIF() << " nao existe" << endl;
					cin.get();
					cin.get();
					clear_screen();
					break;
				}

				cout << "Fornecedor removido com sucesso" << endl;
				cin.get();
				cin.get();
				clear_screen();
			}
				break;
			}
			break;

		}

		case 4: //guardar a informção nos ficheiros de texto
			
			PortoRivers.guardaClientes(ClientesRegFileName, ClientesFileName);
			PortoRivers.guardaFornecedores("C:\\Users\\catam\\Desktop\\aedafinal\\aedafinal\\fornecedores.txt"); //file path so para testes
			PortoRivers.guardaOfertas("C:\\Users\\catam\\Desktop\\aedafinal\\aedafinal\\ofertas.txt");  //file path so para testes

		
			break;


		default: {
			clear_screen();
			cerr << "Erro! Opcao submetida nao existe";
		}
		}

	}

	return 0;
}

