//
//  Fila.cpp
//  F3_Fila
//
//  Created by Eduardo Bouhid Neto on 01/09/21.
//

#include "Fila.hpp"

Fila::Fila()
{
    //Criando a fila vazia
    this->ultimo = NULL;
}

Fila::~Fila(){delete ultimo;}

bool Fila::Vazia()
{
    if (this->ultimo == NULL) {
            return true;
        } else {
            return false;
        }
}

bool Fila::Cheia()
{
    //Conforme o Capítulo 4 do livro-texto, esta operação retornará "false" sempre
    return false;
}

void Fila::Insere(Fila* f, char x, bool* deuCerto)
{
    if (f->Vazia()) {
        Node* novoNode = new Node;
        novoNode->info = x;
        f->ultimo = novoNode;
        f->ultimo->next = f->ultimo;
        *deuCerto = true;
    } else if (!f->Cheia()) {
        Node* novoNode = new Node;
        novoNode->info = x;
        novoNode->next = f->ultimo->next;
        f->ultimo->next = novoNode;
        f->ultimo = novoNode;
        *deuCerto = true;
    }
    else{
        *deuCerto = false;
    }
}
void Fila::Retira(Fila* f, char* x, bool* deuCerto)
{
    if (f->Vazia()) {
        *deuCerto = false;
    } else if (!(f->ultimo->next == f->ultimo)){
        *x = f->ultimo->next->info;
        Node* nAux = f->ultimo->next->next; //Prox. node do "inicio"
        delete f->ultimo->next;
        f->ultimo->next = nAux;
        *deuCerto = true;
    } else {
        *x = f->ultimo->info;
        f->ultimo = NULL;
        *deuCerto = true;
    }
}
