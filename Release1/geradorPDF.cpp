
#include <iostream>
#include <string>
#include <podofo.h>

using namespace PoDoFo;

void PrintHelp()
{
    std::cout << "This is a example application for the PoDoFo PDF library." << std::endl
              << "It creates a small PDF file containing the text >Hello World!<" << std::endl
              << "Please see http://podofo.sf.net for more information" << std::endl << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << "  examplehelloworld [outputfile.pdf]" << std::endl << std::endl;
}

void geraCertificado( std::string nome, std::string evento )
{   
    std::string fName = "/Users/mengo/Desktop/" + nome + ".pdf";
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
    
    std::string msgInicial = "Concedemos este certificado a";
    const char* msgInicial_c = msgInicial.c_str();
    painter.DrawText( 56.69, pPage->GetPageSize().GetHeight() - 56.69, msgInicial_c );
    

    painter.DrawText( 150.00, (pPage->GetPageSize().GetHeight())/2, nome.c_str() );
    
    std::string msgFinal = "Por ter comparecido ao evento " + evento;
    const char* msgFinal_c = msgFinal.c_str();
    painter.DrawText( 56.69, 56.69, msgFinal_c );

    //Carregando a imagem
    PdfImage logo(&document);
    logo.LoadFromFile("/Users/mengo/Documents/UFSCar/2021_1/AED1/Data-Structure-Project/pdf2/medal.png");
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

void geraCertificado2(std::string nome,std::string evento)
{
    //Definindo o nome do arquivo final (nome do participante)
    std::string fName = "/Users/mengo/Desktop/" + nome + ".pdf";
    const char* fNameExt = fName.c_str();
    /*Carregando o pdf existente (modelo a ser preenchido), bem
     como sua única página*/
    PdfMemDocument pdfExistente("/Users/mengo/Desktop/grid_sheet.pdf");
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
    pFont->SetFontSize(18.0);
    painter.SetFont(pFont);
    //painter.SetColor(63.0, 0, 0 ); //Vermelhinho pra aparecer mais
    
    /*Agora sim, escrevemos o que quisermos*/
    std::string msgInicial = "Concedemos este certificado a";
    const char* msgInicial_c = msgInicial.c_str();
    painter.DrawText( 56.69, pPage->GetPageSize().GetHeight() - 56.69, msgInicial_c );
    

    painter.DrawText( 150.00, (pPage->GetPageSize().GetHeight())/2, nome.c_str() );
    
    std::string msgFinal = "Por ter comparecido ao evento " + evento;
    const char* msgFinal_c = msgFinal.c_str();
    painter.DrawText( 56.69, 56.69, msgFinal_c );
    
    //Encerrando a manipulação da página
    painter.FinishPage();
    
    //Gravando o documento (PdfMemDocument) no disco
    pdfExistente.Write(fNameExt);
}

// int main( int argc, char* argv[] )
// {
    
//     std::string pessoa;
//     std::string evento;
//     std::cout << "Digite o nome da pessoa: ";
//     std::getline(std::cin, pessoa);
//     std::cout << "Digite o nome do evento: ";
//     std::getline(std::cin, evento);
    
//     try {
//          geraCertificado( pessoa, evento );
//     } catch( const PdfError & eCode ) {
//         eCode.PrintErrorMsg();
//         return eCode.GetError();
//     }

//     std::cout << std::endl
//               << "PDF criado com sucesso, cria."  << std::endl << std::endl;
    
//     return 0;
// }

