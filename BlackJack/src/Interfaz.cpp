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


		if (gD.selection == i) botonesMenu[i].colorBoton = RED;

		DibujarBoton(botonesMenu[i]);
	}

	longitudTexto = MeasureText("Muevete arriba y abajo con las teclas direccionales.", 40);
	DrawText("Muevete arriba y abajo con las teclas direccionales.", VENTANA_ANCHO / 2 - longitudTexto / 2, 680, 40, BLACK);
	longitudTexto = MeasureText("Presiona ENTER para continuar.", 40);
	DrawText("Presiona ENTER para continuar.", VENTANA_ANCHO / 2 - longitudTexto / 2, 750, 40, BLACK);

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
	//Notificacion notif;

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
	for (int i = 0; i < 52 - gD.player_cards_count - gD.cpu_cards_count; ++i)
	{
		Vector2 pos;
		pos.x = posXDeck;
		pos.y = posYDeck;

		DrawTextureEx(cardTextures[52], pos, 0, 0.45, WHITE);
	}

	//Dibujamos las cartas activas dependiendo de quien las haya tomado
	int offsetX = 125.0f;
	int offsetY = 500;
	for (int i = 0; i < gD.player_cards_count; ++i)
	{
		int index = gD.cardsPlayer[i];

		//if (i != 0) deck[i].pos.x = deck[i - 1].pos.x + 20;
		deck[index].pos.x = 150.0f + offsetX * i;
		deck[index].pos.y = offsetY;

		DrawTextureEx(cardTextures[index], deck[index].pos, 0, 0.45, WHITE);
	}

	offsetY = 175;
	for (int i = 0; i < gD.cpu_cards_count; ++i)
	{
		int index = gD.cardsCPU[i];

		//if (i != 0) deck[i].pos.x = deck[i - 1].pos.x + 20;
		deck[index].pos.x = 150.0f + offsetX * i;
		deck[index].pos.y = offsetY;

		DrawTextureEx(cardTextures[index], deck[index].pos, 0, 0.45, WHITE);
	}
}

//WIP
void RenderReglas(gameData &gD)
{
	int longitudTexto;

	const char* titulo = { "Reglas" };
	ClearBackground(DARKBROWN);
	longitudTexto = MeasureText(titulo, 80);
	DrawText(titulo, VENTANA_ANCHO / 2 - longitudTexto / 2, 20, 80, RAYWHITE);

	DrawText("Este es un juego de un solo jugador contra una mesa CPU."
		"\nEl juego consiste en obtener un valor mayor al contrincante\n"
		"sin pasarte de 21.\n"
		"Al inicio del juego el jugador saca automaticamente dos cartas.\n"
		"El jugador puede pedir tantas cartas como desee hasta que se plante.\n"
		"Una vez plantado, el dealer sacara del mazo sus cartas."
		, 20, 130, 20, RAYWHITE);

	DrawText("CONTROLES", 620, 320, 40, RAYWHITE);
	DrawText("Usa las flechas direccionales para moverte entre los menus.\n"
		"Presiona ENTER para confirmar tu seleccion\n"
		"Presiona ESC para salir del juego", 620, 360, 20, RAYWHITE);


	DrawText("CONDICIONES DE VICTORIA", 20, 500, 40, RAYWHITE);
	DrawText("La condiccion de blackjack se obtiene cuando se obtiene al sacar 21.\n"
		"Si al terminar el juego\n"
		"El jugador tiene un puntaje menor a 21 pero mayor al dealer, gana.\n"
		"La mesa se pasa de 21, el jugador gana.\n"
		"El jugador obtiene un 21 antes que la mesa, el jugador gana.\n"
		"La mesa obtiene un 21, el jguador pierde.\n", 20, 540, 20, RAYWHITE);

	longitudTexto = MeasureText("Presiona ENTER para regresar", 40);
	DrawText("Presiona ENTER para regresar", VENTANA_ANCHO / 2 - longitudTexto / 2, 750, 40, RAYWHITE);
}

