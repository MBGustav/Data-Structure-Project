#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include "Fila.hpp"

using namespace std;

void novoCadastro(string* nome, string* cpf);
void CSVcreator(string fPath, string nome, string cpf);
void CSVtoFila(string fPath, Fila* f);

int main(){
    //Interface principal
    //Decl. Globais
    bool deuCerto = true;
    int controle;
    string nome, cpf;
    Fila* fPessoas = new Fila();


    cout << "O que deseja fazer?" << endl;
    cout << "1. Inserir um participante na lista" << endl;
    cout << "2. Continuar para a emissão de certificados" << endl;
    cin >> controle;

    while (controle != 2)
    {
        switch (controle)
        {
        case 1:
            novoCadastro(&nome, &cpf);
            CSVcreator("data.csv", nome, cpf);
            break;
        
        case 2:
            cout << "Passando para a emissão dos certificados..." << endl;
            CSVtoFila("data.csv", fPessoas);
            cout << "Testando a inserção na fila..." << endl;
            while (deuCerto)
            {
                Pessoa p;
                fPessoas->Retira(fPessoas, &p, &deuCerto);
                cout << "Nome: " << p.nome << endl;
                cout << "Documento: " << p.cpf << endl;
                cout << "==================" << endl;
            }
            
            break;
        default:
            cout << "Codigo inválido." << endl;
            break;
        }
    }
    

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
void CSVcreator(string fPath, string nome, string cpf) {
    fstream arq;
    arq.open(fPath, ios::out | ios::app);
    //Gravando as informações no arquivo
    arq << nome << ", ";
    arq << cpf << ", ";
}

void CSVtoFila(string fPath, Fila* f)
{
    vector<string> lineVector;
    ifstream data(fPath);
    string line;
    bool deuCerto;
    while (getline(data, line))
    {
        lineVector.clear();
        stringstream lineStream(line);
        string celula;
        while (getline(lineStream, celula, ','))
        {
            //Aqui, temos uma celula na mão!!
            lineVector.push_back(celula);
        }
        //Criando um objeto Pessoa com as informações desta linha
        Pessoa p;
        p.nome = lineVector[0];
        p.cpf = lineVector[1];
        f->Insere(f, p, &deuCerto);
    }
}