#include "JuegoBJ.hpp"

void IniciarJuego(gameData &gD, carta deck[])
{
    bool terminateGame = false;
    int index_jugador(0);
    int index_CPU(0);
    bool isPlayerTurn;
    bool retryGame = true;

    while (terminateGame == false)
    {
        srand((unsigned)time(0)); // Inicializa la semilla para números aleatorios.

        // Crear el mazo ----------------------------------------------------------------
        int k(0); // Índice para el array deck.
        for (int i = CORAZON; i <= PICA; i++) // Itera por los 4 palos.
        {
            for (int j = 1; j <= 13; j++) // Itera por las 13 denominaciones
            {
                deck[k].palo = i;
                deck[k].denominacion = j;
                k++;
            }
        }

            // IMPORTANTE: Reinicia el tracker y demas variables del juego, marcando todas las cartas como disponibles.
            for (int i = 0; i < 52; ++i) {
                deck[i].isSelected = false;
            }
            gD.sumPlayer = 0;
            gD.sumCPU = 0;
            gD.gameOutcome = PERDIDA;
            bool player_got_blackjack = false; // Flag: ¿Obtuvo 21 con 2 cartas?

            // 2 Cartas para el JUGADOR
            isPlayerTurn = true;
            for (int i = 1; i <= 2; i++)
            {
                gD.sumPlayer += card_pull(gD, deck,gD.sumPlayer, JUGADOR, index_jugador, index_CPU);
                gD.player_cards_count++;
            }

            // Comprobar si el jugador tiene un Blackjack Natural (21 con 2 cartas)
            if (gD.player_cards_count == 2 && gD.sumPlayer == 21) {
                player_got_blackjack = true;
            }

            // 1 Carta para la MESA (CPU)
            isPlayerTurn = false;
            gD.sumCPU += card_pull(gD, deck,gD.sumCPU, CPU, index_jugador, index_CPU);
            gD.cpu_cards_count++;

            // --- TURNO DEL JUGADOR (SI NO HUBO BLACKJACK NATURAL) ---
            if (!player_got_blackjack && gD.sumPlayer < 21) {
                isPlayerTurn = true;

                // Bucle para las acciones del jugador (Pedir, Plantarse)
                bool is_pedir;
                bool is_plantarse;
                while (gD.sumPlayer < 21) { // Continuar mientras no se pase.
                    // --- Procesar Acción del Jugador ---
                    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_LEFT))
                    {
                        if (gD.seleccion < 2) ++gD.seleccion;
                        else gD.seleccion = 2;
                    }

                    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_RIGHT))
                    {
                        if (gD.seleccion > 0) --gD.seleccion;
                        else gD.seleccion = 0;
                    }

                    switch (gD.seleccion)
                    {
                    case PEDIR: if (IsKeyPressed(KEY_ENTER)) is_pedir = true; break;
                    case PLANTARSE: if (IsKeyPressed(KEY_ENTER)) is_plantarse = true; break;
                    }


                    if (is_pedir) { // ----- PEDIR (HIT) -----
                        gD.sumPlayer += card_pull(gD, deck,gD.sumPlayer, JUGADOR, index_jugador, index_CPU);
                        gD.player_cards_count++;

                    }
                    else if (is_plantarse) { // ----- PLANTARSE (STAND) -----
                        break; // FIN DEL TURNO DEL JUGADOR.
                    }

                    // Si tras pedir, el jugador se pasa de 21, sale del bucle de acciones.
                    if (gD.sumPlayer >= 21) {
                        break;
                    }
                } // Fin while (acciones del jugador)
            } // Fin if (turno del jugador)

            // --- TURNO DE LA MESA (CPU) ---
            bool cpu_got_natural_blackjack = false;
            // La mesa juega sólo si el jugador no se pasó (sumPlayer <= 21).
            if (gD.sumPlayer <= 21) {
                isPlayerTurn = false;

                // Coge/Revela la segunda carta
                if (gD.cpu_cards_count == 1) {
                    gD.sumCPU += card_pull(gD, deck,gD.sumCPU, CPU, index_jugador, index_CPU);
                    gD.cpu_cards_count++;

                    // Comprueba si la CPU obtuvo Blackjack natural
                    if (gD.cpu_cards_count == 2 && gD.sumCPU == 21) {
                        cpu_got_natural_blackjack = true;
                    }
                }

                // REGLA DE LA MESA: Pedir si tiene 16 o menos, plantarse con 17 o más.
                while (!cpu_got_natural_blackjack && gD.sumCPU < 17 && gD.sumCPU < 21) {
                    gD.sumCPU += card_pull(gD, deck,gD.sumCPU, CPU, index_jugador, index_CPU);
                    gD.cpu_cards_count++;
                }

            } // Fin if (Turno de la Mesa)

            // --- RESULTADOS Y PAGOS ---
            // Evaluar condiciones de victoria, derrota o empate
            if (player_got_blackjack && !cpu_got_natural_blackjack) {
                gD.gameOutcome = VICTORIA;
                gD.blackjackOcurred = true;
            }
            else if (player_got_blackjack && cpu_got_natural_blackjack) {
                gD.gameOutcome = EMPATE;
                gD.blackjackOcurred = true;
            }
            else if (cpu_got_natural_blackjack && !player_got_blackjack) {
                gD.gameOutcome = PERDIDA;
            }
            else if (gD.sumPlayer > 21) {
                gD.gameOutcome = PERDIDA;
            }
            else if (gD.sumCPU > 21) {
                gD.gameOutcome = VICTORIA;
            }
            else if (gD.sumPlayer == gD.sumCPU) {
                gD.gameOutcome = EMPATE;
            }
            else if (gD.sumPlayer > gD.sumCPU) {
                gD.gameOutcome = VICTORIA;
            }
            else { // (sumCPU > sumPlayer)
                gD.gameOutcome = PERDIDA;
            }

            if (IsKeyPressed(KEY_ENTER)) terminateGame = true;
    }

    Pantalla TITULO;
}

