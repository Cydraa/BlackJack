#include "Titulo.hpp"
#include "Reglas.hpp"
#include "Interfaz.hpp"
#include "resource_dir.h"
#include "JuegoBJ.hpp"

void ResetGame(gameData& gD, carta deck[], Pantalla& PantallaActual);

int main()
{
	Pantalla pantallaActual = TITULO;
	gameData gD;
	carta deck[52];

	// Crear el mazo ----------------------------------------------------------------
	int k(0); // Índice para el array deck.
	for (int i = CORAZON; i <= PICA; i++) // Itera por los 4 palos.
	{
		for (int j = 1; j <= 13; j++) // Itera por las 13 denominaciones
		{
			deck[k].palo = i;
			deck[k].denominacion = j;
			k++;
		}
	}

	// Crear el contexto de OpenGL
	InitWindow(VENTANA_ANCHO, VENTANA_ALTO, "BLACKJACK");
	SearchAndSetResourceDir("resources");

	//Cargamos los recursos
	Texture2D cardTextures[53];
	LoadAllTextures(cardTextures);

	SetTargetFPS(60);

	// Loop del juego
	while (!gD.exitWindow) {
		if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) { gD.seleccionPausa = 0;  gD.exitWindowRequested = true; };

		//Logica
		// Inicia el dibujo

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
			case RESET:
				ResetGame(gD,deck,pantallaActual);
				break;
			}
		}
		else
		{
			PauseGame(gD);
		}

			BeginDrawing();
			//Renders
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
				RenderCreditos(gD);
				break;
			}

			if (gD.exitWindowRequested)
			{
				RenderPausa(gD);
			}

			// end the frame and get ready for the next one  (display frame, poll input, etc...)
			EndDrawing();

		}

		UnloadAllTextures(cardTextures);

		// destroy the window and cleanup the OpenGL context
		CloseWindow();
		return 0;
}

void ResetGame(gameData& gD, carta deck[], Pantalla& PantallaActual)
{
	PantallaActual = JUEGO;
	// IMPORTANTE: Reinicia el tracker y demas variables del juego, marcando todas las cartas como disponibles.
	for (int i = 0; i < 52; ++i) {
		deck[i].isSelected = false;
	}
	gD.sumPlayer = 0;
	gD.sumCPU = 0;
	gD.gameOutcome = SIN_DECIDIR;
}