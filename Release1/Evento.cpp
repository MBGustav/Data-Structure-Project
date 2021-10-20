#include <string>
using namespace std;
typedef struct Evento
{
    char nomeEvento[128];
    char descritivo[128]; //comparecido à Palestra; concluído o Curso/Treinamento; etc
    int cargaHoraria;
    char assinaturaPath[128]; //Caminho para a imagem da assinatura
    char responsavel[128]; //Nome do diretor, coordenador, etc., que está assinando o certificado
    char cargo[128]; //Cargo do responsável (diretor, coordenador, etc.)
}Evento;
