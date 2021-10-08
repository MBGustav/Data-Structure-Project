#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Fila.hpp"
#include "Pessoa.hpp"

using namespace std;

void novoCadastro(string* nome, string* cpf);
void CSVcreator(string fPath);
void CSVreader(string fPath);

int main(){
    //Interface principal
    /*
    cout << "O que deseja fazer?" << endl;
    cout << "1. Realizar a leitura de presença (criar um novo .csv)" << endl;
    cout << "2. Carregar um arquivo .csv existente" << endl;
    */
    cout << "Criação de um arquivo e cadastro de alunos" << endl;
    CSVcreator("data.csv");
    CSVreader("data.csv");

    return 0;

}

void novoCadastro(string* nome, string* cpf) {
    cout << "Nome: ";
    getline(cin, *nome);
    cout << "CPF: ";
    getline(cin, *cpf);
}

/*CSVcreator: cria (ou modifica, caso já exista) um arquivo .csv utilizando o
método novoCadastro para obter as informações dos participantes.*/
void CSVcreator(string fPath) {
    fstream arq;
    arq.open(fPath, ios::out | ios::app);
    cout << "===CADASTRO DE PARTICIPANTES===" << endl;
    string nome, cpf;
    novoCadastro(&nome, &cpf);
    //Gravando as informações no arquivo
    arq << nome << ", ";
    arq << cpf << ", ";
}

void CSVreader(string fPath){

    ifstream data(fPath);
    string line;
    while (getline(data, line))
    {
        stringstream lineStream(line);
        string celula;
        while (getline(lineStream, celula, ','))
        {
            cout << celula << endl;
        }
        
    }
    

}