int card_pull(gameData &gD, carta deck[], int currentSum, int caller, int &index_jugador, int &index_CPU)
{
    int card; // Índice de la carta seleccionada (0-51).
    int cardValue; // El valor numérico (1, 2,.. 10, 11) que la carta aporta a la suma.

    // 1. BUSCAR UNA CARTA DISPONIBLE
    card = rand() % 52;
    do {
        card = rand() % 52; // Genera un índice aleatorio entre 0 y 51.
    } while (deck[card].isSelected == true); // Repite si la carta en ese índice YA FUE USADA (denominacion != 0).

    // 2. MARCAR LA CARTA COMO "USADA" en el tracker 'isSelected'. Y realocar a la posicion adecuada dependiendo de quien llamo a la funcion.
    deck[card].isSelected = true;

    switch (caller)
    {
        case JUGADOR:
        {
            deck[card].pos.x = 100;
            deck[card].pos.y = 450;
            gD.cartasJugador[index_jugador] = card;
            ++index_jugador;
            break;
        }
        case CPU:
        {
            deck[card].pos.x = 100;
            deck[card].pos.y = 130;
            gD.cartasCPU[index_CPU] = card;
            ++index_CPU;
            break;
        }
    }


    // 3. ASIGNAR EL VALOR NUMÉRICO (PARA LA SUMA)
    if (deck[card].denominacion == 1) // Es un AS
    {
        // Usa 11 si NO se pasa de 21, en caso contrario, usa 1.
        if (currentSum + 11 <= 21) {
          cardValue = 11;
        }
        else {
          cardValue = 1;
        }
    }
    else if (deck[card].denominacion >= 10 && deck[card].denominacion <= 13) // Cartas 10, J, Q, K
    {
        cardValue = 10; // Valen 10.
    }
    else // Cartas 2-9
    {
        cardValue = deck[card].denominacion; // Valen su propia denominación.
    }

    // 5. DEVOLVER EL VALOR CALCULADO
    return cardValue;
}

// Constructor
carta::carta() {
    palo = NULO_PALO;
    denominacion = 0;
    pos.x = 0;
    pos.y = 0;
    textura = 52;
    isSelected = false;
}