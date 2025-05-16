#pragma once

#include "Core.hpp"
#include "JuegoBJ.hpp"

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
	int width;
	int height;

	Boton();

};

struct Notificacion
{
	Vector2 pos;
	char* titulo;
	char* texto;
	int tamTitulo;
	int tamTexto;
	Color colorTitulo;
	Color colorTexto;
	Color colorFondo;
	int width;
	int height;

	Notificacion();
};

/**
* \brief Dibuja un boton de la interfaz.
* \param Boton Estructura de boton.
*/
void DibujarBoton(Boton boton);

void DibujarNotificacion(Notificacion notif);

/**
* \brief Maneja toda la interfaz grafica de la pantalla del titulo.
* \param short seleccion de usuario.
*/
void RenderTitulo(gameData &gD);

void RenderJuego(Texture2D cardTextures[], gameData &gD, carta deck[]);
void RenderReglas(gameData &gD);
void RenderCreditos(gameData &gD);
void RenderPausa(gameData &gD);
