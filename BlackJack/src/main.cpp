#include "Titulo.hpp"
#include "Reglas.hpp"
#include "Interfaz.hpp"

bool exitWindow = false;
bool exitWindowRequested = false;
int seleccionPausa(0);

int main()
{
	Pantalla pantallaActual = TITULO;
	short seleccion(0);

	// Crear el contexto de OpenGL
	InitWindow(VENTANA_ANCHO, VENTANA_ALTO, "BLACKJACK");
	SetTargetFPS(60);

	// Loop del juego
	while (!exitWindow)
	{
		if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) { seleccionPausa = 0;  exitWindowRequested = true; };

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

		if (exitWindowRequested)
		{

			DibujarNotificacion("PAUSA","Deseas salir del juego?");
			Boton boton;
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

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();

	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
