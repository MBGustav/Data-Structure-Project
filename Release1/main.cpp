#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include "Fila.hpp"
#include "geradorPDF.cpp"
#include "Evento.cpp"
//Incluir pessoa_hpp

using namespace std;

void novoCadastro(string* nome, string* cpf);
void CSVcreator(string fPath, string nome, string cpf);
void CSVtoFila(string fPath, Fila* f);
void cria_info_dat();

int main(){
    //Interface principal
    //Decl. Globais
    bool deuCerto = true;
    int controle = 0;
    Pessoa p;
    //Parâmetros da pessoa
    string nome, cpf;
    //Parâmetros do evento
    string nEvento, tEvento, assinaturaPath, nResponsavel, cargoResponsavel;
    int cargaHoraria;
    Fila* fPessoas = new Fila();
    bool temArquivo = true;
    
    //Criando "info.dat"
    cria_info_dat();

    //Carregando as informações do "info.dat"
    vector<string> info_dat_vector;
    fstream info_dat;
    info_dat.open("./resources/info.dat", ios::in);
    string line, cell;
    while (getline(info_dat, line)) {
        stringstream lineStream(line);
        while(getline(lineStream, cell, ',')) {
            info_dat_vector.push_back(cell);
        }
    }
    info_dat.close();

    //Atualizando parâmetros locais
    nEvento = info_dat_vector[0];

    //Seguindo para a manipulação do arquivo de participantes
    controle = 0;
    while (controle != 2)
    {
        cout << "====Emissao de certificados para o evento \"" << nEvento << "\"====" << endl;
        cout << "O que deseja fazer?" << endl;
        cout << "1. Inserir um participante na lista" << endl;
        cout << "2. Continuar para a emissão de certificados" << endl;
        //Implementar dps uma opção p/carregar o data.csv de outro local...
        
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
                geraCertificado2(p.nome, nEvento);
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

void cria_info_dat() {
    string nEvento, tEvento, cargaHoraria, assinaturaPath, nResponsavel, cargoResponsavel;
    fstream info_dat;
    info_dat.open("./resources/info.dat", ios::out | ios::trunc);
    //Lendo as informações necessárias
    cout << "Configurando um novo evento" << endl;
    cout << "Digite o nome do evento: ";
    getline(cin, nEvento);
    info_dat << nEvento << ",";
    cout << "Digite o tipo do evento (curso, palestra, etc.): ";
    getline(cin, tEvento);
    info_dat << tEvento << ",";
    cout << "Digite a carga horaria do evento: ";
    getline(cin, cargaHoraria);
    info_dat << cargaHoraria << ",";
    cout << "Digite o caminho da assinatura: ";
    getline(cin, assinaturaPath);
    info_dat << assinaturaPath << ",";
    cout << "Digite o nome do responsavel: ";
    getline(cin, nResponsavel);
    info_dat << nResponsavel << ",";
    cout << "Digite o cargo do responsavel: ";
    getline(cin, cargoResponsavel);
    info_dat << cargoResponsavel << ",";
    info_dat.close();
}