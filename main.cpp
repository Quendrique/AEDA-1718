#include <iostream>

#include "barco.h"
#include "cliente.h"
#include"empresa.h"
#include "fornecedor.h"
#include "oferta.h"

using namespace std;

int main () 
{
	cout << "               __Bemvindo a empresa Porto Rivers__             " << endl << endl;

	//Inserir o nome dos ficheiros de texto

	cout << "Por favor insira o nome dos ficheiros" << endl;
	/*
	PROCESS IT..
	*/

	system("cls"); // limpa a janela de comando

	/*
	Chamar ler ficheiro de linhas e condutores
	...
	*/

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
		cout << "|   4.Guardar informação                              |" << endl;
		cout << "+-----------------------------------------------------+" << endl;
		cout << "|   0.Sair                                            |" << endl;
		cout << "+-----------------------------------------------------+" << endl;
		cout << "opção: ";
		cin >> option;
		system("cls"); // limpa a janela de comando


		switch (option)
		{
		case 0: //sair	
			return 0;
			break;

		case 1: //entrar como utilizador
			int option_utilizador;

			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   Escolha a opcao pertendida                        |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   1.Consultar pontos                                |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   2.Fazer reserva                                   |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   3.Cancelar reserva                                |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "opção: ";
			cin >> option_utilizador;
			system("cls");

			int  option_utilizador_2;

			switch (option_utilizador_2)
			{
			case 1: // consultar pontos
				//chamar a função de consular pontos
				break;

			case 2: //fazer reserva
				//mostrar as vigens disponiveis adado o dia e o local de chegada pretendididos pelo utilizador
				break;

			case 3: //cancelar reserva
				//chamar a função que apaga a reserva no vetor de reservas e trata da taxa (saldo da empresa= saldo-taxa de cancelamento )
			}

			break;

		case 2:
			int opcao_fornecedor;

			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   Escolha a opcao pertendida                        |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   1.Registar novo fornecedor                        |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   2.Acrescentar oferta                              |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   3.Remover oferta                                  |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cin >> opcao_fornecedor;
			system("cls");

			switch (opcao_fornecedor)
			{
			case 1: //registar novo fornecedor
				 //adicionar o fornecedor ao vetor de fornecedores da empresa DEVIA ESTAR NA OPCAO DE GESTOR
				break;

			case 2: // acrescentar oferta
				//adicionar uma nova oferta
				break;

			case 3: //remover oferta
				break;

			}
			break;

		case 3: //entar como gestor
			int option_gestor;

			cout << "+-----------------------------------------------------+" << endl;
			cout << "| Escolha a opcao pretendida:                         |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   1. Vizualizar dados                                |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|   2. Gerir saldo                                    |" << endl;
			cout << "+-----------------------------------------------------+" << endl;

			cout << "opção: ";
			cin >> option;
			system("cls"); // limpa a janela de comando

			switch (option_gestor)
			{
			case1: //visualizar dados
				int option_visualiza_g;
				cout << "+-----------------------------------------------------+" << endl;
				cout << "| O que pretende visualizar:                         |" << endl;
				cout << "+-----------------------------------------------------+" << endl;
				cout << "|   1. Fornecedores                                   |" << endl;
				cout << "+-----------------------------------------------------+" << endl;
				cout << "|   2. Clientes                                       |" << endl;
				cout << "+-----------------------------------------------------+" << endl;

				cout << "opção: ";
				cin >> option_visualiza_g;
				system("cls");

				switch (option_visualiza_g)
				{
				case 1:
					//chama função de visualização dos fornecedores
					break;
				case 2:
					//chama a função de visualização dos clientes
					break;
				}
				break;

			case 2: //gerir saldo

				//imprime o saldo no ecrã (mostrando o dinheiro ganho com as viajens e taxas perdidas com cancelamentos de viajens)


				break;
			}
			break;

		case 4: //guardar a informção nos ficheiros de texto
			/*
			Chamar a função que guarda a informação nos ficheiros de texto
			*/
			break;


		default:
			system("cls");
			cerr << "Erro! Opcao submetida nao existe";
		}

	}

	return 0;
}

