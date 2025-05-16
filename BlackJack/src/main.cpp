#include "Titulo.hpp"
#include "Reglas.hpp"
#include "Interfaz.hpp"
#include "resource_dir.h"

bool exitWindow = false;
bool exitWindowRequested = false;
int seleccionPausa(0);

int main()
{
	Pantalla pantallaActual = TITULO;
	gameData gData;

	short seleccion(0);

	// Crear el contexto de OpenGL
	InitWindow(VENTANA_ANCHO, VENTANA_ALTO, "BLACKJACK");
	SearchAndSetResourceDir("resources");

	Texture2D cardTextures[52];
	LoadAllTextures(cardTextures);

	carta hand[52];

	SetTargetFPS(60);

	// Loop del juego
	while (!exitWindow)
	{
		if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) { seleccionPausa = 0;  exitWindowRequested = true; };

		//Logica

		if (exitWindowRequested == false)
		{
			switch (pantallaActual)
			{
				case TITULO:
				{
					IniciarTitulo(seleccion, pantallaActual);
					break;
				}
				case JUEGO:
					break;

				case REGLAS:
				{
					IniciarReglas(seleccion, pantallaActual);
					break;
				}
			}
		}
		else
		{
			PauseGame();
		}

		// Inicia el dibujo
		BeginDrawing();

		//Renders
		switch (pantallaActual)
		{
		case TITULO:
		{
			RenderTitulo(seleccion);
			break;
		}
		case JUEGO:
			RenderJuego(cardTextures, gData, hand);
			break;

		case REGLAS:
			RenderReglas();
			break;

		case CREDITOS:
			RenderCreditos();
			break;
		}

		if (exitWindowRequested)
		{
			RenderPausa();
		}

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();

	}

	UnloadAllTextures(cardTextures);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
