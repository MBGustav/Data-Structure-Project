//
//  Fila.hpp
//  F3_Fila
//
//  Created by Eduardo Bouhid Neto on 01/09/21.
//

#ifndef Fila_hpp
#define Fila_hpp

#include <stdio.h>
#include <string>
#include "Pessoa.hpp"

using namespace std;

typedef struct Node
{
    Pessoa* info;
    Node* next;
}Node;

class Fila{
private:
    Node* ultimo;
    
public:
    Fila();
    ~Fila();
    bool Vazia();
    bool Cheia();
    void Insere(Fila* f, Pessoa* x, bool* deuCerto);
    void Retira(Fila* f, Pessoa** x, bool* deuCerto);

};

#endif /* Fila_hpp */
