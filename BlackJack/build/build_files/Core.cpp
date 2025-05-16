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