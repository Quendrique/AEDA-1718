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
		cout << "|   1.                                                |" << endl;
		cout << "+-----------------------------------------------------+" << endl;
		cout << "|   2.                                                |" << endl;
		cout << "+-----------------------------------------------------+" << endl;
		cout << "|   3.                                                |" << endl;
		cout << "+-----------------------------------------------------+" << endl;
		cout << "|   4.Visualizacao de informacao                      |" << endl;
		cout << "+-----------------------------------------------------+" << endl;
		cout << "|   5.Guardar informação                              |" << endl;
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
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			system("cls");
			cerr << "Erro! Opcao submetida nao existe";
		}

	}

	return 0;
}




