#include "Interfaz.hpp"

extern int seleccionPausa;

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

Notificacion::Notificacion()
{
	titulo = "Titulo";
	texto = "Texto";
	tamTitulo = 60;
	tamTexto = 30;
	colorTitulo = RAYWHITE;
	colorTexto = RAYWHITE;
	colorFondo = Color{ 0, 0, 0, 235 };
	width = VENTANA_ANCHO;
	height = 200;
	pos.x = 0;
	pos.y = VENTANA_ALTO / 2 - height / 2;
}

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

void DibujarNotificacion(Notificacion notif)
{
	int textoX, textoY;
	int longitudTexto;

	textoY = (VENTANA_ALTO / 2 - notif.height / 2);

	DrawRectangle(notif.pos.x, notif.pos.y, notif.width, notif.height, notif.colorFondo);

	longitudTexto = MeasureText(notif.titulo, notif.tamTitulo);
	textoX = VENTANA_ANCHO / 2 - longitudTexto/2;
	DrawText(notif.titulo, textoX, textoY + 20, notif.tamTitulo, notif.colorTitulo);

	longitudTexto = MeasureText(notif.texto, notif.tamTexto);
	textoX = VENTANA_ANCHO / 2 - longitudTexto/2;
	DrawText(notif.texto, textoX, textoY + 70, notif.tamTexto, notif.colorTexto);
}

//WIP
void RenderJuego(Texture2D cardTextures[], gameData &gD, carta deck[])
{
	int longitudTexto;
	const int posXOriginal = 1000;
	const int posYOriginal = 175;

	const char* titulo = { "BLACKJACK" };
	longitudTexto = MeasureText(titulo, 80);
	DrawText(titulo, VENTANA_ANCHO / 2 - longitudTexto / 2, 40, 80, RAYWHITE);

	ClearBackground(Color{0,87,43,255});

	DrawText("Mesa", 100, 120, 40, RAYWHITE);
	DrawText("Jugador", 100, 440, 40, RAYWHITE);

	deck[1].pos.x = 1000;
	deck[1].pos.y = 175;

	DrawTextureEx(cardTextures[deck[1].textura],deck[1].pos,0,0.45,WHITE);

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

void RenderPausa()
{
	Boton boton;
	Notificacion pausa;

	pausa.titulo = "PAUSA";
	pausa.texto = "Deseas salir del juego?";

	DibujarNotificacion(pausa);

	boton.tamTexto = 50;

	boton.texto = "SI";
	boton.width = MeasureText(boton.texto, boton.tamTexto) + 20;
	boton.height = boton.tamTexto + 20;
	boton.pos.x = VENTANA_ANCHO / 2 - boton.width - 20;
	boton.pos.y = VENTANA_ALTO / 2 + 10;
	if (seleccionPausa == 0) boton.colorBoton = RED;
	else boton.colorBoton = DARKBROWN;


	DibujarBoton(boton);

	boton.texto = "NO";
	boton.width = MeasureText(boton.texto, boton.tamTexto) + 20;
	boton.height = boton.tamTexto + 20;
	boton.pos.x = VENTANA_ANCHO / 2 + 20;
	boton.pos.y = VENTANA_ALTO / 2 + 10;
	if (seleccionPausa == 1) boton.colorBoton = RED;
	else boton.colorBoton = DARKBROWN;

	DibujarBoton(boton);
}