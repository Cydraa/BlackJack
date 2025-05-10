#include "Interfaz.hpp"

Boton::Boton()
{
	pos.x = 0;
	pos.y = 0;
	texto = "Boton";
	tamTexto = 20;
	colorTexto = RAYWHITE;
	colorBoton = BLACK;
};

void DibujarBoton(Boton boton)
{
	int offSetX = 10;
	int offSetY = 10;

	DrawRectangle(boton.pos.x, boton.pos.y, MeasureText(boton.texto, boton.tamTexto) + (offSetX * 2), boton.tamTexto + (offSetY * 2), boton.colorBoton);
	DrawText(boton.texto, boton.pos.x + offSetX, boton.pos.y + offSetY, boton.tamTexto, boton.colorTexto);
}

void RenderTitulo(short seleccion)
{
	Boton botonesMenu[MENU_MAX];
	char* menu[MENU_MAX] = { "Jugar","Instrucciones","Creditos","Salir" };

	const char* titulo = { "BLACKJACK" };
	ClearBackground(DARKGREEN);
	DrawText(titulo, VENTANA_ANCHO / 2 - MeasureText(titulo, 80) / 2, 100, 80, RAYWHITE);


	for (int i = 0; i < MENU_MAX; ++i)
	{
		botonesMenu[i].tamTexto = 60;
		botonesMenu[i].pos.x = VENTANA_ANCHO / 2 - (MeasureText(menu[i], botonesMenu[i].tamTexto)) / 2;
		botonesMenu[i].pos.y = 180 + 90 * (i + 1);
		botonesMenu[i].texto = menu[i];

		if (seleccion == i) botonesMenu[i].colorBoton = RED;

		DibujarBoton(botonesMenu[i]);
	}

}