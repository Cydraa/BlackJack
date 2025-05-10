#include "Titulo.hpp"
#include "Reglas.hpp"
#include "Interfaz.hpp"

int main()
{
	Pantalla pantallaActual = TITULO;
	short seleccion(0);

	// Crear el contexto de OpenGL
	InitWindow(VENTANA_ANCHO, VENTANA_ALTO, "BLACKJACK");
	SetTargetFPS(60);

	// Loop del juego
	while (!WindowShouldClose())
	{
		//Logica
		switch (pantallaActual)
		{
			case TITULO:
			{
				IniciarTitulo(seleccion, pantallaActual);
				break;
			}
			case REGLAS:
			{
				IniciarReglas(seleccion, pantallaActual);
			}
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
			RenderJuego();
			break;

		case REGLAS:
			RenderReglas();
			break;

		case CREDITOS:
			RenderCreditos();
			break;

		}

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();

	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
