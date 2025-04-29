/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/


#include "raylib.h"

#define VENTANA_ANCHO 1200
#define VENTANA_ALTO 800

int main()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(VENTANA_ANCHO, VENTANA_ALTO, "BLACKJACK");

	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{

		// DRAWING
		BeginDrawing();

		//Menu principal
		DrawText("BLACKJACK", (VENTANA_ANCHO - (MeasureText("BLACKJACK", 70))) / 2, 100, 70, RAYWHITE);
		DrawText("JUGAR", (VENTANA_ANCHO - (MeasureText("JUGAR", 50))) / 2, 240, 50, RAYWHITE);
		DrawText("INSTRUCCIONES", (VENTANA_ANCHO - (MeasureText("INSTRUCCIONES", 50))) / 2, 320, 50, RAYWHITE);
		DrawText("CREDITOS", (VENTANA_ANCHO - (MeasureText("CREDITOS", 50))) / 2, 400, 50, RAYWHITE);
		DrawText("SALIR", (VENTANA_ANCHO - (MeasureText("SALIR", 50))) / 2, 480, 50, RAYWHITE);

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
