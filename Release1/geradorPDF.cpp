
#include <iostream>
#include <string>
#include <podofo.h>
#include "Evento.h"
using namespace PoDoFo;
/*
 * PLEASE UPDATE THE FOLLOWING PARAMETERS BEFORE PROCEEDING
 */

std::string outputLoc = "./PDFoutput/";
//std::string imagePath = "./resources/medal.png";
//const char* imageSrc = imagePath.c_str();

/* modelPdf: Set the variable in case you want to generate the certificate by modifying an existing PDF file (such as a form)
 * and use the "geraCertificado2" function when iterating through a "Fila". We'll probably use these only on later versions
 */
std::string modelPdf = "./resources/templateCertificado.pdf";
const char* modelPdfSrc = modelPdf.c_str();

/*
void geraCertificado(std::string nome, Evento evento)
{   
    std::string fName = outputLoc + nome + ".pdf";
    const char* fNameExt = fName.c_str();
    PdfStreamedDocument document( fNameExt );
    PdfPage* pPage;
    PdfPainter painter;
    PdfFont* pFont;
    //Esse tamRetrato deixa a página na orientação que queremos
    static PdfRect tamRetrato = pPage->CreateStandardPageSize(ePdfPageSize_A4, true);
    pPage = document.CreatePage(tamRetrato);

    if( !pPage )
    {
        PODOFO_RAISE_ERROR( ePdfError_InvalidHandle );
    }

    painter.SetPage( pPage );

    pFont = document.CreateFont( "Arial" );

    if( !pFont )
    {
        PODOFO_RAISE_ERROR( ePdfError_InvalidHandle );
    }

    pFont->SetFontSize( 18.0 );

    painter.SetFont( pFont );

    painter.DrawText( 56.69, (pPage->GetPageSize().GetHeight())/2, nome.c_str() );
    
    std::string msgFinal = "Por ter comparecido ao evento " + evento;
    const char* msgFinal_c = msgFinal.c_str();
    painter.DrawText( 56.69, 56.69, msgFinal_c );

    //Carregando a imagem
    PdfImage logo(&document);
    logo.LoadFromFile(imageSrc);
    painter.DrawImage(pPage->GetPageSize().GetWidth() - 120.69, pPage->GetPageSize().GetHeight() - 80.69, &logo);
    
    //Encerrando a Manipulação
    painter.FinishPage();

    //Metadados
    document.GetInfo()->SetCreator ( PdfString("PoDoFo PDF") );
    document.GetInfo()->SetAuthor  ( PdfString(evento) );
    document.GetInfo()->SetTitle   ( PdfString("Certificado do evento" + evento) );
    document.GetInfo()->SetSubject ( PdfString("") );
    document.GetInfo()->SetKeywords( PdfString("") );

    //Fechando o documento
    document.Close();
}
*/

void geraCertificado2(std::string nome, Evento e)
{
    //Definindo o nome do arquivo final (nome do participante)
    std::string fName = outputLoc + nome + ".pdf";
    const char* fNameExt = fName.c_str();
    /*Carregando o pdf existente (modelo a ser preenchido), bem
     como sua única página*/
    PdfMemDocument pdfExistente(modelPdfSrc);
    PdfPage* pPage = pdfExistente.GetPage(0);
    if( !pPage )
    {
        PODOFO_RAISE_ERROR( ePdfError_InvalidHandle );
    }
    
    //Alguns parâmetros necessários
    PdfPainter painter;
    PdfFont* pFont;
    painter.SetPage(pPage);
    
    //Definindo a fonte
    pFont = pdfExistente.CreateFont("Arial");
    if( !pFont )
    {
        PODOFO_RAISE_ERROR( ePdfError_InvalidHandle );
    }
    pFont->SetFontSize(24.0);
    painter.SetFont(pFont);
    //painter.SetColor(63.0, 0, 0 ); //Vermelhinho pra aparecer mais
    
    //Escrevendo no certificado

    //Nome
    painter.DrawText(98, pPage->GetPageSize().GetHeight() - 223, nome.c_str() );
    
    //Por ter [...]
    painter.DrawText(155, pPage->GetPageSize().GetHeight() - 279, e.descritivo.c_str());
    
    //Evento
    painter.DrawText(98, pPage->GetPageSize().GetHeight() - 333, e.nomeEvento.c_str());

    //Carga Horária
    painter.DrawText(461, pPage->GetPageSize().GetHeight() - 395, to_string(e.cargaHoraria).c_str());

    //Logo
    PdfImage logo(&pdfExistente);
    logo.LoadFromFile((e.logoPath).c_str());
    painter.DrawImage(635, pPage->GetPageSize().GetHeight() - 103, &logo);

    //Assinatura
    PdfImage signature(&pdfExistente);
    signature.LoadFromFile((e.assinaturaPath).c_str());
    painter.DrawImage(98, pPage->GetPageSize().GetHeight() - 500, &signature);

    //Dados do responsável
    pFont->SetFontSize(16.0);
    painter.DrawText(118, pPage->GetPageSize().GetHeight() - 530, e.responsavel);
    painter.DrawText(118, pPage->GetPageSize().GetHeight() - 550, e.cargo);

    //Encerrando a manipulação da página
    painter.FinishPage();
    
    //Gravando o documento (PdfMemDocument) no disco
    pdfExistente.Write(fNameExt);
}
