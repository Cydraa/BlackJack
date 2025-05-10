#pragma once

#include "raylib.h"
#include "Titulo.hpp"

#define VENTANA_ANCHO 1200
#define VENTANA_ALTO 800

struct Boton
{
	Vector2 pos;
	char* texto;
	int tamTexto;
	Color colorTexto;
	Color colorBoton;

	Boton();

};

void DibujarBoton(Boton boton);

void RenderTitulo(short opciones);
void RenderJuego();
void RenderInstrucciones();
void RenderCreditos();
