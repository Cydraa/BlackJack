#include "FuncionesAuxiliares.hpp"

void DibujarBoton(const char* texto, int tamanoTexto, Color colorTexto, Vector2 posicion, Color colorBoton)
{
	int offSetX = 10;
	int offSetY = 10;

	DrawRectangle(posicion.x, posicion.y, MeasureText(texto, tamanoTexto) + (offSetX * 2), tamanoTexto + (offSetY * 2), colorBoton);
	DrawText(texto, posicion.x + offSetX, posicion.y + offSetY, tamanoTexto, colorTexto);
}