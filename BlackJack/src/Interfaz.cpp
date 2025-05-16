#include "Interfaz.hpp"

Boton::Boton()
{
	pos.x = 0;
	pos.y = 0;
	texto = "Boton";
	tamTexto = 20;
	colorTexto = RAYWHITE;
	colorBoton = BLACK;
	width = MeasureText(texto, tamTexto) + 20;
	height = tamTexto + 20;
};

void DibujarBoton(Boton boton)
{
	int offSetX = 10;
	int offSetY = 10;

	DrawRectangle(boton.pos.x, boton.pos.y, boton.width, boton.height, boton.colorBoton);
	DrawText(boton.texto, boton.pos.x + offSetX, boton.pos.y + offSetY, boton.tamTexto, boton.colorTexto);
}

void RenderTitulo(short seleccion)
{
	Boton botonesMenu[MENU_MAX];
	char* menu[MENU_MAX] = { "Jugar","Reglas","Creditos","Salir" };
	int longitudTexto;
	const char* titulo = { "BLACKJACK" };

	ClearBackground(DARKGREEN);

	longitudTexto = MeasureText(titulo, 80) ;
	DrawText(titulo, VENTANA_ANCHO/2 - longitudTexto/2 , 100, 80, RAYWHITE);


	for (int i = 0; i < MENU_MAX; ++i)
	{
		botonesMenu[i].tamTexto = 60;
		longitudTexto = MeasureText(menu[i], botonesMenu[i].tamTexto);
		botonesMenu[i].texto = menu[i];
		botonesMenu[i].width = longitudTexto + 20;
		botonesMenu[i].height = botonesMenu[i].tamTexto + 20;
		botonesMenu[i].pos.x = VENTANA_ANCHO / 2 - botonesMenu[i].width/2;
		botonesMenu[i].pos.y = 180 + 90 * (i + 1);


		if (seleccion == i) botonesMenu[i].colorBoton = RED;

		DibujarBoton(botonesMenu[i]);
	}

}

void DibujarNotificacion(char* titulo, char* texto)
{
	int height = 200;
	int longitudTexto = MeasureText(titulo, 50);
	DrawRectangle(0, VENTANA_ALTO / 2 - height/2, VENTANA_ANCHO, height, Color{ 0, 0, 0, 235 });
	DrawText(titulo, VENTANA_ANCHO / 2 - longitudTexto / 2, (VENTANA_ALTO / 2 - height / 2)+20, 50, RAYWHITE);
	longitudTexto = MeasureText(texto, 30);
	DrawText(texto, VENTANA_ANCHO / 2 - longitudTexto / 2, (VENTANA_ALTO / 2 - height / 2) + 70, 30, RAYWHITE);
}

//WIP
void RenderJuego()
{

	int longitudTexto;
	const char* titulo = { "Juego" };

	ClearBackground(DARKBLUE);

	longitudTexto = MeasureText(titulo, 80);
	DrawText(titulo, VENTANA_ANCHO / 2 - longitudTexto / 2, 100, 80, RAYWHITE);


}

//WIP
void RenderReglas()
{
	int longitudTexto;
	const char* titulo = { "Reglas" };

	ClearBackground(DARKPURPLE);

	longitudTexto = MeasureText(titulo, 80);
	DrawText(titulo, VENTANA_ANCHO / 2 - longitudTexto / 2, 100, 80, RAYWHITE);

	longitudTexto = MeasureText("PRUEBA: Presiona ENTER para regresar", 40);
	DrawText("PRUEBA: Presiona ENTER para regresar", VENTANA_ANCHO / 2 - longitudTexto / 2, 200, 40, BEIGE);
}

//WIP
void RenderCreditos()
{
	int longitudTexto;
	const char* titulo = { "Creditos" };

	ClearBackground(DARKBROWN);

	longitudTexto = MeasureText(titulo, 80);
	DrawText(titulo, VENTANA_ANCHO / 2 - longitudTexto / 2, 100, 80, RAYWHITE);

}