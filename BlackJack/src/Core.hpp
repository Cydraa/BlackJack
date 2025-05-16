#pragma once

#include "raylib.h"

#define MENU_MAX 4

extern bool exitWindow;
extern bool exitWindowRequested;
extern int seleccionPausa;

typedef enum Pantalla { TITULO = -1, JUEGO, REGLAS, CREDITOS, SALIR } Pantalla;

void PauseGame();
