#include "Titulo.hpp"
#include "Reglas.hpp"
#include "Interfaz.hpp"
#include "resource_dir.h"
#include "JuegoBJ.hpp"
#include "Creditos.hpp"

//int main();

int main()
{
	Pantalla pantallaActual = TITULO;
	gameData gD;
	carta deck[52];

	// Crear el mazo ----------------------------------------------------------------
	CreateDeck(deck);

	// Crear el contexto de OpenGL
	InitWindow(VENTANA_ANCHO, VENTANA_ALTO, "BLACKJACK");
	SearchAndSetResourceDir("resources");

	//Cargamos los recursos
	Texture2D cardTextures[53];
	LoadAllTextures(cardTextures);
	Texture2D logo = LoadTexture("lcc_logo.png");

	SetTargetFPS(60);

	// Loop del juego
	while (!gD.exitWindow) {
		if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) { gD.selectionPause = 0;  gD.exitWindowRequested = true; };

		//Logica
		if (gD.exitWindowRequested == false)
		{
			switch (pantallaActual)
			{
			case TITULO:
			{
				IniciarTitulo(gD, pantallaActual);
				break;
			}
			case JUEGO:
				IniciarJuego(gD, deck, pantallaActual);
				break;

			case REGLAS:
			{
				IniciarReglas(gD, pantallaActual);
				break;
			}
			case CREDITOS:
			{
				IniciarCreditos(gD, pantallaActual);
				break;
			}
			case RESET:
				CreateDeck(deck);
				ResetGame(gD, deck, pantallaActual);
				break;
			case PLAY_AGAIN:
			{
				PlayAgain(gD, deck, pantallaActual);
				break;
			}
			case PICK_CARD:
			{
				PickCard(gD, deck, pantallaActual);
				break;
			}
			}
		}
		else
		{
			PauseGame(gD);
		}

		// Inicia el dibujo
		BeginDrawing();
		switch (pantallaActual)
		{
		case TITULO:
		{
			RenderTitulo(gD);
			break;
		}
		case JUEGO:
			RenderJuego(cardTextures, gD, deck);
			break;

		case REGLAS:
			RenderReglas(gD);
			break;

		case CREDITOS:
			RenderCreditos(gD,logo);
			break;
		case PLAY_AGAIN:
		{
			RenderJuego(cardTextures, gD, deck);
			RenderPickCard(cardTextures, gD, deck);
			RenderPlayAgain(cardTextures, gD, deck);
			break;
		}
		case PICK_CARD:
		{
			RenderJuego(cardTextures, gD, deck);
			RenderPickCard(cardTextures, gD, deck);
			break;
		}
		}

		if (gD.exitWindowRequested)
		{
			RenderPausa(gD);
		}

		EndDrawing();

	}

	UnloadAllTextures(cardTextures);

	CloseWindow();
	return 0;
}
