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

void RenderTitulo(gameData &gD)
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


		if (gD.seleccion == i) botonesMenu[i].colorBoton = RED;

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
void RenderJuego(Texture2D cardTextures[], gameData &gD,carta deck[])
{
	int longitudTexto;
	const int posXDeck = 1000;
	const int posYDeck = 175;
	char msg[50];
	const int menuMax = 2;
	char* menu[menuMax] = { "Pedir", "Plantarse"};
	Boton botonesMenu[menuMax];

	//Titulo
	const char* titulo = { "BLACKJACK" };
	longitudTexto = MeasureText(titulo, 80);
	DrawText(titulo, VENTANA_ANCHO / 2 - longitudTexto / 2, 40, 80, RAYWHITE);
	ClearBackground(Color{0,87,43,255});

	//Dibujamos el score
	sprintf_s(msg, "Mesa: %d", gD.sumCPU);
	DrawText(msg, 100, 120, 40, RAYWHITE);
	sprintf_s(msg, "Jugador: %d", gD.sumPlayer);
	DrawText(msg, 100, 440, 40, RAYWHITE);

	//Dibujamos la baraja
	int offSetX(0);
	for (int i = 0; i < 52-gD.player_cards_count-gD.cpu_cards_count; ++i)
	{
		deck[i].pos.x = posXDeck;
		deck[i].pos.y = posYDeck;

		DrawTextureEx(cardTextures[52], deck[i].pos, 0, 0.45, WHITE);
	}

	//Dibujamos las cartas activas dependiendo de quien las haya tomado
	int index;
	for (int i = 0; i < gD.player_cards_count; ++i)
	{
		index = gD.cartasJugador[i];

		if (i != 0) deck[i].pos.x = deck[i - 1].pos.x + 20;

		DrawTextureEx(cardTextures[index], deck[index].pos, 0, 0.45, WHITE);
	}

	for (int i = 0; i < gD.cpu_cards_count; ++i)
	{
		index = gD.cartasCPU[i];

		if (i != 0) deck[i].pos.x = deck[i - 1].pos.x + 20;

		DrawTextureEx(cardTextures[index], deck[index].pos, 0, 0.45, WHITE);
	}

	//Dibujamos la notificacion dependiendo del resultado del juego
	Notificacion notif;
	switch (gD.gameOutcome)
	{
		case EMPATE:
		{
			notif.titulo = "EMPATE";
			
			if (gD.blackjackOcurred) notif.texto = "Ambos han empatado con un blackjack!\nPresiona ENTER para continuar...";
			else notif.texto = "Ha ocurrido un empate!\nPresiona ENTER para continuar...";

			break;
		}
		case VICTORIA:
		{
			notif.titulo = "VICTORIA";

			if (gD.blackjackOcurred) notif.texto = "Enorabuena! Has obtenido un BLACKJACK!\nPresiona ENTER para continuar...";
			else notif.texto = "Has ganado!\nPresiona ENTER para continuar...";

			break;
		}
		case PERDIDA:
		{
			notif.titulo = "PERDISTE";

			if (gD.blackjackOcurred) notif.texto = "La mesa obtuvo un BLACKJACK.Has perdido.\nPresiona ENTER para continuar...";
			else notif.texto = "Lo siento, has perdido.\nPresiona ENTER para continuar...";
			break;
		}
	}

	DibujarNotificacion(notif);

	//Dibujamos los botones
	for (int i = 0; i < menuMax; ++i)
	{
		botonesMenu[i].tamTexto = 40;
		longitudTexto = MeasureText(menu[i], botonesMenu[i].tamTexto);
		botonesMenu[i].texto = menu[i];
		botonesMenu[i].width = longitudTexto + 20;
		botonesMenu[i].height = botonesMenu[i].tamTexto + 20;

		if (i != 0) botonesMenu[i].pos.x = botonesMenu[i - 1].pos.x + botonesMenu[i-1].width + 20;
		else botonesMenu[i].pos.x = 720;

		botonesMenu[i].pos.y = 720;

		if (gD.seleccion == i) botonesMenu[i].colorBoton = RED;

		DibujarBoton(botonesMenu[i]);
	}

}

//WIP
void RenderReglas(gameData &gD)
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
void RenderCreditos(gameData &gD)
{
	int longitudTexto;
	const char* titulo = { "Creditos" };

	ClearBackground(DARKBROWN);

	longitudTexto = MeasureText(titulo, 80);
	DrawText(titulo, VENTANA_ANCHO / 2 - longitudTexto / 2, 100, 80, RAYWHITE);

}

void RenderPausa(gameData &gD)
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
	if (gD.seleccionPausa == 0) boton.colorBoton = RED;
	else boton.colorBoton = DARKBROWN;


	DibujarBoton(boton);

	boton.texto = "NO";
	boton.width = MeasureText(boton.texto, boton.tamTexto) + 20;
	boton.height = boton.tamTexto + 20;
	boton.pos.x = VENTANA_ANCHO / 2 + 20;
	boton.pos.y = VENTANA_ALTO / 2 + 10;
	if (gD.seleccionPausa == 1) boton.colorBoton = RED;
	else boton.colorBoton = DARKBROWN;

	DibujarBoton(boton);
}