#pragma once

#include "Core.hpp"
#include <cstdlib> // Para rand, srand
#include <ctime>   // Para time

/**
* \brief Toma una carta.
* \param gD Estructura de datos del juego.
* \param deck Arreglo de cartas.
* \param currentSum Suma actual.
* \param caller El actor que esta llamando a la funcion.
* \param index_jugador El indice para el arreglo que tiene las cartas del jugador.
* \param index_CPU El indice para el arreglo que tiene las cartas del jugador.
*/
int card_pull(gameData& gD, carta deck[], int currentSum, int caller, int& index_jugador, int& index_CPU);

/**
* \brief Inicializa la logica de la pantalla del juego.
* \param gD Estructura de datos del juego.
* \param pantallaActual Estado del juego.
*/
void IniciarJuego(gameData& gD, carta deck[], Pantalla& pantallaActual);