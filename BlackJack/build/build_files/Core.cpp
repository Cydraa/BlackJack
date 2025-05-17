#include "Core.hpp"

void PauseGame(gameData &gD)
{
	if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_UP))
	{
		if (gD.selectionPause < 1) ++gD.selectionPause;
		else gD.selectionPause = 1;
	}

	if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_DOWN))
	{
		if (gD.selectionPause > 0) --gD.selectionPause;
		else gD.selectionPause = 0;
	}

	switch (gD.selectionPause)
	{
	case 0: if (IsKeyPressed(KEY_ENTER)) gD.exitWindow = true; break;
	case 1: if (IsKeyPressed(KEY_ENTER)) { gD.exitWindow = false; gD.exitWindowRequested = false; } break;
	}

	if (IsKeyPressed(KEY_S)) gD.exitWindow = true;
	else if (IsKeyPressed(KEY_N)) gD.exitWindowRequested = false;
}

void LoadAllTextures(Texture2D textures[])
{
	char path[100];
	int k(0);

	for (int i = 1; i <= 4; ++i) // palo
	{
		for (int j = 1; j <= 13; ++j) // denom
		{
			sprintf_s(path,"cartas/%d_%d.png", i, j);
			textures[k] = LoadTexture(path);
			++k;
		}
	}

	textures[52] = LoadTexture("cartas/reverso.png");
}

void UnloadAllTextures(Texture2D textures[])
{
	for (int i = 0; i < TEXTURE_COUNT; ++i)
	{
		UnloadTexture(textures[i]);
	}

	UnloadTexture(textures[52]);
}

void ResetGame(gameData& gD, carta deck[], Pantalla& PantallaActual)
{
	PantallaActual = JUEGO;
	// IMPORTANTE: Reinicia el tracker y demas variables del juego, marcando todas las cartas como disponibles.
	for (int i = 0; i < 52; ++i) {
		deck[i].isSelected = false;
	}
	gD.sumPlayer = 0;
	gD.sumCPU = 0;
	gD.gameOutcome = SIN_DECIDIR;
	gD.blackjackOcurred = false;
	for (int i = 0; i < 26; i++)
	{
		gD.cardsPlayer[i] = 0;
		gD.cardsCPU[i] = 0;
	}
	gD.cpu_cards_count = 0;
	gD.player_cards_count = 0;
	gD.isHit = false;
	gD.isHold = false;
}
void PlayAgain(gameData& gD, carta deck[], Pantalla& PantallaActual)
{
	if (IsKeyPressed(KEY_ENTER))
	{
		PantallaActual = TITULO;
	}
	//Espera por un ENTER y resetea el estado del juego.
}

void PickCard(gameData& gD, carta deck[], Pantalla& PantallaActual)
{
	// --- Procesar Acción del Jugador ---
	if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_RIGHT))
	{
		if (gD.selectionGame < 1) ++gD.selectionGame;
		else gD.selectionGame = 1;
	}

	if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_LEFT))
	{
		if (gD.selectionGame > 0) --gD.selectionGame;
		else gD.selectionGame = 0;
	}

	switch (gD.selectionGame)
	{
	case PEDIR: if (IsKeyPressed(KEY_ENTER)) gD.isHit = true; break;
	case PLANTARSE: if (IsKeyPressed(KEY_ENTER)) gD.isHold = true; break;
	}

	if (gD.isHit || gD.isHold)
	{
		PantallaActual = JUEGO;
	}
}

void CreateDeck(carta* deck)
{
	int k(0); // Índice para el array deck.
	for (int i = CORAZON; i <= PICA; i++) // Itera por los 4 palos.
	{
		for (int j = 1; j <= 13; j++) // Itera por las 13 denominaciones
		{
			deck[k] = carta();
			deck[k].palo = i;
			deck[k].denominacion = j;
			k++;
		}
	}
}

gameData::gameData()
{
		sumPlayer = 0;
		sumCPU = 0;
		gameOutcome = -1; // -1 = sin decidir, 1 = jugador gano, 0 = jugador perdio
		exitWindow = false;
		exitWindowRequested = false;
		selectionPause = 0;
		selection = 0;
		player_cards_count = 0;
		cpu_cards_count = 0;
		blackjackOcurred = false;
		selectionGame = 0;
		isHit = false;
		isHold = false;
}
