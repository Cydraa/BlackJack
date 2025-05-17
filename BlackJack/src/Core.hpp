#pragma once

/** @file
*/

#include "raylib.h"
#include <string>
#include <cstdio>

#define MENU_MAX 4
#define VENTANA_ANCHO 1280
#define VENTANA_ALTO 800
#define TEXTURE_COUNT 52

using std::string;
using std::sprintf;


/**
* \brief Estructura principal del juego. Contiene todas las variables que se deben de seguir para comunicarse entre funciones.
*/
struct gameData
{
    int sumPlayer; /**Suma del jugador*/
    int sumCPU; /**Suma del CPU*/
    int gameOutcome; /** Flag para indicar si el jugador ganó la mano (usado en la lógica original).*/
    bool exitWindow; /**Salir del juego*/
    bool exitWindowRequested; /**Peticion de salida del juego, llama a la ventana de pausa*/
    int selectionPause; /**Menu de seleccion para la pausa*/
    short selection; /**Menu seleccion para el menu principal*/
    int cardsPlayer[26] = {}; /**Guardamos el orden de la salida de las cartas para el jugador (indice del mazo)*/
    int cardsCPU[26] = {}; /**Guardamos el orden de la salida de las cartas para el cpu (indice del mazo)*/
    int player_cards_count; /** Contador de cartas del jugador para esta mano.*/
    int cpu_cards_count; /** Contador de cartas de la CPU para esta mano.*/
    bool blackjackOcurred; /**Si ocurrio blackjack o no*/
    int selectionGame; /**Seleccion */
    bool isHit; /**Si se pidio una carta*/
    bool isHold; /**Si se planto*/

    /**
    * \brief Constructor de los datos del juego.
    */
    gameData();
};

/**Enumeracion de los estados del juego*/
typedef enum Pantalla { TITULO = -1, JUEGO, REGLAS, CREDITOS, SALIR, RESET, PLAY_AGAIN, PICK_CARD } Pantalla;

/**Palos de cartas. NULO_PALO es para el espacios del arreglo de "mano" que aun no se usan.*/
enum Palo { NULO_PALO = 0, CORAZON = 1, DIAMANTE, TREBOL, PICA };

/**Opciones del juego.*/
enum Opciones { PEDIR = 0, PLANTARSE };

/**Jugadores el juego. Este enum sirve para determinar quien tiene la carta recien sacada.*/
enum Actores { DECK = -1, CPU, JUGADOR };

/**Resultado del juego*/
enum Outcome { SIN_DECIDIR = -1, PERDIDA, VICTORIA, EMPATE };

/**
* \brief Estructura de una carta.
*/
struct carta {
    int palo;         /**Figura*/
    int denominacion; /**Número de la carta*/
    Vector2 pos; /**Posicion en pixeles*/
    bool isSelected; /**Si se ha seleccionado la carta*/

    /**
    * \brief Constructor de carta.
    */
    carta();
};

/**
* \brief Pausa el juego.
* \param gD Estructura de datos del juego.
*/
void PauseGame(gameData &gD);

/**
* \brief Carga todas las texturas.
* \param textures Arreglo de texturas.
*/
void LoadAllTextures(Texture2D textures[]);

/**
* \brief Descarga todas las texturas.
* \param textures Arreglo de texturas.
*/
void UnloadAllTextures(Texture2D textures[]);

/**
* \brief Reinicializa todo el juego.
* \param gD Estructura de datos del juego.
* \param deck Arreglo de cartas.
* \param PantallaActual Estado del juego.
*/
void ResetGame(gameData& gD, carta deck[], Pantalla& PantallaActual);

/**
* \brief Logica del reinicio del juego.
* \param gD Estructura de datos del juego.
* \param deck Arreglo de cartas.
* \param PantallaActual Estado del juego.
*/
void PlayAgain(gameData& gD, carta deck[], Pantalla& PantallaActual);

/**
* \brief Logica de la fase de toma de cartas.
* \param gD Estructura de datos del juego.
* \param deck Arreglo de cartas.
* \param PantallaActual Estado del juego.
*/
void PickCard(gameData& gD, carta deck[], Pantalla& PantallaActual);

/**
* \brief Creamos el mazo inicial.
* \param deck Arreglo de cartas.
*/
void CreateDeck(carta* deck);
