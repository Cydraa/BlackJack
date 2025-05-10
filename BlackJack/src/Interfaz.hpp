#pragma once

#include "Core.hpp"

#define VENTANA_ANCHO 1200
#define VENTANA_ALTO 800

/**
* \brief Contiene la informacion para generar un boton con texto.
*/
struct Boton
{
	Vector2 pos;
	char* texto;
	int tamTexto;
	Color colorTexto;
	Color colorBoton;

	Boton();

};

/**
* \brief Dibuja un boton de la interfaz.
* \param Boton Estructura de boton.
*/
void DibujarBoton(Boton boton);

/**
* \brief Maneja toda la interfaz grafica de la pantalla del titulo.
* \param short seleccion de usuario.
*/
void RenderTitulo(short seleccion);

void RenderJuego();
void RenderReglas();
void RenderCreditos();