//WIP
void RenderCreditos(gameData &gD, Texture2D logo)
{
	int longitudTexto;

	const char* titulo = { "Creditos" };
	ClearBackground(Color{ 240,223,219,255 });
	longitudTexto = MeasureText(titulo, 80);
	DrawText(titulo, VENTANA_ANCHO / 2 - longitudTexto / 2, 20, 80, BLACK);

	DrawText("Programa elaborado como proyecto final de Programacion de Computadoras de \n"
		"de la Licenciatura en Ciencias de la Computacion de la Universidad de Sonora.", 20, 200, 30, BLACK);

	DrawText("Presentado el 17 de mayo del 2025.", 20, 300, 30, BLACK);

	DrawText("Desarrolladores: \n"
		"Ana Paulina Sortillon Sortillon\n"
		"Denzel Omar Rivera Urias\n"
		"Jovanna Amiraxel Reyes Casillas", 20, 400, 30, BLACK);
	Vector2 pos;
	pos.x = 700;
	pos.y = 300;
	DrawTextureEx(logo, pos, 0, 0.2, WHITE);

	longitudTexto = MeasureText("Presiona ENTER para regresar", 40);
	DrawText("Presiona ENTER para regresar", VENTANA_ANCHO / 2 - longitudTexto / 2, 750, 40, BLACK);

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
	if (gD.selectionPause == 0) boton.colorBoton = RED;
	else boton.colorBoton = DARKBROWN;


	DibujarBoton(boton);

	boton.texto = "NO";
	boton.width = MeasureText(boton.texto, boton.tamTexto) + 20;
	boton.height = boton.tamTexto + 20;
	boton.pos.x = VENTANA_ANCHO / 2 + 20;
	boton.pos.y = VENTANA_ALTO / 2 + 10;
	if (gD.selectionPause == 1) boton.colorBoton = RED;
	else boton.colorBoton = DARKBROWN;

	DibujarBoton(boton);
}

void RenderPlayAgain(Texture2D cardTextures[], gameData &gD,carta deck[])
{
	Notificacion notif;
	//Dibujamos la notificacion dependiendo del resultado del juego
	switch (gD.gameOutcome)
	{
	case EMPATE:
	{
		notif.titulo = "EMPATE";

		if (gD.blackjackOcurred) notif.texto = "Ambos han empatado con un blackjack!\nPresiona ENTER para continuar...";
		else notif.texto = "Ha ocurrido un empate!\nPresiona ENTER para continuar...";
		DibujarNotificacion(notif);
		break;
	}
	case VICTORIA:
	{
		notif.titulo = "VICTORIA";

		if (gD.blackjackOcurred) notif.texto = "Enorabuena! Has obtenido un BLACKJACK!\nPresiona ENTER para continuar...";
		else notif.texto = "Has ganado!\nPresiona ENTER para continuar...";
		DibujarNotificacion(notif);
		break;
	}
	case PERDIDA:
	{
		notif.titulo = "PERDISTE";

		if (gD.blackjackOcurred) notif.texto = "La mesa obtuvo un BLACKJACK.Has perdido.\nPresiona ENTER para continuar...";
		else notif.texto = "Lo siento, has perdido.\nPresiona ENTER para continuar...";
		DibujarNotificacion(notif);
		break;
	}
	}
}

void RenderPickCard(Texture2D cardTextures[], gameData &gD,carta deck[])
{
	//Dibujamos los botones necesarios para la fase de toma de cartas
	int longitudTexto;
	const int menuMax = 2;
	char* menu[menuMax] = { "Pedir", "Plantarse" };
	Boton botonesMenu[menuMax];
	for (int i = 0; i < menuMax; ++i)
	{
		botonesMenu[i].tamTexto = 40;
		longitudTexto = MeasureText(menu[i], botonesMenu[i].tamTexto);
		botonesMenu[i].texto = menu[i];
		botonesMenu[i].width = longitudTexto + 20;
		botonesMenu[i].height = botonesMenu[i].tamTexto + 20;

		if (i != 0) botonesMenu[i].pos.x = botonesMenu[i - 1].pos.x + botonesMenu[i - 1].width + 20;
		else botonesMenu[i].pos.x = 720;

		botonesMenu[i].pos.y = 720;

		if (gD.selectionGame == i) botonesMenu[i].colorBoton = RED;

		DibujarBoton(botonesMenu[i]);
	}
}