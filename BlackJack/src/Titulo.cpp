#include "Titulo.hpp"

extern bool exitWindowRequested;
extern int seleccionPausa;

void IniciarTitulo(gameData &gD, Pantalla & pantallaActual)
{

		if (IsKeyPressed(KEY_DOWN))
		{
			if (gD.seleccion < 4) ++gD.seleccion;
			else gD.seleccion = 4;
		}

		if (IsKeyPressed(KEY_UP))
		{
			if (gD.seleccion > 0) --gD.seleccion;
			else gD.seleccion = 0;
		}

		switch (gD.seleccion)
		{
		case JUEGO: if (IsKeyPressed(KEY_ENTER)) pantallaActual = JUEGO; break;
		case REGLAS: if (IsKeyPressed(KEY_ENTER)) pantallaActual = REGLAS; break;
		case CREDITOS: if (IsKeyPressed(KEY_ENTER)) pantallaActual = CREDITOS; break;
		case SALIR: if (IsKeyPressed(KEY_ENTER)) gD.exitWindowRequested = true; break;
		}

}