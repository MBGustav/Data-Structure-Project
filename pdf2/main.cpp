/***************************************************************************
 *   Copyright (C) 2006 by Dominik Seichter                                *
 *   domseichter@web.de                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


/*
 * Include the standard headers for cout to write
 * some output to the console.
 */
#include <iostream>

#include <string>
/*
 * Now include all podofo header files, to have access
 * to all functions of podofo and so that you do not have
 * to care about the order of includes.
 *
 * You should always use podofo.h and not try to include
 * the required headers on your own.
 */
#include <podofo.h>
/*
 * All podofo classes are member of the PoDoFo namespace.
 */
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
    /*
     * PdfStreamedDocument is the class that can actually write a PDF file.
     * PdfStreamedDocument is much faster than PdfDocument, but it is only
     * suitable for creating/drawing PDF files and cannot modify existing
     * PDF documents.
     *
     * The document is written directly to pszFilename while being created.
     */
    
    std::string fName = "/Users/mengo/Desktop/" + nome + ".pdf";
    const char* fNameExt = fName.c_str();
    PdfStreamedDocument document( fNameExt );
    /*
     * This pointer will hold the page object later.
     * PdfSimpleWriter can write several PdfPage's to a PDF file.
     */
    PdfPage* pPage;
    /*
     * PdfPainter is the class which is able to draw text and graphics
     * directly on a PdfPage object.
     */
    PdfPainter painter;
    /*
     * A PdfFont object is required to draw text on a PdfPage using a PdfPainter.
     * PoDoFo will find the font using fontconfig on your system and embedd truetype
     * fonts automatically in the PDF file.
     */
    PdfFont* pFont;

    /*
     * The PdfDocument object can be used to create new PdfPage objects.
     * The PdfPage object is owned by the PdfDocument will also be deleted automatically
     * by the PdfDocument object.
     *
     * You have to pass only one argument, i.e. the page size of the page to create.
     * There are predefined enums for some common page sizes.
     */
    
    //Esse tamRetrato deixa a página na orientação que queremos
    static PdfRect tamRetrato = pPage->CreateStandardPageSize(ePdfPageSize_A4, true);
    pPage = document.CreatePage(tamRetrato);

    /*
     * If the page cannot be created because of an error (e.g. ePdfError_OutOfMemory )
     * a NULL pointer is returned.
     * We check for a NULL pointer here and throw an exception using the RAISE_ERROR macro.
     * The raise error macro initializes a PdfError object with a given error code and
     * the location in the file in which the error ocurred and throws it as an exception.
     */
    if( !pPage )
    {
        PODOFO_RAISE_ERROR( ePdfError_InvalidHandle );
    }

    /*
     * Set the page as drawing target for the PdfPainter.
     * Before the painter can draw, a page has to be set first.
     */
    painter.SetPage( pPage );

    /*
     * Create a PdfFont object using the font "Arial".
     * The font is found on the system using fontconfig and embedded into the
     * PDF file. If Arial is not available, a default font will be used.
     *
     * The created PdfFont will be deleted by the PdfDocument.
     */
    pFont = document.CreateFont( "Arial" );
    
    /*
     * If the PdfFont object cannot be allocated return an error.
     */
    if( !pFont )
    {
        PODOFO_RAISE_ERROR( ePdfError_InvalidHandle );
    }

    pFont->SetFontSize( 18.0 );

    painter.SetFont( pFont );

    /*
     
     Escrevendo no PDF
     Essa lib não permite escolher o alinhamento do texto, e acho que também não tem quebra de linha
     automática. Por isso, precisamos colocar as posições no olhômetro mesmo.
     Tomei por guia aquele documento "grid_sheet.pdf"
     
     Nota mental: Agora, falta implementar a manipulação de imagens. Pensei em fazer os certificados assim:
     Uma imagem de fundo padrão com os campos para preencher com o nome do participante, nome do evento e
     a(s) assinatura(s) do(s) organizador(es).
     
     */
    
    std::string msgInicial = "Concedemos este certificado a";
    const char* msgInicial_c = msgInicial.c_str();
    painter.DrawText( 56.69, pPage->GetPageSize().GetHeight() - 56.69, msgInicial_c );
    

    painter.DrawText( 150.00, (pPage->GetPageSize().GetHeight())/2, nome.c_str() );
    
    std::string msgFinal = "Por ter comparecido ao evento " + evento;
    const char* msgFinal_c = msgFinal.c_str();
    painter.DrawText( 56.69, 56.69, msgFinal_c );

    //Carregando a imagem
    PdfImage logo(&document);
    logo.LoadFromFile("/Users/mengo/Desktop/testePDF2/pdf2/pdf2/medal.png");
    painter.DrawImage(pPage->GetPageSize().GetWidth() - 120.69, pPage->GetPageSize().GetHeight() - 80.69, &logo);
    
    //Encerrando a Manipulação
    painter.FinishPage();

    /*
     * Set some additional information on the PDF file.
     */
    document.GetInfo()->SetCreator ( PdfString("PoDoFo PDF") );
    document.GetInfo()->SetAuthor  ( PdfString(evento) );
    document.GetInfo()->SetTitle   ( PdfString("Certificado do evento" + evento) );
    document.GetInfo()->SetSubject ( PdfString("") );
    document.GetInfo()->SetKeywords( PdfString("") );

    /*
     * The last step is to close the document.
     */
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

int main( int argc, char* argv[] )
{
    /*
     * Check if a filename was passed as commandline argument.
     * If more than 1 argument or no argument is passed,
     * a help message is displayed and the example application
     * will quit.
     */
    
    std::string pessoa;
    std::string evento;
    std::cout << "Digite o nome da pessoa: ";
    std::getline(std::cin, pessoa);
    std::cout << "Digite o nome do evento: ";
    std::getline(std::cin, evento);
    
    

    /*
     * All podofo functions will throw an exception in case of an error.
     *
     * You should catch the exception to either fix it or report
     * back to the user.
     *
     * All exceptions podofo throws are objects of the class PdfError.
     * Thats why we simply catch PdfError objects.
     */
    try {
        /*
         * Call the drawing routing which will create a PDF file
         * with the filename of the output file as argument.
         */
         geraCertificado( pessoa, evento );
    } catch( const PdfError & eCode ) {
        /*
         * We have to check if an error has occurred.
         * If yes, we return and print an error message
         * to the commandline.
         */
        eCode.PrintErrorMsg();
        return eCode.GetError();
    }

    /*
     * The PDF was created sucessfully.
     */
    std::cout << std::endl
              << "PDF criado com sucesso, cria."  << std::endl << std::endl;
    
    return 0;
}

