#include "olcPixelGameEngine.h"
#include "Game.h"

int main()
{
	if (game.Construct(720, 405, 3, 3))
		game.Start();

	return 0;
}