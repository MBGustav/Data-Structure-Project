
/*    Pessoa(char* nome, char* nDocumento);
 ~Pessoa();


 int getPresenca();
 double* getNotas();
 void setPresenca(int presenca);
 void setNota(int pos, double nota);
*/
#include "Pessoa.hpp"



Pessoa::Pessoa(string nome, string documento)
{
    this->nome = nome;
    this->nDocumento = documento;
    this->notaQuest = 0.0; /*Acho mais safe inicializar como 0*/
}
Pessoa::~Pessoa(){}
string Pessoa::getNome()
{
    return nome;
}
string Pessoa::getDocumento()
{
  return nDocumento;
}
double Pessoa::getNota()
{
  return notaQuest;
}
void Pessoa::setNota(int pos, double nota){
	this->notaQuest = nota;
}
