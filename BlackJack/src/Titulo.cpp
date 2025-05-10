#include "Titulo.hpp"

void IniciarTitulo(short &opciones)
{
	if (IsKeyPressed(KEY_DOWN))
	{
		if (opciones < 4) ++opciones;
		else opciones = 4;
	}

	if (IsKeyPressed(KEY_UP))
	{
		if (opciones > 0) --opciones;
		else opciones = 0;
	}


}