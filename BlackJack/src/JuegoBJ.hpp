#pragma once

#include "Core.hpp"

// Palos de cartas. NULO_PALO es para el espacios del arreglo de "mano" que aun no se usan.
enum Palo { NULO_PALO = 0, CORAZON = 1, DIAMANTE, TREBOL, PICA };

// Define la estructura de una carta.
class carta {
public:
    int palo;         // Figura
    int denominacion; // Número de la carta
    Vector2 pos;
    int textura;
    bool isSelected;

    // Constructor
    carta(int pal = NULO_PALO, int denom = 0) {
        palo = pal;
        denominacion = denom;
        pos.x = 0;
        pos.y = 0;
        textura = 0;
        isSelected = false;
    }
};
