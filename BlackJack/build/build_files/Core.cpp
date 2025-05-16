#include "Core.hpp"

void PauseGame()
{
	if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_UP))
	{
		if (seleccionPausa < 1) ++seleccionPausa;
		else seleccionPausa = 1;
	}

	if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_DOWN))
	{
		if (seleccionPausa > 0) --seleccionPausa;
		else seleccionPausa = 0;
	}

	switch (seleccionPausa)
	{
	case 0: if (IsKeyPressed(KEY_ENTER)) exitWindow = true; break;
	case 1: if (IsKeyPressed(KEY_ENTER)) { exitWindow = false; exitWindowRequested = false; } break;
	}

	if (IsKeyPressed(KEY_S)) exitWindow = true;
	else if (IsKeyPressed(KEY_N)) exitWindowRequested = false;
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
}

void UnloadAllTextures(Texture2D textures[])
{
	for (int i = 0; i < TEXTURE_COUNT; ++i)
	{
		UnloadTexture(textures[i]);
	}
}
