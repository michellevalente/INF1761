/* 
 * File:   Window.h
 * Author: jefersonlocal
 *
 * Created on September 25, 2015, 8:01 AM
 */

#ifndef WINDOW_H
#define	WINDOW_H



class Window
{
public:
    /**
     * Construtor default.
     */
    Window( );

    /**
     * Destrutor.
     */
    virtual ~Window( );

    /**
     * Funcao para mostrar a janela.
     */
    void show( );
private:
    /**
     * Funcao para criar janela.
     */
    void createWindow( );

    /**
     * Metodo do objeto para tratar redesenho.
     */
    void renderScene( );

    /**
     * Metodo do objeto para tratar resize.
     * @param w - nova largura do canvas.
     * @param h - nova altura do canvas.
     */
    void resize( int w, int h );

private:
    /**
     * Callback de redesenho do canvas.
     * @param canvas - ponteiro para o canvas.
     * @return - IUP_DEFAULT.
     */
    static int canvasAction( Ihandle* canvas );

    /**
     * Callback de resize do canvas.
     * @param canvas - ponteiro para o canvas.
     * @param w - nova largura do canvas.
     * @param h - nova altura do canvas.
     * @return - IUP_DEFAULT.
     */
    static int canvasResize( Ihandle* canvas, int w, int h );
    
    static int motion( Ihandle* canvas, int x, int y, char * status );
    static int button(Ihandle* ih, int button, int pressed, int x, int y, char* status);

private:

    /**
     * Dialogo.
     */
    Ihandle* _dialog;

    /**
     * define o sistema de coordenadas variando de (x1, y1) ate (x2, y2)
     */
    float xx1, yy1, xx2, yy2;

    /**
     * coordenadas dos pontos que geram o desenho
     */
    float p1x, p1y, p2x, p2y, p3x, p3y;
    float p4x, p4y, p5x, p5y, p6x, p6y;
    float p7x, p7y, p8x, p8y, p9x, p9y;
    float p10x, p10y, p11x, p11y, p12x, p12y;
    float p13x, p13y, p14x, p14y, p15x, p15y;
    float p16x, p16y;
    float angle; 

    /**
     * coordenadas da AABB (align axis bounding box), ou seja, retangulo que contem
     * todos os pontos alinhado com os eixos. Basicamente (xmin, ymin) e (xmax, ymax)
     */
    float xMin, xMax, yMin, yMax;
};

#endif	/* WINDOW_H */
