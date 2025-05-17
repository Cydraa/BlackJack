#pragma once

/** @file
*/

#include "Core.hpp"
#include "JuegoBJ.hpp"

/**
* \brief Contiene la informacion para generar un boton con texto.
*/
struct Boton
{
	Vector2 pos; /**Posicion x,yen pixeles*/
	char* texto; /**Texto*/
	int tamTexto; /**Tama&nacute;o del texto*/
	Color colorTexto; /**colorTexto*/
	Color colorBoton; /**colorBoton*/
	int width; /**Ancho*/
	int height; /**Alto*/

	/**
	* \brief Constructor del boton.
	*/
	Boton();

};

/**
* \brief Contiene la informacion para generar una notificacion con texto.
*/
struct Notificacion
{
	Vector2 pos; /**Posicion x,y en pixeles*/
	char* titulo; /**Titulo*/
	char* texto; /**Texto*/
	int tamTitulo; /**Tama&nacute;o del titulo*/
	int tamTexto; /**Tama& nacute; o del texto*/
	Color colorTitulo; /**Color del titulo*/
	Color colorTexto; /**Color del texto*/
	Color colorFondo; /**Color del fondo*/
	int width; /**Ancho*/
	int height; /**Alto*/

	/**
	* \brief Constructor de la notificacion.
	*/
	Notificacion();
};

/**
* \brief Dibuja un boton de la interfaz.
* \param Boton Estructura de boton.
*/
void DibujarBoton(Boton boton);

/**
* \brief Dibuja una notificacion.
* \param Boton Estructura de notificacion.
*/
void DibujarNotificacion(Notificacion notif);

/**
* \brief Maneja toda la interfaz grafica de la pantalla del titulo.
* \param gD Estructura de datos del juego.
*/
void RenderTitulo(gameData &gD);

/**
* \brief Maneja toda la interfaz grafica de la pantalla del juego.
* \param cardTextures Arreglo de texturas.
* \param gD Estructura de datos del juego.
* \param deck Arreglo de cartas.
*/
void RenderJuego(Texture2D cardTextures[], gameData &gD, carta deck[]);

/**
* \brief Maneja toda la interfaz grafica de la pantalla de reglas.
* \param gD Estructura de datos del juego
* \param textures Arreglo de las texturas de cartas.
*/
void RenderReglas(gameData& gD, Texture2D textures[]);

/**
* \brief Maneja toda la interfaz grafica de la pantalla de creditos.
* \param gD Estructura de datos del juego.
*/
void RenderCreditos(gameData& gD, Texture2D logo);

/**
* \brief Maneja toda la interfaz grafica de la pantalla de pausa.
* \param gD Estructura de datos del juego.
*/
void RenderPausa(gameData &gD);

/**
* \brief Maneja toda la interfaz grafica de la pantalla del final del juego.
* \param cardTextures Arreglo de texturas.
* \param gD Estructura de datos del juego.
* \param deck Arreglo de cartas.
*/
void RenderPlayAgain(Texture2D cardTextures[], gameData &gD, carta deck[]);

/**
* \brief Maneja toda la interfaz grafica de la pantalla de cuando se elije una carta.
* \param cardTextures Arreglo de texturas.
* \param gD Estructura de datos del juego.
* \param deck Arreglo de cartas.
*/
void RenderPickCard(Texture2D cardTextures[], gameData& gD, carta deck[]);
