#include "Titulo.hpp"

extern bool exitWindowRequested;
extern int selectionPause;

void IniciarTitulo(gameData &gD, Pantalla & pantallaActual)
{

		if (IsKeyPressed(KEY_DOWN))
		{
			if (gD.selection < 3) ++gD.selection;
			else gD.selection = 3;
		}

		if (IsKeyPressed(KEY_UP))
		{
			if (gD.selection > 0) --gD.selection;
			else gD.selection = 0;
		}

		switch (gD.selection)
		{
		case JUEGO: if (IsKeyPressed(KEY_ENTER)) pantallaActual = RESET; break;
		case REGLAS: if (IsKeyPressed(KEY_ENTER)) pantallaActual = REGLAS; break;
		case CREDITOS: if (IsKeyPressed(KEY_ENTER)) pantallaActual = CREDITOS; break;
		case SALIR: if (IsKeyPressed(KEY_ENTER)) gD.exitWindowRequested = true; break;
		}

}