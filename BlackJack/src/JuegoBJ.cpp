#include "JuegoBJ.hpp"

static int index_jugador = 0;
static int index_CPU = 0;

void IniciarJuego(gameData& gD, carta deck[], Pantalla& pantallaActual)
{
	// 2 Cartas para el JUGADOR y 1 para la MESA
	if (!gD.isHit && !gD.isHold)
	{
		for (int i = 1; i <= 2; i++)
		{
			gD.sumPlayer += card_pull(gD, deck, gD.sumPlayer, JUGADOR, index_jugador, index_CPU);
			gD.player_cards_count++;
		}

		gD.sumCPU += card_pull(gD, deck, gD.sumCPU, CPU, index_jugador, index_CPU);
		gD.cpu_cards_count++;
		if (gD.sumPlayer != 21)
		{
			pantallaActual = PICK_CARD;
			return;
		}
	}
	else if (gD.isHit)
	{
		gD.sumPlayer += card_pull(gD, deck, gD.sumPlayer, JUGADOR, index_jugador, index_CPU);
		gD.player_cards_count++;	
		if (gD.sumPlayer < 21)
		{
			gD.isHit = false;
			pantallaActual = PICK_CARD;
			return;
		}
	}
	else if (gD.isHold)
	{
		// No hacer nada.
	}

	//TOMA DE DECISION DEL CPU
	while (gD.sumPlayer <= 21 && gD.sumCPU != 21 && gD.sumCPU < 17) {
		gD.sumCPU += card_pull(gD, deck, gD.sumCPU, CPU, index_jugador, index_CPU);
		gD.cpu_cards_count++;
	}

	//CONDICION DE BLACKJACK
	bool cpu_got_natural_blackjack = gD.sumPlayer == 21;
	bool player_got_blackjack = gD.sumPlayer == 21;

	//CONDICIONES DE VICTORIA
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

	pantallaActual = PLAY_AGAIN;
	index_jugador = 0;
	index_CPU = 0;
}

int card_pull(gameData& gD, carta deck[], int currentSum, int caller, int& index_jugador, int& index_CPU)
{
	srand((unsigned)time(0)); // Inicializa la semilla para números aleatorios.

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
		gD.cardsPlayer[index_jugador] = card;
		++index_jugador;
		break;
	}
	case CPU:
	{
		deck[card].pos.x = 100;
		deck[card].pos.y = 130;
		gD.cardsCPU[index_CPU] = card;
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