#include <string>
using namespace std;
typedef struct Evento
{
    string nomeEvento;
    string descritivo; //comparecido à Palestra; concluído o Curso/Treinamento; etc
    int cargaHoraria;
    string assinaturaPath; //Caminho para a imagem da assinatura
    string responsavel; //Nome do diretor, coordenador, etc., que está assinando o certificado
    string cargo; //Cargo do responsável (diretor, coordenador, etc.)
}Evento;
