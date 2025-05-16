#include "Titulo.hpp"
#include "Reglas.hpp"
#include "Interfaz.hpp"
#include "resource_dir.h"
#include "JuegoBJ.hpp"

int main()
{
	Pantalla pantallaActual = TITULO;
	gameData gD;

	// Crear el contexto de OpenGL
	InitWindow(VENTANA_ANCHO, VENTANA_ALTO, "BLACKJACK");
	SearchAndSetResourceDir("resources");

	Texture2D cardTextures[52];
	LoadAllTextures(cardTextures);

	carta hand[52];

	SetTargetFPS(60);

	// Loop del juego
	while (!gD.exitWindow)
	{
		if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) { gD.seleccionPausa = 0;  gD.exitWindowRequested = true; };

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
					break;

				case REGLAS:
				{
					IniciarReglas(gD, pantallaActual);
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

		//Renders
		switch (pantallaActual)
		{
		case TITULO:
		{
			RenderTitulo(gD);
			break;
		}
		case JUEGO:
			RenderJuego(cardTextures, gD, hand);
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
