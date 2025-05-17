#pragma once

#include "Core.hpp"
#include <cstdlib> // Para rand, srand
#include <ctime>   // Para time

// Palos de cartas. NULO_PALO es para el espacios del arreglo de "mano" que aun no se usan.
enum Palo { NULO_PALO = 0, CORAZON = 1, DIAMANTE, TREBOL, PICA };

enum Opciones { PEDIR = 0, PLANTARSE};

enum Actores { DECK = -1, CPU, JUGADOR };

enum Outcome { SIN_DECIDIR = -1, PERDIDA, VICTORIA, EMPATE };

// Define la estructura de una carta.
struct carta {
    int palo;         // Figura
    int denominacion; // Número de la carta
    Vector2 pos;
    int textura;
    bool isSelected;

    carta();
};

int card_pull(gameData& gD, carta deck[], int currentSum, int caller, int& index_jugador, int& index_CPU);
void IniciarJuego(gameData& gD, carta deck[]);