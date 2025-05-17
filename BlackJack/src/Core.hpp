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

typedef enum Pantalla { TITULO = -1, JUEGO, REGLAS, CREDITOS, SALIR, RESET } Pantalla;

struct gameData
{
    int sumPlayer;
    int sumCPU;
    int gameOutcome; // Flag para indicar si el jugador ganó la mano (usado en la lógica original).
    bool exitWindow;
    bool exitWindowRequested;
    int seleccionPausa;
    short seleccion;
    int cartasJugador[26] = {}; //Guardamos el orden de la salida de las cartas para el jugador (indice del mazo)
    int cartasCPU[26] = {}; //Guardamos el orden de la salida de las cartas para el cpu (indice del mazo)
    int player_cards_count; // Contador de cartas del jugador para esta mano.
    int cpu_cards_count; // Contador de cartas de la CPU para esta mano.
    bool blackjackOcurred;
    int seleccionJuego;

    gameData()
    {
        sumPlayer = 0;
        sumCPU = 0;
        gameOutcome = -1; // -1 = sin decidir, 1 = jugador gano, 0 = jugador perdio
        exitWindow = false;
        exitWindowRequested = false;
        seleccionPausa = 0;
        seleccion = 0;
        player_cards_count = 0;
        cpu_cards_count = 0;
        blackjackOcurred = false;
        seleccionJuego = 0;
    }
};

void PauseGame(gameData &gD);
void LoadAllTextures(Texture2D textures[]);
void UnloadAllTextures(Texture2D textures[]);
