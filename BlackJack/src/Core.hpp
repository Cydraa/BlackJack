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

// Palos de cartas. NULO_PALO es para el espacios del arreglo de "mano" que aun no se usan.
enum Palo { NULO_PALO = 0, CORAZON = 1, DIAMANTE, TREBOL, PICA };

// Define la estructura de una carta.
class carta {
public:
    int palo;         // Figura
    int denominacion; // Número de la carta
    Vector2 pos;
    int textura;

    // Constructor
    carta(int pal = NULO_PALO, int denom = 0) {
        palo = pal;
        denominacion = denom;
        pos.x = 0;
        pos.y = 0;
        textura = 0;
    }
};

void PauseGame(gameData &gD);
void LoadAllTextures(Texture2D textures[]);
void UnloadAllTextures(Texture2D textures[]);
