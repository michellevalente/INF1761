/* 
 * File:   Window.cpp
 * Author: jefersonlocal
 * 
 * Created on September 25, 2015, 8:01 AM
 */

#include <iup/iup.h>
#include <iup/iupgl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include "Window.h"



Window::Window( )
{
    //Cria janela.
    createWindow( );
}

void Window::createWindow( )
{
    //Cria canvas.
    Ihandle* canvas = IupGLCanvas( NULL );
 
    //Cria uma box.
    Ihandle* vbox = IupVbox( canvas, NULL );

    //Cria o dialoo.
    _dialog = IupDialog( vbox );

    //Define atributos do dialogo.
    IupSetAttribute( _dialog, IUP_RASTERSIZE, "500x500" );
    IupSetAttribute( canvas, IUP_BUFFER, IUP_DOUBLE_BUFFER );
    IupSetAttribute( _dialog, "THIS", ( char* ) this );

    //Define callbacks do canvas.
    IupSetCallback( canvas, IUP_ACTION, ( Icallback ) canvasAction );
    IupSetCallback( canvas, "RESIZE_CB", ( Icallback ) canvasResize );

}



int Window::canvasAction( Ihandle* canvas )
{
    //Define o canvas como corrente.
    IupGLMakeCurrent( canvas );

    //Obtem um ponteiro par ao objeto.
    Window *house = ( Window* ) IupGetAttribute( canvas, "THIS" );

    //Passa para o objeto a responsabilidade de trtatar o evendo.
    house->renderScene( );

    //descarrega na tela os comandos executados
    IupGLSwapBuffers( canvas );

    return IUP_DEFAULT;
}



void Window::renderScene( )
{
    //define que a cor para limpar a janela eh branca
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );

    //Limpa a janela com a cor pre-determinada
    glClear( GL_COLOR_BUFFER_BIT );

    //define a cor da casa
    glColor3f( 1.0f, 0.5f, 0.0f );

    //desenha casa
    glBegin( GL_QUADS );
    glVertex2f( -2.0f, -2.0f );
    glVertex2f( -2.0f, 2.0f );
    glVertex2f( 2.0f, 2.0f );
    glVertex2f( 2.0f, -2.0f );
    glEnd( );
}


int Window::canvasResize( Ihandle* canvas, int w, int h )
{
    //Define o canvas como corrente.
    IupGLMakeCurrent( canvas );

    //Obtem um ponteiro par ao objeto.
    Window *window = ( Window* ) IupGetAttribute( canvas, "THIS" );

    //Passa para o objeto a responsabilidade de trtatar o evendo.
    window->resize( w, h );

    //descarrega na tela os comandos executados
    IupUpdate( canvas );
}




int Window::button( Ihandle* ih, int button, int pressed, int x, int y, char* status )
{

}



void Window::resize( int w, int h )
{
    //Define que toda a janela sera usada para desenho. Isso eh feito atras da
    //definicao do viewport, que recebe o ponto inferior esquerdo, a largura e
    //a altura da janela.
    glViewport( 0, 0, w, h );

    //Define a matriz de projecao como matriz corrente. Essa matriz guarda informacoes
    //de como o desenho deve ser projetado na tela, desta forma qualquer definicao
    //relativa a sistema de coordenadas deve ser feita na matriz de projecao
    glMatrixMode( GL_PROJECTION );

    //Carrega a matriz indentida na matriz corrente. Esta operacao substitui a matriz
    //corrente pela matriz identidade
    glLoadIdentity( );

    //Define como o sistema de coordenadas varia dentro do viewport, ou seja,
    //da esquerda para direita o eixo x varia de x1 ate x2 e o eixo y varia de
    //y1 ate y2. Note que nao necessariamente x1 <= x2 ou y1 <= y2
    gluPerspective( 65, (float)w/h, 1, 1000);    

}



void Window::show( )
{
    IupShow( _dialog );
}



Window::~Window( )
{
}

