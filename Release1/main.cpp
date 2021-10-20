#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include "Fila.hpp"
#include "geradorPDF.cpp"
#include "Evento.cpp"

using namespace std;

void novoCadastro(string* nome, string* cpf);
void CSVcreator(string fPath, string nome, string cpf);
void CSVtoFila(string fPath, Fila* f);

int main(){
    //Interface principal
    //Decl. Globais
    bool deuCerto = true;
    int controle = 0;
    Pessoa p;
    string nome, cpf, nomeEvento;
    Fila* fPessoas = new Fila();
    bool temArquivo = true;

    //Buscando o arquivo info.dat
    streampos pos;
    ifstream infile;
    infile.open("info.dat", ios::binary | ios::in);
    if (!infile) {
        temArquivo = false;
    } else {
        //Puxar o nome do evento
        infile.seekg(0, ios::beg);
        char bufferEvento[sizeof(Evento)];
        infile.read(bufferEvento, sizeof(Evento));
        Evento eventoTemp = *reinterpret_cast<Evento*>(bufferEvento);
        nomeEvento = eventoTemp.nomeEvento;
    }
    if (temArquivo) {
        //Perguntar se deseja criar outro evento
        cout << "Arquivo \"info.dat\" correspondente ao evento " << nomeEvento << " encontrado!\nDeseja criar outro evento?: " << endl;
        cout << "1. Utilizar o  \"info.dat\" atual" << endl;
        cout << "2. Criar outro evento" << endl;
        cin >> controle;
        while (controle != 1 && controle != 2)
        {
            switch (controle)
            {
            case 1:
                //Nada a ser feito
                break;
            
            case 2:
                //Criando outro "info.dat"

                break;
            }
        }
    }

    controle = 0;
    while (controle != 2)
    {
        cout << "O que deseja fazer?" << endl;
        cout << "1. Inserir um participante na lista" << endl;
        cout << "2. Continuar para a emissão de certificados" << endl;
        cin >> controle;
        switch (controle)
        {
        case 1:
            cin.ignore(64, '\n');
            novoCadastro(&nome, &cpf);
            CSVcreator("data.csv", nome, cpf);
            break;
        
        case 2:
            cout << "Passando para a emissão dos certificados..." << endl;
            CSVtoFila("data.csv", fPessoas);
            cout << "Testando a inserção na fila..." << endl;
            fPessoas->Retira(fPessoas, &p, &deuCerto);
            while (deuCerto)
            {
                cout << "Nome: " << p.nome << endl;
                cout << "Documento: " << p.cpf << endl;
                cout << "==================" << endl;
                geraCertificado2(p.nome, nomeEvento);
                fPessoas->Retira(fPessoas, &p, &deuCerto);
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
    arq << cpf << "\n";
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