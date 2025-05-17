#include "Core.hpp"

void PauseGame(gameData &gD)
{
	if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_UP))
	{
		if (gD.seleccionPausa < 1) ++gD.seleccionPausa;
		else gD.seleccionPausa = 1;
	}

	if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_DOWN))
	{
		if (gD.seleccionPausa > 0) --gD.seleccionPausa;
		else gD.seleccionPausa = 0;
	}

	switch (gD.seleccionPausa)
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
