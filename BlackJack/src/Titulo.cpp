#include "Titulo.hpp"

void IniciarTitulo(short &seleccion, Pantalla & pantallaActual)
{
	if (IsKeyPressed(KEY_DOWN))
	{
		if (seleccion < 4) ++seleccion;
		else seleccion = 4;
	}

	if (IsKeyPressed(KEY_UP))
	{
		if (seleccion > 0) --seleccion;
		else seleccion = 0;
	}

	switch (seleccion)
	{
	case JUEGO: if (IsKeyPressed(KEY_ENTER)) pantallaActual = JUEGO; break;
	case REGLAS: if (IsKeyPressed(KEY_ENTER)) pantallaActual = REGLAS; break;
	case CREDITOS: if (IsKeyPressed(KEY_ENTER)) pantallaActual = CREDITOS; break;
	}

}