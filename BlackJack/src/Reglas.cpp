#include "Reglas.hpp"

void IniciarReglas(short& seleccion, Pantalla& pantallaActual)
{

	if (exitWindowRequested == false)
	{
		if (IsKeyPressed(KEY_ENTER)) pantallaActual = TITULO;
	}
	else
	{
		PauseGame();
	}

}