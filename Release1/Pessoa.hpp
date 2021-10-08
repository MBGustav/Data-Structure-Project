#ifndef Pessoa_hpp
#define Pessoa_hpp

#include <string>
using std::string;
#include <iostream>
using std::cout; 
using std::endl; 


class Pessoa{
public:
//Constructor & Desctructor
	Pessoa(string nome, string nDocumento);
	~Pessoa();

//Get and Set
	string getNome();
	string getDocumento();
	//int getPresenca();
	double getNota();

	//void setPresenca(int presenca);
	void setNota(int pos, double nota);


private:
	string nome;
	string nDocumento;
	double notaQuest;
    
};
#endif /* Pessoa_hpp */