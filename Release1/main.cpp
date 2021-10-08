#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void novoRegistro();

int main(){
    //Interface principal
    cout << "O que deseja fazer?" << endl;
    cout << "1. Realizar a leitura de presença (criar um novo .csv)" << endl;
    cout << "2. Carregar um arquivo .csv existente" << endl;
    

    return 0;

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
            //Aqui, temos uma celula na mão!!
        }
        
    }
    

}