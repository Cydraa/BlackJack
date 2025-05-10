#include "Titulo.hpp"
#include "Interfaz.hpp"

typedef enum Pantalla { TITULO, JUEGO, REGLAS, CREDITOS, SALIR } Pantalla;

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
		switch (pantallaActual)
		{
			case TITULO:
			{
				IniciarTitulo(seleccion);
				break;
			}

		}

		// Inicia el dibujo
		BeginDrawing();

		switch (pantallaActual)
		{
		case TITULO:
		{
			RenderTitulo(seleccion);
			break;
		}

		}

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();

	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
