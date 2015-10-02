/* 
 * File:   main.cpp
 * Author: jefersonlocal
 *
 * Created on September 25, 2015, 8:00 AM
 */
#include <cstdlib>
#include "iup/iup.h"
#include "iup/iupgl.h"
#include "Window.h"



int main( int argc, char **argv )
{
    //Inicializa IUP.
    IupOpen( &argc, &argv );

    //Abre o canvas OpenGL.
    IupGLCanvasOpen( );

    //Instancia a janela.
    Window *window = new Window( );

    //Exibe a Janela.
    window->show( );

    IupMainLoop( );
    delete window;
    IupClose( );
    return EXIT_SUCCESS;
}