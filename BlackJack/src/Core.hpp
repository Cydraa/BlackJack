#pragma once

#include "raylib.h"
#include <string>
#include <cstdio>

#define MENU_MAX 4
#define VENTANA_ANCHO 1280
#define VENTANA_ALTO 800
#define TEXTURE_COUNT 52

using std::string;
using std::sprintf;

typedef enum Pantalla { TITULO = -1, JUEGO, REGLAS, CREDITOS, SALIR } Pantalla;

struct gameData
{
    int sumPlayer;
    int sumCPU;
    bool playerWin;
    bool exitWindow;
    bool exitWindowRequested;
    int seleccionPausa;
    short seleccion;

    gameData()
    {
        sumPlayer = 0;
        sumCPU = 0;
        playerWin = false;
        exitWindow = false;
        exitWindowRequested = false;
        seleccionPausa = 0;
        seleccion = 0;
    }
};

void PauseGame(gameData &gD);
void LoadAllTextures(Texture2D textures[]);
void UnloadAllTextures(Texture2D textures[]);
